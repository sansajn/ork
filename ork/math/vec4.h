/*
 * Ork: a small object-oriented OpenGL Rendering Kernel.
 * Copyright (c) 2008-2010 INRIA
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.
 */

/*
 * Authors: Eric Bruneton, Antoine Begault, Guillaume Piolat.
 */

#ifndef _ORK_VEC4_H_
#define _ORK_VEC4_H_

#include "ork/math/vec3.h"
#include "half.h"

namespace ork
{

/**
 * A 4D vector.
 * @ingroup math
 */
template <typename type> class vec4
{
public:
    /**
     * x coordinate.
     */
    type x;

    /**
     * x coordinate.
     */
    type y;

    /**
     * z coordinate.
     */
    type z;

    /**
     * w coordinate.
     */
    type w;

    /**
     * Creates a new, uninitialized vector.
     */
    vec4();

    /**
     * Creates a new vector with the given coordinates.
     */
    vec4(type xi, type yi, type zi, type wi);

    /**
     * Creates a new vector with the given coordinates.
     */
    vec4(const type v[4]);

    /**
     * Creates a new vector as a copy of the given vector.
     */
    vec4(const vec4& v);

    /**
     * Creates a new vector as a copy of the given vector. The fourth
     * coordinate is initialized to 1.
     */
    vec4(const vec3<type>& v);

    /**
     * Creates a new vector as an extension of a vec3.
     */
    vec4(const vec3<type>& v, const type wi);

    /**
     * Returns the coordinate of this vector whose index is given.
     */
    type operator[](const int i) const;

    /**
     * Returns the coordinate of this vector whose index is given.
     */
    type& operator[](const int i);

    /**
     * Assigns the given vector to this vector.
     */
    vec4 operator=(const vec4& v);

    /**
     * Returns true if this vector is equal to the given vector.
     */
    bool operator==(const vec4& v) const;

    /**
     * Returns true if this vector is different from the given vector.
     */
    bool operator!=(const vec4& v) const;

    /**
     * Returns the sum of this vector and of the given vector.
     */
    vec4 operator+(const vec4& v) const;

    /**
     * Returns the difference of this vector and of the given vector.
     */
    vec4 operator-(const vec4& v) const;

    /**
     * Returns the product of this vector and of the given vector. The
     * product is done component by component.
     */
    vec4 operator*(const vec4& v) const;

    /**
     * Returns the product of this vector and of the given scalar.
     */
    vec4 operator*(const type scalar) const;

    /**
     * Returns the division of this vector and of the given vector. The
     * division is done component by component.
     */
    vec4 operator/(const vec4& v) const;

    /**
     * Returns the division of this vector and of the given scalar.
     */
    vec4 operator/(const type scalar) const;

    /**
     * Returns the opposite of this vector.
     */
    vec4 operator-() const;

    /**
     * Adds the given vector to this vector.
     */
    vec4& operator+=(const vec4& v);

    /**
     * Substracts the given vector from this vector.
     */
    vec4& operator-=(const vec4& v);

    /**
     * Multiplies this vector by the given scalar.
     */
    vec4& operator*=(const type scalar);

    /**
     * Divides this vector by the given scalar.
     */
    vec4& operator/=(const type scalar);

    /**
     * Compare first element, then second if equal, then third if equal, then fourth if equal.
     */
    bool operator<(const vec4& v) const;

    /**
     * Returns the dot product of this vector and of the given vector.
     * The given vector is considered as a 4D vector with w = 1.
     */
    type dotproduct(const vec3<type>& v) const;

    /**
     * Returns the dot product of this vector and of the given vector.
     */
    type dotproduct(const vec4& v) const;

    /**
     * Returns the 3D vector defined by (x/w,y/w,z/w).
     */
    vec3<type> xyzw() const;

    /**
     * Returns the 3D vector defined by (x,y,z).
     */
    vec3<type> xyz() const;

    /**
     * Returns the 2D vector defined by (x,y).
     */
    vec2<type> xy() const;

    /**
     * Casts this vector to another base type.
     */
    template <class t>
    vec4<t> cast() const {
        return vec4<t>((t) x, (t) y, (t) z, (t )w);
    }

    /**
     * The null vector (0,0,0,0).
     */
    static const vec4 ZERO;

    /**
     * The unit x vector (1,0,0,0).
     */
    static const vec4 UNIT_X;

    /**
     * The unit y vector (0,1,0,0).
     */
    static const vec4 UNIT_Y;

    /**
     * The unit z vector (0,0,1,0).
     */
    static const vec4 UNIT_Z;

    /**
     * The unit w vector (0,0,0,1).
     */
    static const vec4 UNIT_W;
};

/**
 * A 4D vector with half float coordinates.
 * @ingroup math
 */
typedef vec4<half> vec4h;

/**
 * A 4D vector with float coordinates.
 * @ingroup math
 */
typedef vec4<float> vec4f;

/**
 * A 4D vector with double coordinates.
 * @ingroup math
 */
typedef vec4<double> vec4d;

/**
 * A 4D vector with int coordinates.
 * @ingroup math
 */
typedef vec4<int> vec4i;

template <typename type>
inline vec4<type>::vec4()
{
}

template <typename type>
inline vec4<type>::vec4(type xi, type yi, type zi, type wi) :
    x(xi), y(yi), z(zi), w(wi)
{
}

template <typename type>
inline vec4<type>::vec4(const type v[4]) :
    x(v[0]), y(v[1]), z(v[2]), w(v[3])
{
}

template <typename type>
inline vec4<type>::vec4(const vec4& v) :
    x(v.x), y(v.y), z(v.z), w(v.w)
{
}

template <typename type>
inline vec4<type>::vec4(const vec3<type>& v) :
    x(v.x), y(v.y), z(v.z), w(1)
{
}

template <typename type>
inline vec4<type>::vec4(const vec3<type>& v, const type wi) :
    x(v.x), y(v.y), z(v.z), w(wi)
{
}

template <typename type>
inline type vec4<type>::operator[](const int i) const
{
    //assert(i<4);
    return *(&x + i);
}

template <typename type>
inline type& vec4<type>::operator[](const int i)
{
    //assert(i<4);
    return *(&x + i);
}

template <typename type>
inline vec4<type> vec4<type>::operator=(const vec4<type>& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

template <typename type>
inline bool vec4<type>::operator==(const vec4<type>& v) const
{
    return (x == v.x && y == v.y && z == v.z && w == v.w);
}

template <typename type>
inline bool vec4<type>::operator!=(const vec4<type>& v) const
{
    return (x != v.x || y != v.y || z != v.z || w != v.w);
}

template <typename type>
inline vec4<type> vec4<type>::operator+(const vec4<type>& v) const
{
    return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

template <typename type>
inline vec4<type> vec4<type>::operator-(const vec4<type>& v) const
{
    return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

template <typename type>
inline vec4<type> vec4<type>::operator*(const vec4<type>& v) const
{
    return vec4(x * v.x, y * v.y, z * v.z, w * v.w);
}

template <typename type>
inline vec4<type> vec4<type>::operator*(const type scalar) const
{
    return vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}

template <typename type>
inline vec4<type> vec4<type>::operator/(const vec4<type>& v) const
{
    return vec4(x / v.x, y / v.y, z / v.z, w / v.w);
}

template <typename type>
inline vec4<type> vec4<type>::operator/(const type scalar) const
{
    assert(scalar != 0);
    type inv = 1 / scalar;
    return vec4(x * inv, y * inv, z * inv, w * inv);
}

template <typename type>
inline vec4<type> vec4<type>::operator-() const
{
    return vec4(-x, -y, -z, -w);
}

template <typename type>
inline vec4<type>& vec4<type>::operator+=(const vec4<type>& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

template <typename type>
inline vec4<type>& vec4<type>::operator-=(const vec4<type>& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

template <typename type>
inline vec4<type>& vec4<type>::operator*=(const type scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

template <typename type>
inline vec4<type>& vec4<type>::operator/=(const type scalar)
{
    assert(scalar != 0);
    type inv = 1 / scalar;
    x *= inv;
    y *= inv;
    z *= inv;
    w *= inv;
    return *this;
}

template <typename type>
inline bool vec4<type>::operator<(const vec4<type>& v) const
{
    if (x < v.x) {
        return true;
    }
    if (x > v.x) {
        return false;
    }
    if (y < v.y) {
        return true;
    }
    if (y > v.y) {
        return false;
    }
    if (z < v.z) {
        return true;
    }
    if (z > v.z) {
        return false;
    }
    return w < v.w;
}

template <typename type>
inline type vec4<type>::dotproduct(const vec3<type>& v) const
{
    return (x*v.x + y*v.y + z*v.z + w);
}

template <typename type>
inline type vec4<type>::dotproduct(const vec4<type>& v) const
{
    return (x*v.x + y*v.y + z*v.z + w*v.w);
}

template <typename type>
inline vec3<type> vec4<type>::xyzw() const
{
    return vec3<type>(x / w, y / w, z / w);
}

template <typename type>
inline vec3<type> vec4<type>::xyz() const
{
    return vec3<type>(x, y, z);
}

template <typename type>
inline vec2<type> vec4<type>::xy() const
{
    return vec2<type>(x, y);
}

template <typename type>
const vec4<type> vec4<type>::ZERO(0, 0, 0, 0);

template <typename type>
const vec4<type> vec4<type>::UNIT_X(1, 0, 0, 0);

template <typename type>
const vec4<type> vec4<type>::UNIT_Y(0, 1, 0, 0);

template <typename type>
const vec4<type> vec4<type>::UNIT_Z(0, 0, 1, 0);

template <typename type>
const vec4<type> vec4<type>::UNIT_W(0, 0, 0, 1);

}

/**
 * Returns the product of this vector and of the given scalar.
 */
template <typename scalarType, typename vecType>
inline ork::vec4<vecType> operator*(const scalarType scalar, const ork::vec4<vecType> &v)
{
  return v * static_cast<vecType>(scalar);
}

#endif
