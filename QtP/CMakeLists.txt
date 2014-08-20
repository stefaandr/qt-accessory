find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

find_package(Boost 1.46.1 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

if (NOT USE_CXX11)
	add_definitions(-DQTPROPERTY_BOOST)
endif (NOT USE_CXX11)

set(CMAKE_AUTOMOC true)

set(QtP_SOURCES
    main.cpp
    Test.cpp
    QtP.cpp
    QtPBinding.cpp
    QtPCombination.cpp
    QtPConstant.cpp
    QtPType.cpp
    QtPObject.cpp
    QtPAccess.cpp
    QtPBase.cpp
    QtPTraits.cpp
)

set(QtP_HEADERS
    Test.h
    QtP.h
    QtPBinding.h
    QtPCombination.h
    QtPConstant.h
    QtPImpl.h
    QtPType.h
    QtPObject.h
    QtPAccess.h
    fwd.h
    QtPBase.h
    QtPTraits.h
)

add_executable(test ${QtP_SOURCES} ${QtP_HEADERS})
target_link_libraries(test ${QT_LIBRARIES})

