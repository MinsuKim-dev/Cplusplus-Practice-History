#include <iostream>
using namespace std;
// 전역 변수를 활용한 텍스트 알피지

// 만들어야 하는 함수 리스트
// 메세지를 출력하는 함수
// 로비에 입장하는 함수
// 캐릭터를 선택하는 함수
// 필드에 입장하는 함수
// 랜덤 몬스터를 생성하는 함수
// 전투에 입장하는 함수 (로비 재입장)

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
	MT_SKELETON = 3,
};

struct CreatureInfo
{
	int type;
	int hp;
	int attack;
	int defence;
};

CreatureInfo PlayerInfo;
CreatureInfo MonsterInfo;

void PrintMessage(const char* msg);
void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	srand((unsigned)time(nullptr));
	EnterLobby();
}

void PrintMessage(const char* msg)
{
	cout << "-------------------------------------" << endl;
	cout << msg << endl;
	cout << "-------------------------------------" << endl;
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("로비에 입장했습니다.");

		SelectPlayer();

		PrintMessage("[1] 필드 입장 [2] 게임 종료");

		int PlayerInput;
		cin >> PlayerInput;

		if (PlayerInput == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlayer()
{
	while (true)
	{
		PrintMessage("직업을 선택해주세요.");
		PrintMessage("[1] 기사 [2] 궁수 [3] 법사");
		cout << "> ";

		cin >> PlayerInfo.type;

		if (PlayerInfo.type == PT_KINGHT)
		{
			PrintMessage("기사 생성중... !");
			PlayerInfo.hp = 100;
			PlayerInfo.attack = 10;
			PlayerInfo.defence = 5;
			break;
		}
		else if (PlayerInfo.type == PT_ARCHER)
		{
			PrintMessage("궁수 생성중... !");
			PlayerInfo.hp = 80;
			PlayerInfo.attack = 20;
			PlayerInfo.defence = 3;
			break;
		}
		else if (PlayerInfo.type == PT_MAGE)
		{
			PrintMessage("법사 생성중... !");
			PlayerInfo.hp = 60;
			PlayerInfo.attack = 25;
			PlayerInfo.defence = 0;
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		PrintMessage("필드에 입장했습니다.");

		cout << "PLAYER HP : " << PlayerInfo.hp << " PLAYER ATT : " << PlayerInfo.attack << " PLAYER DEF : " << PlayerInfo.defence << endl;

		CreateRandomMonster();

		PrintMessage("[1] 전투 [2] 도주");
		cout << "> ";

		int PlayerInput;
		cin >> PlayerInput;

		if (PlayerInput == 1)
		{
			EnterBattle();
			{
				if (PlayerInfo.hp == 0)
					return;
			}
		}
		else
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	MonsterInfo.type = 1 + (rand() % 3);

	switch (MonsterInfo.type)
	{
	case MT_SLIME:
		cout << "슬라임 생성중... !" << endl;
		MonsterInfo.hp = 15;
		MonsterInfo.attack = 6;
		MonsterInfo.defence = 0;
		cout << "MONSTER HP : " << MonsterInfo.hp << " MONSTER ATT : " << MonsterInfo.attack << " MONSTER DEF : " << MonsterInfo.defence << endl;
		break;
	case MT_ORC:
		cout << "오크 생성중... !" << endl;
		MonsterInfo.hp = 30;
		MonsterInfo.attack = 9;
		MonsterInfo.defence = 2;
		cout << "MONSTER HP : " << MonsterInfo.hp << " MONSTER ATT : " << MonsterInfo.attack << " MONSTER DEF : " << MonsterInfo.defence << endl;
		break;
	case MT_SKELETON:
		cout << "해골 생성중... !" << endl;
		MonsterInfo.hp = 50;
		MonsterInfo.attack = 14;
		MonsterInfo.defence = 3;
		cout << "MONSTER HP : " << MonsterInfo.hp << " MONSTER ATT : " << MonsterInfo.attack << " MONSTER DEF : " << MonsterInfo.defence << endl;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = PlayerInfo.attack - MonsterInfo.defence;
		if (damage < 0)
			damage = 0;

		MonsterInfo.hp -= damage;
		if (MonsterInfo.hp < 0)
			MonsterInfo.hp = 0;

		cout << "몬스터 남은 체력: " << MonsterInfo.hp << endl;
		
		if (MonsterInfo.hp == 0)
		{
			PrintMessage("몬스터를 처치했습니다.");
			return;
		}

		damage = MonsterInfo.attack - PlayerInfo.defence; 
		if (damage < 0)
			damage = 0;

		PlayerInfo.hp -= damage;
		if (PlayerInfo.hp < 0)
			PlayerInfo.hp = 0;

		cout << "플레이어 남은 체력: " << PlayerInfo.hp << endl;

		if (PlayerInfo.hp == 0)
		{
			PrintMessage("GAME OVER.");
			return;
		}
	}
}