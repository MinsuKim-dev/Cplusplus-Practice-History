#include <iostream>
using namespace std;

#include "07_GameManager.h"

// TEXT RPG를 객체를 활용해 만들어 보기

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