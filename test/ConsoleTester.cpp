/*
 * ConsoleTester
 * Tests LabelFilter library and measures execution time
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include <iostream>
#include <stdio.h>
#include <chrono> //for measuring time

#include <Coordinates.hpp>
#include <Size.hpp>
#include <Point.hpp>
#include <Label.hpp>
#include <LabelGroup.hpp>
#include <LabelGroupList.hpp>
#include <LabelFilter.hpp>
#include <CommonTestFunctions.hpp>

namespace pl
{
namespace rebold
{
namespace labelFilter
{

extern int HOW_MANY_LISTS;
extern int HOW_MANY_LABELS;

}//namespace labelFilter
}//namespace rebold
}//namespace pl



using namespace pl::rebold::labelFilter;

int main(int argc, char** argv )
{
    //Parsing arguments. First argument is for numer of lists, and second argument is for number of labels in each list
    LabelGroupList list;
    if(argc == 3)
    {
        HOW_MANY_LISTS = std::atoi(argv[1]);
        HOW_MANY_LABELS = std::atoi(argv[2]);
    }

    //Generating random labels:
    std::cout<<"Random generating labels:"<<std::endl;
    list = generateRadnomLists(Size{24,16}, Size{120,34});  //arguments are minimal and maximal label size
    //Printing all generated labels
    printList(list);
    //Creating filter
    LabelFilter newLabelFilter(list);

    //Filtering and printing names of all selected labels:
    std::cout<<"Selected labels:"<<std::endl;
    LabelGroup selectedLabels = newLabelFilter.getFilteredLabels(stable);
    for(LabelGroup::iterator git = selectedLabels.begin(); git != selectedLabels.end(); ++git){
        Label &label = (*git);

        std::cout<<label.name<<", ";
    }
    std::cout<<std::endl<<std::endl;


    //repeating operation 1000x to measure time
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<1000; ++i)
    {
        selectedLabels = newLabelFilter.getFilteredLabels(stable);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
 
    // To get the value of duration use the count()
    // member function on the duration object
    std::cout << "Average execution time of stable algorithm for "<<HOW_MANY_LABELS*HOW_MANY_LISTS<<" labels is: "<< duration.count()/1000.0 << " ms."<<std::endl;

    std::cout<<std::endl<<std::endl;

    start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<1000; ++i)
    {
        selectedLabels = newLabelFilter.getFilteredLabels(showMore);
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Average execution time of showMore algorithm for "<<HOW_MANY_LABELS*HOW_MANY_LISTS<<" labels is: "<< duration.count()/1000.0 << " ms."<<std::endl;

    std::cout<<std::endl<<std::endl;

    return 0;
}