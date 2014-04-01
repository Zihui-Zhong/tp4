////////////////////////////////////////////////////////////////////////////////
//        FILE : Character.hpp
//      AUTHOR : 
//        DATE :   Creation : 
//               Last entry : 
// DESCRIPTION :
////////////////////////////////////////////////////////////////////////////////

#pragma once


//{ Includes and usings

#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>

#include "SkillPoints.hpp"
#include "ClassInfo.hpp"
#include "Powerup.hpp"


using namespace std;

//}


//{ Declarations

//{ Classes

template <
	typename Key,
	typename T
>
class Character
{
public:
	// Friends
	template < typename K, typename U >
	  friend
	ostream& operator << ( ostream&, const Character<K, U>& c);
	
	// Constructors and destructor
	Character ( )
	{
		name_ = "INVALID";
	}

	Character( const Character& c)
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

	Character ( const string& nom, const ClassInfo<T>& classe)
	{
		name_ = nom;
		class_ = classe;
	}
	
	// Modifying methods
	void setBaseSkills ( const SkillPoints<T>& sp)
	{
		baseSkills_ = sp;
		realSkills_ = baseSkills_;
		computeRealSkills();
	}

	void addToBaseSkills ( const SkillPoints<T>& sp)
	{
		baseSkills_ = baseSkills_ + sp;
		computeRealSkills();
	}
	
	void insertPowerup ( const Key& key, const Powerup<T>& p)
	{
		powerups_[key] = p;
		computeRealSkills();
	}

	void removePowerup ( const Key& key)
	{
		powerups_.erase(key);
		computeRealSkills();
	}
	
	// Non-modifying methods
	const string& getName ( ) const
	{
		return name_;
	}

	const ClassInfo<T>& getClass ( ) const
	{
		return class_;
	}

	const SkillPoints<T>& getBaseSkills ( ) const
	{
		return baseSkills_;
	}

	const SkillPoints<T>& getRealSkills ( ) const
	{
		return realSkills_;
	}

	const map<Key, Powerup<T>>& getPowerups ( ) const
	{
		return powerups_;
	}	
	
	void print ( ) const
	{
		cout<<(*this);
		/*cout<< name_ <<", "<<class_.getName()<<endl
			<<"-     Fighting : "<<baseSkills_.fighting<<" + "
			<<realSkills_.fighting-baseSkills_.fighting<<endl

			<<"- Marksmanship : "<<baseSkills_.marksmanship<<" + "
			<<realSkills_.marksmanship-baseSkills_.marksmanship<<endl
	
			<<"-      Sorcery : "<<baseSkills_.sorcery<<" + "
			<<realSkills_.sorcery-baseSkills_.sorcery<<endl
			<<"- Damage : "<< computeDamageOutput()<<endl;*/
	}

	T computeDamageOutput ( ) const
	{
		return class_.computeDamage(realSkills_);
	}


protected:
	              string name_;
	        ClassInfo<T> class_;
	      SkillPoints<T> baseSkills_;  // Avant application des powerups.
	      SkillPoints<T> realSkills_;  // Après application des powerups.
	map<Key, Powerup<T>> powerups_;

	void computeRealSkills()
	{
		realSkills_ = baseSkills_;
		for(map<Key,Powerup<T>>::iterator it = c.powerups_.begin(); it != m.end(); it++)
		{
			it->second.applyEffectOn(realSkills);
		}
	}
};

//}


//{ Globals

template <
	typename Key,
	typename T
>
ostream& operator << ( ostream& o, const Character<Key, T>& c)
{
	return o << c.name_ <<", "<<c.class_.getName()<<endl
			 <<"-     Fighting : "<<c.baseSkills_.fighting<<" + "
			 <<c.realSkills_.fighting-c.baseSkills_.fighting<<endl

			 <<"- Marksmanship : "<<c.baseSkills_.marksmanship<<" + "
			 <<c.realSkills_.marksmanship-c.baseSkills_.marksmanship<<endl
	
			 <<"-      Sorcery : "<<c.baseSkills_.sorcery<<" + "
			 <<c.realSkills_.sorcery-c.baseSkills_.sorcery<<endl
	
			 <<"- Damage : "<< c.computeDamageOutput()<<endl;	
}
//}

//}

