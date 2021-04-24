#ifndef CONSTITER_H
#define CONSTITER_H

#include <iterator>
#include <memory>

template <typename Type>
class Vector;

template <typename Type>
class ConstIterator: public std::iterator<std::random_access_iterator_tag, int>
{
public:
    ConstIterator(const std::shared_ptr<Type[]> &arr,
                  const std::shared_ptr<std::size_t> &size, std::size_t index = 0) noexcept;
    ConstIterator(const ConstIterator<Type> &iterator) noexcept;
    ConstIterator(const Vector<Type> &vector, std::size_t index = 0) noexcept;

    ~ConstIterator() = default;

    // operators
    ConstIterator<Type> &operator=(const ConstIterator<Type> &it) noexcept;

    const Type *operator->() const;
    const Type &operator*() const;
    const Type &operator[](const std::size_t index) const;
    operator bool() const;

    ConstIterator<Type> &operator++();
    ConstIterator<Type> operator++(int);
    ConstIterator<Type> &operator+=(std::size_t delta);
    ConstIterator<Type> operator+(std::size_t delta) const;

    ConstIterator<Type> &operator--();
    ConstIterator<Type> operator--(int);
    ConstIterator<Type> &operator-=(std::size_t delta);
    ConstIterator<Type> operator-(std::size_t delta) const;
    std::size_t operator-(ConstIterator<Type> &iterator) const;

    bool operator==(const ConstIterator<Type> &it) const;
    bool operator!=(const ConstIterator<Type> &it) const;
    bool operator<(const ConstIterator<Type> &it) const;
    bool operator>(const ConstIterator<Type> &it) const;
    bool operator<=(const ConstIterator<Type> &it) const;
    bool operator>=(const ConstIterator<Type> &it) const;

protected:
    std::size_t size;
    std::size_t index;
    void has_valid_index(int line_number) const;
    void check_if_expired(int line_number) const;

private:
    std::weak_ptr<Type[]> arr;
};

#include "constiter.hpp"

#endif // CONSTITER_H
