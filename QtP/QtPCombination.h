#ifndef QTPCOMBINATION_H
#define QTPCOMBINATION_H

/**
 * QtPFunction*:
 *
 * A QtP representation of a function of one or two other QtP objects.
 */

#ifdef QTPROPERTY_BOOST
#include <boost/function.hpp>
#include <boost/utility/result_of.hpp>
#else
#include <functional>
#endif // !QTPROPERTY_BOOST

namespace QtProperty {
#ifdef QTPROPERTY_BOOST
using boost::result_of;
#else
using std::result_of;
#endif // !QTPROPERTY_BOOST
}

#include "QtPObject.h"
#include "QtPType.h"

namespace QtProperty {

/// base for QtPObjects representing a property resulting from a function
class QtPFunctionBase : public QtPObject
{
	Q_OBJECT

public:
	QtPFunctionBase(QObject * parent = 0)
		: QtPObject(parent) {}

protected slots:
	virtual void update() = 0;

protected:
	void addUpdateTrigger(QtPBase const &);
};

/// base for unary functions
class QtPFunctionBase1 : public QtPFunctionBase
{
public:
	QtPFunctionBase1(QtPBase const & arg, QObject * parent = 0)
		: QtPFunctionBase(parent), arg(arg) {}

protected:
	QtPBase const arg;
};

/// base for binary functions
class QtPFunctionBase2 : public QtPFunctionBase
{
public:
	QtPFunctionBase2(QtPBase const & arg0, QtPBase const & arg1, QObject * parent = 0)
		: QtPFunctionBase(parent), arg0(arg0), arg1(arg1)
	{}

protected:
	QtPBase const arg0, arg1;
};

/// specialization for unary functions of given types
template <class Tout, class T0>
class QtPFunction1 : public QtPFunctionBase1
{
public:
	typedef Tout (F)(T0);

	QtPFunction1(function <F> f, P <T0> const & arg, QObject * parent = 0)
		: QtPFunctionBase1(arg, parent), f(f)
	{
		addUpdateTrigger(arg);
		update();
	}

protected:
	virtual void update()
	{
		T0 v0 = readQtP(arg).template value <T0> ();
		Tout result = f(v0);
		setValue(result);
	}

	function <Tout (T0)> const f;
};

/// specialization for binary functions of given types
template <class Tout, class T0, class T1>
class QtPFunction2 : public QtPFunctionBase2
{
public:
	typedef Tout (F)(T0, T1);

	QtPFunction2(function <F> f, P <T0> const & arg0, P <T1> const & arg1, QObject * parent = 0)
		: QtPFunctionBase2(arg0, arg1, parent), f(f)
	{
		addUpdateTrigger(arg0);
		addUpdateTrigger(arg1);
		update();
	}

protected:
	virtual void update()
	{
		T0 v0 = readQtP(arg0).template value <T0> ();
		T1 v1 = readQtP(arg1).template value <T1> ();
		Tout result = f(v0, v1);
		setValue(result);
	}

	function <F> const f;
};

template <typename Tout, class Targ0>
P <Tout> QtPF(function <Tout (Targ0)> f, P <Targ0> arg0)
{
	return P <Tout> (new QtPFunction1 <Tout, Targ0> (f, arg0));
}

template <typename Tout, class Targ0>
P <Tout> QtPF(Tout (*f)(Targ0), P <Targ0> arg0)
{
	return QtPF(function <Tout (Targ0)> (f), arg0);
}

template <typename L, class Targ0>
P <typename result_of <L(Targ0)>::type> QtPF(L lambda, P <Targ0> arg0)
{
    return QtPF(function <typename result_of <L(Targ0)>::type (Targ0)> (lambda), arg0);
}

template <typename Tout, class Targ0, class Targ1>
P <Tout> QtPF(function <Tout (Targ0, Targ1)> f, P <Targ0> arg0, P <Targ1> arg1)
{
	return P <Tout> (new QtPFunction2 <Tout, Targ0, Targ1> (f, arg0, arg1));
}

template <typename Tout, class Targ0, class Targ1>
P <Tout> QtPF(Tout (*f)(Targ0, Targ1), P <Targ0> arg0, P <Targ1> arg1)
{
	return QtPF(function <Tout (Targ0, Targ1)> (f), arg0, arg1);
}

template <typename L, class Targ0, class Targ1>
P <typename result_of <L(Targ0, Targ1)>::type> QtPF(L lambda, P <Targ0> arg0, P <Targ1> arg1)
{
    return QtPF(function <typename result_of <L(Targ0, Targ1)>::type (Targ0, Targ1)> (lambda), arg0, arg1);
}

} // namespace QtProperty

#endif // QTPCOMBINATION_H
