# CMakeList.txt: projekt CMake dla elementu TKOMProject, do��cz �r�d�o i zdefiniuj
# tutaj logik� specyficzn� dla projektu.
#

# Dodaj �r�d�o do pliku wykonywalnego tego projektu.
add_library(Validator 
"Validator.h" "Validator.cpp"
"Located_Variable_Essence.h" "Located_Variable_Essence.cpp" 
"Located_Function_Essence.h" "Located_Function_Essence.cpp"
 "Validated_Objects_Tree.h" "Validated_Objects_Tree.cpp" 
 "Real_Validator.h" "Real_Validator.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Validator PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(Validator Parser)