#include "CharacterList.hpp"


void CharacterList::insert ( Character<string, int>* character){
	characters_.push_back(character);
}
void CharacterList::erase ( Character<string, int>* character){
	vector<Character<string, int>*>::iterator it;
	it=std::find(characters_.begin(),characters_.end(),character);
	characters_.erase(it);
}
template < typename Pred >
void CharacterList::sortCharacters ( const Pred& predicat){
	sort(characters_.begin(), characters_end(), predicat);
}

const vector<Character<string, int>*>& CharacterList::getCharacters ( ) const{
	return characters_;
}