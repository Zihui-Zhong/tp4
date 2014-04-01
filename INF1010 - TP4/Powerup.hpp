////////////////////////////////////////////////////////////////////////////////
//        FILE : Powerup.hpp
//      AUTHOR : Zihui Zhong, Pascal Desrochers
//        DATE : 31 mars 2014  
//               Last entry : 31 mars 2014
// DESCRIPTION : Powerup qui affectent les skillpoints
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
	/**
	* Applique ses effets au skillpoints en parametre
	* @param sp skillpoints que l'on applique l'effet
	*/
	void applyEffectOn ( SkillPoints<T>& sp)
	{
		sp= sp+effect_->compute(sp);
	}
	/**
	* Retire ses effets au skillpoints en parametre
	* @param sp skillpoints que l'on retire l'effet
	*/
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

