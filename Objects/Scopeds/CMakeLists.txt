# CMakeList.txt: projekt CMake dla elementu TKOMProject, do³¹cz Ÿród³o i zdefiniuj
# tutaj logikê specyficzn¹ dla projektu.
#

# Dodaj Ÿród³o do pliku wykonywalnego tego projektu.
add_library(Scopeds 
"Scoped_Object.h" "Scoped_Object.cpp"
"If_Object.h" "If_Object.cpp"
"While_Object.h" "While_Object.cpp" 
"Function_Object.h" "Function_Object.cpp" 
"Inspect_Option_Object.h" "Inspect_Option_Object.cpp"
 "Else_Object.h" "Else_Object.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Scopeds PROPERTY CXX_STANDARD 20)
endif()