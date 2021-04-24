#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H

#include <exception>
#include <string>

class BaseException: public std::exception
{
public:
    BaseException(std::string file, int line, std::string info);

    virtual const char *what() const noexcept override;

    virtual ~BaseException() {};

protected:
    std::string information;
};

#endif // BASE_EXCEPTION_H
