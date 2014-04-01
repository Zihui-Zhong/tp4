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
	ostream& operator << ( ostream&, const Character<K, U>& );
	
	
	// Constructors and destructor
	Character ( );
	Character ( const Character& c);
	Character ( const string& nom, const ClassInfo<T>& classe);
	
	// Modifying methods
	void setBaseSkills ( const SkillPoints<T>& sp);
	void addToBaseSkills ( const SkillPoints<T>& );
	
	void insertPowerup ( const Key&, const Powerup<T>& );
	void removePowerup ( const Key& );
	
	// Non-modifying methods
	              const string& getName ( ) const;
	        const ClassInfo<T>& getClass ( ) const;
	      const SkillPoints<T>& getBaseSkills ( ) const;
	      const SkillPoints<T>& getRealSkills ( ) const;
	const map<Key, Powerup<T>>& getPowerups ( ) const;
	
	void print ( ) const;
	   T computeDamageOutput ( ) const;


protected:
	              string name_;
	        ClassInfo<T> class_;
	      SkillPoints<T> baseSkills_;  // Avant application des powerups.
	      SkillPoints<T> realSkills_;  // Après application des powerups.
	map<Key, Powerup<T>> powerups_;
};

//}


//{ Globals

template <
	typename Key,
	typename T
>
ostream& operator << ( ostream&, const Character<Key, T>& );

//}

//}

