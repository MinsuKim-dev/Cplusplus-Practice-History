#include "07_GameManager.h"
#include <iostream>
using namespace std;
#include "07_Player.h"
#include "07_Field.h"

GameManager::GameManager() : _player(nullptr), _field(nullptr)
{

}

GameManager::~GameManager()
{
	if (_player != nullptr)
		delete _player;
	if (_field != nullptr)
		delete _field;
}

void GameManager::Init()
{
	_field = new Field;
}

void GameManager::Update()
{
	if (_player == nullptr)
		CreatePlayer();

	if (_player->isDead())
	{
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}

	_field->Update(_player);
}

void GameManager::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "-----------------" << endl;
		cout << "캐릭터 생성" << endl;
		cout << "[1] 기사 [2] 궁수 [3] 법사" << endl;

		cout << "> ";

		int input = 0;
		cin >> input;

		if (input == e_Knight)
		{
			_player = new Knight;
		}
		else if (input == e_Archer)
		{
			_player = new Archer;
		}
		else if (input == e_Mage)
		{
			_player = new Mage;
		}
	}
}