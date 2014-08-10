#ifndef QTPCOMBINATION_H
#define QTPCOMBINATION_H

/**
 * QtPFunction*:
 *
 * A QtP representation of a function of one or two other QtP objects.
 */

#ifdef QTPROPERTY_BOOST
#include <boost/function.hpp>
#else
#include <functional>
#endif

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

#include <boost/functional.hpp>

/// specialization for unary functions of given types
template <class F>
class QtPFunction1 : public QtPFunctionBase1
{
public:
	typedef typename boost::unary_traits <F>::result_type Tout;
	typedef typename boost::unary_traits <F>::argument_type T0;

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
template <class F>
class QtPFunction2 : public QtPFunctionBase2
{
public:
	typedef typename boost::binary_traits <F>::result_type Tout;
	typedef typename boost::binary_traits <F>::first_argument_type T0;
	typedef typename boost::binary_traits <F>::second_argument_type T1;

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

}

#endif // QTPCOMBINATION_H
