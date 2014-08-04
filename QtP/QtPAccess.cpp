#include "QtPAccess.h"

#include <QMetaMethod>
#include "QtPBase.h"

namespace QtProperty {

void QtPAccess::addTrigger(const QtPBase & qtP, const char *slotName)
{
	QMetaObject const * m = metaObject();
	QMetaMethod slot = m->method(m->indexOfSlot(slotName));
	connect(qtP.obj, qtP.p.notifySignal(), this, slot);
}

QObject * QtPAccess::object(QtPBase const & qtP)
{
	return qtP.obj;
}

QVariant QtPAccess::readQtP(QtPBase const & qtP)
{
	return qtP.p.read(qtP.obj);
}

void QtPAccess::writeQtP(QtPBase const & qtP, QVariant const & v)
{
	qtP.p.write(qtP.obj, v);
}

} // namespace QtProperty
