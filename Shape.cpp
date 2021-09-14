//@Author: Sarah Al Yahyaei
//@Date: 21 Dec 2020
//@Purpose: Shape class
#include "Square.h"

//Defualt constructor
Shape::Shape(){
    this->setX(DEFAULT_X);
    this->setY(DEFAULT_Y);
}

Shape::Shape(float x, float y){
    this->x = new float(x);
    this->y = new float(y);
}
Shape::~Shape(){
    if(this->x){
        float* ptr1 = this->x;
        delete ptr1;
    }
    if(this->y){
        float* ptr2 = this-> y;
        delete ptr2;
    }
}

Shape::Shape(const Shape& s){
        this->setX(s.getX());
        this->setY(s.getY());
}
void Shape:: setX(float x){
    if(!this->x){
        this-> x = new float(x);
    }
    else{
        float* ptr = this->x;
        this->x = new float(x);
        delete ptr;
    }
}

void Shape:: setY(float y){
    if(!this->y){
        this-> y = new float(y);
    }
    else{
        float* ptr = this->y;
        this->y = new float(y);
        delete ptr;
    }
}

float Shape::getX() const{
    return *this->x;
}

float Shape::getY() const{
    return *this->y;
}

void Shape::incrementX(){
    this->x +=1;
}

void Shape::incrementY(){
    this->y +=1;
}

//Overloads
Shape& Shape::operator++(int){
    this->x += 1;
    this->y += 1;
    return *this;
}

Shape& Shape:: operator++(){
    this->x +=1;
    this->y +=1;
    return *this;
}


Shape& Shape::operator--(int){
    this->x -= 1;
    this->y -= 1;
    return *this;
}

Shape& Shape:: operator--(){
    this->x -=1;
    this->y -=1;
    return *this;
}

Shape& Shape::operator=(const Shape& rhs){
    if(*this == rhs)
        return *this;

    this->setX(rhs.getX());
        return *this;
}

bool Shape::operator==(const Shape& rhs){
    return(
        this->getX() == rhs.getX()
    )
    && (
        this->getY() == rhs.getY());
}