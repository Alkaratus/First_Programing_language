# CMakeList.txt: projekt CMake dla elementu TKOMProject, do��cz �r�d�o i zdefiniuj
# tutaj logik� specyficzn� dla projektu.
#

# Dodaj �r�d�o do pliku wykonywalnego tego projektu.
add_library(Final_Functions 
"Final_Functions.h" "Final_Functions.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Validator PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(Final_Functions Validator)
target_link_libraries(Final_Functions Runner)