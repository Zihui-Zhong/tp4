////////////////////////////////////////////////////////////////////////////////
//        FILE : DamageModels.hpp
//      AUTHOR : Zihui Zhong, Pascal Desrochers
//        DATE : 31 mars 2014  
//               Last entry : 31 mars 2014
// DESCRIPTION : Classe contenant les differents modeles de dommages
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

