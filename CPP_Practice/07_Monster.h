#pragma once
#include "07_Creature.h"

enum MonsterType
{
	e_Slime = 1,
	e_Orc = 2,
	e_Skeleton = 3,
};

class Monster : public Creature
{
public:
	Monster(int monstertype) : Creature(e_Monster), _monstertype(monstertype)
	{

	}

	void PrintInfo();

protected:
	int _monstertype;
};

class Slime : public Monster
{
public:
	Slime() : Monster(e_Slime)
	{
		_hp = 50;
		_damage = 5;
		_defence = 2;
	}
};

class Orc : public Monster
{
public:
	Orc() : Monster(e_Orc)
	{
		_hp = 80;
		_damage = 8;
		_defence = 3;
	}
};

class Skeleton : public Monster
{
public:
	Skeleton() : Monster(e_Skeleton)
	{
		_hp = 100;
		_damage = 10;
		_defence = 4;
	}
};


