#include <iostream>
using namespace std;

// 포인터, 참조, 배열을 활용한 텍스트 알피지

// 만들어야 할 함수와 구조
// main
// PrintMessage
// - EnterLobby
// --CreatePlayer
// --EnterGame
// ---CreateMonsters
// ---EnterBattle

enum PlayerType
{
	PT_KINGHT = 1,
	PT_ARCHER = 2,
	PT_MAGE = 3,
};

enum MonsterType
{
	MT_SLIME = 1,
	MT_ORC = 2,
	MT_SKELTON = 3,
};

struct StatInfo
{
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void PrintMessage(const char* msg);
void EnterLobby();
void CreatePlayer(StatInfo* playerinfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerinfo);
void CreateMonser(StatInfo* monsterinfo, int count);
bool EnterBattle(StatInfo* playerinfo, StatInfo* monsterinfo);

int main()
{
	srand((unsigned)time(nullptr));
	EnterLobby();
}

void PrintMessage(const char* msg)
{
	cout << "****************************************" << endl;
	cout << msg << endl;
	cout << "****************************************" << endl;
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("로비에 입장했습니다.");
		StatInfo PlayerInfo;
		CreatePlayer(&PlayerInfo);
		PrintStatInfo("PLAYER", PlayerInfo);
		EnterGame(&PlayerInfo);
	}
}

void CreatePlayer(StatInfo* playerinfo)
{
	bool GameReady = false;
	while (GameReady == false)
	{
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 법사");
		
		int PlayerInput;
		cin >> PlayerInput;
		cout << "> ";

		switch (PlayerInput)
		{
		case PT_KINGHT:
			playerinfo->hp = 100;
			playerinfo->attack = 10;
			playerinfo->defence = 5;
			GameReady = true;
			break;
		case PT_ARCHER:
			playerinfo->hp = 80;
			playerinfo->attack = 15;
			playerinfo->defence = 3;
			GameReady = true;
			break;
		case PT_MAGE:
			playerinfo->hp = 50;
			playerinfo->attack = 25;
			playerinfo->defence = 1;
			GameReady = true;
			break;
		}
	}
}

void PrintStatInfo(const char* name, const StatInfo& info) // 참조, 읽기 전용
{
	cout << "****************************************" << endl;
	cout << name << " HP = " << info.hp << " ATT = " << info.hp << " DEF = " << info.defence << endl;
	cout << "****************************************" << endl;
}

void EnterGame(StatInfo* playerinfo)
{
	const int MonsterCount = 2;
	PrintMessage("게임에 입장했습니다.");

	while (true)
	{
		StatInfo MonsterInfo[MonsterCount];
		CreateMonser(MonsterInfo, MonsterCount);
		for (int i = 0; i < MonsterCount; i++)
		{
			PrintStatInfo("MONSTER", MonsterInfo[i]);
		}
		PrintStatInfo("PLAYER", *playerinfo);

		PrintMessage("[1] 1번 몬스터와 전투 [2] 2번 몬스터와 전투 [3] 도망");
		int PlayerInput;
		cin >> PlayerInput;

		if (PlayerInput == 1 || PlayerInput == 2)
		{
			int MonsterIndex = PlayerInput - 1;
			bool Victory = EnterBattle(playerinfo, &(MonsterInfo[MonsterIndex]));
			if (Victory == false)
				break;
		}
	}
}

void CreateMonser(StatInfo* monsterinfo, int count)
{
	for (int i = 0; i < count; i++)
	{
		int RandomValue = 1 + (rand() % 3);

		switch (RandomValue)
		{
		case MT_SLIME:
			monsterinfo[i].hp = 30;
			monsterinfo[i].attack = 5;
			monsterinfo[i].defence = 1;
			break;
		case MT_ORC:
			monsterinfo[i].hp = 40;
			monsterinfo[i].attack = 8;
			monsterinfo[i].defence = 2;
			break;
		case MT_SKELTON:
			monsterinfo[i].hp = 50;
			monsterinfo[i].attack = 15;
			monsterinfo[i].defence = 3;
			break;
		}
	}
}

bool EnterBattle(StatInfo* playerinfo, StatInfo* monsterinfo)
{
	while (true)
	{
		int damage = playerinfo->attack - monsterinfo->defence;
		if (damage < 0)
			damage = 0;

		monsterinfo->hp -= damage;
		if (monsterinfo->hp < 0)
			monsterinfo->hp = 0;

		PrintStatInfo("MONSTER", *monsterinfo);

		if (monsterinfo->hp == 0)
		{
			PrintMessage("몬스터를 처지했습니다.");
			return true;
		}

		damage = monsterinfo->attack - playerinfo->defence;
		if (damage < 0)
			damage = 0;

		playerinfo->hp -= damage;
		if (playerinfo->hp < 0)
			playerinfo->hp = 0;

		PrintStatInfo("PLAYER", *playerinfo);

		if (playerinfo->hp == 0)
		{
			PrintMessage("Game Over");
			return false;
		}
	}
}
