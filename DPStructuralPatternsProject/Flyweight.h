#pragma once
#include <iostream>
#include <map>
using namespace std;

class BookBad
{
	string title;
	string authorFirstName;
	string authorLastName;
public:
	BookBad(string title, string authorFirstName, string authorLastName)
		: title{ title }, authorFirstName{ authorFirstName }, authorLastName{ authorLastName } {}

};

class Author
{
	string authorFirstName;
	string authorLastName;
public:
	Author(string authorFirstName, string authorLastName)
		: authorFirstName{ authorFirstName }, authorLastName{ authorLastName } {}
};

class BookGood
{
	string title;
	Author* author;
public:
	BookGood(string title, Author* author)
		: title{ title }, author{ author } {}
};


enum TankCode
{
	Armata,
	T34
};
	

class TankType
{
	string name;
	string color;
	string texture;
public:
	TankType(string name, string color, string texture)
		: name{ name }, color{ color }, texture{ texture } {}
	void Draw(int x, int y)
	{
		cout << "Tank " << name << " draw in x = " << x << ", y = " << y << "\n";
	}
};

class TankFactory
{
	map<string, TankType*> tanksBase;
public:
	TankType* CreateTank(string name, string color, string texture)
	{
		if (tanksBase.find(name) == tanksBase.end())
		{
			TankType* tank = new TankType(name, color, texture);
			tanksBase.insert(make_pair(name, tank));
		}
		return tanksBase[name];
	}
};

class TankContext
{
	int x, y;
	TankType* tank;
public:
	TankContext(int x, int y, TankFactory* factory, string name, string color, string texture) : x{x}, y{y}
	{
		tank = factory->CreateTank(name, color, texture);
	}
	void Draw()
	{
		tank->Draw(x, y);
	}
};