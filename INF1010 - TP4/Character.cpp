#include "Character.hpp"

template <	typename Key,typename T>
Character<	typename Key,typename T>::Character ( )
{
	name_ = "INVALID";
}

template <	typename Key,typename T>
Character<	typename Key,typename T>::Character( const Character& c)
{
	name_ = string(c.name_);
	class_ = ClassInfo(c.class_.getName(), c.class_.getDamageModel(), c.class_.getInitialSkills());
	baseSkills_ = SkillPoints();
	baseSkills_ baseSkills_+c.baseSkills_;
	realSkills_ = SkillPoints();
	realSkills_ = realSKills_+c.realSkills_;
	
	//pas sur
	for(map<Key,Powerup<T>>::iterator it = c.powerups_.begin(); it != m.end(); it++)
	{
		insertPowerup(it->first, Powerup(it->second, baseSkills_));
	}

}

template <	typename Key,typename T>
Character<	typename Key,typename T>::Character ( const string& nom, const ClassInfo<T>& classe)
{
	name_ = nom;
	class_ = classe;
}

template <	typename Key,typename T>
const string& Character<	typename Key,typename T>::getName ( ) const
{
	return name_;
}

template <	typename Key,typename T>
const ClassInfo<T>& Character<	typename Key,typename T>::getClass ( ) const
{
	return class_;
}

template <	typename Key,typename T>
const SkillPoints<T>& Character<	typename Key,typename T>::getBaseSkills ( ) const
{
	return baseSkills_;
}

template <	typename Key,typename T>
const SkillPoints<T>& Character<	typename Key,typename T>::getRealSkills ( ) const
{
	return realSkills_;
}

template <	typename Key,typename T>
const map<Key, Powerup<T>>& Character<	typename Key,typename T>::getPowerups ( ) const
{
	return powerups_;
}

template <	typename Key,typename T>
void Character<	typename Key,typename T>::setBaseSkills ( const SkillPoints<T>& sp)
{
	baseSkills_ = sp;
	realSkills_ = sp;
	for(map<Key,Powerup<T>>::iterator it = c.powerups_.begin(); it != m.end(); it++)
	{
		it->second.applyEffectOn(realSkills);
	}
}

template <	typename Key,typename T>
void Character<	typename Key,typename T>::addToBaseSkills ( const SkillPoints<T>& sp)
{
	baseSkills_ = baseSkills_ + sp;
	realSkills_ = sp;
	for(map<Key,Powerup<T>>::iterator it = c.powerups_.begin(); it != m.end(); it++)
	{
		it->second.applyEffectOn(realSkills);
	}
}


template < typename K, typename U >
ostream& operator << ( ostream&, const Character<K, U>& c)
{
	return o << c.name_ <<", "<<c.class_<<endl
			 <<"-     Fighting : "<<c.baseSkills_.fighting<<" + "
			 <<c.realSkills_.fighting-c.baseSkills_.fighting<<endl

			 <<"- Marksmanship : "<<c.baseSkills_.¸marksmanship<<" + "
			 <<c.realSkills_.¸marksmanship-baseSkills_.¸marksmanship<<endl

			 <<"-      Sorcery : "<<c.baseSkills_.sorcery<<" + "
			 <<c.realSkills_.sorcery-c.baseSkills_.sorcery<<endl

			 <<"- Damage : "<< c.computeDamageOutput()<<endl;
	
}

template <	typename Key,typename T>
T Character<typename Key,typename T>::computeDamageOutput ( ) const
{
	return class_.computeDamage(realSkills_);
}