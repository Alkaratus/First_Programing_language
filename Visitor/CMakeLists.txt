# CMakeList.txt: projekt CMake dla elementu TKOMProject, do��cz �r�d�o i zdefiniuj
# tutaj logik� specyficzn� dla projektu.
#

# Dodaj �r�d�o do pliku wykonywalnego tego projektu.
add_library(Visitor 
	"Visitor.h" "Visitor.cpp"
 )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Visitor PROPERTY CXX_STANDARD 20)
endif()