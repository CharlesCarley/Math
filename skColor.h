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
#ifndef _skColor_h_
#define _skColor_h_

#include "skMath.h"

typedef unsigned int skColori;
class skColorHSV;
class skColor;

class skColorUtils
{
public:
    static const skScalar i100;
    static const skScalar i255;
    static const skScalar i360;

    static void convert(skColori& dst, const skColor& src);
    static void convert(skColor& dst, const skColori& src);
    static void convert(skColor& dst, const skColorHSV& src);
    static void convert(skColorHSV& dst, const skColor& src);
};

class skColorHSV
{
public:
    skColorHSV() :
        h(0),
        s(0),
        v(0),
        a(0)
    {
    }

    skColorHSV(const skColori& _h,
               const skColori& _s,
               const skColori& _v,
               const skColori& _a = 100) :
        h(skScalar(_h) * skColorUtils::i360),
        s(skScalar(_s) * skColorUtils::i100),
        v(skScalar(_v) * skColorUtils::i100),
        a(skScalar(_a) * skColorUtils::i100)
    {
    }

    skColorHSV(const skColor& rgb) :
        h(0),
        s(0),
        v(0),
        a(0)
    {
        skColorUtils::convert(*this, rgb);
    }

    void setHue(const skColori& _h)
    {
        h = skScalar(_h);
    }

    void setSaturation(const skColori& _s)
    {
        s = skScalar(_s) * skColorUtils::i100;
    }
    void setValue(const skColori& _v)
    {
        v = skScalar(_v) * skColorUtils::i100;
    }
    void saturate(skScalar fac)
    {
        s = skClamp(s + fac, skScalar(0.0), skScalar(1.0));
    }
    void lighten(skScalar fac)
    {
        v = skClamp(v + fac, skScalar(0.0), skScalar(1.0));
    }

    void toInt(skColori& _h, skColori& _s, skColori& _v, skColori& _a) const
    {
        _h = skColori(h);
        _s = skColori(s * 100);
        _v = skColori(v * 100);
        _a = skColori(a * 100);
    }

    // h is 0, 360;
    // s, v, a [0,1]
    skScalar h, s, v, a;
};

class skColor
{
public:
    skScalar r{}, g{}, b{}, a{};

    static const skColor White;
    static const skColor Black;

public:
    skColor() :
        a(1)
    {
    }

    skColor(skScalar _r, skScalar _g, skScalar _b, skScalar _a = skScalar(1.0)) :
        r(_r),
        g(_g),
        b(_b),
        a(_a)
    {
    }

    skColor(const skColor& o) :
        r(o.r),
        g(o.g),
        b(o.b),
        a(o.a)
    {
    }

    explicit skColor(const skColori& color)
    {
        skColorUtils::convert(*this, color);
    }

    operator skColori(void) const
    {
        skColori i;
        skColorUtils::convert(i, *this);
        return i;
    }

    explicit skColor(const skColorHSV& hsv)
    {
        skColorUtils::convert(*this, hsv);
    }

    void setHue(const skColori& h)
    {
        skColorHSV hsv;
        skColorUtils::convert(hsv, *this);
        hsv.h = skScalar(h);
        skColorUtils::convert(*this, hsv);
    }

    void setSaturation(const skColori& s)
    {
        skColorHSV hsv;
        skColorUtils::convert(hsv, *this);
        hsv.s = skScalar(s) * skColorUtils::i100;
        skColorUtils::convert(*this, hsv);
    }

    void setValue(const skColori& v)
    {
        skColorHSV hsv;
        skColorUtils::convert(hsv, *this);
        hsv.v = skScalar(v) * skColorUtils::i100;
        skColorUtils::convert(*this, hsv);
    }

    void saturate(skScalar fac)
    {
        skColorHSV hsv;
        skColorUtils::convert(hsv, *this);
        hsv.saturate(fac);
        skColorUtils::convert(*this, hsv);
    }

