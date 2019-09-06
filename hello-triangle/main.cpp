#include <iostream>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-pack"
#include <SDL/SDL.h>
#include <SDL/SDL_vulkan.h>
#pragma clang diagnostic pop

#ifdef _WIN32
    #pragma comment(linker, "/subsystem:windows")
    #define VK_USE_PLATFORM_WIN32_KHR
    #define PLATFORM_SURFACE_EXTENSION_NAME VK_KHR_WIN32_SURFACE_EXTENSION_NAME
#else
    #define PLATFORM_SURFACE_EXTENSION_NAME VK_KHR_XLIB_SURFACE_EXTENSION_NAME
#endif

#include <vulkan/vulkan.hpp>

#define APP_NAME "hello-triangle"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

VkBool32 verify_instance_layers(const char** instanceLayerNames) {
    uint32_t instanceLayerCount = 0;
    vkEnumerateInstanceLayerProperties(&instanceLayerCount, NULL);
    VkLayerProperties* instanceLayers = (VkLayerProperties*) malloc(sizeof (VkLayerProperties) * instanceLayerCount);
    vkEnumerateInstanceLayerProperties(&instanceLayerCount, instanceLayers);

    for (uint32_t i = 0; i < ARRAY_SIZE(instanceLayerNames); ++i)
        for (uint32_t j = 0; j < instanceLayerCount; ++j)
            if (!strcmp(instanceLayerNames[i], instanceLayers[j].layerName)) {
                free(instanceLayers);
                return 1;
            }
    free(instanceLayers);
    return 0;
}

int main(int argc, char * argv[]) {
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 360, SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);
    SDL_GL_CreateContext(window);

    VkApplicationInfo appInfo = {
        VK_STRUCTURE_TYPE_APPLICATION_INFO, // sType
        NULL,                               // pNext
        APP_NAME,                           // pApplicationName
        0,                                  // applicationVersion
        APP_NAME,                           // pEngineName
        0,                                  // engineVersion
        VK_API_VERSION_1_0,                 // apiVersion
    };

    const char* instance_validation_layers[] = {
        "VK_LAYER_LUNARG_standard_validation"
    };
    const char* instance_validation_layers_alt[] = {
        "VK_LAYER_GOOGLE_threading",     "VK_LAYER_LUNARG_parameter_validation",
        "VK_LAYER_LUNARG_device_limits", "VK_LAYER_LUNARG_object_tracker",
        "VK_LAYER_LUNARG_image",         "VK_LAYER_LUNARG_core_validation",
        "VK_LAYER_LUNARG_swapchain",     "VK_LAYER_GOOGLE_unique_objects"
    };
    VkBool32 useStdLayers = verify_instance_layers(instance_validation_layers);

    uint32_t enabledExtensionCount = 0;
    const char* extensionNames[64];
    uint32_t instanceExtensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &instanceExtensionCount, NULL);
    VkExtensionProperties* instanceExtensions = (VkExtensionProperties*) malloc(sizeof(VkExtensionProperties) * instanceExtensionCount);
    for (uint32_t i = 0; i < instanceExtensionCount; ++i) {
        if (!strcmp(VK_KHR_SURFACE_EXTENSION_NAME, instanceExtensions[i].extensionName))
                extensionNames[enabledExtensionCount++] = VK_KHR_SURFACE_EXTENSION_NAME;
        if (!strcmp(PLATFORM_SURFACE_EXTENSION_NAME, instanceExtensions[i].extensionName))
                extensionNames[enabledExtensionCount++] = PLATFORM_SURFACE_EXTENSION_NAME;
        if (!strcmp(VK_EXT_DEBUG_REPORT_EXTENSION_NAME, instanceExtensions[i].extensionName))
                extensionNames[enabledExtensionCount++] = VK_EXT_DEBUG_REPORT_EXTENSION_NAME;
    }
    free(instanceExtensions);

    VkInstanceCreateInfo instInfo = {
        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, // sType
        NULL,                                   // pNext
        NULL,                                   // flags
        &appInfo,                               // pApplicationInfo
        ARRAY_SIZE((useStdLayers ? instance_validation_layers : instance_validation_layers_alt)),           // enabledLayerCount
        (const char* const*)(useStdLayers ? instance_validation_layers : instance_validation_layers_alt),   // ppEnabledLayerNames
        enabledExtensionCount,                  // enabledExtensionCount
        extensionNames,                         // ppEnabledExtensionNames
    };
    VkInstance* pVkInst;
    vkCreateInstance(&instInfo, NULL, pVkInst);

    bool running = true;
    while(running) {
        SDL_Event windowEvent;
        while(SDL_PollEvent(&windowEvent))
            if(windowEvent.type == SDL_QUIT) {
                running = false;
                break;
            }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}