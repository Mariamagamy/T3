#include <iostream>
using namespace std;
#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;
#include "colors.h"
#include <string>

#include "CMUgraphics.h"
#include "windowinput.h"
#include "error.h"

#include "mousequeue.h"

mqueue::mqueue() {

	mqueHead = NULL;
	mqueTail = NULL;

}

mqueue::~mqueue() {

	mqueuenode* mqueTmp;

	mqueTail = NULL;

	while (mqueHead != NULL) {
		mqueTmp = mqueHead;
		mqueHead = mqueHead->mqueNext;
		delete mqueTmp;
	}
}

void mqueue::Insert(mqueuenode* mqueNode) {

	if (mqueNode == NULL) {
		return;
	}
	else if (mqueHead == NULL) {
		mqueHead = mqueNode;
		mqueTail = mqueHead;
	}
	else {
		mqueTail->mqueNext = mqueNode;
		mqueTail = mqueTail->mqueNext;
	}
}

mqueuenode* mqueue::Remove() {

	mqueuenode* mqueTmp;

	if (mqueHead != NULL) {
		mqueTmp = mqueHead;
		mqueHead = mqueHead->mqueNext;
		mqueTmp->mqueNext = NULL;
	}
	else {
		mqueTmp = NULL;
	}

	return mqueTmp;

}

windowinput::windowinput(const HWND hwndNew, const window* wpNewWind) {

	wiHead = NULL;
	bWaitClose = true;
	usNumWindows = 0;

	AddWindow(hwndNew, wpNewWind);

}

windowinput::~windowinput() {

	if (wiHead != NULL) {
		delete wiHead;
	}

}

void windowinput::AddWindowInt(const HWND hwndNew, const window* wpNewWind, winode*& wiNode) {

	if (wiNode == NULL) {
		usNumWindows++;
		wiNode = new winode(hwndNew, wpNewWind);
		if (wiNode == NULL) {
			throw OUT_OF_MEMORY;
		}
	}
	else if (wiNode->hwndValue == hwndNew) {
		return;
	}
	else {
		AddWindowInt(hwndNew, wpNewWind, wiNode->wiNext);
	}

}

void windowinput::RemoveWindowInt(const HWND hwndOld, winode*& wiNode) {

	winode* wiTemp;

	if (wiNode == NULL) {
		return;
	}
	else if (wiNode->hwndValue == hwndOld) {
		usNumWindows--;
		wiTemp = wiNode->wiNext;
		wiNode->wiNext = NULL;
		delete wiNode;
		wiNode = wiTemp;
	}
	else {
		RemoveWindowInt(hwndOld, wiNode->wiNext);
	}

}

window* windowinput::FindWindowInt(const HWND hwndKey, const winode* wiNode) {

	if (wiNode == NULL) {
		return NULL;
	}
	else if (wiNode->hwndValue == hwndKey) {
		return ((window*)wiNode->wpValue);
	}
	else {
		return FindWindowInt(hwndKey, wiNode->wiNext);
	}
}

void windowinput::AddWindow(const HWND hwndNew, const window* wpNewWind) {

	AddWindowInt(hwndNew, wpNewWind, wiHead);

}

void windowinput::RemoveWindow(const HWND hwndOld) {

	RemoveWindowInt(hwndOld, wiHead);

}


window* windowinput::FindWindow(const HWND hwndKey) {

	return FindWindowInt(hwndKey, wiHead);

}

unsigned short windowinput::Count() {

	return usNumWindows;
}

void windowinput::SetMouseState(const HWND hwndKey, const button btMouse, const buttonstate bsNew, const int iX, const int iY) {

	window* windTmp = FindWindow(hwndKey);

	if (windTmp != NULL) {
		if (btMouse == LEFT_BUTTON) {
			windTmp->bsLeft = bsNew;
		}
		else {
			windTmp->bsRight = bsNew;
		}
		windTmp->iMouseX = iX;
		windTmp->iMouseY = iY;
	}

}

void windowinput::SetMouseCoord(const HWND hwndKey, const int iX, const int iY) {

	window* windTmp = FindWindow(hwndKey);

	if (windTmp != NULL) {
		windTmp->iMouseX = iX;
		windTmp->iMouseY = iY;
	}
}

void windowinput::SetClickInfo(const HWND hwndKey, const clicktype ctInfo, const int iX, const int iY) {

	window* windTmp = FindWindow(hwndKey);
	mqueuenode* mqueTmp;

	if (windTmp != NULL) {
		mqueTmp = new mqueuenode;
		if (mqueTmp == NULL) {
			throw OUT_OF_MEMORY;
		}
		mqueTmp->ctInfo = ctInfo;
		mqueTmp->iX = iX;
		mqueTmp->iY = iY;

		windTmp->mqueInput.Insert(mqueTmp);
	}
}

void windowinput::SetKeyInfo(const HWND hwndKey, const keytype ktInfo, const char cValue) {

	window* windTmp = FindWindow(hwndKey);
	kqueuenode* kqueTmp;

	if (windTmp != NULL) {
		kqueTmp = new kqueuenode;
		if (kqueTmp == NULL) {
			throw OUT_OF_MEMORY;
		}
		kqueTmp->ktInfo = ktInfo;
		kqueTmp->cValue = cValue;

		windTmp->kqueInput.Insert(kqueTmp);
	}
}



bool operator==(color a, color b) {

	return ((a.ucRed == b.ucRed) && (a.ucGreen == b.ucGreen) && (a.ucBlue == b.ucBlue));

}

bool operator!=(color a, color b) {

	return !(a == b);

}

shape::shape(GfxInfo shapeGfxInfo)
{
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}

void shape::SetSelected(bool s)
{
	ShpGfxInfo.isSelected = s;
}

bool shape::IsSelected() const
{
	return ShpGfxInfo.isSelected;
}

void shape::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}

void shape::ChngFillClr(color Fclr)
{
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr;
}

//forward decl
class GUI;

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
public:
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape

	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
};
#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Rect(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
};

#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info

	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(GUI* pUI) const = 0;		//Draw the shape

	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color

	
};


int main()
{
	window w(1200, 700);
	w.setpen(YELLOW, 6);
	w.setbrush(BLUE);
	w.drawoval(200, 400, 80);

	image testImage("Menu_Rect.JPG", JPEG);
	testwindow.DrawImage(testImage, 50, 50);
	testwindow.DrawImage(testImage, 50, 300, 500, 300);
	testwindow.DrawImage(testImage, 10, 10);

	return 0;