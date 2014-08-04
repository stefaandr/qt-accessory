#ifndef QTPBASE_H
#define QTPBASE_H

/**
 * QtPBase:
 *
 * Shared parent type for all QtP <T> classes.
 */

#include <QPointer>
#include <QMetaProperty>

namespace QtProperty
{

class QtPBase
{
	friend class QtPAccess;

protected:
	QtPBase(QObject * obj, char const * propName);
/// \TODO maybe constructor for QtPObject here instead of in class P?

	QPointer <QObject> const obj;
	QMetaProperty p;
};

}

#endif // QTPBASE_H
