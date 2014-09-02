#ifndef FWD_H
#define FWD_H

#ifdef QTPROPERTY_BOOST
#include <boost/function/function_fwd.hpp>
#else
#include <functional>
#endif

namespace QtProperty
{

class QtPBase;
class QtPObject;
template <class T> class P;

#ifdef QTPROPERTY_BOOST
using boost::function;
#else
using std::function;
#endif
}

#endif // FWD_H
