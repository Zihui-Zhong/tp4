////////////////////////////////////////////////////////////////////////////////
//        FILE : SkillPoints.hpp
//      AUTHOR : 
//        DATE :   Creation : 
//               Last entry : 
// DESCRIPTION :
////////////////////////////////////////////////////////////////////////////////

#pragma once


//{ Declarations

//{ Classes

template < typename T >
struct SkillPoints
{
	SkillPoints ( ){
	fighting = 0;
	marksmanship = 0;
	sorcery = 0;
	}

	SkillPoints ( T f, T m, T s ){
	fighting = f;
	marksmanship = m;
	sorcery = s;
	}


	T fighting;
	T marksmanship;
	T sorcery;
};

//}


//{ Globals

template < typename T >
SkillPoints<T> operator + ( const SkillPoints<T>& sp1, const SkillPoints<T>& sp2){
	sp = SkillPoints();
	sp = sp1;
	sp.fighting += sp2.fighting;
	sp.marksmanship += sp2.marksmanship;
	sp.sorcery += sp2.sorcery;

	return sp;
}


template < typename T >
SkillPoints<T> operator - ( const SkillPoints<T>& sp1, const SkillPoints<T>& sp2){
	sp = SkillPoints();
	sp = sp1;
	sp.fighting -= sp2.fighting;
	sp.marksmanship -= sp2.marksmanship;
	sp.sorcery -= sp2.sorcery;

	return sp;
}


//}

//}

