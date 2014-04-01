////////////////////////////////////////////////////////////////////////////////
//        FILE : Bonuses.hpp
//      AUTHOR : 
//        DATE :   Creation : 
//               Last entry : 
// DESCRIPTION :
////////////////////////////////////////////////////////////////////////////////

#pragma once


//{ Includes and usings

#include "SkillPoints.hpp"
#include "BaseModelClasses.hpp"

//}


//{ Declarations

//{ Classes

struct MagicWeaponEffect
: public Bonus<int>
{
	// Non-modifying methods
	         virtual
	SkillPoints<int> compute ( const SkillPoints<int>& ) const;
};


struct MagicBowEffect
: public Bonus<int>
{
	// Non-modifying methods
	         virtual
	SkillPoints<int> compute ( const SkillPoints<int>& ) const;
};


struct MagicWandEffect
: public Bonus<int>
{
	// Non-modifying methods
	         virtual
	SkillPoints<int> compute ( const SkillPoints<int>& ) const;
};


struct SkillPotionEffect
: public Bonus<int>
{
	// Non-modifying methods
	         virtual
	SkillPoints<int> compute ( const SkillPoints<int>& ) const;
};

//}

//}

