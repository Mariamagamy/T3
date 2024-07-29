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

// Types of keys that can be pressed
enum keytype {
    NO_KEYPRESS,
    ASCII,
    ARROW,
    FUNCTION,
    ESCAPE
};


void Line(window& L)
{


    L.SetPen(RED, 5);
    L.DrawLine(100, 100, 100, 420);

}

void triangle(window& T) {
    T.SetBrush(YELLOW);
    T.SetPen(RED, 5);
    T.DrawTriangle(50, 50, 50, 50, 50, 50);
}
void circle(window& C) {

    C.SetBrush(GREEN);
    C.SetPen(RED, 5);
    C.DrawCircle(75, 75, 50);








    //
    void KeyboardMouse(window & K)
    {
        K.SetBuffering(true);

        bool bQuit = false;
        keytype ktInput;
        clicktype ctInput;
        char cKeyData;


        K.FlushMouseQueue();
        K.FlushKeyQueue();

        K.SetFont(20, BOLD, BY_NAME, "Arial");

        do
        {

            K.SetPen(WHITE, 0);
            K.SetBrush(WHITE);
            K.DrawRectangle(0, 0, KGetWidth(), K.GetHeight());


            K.SetPen(BLACK);

            K.DrawString(5, 5, "Keyboard and Mouse Input Demo. Press \"Escape\" to quit");

            int iX, iY;
            ktInput = K.GetKeyPress(cKeyData);
            ctInput = K.GetMouseClick(iX, iY);


            if (ktInput == ESCAPE) {
                bQuit = true;
            }
            else if (ktInput == ASCII) {
                ostringstream output;
                output << "The ASCII key '" << cKeyData << "' was pressed.";
                K.DrawString(5, 30, output.str());
            }
            else if (ktInput == FUNCTION) {
                ostringstream output;
                output << "The Function key F" << int(cKeyData) << " was pressed.";
                K.DrawString(5, 30, output.str());
            }
            else if (ktInput == ARROW) {
                switch (cKeyData)
                {
                case 1:
                    K.DrawString(5, 30, "The End key was pressed.");
                    break;
                case 2:
                    K.DrawString(5, 30, "The Down Arrow key was pressed.");
                    break;
                case 3:
                    K.DrawString(5, 30, "The Page Down key was pressed.");
                    break;
                case 4:
                    K.DrawString(5, 30, "The Left Arrow key was pressed.");
                    break;
                case 5:
                    K.DrawString(5, 30, "The Center Keypad key was pressed.");
                    break;
                case 6:
                    K.DrawString(5, 30, "The Right Arrow key was pressed.");
                    break;
                case 7:
                    K.DrawString(5, 30, "The Home key was pressed.");
                    break;
                case 8:
                    K.DrawString(5, 30, "The Up Arrow key was pressed.");
                    break;
                case 9:
                    K.DrawString(5, 30, "The Page Up key was pressed.");
                }

            }

        }




        void GetColor(window & G)
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
        }





        
        void DrawMenu(window & M, string * MenuItems, int ItemCount, int MenuItemWidth, int MenuItemHeight)
        {
            // Draw menu item one image at a time
            for (int i = 0; i < ItemCount; i++)
                M.DrawImage(MenuItems[i], i * MenuItemWidth, 0, MenuItemWidth, MenuItemHeight);

            // Draw a line under the toolbar
            M.SetPen(RED, 3);
            M.DrawLine(0, MenuItemHeight, M.GetWidth(), MenuItemHeight);


        }
        void DetectMenu(window & M, int ItemCount, int MenuItemWidth, int MenuItemHeight)
        {

            // Draws instructions
            M.SetPen(BLACK);
            M.SetFont(20, BOLD, BY_NAME, "Arial");

            M.DrawString(5, testWindow.GetHeight() - 50, "Click on a menu icon. ==> Right-click to quit.....");

            while (1)
            {
                int Xcoord, Ycoord;
                clicktype ClkType = testWindow.WaitMouseClick(Xcoord, Ycoord);

                testWindow.SetPen(WHITE);
                testWindow.SetBrush(WHITE);
                testWindow.DrawRectangle(0, testWindow.GetHeight() - 100, testWindow.GetWidth(), testWindow.GetHeight());

                if (ClkType == RIGHT_CLICK) return;


                if (Ycoord < MenuItemHeight)
                {
                    int itemClicked = Xcoord / MenuItemWidth;	//int division
                    if (itemClicked < ItemCount)
                    {
                        ostringstream msg;
                        msg << "You clicked on menu item #" << itemClicked + 1 << "  Click on a menu icon. ==> Right-click to quit.....";
                        testWindow.SetPen(BLACK);
                        testWindow.DrawString(5, testWindow.GetHeight() - 50, msg.str());
                    }


                }


            }

        }

        ////////////////////////////////////////////////////////////////////////////
        int main()
        {


            window myWind(900, 700, 5, 5);

            myWind.ChangeTitle("TEAM 3..");

            Line(myWind);
            WaitNClear(myWind);



            triangle(myWind);
            WaitNClear(myWind);



            circleDemo(myWind);
            WaitNClear(myWind);


            KeyboardMouse(myWind);
            GetColor(myWind);






            return 0;
        }