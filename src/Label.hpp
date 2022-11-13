/*
 * Label is a simple text object with un-transformed and tranfsformed position
 * display priority, and size.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

 
#pragma once
#ifndef LABEL_HPP
#define LABEL_HPP

#include <string>
#include <Point.hpp>
#include <Size.hpp>
#include <Coordinates.hpp>

namespace pl
{
namespace rebold
{
namespace labelFilter
{


enum FilteringAlgorithm { stable, showMore };

struct Label {
    std::string     name;       //Name of the label
    Coordinates     position;   //position as longitude, latitude in WGS84
    Point           pivot;      //pivot point in screen pixels
    Size            size;       //size in screen pixels
    double          priority;   //display priority

    Label(){}
    Label(const std::string& n, const Coordinates &pos, const Point &piv, const Size &s, double pri ) 
        :       name(n),              position(pos),          pivot(piv),       size(s), priority(pri) {}

    bool operator < (const Label& otherLabel) const
    {
        return (priority < otherLabel.priority);
    }

    bool operator > (const Label& otherLabel) const
    {
        return (priority > otherLabel.priority);
    }

};


}//namespace labelFilter
}//namespace rebold
}//namespace pl

#endif // LABEL_HPP