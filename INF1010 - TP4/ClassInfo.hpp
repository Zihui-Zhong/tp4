////////////////////////////////////////////////////////////////////////////////
//        FILE : ClassInfo.hpp
//      AUTHOR : 
//        DATE :   Creation : 
//               Last entry : 
// DESCRIPTION :
////////////////////////////////////////////////////////////////////////////////

#pragma once


//{ Includes and usings

#include <string>

#include "SkillPoints.hpp"
#include "BaseModelClasses.hpp"


using namespace std;

//}


//{ Declarations

//{ Classes

template < typename T >
class ClassInfo
{
public:
	// Constructors and destructor
	ClassInfo ( );
	ClassInfo ( const string& nom, const DamageModel<T>* damage, const SkillPoints<T>& skills);
	
	// Non-modifying methods
	        const string& getName ( ) const;
	const DamageModel<T>* getDamageModel ( ) const;
	const SkillPoints<T>& getInitialSkills ( ) const;
	
	T computeDamage ( const SkillPoints<T>& sp) const;
	
	// Non-modifying operators
	bool operator == ( const ClassInfo& c) const;


protected:
	               string name_;
	const DamageModel<T>* damageModel_;
	       SkillPoints<T> initialSkills_;
};

//}

//}

