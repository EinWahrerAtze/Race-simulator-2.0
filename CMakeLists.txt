cmake_minimum_required (VERSION 3.8)
project ("Race simulator")
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#add_library (Units SHARED Units_ABC.h Units_ABC.cpp
#						  Camel.h Camel.cpp
#						  Fast_camel.h Fast_camel.cpp
#						  Centaur.h Centaur.cpp
#						  Boots.h Boots.cpp
#						  Magic_carpet.h Magic_carpet.cpp
#						  Eagle.h Eagle.cpp
#						  Magic_broom.h Magic_broom.cpp
#						  Display.h Display.cpp
#						  Keyboard.h)
add_executable(Race_simulator main.cpp)
target_link_libraries (Race_simulator Units)