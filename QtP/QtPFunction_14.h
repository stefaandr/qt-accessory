#ifndef QTPFUNCTION_14_H
#define QTPFUNCTION_14_H

#ifdef QTPROPERTY_VARIADIC

#include <tuple>
#include <functional>

#include "QtPObject.h"
#include "QtPMisc.h"

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

    void addUpdateTrigger(QtPBase const & one, QtPBase const & others...)
    {
        addUpdateTrigger(one);
        addUpdateTrigger(others);
    }
};

template <typename Tout, typename... Targ>
class QtPFunction : public QtPFunctionBase
{
public:
    QtPFunction(std::function <Tout (Targ...)> f, P <Targ>... argP)
        : argP(argP...), f(f)
    {
        addUpdateTrigger(argP...);
        update();
    }

protected:
    std::tuple <P <Targ>...> argP;

    std::function <Tout (Targ...)> f;

    template <long unsigned int... indices>
    std::tuple <Targ...> readArgs(std::index_sequence <indices...>) const
    {
        return std::tuple <Targ...> (std::get <indices> (argP).read()...);
    }

    virtual void update()
    {
        std::tuple <Targ...> tuple = readArgs(std::make_index_sequence <sizeof... (Targ)> ());
        Tout result = callWithTupleArgs(f, tuple);
        setValue(result);
    }
};

template <class Tout, class Targ0> using QtPFunction1 = QtPFunction <Tout, Targ0>;
template <class Tout, class Targ0, class Targ1> using QtPFunction2 = QtPFunction <Tout, Targ0, Targ1>;

template <typename Tout, class ...Targ>
P <Tout> QtPF(function <Tout (Targ...)> f, P <Targ>... args)
{
    return P <Tout> (new QtPFunction <Tout, Targ...> (f, args...));
}

template <typename Tout, class ...Targ>
P <Tout> QtPF(Tout (*f)(Targ...), P <Targ>... args)
{
    return QtPF <Tout, Targ...> (
                function <Tout (Targ...)> (f),
                args...);
}

template <typename L, class ...Targ>
P <typename result_of <L(Targ...)>::type> QtPF(L lambda, P <Targ>... args)
{
	return QtPF(function <typename result_of <L(Targ...)>::type (Targ...)> (lambda), args...);
}

} // namespace QtProperty

#endif // QTPFUNCTIONVARIADIC

#endif // QTPFUNCTION_14_H
