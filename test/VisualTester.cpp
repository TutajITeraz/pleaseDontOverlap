/*
 * VisualTester
 * Used in both the Visual and Console Tester.
 *
 * Copyright (C) 2022 Łukasz Bolda < http://rebold.pl/ >
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include <stdio.h>
#include <opencv2/opencv.hpp>

#include <Coordinates.hpp>
#include <Size.hpp>
#include <Point.hpp>
#include <Label.hpp>
#include <LabelGroup.hpp>
#include <LabelGroupList.hpp>
#include <LabelFilter.hpp>
#include <CommonTestFunctions.hpp>


double SCALE = 1.0;
const double MIN_SCALE = 0.2;
const double SCALE_STEP = 0.02;
double PADDING_X = 1.0;
double PADDING_Y = 1.0;
extern int HOW_MANY_LISTS;
extern int HOW_MANY_LABELS;

cv::Mat SCREEN_MAT;
cv::Mat BG_IMAGE;

LabelGroupList LIST;

void calculateScreenPixels(LabelGroupList &list, double scale)
{
    int list_i=0;
    for (LabelGroupList::iterator lit = list.begin(); lit != list.end(); ++lit){

        for(LabelGroup::iterator git = lit->begin(); git != lit->end(); ++git){
            Label &label = (*git);

            label.pivot.x = floor(label.position.lon * scale) + PADDING_X;
            label.pivot.y = floor(label.position.lat * scale) + PADDING_Y;
        }
        //std::cout<<std::endl;
    }
}

void displayList(LabelGroupList &list)
{
    int list_i=0;
    for (LabelGroupList::iterator lit = list.begin(); lit != list.end(); ++lit){
        //std::cout<<"List "<<list_i++<<std::endl;

        for(LabelGroup::iterator git = lit->begin(); git != lit->end(); ++git){
            Label &label = (*git);

            //1. Draw rectangle
            int x = label.pivot.x;
            int y = label.pivot.y;
            int width = label.size.w;
            int height = label.size.h;
            cv::Scalar color = CV_RGB(200, 200, 200);

            cv::Rect rect(x, y+12, width, height);
            cv::rectangle(SCREEN_MAT, rect, color);

            //2. Draw priority
            std::stringstream label_ss;
            label_ss << label.priority;

            cv::putText(SCREEN_MAT, //target image
            label_ss.str(), //text
            cv::Point(x,y+26), //top-left position. 24 is font h
            cv::FONT_HERSHEY_COMPLEX_SMALL,
            1.0,
            color, //font color
            2);//2 makes bold
            
        }
        //std::cout<<std::endl;
    }

    //Drawing selected labels:
    LabelFilter newLabelFilter(list);
    LabelGroup selectedLabels = newLabelFilter.getFilteredLabels(stable);

    for(LabelGroup::iterator git = selectedLabels.begin(); git != selectedLabels.end(); ++git){
        Label &label = (*git);

        //1. Draw rectangle
        int x = label.pivot.x;
        int y = label.pivot.y;
        int width = label.size.w;
        int height = label.size.h;
        cv::Scalar color = CV_RGB(0, 0, 0);

        cv::Rect rect(x, y+12, width, height);
        cv::rectangle(SCREEN_MAT, rect, color);

        //2. Draw priority
        std::stringstream label_ss;
        label_ss << label.priority;

        cv::putText(SCREEN_MAT, //target image
        label_ss.str(), //text
        cv::Point(x,y+26), //top-left position. 24 is font h
        cv::FONT_HERSHEY_COMPLEX_SMALL,
        1.0,
        color, //font color
        2);//2 makes bold
        
    }

}

void refreshDisplay(){
    cv::resize(BG_IMAGE, SCREEN_MAT, cv::Size(WINDOW_W, WINDOW_H));
    calculateScreenPixels(LIST, SCALE);
    //printList(LIST);
    displayList(LIST);
    //cv::pyrUp(BG_IMAGE, SCREEN_MAT, cv::Size(WINDOW_W * SCALE, WINDOW_H * SCALE));
    cv::imshow("Label filter terster", SCREEN_MAT);
}


void on_mouse(int event, int x, int y, int flags, void* userdata)
{
    static int position_from_x = -1;
    static int position_from_y = -1;
    //mouse position for zoomming:
    static double mx;
    static double my;

    //printf("event = %d, %d\n", event, cv::getMouseWheelDelta(flags));

    if (event==cv::EVENT_MOUSEWHEEL){
        /*
        std::cout<<"mx = "<<mx<<std::endl;
        std::cout<<"my = "<<my<<std::endl;
        std::cout<<"x = "<<x<<std::endl;
        std::cout<<"y = "<<y<<std::endl;
        */
        if(cv::getMouseWheelDelta(flags)>0)//Zoom in
        {
            SCALE += SCALE_STEP;
            PADDING_X -= SCALE_STEP*x;
            PADDING_Y -= SCALE_STEP*y;
        }
        else{//zoom out
            if(SCALE >MIN_SCALE)
            {
                SCALE -= SCALE_STEP;

                PADDING_X += SCALE_STEP*x;
                PADDING_Y += SCALE_STEP*y;
            }
        }

        std::cout<<SCALE<<std::endl;

        refreshDisplay();
    }
    else if ( event == cv::EVENT_LBUTTONDOWN) // 
    {
        position_from_x = x;
        position_from_y = y;
    }
    else if ( event == cv::EVENT_LBUTTONUP) // 
    {
        /*
        PADDING_X += x - position_from_x;
        PADDING_Y += y - position_from_y;

        std::cout<<"PADDING_X"<<PADDING_X<<std::endl;
        std::cout<<"PADDING_Y"<<PADDING_Y<<std::endl;

        position_from_x = -1;
        position_from_y = -1;*/
        refreshDisplay();
    }
    else // mouse move (pressed)
    {
        PADDING_X += x - position_from_x;
        PADDING_Y += y - position_from_y;

        refreshDisplay();

        position_from_x = x;
        position_from_y = y;
    }

    
}

int main(int argc, char** argv )
{
    //generating background    
    BG_IMAGE = cv::imread( "../test/img/map.png", 1 );
    if ( !BG_IMAGE.data )
    {
        BG_IMAGE = cv::Mat(WINDOW_W,WINDOW_H,CV_8UC3, cv::Scalar(255, 210, 195));
    }
    
    cv::namedWindow("Label filter terster", cv::WINDOW_OPENGL );// other options: WINDOW_AUTOSIZE |  cv::WINDOW_GUI_NORMAL 


    refreshDisplay();

    cv::resizeWindow("Label filter terster", WINDOW_W, WINDOW_H );
    //cv::setWindowProperty"Label filter terster", prop_id, prop_value	);


    //Creating random list:
    LIST = generateRadnomLists(Size{24,16}, Size{120,34});
    refreshDisplay();

    cv::setMouseCallback( "Label filter terster", on_mouse, NULL );


    cv::waitKey(0);
    return 0;
}