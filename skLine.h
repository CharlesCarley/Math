/*
-------------------------------------------------------------------------------
    Copyright (c) 2019 Charles Carley.

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
#ifndef _skLine_h_
#define _skLine_h_

#include "skMath.h"

class skLine
{
public:
    // Point slope y - y1 = m(x - x1)
    skScalar m{}, y1{}, x1{};

public:

    skLine(const skLine& rhs) :
        m(rhs.m),
        y1(rhs.y1),
        x1(rhs.x1)
    {
    }

    skLine()
    {
    }


    skScalar F(skScalar x)
    {
        return (m * (x - x1)) + y1;
    }
};

#endif  //_skFoot_h_
