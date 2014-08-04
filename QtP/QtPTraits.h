#ifndef QTPTRAITS_H
#define QTPTRAITS_H

class QLineEdit;
class QLabel;
class QString;

#include <boost/functional.hpp> // binary_traits

namespace QtProperty {

template <class T>
struct FuncTraitsCombo
{};
/// \TODO I don't understand why using this combo works, while binary_traits directly does not
template <class T, class U, class V>
struct FuncTraitsCombo <T (U, V)> : boost::binary_traits <T (U, V)>
{};

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
