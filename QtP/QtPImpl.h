#ifndef QTPIMPL_H
#define QTPIMPL_H

#include "QtPCombination.h"

namespace QtProperty {

template <class T>
template <class Tout>
QtPObject * P <T>::apply(Tout (*f)(T)) const
{
	return apply(function <Tout (T)> (f));
}

template <class T>
template <class Tout>
QtPObject * P <T>::apply(function <Tout (T)> f) const
{
	return new QtPFunction1 <Tout (T)> (f, *this);
}

template <class T>
template <class F>
QtPObject * P <T>::apply(F f) const
{
	typedef typename boost::result_of <F(T)>::type Tret;
	return apply(function <Tret (T)> (f));
}

template <class T>
template <class Tout, class T1>
QtPObject * P <T>::apply(Tout (*f)(T, T1), P <T1> const & other) const
{
	return apply(function <Tout (T, T1)> (f), other);
}

template <class T>
template <class Tout, class T1>
QtPObject * P <T>::apply(function <Tout (T, T1)> f, P <T1> const & other) const
{
	return new QtPFunction2 <Tout (T, T1)> (f, *this, other);
}

template <class T>
template <class F, class T1>
QtPObject * P <T>::apply(F f, P <T1> const & other) const
{
	typedef typename boost::result_of <F(T, T1)>::type Tret;
	return apply(function <Tret (T, T1)> (f), other);
}

} // namespace QtProperty

#endif // QTPIMPL_H
