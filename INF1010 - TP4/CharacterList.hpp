////////////////////////////////////////////////////////////////////////////////
//        FILE : CharacterList.hpp
//      AUTHOR : 
//        DATE :   Creation : 
//               Last entry : 
// DESCRIPTION :
////////////////////////////////////////////////////////////////////////////////

#pragma once


//{ Includes and usings

#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <type_traits>

#include "Character.hpp"


using namespace std;

//}


//{ Declarations

//{ Classes

class CharacterList
{
public:
	// Modifying methods
	void insert ( Character<string, int>* );
	void erase ( Character<string, int>* );
	
	template < typename Pred >
	    void sortCharacters ( const Pred& );
	
	// Non-modifying methods
	const vector<Character<string, int>*>& getCharacters ( ) const;
	
	                   void print ( ) const;
	                   void printByClass ( ) const;
	                   void printByDamage ( ) const;
	Character<string, int>* findStrongest ( ) const;
	Character<string, int>* findStrongest ( const ClassInfo<int>& ) const;


protected:
	vector<Character<string, int>*> characters_;
};

//}


//{ Functors

class IsRightClass
{
public:
	// Constructors and destructor
	IsRightClass ( const ClassInfo<int>& = ClassInfo<int>() );
	
	// Function call operators
	bool operator () ( const Character<string, int>* ) const;


protected:
	ClassInfo<int> criteria_;
};

//}


//{ Globals

bool compareClass ( Character<string, int>*, Character<string, int>* );


bool compareDamage ( Character<string, int>*, Character<string, int>* );


bool compareName ( Character<string, int>*, Character<string, int>* );

//}

//}

