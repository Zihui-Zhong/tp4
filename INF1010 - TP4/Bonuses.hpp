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
	SkillPoints<int> compute ( const SkillPoints<int>& sp) const;
};


struct MagicBowEffect
: public Bonus<int>
{
	// Non-modifying methods
	         virtual
	SkillPoints<int> compute ( const SkillPoints<int>& sp) const;
};


struct MagicWandEffect
: public Bonus<int>
{
	// Non-modifying methods
	         virtual
	SkillPoints<int> compute ( const SkillPoints<int>& sp) const;
};


struct SkillPotionEffect
: public Bonus<int>
{
	// Non-modifying methods
	         virtual
	SkillPoints<int> compute ( const SkillPoints<int>& sp) const;
};

//}

//}

