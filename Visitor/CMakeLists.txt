# CMakeList.txt: projekt CMake dla elementu TKOMProject, do³¹cz Ÿród³o i zdefiniuj
# tutaj logikê specyficzn¹ dla projektu.
#

# Dodaj Ÿród³o do pliku wykonywalnego tego projektu.
add_library(Visitor 
	"Visitor.h" "Visitor.cpp"
 )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Visitor PROPERTY CXX_STANDARD 20)
endif()