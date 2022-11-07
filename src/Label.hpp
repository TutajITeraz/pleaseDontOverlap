#pragma once
#ifndef LABEL_HPP
#define LABEL_HPP

#include <string>
#include <Point.hpp>
#include <Size.hpp>
#include <Coordinates.hpp>

struct Label {
    std::string     name;       //Name of the label
    Coordinates     position;   //position as longitude, latitude in WGS84
    Point           pivot;      //pivot point in screen pixels
    Size            size;       //size in screen pixels
    double          priority;   //display priority
};

#endif // LABEL_HPP