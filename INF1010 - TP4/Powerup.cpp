#include "Powerup.hpp"

template < typename T >
Powerup<T>::Powerup ( const Bonus<T>* bonus= nullptr, const SkillPoints<T>* skillPoints= nullptr )
{
	targetBasePoints_ = skillPoints;
	effect_ = bonus;
}

template < typename T >
void Powerup<T>::applyEffectOn ( SkillPoints<T>& sp)
{
	sp= sp+effect_->compute(sp);
}

template < typename T >
void Powerup<T>::removeEffectFrom ( SkillPoints<T>& sp)
{
	sp= sp-effect_->compute(sp);
}

template < typename T >
const SkillPoints<T>* Powerup<T>::getTargetBasePoints ( ) const
{
	return targetBasePoints_;
}

template < typename T >
const Bonus<T>* Powerup<T>::getEffect ( ) const
{
	return effect_;
}
