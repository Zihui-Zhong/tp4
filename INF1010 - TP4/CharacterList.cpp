////////////////////////////////////////////////////////////////////////////////
//        FILE : CharacterList.cpp
//      AUTHOR : Zihui Zhong, Pascal Desrochers
//        DATE : 31 mars 2014  
//               Last entry : 31 mars 2014
// DESCRIPTION : Implementaion de la liste de personnage
////////////////////////////////////////////////////////////////////////////////

#include "CharacterList.hpp"

void A(Character<string, int>* a);


/**
* Insere un nouveau personnage a la liste
* @param character personnage a ajouter
*/
void CharacterList::insert ( Character<string, int>* character){
	if(characters_.size()>0){
		if(( find(characters_.begin(),characters_.end(),character)==characters_.end()) && (character!= characters_.back()))
			characters_.push_back(character);	

	}else{
		characters_.push_back(character);
	}
}
/**
* Retire un personnage de la liste
* @param character personnage a retirer
*/
void CharacterList::erase ( Character<string, int>* character){	

	std::remove(characters_.begin(),characters_.end(),character);
	if(character==characters_.back()){
		characters_.pop_back();
	}
}

const vector<Character<string, int>*>& CharacterList::getCharacters ( ) const{
	return characters_;
}

void CharacterList::print ( ) const{
	for_each(characters_.begin(),characters_.end(),A);

}
void A(Character<string, int>* a){
	a->Character<string, int>::print();

}


/**
* Affiche les personnages de la liste en les classant selon leur classe
*/
void CharacterList::printByClass ( ) const{
	vector<Character<string, int>*> copy_(characters_.size());
	copy(characters_.begin(),characters_.end(),copy_.begin());
	sort(copy_.begin(), copy_.end(), compareDamage);
	stable_sort(copy_.begin(), copy_.end(),compareClass);
	for_each(copy_.begin(),copy_.end(),A);
}

/**
* Affiche les personnages de la liste en les classant selon leur dommages inflige
*/
void CharacterList::printByDamage ( ) const{
	vector<Character<string, int>*> copy_(characters_.size());
	copy(characters_.begin(),characters_.end(),copy_.begin());
	sort(copy_.begin(), copy_.end(), compareDamage);
	for_each(copy_.begin(),copy_.end(),A);
}

/**
* Retourne le personnage le plus fort de la liste
* @return personnage le plus fort
*/
Character<string, int>* CharacterList::findStrongest ( ) const{
	return *max_element(characters_.begin(),characters_.end(),compareDamage);

}

/**
* Retourne le personnage le plus fort de la liste selon la classe specifie
* @param class classe specifie
* @return personnage le plus fort
*/
Character<string, int>* CharacterList::findStrongest ( const ClassInfo<int>& class_) const
{
	vector<Character<string, int>*> copy_(characters_.size());
	IsRightClass a(class_);
	auto it=copy_if(characters_.begin(),characters_.end(),copy_.begin(),a);
	copy_.resize(std::distance(copy_.begin(),it));  // shrink container to new size

	return *max_element(copy_.begin(),copy_.end(),compareDamage);

}

IsRightClass::IsRightClass( const ClassInfo<int>& clas ){
	criteria_=clas;
}

bool IsRightClass::operator () ( const Character<string, int>* class_) const{
	return criteria_.getName()==class_->getClass().getName();
}


bool compareClass ( Character<string, int>* char1, Character<string, int>* char2){
	return char1->getClass().getName()<char2->getClass().getName();
}


bool compareDamage ( Character<string, int>* char1, Character<string, int>* char2){
	return char1->computeDamageOutput()<char2->computeDamageOutput();

}


bool compareName ( Character<string, int>* char1, Character<string, int>* char2)
{
	return char1->getName()<char2->getName();
}
