////////////////////////////////////////////////////////////////////////////////
//        FILE : DamageModels.cpp
//      AUTHOR : Zihui Zhong, Pascal Desrochers
//        DATE : 31 mars 2014  
//               Last entry : 31 mars 2014
// DESCRIPTION : Implementation des modeles de dommage
////////////////////////////////////////////////////////////////////////////////

#include "DamageModels.hpp"

int WizardModel::compute( const SkillPoints<int>& sp) const{
	return 1.25*sp.sorcery+10;
}
int WarriorModel::compute( const SkillPoints<int>& sp) const{
	return sp.fighting+sp.marksmanship/10+30;
}
int ArcherModel::compute( const SkillPoints<int>& sp) const{
	return 1.5*sp.marksmanship-30+sp.fighting/5;
}