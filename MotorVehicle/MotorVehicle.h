//#pragma once
//#include <string>
#include <iostream>
#include <string>

using namespace std;

class Body;
class Engine;

class Owner
{
private:
	string name;
	string address;
	bool allowedToDrive;
public:
	Owner();
	Owner(string sname, string saddress, bool ballowedToDrive);
	void print();
};

class Engine
{
private:
	float sizeInLitres;
	int numberOfCylinders;
	//Body* b;
public:
	Engine(float engineSize, int numberOfCyl);
	Engine();
	void print();
};

class Body
{
private:
	string color;
	float width, height;
public:
	Body(string c, float w, float h);
	Body();
	//Engine e;
	void print();
};

class MotorVehicle
{
private:
	Engine engine;
	Body body;
	Owner owner;
	float* tireDiameters;
	int numberOfTires;
	string model;
public:
	MotorVehicle(Engine e, Body b, Owner o, float* td, int numberot, string m);
	MotorVehicle();
	~MotorVehicle();
	void print();
};