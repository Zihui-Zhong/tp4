
#include <string>

#include "SkillPoints.hpp"
#include "BaseModelClasses.hpp"
#include "Bonuses.hpp"


using namespace std;

SkillPoints<int> MagicWeaponEffect::compute ( const SkillPoints<int>& sp) const{
	SkillPoints<int> skillBonus(sp.fighting/4+15,0,0);
	return skillBonus;


}



SkillPoints<int> MagicBowEffect::compute ( const SkillPoints<int>& sp) const{
	SkillPoints<int> skillBonus(0,sp.marksmanship/4+15,0);
	return skillBonus;
}

SkillPoints<int> MagicWandEffect::compute ( const SkillPoints<int>& sp) const{
	SkillPoints<int> skillBonus(0,0,sp.sorcery/4+15);
	return skillBonus;
}

SkillPoints<int> SkillPotionEffect::compute ( const SkillPoints<int>& sp) const{
	SkillPoints<int> skillBonus(sp.fighting/10+20,sp.marksmanship/10+20,sp.sorcery/10+20);
	return skillBonus;
}

