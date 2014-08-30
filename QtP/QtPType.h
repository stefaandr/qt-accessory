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
