#pragma once

class Player;
class Field;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Init();
	void Update();

	void CreatePlayer();

private:
	Player* _player;
	Field* _field;
};

