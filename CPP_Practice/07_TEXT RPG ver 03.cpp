#include <iostream>
using namespace std;

#include "07_GameManager.h"

// TEXT RPG�� ��ü�� Ȱ���� ����� ����

int main()
{
	srand((unsigned int)time(nullptr));
	GameManager Game;
	Game.Init();

	while (true)
	{
		Game.Update();
	}
}