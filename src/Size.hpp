/*
 * Size - structure representing a square size in 2d cartesian space.
 * e.g. pixel on a computer screen.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#pragma once
#ifndef SIZE_HPP
#define SIZE_HPP

namespace pl
{
namespace rebold
{
namespace labelFilter
{


struct Size {
    double w, h;
};


}//namespace labelFilter
}//namespace rebold
}//namespace pl

#endif // SIZE_HPP