////////////////////////////////////////////////////////////////////////////////
//        FILE : Main.cpp
//      AUTHOR : 
//        DATE :   Creation : 
//               Last entry : 
// DESCRIPTION :
////////////////////////////////////////////////////////////////////////////////

#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>

#include "CharacterList.hpp"
#include "Bonuses.hpp"
#include "DamageModels.hpp"


using namespace std;




int main ( )
{
	// Instanciez chaque bonus.
	MagicWeaponEffect magicWeaponEffect;
	MagicBowEffect magicBowEffect;
	MagicWandEffect magicWandEffect;
	SkillPotionEffect skillPotionEffect;

	// Instanciez chaque modèle de calcul de dommage.
	WizardModel wizardModel;
	WarriorModel warriorModel;
	ArcherModel archerModel;

	// Faites un ClassInfo<int> 'wizard', qui aura comme nom "Wizard", le modèle
	// de dommage approprié (wizardModel) et les valeurs initiales 30, 20, 100.
	ClassInfo<int> wizard = ClassInfo<int>("Wizard", &wizardModel, SkillPoints<int>(30, 20,100));

	// Faites un ClassInfo<int> 'warrior' qui aura comme nom "Warrior", le
	// modèle warriorModel et les valeurs initiales 100, 50, 0.
	ClassInfo<int> warrior = ClassInfo<int>("Warrior", &warriorModel, SkillPoints<int>(100, 50,0));

	// Faites un ClassInfo<int> 'archer' qui aura comme nom "Archer", le modèle
	// archerModel et les valeurs initiales 50, 100, 0.
	ClassInfo<int> archer = ClassInfo<int>("Archer", &wizardModel, SkillPoints<int>(50, 100,0));
	
	// Créez un Powerup<int> 'magicWeapon' avec 'magicWeaponEffect'.
	Powerup<int> magicWeapon = Powerup<int>(&magicWeaponEffect);
	
	// Créez un Powerup<int> 'magicWand' avec 'magicWandEffect'.
	Powerup<int> magicWand = Powerup<int>(&magicWandEffect);

	// Créez un Powerup<int> 'magicBow' avec 'magicBowEffect'.
	Powerup<int> magicBow = Powerup<int>(&magicBowEffect);
	
	// Créez un Powerup<int> 'skillPotion' avec 'skillPotionEffect'.
	Powerup<int> skillPotion = Powerup<int>(&skillPotionEffect);
	
	// Créez un personnage Harry Potter, classe 'wizard'.
	Character<string,int> harryPotter =  Character<string,int>("Harry Potter", wizard);
	
	// Créez un personnage Aragorn, classe 'warrior'.
	Character<string,int> aragorn =  Character<string,int>("Aragorn", warrior);
	
	// Créez un personnage Robin Hood, class 'archer'.
	Character<string,int> robinHood =  Character<string,int>("Robin Hood", archer);
	
	// Créez un personnage Captain America, classe 'warrior'.
	Character<string,int> captainAmerica =  Character<string,int>("Captain America", warrior);
	
	// Créez un CharacterList avec le conteneur de votre choix, selon les
	// contraintes de l'énoncé.
	
	//CharacterList charList;
	
	// Affichez la liste avec 'print'.
	
	
	
	cout << "\n\n" << string(80, '*') << "\n\n";
	
	
	// Ajoutez le power-up Magic Wand à Harry Potter.
	
	
	// Insérez tous les personnages dans la liste.
	
	
	// Affichez la liste avec 'printByClass'.
	
	
	
	cout << "\n\n" << string(80, '*') << "\n\n";
	
	
	// Ajoutez le power-up Magic Weapon à Aragorn et à Captain America.
	
	
	// Ajoutez 20 points de 'marksmanship' à Robin Hood en utilisant
	// 'addToBaseSkills'.
	
	
	// Retirez Captain America de la liste.
	
	
	// Ajoutez le power-up Skill Potion à Captain America
	
	
	// Ajoutez Captain America à la liste.
	
	
	// Triez la liste en ordre croissant de nombre de power-ups appliqués.
	// Utilisez 'sortCharacters' et le type de prédicat que vous voulez.
	
	
	// Affichez la liste avec 'print'.
	
	
	
	cout << "\n\n" << string(80, '*') << "\n\n";
	
	
	// Ajoutez Aragorn à la liste.
	
	
	// Ajoutez le power-up Magic Bow à Robin Hood.
	
	
	// Affichez la liste avec 'printByClass'.
	
	
	// Affichez la liste avec 'printByDamage'.
	
	
	
	cout << "\n\n" << string(80, '*') << "\n\n";
	
	
	// Affichez le nom du personnage le plus puissant.
	
	
	// Affichez le nom du Warrior le plus puissant.
	
}

