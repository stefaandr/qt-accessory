#ifndef QTPIMPL_H
#define QTPIMPL_H

#include "QtPCombination.h"

#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>

namespace QtProperty {

template <class T>
template <class Tout>
QtPObject * P <T>::apply(Tout (*f)(T)) const
{
	return apply <Tout (T)> (f);
}

template <class T>
template <class F>
QtPObject * P <T>::apply(function <F> f) const
{
	BOOST_STATIC_ASSERT_MSG((boost::is_same<typename boost::unary_traits <F>::argument_type, T>::value), "function prototype's argument must match the QtP object on which the apply(...) is being called");
	return new QtPFunction1 <F> (f, *this);
}

template <class T>
template <class Tout, class T1>
QtPObject * P <T>::apply(Tout (*f)(T, T1), P <T> const & other) const
{
	return apply <Tout (T, T1)> (f, other);
}

template <class T>
template <class F>
QtPObject * P <T>::apply(function <F> f, P <typename FuncTraitsCombo <F>::second_argument_type> const & other) const
{
	BOOST_STATIC_ASSERT_MSG((boost::is_same<typename boost::binary_traits <F>::first_argument_type, T>::value), "function prototype's first argument must match the QtP object on which the apply(...) is being called");
		/// \TODO this seems to give unreadable errors
	return new QtPFunction2 <F> (f, *this, other);
}

} // namespace QtProperty

#endif // QTPIMPL_H
