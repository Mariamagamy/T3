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

void KeyboardMouse(window& K)
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