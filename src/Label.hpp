/*
 * LabelFilter - main class of the libLabelFilter
 * Basic implementation of map/chart decluttering labels algorithm.
 * It will determine which labels should be shown on the screen,
 * and which should not, depending on the labels position, collisions and priority.
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

#endif // LABEL_HPP