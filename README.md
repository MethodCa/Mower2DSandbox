# Mower 2D Sandbox
OpenGL 2D sandbox minigame, written in C++ using Blit3D[^1], a lightweight framework to write games using C / C++ additionally GLEW[^2] was used to help manage OpenGL extensions and GLFW[^3] for window managemend with OpenGL and managing user input.

![image](https://github.com/MethodCa/Mower2DSandbox/assets/15893276/294a2212-2608-4a81-b013-488f9714fba5)

The mini-game was written to test the OpenGL mathematics library GLM[^4], sprites, texture atllas management, game object collisions and camera movement.

![mower](https://github.com/MethodCa/Mower2DSandbox/assets/15893276/9168736e-7337-4152-be49-5ad6ee0d3e88)

The mini-game simulates the behaviour of an electric grass mower that moves freely throughout a pre-defined grass area and collides with obstacles and area limits. When a collision is encountered the mower's direction is changed using trigonometric functions as shown in the next code snipped:

```c++
glm::vec2 calculateDirection(float angle, float velocity, float deltaTime)
{
	float radianAngle = glm::radians(angle);
	glm::vec2 direction = glm::vec2(sin(radianAngle), cos(radianAngle));
	return direction * velocity * deltaTime;
}
```

The mower has a battery that lasts 50 seconds, after the battery has depleted its charge the mower will return to its docking station to recharge for 5 seconds.

![mowertodock](https://github.com/MethodCa/Mower2DSandbox/assets/15893276/ef005b4d-ac47-4b42-9fd2-58a206fecd25)


> [!NOTE]
> Please ignore any artifacts or lower framerate in the GIF, these are products of the GIF compression, in execution the 3D model is displayed without artifacts and at 60 FPS.

[^1]: Written by Darreb Reid: [Blid3d](https://gibgezr.wixsite.com/blit3d)
[^2]: OpenGL Extension Wrangler Library [GLEW](https://glew.sourceforge.net/)_
[^3]: Multi-platform library for OpenGL, OpenGL ES and Vulkan development. [GLFW](https://www.glfw.org/)
[^4]: OpenGL mathematics library [GLM](ttps://glm.g-truc.net/)
