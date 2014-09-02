#ifndef QTP_H
#define QTP_H

#include "QtPType.h"
#include "QtPTraits.h"

#ifndef CXX11
#include <boost/lambda/lambda.hpp>
#endif // CXX11

/* convenience function: QtP(...), to access the 'default' property of the given object */
template <class T>
QtProperty::P <typename QtProperty::Defaults <T>::propType> QtP(T * obj)
{
    using namespace QtProperty;
    return P <typename Defaults <T>::propType> (obj, Defaults <T>::propName);
}

/* convenience typedefs */
typedef QtProperty::P <int> QtPInt;
typedef QtProperty::P <double> QtPDouble;
typedef QtProperty::P <QString> QtPString;

namespace QtProperty {

#ifdef CXX11

template <class T, class U>
P <T> operator+(P <T> const & one, P <U> const & other)
{ return QtPF([](T a, U b) { return a + b; }, one, other); }
template <class T, class U>
P <T> operator-(P <T> const & one, P <U> const & other)
{ return QtPF([](T a, U b) { return a - b; }, one, other); }

template <class T, class U>
P <T> operator*(P <T> const & one, P <U> const & other)
{ return QtPF([](T a, U b) { return a * b; }, one, other); }

template <class T, class U>
P <T> operator/(P <T> const & one, P <U> const & other)
{ return QtPF([](T a, U b) { return a / b; }, one, other); }

template <class T> P <T> operator-(P <T> const & one)
{ return QtPF([](T a) { return -a; }, one); }

#else

using boost::lambda::ret;
using boost::lambda::_1;
using boost::lambda::_2;

template <class T, class U>
P <T> operator+(P <T> const & one, P <U> const & other)
{ return QtPF(ret <T> (_1 + _2), one, other); }

template <class T, class U>
P <T> operator-(P <T> const & one, P <U> const & other)
{ return QtPF(ret <T> (_1 - _2), one, other); }

template <class T, class U>
P <T> operator*(P <T> const & one, P <U> const & other)
{ return QtPF(ret <T> (_1 * _2), one, other); }

template <class T, class U>
P <T> operator/(P <T> const & one, P <U> const & other)
{ return QtPF(ret <T> (_1 / _2), one, other); }

template <class T> P <T> operator-(P <T> const & one)
{ return QtPF(- _1, one); }

#endif // !CXX11

template <class T> P <T> operator+(T const & p0, P <T> const & p1)
{ return P <T> (p0) + p1; }
template <class T> P <T> operator+(P <T> const & p0, T const & p1)
{ return p0 + P <T> (p1); }

template <class T> P <T> operator-(T const & p0, P <T> const & p1)
{ return P <T> (p0) - p1; }
template <class T> P <T> operator-(P <T> const & p0, T const & p1)
{ return p0 - P <T> (p1); }

template <class T> P <T> operator*(T const & p0, P <T> const & p1)
{ return P <T> (p0) * p1; }
template <class T> P <T> operator*(P <T> const & p0, T const & p1)
{ return p0 * P <T> (p1); }

template <class T> P <T> operator/(T const & p0, P <T> const & p1)
{ return P <T> (p0) / p1; }
template <class T> P <T> operator/(P <T> const & p0, T const & p1)
{ return p0 / P <T> (p1); }

} // namespace QtProperty

#include "QtPCombination.h"

#endif // QTP_H
