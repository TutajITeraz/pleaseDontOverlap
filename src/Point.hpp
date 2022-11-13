/*
 * Point - structure representing a point in 2d cartesian space.
 * e.g. pixel on a computer screen.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

 
#pragma once
#ifndef POINT_HPP
#define POINT_HPP

namespace pl
{
namespace rebold
{
namespace labelFilter
{


struct Point {
    double x, y;
};


}//namespace labelFilter
}//namespace rebold
}//namespace pl

#endif // POINT_HPP