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
	Powerup ( const Bonus<T>* bonus= nullptr, const SkillPoints<T>* skillPoints= nullptr );

	
	// Modifying methods
	void applyEffectOn ( SkillPoints<T>& sp);
	void removeEffectFrom ( SkillPoints<T>& sp);
	
	// Non-modifying methods
	const SkillPoints<T>* getTargetBasePoints ( ) const;
	      const Bonus<T>* getEffect ( ) const;
	


protected:
	const SkillPoints<T>* targetBasePoints_;
	      const Bonus<T>* effect_;
};

//}

//}

