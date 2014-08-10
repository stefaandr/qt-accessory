#ifndef QTPTRAITS_H
#define QTPTRAITS_H

class QLineEdit;
class QLabel;
class QString;

#include "fwd.h"

namespace QtProperty {

#ifdef CXX11
template <class T>
struct FuncTraits {};
template <class Tout, class Class, class... Targs>
struct FuncTraits <Tout (Class::*)(Targs...) const>
{
    typedef function <Tout (Targs...)> type;
};
#endif
struct DefaultsUnspecialized
{
	static char const * const propName; // "value"
	typedef int propType;
};

struct DefaultsText
{
	static char const * const propName; // "text"
	typedef QString propType;
};

template <class T>
struct Defaults : DefaultsUnspecialized
{
};

template <>
struct Defaults <QLineEdit> : DefaultsText {};

template <>
struct Defaults <QLabel> : DefaultsText {};

} // namespace QtProperty

#endif // QTPTRAITS_H
