#ifndef CONSTITER_HPP
#define CONSTITER_HPP

#include "exceptions.h"

template <typename Type>
ConstIterator<Type>::ConstIterator(const std::shared_ptr<Type[]> &arr,
                                   const std::shared_ptr<size_t> &size, const std::size_t index) noexcept
    : size(size), index(index), arr(arr)
{
}

template <typename Type>
ConstIterator<Type>::ConstIterator(const ConstIterator<Type> &iterator) noexcept
    : size(iterator.size), index(iterator.index), arr(iterator.arr)
{
}


template <typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type> &vector, std::size_t index) noexcept
    : size(vector.size), index(index), arr(vector.coord)
{
}

// operators
template <typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator=(const ConstIterator<Type> &it) noexcept
{
    index = it.index;
    size = it.size;
    arr.reset(it.arr);
    return *this;
}

template <typename Type>
const Type* ConstIterator<Type>::operator->() const
{
    check_if_expired(__LINE__);
    has_valid_index(__LINE__);
    std::shared_ptr<Type[]> a(arr);
    return &a[index];
}

template <typename Type>
const Type& ConstIterator<Type>::operator*() const
{
    check_if_expired(__LINE__);
    has_valid_index(__LINE__);
    std::shared_ptr<Type[]> a(arr);
    return a[index];
}

template <typename Type>
const Type& ConstIterator<Type>::operator[](const std::size_t index) const
{
    check_if_expired(__LINE__);
    if (this->index + index >= size)
        throw WrongIndexException(__FILE__, __LINE__);
    return *(*this + index);
}

template <typename Type>
ConstIterator<Type>::operator bool() const
{
    check_if_expired(__LINE__);

    if (index >= size || size == 0)
        return false;

    return true;
}

template <typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator++()
{
    check_if_expired(__LINE__);
    ++index;
    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator++(int)
{
    check_if_expired(__LINE__);
    ConstIterator<Type> temp = *this;
    ++(*this);
    return temp;
}

template <typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator--()
{
    check_if_expired(__LINE__);
    --index;
    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator--(int)
{
    check_if_expired(__LINE__);
    ConstIterator<Type> temp = *this;
    --(*this);
    return temp;
}

template <typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator+=(std::size_t delta)
{
    check_if_expired(__LINE__);
    index += delta;
    return *this;
}

template <typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator-=(std::size_t delta)
{
    check_if_expired(__LINE__);
    index -= delta;
    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator+(std::size_t delta) const
{
    check_if_expired(__LINE__);
    ConstIterator<Type> sum = *this;
    sum += delta;
    return sum;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator-(std::size_t delta) const
{
    check_if_expired(__LINE__);
    ConstIterator<Type> diff = *this;
    diff -= delta;
    return diff;
}

template <typename Type>
std::size_t ConstIterator<Type>::operator-(ConstIterator<Type> &iterator) const
{
    check_if_expired(__LINE__);
    return index - iterator.index;
}

template <typename Type>
bool ConstIterator<Type>::operator==(const ConstIterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index == it.index;
}

template <typename Type>
bool ConstIterator<Type>::operator!=(const ConstIterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index != it.index;
}

template <typename Type>
bool ConstIterator<Type>::operator<(const ConstIterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index < it.index;
}

template <typename Type>
bool ConstIterator<Type>::operator>(const ConstIterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index > it.index;
}

template <typename Type>
bool ConstIterator<Type>::operator<=(const ConstIterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index <= it.index;
}

template <typename Type>
bool ConstIterator<Type>::operator>=(const ConstIterator<Type> &it) const
{
    check_if_expired(__LINE__);
    return index >= it.index;
}

template <typename Type>
void ConstIterator<Type>::has_valid_index(int line_number) const
{
    if (index >= size)
        throw WrongIndexException(__FILE__, line_number);
}

template <typename Type>
void ConstIterator<Type>::check_if_expired(int line_number) const
{
    if (arr.expired())
        throw ExpiredException(__FILE__, line_number);
}

#endif // CONSTITER_HPP
