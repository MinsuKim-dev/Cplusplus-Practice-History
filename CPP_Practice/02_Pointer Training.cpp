#include <iostream>
using namespace std;

// �� ��� ����� �ּ� ���� ���(������)�� ���� �����ϱ�

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* monsterinfo);

int main()
{
	EnterLobby();
}

void EnterLobby()
{
	cout << "�κ�" << endl;
	StatInfo PlayerInfo;
	PlayerInfo = CreatePlayer(); 
	// �� ��� ����, �ӽ����� �����͸� �����ϰ� �ӽ� ������ ������ ������ �����ϴ� ����
	// ���� ������ ����

	StatInfo MonsterInfo;
	CreateMonster(&MonsterInfo);
	// �ּ� ���� ���, ���� �����͸� ���ų� ��ģ��.
}

StatInfo CreatePlayer()
{
	StatInfo ret;
	cout << "�÷��̾� ����" << endl;
	
	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 1;

	return ret;
}

void CreateMonster(StatInfo* monsterinfo)
{
	cout << "���� ����" << endl;
	monsterinfo->hp = 30;
	monsterinfo->attack = 3;
	monsterinfo->defence = 1;
}