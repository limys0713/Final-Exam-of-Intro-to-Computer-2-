#ifndef Cuboid_H
#define Cuboid_H
#include "Block.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include<stdio.h>
using namespace std;

class Cuboid: public Block {                              //indicate the class cuboid inherits class block(public)
    friend istream &operator>>(istream&, Cuboid&);
    friend ostream &operator<<(ostream&, Cuboid&);

public:
	Cuboid();                                             //ctor of class cuboid
    Cuboid(float x_1, float y_1, float z_1, float x_2, float y_2, float z_2);       //ctor that receive 6 parameters
    void setpoint(float x_1, float y_1, float z_1, float x_2, float y_2, float z_2);        //set x1,y1,z1,x2,y2,z2
    ~Cuboid();
    void shift(int p, float d);

    float operator*(float);
    float operator/(float);
};

#endif