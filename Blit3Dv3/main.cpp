//memory leak detection
#define CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif  // _DEBUG

#include "Blit3D.h"
#include <string>     // std::string, std::to_string
#include <random>
#include "glm/ext.hpp"
#include <array>
#include <vector>
#include <iostream>
#include <fstream>


//GLOBAL DATA
class Mower
{
public:
	Sprite* sprite = NULL;
	float velocity;
	glm::vec2 position;
	glm::vec2 direction;
};
class Util
{
public:
	int getAngle()
	{
		std::mt19937 rng;
		std::uniform_int_distribution<> randomOption(0, 1);
		std::uniform_int_distribution<> randomAngle(60, 120);
		int option = randomOption(rng);
		if (option == 0)
			return -1 * randomAngle(rng);
		else
			return randomAngle(rng);
	}

	std::vector< std::vector<int>> createDummyBoard()
	{
		std::vector< std::vector<int>> map;
		std::vector<int> x = { 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,1,1,1,1,1,5,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,2,5,1,1,1,1,1,1,5,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,1,1,1,1,1,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5 };
		map.push_back(x);
		x = { 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
		map.push_back(x);

		return map;
	}
};


float dt = 0;
Blit3D* blit3D = NULL;
Mower* mower = NULL;
Sprite* grass;
Sprite* mowedGrass;
Sprite* wood;
Sprite* dock;
Sprite* stone;
std::vector<glm::vec2> paths;
std::vector<glm::vec2> hits;
float angle = 90;
glm::vec2 lastPos;
std::vector< std::vector<int>> map;
std::vector< std::vector<int>> newMap;
int counter = 0;
bool lowBattery = false;
bool onEdge = false;
glm::vec2 lastCheckedTile;
int battery = 3000; // 50 Sec
int chargingTime = 300; // 5 sec
bool docked = false;
int moveCounter = 0;
int smartX = 1;
int smartY = -1;
int frames = 0;


glm::vec2 calculateDirection(float angle, float velocity, float deltaTime)
{
	float radianAngle = glm::radians(angle);
	glm::vec2 direction = glm::vec2(sin(radianAngle), cos(radianAngle));
	return direction * velocity * deltaTime;
}
bool mow(float angle, float velocity, float deltaTime)
{
	// If velocity is 0 there us no reason to mow.
	if (velocity == 0)
		return true;
	//Calculate the current framerate
	float perPixelVelocity = 1/ deltaTime;
	//Calculate the position of the mower in the next frame depending of its velocity ovet the time(deltatime) 
	glm::vec2 nextFramePosition = mower->position + calculateDirection(angle, velocity, deltaTime); 
	//Calculate the max distance to mow between the current-frame position and next-frame position, 
	//if there is an obstacule in the way this loop must stop and return the lastPos before impact
	float maxDistanceToMow = glm::distance(nextFramePosition, mower->position);
	//Save current-frame position.
	lastPos = mower->position;
	// Iterate to move the mower at 1px/frame to the next-frame position, needs to be moved at 1px/s to check all posible collisions.
	while (maxDistanceToMow >= 0.f)
	{
		//Update the mower position by 1px velocity to be able to check all possible positions during the frame.
		mower->position += calculateDirection(angle, perPixelVelocity, deltaTime);
	    //Check if the mower in the updated-position is on an obstaculeTile=5, if true the loop must finish.
		if (map[((int)mower->position.x) / 32 ][(int)(mower->position.y ) / 32] == 5)
		{
			return true;
		}
		//Check if the mower in the updated-position is on a grassTile=0, if true the tile must be replaced for a mowedTile=1
		if (map[(int)mower->position.x / 32][(int)mower->position.y / 32] == 0 && !lowBattery)
			map[(int)mower->position.x / 32][(int)mower->position.y / 32] = 1;
		//Save current-frame position for next iteration operations.
		lastPos = mower->position;
		//Update the distance to mow
		maxDistanceToMow--;
	}
	return false;
}
bool goToDock(){
	if (map[mower->position.x / 32][mower->position.y / 32] == 2)
	{
		mower->velocity = 0;
		mower->position = glm::vec2((int)(mower->position.x / 32) * 32 + 16, (int)(mower->position.y / 32) * 32 + 16);
		lastPos = mower->position;
		return true;
	}
	//Check if boundary points are hit and change angle acordingly:
	/*
	 X | X | X         X | X | X
	---+--+---        ---+--+---
	 X | R | X         X | R | X
	---+--+---        ---+--+---
	 X | X | X         X | X | X
	 Angle = -90
	*/
	bool p1, p2, p3, p4, p6, p7, p8, p9 = false;
	p1 = map[mower->position.x / 32 - 1][mower->position.y / 32 + 1] == 5 ? true : false;
	p2 = map[mower->position.x / 32][mower->position.y / 32 + 1] == 5 ? true : false;
	p3 = map[mower->position.x / 32 + 1][mower->position.y / 32 + 1] == 5 ? true : false;
	p4 = map[mower->position.x / 32 - 1][mower->position.y / 32] == 5 ? true : false;
	p6 = map[mower->position.x / 32 + 1][mower->position.y / 32] == 5 ? true : false;
	p7 = map[mower->position.x / 32 - 1][mower->position.y / 32 - 1] == 5 ? true : false;
	p8 = map[mower->position.x / 32][mower->position.y / 32 - 1] == 5 ? true : false;
	p9 = map[mower->position.x / 32 + 1][mower->position.y / 32 - 1] == 5 ? true : false;

	
	if (p1 && p2 && !p4) { angle = -90; return false; }
	if (!p1 && !p2 && p3) { angle = 0;   return false; }
	if (p3 && p6 && !p2) { angle = 0;   return false; }
	if (!p3 && !p6 && p9) { angle = 90;  return false;  }
	if (p6 && p9 && p8) { angle = 0;   return false; }
	if (p2 && p3 && p6) { angle = -90; return false; }
	if (p1 && p2 && p4) { angle = -180; return false; }
	if (!p2 && !p4 && p1) { angle = -90; return false; }
	if (p1 && p4 && !p2) { angle = 180; return false; }
	if (p4 && p7 && p8) { angle = 90;  return false; }
	if (!p4 && !p8 && p7) { angle = 180;   return false; }

	
	return false;
}

void Init()
{
	glClearColor(1.f, 1.0f, 1.0f, 0.0f);	//clear colour: r,g,b,a 	
	mower = new Mower;
	mower->sprite = blit3D->MakeSprite(640, 0, 32, 32, "Media\\atlas.png");
	grass = blit3D->MakeSprite(0, 0, 32, 32, "Media\\atlas.png");
	mowedGrass = blit3D->MakeSprite(256, 0, 32, 32, "Media\\atlas.png");
	wood = blit3D->MakeSprite(608, 0, 32, 32, "Media\\atlas.png");
	dock = blit3D->MakeSprite(320, 0, 32, 32, "Media\\atlas.png");
	stone = blit3D->MakeSprite(288, 0, 32, 32, "Media\\atlas.png");
	mower->position = glm::vec2(656, 367.6);
	mower->velocity = 200;
	lastPos = mower->position;
	map = Util().createDummyBoard();
	
	for (int j = 0; j < map[0].size(); j++)
	{
		std::vector<int> fila;
		for (int i = map.size() - 1; i >= 0; i-- )
		{
			fila.push_back(map[i][j]);
		}
		newMap.push_back(fila);
	}
	map = newMap;
}
void DeInit(void)
{
	if (mower != NULL) delete mower;
	//any sprites/fonts still allocated are freed automatically by the Blit3D object when we destroy it
}

void Update(double seconds)
{
	float deltaTime = static_cast<float>(seconds);
	// Force Maximum framerate of 60fps
	if (deltaTime <= 0.015)
		return;

	
	bool mowUntilDeflect = mow(angle, mower->velocity, deltaTime);
	mower->position = lastPos;

	if (mowUntilDeflect)
	{
		angle = (angle - 180) + Util().getAngle();
		int correctedAngle = (angle + (int)(abs(angle) / 360) * 360);
		angle = correctedAngle < 0 ? 360 + correctedAngle : correctedAngle;
		hits.push_back(mower->position);
	}

	if (battery <= 0) 
		lowBattery = true;

	if (lowBattery && docked)
		chargingTime -= deltaTime;

	if (lowBattery && !docked)
		docked = goToDock();
	if (lowBattery && docked && chargingTime <= 0)
	{
		lowBattery = false;
		docked = false;
		chargingTime = 100;
		battery = 3000;
		angle = 300;
		mower->velocity = 200;
	}
	battery -= deltaTime;
}
void Draw(void)
{
	// wipe the drawing surface clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//draw stuff here
	int offsetX = mower->position.x / 32 - (blit3D->screenWidth / 2) / 32 - 2;
	int offsetY = mower->position.y / 32 - (blit3D->screenHeight / 2)/ 32 - 2; 

	for (int i = offsetX <0? 0: offsetX; i < mower->position.x/32 + (blit3D->screenWidth / 32) && i<map.size(); i++) {
		for (int j = offsetY < 0 ? 0 : offsetY; j < mower->position.y / 32 + (blit3D->screenHeight / 32) && j < map[i].size(); j++) 
		{
			glm::vec2 pos = glm::vec2(i * 32 + 16 + blit3D->screenWidth / 2 - mower->position.x, j * 32 + 16 + blit3D->screenHeight / 2 - mower->position.y);
			switch (map[i][j])
			{
				case 0: grass->		Blit(pos.x, pos.y); break;
				case 1: mowedGrass->Blit(pos.x, pos.y); break;
				case 2: dock->		Blit(pos.x, pos.y); break;
				case 5: wood->		Blit(pos.x, pos.y); break;
				case 6: stone->     Blit(pos.x, pos.y); break;
			}
		}
	}
	mower->sprite->Blit(mower->position.x + blit3D->screenWidth/2  - mower->position.x, mower->position.y + blit3D->screenHeight/2 - mower->position.y);
	mower->sprite->angle+=10;
}

//the key codes/actions/mods for DoInput are from GLFW: check its documentation for their values
void DoInput(int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		blit3D->Quit(); //start the shutdown sequence
}
int main(int argc, char *argv[])
{
	//memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//set X to the memory allocation number in order to force a break on the allocation:
	//useful for debugging memory leaks, as long as your memory allocations are deterministic.
	//_crtBreakAlloc = X;

	blit3D = new Blit3D(Blit3DWindowModel::DECORATEDWINDOW, 1280, 720);

	//set our callback funcs
	blit3D->SetInit(Init);
	blit3D->SetDeInit(DeInit);
	blit3D->SetUpdate(Update);
	blit3D->SetDraw(Draw);
	blit3D->SetDoInput(DoInput);

	//Run() blocks until the window is closed
	blit3D->Run(Blit3DThreadModel::SINGLETHREADED);
	if (blit3D) delete blit3D;
}