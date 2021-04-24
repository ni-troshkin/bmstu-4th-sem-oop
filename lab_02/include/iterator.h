#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>
#include <cstdlib>
#include <memory>

template <typename Type>
class Vector;

template <typename Type>
class Iterator: public std::iterator<std::random_access_iterator_tag, int>
{
public:
    Iterator(const Iterator<Type> &iterator) noexcept;
    Iterator(const Vector<Type> &vector, std::size_t index = 0) noexcept;

    ~Iterator() = default;

    // operators
    Iterator<Type> &operator=(const Iterator<Type> &it) noexcept;

    Type *operator->();
    const Type *operator->() const;
    Type &operator*();
    const Type &operator*() const;
    operator bool() const;

    Type &operator[](std::size_t index);
    const Type &operator[](std::size_t index) const;

    Iterator<Type> &operator++();
    Iterator<Type> operator++(int);
    Iterator<Type> &operator+=(std::size_t delta);
    Iterator<Type> operator+(std::size_t delta) const;

    Iterator<Type> &operator--();
    Iterator<Type> operator--(int);
    Iterator<Type> &operator-=(std::size_t delta);
    Iterator<Type> operator-(std::size_t delta) const;
    std::size_t operator-(Iterator<Type> &iterator) const;

    bool operator==(const Iterator<Type> &it) const;
    bool operator!=(const Iterator<Type> &it) const;
    bool operator<(const Iterator<Type> &it) const;
    bool operator>(const Iterator<Type> &it) const;
    bool operator<=(const Iterator<Type> &it) const;
    bool operator>=(const Iterator<Type> &it) const;

protected:
    std::size_t size;
    std::size_t index;
    void has_valid_index(int line_number) const;
    void check_if_expired(int line_number) const;
    Iterator(const std::shared_ptr<Type[]> &arr,
                  const std::shared_ptr<size_t> &size, std::size_t index = 0) noexcept;

private:
    std::weak_ptr<Type[]> arr;
};

#include "iterator.hpp"

#endif // ITERATOR_H
