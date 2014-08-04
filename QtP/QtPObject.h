#ifndef QTPOBJECT_H
#define QTPOBJECT_H

/**
 * class QtPObject:
 *
 * A QObject with a single property, used to represent intermediate
 * values resulting from other properties (either specified explicitly by
 * the user, or other intermediate properties).
 *
 * It is used in the QtP property descriptor to represent these intermediate
 * properties.
 */

#include "QtPAccess.h"

#include <QVariant>

namespace QtProperty
{

class QtPObject : public QtPAccess
{
	Q_OBJECT

	Q_PROPERTY(QVariant value
			   READ value
			   WRITE setValue
			   NOTIFY valueChanged)

protected:
	QtPObject(QObject * parent = 0)
		: QtPAccess(parent) {}
	QtPObject(QVariant value, QObject * parent = 0)
		: QtPAccess(parent), m_Value(value) {}

	void setValue(QVariant arg) { if (m_Value == arg) return; m_Value = arg; emit valueChanged(m_Value); }
	QVariant value() { return m_Value; }

private:
	QVariant m_Value;

signals:
	void valueChanged(QVariant);
};

}

#endif // QTPOBJECT_H
