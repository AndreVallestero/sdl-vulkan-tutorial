# sdl-tutorial
An in depth cross platform tutorial for SDL2 using legacy OpenGL ES 2 and Vulkan with examples for each written in C++. 

## Why SDL2?
PLATFORM. SUPPORT.

Although alternatives like SFML and GLFW are significantly lighter and leaner, that amount of platform specific code needed in larger projects is not worth it. Additionaly, SDL is one of the few libraries has mobile and emscript support.

## Why ES and Vulkan and not regular modern OpenGL?
I am a firm believer that all modern graphics projects should use Vulkan as it is the future of the industry and if used properly, its performance ceiling is higher than OpenGL.

Unfortunately, hardware support for Vulkan at this time is limited so some compromises should made to support older devices. This is where OpenGL ES 2 shines. Why ES over modern OpenGL? Since performance is being compromised for platform support, it would be better to go for the greatest platform support with our second implementation. ES supports more devices than modern OpenGL such as the very popular Raspberry Pi series of SBCs.

## Why C++?
Although I agree that C or Rust is are more suitable languages than C++ in most implementations, I can't ignore the usefullness of OOP and C++'s zero-cost abstractions and extremely powerful meta-programming. These tools will help reduce development time while keeping performance at a maximum.

## Examples
- hello-triangle: The most basic 2d application. A simple triangle drawn on screen.
- pong: A clone of the simple 2d game for the Atari 2600.
- side-scroller: A simple side scroller 2d game similar to the original Sonic or Mario games.
- dungeon-crawler: A simple top-down rogue-like dungeon crawler game similar to binding of issac.
- hello-cube: The most basic 3d application that consists of a rotation cube in 3d space.
- model-renderer: The most basic application that will render a model in 3d space.
- crossworld: A simple, explorable, 3d world with simple physics similar to VRChat.

All 3D models will use the glTF/GLB format

