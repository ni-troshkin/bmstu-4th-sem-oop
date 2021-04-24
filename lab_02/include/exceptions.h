#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "base_exception.h"

class MemoryException: public BaseException
{
public:
    MemoryException(std::string file, int line, std::string info = "Allocation failed")
        : BaseException(file, line, info) {}
};

class DimensionsException: public BaseException
{
public:
    DimensionsException(std::string file, int line,
                        std::string info = "Vectors have different number of components")
        : BaseException(file, line, info) {}
};

class ExpiredException: public BaseException
{
public:
    ExpiredException(std::string file, int line,
                        std::string info = "The iterator already doesn't exist")
        : BaseException(file, line, info) {}
};

class ZeroVectorException: public BaseException
{
public:
    ZeroVectorException(std::string file, int line,
                        std::string info = "The operation is unavailable for zero-sized vector")
        : BaseException(file, line, info) {}
};

class ZeroDivisionException: public BaseException   // added
{
public:
    ZeroDivisionException(std::string file, int line,
                        std::string info = "Attempt to divide by zero")
        : BaseException(file, line, info) {}
};

class CrossProductException: public BaseException
{
public:
    CrossProductException(std::string file, int line,
                        std::string info = "Cross product is available only for 3d-vectors")
        : BaseException(file, line, info) {}
};

class WrongIndexException: public BaseException
{
public:
    WrongIndexException(std::string file, int line,
                        std::string info = "Index out of range")
        : BaseException(file, line, info) {}
};

class WrongIteratorException: public BaseException
{
public:
    WrongIteratorException(std::string file, int line,
                        std::string info = "Invalid iterator: index out of range")
        : BaseException(file, line, info) {}
};


#endif // EXCEPTIONS_H
