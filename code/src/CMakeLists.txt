SET(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS regex log log_setup filesystem system thread coroutine context REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(coolStuffInC coolStuffInC.c)
add_executable(functionPointers functionPointers.c)
add_executable(functionPointersAdvanced functionPointersAdvanced.c)
add_executable(doublePointers doublePointers.c)
add_executable(boostUsefulStuff boostUsefulStuff.cpp)
add_executable(enterPasswordInTerminal enterPasswordInTerminal.c)
add_executable(cStyleString cStyleString.cpp)

target_link_libraries(boostUsefulStuff ${Boost_LIBRARIES})
