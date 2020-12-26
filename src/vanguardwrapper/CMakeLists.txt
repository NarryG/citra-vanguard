
set(CMAKE_AUTOUIC ON)
add_library(vanguardwrapper STATIC
    ../citra_qt/main.h
    ../citra_qt/main.ui
    UnmanagedWrapper.h
    UnmanagedWrapper.cpp
)

target_link_libraries(vanguardwrapper PUBLIC vanguard fmt Qt5::Widgets)
target_link_libraries(vanguardwrapper PUBLIC Boost::boost PRIVATE Boost::serialization)