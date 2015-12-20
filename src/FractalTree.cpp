/* File: FractalTree.cpp
 * --------------------------------------------------------
 * This programm draws naked Pythagoras tree leaned from a wind.
 */

#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
using namespace std;

/* Function prototypes */
void drawTree(GWindow& window, GPoint start, int length, int degree, int iteration);

/* Contants */
const int ITERATIONS = 14;
const int START_LENGTH = 100;
const int TRUNK_COLOR = 0xe7552c;
const int LEAF_COLOR = 0x4cff00;
const double REDUCTION_RATIO = 0.74;
const int LEFT_ANGLE = 30;
const int RIGHT_ANGLE = 60;
const int START_ANGLE = 90;

/* Main function */
int main() {

    GWindow window(600, 400);

    GPoint start(window.getWidth() / 2, window.getHeight());

    drawTree(window, start, START_LENGTH, START_ANGLE, ITERATIONS);

    return 0;
}

/**
 * Function: drawTree
 * Usage: drawTree(window, start, length, angle, iteration);
 * -------------------------------------------------------------------------
 * This function recursively draws naked Pythagoras tree. Every new
 * iteration draws two new branches. Last five iterations branches
 * drawed using green color, like leafs.
 *
 * @param window GWindow for drawing
 * @param start Point of the begining of new branch
 * @param length Length of the new branch
 * @param angle Angle of every new branch
 * @param iteration Counter of current iteration
 */
void drawTree(GWindow& window, GPoint start, int length, int angle, int iteration){
    if(iteration > 0){
        if (iteration > 5){
            window.setColor(TRUNK_COLOR);
        } else {
            window.setColor(LEAF_COLOR);
        }

        start = window.drawPolarLine(start, length, angle);
        length *= REDUCTION_RATIO;
        iteration --;
        drawTree(window, start, length, angle - LEFT_ANGLE, iteration);
        drawTree(window, start, length, angle + RIGHT_ANGLE, iteration);
    }

}
