#include "CharacterList.hpp"


void CharacterList::insert ( Character<string, int>* character){
	characters_.push_back(character);
}
void CharacterList::erase ( Character<string, int>* character){
	vector<Character<string, int>*>::iterator it;
	it=std::find(characters_.begin(),characters_.end(),character);
	characters_.erase(it);
}


const vector<Character<string, int>*>& CharacterList::getCharacters ( ) const{
	return characters_;
}