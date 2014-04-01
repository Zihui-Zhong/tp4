////////////////////////////////////////////////////////////////////////////////
//        FILE : Powerup.hpp
//      AUTHOR : 
//        DATE :   Creation : 
//               Last entry : 
// DESCRIPTION :
////////////////////////////////////////////////////////////////////////////////

#pragma once


//{ Includes and usings

#include <functional>

#include "SkillPoints.hpp"
#include "BaseModelClasses.hpp"


using namespace std;

//}


//{ Declarations

//{ Classes

template < typename T >
class Powerup
{
public:
	// Constructors and destructor
	Powerup ( const Bonus<T>* bonus= nullptr, const SkillPoints<T>* skillPoints= nullptr ){
	targetBasePoints_ = skillPoints;
	effect_ = bonus;
}

	
	// Modifying methods
	void applyEffectOn ( SkillPoints<T>& sp)
{
	sp= sp+effect_->compute(sp);
}
	void removeEffectFrom ( SkillPoints<T>& sp)
{
	sp= sp-effect_->compute(sp);
}

	// Non-modifying methods
	const SkillPoints<T>* getTargetBasePoints ( ) const
{
	return targetBasePoints_;
}
	      const Bonus<T>* getEffect ( ) const
{
	return effect_;
}

	


protected:
	const SkillPoints<T>* targetBasePoints_;
	      const Bonus<T>* effect_;
};

//}

//}

