// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "MotorVehicle.h"

//using namespace std;

int main()
{
	/*
	Owner* op;
	string name;
	string address;
	bool atd;

	cout << "Enter Owner data" << endl;
	cout << "Name :";
	cin >> name;
	cout << "Address :";
	cin >> address;
	cout << "Allowed to drive (1/0) :";
	cin >> atd;


	op = new Owner(name, address, atd);

	cout << endl;

	op->print();
	*/

	MotorVehicle mv;

	cout << "MV constructed" << endl;
}

MotorVehicle::MotorVehicle(Engine e, Body b, Owner o, float* td, int numberot, string m)
{
	engine = e;
	body = b;
	owner = o;
	tireDiameters = new float[numberot];
	numberOfTires = numberot;
	model = m;

	for (int i = 0; i < numberOfTires; i++)
	{
		tireDiameters[i] = td[i];
	}
}

MotorVehicle::MotorVehicle()
{
	cout << "MotorVehicle" << endl;

	tireDiameters = NULL;
	numberOfTires = 0;
	model = "";
}

MotorVehicle::~MotorVehicle()
{
	delete[] tireDiameters;
}

void MotorVehicle::print()
{
	cout << "Model" << model << endl;
	cout << "Number of tires:" << numberOfTires << endl;

	for (int i = 0; i < numberOfTires; i++)
	{
		cout << "Tire dimension tire nr: " << i << ":" << tireDiameters[i] << endl;
	}

	owner.print();
	engine.print();
	body.print();

}
void Owner::print()
{
	cout << "Name:" << name << endl;
	cout << "Address:" << address << endl;
	cout << "Allowed to drive:" << allowedToDrive << endl;
}

Owner::Owner()
{
	cout << "Owner" << endl;
	name = "";
	address = "";
	allowedToDrive = 0;
}

Owner::Owner(string sname, string saddress, bool ballowedToDrive)
{
	cout << "Owner" << endl;
 	name = sname;
	address = saddress;
	allowedToDrive = ballowedToDrive;
};

Engine::Engine(float engineSize, int numberOfCyl)
{
	cout << "Engine" << endl;
	sizeInLitres = engineSize;
	numberOfCylinders = numberOfCyl;
}

Engine::Engine()
{
	cout << "Engine" << endl;
	sizeInLitres = 0;
	numberOfCylinders = 0;
}

void Engine::print()
{
	cout << "Engine size:" << sizeInLitres << endl;
	cout << "Number of cylinders:" << numberOfCylinders << endl;
}

Body::Body(string c, float w, float h) : color(c), width(w), height(h)
{
	cout << "Body" << endl;
}

Body::Body()
{
	cout << "Body" << endl;

	color = "";
	width = 0.0;
	height = 0.0;
}
void Body::print()
{
	cout << "Color:" << color << endl;
	cout << "Width:" << width << endl;
	cout << "Height:" << height << endl;
}