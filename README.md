# sdl-tutorial
An in depth cross platform tutorial for SDL2 using legacy OpenGL ES 2 and Vulkan with examples for each. 

## Why SDL2?
PLATFORM. SUPPORT.

Although alternatives like SFML and GLFW are significantly lighter and leaner, that amount of platform specific code needed in larger projects is not worth it. Additionaly, SDL is one of the few libraries has mobile support.

## Why ES and Vulkan and not regular modern OpenGL?
I am a firm believer that all modern graphics projects should use Vulkan as it is the future of the industry and if used properly, its performance ceiling is higher than OpenGL.

Unfortunately, hardware support for Vulkan at this time is limited so some compromises should made to support older devices. This is where OpenGL ES 2 shines. Why ES over modern OpenGL? Since performance is being compromised for platform support, it would be better to go for the greatest platform support with our second implementation. ES supports more devices than modern OpenGL such as the very popular Raspberry Pi series of SBCs.