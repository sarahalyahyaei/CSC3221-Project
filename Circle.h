//@Author: Sarah Al Yahyaei
//@Date: 21 Dec 2020
//@Purpose: Header file for Circle Shape
#include "Shape.h"
#pragma once
const static float DEFAULT_RADIUS = 1; 
class Circle: public Shape{
    public:
    virtual ~Circle();
    Circle();
    Circle(float x, float y, float radius);
    //Copy constrcutor
    Circle(const Circle& s);
    //Getter and setter for the radius 
    float getRadius() const;
    void setRadius(float newRadius);

    //Overloads
    bool operator==(const Circle& rhs);
    virtual Circle& operator=(const Circle& rhs);
    
    protected:
    float *radius;
};