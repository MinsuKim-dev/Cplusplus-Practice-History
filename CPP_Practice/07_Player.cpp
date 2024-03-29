#include "07_Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "------------------" << endl;
	cout << "[플레이어 정보] : " << "[HP] : " << _hp << " [Damage] : " << _damage << " [Defence] : " << _defence << endl;
	cout << "------------------" << endl;
}