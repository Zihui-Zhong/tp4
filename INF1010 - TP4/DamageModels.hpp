////////////////////////////////////////////////////////////////////////////////
//        FILE : DamageModels.hpp
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

struct WizardModel
: public DamageModel<int>
{
	// Non-modifying methods
	virtual
	    int compute ( const SkillPoints<int>& ) const;
};


struct WarriorModel
: public DamageModel<int>
{
	// Non-modifying methods
	virtual
	    int compute ( const SkillPoints<int>& ) const;
};



struct ArcherModel
: public DamageModel<int>
{
	// Non-modifying methods
	virtual
	    int compute ( const SkillPoints<int>& ) const;
};

//}

//}

