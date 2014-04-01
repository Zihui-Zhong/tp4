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
	SkillPoints ( );
	SkillPoints ( T f, T m, T s );


	T fighting;
	T marksmanship;
	T sorcery;
};

//}


//{ Globals

template < typename T >
SkillPoints<T> operator + ( const SkillPoints<T>& sp1, const SkillPoints<T>& sp2);


template < typename T >
SkillPoints<T> operator - ( const SkillPoints<T>& sp1, const SkillPoints<T>& sp2);

//}

//}

