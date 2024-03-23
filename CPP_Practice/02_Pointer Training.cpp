#include <iostream>
using namespace std;

// 값 방식 복사와 주소 전달 방식(포인터)의 차이 이해하기

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
	cout << "로비" << endl;
	StatInfo PlayerInfo;
	PlayerInfo = CreatePlayer(); 
	// 값 방식 복사, 임시적인 데이터를 생성하고 임시 데이터 공간에 복사후 대입하는 과정
	// 스택 프레임 이해

	StatInfo MonsterInfo;
	CreateMonster(&MonsterInfo);
	// 주소 전달 방식, 직접 데이터를 쓰거나 고친다.
}

StatInfo CreatePlayer()
{
	StatInfo ret;
	cout << "플레이어 생성" << endl;
	
	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 1;

	return ret;
}

void CreateMonster(StatInfo* monsterinfo)
{
	cout << "몬스터 생성" << endl;
	monsterinfo->hp = 30;
	monsterinfo->attack = 3;
	monsterinfo->defence = 1;
}