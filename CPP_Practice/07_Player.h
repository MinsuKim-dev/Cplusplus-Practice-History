#pragma once
#include "07_Creature.h"

enum PlayerType
{
	e_Knight = 1,
	e_Archer = 2,
	e_Mage = 3,
};

class Player : public Creature
{
public:
	Player(int playertype) : Creature(e_Player), _playertype(playertype)
	{

	}

	~Player()
	{

	}

	void PrintInfo();

protected:
	int _playertype;
};

class Knight : public Player
{
public:
	Knight() : Player(e_Knight)
	{
		_hp = 150;
		_damage = 10;
		_defence = 5;
	}

};

class Archer : public Player
{
public:
	Archer() : Player(e_Archer)
	{
		_hp = 80;
		_damage = 15;
		_defence = 3;
	}

};

class Mage : public Player
{
public:
	Mage() : Player(e_Mage)
	{
		_hp = 50;
		_damage = 25;
		_defence = 1;
	}

};