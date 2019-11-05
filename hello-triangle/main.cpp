#include <iostream>
#include <vector>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-pack"
#include <SDL/SDL.h>
#include <SDL/SDL_vulkan.h>
#pragma clang diagnostic pop
#include <vulkan/vulkan.hpp>

#ifdef _WIN32
    #pragma comment(linker, "/subsystem:windows")
    #define VK_USE_PLATFORM_WIN32_KHR
    #define PLATFORM_SURFACE_EXTENSION_NAME VK_KHR_WIN32_SURFACE_EXTENSION_NAME
#endif

#define APP_NAME "hello-triangle"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#ifndef UINT32_MAX
    #define UINT32_MAX 0xffffffff
#endif

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Vulkan_LoadLibrary(nullptr);
    SDL_Window* window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 360, SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);

    uint32_t extensionCount;
    const char** extensionNames = 0;
    SDL_Vulkan_GetInstanceExtensions(window, &extensionCount, nullptr);
    extensionNames = new const char *[extensionCount];
    SDL_Vulkan_GetInstanceExtensions(window, &extensionCount, extensionNames);
    const VkInstanceCreateInfo instInfo = {
        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, // sType
        nullptr,                                // pNext
        0,                                      // flags
        nullptr,                                // pApplicationInfo
        0,                                      // enabledLayerCount
        nullptr,                                // ppEnabledLayerNames
        extensionCount,                         // enabledExtensionCount
        extensionNames,                         // ppEnabledExtensionNames
    };
    VkInstance vkInst;
    vkCreateInstance(&instInfo, nullptr, &vkInst);

    uint32_t physicalDeviceCount;
    vkEnumeratePhysicalDevices(vkInst, &physicalDeviceCount, nullptr);
    std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
    vkEnumeratePhysicalDevices(vkInst, &physicalDeviceCount, physicalDevices.data());
    VkPhysicalDevice physicalDevice = physicalDevices[0];

    uint32_t queueFamilyCount;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, nullptr);
    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueFamilies.data());

    VkSurfaceKHR surface;
    SDL_Vulkan_CreateSurface(window, vkInst, &surface);

    uint32_t graphicsQueueIndex = UINT32_MAX;
    uint32_t presentQueueIndex = UINT32_MAX;
    VkBool32 support;
    uint32_t i = 0;
    for (VkQueueFamilyProperties queueFamily : queueFamilies) {
        if (graphicsQueueIndex == UINT32_MAX && queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
            graphicsQueueIndex = i;
        if (presentQueueIndex == UINT32_MAX) {
            vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface, &support);
            if(support)
                presentQueueIndex = i;
        }
        ++i;
    }

    float queuePriority = 1.0f;
    VkDeviceQueueCreateInfo queueInfo = {
        VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO, // sType
        nullptr,                                    // pNext
        0,                                          // flags
        graphicsQueueIndex,                         // graphicsQueueIndex
        1,                                          // queueCount
        &queuePriority,                             // pQueuePriorities
    };
    
    VkPhysicalDeviceFeatures deviceFeatures = {};
    const char* deviceExtensionNames[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    VkDeviceCreateInfo createInfo = {
        VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,   // sType
        nullptr,                                // pNext
        0,                                      // flags
        1,                                      // queueCreateInfoCount
        &queueInfo,                             // pQueueCreateInfos
        0,                                      // enabledLayerCount
        nullptr,                                // ppEnabledLayerNames
        1,                                      // enabledExtensionCount
        deviceExtensionNames,                   // ppEnabledExtensionNames
        &deviceFeatures,                        // pEnabledFeatures
    };
    VkDevice device;
    vkCreateDevice(physicalDevice, &createInfo, nullptr, &device);

    VkQueue graphicsQueue;
    vkGetDeviceQueue(device, graphicsQueueIndex, 0, &graphicsQueue);

    VkQueue presentQueue;
    vkGetDeviceQueue(device, presentQueueIndex, 0, &presentQueue);

    SDL_Log("Initialized with errors: %s", SDL_GetError());
    
    bool running = true;
    while(running) {
        SDL_Event windowEvent;
        while(SDL_PollEvent(&windowEvent))
            if(windowEvent.type == SDL_QUIT) {
                running = false;
                break;
            }
    }

    vkDestroyDevice(device, nullptr);
    vkDestroyInstance(vkInst, nullptr);
    SDL_DestroyWindow(window);
    SDL_Vulkan_UnloadLibrary();
    SDL_Quit();

    SDL_Log("Cleaned up with errors: %s", SDL_GetError());

    return 0;
}