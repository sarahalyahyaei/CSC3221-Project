//@Author: Sarah Al Yahyaei
//@Date:13 Jan 2021
//@Purpose: Overlap header file
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#pragma once

class Overlap{
public:
float calDistance(float x1,float x2, float y1, float y2);
bool twoCirclesCollisions(const Circle& circle1, const Circle& circle2);
bool twoSquaresCollisions(const Square& sq1, const Square& sq2);
bool circleAndSquareColiision(const Square& sq, const Circle circ);


};