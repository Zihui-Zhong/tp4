////////////////////////////////////////////////////////////////////////////////
//        FILE : Character.hpp
//      AUTHOR : Zihui Zhong, Pascal Desrochers
//        DATE : 31 mars 2014  
//               Last entry : 31 mars 2014
// DESCRIPTION : Classe d'un personnage
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
	
		for(map<Key,Powerup<T>>::iterator it = c.powerups_.begin(); it != m.end(); it++)
		{
			insertPowerup(it->first, Powerup(it->second, baseSkills_));
		}
	}

	Character ( const string& nom, const ClassInfo<T>& classe)
	{
		name_ = nom;
		class_ = classe;
		baseSkills_=classe.getInitialSkills();
		computeRealSkills();
	}
	
	// Modifying methods
	void setBaseSkills ( const SkillPoints<T>& sp)
	{
		baseSkills_ = sp;
		computeRealSkills();
	}

	void addToBaseSkills ( const SkillPoints<T>& sp)
	{
		baseSkills_ = baseSkills_ + sp;
		computeRealSkills();
	}
	
	/**
	* Ajoute un nouveau powerup au personnage
	* @param key cle du powerup
	* @param p powerup a ajouter
	*/
	void insertPowerup ( const Key& key, const Powerup<T>& p)
	{
		powerups_[key] = p;
		computeRealSkills();
	}

	/**
	* Retire un powerup du personnage
	* @param key cle du powerup
	*/
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
	}

	/**
	* Calcul les dommages inflige du personnage
	*/
	T computeDamageOutput ( ) const
	{
		return class_.computeDamage(realSkills_);
	}

	//Non modifying operator


protected:
	              string name_;
	        ClassInfo<T> class_;
	      SkillPoints<T> baseSkills_;  // Avant application des powerups.
	      SkillPoints<T> realSkills_;  // Après application des powerups.
	map<Key, Powerup<T>> powerups_;


	/**
	* Calcul les realSkills_ en appliquant tous les powerups sur les baseSkill_
	*/
	void computeRealSkills()
	{
		realSkills_ = baseSkills_;
		for(map<Key,Powerup<T>>::iterator it = powerups_.begin(); it != powerups_.end(); it++)
		{
			it->second.applyEffectOn(realSkills_);
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

