#include "base_exception.h"

BaseException::BaseException(std::string file, int line, std::string info)
{
    this->information = "\n" + file + ":" + std::to_string(line) + ": " + info;
}

const char * BaseException::what() const noexcept
{
    return information.c_str();
}
