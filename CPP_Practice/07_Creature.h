#pragma once

enum CreatureType
{
	e_Player = 0,
	e_Monster = 1,
};

class Creature
{
public:
	Creature(int creaturetype)
		: _creaturetype(creaturetype), _hp(0), _damage(0), _defence(0)
	{

	}

	virtual ~Creature()
	{

	}

	void OnHit(Creature* damageOwner);

	virtual void PrintInfo() = 0;

	bool isDead();
	
protected:
	int _creaturetype;
	int _hp;
	int _damage;
	int _defence;
};

