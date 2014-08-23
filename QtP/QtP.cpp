#include "QtP.h"

#include "QtPBinding.h"
#include "QtPConstant.h"

namespace QtProperty {

template <class T>
P <T>::P(QObject * obj, char const * propName)
	: QtPBase(obj, propName)
{}

template <class T>
P <T>::P(QtPObject * obj)
	: QtPBase(obj, "value")
{}

template <class T>
P <T>::P(T value)
	: QtPBase(new QtPConstant <T> (value), "value")
{}

template <class T>
void P <T>::bindTo(P const & src) const
{
	Q_ASSERT(p.isWritable());
	Q_ASSERT(src.p.isReadable());
	Q_ASSERT(src.p.hasNotifySignal());

	new QtPBinding <T>(src, *this);
}

template class P <int>;
template class P <double>;
template class P <QString>;

} // namespace QtProperty
