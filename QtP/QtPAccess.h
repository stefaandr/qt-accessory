#ifndef QTPACCESS_H
#define QTPACCESS_H

/**
 * QtPAccess:
 *
 * Base class that provides privileged access to QtPBase objects.
 */

#include <QObject>

#include "fwd.h"

namespace QtProperty
{

class QtPAccess : public QObject
{
protected:
	QtPAccess(QObject * parent = 0) : QObject(parent) {}

	void addTrigger(QtPBase const &, char const * slotName);
	static QObject * object(QtPBase const &);

	static QVariant readQtP(QtPBase const &);
	static void writeQtP(QtPBase const &, QVariant const &);
};

}

#endif // QTPACCESS_H
