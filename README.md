# GLAD Walnut

GLADWalnut is a simple application framework built with Dear ImGui and designed to be used with GLAD - basically this means you can seemlessly blend real-time GLAD rendering with a great UI library to build desktop applications. The plan is to expand Walnut to include common utilities to make immediate-mode desktop apps and simple GLAD applications. This is inspired from @TheCherno Walnut which was written in Vulkan api.

Currently supports Windows & Linux - with macOS planned. Setup scripts support Visual Studio 2022 by default.

## Requirements
- [Visual Studio 2022](https://visualstudio.com) (Only for Windows build.)

## Getting Started
Once you've cloned, run `scripts/Setup.bat` to generate Visual Studio 2022 solution/project files. You can use CMAKE for building project on linux. Once you've opened the solution, you can run the WalnutApp project to see a basic example (code in `WalnutApp.cpp`). I recommend modifying that WalnutApp project to create your own application, as everything should be setup and ready to go.

### 3rd party libaries
- [Dear ImGui](https://github.com/ocornut/imgui)
- [GLFW](https://github.com/glfw/glfw)
- [stb_image](https://github.com/nothings/stb)
- [GLM](https://github.com/g-truc/glm) (included for convenience)
- [GLAD](https://glad.dav1d.de/)

### Additional
- Walnut uses the [Roboto](https://fonts.google.com/specimen/Roboto) font ([Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0))

### Current known Bugs
None -:)
