

using namespace std;
#include<iostream>
#include "CMUgraphicsLib/colors.h"
#include<cmath>
#include<sstream>
#include "CMUgraphicsLib/CMUgraphics.h"
#include <stdio.h>
#include "CMUgraphicsLib\auxil.h"



#ifndef KEYQUEUE_H
#define KEYQUEUE_H

#include <cstdlib>
#include "version.h"




void GetColor(window& G)
{
    image testImage("scs.jpg", JPEG);

    G.SetBuffering(true);


    G.FlushMouseQueue();
    G.FlushKeyQueue();




    G.SetPen(WHITE);
    G.SetBrush(WHITE);
    G.DrawRectangle(0, 0, G.GetWidth(), G.GetHeight());

    int iX = 0, iY = 0;

    G.DrawImage(testImage, 10, 10);


    while (G.GetMouseClick(iX, iY) == NO_CLICK)
    {
        G.SetPen(WHITE);
        G.SetBrush(WHITE);
        G.DrawRectangle(4, 370, 630, 430);

        G.SetPen(BLACK);
        G.SetBrush(WHITE);

        double dRed, dGreen, dBlue;


        G.GetMouseCoord(iX, iY);
        G.GetColor(iX, iY, dRed, dGreen, dBlue);


        ostringstream output;
        output << "Red: " << dRed << "  Green: " << dGreen << "  Blue: " << dBlue;
        G.SetFont(28, BOLD | ITALICIZED, BY_NAME, "Arial");
        G.DrawString(5, 380, output.str());
        G.DrawString(G.GetWidth() / 2 - 100, G.GetHeight() - 50, "Click mouse to continue...");


        G.UpdateBuffer();
    }
    G.SetBuffering(false);





    Line(myWind);
    WaitNClear(myWind);



    triangle(myWind);
    WaitNClear(myWind);





    KeyboardMouse(myWind);
    GetColor(myWind);

}











   
