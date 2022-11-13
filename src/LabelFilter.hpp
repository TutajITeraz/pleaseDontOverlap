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
#ifndef LABEL_FILTER_HPP
#define LABEL_FILTER_HPP

#include <string>
#include <Point.hpp>
#include <Size.hpp>
#include <Coordinates.hpp>
#include <Label.hpp>
#include <LabelGroup.hpp>
#include <LabelGroupList.hpp>

class LabelFilter{
    public:
        LabelFilter();
        LabelFilter(const LabelGroupList newList);

        void                setList(const LabelGroupList newList);
        LabelGroupList      getList();
        LabelGroup          getFilteredLabels(FilteringAlgorithm algorithm=stable);

    private:
        LabelGroupList      list;

        bool                checkLabelsCollision(const Label &l1,const Label &l2);
        LabelGroup          getFilteredLabelsStable();
        LabelGroup          getFilteredLabelsShowMore();
};


#endif // LABEL_FILTER_HPP