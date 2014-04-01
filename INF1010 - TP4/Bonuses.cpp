
#include <string>

#include "SkillPoints.hpp"
#include "BaseModelClasses.hpp"
#include "Bonuses.hpp"


using namespace std;

	SkillPoints<int> MagicWeaponEffect::compute ( const SkillPoints<int>& sp) const{
		SkillPoints<int> skillBonus(sp.fighting/4+15,0,0);
		return skillBonus;


	}



