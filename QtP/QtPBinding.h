#ifndef QTPBINDING_H
#define QTPBINDING_H

#include "QtP.h"

namespace QtProperty {

class QtPBindingBase : public QtPAccess
{
	Q_OBJECT

protected:
	QtPBindingBase(QObject * parent) : QtPAccess(parent) {}

protected slots:
	virtual void onSrcPropertyChanged() = 0;
};

template <class T>
class QtPBinding : public QtPBindingBase
{
public:
	QtPBinding(P <T> const & src, P <T> const & dst);

protected:
	virtual void onSrcPropertyChanged();

private:
	P <T> const src, dst;
};

} // namespace QtProperty

#endif // QTPBINDING_H
