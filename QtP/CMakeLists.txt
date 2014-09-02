find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

find_package(Boost 1.46.1 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

if (USE_CXX11)
	add_definitions(-DCXX11)
else (USE_CXX11)
	add_definitions(-DQTPROPERTY_BOOST)
endif (USE_CXX11)

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
    QtPType.h
    QtPObject.h
    QtPAccess.h
    fwd.h
    QtPBase.h
    QtPTraits.h
    QtPMisc.h
    QtPFunction_14.h
)

add_executable(${profile}test ${QtP_SOURCES} ${QtP_HEADERS})
target_link_libraries(${profile}test ${QT_LIBRARIES})

