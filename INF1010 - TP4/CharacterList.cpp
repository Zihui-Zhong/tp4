#include "CharacterList.hpp"

void A(Character<string, int>* a);
void CharacterList::insert ( Character<string, int>* character){
	characters_.push_back(character);
}
void CharacterList::erase ( Character<string, int>* character){	
	std::remove(characters_.begin(),characters_.end(),character);
	
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



void CharacterList::printByClass ( ) const{
	sort(characters_.begin(), characters_.end(), compareDamage);
	stable_sort(characters_.begin(), characters_.end(),compareClass);
	print();
}
void CharacterList::printByDamage ( ) const{
	sort(characters_.begin(),characters_.end(),compareDamage);
	print();
}

Character<string, int>* CharacterList::findStrongest ( ) const{
	return *max_element(characters_.begin(),characters_.end(),compareDamage);

}

Character<string, int>* CharacterList::findStrongest ( const ClassInfo<int>& class_) const
{
	sort(characters_.begin(), characters_.end(), compareDamage);
	stable_sort(characters_.begin(), characters_.end(),compareClass);
	return *max_element(characters_.begin(),characters_.end(),compareDamage);

}

bool compareClass ( Character<string, int>* char1, Character<string, int>* char2){
	return char1->getClass().getName()>char2->getClass().getName();
}


bool compareDamage ( Character<string, int>* char1, Character<string, int>* char2){
	return char1->computeDamageOutput()>char2->computeDamageOutput();

}


bool compareName ( Character<string, int>* char1, Character<string, int>* char2)
{
	return char1->getName()>char2->getName();
}
