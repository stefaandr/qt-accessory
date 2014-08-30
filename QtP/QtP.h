#ifndef QTP_H
#define QTP_H

#include "QtPType.h"
#include "QtPTraits.h"

#include <boost/lambda/lambda.hpp>

namespace QtProperty {

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

#include "QtPImpl.h"

#endif // QTP_H
