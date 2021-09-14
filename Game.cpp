//@Author: Sarah Al Yahyaei
//@Date: 21 Dec 2020
//@Purpose: Test the overlap algorithm
#include "Overlap.h"
#include "Circle.h"
#include "Square.h"
#include <vector>
#include<iostream>
#include <random>

using namespace std;
const float xAxis = 100;
const float yAxis = 100;
float randomX = rand() % 100;
float randomY = rand() % 100;
Overlap* overlap = new Overlap();
int main(){
    //Create randome circles shapes
      vector <Circle*> circles(2);
    for (int i = 0; i< circles.size(); i++){
        float randomRadius = rand() % 100;
        Circle* cir = new Circle (randomX, randomY, randomRadius);
        circles[i] = cir;
    }
    //Create random Squares shapes
    vector<Square*> squares(2);
 for (int j = 0; j< squares.size(); j++){
        float randomHeigt = rand() % 100;
        float randomWidth = rand() % 100;
        Square* sqr = new Square(randomX, randomY, randomHeigt, randomWidth);
       squares[j] = sqr;
    }
    float currentXAxis = 0;
    float currentYAxis = 0;

    //Testing Circles Coliisions
    while((currentYAxis < yAxis && currentYAxis > 0) && (currentXAxis > 0 && currentXAxis < xAxis)){
        for(int i = 0; i < circles.size(); i++){
            for(int j = 1; j < circles.size()-1; j++ ){
            bool checkCollision = overlap->twoCirclesCollisions(*circles[i], *circles[j]);
            if(checkCollision){
                cout << "Two Circles are overlapped\n";
                cout << "Objects that are overlapped: \n" << 
                "Circle 1: \n" << "X: " << circles[i]->getX() << "\n"
                << "Y: " << circles[i]->getY() <<"\n";
                cout << "Circle 2: \n" << "X: " << 
                circles[j]->getX() << "\n"
                << "Y: " << circles[j]->getY() <<"\n";
                circles.erase(circles.begin()+j);
                circles.erase(circles.begin()+i);
            }
            else if (!checkCollision){
                circles[i]->incrementX();
                circles[i]->incrementY();
                currentXAxis = circles[i]->getX();
                currentYAxis = circles[i]->getY();
                cout << "Objects are moving";
            }
            
            else{
                cout << "End of the loop\n";
                break;
                }
            }   
        }
        
    }

    //Test Squares Coliisions
    float currentXAxis1 =0;
    float currentYAxis1 =0;
     while((currentYAxis < yAxis && currentYAxis > 0) && (currentXAxis > 0 && currentXAxis < xAxis)){
        for(int i = 0; i < squares.size(); i++){
            for(int j = 1; j < squares.size()-1; j++ ){
                    bool checkCollision = overlap->twoSquaresCollisions(*squares[i], *squares[j]);
                    if(checkCollision){
                cout << "Two Squares are overlapped\n";
                cout << "Objects that are overlapped: \n" << 
                "Square 1: \n" << "X: " <<  squares[i]->getX() << "\n"
                << "Y: " << squares[i]->getY() <<"\n";
                cout << "Square 2: \n" << "X: " << 
                squares[j]->getX() << "\n"
                << "Y: " << squares[j]->getY() <<"\n";
                squares.erase(squares.begin()+j);
                squares.erase(squares.begin()+i);
            }
            else if (!checkCollision){
                squares[i]->incrementX();
                squares[i]->incrementY();
                currentXAxis = squares[i]->getX();
                currentYAxis = squares[i]->getY();
                cout << "Objects are moving";
            }
            
            else{
                cout << "End of the loop\n";
                break;
                }
            }
        }
     }

     //Testing Square and circle overlap:
     


    //Delete objects after finishing
        delete overlap;
    return 0;
}

