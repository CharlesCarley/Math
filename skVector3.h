/*
-------------------------------------------------------------------------------
    Copyright (c) 2012 Charles Carley.

  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#ifndef _skVector3_h_
#define _skVector3_h_

#include "skMath.h"
class skColor;

class skVector3
{
public:
    skVector3() :
        x(0),
        y(0),
        z(0)
    {
    }

    skVector3(skScalar nx, skScalar ny, skScalar nz) :
        x(nx),
        y(ny),
        z(nz)
    {
    }

    explicit skVector3(const skColor& col);

    explicit skVector3(const float* p)
    {
        if (p)
        {
            x = (skScalar)p[0];
            y = (skScalar)p[1];
            z = (skScalar)p[2];
        }
        else
            x = y = z = 0;
    }

    explicit skVector3(const double* p)
    {
        if (p)
        {
            x = (skScalar)p[0];
            y = (skScalar)p[1];
            z = (skScalar)p[2];
        }
        else
            x = y = z = 0;
    }

    skVector3(const skVector3& v) :
        x(v.x),
        y(v.y),
        z(v.z)
    {
    }

    SK_INLINE skScalar* ptr(void)
    {
        return &x;
    }

    SK_INLINE const skScalar* ptr(void) const
    {
        return &x;
    }

    SK_INLINE bool operator==(const skVector3& v) const
    {
        return skEq(x, v.x) && skEq(y, v.y) && skEq(z, v.z);
    }

    SK_INLINE bool operator!=(const skVector3& v) const
    {
        return !skEq(x, v.x) && !skEq(y, v.y) && !skEq(z, v.z);
    }

    SK_INLINE skVector3 operator+(skScalar v) const
    {
        return skVector3(x + v, y + v, z + v);
    }

    SK_INLINE skVector3 operator+(const skVector3& v) const
    {
        return skVector3(x + v.x, y + v.y, z + v.z);
    }

    skVector3& operator+=(skScalar v)
    {
        x += v;
        y += v;
        z += v;
        return *this;
    }

    skVector3& operator+=(const skVector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    SK_INLINE skVector3 operator-(skScalar v) const
    {
        return skVector3(x - v, y - v, z - v);
    }

    SK_INLINE skVector3 operator-(const skVector3& v) const
    {
        return skVector3(x - v.x, y - v.y, z - v.z);
    }

    skVector3& operator-=(skScalar v)
    {
        x -= v;
        y -= v;
        z -= v;
        return *this;
    }

    skVector3& operator-=(const skVector3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    SK_INLINE skVector3 operator-(void) const
    {
        return skVector3(-x, -y, -z);
    }

    SK_INLINE skVector3 operator*(skScalar v) const
    {
        return skVector3(x * v, y * v, z * v);
    }

    SK_INLINE skVector3 operator*(const skVector3& v) const
    {
        return skVector3(x * v.x, y * v.y, z * v.z);
    }

    skVector3& operator*=(skScalar v)
    {
        x *= v;
        y *= v;
        z *= v;
        return *this;
    }

    skVector3& operator*=(const skVector3& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    SK_INLINE skVector3 operator/(skScalar v) const
    {
        return skVector3(x / v, y / v, z / v);
    }

    SK_INLINE skVector3 operator/(const skVector3& v) const
    {
        return skVector3(x / v.x, y / v.y, z / v.z);
    }

    skVector3& operator/=(skScalar v)
    {
        x /= v;
        y /= v;
        z /= v;
        return *this;
    }

    skVector3& operator/=(const skVector3& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }

    SK_INLINE skScalar length(void) const
    {
        return skSqrt(length2());
    }

    SK_INLINE skScalar length2(void) const
    {
        return x * x + y * y + z * z;
    }

    SK_INLINE skScalar dot(const skVector3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    SK_INLINE skScalar distance(const skVector3& v) const
    {
        return skVector3(x - v.x, y - v.y, z - v.z).length();
    }

    SK_INLINE skScalar distance2(const skVector3& v) const
    {
        return skVector3(x - v.x, y - v.y, z - v.z).length2();
    }

    skVector3 cross(const skVector3& v) const
    {
        return skVector3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x);
    }

    void normalize(void)
    {
        const skScalar mag = length();
        if (mag > skScalar(0.0))
            *this /= mag;
    }

    skVector3 normalized(void) const
    {
        const skScalar mag = length();
        if (mag > skScalar(0.0))
            return skVector3(*this) / mag;
        return Zero;
    }
    void print(void) const;

    skScalar x, y, z;

public:
    static const skVector3 Unit;
    static const skVector3 UnitX;
    static const skVector3 UnitY;
    static const skVector3 UnitZ;
    static const skVector3 Zero;
};

SK_INLINE skVector3 operator-(skScalar r, const skVector3& l)
{
    return skVector3(l.x - r, l.y - r, l.z - r);
}

SK_INLINE skVector3 operator+(skScalar r, const skVector3& l)
{
    return skVector3(l.x + r, l.y + r, l.z + r);
}

SK_INLINE skVector3 operator/(skScalar r, const skVector3& l)
{
    return skVector3(l.x / r, l.y / r, l.z / r);
}

SK_INLINE skVector3 operator*(skScalar r, const skVector3& l)
{
    return skVector3(l.x * r, l.y * r, l.z * r);
}

#endif  //_skVector3_h_
