



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