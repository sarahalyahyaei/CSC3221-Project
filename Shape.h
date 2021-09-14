//@Author: Sarah Al Yahyaei
//@Date: 21 Dec 2020
//@Purpose: Header file for Shapes objects
   static const int DEFAULT_X = 1;
   static const int DEFAULT_Y = 1;
class Shape{
public:
    Shape(); //Default Constructor
    Shape(float x, float y); 
    Shape(const Shape& s); //Copy Constructor
    virtual ~Shape(); //Virtual Deconstructor

    //Getters and Setters
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);

    //Methods to increase x and y on the gird
    void incrementX();
    void incrementY();


    //Overload to change shape position
    Shape& operator++(int);
    Shape& operator++();
    Shape& operator--(int);
    Shape& operator--();

    virtual Shape& operator=(const Shape& rhs);

    bool operator==(const Shape& rhs);
    
    private:
    float* x;
    float* y;

};