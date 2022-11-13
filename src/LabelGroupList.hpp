/*
 * LabelGroupList is a collection of LabelGroups. Dataset.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

 
 #pragma once
#ifndef LABEL_GROUP_LIST_HPP
#define LABEL_GROUP_LIST_HPP

#include <LabelGroup.hpp>
#include <list>

namespace pl
{
namespace rebold
{
namespace labelFilter
{


typedef std::list <LabelGroup> LabelGroupList;


}//namespace labelFilter
}//namespace rebold
}//namespace pl

#endif // LABEL_GROUP_LIST_HPP