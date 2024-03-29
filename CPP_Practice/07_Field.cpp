#include "07_Field.h"
#include <stdlib.h>
#include "07_Monster.h"
#include "07_Player.h"

Field::Field() : _monster(nullptr)
{

}

Field::~Field()
{
	if (_monster != nullptr)
		delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();

	StartBattle(player);
}

void Field::CreateMonster()
{
	int RandomValue = 1 + (rand() % 3);

	switch (RandomValue)
	{
	case e_Slime:
		_monster = new Slime;
	case e_Orc:
		_monster = new Orc;
	case e_Skeleton:
		_monster = new Skeleton;
	default:
		break;
	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		_monster->OnHit(player);

		if (_monster->isDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}

		player->OnHit(_monster);

		if (player->isDead())
		{
			player->isDead();
			break;
		}
	}
}
