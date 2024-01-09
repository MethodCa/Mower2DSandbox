# Mower 2D Sandbox
OpenGL 2D sandbox minigame, written in C++ using Blit3D[^1], a lightweight framework to write games using C / C++ additionally GLEW[^2] was used to help manage OpenGL extensions and GLFW2[^3] for window managemend with OpenGL and managing user input.

![image](https://github.com/MethodCa/Mower2DSandbox/assets/15893276/294a2212-2608-4a81-b013-488f9714fba5)

The mini-game was written to test the OpenGL mathematics library GLM[^4], sprites, texture atllas management, game object collisions and camera movement.

![mower](https://github.com/MethodCa/Mower2DSandbox/assets/15893276/9168736e-7337-4152-be49-5ad6ee0d3e88)

The mini-game simulates the behainour of a electric grass mower thats moves freely throughtout a pre-defined grass area, it coliides with opbstracules and area limits. When collision is encounter the mower's direction is changed using trigonometric functions:

https://github.com/MethodCa/Mower2DSandbox/blob/ab97dba68e5c40fe58ef527f6c32494583599d28/Blit3Dv3/main.cpp#L152C1-L157C2



> [!NOTE]
> Please ignore any artifacts or lower framerate in the GIF, these are products of the GIF compression, in execution the 3D model is displayed without artifacts and at 60 FPS.

[^1]: Blit3D, written by Darreb Reid: https://gibgezr.wixsite.com/blit3d
[^2]: GLEW - OpenGL Extension Wrangler Library https://glew.sourceforge.net/
[^3]: GLFW - Multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop https://www.glfw.org/
[^4]: GLM ttps://glm.g-truc.net/
