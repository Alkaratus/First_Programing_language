#pragma once
#include "Position.h"

[[noreturn]] void raise_error(Position position, std::string error);
void show_warning(Position position, std::string warning);
