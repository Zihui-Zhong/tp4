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
	ClassInfo ( )
	{
		name_ = "INVALID";
		damageModel_ = nullptr;
	}

	ClassInfo ( const string& nom, const DamageModel<T>* damage, const SkillPoints<T>& skills)
	{
		name_ = nom;
		damageModel_ = damage;
		initialSkills_ = skills;
	}
	
	// Non-modifying methods
	const string& getName ( ) const
	{
		return name_;
	}

	const DamageModel<T>* getDamageModel ( ) const
	{
		return damageModel_;
	}

	const SkillPoints<T>& getInitialSkills ( ) const
	{
		return initialSkills_;
	}
	

	T computeDamage ( const SkillPoints<T>& sp) const
	{
		return damageModel_->compute(sp);
	}
	
	// Non-modifying operators
	bool operator == ( const ClassInfo& c) const
	{
		return name_==c.name_;
	}

protected:
	               string name_;
	const DamageModel<T>* damageModel_;
	       SkillPoints<T> initialSkills_;
};

//}

//}

