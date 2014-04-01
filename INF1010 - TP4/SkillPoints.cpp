#include "SkillPoints.hpp"

template < typename T >
SkillPoints<T>::SkillPoints()
{
	fighting = 0;
	marksmanship = 0;
	sorcery = 0;
}

template < typename T >
SkillPoints<T>::SkillPoints(T f, T m, T s)
{
	fighting = f;
	marksmanship = m;
	sorcery = s;

}

template < typename T >
SkillPoints<T> operator + ( const SkillPoints<T>& sp1, const SkillPoints<T>& sp2)
{
	sp = SkillPoints();
	sp = sp1;
	sp.fighting += sp2.fighting;
	sp.marksmanship += sp2.marksmanship;
	sp.sorcery += sp2.sorcery;

	return sp;
}

template < typename T >
SkillPoints<T> operator - ( const SkillPoints<T>& sp1, const SkillPoints<T>& sp2)
{
	sp = SkillPoints();
	sp = sp1;
	sp.fighting -= sp2.fighting;
	sp.marksmanship -= sp2.marksmanship;
	sp.sorcery -= sp2.sorcery;

	return sp;
}
