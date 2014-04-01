#include "ClassInfo.hpp"

template < typename T >
ClassInfo<T>::ClassInfo ( )
{
	name_ = "INVALID";
	damageModel_ = nullptr;
}

template < typename T >
ClassInfo<T>::ClassInfo ( const string& nom, const DamageModel<T>* damage, const SkillPoints<T>& skills)
{
	name_ = nom;
	damageModel_ = damage;
	initialSkills_ = skills;
}

template < typename T >
const ClassInfo<T>::string& getName ( ) const
{
	return name_;
}

template < typename T >
const ClassInfo<T>::DamageModel<T>* getDamageModel ( ) const
{
	return damageModel_;
}

template < typename T >
const ClassInfo<T>::SkillPoints<T>& getInitialSkills ( ) const
{
	return initialSkills_;
}

template < typename T >
T ClassInfo<T>::computeDamage ( const SkillPoints<T>& sp) const
{
	//pas sur
	T t= damageModel_->compute(sp);
	return t; 
}


bool ClassInfo<T>::operator == ( const ClassInfo& c) const
{
	return name_==c.name_;
}
