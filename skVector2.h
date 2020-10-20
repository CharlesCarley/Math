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
#ifndef _skVector2_h_
#define _skVector2_h_

#include "skMath.h"

class skVector2
{
public:
    skVector2() :
        x(0), 
        y(0)
    {
    }

    skVector2(const skScalar nx, const skScalar ny) :
        x(nx), 
        y(ny)
    {
    }

    explicit skVector2(skScalar* p) :
        x(p[0]), 
        y(p[1])
    {
    }
    
    skVector2(const skVector2& v) :
        x(v.x), 
        y(v.y)
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

    SK_INLINE skVector2& operator=(const skVector2& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    SK_INLINE bool operator==(const skVector2& v) const
    {
        return skEq(x, v.x) && skEq(y, v.y);
    }

    SK_INLINE bool operator!=(const skVector2& v) const
    {
        return !skEq(x, v.x) && !skEq(y, v.y);
    }

    SK_INLINE bool operator<(const skVector2& v) const
    {
        return x < v.x && y < v.y;
    }

    SK_INLINE bool operator>(const skVector2& v) const
    {
        return x > v.x&& y > v.y;
    }

    SK_INLINE bool operator<=(const skVector2& v) const
    {
        return x <= v.x && y <= v.y;
    }

    SK_INLINE bool operator>=(const skVector2& v) const
    {
        return x >= v.x && y >= v.y;
    }

    SK_INLINE skVector2 operator+(skScalar v) const
    {
        return skVector2(x + v, y + v);
    }

    SK_INLINE skVector2 operator+(const skVector2& v) const
    {
        return skVector2(x + v.x, y + v.y);
    }

    SK_INLINE skVector2& operator+=(skScalar v)
    {
        x += v;
        y += v;
        return *this;
    }

    SK_INLINE skVector2& operator+=(const skVector2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    friend SK_INLINE skVector2 operator+(skScalar r, const skVector2& l)
    {
        return skVector2(l.x + r, l.y + r);
    }

    SK_INLINE skVector2 operator-(skScalar v) const
    {
        return skVector2(x - v, y - v);
    }

    SK_INLINE skVector2 operator-(const skVector2& v) const
    {
        return skVector2(x - v.x, y - v.y);
    }

    SK_INLINE skVector2& operator-=(skScalar v)
    {
        x -= v;
        y -= v;
        return *this;
    }

    SK_INLINE skVector2& operator-=(const skVector2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    SK_INLINE skVector2 operator-(void) const
    {
        return skVector2(-x, -y);
    }

    friend SK_INLINE skVector2 operator-(skScalar r, const skVector2& l)
    {
        return skVector2(l.x - r, l.y - r);
    }

    SK_INLINE skVector2 operator*(skScalar v) const
    {
        return skVector2(x * v, y * v);
    }

    SK_INLINE skVector2 operator*(const skVector2& v) const
    {
        return skVector2(x * v.x, y * v.y);
    }

    SK_INLINE skVector2& operator*=(skScalar v)
    {
        x *= v;
        y *= v;
        return *this;
    }

    SK_INLINE skVector2& operator*=(const skVector2& v)
    {
        x *= v.x;
        y *= v.y;
        return *this;
    }

    friend SK_INLINE skVector2 operator*(skScalar r, const skVector2& l)
    {
        return skVector2(l.x * r, l.y * r);
    }

    SK_INLINE skVector2 operator/(skScalar v) const
    {
        return skVector2(x / v, y / v);
    }

    SK_INLINE skVector2 operator/(const skVector2& v) const
    {
        return skVector2(x / v.x, y / v.y);
    }

    SK_INLINE skVector2& operator/=(skScalar v)
    {
        x /= v;
        y /= v;
        return *this;
    }

    SK_INLINE skVector2& operator/=(const skVector2& v)
    {
        x /= v.x;
        y /= v.y;
        return *this;
    }

    friend SK_INLINE skVector2 operator/(skScalar r, const skVector2& l)
    {
        return skVector2(l.x / r, l.y / r);
    }

    SK_INLINE skScalar length(void) const
    {
        return skSqrt(length2());
    }

    SK_INLINE skScalar length2(void) const
    {
        return dot(*this);
    }

    SK_INLINE skScalar dot(const skVector2& v) const
    {
        return x * v.x + y * v.y;
    }

    SK_INLINE skVector2 abs(void) const
    {
        return skVector2(skAbs(x), skAbs(y));
    }

    SK_INLINE skScalar distance(const skVector2& v) const
    {
        return skVector2(x - v.x, y - v.y).length();
    }

    SK_INLINE skScalar distance2(const skVector2& v) const
    {
        return skVector2(x - v.x, y - v.y).length2();
    }

    SK_INLINE skVector2 perpendicular(void) const
    {
        return skVector2(-y, x);
    }

    SK_INLINE bool isZero(void) const
    {
        return skIsZero(x) && skIsZero(y);
    }

    void normalize(void)
    {
        auto len = skSqrt(x * x + y * y);

        if (skIsZero(len))
        {
            len = skScalar(1.0) / len;
            x *= len;
            y *= len;
        }
    }

    skVector2 normalized(void) const
    {
        skVector2 v(x, y);
        v.normalize();
        return v;
    }

    SK_INLINE bool contains(skScalar x1, skScalar y1, skScalar x2, skScalar y2) const
    {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }

    void constrainX(skScalar min, skScalar max)
    {
        if (x < min)
            x = min;
        if (x > max)
            x = max;
        if (y < min)
            y = min;
        if (y > max)
            y = max;
    }

    void constrainY(skScalar min, skScalar max)
    {
        if (y < min)
            y = min;
        if (y > max)
            y = max;
    }

    void constrain(skScalar x1, skScalar y1, skScalar x2, skScalar y2)
    {
        constrainX(x1, x2);
        constrainY(y1, y2);
    }

public:
    skScalar x, y;

    static const skVector2 Unit;
    static const skVector2 UnitX;
    static const skVector2 UnitY;
    static const skVector2 Zero;
};

#endif  //_skVector2_h_
