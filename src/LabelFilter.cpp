/*
 * LabelFilter - main class of the libLabelFilter
 * Basic implementation of map/chart decluttering labels algorithm.
 * It will determine which labels should be shown on the screen,
 * and which should not, depending on the labels position, collisions and priority.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include <LabelFilter.hpp>
#include <LabelGroupList.hpp>
#include <new> //For std::nothrow
#include <algorithm> //For std::sort

/**
 * Function checks if two label colides with each other
 *
 * @param l1 first label
 * @param l2 second label
 * @return true - if label colides, false - if they are not
 */

inline bool LabelFilter::checkLabelsCollision(const Label &l1,const Label &l2)
{
    return (
        l1.pivot.x < l2.pivot.x + l2.size.w &&
        l1.pivot.x + l1.size.w > l2.pivot.x &&
        l1.pivot.y < l2.pivot.y + l2.size.h &&
        l1.size.h + l1.pivot.y > l2.pivot.y
    );
}


/**
 * Function filters the list and returns one filtered out LabelGroup
 *

 * @param algorithm selects algoritm. It can be "stable" or "showMore".
 * @return all the labels that should be visible in a one combined group
 */
LabelGroup LabelFilter::getFilteredLabels(FilteringAlgorithm algorithm)
{
    if( algorithm == stable)
        return getFilteredLabelsStable();
    else //if algorithm == showMore
        return getFilteredLabelsShowMore();
}

LabelGroup LabelFilter::getFilteredLabelsStable()
{
    //Step 1. We are creating new group (allLabels) that will contain all the labels from all the datasets:
    LabelGroup allLabels;
    LabelGroup selectedLabels;

    int list_i=0;
    for (LabelGroupList::iterator lit = list.begin(); lit != list.end(); ++lit){
        allLabels.insert(allLabels.end(), (*lit).begin(), (*lit).end() );
    }

    //Step 2. Sorting the labels based on the position (left first):
    // We are using lamba compare function
    std::sort( allLabels.begin( ), allLabels.end( ), [ ]( const Label& label1, const Label& label2 )
    {
        return label1.pivot.x < label2.pivot.x;
    });

    //Step 3. Sorting the labels based on priority (using standard operator of the Label struct).
    // We have to use stable_sort to preserve previous order in case of the same priority:
    std::stable_sort(allLabels.begin(), allLabels.end(),std::greater<Label>());


    //Step 4. selecting labels one by one from the lowest priority
    for(LabelGroup::reverse_iterator a = allLabels.rbegin(); a != allLabels.rend(); ++a)
    {
        //We are comparing current selected label with all the lower priority labels
        //and delecting every lower priority label that we colide with
        //allLabels.erase(std::remove_if(a, allLabels.end();, 
        //               [](Label x) { return this->checkLabelsCollision((*a),(*x)) }), v.end());

        LabelGroup::reverse_iterator b = allLabels.rbegin();
        while(b != a)
        {
            if(this->checkLabelsCollision((*a),(*b)))
            {
                std::advance(b, 1);
                allLabels.erase(b.base());   //https://stackoverflow.com/questions/1830158/how-to-call-erase-with-a-reverse-iterator
            }
            else
                std::advance(b, 1);
        }
    }
    
    return allLabels;
}

LabelGroup LabelFilter::getFilteredLabelsShowMore()
{
    //Step 1. We are creating new group (allLabels) that will contain all the labels from all the datasets:
    LabelGroup allLabels;
    LabelGroup selectedLabels;

    int list_i=0;
    for (LabelGroupList::iterator lit = list.begin(); lit != list.end(); ++lit){
        allLabels.insert(allLabels.end(), (*lit).begin(), (*lit).end() );
    }

    //Step 2. Sorting the labels based on the position (left first):
    // We are using lamba compare function
    std::sort( allLabels.begin( ), allLabels.end( ), [ ]( const Label& label1, const Label& label2 )
    {
        return label1.pivot.x < label2.pivot.x;
    });

    //Step 3. Sorting the labels based on priority (using standard operator of the Label struct).
    // We have to use stable_sort to preserve previous order in case of the same priority:
    std::stable_sort(allLabels.begin(), allLabels.end(),std::greater<Label>());


    //Step 4. selecting labels one by one...
    for(LabelGroup::iterator a = allLabels.begin(); a != allLabels.end(); ++a)
    {
        //Step 4.1 We are brute-force checking collision of the label with the every other label already placed
        bool collisionDetected=false;
        for(LabelGroup::iterator s = selectedLabels.begin(); s != selectedLabels.end(); ++s)
        {
            //if collision is detected
            if(this->checkLabelsCollision((*a),(*s)))
            {
                collisionDetected=true;
                break;
            }
        }

        //if any collision is detected - we are skipping this label and checking next one
        if(collisionDetected)
            continue;

        //else (no collision detected) - we are adding the label to the selected list
        selectedLabels.push_back(*a);
    }
    
    return selectedLabels;
}

/**
 * Default constructor
 *
 * @param newList new list to process
 */
LabelFilter::LabelFilter()
{
}


/**
 * Constructor
 *
 * @param newList new list to process
 */
LabelFilter::LabelFilter(const LabelGroupList newList)
{
    this->list = newList;
}


/**
 * sets list to process
 *
 * @param newList new list to process
 */
void LabelFilter::setList(const LabelGroupList newList)
{
    this->list = newList;
}


/**
 * gets original (unfiltered) list saved in object
 *
 * @return original (unfiltered)  list saved in object
 */
LabelGroupList LabelFilter::getList()
{
    return this->list;
}

