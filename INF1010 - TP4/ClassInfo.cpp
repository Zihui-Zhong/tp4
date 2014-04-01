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
const string& ClassInfo<T>::getName ( ) const
{
	return name_;
}

template < typename T >
const DamageModel<T>* ClassInfo<T>::getDamageModel ( ) const
{
	return damageModel_;
}

template < typename T >
const SkillPoints<T>& ClassInfo<T>::getInitialSkills ( ) const
{
	return initialSkills_;
}

template < typename T >
T ClassInfo<T>::computeDamage ( const SkillPoints<T>& sp) const
{
	return damageModel_->compute(sp);
}

template < typename T >
bool ClassInfo<T>::operator == ( const ClassInfo& c) const
{
	return name_==c.name_;
}
