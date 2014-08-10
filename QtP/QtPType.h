#ifndef QTPTYPE_H
#define QTPTYPE_H

#include "fwd.h"

#include <boost/functional.hpp> // traits

#include "QtPBase.h"
#include "QtPTraits.h"

namespace QtProperty
{

template <class T>
class P : public QtPBase
{
public:
	P(QObject * obj, char const * propName);
	P(QtPObject * obj);
	P(T value);

	void bindTo(P const &) const;
	P const & operator<<(P const & src)
	{ bindTo(src); return src; }

	/* Three ways to call "apply":
	 * one is with function pointer (without having to supply template arguments)
	 * second is with lambda, you explicitly provide function prototype
	 * third is with boost::function, which can be passed without giving extra template arguments
	 */

	// unary
	template <class Tout>
	QtPObject * apply(Tout (*f)(T)) const;
	template <class Tout>
	QtPObject * apply(function <Tout (T)>) const;
	template <class F>
	QtPObject * apply(F) const;

	// binary
	template <class Tout, class T1>
	QtPObject * apply(Tout (*f)(T, T1), P <T1> const &) const;
	template <class Tout, class T1>
	QtPObject * apply(function <Tout (T, T1)>, P <T1> const &) const;
	template <class F, class T1>
	QtPObject * apply(F, P <T1> const &) const;
};

}

template <class T>
QtProperty::P <typename QtProperty::Defaults <T>::propType> QtP(T * obj)
{
	using namespace QtProperty;
	return P <typename Defaults <T>::propType> (obj, Defaults <T>::propName);
}

typedef QtProperty::P <int> QtPInt;
typedef QtProperty::P <double> QtPDouble;
typedef QtProperty::P <QString> QtPString;

#endif // QTPTYPE_H
