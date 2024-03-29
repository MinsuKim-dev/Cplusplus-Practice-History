#include "07_Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "------------------" << endl;
	cout << "몬스터 정보 : " << "HP : " << _hp << " Damage : " << _damage << " Defence : " << _defence << endl;
	cout << "------------------" << endl;
}