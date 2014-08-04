#ifndef QTPCONSTANT_H
#define QTPCONSTANT_H

/**
 * QtPConstant:
 *
 * A QtP representation of a fixed value (originating from an expression,
 * rather than a QObject)
 */

#include "QtPObject.h"

namespace QtProperty {

template <class T>
class QtPConstant : public QtPObject
{
public:
	QtPConstant(T constant) : QtPObject(constant) {}
};

} // namespace QtProperty

#endif // QTPCONSTANT_H
