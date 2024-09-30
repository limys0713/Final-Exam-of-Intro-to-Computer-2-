#include "Cuboid.h"

Cuboid::Cuboid(){
    x1 = 0;
    y1 = 0;
    z1 = 0;
    x2 = 2;
    y2 = 4;
    z2 = 4;

}

Cuboid::Cuboid(float x_1, float y_1, float z_1, float x_2, float y_2, float z_2){
    setpoint(x_1, y_1, z_1, x_2, y_2, z_2);
}

void Cuboid::setpoint(float x_1, float y_1, float z_1, float x_2, float y_2, float z_2){
    x1=x_1;
    y1=y_1;
    z1=z_1;
    x2=x_2;
    y2=y_2;
    z2=z_2;
}

void Cuboid::shift(int p, float d){
    if(p==1 || p==2 || p==3 || p==-1 || p==-2 || p==-3){    //if p is not these value, then it will not do anything for it

        if(p==1){
            x1=x1+d;
            x2=x2+d;
        }
        if(p==-1){
            x1=x1-d;
            x2=x2-d;
        }
        if(p==2){
            y1=y1+d;
            y2=y2+d;
        }
        if(p==-2){
            y1=y1-d;
            y2=y2-d;
        }
        if(p==3){
            z1=z1+d;
            z2=z2+d;
        }
        if(p==-3){
            z1=z1-d;
            z2=z2-d;
        }
    }
}

float Cuboid::operator/(float a){
    
    float x,y,z;

    if(x1<x2){
        x=x2-x1;
    }
    else{
        x=x1-x2;
    }
    if(y1<y2){
        y=y2-y1;
    }
    else{
        y=y1-y2;
    }
    if(z1<z2){
        z=z2-z1;
    }
    else{
        z=z1-z2;
    }

    if((x1>0 && x2>0 && x2>x1) || (x1<0 && x2<0 && x2>x1) || (x1<0 && x2>0) ){          //insert new coordinate for x2 while x1 remains const   //cuboid change x2 only
        x2=x1+(x/a);
    }
    else if((x1>0 && x2>0 && x2<x1) || (x1<0 && x2<0 && x2<x1) || (x1>0 && x2<0)){
        x2=x2+(x/a);
    }
    
    return (x/cbrt(a))*(y/cbrt(a))*(z/cbrt(a));

}

float Cuboid::operator*(float a){

    float x,y,z;

    if(x1<x2){
        x=x2-x1;           
    }
    else{
        x=x1-x2;
    }
    if(y1<y2){
        y=y2-y1;
    }
    else{
        y=y1-y2; 
    }
    if(z1<z2){
        z=z2-z1;
    }
    else{
        z=z1-z2; 
    }

    if((x1>0 && x2>0 && x2>x1) || (x1<0 && x2<0 && x2>x1) || (x1<0 && x2>0) ){          //insert new coordinate for x2 while x1 remains const
        x2=x1+(x*a);
    }
    else if((x1>0 && x2>0 && x2<x1) || (x1<0 && x2<0 && x2<x1) || (x1>0 && x2<0)){
        x2=x2+(x*a);
    }

    return (x*cbrt(a))*(y*cbrt(a))*(z*cbrt(a));
}

Cuboid::~Cuboid(){}

istream &operator>>(istream &in, Cuboid &a){
    
    in>>a.x1;
    in>>a.y1;
    in>>a.z1;
    in>>a.x2;               //to let the corresponding number be saved in the corresponding member data
    in>>a.y2;
    in>>a.z2;
    
    return in;

}
ostream &operator<<(ostream &out, Cuboid &b){

 out<<"the x1 is "<<b.x1<<endl;
    out<<"the y1 is "<<b.y1<<endl;
    out<<"the z1 is "<<b.z1<<endl;
    out<<"the x2 is "<<b.x2<<endl;
    out<<"the y2 is "<<b.y2<<endl;
    out<<"the z2 is "<<b.z2<<endl;

    return out;
}