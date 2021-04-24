#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "exceptions.h"

template <typename Type>
Iterator<Type>::Iterator(const std::shared_ptr<Type[]> &arr,
                         const std::shared_ptr<size_t> &size, const std::size_t index) noexcept
    : size(size), index(index), arr(arr)
{
}

template <typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iterator) noexcept
    : size(iterator.size), index(iterator.index), arr(iterator.arr)
{
}


template <typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vector, const std::size_t index) noexcept
    : size(vector.size), index(index), arr(vector.coord)
{
}

// operators
template <typename Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type> &it) noexcept
{
    index = it.index;
    size = it.size;
    arr.reset(it.arr);
    return *this;
}

template <typename Type>
Type* Iterator<Type>::operator->()
{
    check_if_expired(__LINE__);
    has_valid_index(__LINE__);
    std::shared_ptr<Type[]> a(arr);
    return &a[index];
}

template <typename Type>
const Type* Iterator<Type>::operator->() const
{
    check_if_expired(__LINE__);
    has_valid_index(__LINE__);
    std::shared_ptr<Type[]> a(arr);
    return &a[index];
}

template <typename Type>
Type& Iterator<Type>::operator*()
{
    check_if_expired(__LINE__);
    has_valid_index(__LINE__);
    std::shared_ptr<Type[]> a(arr);
    return a[index];
}

template <typename Type>
const Type& Iterator<Type>::operator*() const
{
    check_if_expired(__LINE__);
    has_valid_index(__LINE__);
    std::shared_ptr<Type[]> a(arr);
    return a[index];
}

template <typename Type>
Type& Iterator<Type>::operator[](std::size_t index)
{
    check_if_expired(__LINE__);
    if (this->index + index >= size)
        throw WrongIndexException(__FILE__, __LINE__);
    return *(*this + index);
}

template <typename Type>
const Type& Iterator<Type>::operator[](std::size_t index) const
{
    check_if_expired(__LINE__);
    if (this->index + index >= size)
        throw WrongIndexException(__FILE__, __LINE__);
    return *(*this + index);
}

template <typename Type>
Iterator<Type>::operator bool() const
{
    check_if_expired(__LINE__);

    if (index >= size || size == 0)
        return false;

    return true;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    check_if_expired(__LINE__);
    ++index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    check_if_expired(__LINE__);
    Iterator<Type> temp = *this;
    ++(*this);
    return temp;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    check_if_expired(__LINE__);
    --index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    check_if_expired(__LINE__);
    Iterator<Type> temp = *this;
    --(*this);
    return temp;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator+=(std::size_t delta)
{
    check_if_expired(__LINE__);
    index += delta;
    return *this;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator-=(std::size_t delta)
{
    check_if_expired(__LINE__);
    index -= delta;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator+(std::size_t delta) const
{
    check_if_expired(__LINE__);
    Iterator<Type> sum = *this;
    sum += delta;
    return sum;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator-(std::size_t delta) const
{
    check_if_expired(__LINE__);
    Iterator<Type> diff = *this;
    diff -= delta;
    return diff;
}

template <typename Type>
std::size_t Iterator<Type>::operator-(Iterator<Type> &iterator) const
{
    check_if_expired(__LINE__);
    return index - iterator.index;
}

template <typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index == it.index;
}

template <typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index != it.index;
}

template <typename Type>
bool Iterator<Type>::operator<(const Iterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index < it.index;
}

template <typename Type>
bool Iterator<Type>::operator>(const Iterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index > it.index;
}

template <typename Type>
bool Iterator<Type>::operator<=(const Iterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index <= it.index;
}

template <typename Type>
bool Iterator<Type>::operator>=(const Iterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index >= it.index;
}

template <typename Type>
void Iterator<Type>::has_valid_index(int line_number) const
{
    if (index >= size)
        throw WrongIteratorException(__FILE__, line_number);
}

template <typename Type>
void Iterator<Type>::check_if_expired(int line_number) const
{
    if (arr.expired())
        throw ExpiredException(__FILE__, line_number);
}

#endif // ITERATOR_HPP
