# CMakeList.txt: projekt CMake dla elementu TKOMProject, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (TKOMProject "Main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TKOMProject PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(TKOMProject Final_Functions)
