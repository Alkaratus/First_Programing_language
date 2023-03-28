# CMakeList.txt: projekt CMake dla elementu TKOMProject, do³¹cz Ÿród³o i zdefiniuj
# tutaj logikê specyficzn¹ dla projektu.
#

# Dodaj Ÿród³o do pliku wykonywalnego tego projektu.
add_library(Final_Functions 
"Final_Functions.h" "Final_Functions.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Validator PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(Final_Functions Validator)
target_link_libraries(Final_Functions Runner)