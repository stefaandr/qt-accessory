#include "QtPBinding.h"

namespace QtProperty {

template <class T>
QtPBinding <T>::QtPBinding(const P <T> &src, const P <T> &dst)
	: QtPBindingBase(object(dst)), src(src), dst(dst)
{
	addTrigger(src, "onSrcPropertyChanged()");
	onSrcPropertyChanged();
}

template <class T>
void QtPBinding <T>::onSrcPropertyChanged()
{
	QVariant v = readQtP(src);
	writeQtP(dst, v);
}

template class QtPBinding <int>;
template class QtPBinding <double>;
template class QtPBinding <QString>;

} // namespace QtProperty
