//@Author: Sarah Al Yahyaei
//@Date: 21 Dec 2020
//@Purpose: Square Class
#include "Square.h"

//Defualt constructor
Square:: Square(){
    this->setX(DEFAULT_X);
    this->setY(DEFAULT_Y);
    this->setHeight(DEFAULT_HEIGHT);
    this->setWidth(DEFAULT_WIDTH);
}

Square:: Square(float x, float y, float width, float height){
    this->setX(x);
    this->setY(y);
    this->setWidth(width);
    this->setHeight(height);
}

Square::~Square(){
    if(!this->width){
        float* ptr1 = this->width;
        delete ptr1;
    }

    if(!this->height){
        float* ptr2 = this->height;
        delete ptr2;
    }
}

//Getters and Setter
float Square::getWidth() const{
    return *this->width;
}

float Square::getHeight() const{
    return *this->height;
}

void Square::setWidth(float width){
    if(this->width == nullptr){
        this->width = new float(width);
    }
    else{
        float* ptr = this->width;
        this-> width = new float(width);
        delete ptr;
    }
}

void Square::setHeight(float height){
  if(this->height == nullptr){
        this->height= new float(height);
    }
    else{
        float* ptr = this->height;
        this-> height = new float(height);
        delete ptr;
    }
}

//Overloads
bool Square::operator==(const Square& s){
    return(
        (this->getX() == s.getX()) &&
        (this->getY() == s.getY()) &&
        (this->getHeight() == s.getHeight()) && 
        (this->getWidth() == s.getWidth())
    );
}

Square& Square::operator=(const Square& s){
    if(*this == s)
    return *this;

    this->setX(s.getX());
    this->setY(s.getY());
    this->setWidth(s.getWidth());
    this->setHeight(s.getHeight());

    return *this;
}