    void lighten(skScalar fac)
    {
        skColorHSV hsv;
        skColorUtils::convert(hsv, *this);
        hsv.lighten(fac);
        skColorUtils::convert(*this, hsv);
    }

    skColori asInt(void) const
    {
        skColori i;
        skColorUtils::convert(i, (*this));
        return i;
    }

    void limit(void)
    {
        r = skClamp<skScalar>(r, 0, 1);
        g = skClamp<skScalar>(g, 0, 1);
        b = skClamp<skScalar>(b, 0, 1);
        a = skClamp<skScalar>(a, 0, 1);
    }

    skColor limit(void) const
    {
        return skColor(
            skClamp<skScalar>(r, 0, 1),
            skClamp<skScalar>(g, 0, 1),
            skClamp<skScalar>(b, 0, 1),
            skClamp<skScalar>(a, 0, 1));
    }

    SK_INLINE skColor operator+(skScalar v) const
    {
        return skColor(r + v, g + v, b + v, a);
    }

    SK_INLINE skColor operator+(const skColor& v) const
    {
        return skColor(r + v.r, g + v.g, b + v.b, a);
    }

    skColor& operator+=(skScalar v)
    {
        r += v;
        g += v;
        b += v;
        return *this;
    }
    skColor& operator+=(const skColor& v)
    {
        r += v.r;
        g += v.g;
        b += v.b;
        return *this;
    }

    friend SK_INLINE skColor operator+(const skScalar rc, const skColor& l)
    {
        return l + rc;
    }

    SK_INLINE skColor operator-(skScalar v) const
    {
        return skColor(r - v, g - v, b - v, a);
    }

    SK_INLINE skColor operator-(const skColor& v) const
    {
        return skColor(r - v.r, g - v.g, b - v.b, a);
    }

    skColor& operator-=(skScalar v)
    {
        r -= v;
        g -= v;
        b -= v;
        return *this;
    }

    skColor& operator-=(const skColor& v)
    {
        r -= v.r;
        g -= v.g;
        b -= v.b;
        return *this;
    }

    friend SK_INLINE skColor operator-(const skScalar rc, const skColor& l)
    {
        return l - rc;
    }

    SK_INLINE skColor operator*(skScalar v) const
    {
        return skColor(r * v, g * v, b * v, a);
    }

    SK_INLINE skColor operator*(const skColor& v) const
    {
        return skColor(r * v.r, g * v.g, b * v.b, a);
    }

    skColor& operator*=(skScalar v)
    {
        r *= v;
        g *= v;
        b *= v;
        return *this;
    }

    skColor& operator*=(const skColor& v)
    {
        r *= v.r;
        g *= v.g;
        b *= v.b;
        return *this;
    }

    friend SK_INLINE skColor operator*(skScalar rc, const skColor& l)
    {
        return l * rc;
    }

    SK_INLINE skColor operator/(skScalar v) const
    {
        if (skIsZero(v))
            v = 1;
        return skColor(r / v, g / v, b / v, a);
    }

    SK_INLINE skColor operator/(const skColor& v) const
    {
        return skColor(r / v.r, g / v.g, b / v.b, a);
    }

    skColor& operator/=(skScalar v)
    {
        r /= v;
        g /= v;
        b /= v;
        return *this;
    }

    skColor& operator/=(const skColor& v)
    {
        r /= v.r;
        g /= v.g;
        b /= v.b;
        return *this;
    }

    friend SK_INLINE skColor operator/(skScalar rc, const skColor& l)
    {
        return l / rc;
    }

    skColor& operator=(const skColor& o)
    {
        r = o.r;
        g = o.g;
        b = o.b;
        a = o.a;
        return *this;
    }

    SK_INLINE skScalar* ptr()
    {
        return &r;
    }

    SK_INLINE const skScalar* ptr() const
    {
        return &r;
    }

    void asInt8(SKuint8& vr, SKuint8& vg, SKuint8& vb, SKuint8& va) const;
    void asRGB888(SKuint8& vr, SKuint8& vg, SKuint8& vb) const;

    void print() const;
};

#endif  //_skColor_h_
