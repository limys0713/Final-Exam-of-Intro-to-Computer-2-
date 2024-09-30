#ifndef Cube_H
#define Cube_H
#include "Block.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include<stdio.h>
using namespace std;

class Cube: public Block {                              //indicate the class cube inherits class block(public)
    friend istream &operator>>(istream&, Cube&);
    friend ostream &operator<<(ostream&, Cube&);

public:
	Cube();                                             //ctor of class cube
    Cube(float x_1, float y_1, float z_1, float x_2, float y_2, float z_2);       //ctor that receive 6 parameters
    void setpoint(float x_1, float y_1, float z_1, float x_2, float y_2, float z_2);        //set x1,y1,z1,x2,y2,z2
    ~Cube();
    void shift(int p, float d);

    float operator*(float);
    float operator/(float);
};

#endif
