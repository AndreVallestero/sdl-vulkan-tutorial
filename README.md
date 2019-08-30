# sdl-vulkan-tutorial
An in depth tutorial for SDL2 using Vulkan with examples written in C++. This tutorial aims to be cross platform in development, compilation and testing. All code will be as minimal as possible while being heavily documented, readable, and easy to understand.

## Why SDL2?
PLATFORM. SUPPORT.

Although alternatives like SFML and GLFW are significantly lighter and leaner, that amount of platform specific code needed in larger projects is not worth it. Additionaly, SDL is one of the few libraries has mobile and emscript support.

## Why Vulkan and not regular modern OpenGL?
I am a firm believer that all modern graphics projects should use Vulkan as it is the future of the industry and if used properly, its performance ceiling is higher than OpenGL.

## Why C++?
Although I agree that C or Rust are more suitable languages in most use cases, I can't ignore the usefullness of OOP and C++'s zero-cost abstractions and extremely powerful meta-programming. These tools will help reduce development time while keeping performance at a maximum.

## Why Meson?
When choosing a build system for this project, being able to compile on the 3 main platforms was the highest priority. Although I love the minimalism of Make(makefiles), there are far too many issues with trying to make it work on Windows even with mingw and cygwin.

The next logical step is to look towards CMake. CMake has been the gold standard in cross-platform development since it's inception, however, it's known to have performance issues and it's scripting language is overly complicated and often results in many issues. [SucklessOrg](https://suckless.org/sucks/) said it best: "[CMake is] so huge and bloated, compilation takes longer than compiling GCC!". 

That leaves us with Meson. Meson is much newer than the 2 previously mentioned systems. As such, it tries to combine the advantages of both and (mostly) leaves behind their issues. Meson is blazing fast as it primarily uses Ninja as the back-end for compilation. Additionally, the it uses its own (python-like) language and is completely platform agnostic. This makes it suitable for this project and I plan on using it for future projects as well.

## Examples
### 2D:

- **hello-triangle:** The most basic 2D application. A simple triangle drawn on screen.
- **pong:** A clone of the simple game for the Atari 2600.
- **side-scroller:** A simple side scroller game similar to the original Sonic or Mario games.
- **dungeon-crawler:** A simple top-down rogue-like dungeon crawler game similar to binding of issac.

### 3D:

- **hello-cube:** The most basic 3D application that consists of rotating cube.
- **model-renderer:** The most basic application that will render a model.
- **crossworld:** A simple, explorable world with simple physics similar to VRChat.

All 3D models will use the glTF/GLB format
