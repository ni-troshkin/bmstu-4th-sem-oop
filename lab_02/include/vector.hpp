#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>
#include <cstdlib>
#include <exception>
#include "exceptions.h"

#define EPS 1e-7

// iterator
template <typename Type>
Iterator<Type> Vector<Type>::begin() noexcept
{
    Iterator<Type> iterator(*this);
    return iterator;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::begin() const noexcept
{
    ConstIterator<Type> iterator(*this);
    return iterator;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::cbegin() const noexcept
{
    ConstIterator<Type> iterator(*this);
    return iterator;
}

template <typename Type>
Iterator<Type> Vector<Type>::end() noexcept
{
    Iterator<Type> iterator(*this);
    return iterator + size;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::end() const noexcept
{
    ConstIterator<Type> iterator(*this);
    return iterator + size;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::cend() const noexcept
{
    ConstIterator<Type> iterator(*this);
    return iterator + size;
}


// protected exception throwers

template <typename Type>
void Vector<Type>::check_if_zero_sized(const std::size_t another_size, const int line_num) const
{
    if (size == 0 || another_size == 0)
        throw ZeroVectorException(__FILE__, line_num);
}

template <typename Type>
void Vector<Type>::check_dimensions(const std::size_t another_size, const int line_num) const
{
    if (size != another_size)
        throw DimensionsException(__FILE__, line_num);
}

template <typename Type>
void Vector<Type>::check_cross_prod_dimensions(const std::size_t another_size, const int line_num) const
{
    if (size != 3 || another_size != 3)
        throw CrossProductException(__FILE__, line_num);
}


// constructors
template <typename Type>
Vector<Type>::Vector() noexcept
    : BaseContainer(0), coord(nullptr)
{
}

template <typename Type>
Vector<Type>::Vector(std::size_t size)
    try : BaseContainer(size)
{
    coord.reset(new Type[size]);
    Iterator<Type> iterator = begin();
    for (; iterator != end(); iterator++)
        *iterator = 0;

}
catch (std::bad_alloc &exc)
{
    throw MemoryException(__FILE__, __LINE__);
}

template <typename Type>
Vector<Type>::Vector(std::size_t size, const Type &elem)
    : Vector(size)
{
    Iterator<Type> iterator = begin();
    for (; iterator != end(); iterator++)
        *iterator = elem;
}

template <typename Type>
Vector<Type>::Vector(std::initializer_list<Type> list)
    : Vector(list.size())
{
    Iterator<Type> iterator = begin();

    for (auto element : list)
    {
        *iterator = element;
        ++iterator;
    }
}

template <typename Type>
Vector<Type>::Vector(const Vector &vector)
    try : BaseContainer(vector.size)
{
    coord.reset(new Type[size]);
    Iterator<Type> iterator = begin();

    for (auto element: vector)
    {
        *iterator = element;
        ++iterator;
    }
}
catch (std::bad_alloc &exc)
{
    throw MemoryException(__FILE__, __LINE__);
}

template <typename Type>
Vector<Type>::Vector(Vector &&vector) noexcept
    : BaseContainer(vector.size), coord(vector.coord)
{
    vector.coord = nullptr;
}

template <typename Type>
template <typename IterType>
Vector<Type>::Vector(const IterType &it_begin, const IterType &it_end)
try {
    size = it_end - it_begin;
    coord.reset(new Type[size]);

    Iterator<Type> vec_iterator = begin();

    for (; it_begin < it_end; ++it_begin, ++vec_iterator)
        *vec_iterator = *it_begin;
}
catch (std::bad_alloc &exc)
{
    throw MemoryException(__FILE__, __LINE__);
}

template <typename Type>
Vector<Type>::Vector(std::size_t size, const Type *array)
    : Vector(size)
{
    Iterator<Type> iter = begin();
    for (; iter < end(); ++iter)
    {
        *iter = *array;
        ++array;
    }
}

// math operations

template <typename Type>
template <typename VecType>
decltype(auto) Vector<Type>::sum(const Vector<VecType> &vector) const
{
    check_if_zero_sized(vector.size, __LINE__);
    check_dimensions(vector.size, __LINE__);

    Vector<decltype((*this)[0] + vector[0])> v_sum(size);
    Iterator<decltype((*this)[0] + vector[0])> iterator = v_sum.begin();
    ConstIterator<Type> this_iter = begin();

    for (auto element: vector)
    {
        *iterator = *this_iter + element;
        ++iterator;
        ++this_iter;
    }

    return v_sum;
}

template <typename Type>
Vector<Type> &Vector<Type>::add(const Vector<Type> &vector)
{
    *this = sum(vector);
    return *this;
}

template <typename Type>
template <typename VecType>
decltype(auto) Vector<Type>::diff(const Vector<VecType> &vector) const
{
    check_if_zero_sized(vector.size, __LINE__);
    check_dimensions(vector.size, __LINE__);

    Vector<decltype((*this)[0] - vector[0])> v_diff(size);
    Iterator<decltype((*this)[0] - vector[0])> iterator = v_diff.begin();
    ConstIterator<Type> this_iter = begin();

    for (auto element: vector)
    {
        *iterator = *this_iter - element;
        ++iterator;
        ++this_iter;
    }

    return v_diff;
}

template <typename Type>
Vector<Type> &Vector<Type>::substract(const Vector<Type> &vector)
{
    *this = diff(vector);
    return *this;
}

template <typename Type>
template <typename ArgType>
decltype(auto) Vector<Type>::product(const ArgType &factor) const
{
    if (size == 0)
        throw ZeroVectorException(__FILE__, __LINE__);

    Vector<decltype((*this)[0] * factor)> v_prod(size);
    Iterator<decltype((*this)[0] * factor)> iterator = v_prod.begin();

    for (auto element: *this)
    {
        *iterator = element * factor;
        ++iterator;
    }

    return v_prod;
}

template <typename Type>
Vector<Type> &Vector<Type>::mul(const Type &factor)
{
    *this = product(factor);
    return *this;
}

template <typename Type>
template <typename VecType>
decltype(auto) Vector<Type>::dot_product(const Vector<VecType> &vector) const
{
    check_if_zero_sized(vector.size, __LINE__);
    check_dimensions(vector.size, __LINE__);

    decltype((*this)[0] * vector[0]) prod_sum = 0;
    ConstIterator<Type> iterator = begin();

    for (auto element: vector)
    {
        prod_sum += element * (*iterator);
        ++iterator;
    }

    return prod_sum;
}

template <typename Type>
template <typename VecType>
decltype(auto) Vector<Type>::cross_product(const Vector<VecType> &vector) const
{
    check_dimensions(vector.size, __LINE__);
    check_cross_prod_dimensions(vector.size, __LINE__);
    Vector<decltype((*this)[0] * vector[0])> vec_prod = Vector(3);

    vec_prod[0] = (*this)[1] * vector[2] - (*this)[2] * vector[1];
    vec_prod[1] = (*this)[2] * vector[0] - (*this)[0] * vector[2];
    vec_prod[2] = (*this)[0] * vector[1] - (*this)[1] * vector[0];

    return vec_prod;
}

template <typename Type>
Vector<Type> &Vector<Type>::vec_mul(const Vector<Type> &vector)
{
    *this = vec_prod(vector);
    return *this;
}

template <typename Type>
template <typename ArgType>
decltype(auto) Vector<Type>::quotient(const ArgType &num) const
{
    if (abs(num) < EPS)
        throw ZeroDivisionException(__FILE__, __LINE__);

    return product(1.0 / num);
}

template <typename Type>
Vector<Type> &Vector<Type>::divide(const Type &num)
{
    *this = quotient(1.0 / num);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::negative() const
{
    double factor = -1;
    return product(factor);
}

template <typename Type>
bool Vector<Type>::is_equal(const Vector<Type> &v) const
{
    if (size != v.size)
        return false;

    check_if_zero_sized(v.size, __LINE__);
    ConstIterator<Type> iterator = begin();
    bool equal = true;
    for (auto element: v)
    {
        if (element != *iterator)
            equal = false;
        ++iterator;
    }

    return equal;
}

template <>
bool Vector<double>::is_equal(const Vector<double> &v) const
{
    if (size != v.size)
        return false;

    check_if_zero_sized(v.size, __LINE__);
    ConstIterator<double> iterator = begin();
    bool equal = true;
    for (auto element: v)
    {
        if (fabs(element - *iterator) > EPS)
            equal = false;
        ++iterator;
    }

    return equal;
}

template <typename Type>
bool Vector<Type>::is_not_equal(const Vector<Type> &v) const
{
    return !(*this == v);
}

template <typename Type>
Type &Vector<Type>::get_elem_by_index(const std::size_t index)
{
    if (index >= size)
        throw WrongIndexException(__FILE__, __LINE__);
    Iterator<Type> iterator = begin();
    return iterator[index];
}

template <typename Type>
const Type &Vector<Type>::get_elem_by_index(const std::size_t index) const
{
    if (index >= size)
        throw WrongIndexException(__FILE__, __LINE__);
    ConstIterator<Type> iterator = begin();
    return iterator[index];
}

// operators

template <typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vector)
{
    size = vector.size;
    try
    {
        coord.reset(new Type[size]);
    }
    catch (std::bad_alloc &exc)
    {
        throw MemoryException(__FILE__, __LINE__);
    }

    Iterator<Type> iterator = begin();

    for (auto element: vector)
    {
        *iterator = element;
        ++iterator;
    }

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vector) noexcept
{
    size = vector.size;
    coord = vector.coord;
    vector.coord.reset();
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(std::initializer_list <Type> list)
{
    size = list.size();
    try
    {
        coord.reset(new Type[size]);
    }
    catch (std::bad_alloc &exc)
    {
        throw MemoryException(__FILE__, __LINE__);
    }

    Iterator<Type> iterator = begin();

    for (auto element: list)
    {
        *iterator = element;
        ++iterator;
    }

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator+=(const Vector<Type> &v)
{
    *this = add(v);
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator-=(const Vector<Type> &v)
{
    *this = sub(v);
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator*=(const Type &num)
{
    *this = mul(num);
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator/=(const Type &num)
{
    *this = divide(num);
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator^=(const Vector<Type> &v)
{
    *this = vec_mul(v);
    return *this;
}

template <typename Type>
template <typename VecType>
decltype(auto) Vector<Type>::operator+(const Vector<VecType> &v) const
{
    return sum(v);
}

template <typename Type>
template <typename VecType>
decltype(auto) Vector<Type>::operator-(const Vector<VecType> &v) const
{
    return diff(v);
}

template <typename Type>
template <typename VecType>
decltype(auto) Vector<Type>::operator*(const Vector<VecType> &v) const
{
    return dot_product(v);
}

template <typename Type>
template <typename ArgType>
decltype(auto) Vector<Type>::operator*(const ArgType &num) const
{
    return product(num);
}

template <typename Type>
template <typename ArgType>
decltype(auto) Vector<Type>::operator/(const ArgType &num) const
{
    return quotient(num);
}

template <typename Type>
template <typename VecType>
decltype(auto) Vector<Type>::operator^(const Vector<VecType> &v) const
{
    return cross_product(v);
}

template <typename Type>
Vector<Type> Vector<Type>::operator-() const
{
    return negative();
}

template <typename Type>
bool Vector<Type>::operator==(const Vector<Type> &v) const
{
    return is_equal(v);
}

template <typename Type>
bool Vector<Type>::operator!=(const Vector<Type> &v) const
{
    return is_not_equal(v);
}

template <typename Type>
Type &Vector<Type>::operator[](const std::size_t index)
{
    return get_elem_by_index(index);
}

template <typename Type>
const Type &Vector<Type>::operator[](const std::size_t index) const
{
    return get_elem_by_index(index);
}

// extra functions
template <typename Type>
bool Vector<Type>::is_zero() const
{
    if (size == 0)
        throw ZeroVectorException(__FILE__, __LINE__);
    bool only_zeros = true;
    for (auto element: *this)
        if (element)
            only_zeros = false;

    return only_zeros;
}

template <typename Type>
Vector<Type> Vector<Type>::get_ort() const
{
    if (size == 0)
        throw ZeroVectorException(__FILE__, __LINE__);

    Vector<Type> ort(*this);
    Iterator<Type> iter = ort.begin();

    for (auto element: *this)
    {
        *iter = element / module<Type>();
        ++iter;
    }

    return ort;
}

template <typename Type>
bool Vector<Type>::is_orthogonal(const Vector<Type> &vector) const
{
    return (fabs(*this * vector) < EPS);
}

template <typename Type>
bool Vector<Type>::is_collinear(const Vector<Type> &vector) const
{
    if (vector.is_zero() || is_zero())
        return true;
    return (angle<Type>(vector) < EPS);
}

template <typename Type>
template <typename OutType>
OutType Vector<Type>::angle(const Vector<Type> &vector) const
{
    if (vector.is_zero() || is_zero())
        return 0;
    return acos(*this * vector / module<Type>() / vector.module<Type>());
}

template <typename Type>
template <typename OutType>
OutType Vector<Type>::module() const
{
    return sqrt(*this * *this);
}

template <typename Type>
std::ostream &operator<<(std::ostream &out, const Vector<Type> &vector) noexcept
{
    if (!vector.get_size())
    {
        out << "Zero-sized vector";
        return out;
    }

    out << "{ ";
    for (auto element : vector)
    {
        out << element << " ";
    }
    out << "}";
    return out;
}

#endif // VECTOR_HPP
