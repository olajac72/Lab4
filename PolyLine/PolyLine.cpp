// Point2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PolyLine.h"


int main()
{
	float dist;
	Point2D p1(0, 0);
	Point2D p2(3, 4);
	Point2D p3;

	PolyLine pl;

	pl.Add(1, 2);
	pl.Add(3, 4);
	pl.print();
	pl.Remove();
	pl.Add(5, 6);
	pl.print();
	pl.Remove();
	pl.Remove();
	pl.print();
/*
	dist = p1.Distance(p2);
	cout << "Distance:" << dist << endl;

	p3 = p2;

	cout << "p3 :" << p3.toString() << endl;

	Point2D p4 = p2;

	cout << "p4 :" << p4.toString() << endl;

	Point2D p5 = p4 + p3;

	cout << "p5:" << p5.toString() << endl;

	dist = p5.Distance(p1);

	cout << "p5:" << p5.toString() << endl;

	if (p3 == p2)
		cout << "Same" << endl;
	else
		cout << "Not same" << endl;
*/
}

Point2D::Point2D(int x, int y) : x(x), y(y)
{

}

Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(const Point2D& p2d) // copy constructor
{
	x = p2d.x;
	y = p2d.y;
}
float Point2D::Distance(Point2D p2d)
{
	return (sqrt(pow(p2d.x, 2) + pow(p2d.y, 2)));
}
string Point2D::toString()
{
	string ret;

	ret = "[" + to_string(x) + "," + to_string(y) + "]";

	return ret;
}

Point2D Point2D::operator+(const Point2D& p2d)
{
	Point2D temp;

	temp.x = x + p2d.x;
	temp.y = y + p2d.y;

	return temp;
}
bool Point2D::operator== (const Point2D& p2d)
{
	if (x == p2d.x && y == p2d.y)
		return true;
	else
		return false;
}
Point2D& Point2D::operator=(const Point2D& p2d)
{
	x = p2d.x;
	y = p2d.y;
	return *this;
}

PolyLine::PolyLine()
{
	numberOfElements = 0;
	firstPoint2DElement = NULL;
	lastPoint2DElement = NULL;
	newPoint2d = NULL;

}

void PolyLine::print()
{
	Point2D* tempPoint = NULL;
	if (numberOfElements != 0)
	{
		tempPoint = firstPoint2DElement;
	}
	else
	{
		cout << "No elements" << endl;
	}
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << "Point nr:" << i << ":" << tempPoint->toString() << endl;
		tempPoint = tempPoint->next2dp;
	}
}

void PolyLine::Add(int x, int y)
{
	Point2D* tempPrevPoint;
	
	tempPrevPoint = lastPoint2DElement;

	newPoint2d = new Point2D(x, y);
	newPoint2d->next2dp = NULL;
	
	if (numberOfElements == 0)
	{
		newPoint2d->prev2dp = NULL;
		firstPoint2DElement = newPoint2d;	
	}
	else
	{
		lastPoint2DElement->next2dp = newPoint2d;
	}
	lastPoint2DElement = newPoint2d;

	if (numberOfElements == 0)
	{

	}
	else
	{
		lastPoint2DElement->prev2dp = tempPrevPoint;
	}
	numberOfElements++;
}

void PolyLine::Remove()
{
	Point2D* tempPointer;

	

	if (numberOfElements == 0)
	{

	}
	else
	{
		tempPointer = lastPoint2DElement->prev2dp;

		if (numberOfElements == 1)
		{
			
		}
		else
		{
			lastPoint2DElement->prev2dp->next2dp = NULL;
		}
		delete lastPoint2DElement;
		lastPoint2DElement = tempPointer;

		numberOfElements--;
	}
}
