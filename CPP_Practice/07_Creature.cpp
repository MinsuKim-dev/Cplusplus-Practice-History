#include "07_Creature.h"

void Creature::OnHit(Creature* damageOwner)
{
	int damage = damageOwner->_damage - _defence;
	if (damage < 0)
		damage = 0;

	_hp -= damage;

	if (_hp < 0)
		_hp = 0;
}

bool Creature::isDead()
{
	return _hp <= 0;
}