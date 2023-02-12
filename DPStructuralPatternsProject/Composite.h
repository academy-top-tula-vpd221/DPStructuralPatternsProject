#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Component
class Unit
{
protected:
	int attack;
	string name;
public:
	Unit(string name) : name{ name } {}
	virtual int GetAtttack() = 0;
	virtual ~Unit() {}

	virtual string ToString()
	{
		string s = name + " " + to_string(GetAtttack());
		return s;
	}
};

class IFactory
{
public:
	virtual Unit* CreateUnit() = 0;
};

class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry")
	{
		this->attack = 5;
	}
	int GetAtttack() override
	{
		return attack;
	}
};

class InfantryUnitFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new InfantryUnit();
	}
};

class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer")
	{
		this->attack = 7;
	}
	int GetAtttack() override
	{
		return attack;
	}
};

class ArcherUnitFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new ArcherUnit();
	}
};

class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry")
	{
		this->attack = 10;
	}
	int GetAtttack() override
	{
		return attack;
	}
};

class CavalryUnitFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new CavalryUnit();
	}
};

class CompositeUnit : public Unit
{
	vector<Unit*> units;
public:
	CompositeUnit(string name) : Unit(name) {};
	void AddUnit(Unit* unit)
	{
		units.push_back(unit);
	}
	void RemoveUnit(int index)
	{
		units.erase(units.begin() + index);
	}

	int GetAtttack() override
	{
		int attackFull{};

		for (auto unit : units)
			attackFull += unit->GetAtttack();

		return attackFull;
	}

	string ToString() override
	{
		string s = name + " " + to_string(GetAtttack()) + "\n";
		for (auto unit : units)
			s += "\t" + unit->ToString() + "\n";
		s += "\n";
		return s;
	}
};

