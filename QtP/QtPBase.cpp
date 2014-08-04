#include "QtPBase.h"

namespace QtProperty {

QtPBase::QtPBase(QObject * obj, char const * propName)
	: obj(obj)
{
	QMetaObject const * metaObject = obj->metaObject();
	int pIndex = metaObject->indexOfProperty(propName);
	Q_ASSERT(pIndex != -1);
	p = metaObject->property(pIndex);
	Q_ASSERT(p.isValid());
}

} // namespace QtProperty
