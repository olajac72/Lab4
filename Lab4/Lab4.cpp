// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
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
}

class Vehicle
{
	Engine engine;
	Body body;
	Owner owner;
	float* tireDiameters;
	int numberOfTires;
	string model;
};

class Engine
{
	float sizeInLitres;
	int numberOfCylinders;
};

class Body
{
	string color;
	float width, height;
};

class Owner
{
private:
	string name;
	string address;
	bool allowedToDrive;
public:
	Owner() {};
	Owner(string sname, string saddress, bool ballowedToDrive);
	void print() {};
};

void Owner::print()
{
	cout << "Name:" << name << endl;
	cout << "Address:" << address << endl;
	cout << "Allowed to drive:" << allowedToDrive << endl;
}

Owner::Owner(string sname, string saddress, bool ballowedToDrive)
{
	name = sname;
	address = saddress;
	allowedToDrive = ballowedToDrive;
};
