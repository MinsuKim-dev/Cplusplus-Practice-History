#include <iostream>
using namespace std;
// ���� ������ Ȱ���� �ؽ�Ʈ ������

// ������ �ϴ� �Լ� ����Ʈ
// �޼����� ����ϴ� �Լ�
// �κ� �����ϴ� �Լ�
// ĳ���͸� �����ϴ� �Լ�
// �ʵ忡 �����ϴ� �Լ�
// ���� ���͸� �����ϴ� �Լ�
// ������ �����ϴ� �Լ� (�κ� ������)

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
		PrintMessage("�κ� �����߽��ϴ�.");

		SelectPlayer();

		PrintMessage("[1] �ʵ� ���� [2] ���� ����");

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
		PrintMessage("������ �������ּ���.");
		PrintMessage("[1] ��� [2] �ü� [3] ����");
		cout << "> ";

		cin >> PlayerInfo.type;

		if (PlayerInfo.type == PT_KINGHT)
		{
			PrintMessage("��� ������... !");
			PlayerInfo.hp = 100;
			PlayerInfo.attack = 10;
			PlayerInfo.defence = 5;
			break;
		}
		else if (PlayerInfo.type == PT_ARCHER)
		{
			PrintMessage("�ü� ������... !");
			PlayerInfo.hp = 80;
			PlayerInfo.attack = 20;
			PlayerInfo.defence = 3;
			break;
		}
		else if (PlayerInfo.type == PT_MAGE)
		{
			PrintMessage("���� ������... !");
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
		PrintMessage("�ʵ忡 �����߽��ϴ�.");

		cout << "PLAYER HP : " << PlayerInfo.hp << " PLAYER ATT : " << PlayerInfo.attack << " PLAYER DEF : " << PlayerInfo.defence << endl;

		CreateRandomMonster();

		PrintMessage("[1] ���� [2] ����");
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
		cout << "������ ������... !" << endl;
		MonsterInfo.hp = 15;
		MonsterInfo.attack = 6;
		MonsterInfo.defence = 0;
		cout << "MONSTER HP : " << MonsterInfo.hp << " MONSTER ATT : " << MonsterInfo.attack << " MONSTER DEF : " << MonsterInfo.defence << endl;
		break;
	case MT_ORC:
		cout << "��ũ ������... !" << endl;
		MonsterInfo.hp = 30;
		MonsterInfo.attack = 9;
		MonsterInfo.defence = 2;
		cout << "MONSTER HP : " << MonsterInfo.hp << " MONSTER ATT : " << MonsterInfo.attack << " MONSTER DEF : " << MonsterInfo.defence << endl;
		break;
	case MT_SKELETON:
		cout << "�ذ� ������... !" << endl;
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

		cout << "���� ���� ü��: " << MonsterInfo.hp << endl;
		
		if (MonsterInfo.hp == 0)
		{
			PrintMessage("���͸� óġ�߽��ϴ�.");
			return;
		}

		damage = MonsterInfo.attack - PlayerInfo.defence; 
		if (damage < 0)
			damage = 0;

		PlayerInfo.hp -= damage;
		if (PlayerInfo.hp < 0)
			PlayerInfo.hp = 0;

		cout << "�÷��̾� ���� ü��: " << PlayerInfo.hp << endl;

		if (PlayerInfo.hp == 0)
		{
			PrintMessage("GAME OVER.");
			return;
		}
	}
}