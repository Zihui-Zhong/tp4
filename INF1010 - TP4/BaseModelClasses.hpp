////////////////////////////////////////////////////////////////////////////////
//        FILE : BaseModelClasses.hpp
//      AUTHOR : 
//        DATE :   Creation : 
//               Last entry : 
// DESCRIPTION :
////////////////////////////////////////////////////////////////////////////////

#pragma once


//{ Includes and usings

#include "SkillPoints.hpp"

//}


//{ Declarations

//{ Classes

template < typename T >
struct Bonus
{
	// Non-modifying methods
	       virtual
	SkillPoints<T> compute ( const SkillPoints<T>& ) const = 0;
};


template < typename T >
struct DamageModel
{
	// Non-modifying methods
	virtual
	      T compute ( const SkillPoints<T>& ) const = 0;
};

//}

//}

