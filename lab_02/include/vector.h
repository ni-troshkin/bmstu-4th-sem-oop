#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <initializer_list>
#include <memory>

#include "base_container.h"
#include "iterator.h"
#include "constiter.h"

template <typename Type>
class Vector: public BaseContainer
{
    friend class Iterator<Type>;
    friend class ConstIterator<Type>;
public:    // changed order
    // constructors
    Vector() noexcept;
    explicit Vector(std::size_t size);
    explicit Vector(std::size_t size, const Type &elem);
    Vector(std::initializer_list <Type> list);
    explicit Vector(const Vector<Type> &vector);
    Vector(Vector<Type> &&vector) noexcept;

    template <typename IterType>
    Vector(const IterType &begin, const IterType &end);    // added template
    Vector(std::size_t size, const Type *array);    // added

    // destructor
    virtual ~Vector() = default;

    // operators
    Vector<Type> &operator=(const Vector<Type> &vector);
    Vector<Type> &operator=(Vector<Type> &&vector) noexcept;
    Vector<Type> &operator=(std::initializer_list <Type> list);  // added

    // +
    Vector<Type> &operator+=(const Vector<Type> &v);
    Vector<Type> &add(const Vector<Type> &v);

    template <typename VecType>
    decltype(auto) operator+(const Vector<VecType> &v) const;    // added
    template <typename VecType>
    decltype(auto) sum(const Vector<VecType> &vector) const;

    // -
    Vector<Type> &operator-=(const Vector<Type> &v);
    Vector<Type> &substract(const Vector<Type> &vector);

    template <typename VecType>
    decltype(auto) operator-(const Vector<VecType> &v) const;
    template <typename VecType>
    decltype(auto) diff(const Vector<VecType> &vector) const;

    // *
    Vector<Type> &operator*=(const Type &factor);   // double -> Type
    Vector<Type> &mul(const Type &factor);

    template <typename ArgType>
    decltype(auto) operator*(const ArgType &factor) const;
    template <typename ArgType>
    decltype(auto) product(const ArgType &factor) const;

    template <typename VecType>
    decltype(auto) operator*(const Vector<VecType> &v) const;
    template <typename VecType>
    decltype(auto) dot_product(const Vector<VecType> &vector) const;

    // x
    Vector<Type> &operator^=(const Vector<Type> &v);
    Vector<Type> &vec_mul(const Vector<Type> &v);

    template <typename VecType>
    decltype(auto) operator^(const Vector<VecType> &v) const;
    template <typename VecType>
    decltype(auto) cross_product(const Vector<VecType> &vector) const;

    // /
    Vector<Type> &operator/=(const Type &num);    // added
    Vector<Type> &divide(const Type &num);

    template <typename ArgType>
    decltype(auto) operator/(const ArgType &num) const;
    template <typename ArgType>
    decltype(auto) quotient(const ArgType &num) const;

    Vector<Type> operator-() const;
    Vector<Type> negative() const; // added

    bool operator==(const Vector<Type> &v) const;
    bool is_equal(const Vector<Type> &v) const;

    bool operator!=(const Vector<Type> &v) const;
    bool is_not_equal(const Vector<Type> &v) const;

    Type &operator[](const std::size_t index);
    const Type &operator[](const std::size_t index) const;
    Type &get_elem_by_index(const std::size_t index);
    const Type &get_elem_by_index(const std::size_t index) const;

    // functions

    bool is_zero() const;
    bool is_orthogonal(const Vector<Type> &vector) const;
    bool is_collinear(const Vector<Type> &vector) const;
    template <typename OutType>
    OutType angle(const Vector<Type> &vector) const;   // added template
    template <typename OutType>
    OutType module() const;
    Vector<Type> get_ort() const;

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;
    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;
    ConstIterator<Type> cbegin() const noexcept;
    ConstIterator<Type> cend() const noexcept;

protected:
    void check_dimensions(const std::size_t another_size, const int line_num) const;
    void check_if_zero_sized(const std::size_t another_size, const int line_num) const;
    void check_cross_prod_dimensions(const std::size_t another_size, const int line_num) const;

private:
    std::shared_ptr<Type[]> coord;
};

#include "vector.hpp"

#endif // VECTOR_H
