/*
 * CommonTestFunctions - functions for testing LabelFilter library.
 * Used in both the Visual and Console Tester.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */


#include <Point.hpp>
#include <Size.hpp>
#include <Coordinates.hpp>
#include <Label.hpp>
#include <LabelGroup.hpp>
#include <LabelGroupList.hpp>
#include <CommonTestFunctions.hpp>
#include <iostream>
#include <random>
#include <sstream>

namespace pl
{
namespace rebold
{
namespace labelFilter
{


int HOW_MANY_LISTS = 3;
int HOW_MANY_LABELS = 33;

double fRand(double fMin, double fMax)
{
    thread_local static std::random_device rd;

    thread_local static std::mt19937 gen(rd());

    std::uniform_real_distribution<double> dis(fMin,fMax);
    std::default_random_engine re;
    return dis(gen);
}


LabelGroupList generateRadnomLists(Size min_label_size, Size max_label_size)
{
    LabelGroupList list;

    for(int l=0; l<HOW_MANY_LISTS; l++)
    {
        LabelGroup group;

        for(int g=0; g<HOW_MANY_LABELS; g++)
        {
            double pos_x = fRand(0,WINDOW_W);
            double pos_y = fRand(0,WINDOW_H);
            double w = fRand(min_label_size.w,max_label_size.w);
            double h = fRand(min_label_size.h,max_label_size.h);
            double priority = floor(fRand(0.1,10.0));
            std::stringstream ssname;
            ssname << l <<"_label_" << g;

            Label label;
            label.name = ssname.str();
            label.position = Coordinates{pos_x, pos_y};
            label.pivot = Point{pos_x, pos_y};
            label.size = Size{w,h};
            label.priority = priority;

            group.push_back(label);
        }

        list.push_back(group);
    }

    return list;
}

void printList(LabelGroupList &list)
{
    int list_i=0;
    for (LabelGroupList::iterator lit = list.begin(); lit != list.end(); ++lit){
        std::cout<<"List "<<list_i++<<std::endl;

        for(LabelGroup::iterator git = lit->begin(); git != lit->end(); ++git){
            Label &label = (*git);

            std::cout<<label.name<<'\t'<<label.position.lon<<'\t'<<label.position.lat<<'\t'<<label.pivot.x<<'\t'<<label.pivot.y<<'\t'<<label.size.w<<'\t'<<label.size.h<<'\t'<<label.priority<<'\t'<<std::endl;
        }
        std::cout<<std::endl;
    }
}


}//namespace labelFilter
}//namespace rebold
}//namespace pl
