#include "QtPCombination.h"

namespace QtProperty {

void QtPFunctionBase::addUpdateTrigger(QtPBase const & qtP)
{
	addTrigger(qtP, "update()");
}

}
