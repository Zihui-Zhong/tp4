#include "Character.hpp"

template <	typename Key,typename T>
Character::Character ( )
{
	name_ = "INVALID";
}

template <	typename Key,typename T>
Character::Character ( const Character& c)
{
	name_ = string(c.name_);
	class_ = ClassInfo(c.class_.getName(), c.class_.getDamageModel(), c.class_.getInitialSkills());
	baseSkills_ = SkillPoints();
	baseSkills_ baseSkills_+c.baseSkills_;
	realSkills_ = SkillPoints();
	realSkills_ = realSKills_+c.realSkills_;

	//copier maps ici
}

template <	typename Key,typename T>
Character::Character ( const string& nom, const ClassInfo<T>& classe)
{
	name_ = nom;
	class_ = classe;
}

template <	typename Key,typename T>
const string& Character::getName ( ) const
{
	return name_;
}

template <	typename Key,typename T>
const ClassInfo<T>& Character::getClass ( ) const
{
	return class_;
}

template <	typename Key,typename T>
const SkillPoints<T>& Character::getBaseSkills ( ) const
{
	return baseSkills_;
}

template <	typename Key,typename T>
const SkillPoints<T>& Character::getRealSkills ( ) const
{
	return realSkills_;
}

template <	typename Key,typename T>
const map<Key, Powerup<T>>& Character::getPowerups ( ) const
{
	return powerups_;
}

void Character::setBaseSkills ( const SkillPoints<T>& sp)
{
	//avertissement sur real skills?
	baseSkills_ = sp;
}