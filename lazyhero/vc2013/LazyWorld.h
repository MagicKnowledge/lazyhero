#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <Box2D/Box2D.h>

#include <iostream>
#include <vector>

using namespace std;

#include "Block.h"
#include "Line.h"
#include "Entity.h"
#include "Hero.h"
#include "Camera2D.h"

class LazyWorld
{
	//static boxes
	//bool debug = true;
	int WORLD_WIDTH_BLOCK = 200;
	int WORLD_HEIGHT_BLOCK = 100;
	double WORLD_SCALE_BLOCK = 1;
	vector<vector<Block>> worldData;
	vector<Line2> blockOutlines;

	//entities
	vector<Entity *> worldEntities;
	Hero * hero;	//0th element of worldEntities (generated in buildLevel0() function - currently FALSE, actually in constructor)

	//overall physics
	b2World * physWorld;
	vector<b2Body *> physicsBodies;

	Timer deltaRenderTimer;
	Timer deltaPhysicsTimer;
	float deltaRender = 1.0;
	float deltaPhysics = 1.0;
	
public:
	//constructor
	LazyWorld();

	//init physics/graphics
	void initPhysics();

	//camera
	Camera2D cam;

	//levels
	void buildLevel0();
	vector<Line2> createWorldFromList();

	//physics/entity/test s***
	void createTestBox(double x, double y);
	b2Vec2 raycast(b2Vec2 p1, b2Vec2 p2);

	//update
	void stepPhysics();
	void stepAI();
	void render();

	//utility
	Block getBlockAt(int x, int y);
	int getBlockWidth();
	int getBlockHeight();
	double getBlockScale();
	b2World* getB2World();
	void setBlockAt(int x, int y, int type);
	void fillBlocks(int x1, int y1, int x2, int y2, int type);
	void addPhysicsBody(b2Body * newPhysBody);
	float getDeltaRender();
	float getDeltaPhysics();
	//destructor
	~LazyWorld();
};