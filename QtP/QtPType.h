#ifndef QTPTYPE_H
#define QTPTYPE_H

#include "fwd.h"

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

	T read() const { return p.read(obj).value <T>(); }
};

}

#endif // QTPTYPE_H
