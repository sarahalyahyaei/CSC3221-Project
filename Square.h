//@Author: Sarah Al Yahyaei
//@Date: 21 Dec 2020
//@Purpose: Header file for the Square shape
#include "Shape.h"
#pragma once
  const static float DEFAULT_WIDTH = 1;
  const static float DEFAULT_HEIGHT = 1;
class Square: public Shape{
  public:
    virtual ~Square();
    Square(); //Default Constructor
    Square(const Square& s); //Copy Constructor
    Square(float x, float y, float width, float height); 

    //Getters and Setters
    float getWidth() const;
    float getHeight() const;
    void setWidth(float width);
    void setHeight(float height);

    //Overload 
    virtual Square& operator= (const Square& rhs);
    bool operator==(const Square& rhs);
    

    
    protected:
    float* width;
    float* height;

};