#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};




class GUI
{
	enum MenuIcon //The icons of the menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,       //Rectangle icon in menu
		ICON_TRI,        //Triangle icon in menu
		ICON_SQU,//Square icon in menu <-- Add this line
		ICON_CIR,
		ICON_EXIT,       //Exit icon

		DRAW_ICON_COUNT  //no. of menu icons ==> This should be the last line in this enum
	};





	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		
	color FillColor;		
	color HighlightColor;	
	color MsgColor;			
	color BkGrndColor;		
	color StatusBarColor;	
	int PenWidth;			





	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void DrawCircle(Point P1, int radius, GfxInfo CircleGfxInfo) const; // Draw a circle
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	void DrawSquare(Point P1, int length, GfxInfo SquareGfxInfo) const; 

	
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  

	

	void PrintMessage(string msg) const;	

	color getCrntDrawColor() const;	
	color getCrntFillColor() const;	
	int getCrntPenWidth() const;		


	~GUI();
};

