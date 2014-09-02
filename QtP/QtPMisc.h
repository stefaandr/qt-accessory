#ifndef QTPMISC_H
#define QTPMISC_H

#include <utility>

namespace QtProperty
{

template <class Function, class ArgsTuple, long unsigned int... N>
auto callWithTupleArgs1(Function f, ArgsTuple args, std::index_sequence <N...>)
{
    return f(std::get <N> (args)...);
}

template <class Tout, class... Targs>
Tout callWithTupleArgs(std::function <Tout (Targs...)> f, std::tuple <Targs...> args)
{
    return callWithTupleArgs1(f, args, std::make_index_sequence <sizeof... (Targs)> ());
}

}

#endif // QTPMISC_H
