//@Author: Sarah Al Yahyaei
//@Date: 21 Dec 2020
//@Purpose: Circle class
#include "Circle.h"

//Constructors
Circle::Circle(){
    this->setX(DEFAULT_X);
    this->setY(DEFAULT_Y);
    this->setRadius(DEFAULT_RADIUS);
}


Circle::Circle(float x, float y, float radius){
    this->setX(x);
    this->setY(y);
    this->setRadius(radius);
}
//Copy Constructor
Circle::Circle(const Circle& s){
    this->setX(s.getX());
    this->setY(s.getY());
    this->setRadius(s.getRadius());
}
//Deconstructor
Circle::~Circle(){
    if(!this->radius){
        float* ptr = this->radius;
        delete ptr;
    }
}

//Setters and Getters
void Circle::setRadius(float radius){
    if(!this->radius){
        this->radius = new float(radius);
    }
    else{
        float* ptr = this-> radius;
        this->radius = new float(radius);
        delete ptr;
    }
}
float Circle::getRadius() const{
    return *this->radius;
}

//Overloads

Circle& Circle:: operator=(const Circle& rhs){
    if(*this == rhs){
        return *this;
    }
    
    else
    {
        this->setX(rhs.getX());
        this->setY(rhs.getY());
        this->setRadius(rhs.getRadius());
        return *this;
    }
    
}

bool Circle::operator==(const Circle& rhs){
    return(
        (this->getX() == rhs.getX()) &&
        (this->getY() == rhs.getY()) &&
        (this->getRadius() == rhs.getRadius())
    );
}
