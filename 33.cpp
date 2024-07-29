#include "CMUgraphicsLib/CMUgraphics.h"
#include "CMUgraphicsLib/auxil.h"
#include <cmath>
#include<iostream>
using name space std;

class RegularPolygon : public Shape {
private:
    double x, y, radius, numSides;
    string color;

public:
    RegularPolygon(double x, double y, double radius, int numSides, string color)
        : x(x), y(y), radius(radius), numSides(numSides), color(color) {}

    void draw() override {

        vector<double> xCoords, yCoords;
        for (int i = 0; i < numSides; i++) {
            double angle = 2 * M_PI * i / numSides;
            xCoords.push_back(x + radius * cos(angle));
            yCoords.push_back(y + radius * sin(angle));
        }


        setColor(color.c_str());
        beginShape();
        for (int i = 0; i < numSides; i++) {
            vertex(xCoords[i], yCoords[i]);
        }
        endShape(CLOSE);
    }

    void resize(double factor) override {
        radius *= factor;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
    }

    void setColor(string newColor) override {
        color = newColor;
    }

    string getColor() override {
        return color;
    }
};

int main() {
    initGraph();


    RegularPolygon polygon(200, 200, 50, 6, "green");
    polygon.draw();


    waitForMouseClick();
    closeGraph();

    return 0;
}