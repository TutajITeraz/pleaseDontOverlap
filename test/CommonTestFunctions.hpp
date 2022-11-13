/*
 * CommonTestFunctions - functions for testing LabelFilter library.
 * Used in both the Visual and Console Tester.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#pragma once
#ifndef COMMON_TEST_FUNCTIONS_HPP
#define COMMON_TEST_FUNCTIONS_HPP

#include <Size.hpp>
#include <LabelGroupList.hpp>

namespace pl
{
namespace rebold
{
namespace labelFilter
{


const int WINDOW_W = 800;
const int WINDOW_H = 600;

extern int HOW_MANY_LISTS;
extern int HOW_MANY_LABELS;


double fRand(double fMin, double fMax);
void calculateScreenPixels(LabelGroupList &list, double scale);
LabelGroupList generateRadnomLists(Size min_label_size, Size max_label_size);
void printList(LabelGroupList &list);


}//namespace labelFilter
}//namespace rebold
}//namespace pl

#endif // COMMON_TEST_FUNCTIONS_HPP