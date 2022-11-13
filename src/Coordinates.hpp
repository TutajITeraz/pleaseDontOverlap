/*
 * Coordinates - longitide and latitude in any coordinate system.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

 

#pragma once
#ifndef COORDINATES_HPP
#define COORDINATES_HPP

namespace pl
{
namespace rebold
{
namespace labelFilter
{


struct Coordinates {
    double lon, lat;    //latitude, longitude
};


}//namespace labelFilter
}//namespace rebold
}//namespace pl

#endif // COORDINATES_HPP