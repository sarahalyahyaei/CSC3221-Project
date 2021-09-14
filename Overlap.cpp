//@Author: Sarah Al Yahyaei
//@Date: 24 Dec 2020
//@Purpose: Overlap algorithm

#include <math.h>
#include "Overlap.h"
//Two circle overlaping
//(Centre x of circle 1 - centre x of circle 2)^ 2
// - (Y of circle 1 - Y of circle 2)^2
//Must be less than the total of both radius

//Calulcate distance between two circles 
float Overlap::calDistance(float x1,float x2, float y1, float y2){
    return pow(x1 - x2,2.0) + pow(y1- y2,2.0);
}
//Detects overlapping
bool Overlap::twoCirclesCollisions(const Circle& circle1, const Circle& circle2){
   float distance = calDistance(circle1.getX(), circle2.getX(), circle1.getY(), circle2.getY());
    return pow(circle1.getRadius() + circle2.getRadius(), 2.0) >= distance;
}


//Coliision of two squares
/*
    if the coord of both sqaures intersect in the right top of sqaure 1 and top left of square 1 
    then they coliied and the same applies for all the coords in both squares.
    code from : http://www.jeffreythompson.org/collision-detection/rect-rect.php
*/
bool Overlap::twoSquaresCollisions(const Square& sq1, const Square& sq2){
    float sq1RightEdge = sq1.getX() + sq1.getWidth();
    float sq2LeftEdge = sq2.getX() + sq2.getWidth();
    float sq1TopEdge = sq1.getY() + sq1.getHeight();
    float sq2BottomEdge = sq2.getY() + sq2.getHeight();
    if(
        (sq1RightEdge >= sq2.getX())
        &&
        (sq1.getX() <= sq2LeftEdge)
        &&
        (sq1TopEdge >= sq2.getY())
        &&
        (sq1.getY() <= sq2BottomEdge)
    ){
        return true;
    }
    else{
        return false;
    }
}

//Collision of a square and a circle 
/*
    The algorthim will check when a circle is near a square 
    by calculatin the distance fron the centre of 
    the circle to one of the square edges
    Code taken from : http://www.jeffreythompson.org/collision-detection/circle-rect.php

*/
bool Overlap::circleAndSquareColiision(const Square& sq, const Circle circ){
    // 1- to check where the closest point to the circle 
    float checkX = circ.getX();
    float checkY = circ.getY();

    //2- Check the edges
    if(circ.getX() < sq.getX()){
        checkX = sq.getX();
    }
    

    else if(circ.getY() > sq.getX() + sq.getWidth()){
        checkX = sq.getX() + sq.getWidth();
    }
   

    if(circ.getY() < sq.getY()){
        checkY = sq.getY();
    }
  

    else if(circ.getY() > sq.getY() + sq.getHeight()){
         checkY = sq.getY() + sq.getHeight();
    }
   

    //3- Distance from closest edges 
    float distX = circ.getX() - checkX;
    float distY = circ.getY() - checkY;

    //4-Distance from the circle to the square
    float distance = sqrt(pow(distX,2.0) + pow(distY, 2.0)); 

    //5-Check if there is a collision 
    if(distance <= circ.getRadius())
    {
        return true;
    }
    else{
        return false;
    }
}