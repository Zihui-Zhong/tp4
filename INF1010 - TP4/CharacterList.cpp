#include "CharacterList.hpp"

void A(Character<string, int>* a);


void CharacterList::insert ( Character<string, int>* character){
	if(characters_.size()>0){
		if(( find(characters_.begin(),characters_.end(),character)==characters_.end()) && (character!= characters_.back()))
			characters_.push_back(character);	

	}else{
		characters_.push_back(character);
	}
}
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



void CharacterList::printByClass ( ) const{
	vector<Character<string, int>*> copy_(characters_.size());
	copy(characters_.begin(),characters_.end(),copy_.begin());
	sort(copy_.begin(), copy_.end(), compareDamage);
	stable_sort(copy_.begin(), copy_.end(),compareClass);
	for_each(copy_.begin(),copy_.end(),A);
}


void CharacterList::printByDamage ( ) const{
	vector<Character<string, int>*> copy_(characters_.size());
	copy(characters_.begin(),characters_.end(),copy_.begin());
	sort(copy_.begin(), copy_.end(), compareDamage);
	for_each(copy_.begin(),copy_.end(),A);
}

Character<string, int>* CharacterList::findStrongest ( ) const{
	return *max_element(characters_.begin(),characters_.end(),compareDamage);

}

Character<string, int>* CharacterList::findStrongest ( const ClassInfo<int>& class_) const
{
	vector<Character<string, int>*> copy_(characters_.size());
	IsRightClass a(class_);
	copy_if(characters_.begin(),characters_.end(),copy_.begin(),a);
	return *max_element(characters_.begin(),characters_.end(),compareDamage);

}

IsRightClass::IsRightClass( const ClassInfo<int>& clas ){
	criteria_=clas;
}

bool IsRightClass::operator () ( const Character<string, int>* class_) const{
	return criteria_.getName()==class_->getName();
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
