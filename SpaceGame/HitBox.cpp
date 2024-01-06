#include "HitBox.h"

//functions
void HitBox::setHitbox(const sf::FloatRect& hitbox)
{
	this->m_hitbox = hitbox;
}
sf::FloatRect HitBox::getGlobalHitbox() const
{
	return getTransform().transformRect(this->m_hitbox);
}



