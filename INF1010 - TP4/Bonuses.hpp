////////////////////////////////////////////////////////////////////////////////
//        FILE : Bonuses.hpp
//      AUTHOR : Zihui Zhong, Pascal Desrochers
//        DATE : 31 mars 2014  
//               Last entry : 31 mars 2014
// DESCRIPTION : Bonus qui affectent les Skillpoints
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

