#include "CharacterList.hpp"


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
	for_each(characters_.begin(),characters_.end(),print);
}



void printByClass ( ) const;
void printByDamage ( ) const;
Character<string, int>* findStrongest ( ) const;
Character<string, int>* findStrongest ( const ClassInfo<int>& ) const;


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
