#include "../Source/Source_String.h"
#include "../Source/Source_File.h"

#include "../Executives/Executive_File.h"
#include "../Executives/Executive_Code.h"

std::string compile(Source& source);

void compile_to_file(Source_File& file);

void execute(Source& source);