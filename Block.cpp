#include "Block.h"

Block::Block(const Block &G){


    x1=G.x1;
    y1=G.y1;
    z1=G.z1;            // copy the new member datas with the data in G
    x2=G.x2;
    y2=G.y2;
    z2=G.z2;
}  

float Block::interVolumn(float x_1, float y_1, float z_1, float x_2, float y_2, float z_2){

    float a,b,c;
    a=0;
    b=0;                // for if the condition below didnt match just all equals to 0 (didnt have intervolumn)
    c=0;

    if((x1==x_1 && y1==y_1 && z1==z_1 && x2==x_2 && y2==y_2 && z2==z_2) || (x1==x_2 && y1==y_2 && z1==z_2 && x2==x_1 && y2==y_1 && z2==z_1)){                 //same shape
       if(x2>x1){a=x2-x1;}
       else{a=x1-x2;}
       if(y2>y1){b=y2-y1;}
       else{b=y1-y2;}
       if(z2>z1){c=z2-z1;}
       else{c=z1-z2;}
    }
    else{
    if(x_1<x1 && x1<x_2){         //for x
        if(x1>x_1 && x_1>x2){
            a=x1-x_1;
        }
        if(x1<x_2 && x_2<x2){
            a=x_2-x1;
        }    
    }
    if(x_1>x1 && x1>x_2){
        if(x2>x_1 && x_1>x1){
            a=x_1-x1;
        }
        if(x2<x_2 && x_2<x1){
            a=x1-x_2;
        }  
    }
    if(x_1<x2 && x2<x_2){
       if(x2>x_1 && x_1>x1){
            a=x2-x_1;
        }
        if(x2<x_2 && x_2<x1){
            a=x_2-x2;
        } 
    }
    if(x_1>x2 && x_2>x_2){
         if(x1>x_1 && x_1>x2){
            a=x_1-x2;
        }
        if(x1<x_2 && x_2<x2){
            a=x2-x_2;
        }  
    }
    if(x_1<=x1 && x1<=x_2 && x_1<=x2 && x2<=x_2){    //for the cuboid(smaller square)  //means x1 x2 square inside x_1 x_2
        if(x1>x2){a=x1-x2;}
        else{a=x2-x1;}
    }
    if(x1<=x_1 && x_1<=x2 && x1<=x_2 && x_2<=x2){    //for the cuboid(smaller square)  //means x_1 x_2 square inside x1 x2
        if(x_1>x_2){a=x_1-x_2;}
        else{a=x_2-x_1;}
    }
    if(x_2<=x1 && x1<=x_1 && x_2<=x2 && x2<=x_1){    //for the cuboid(smaller square)  
        if(x1>x2){a=x1-x2;}
        else{a=x2-x1;}
    }
    if(x2<=x_1 && x_1<=x1 && x2<=x_2 && x_2<=x1){    //for the cuboid(smaller square)  
        if(x_1>x_2){a=x_1-x_2;}
        else{a=x_2-x_1;}
    }


    if(y_1<y1 && y1<y_2){     //for y
        if(y1>y_1 && y_1>y2){
            b=y1-y_1;
        }
        if(y1<y_2 && y_2<y2){
            b=y_2-y1;
        }    
    }
    if(y_1>y1 && y1>y_2){
        if(y2>y_1 && y_1>y1){
            b=y_1-y1;
        }
        if(y2<y_2 && y_2<y1){
            b=y1-y_2;
        }  
    }
    if(y_1<y2 && y2<y_2){
        if(y2>y_1 && y_1>y1){
            b=y2-y_1;
        }
        if(y2<y_2 && y_2<y1){
            b=y_2-y2;
        } 
    }
    if(y_1>y2 && y2>y_2){
         if(y1>y_1 && y_1>y2){
            b=y_1-y2;
        }
        if(y1<y_2 && y_2<y2){
            b=y2-y_2;
        }  
    }
    if(y_1<=y1 && y1<=y_2 && y_1<=y2 && y2<=y_2){    //for the cuboid(smaller square)  //means y1 y2 square inside y_1 y_2
        if(y1>y2){b=y1-y2;}
        else{b=y2-y1;}
    }
    if(y1<=y_1 && y_1<=y2 && y1<=y_2 && y_2<=y2){    //for the cuboid(smaller square)  //means y_1 y_2 square inside y1 y2
        if(y_1>y_2){b=y_1-y_2;}
        else{b=y_2-y_1;}
    }
    if(y_2<=y1 && y1<=y_1 && y_2<=y2 && y2<=y_1){    //for the cuboid(smaller square)  
        if(y1>y2){b=y1-y2;}
        else{b=y2-y1;}
    }
    if(y2<=y_1 && y_1<=y1 && y2<=y_2 && y_2<=y1){    //for the cuboid(smaller square)  
        if(y_1>y_2){b=y_1-y_2;}
        else{b=y_2-y_1;}
    }


    if(z_1<z1 && z1<z_2){         //for z
        if(z1>z_1 && z_1>z2){
            c=z1-z_1;
        }
        if(z1<z_2 && z_2<z2){
            c=z_2-z1;
        }    
    }
    if(z_1>z1 && z1>z_2){
        if(z2>z_1 && z_1>z1){
            c=z_1-z1;
        }
        if(z2<z_2 && z_2<z1){
            c=z1-z_2;
        }  
    }
    if(z_1<z2 && z2<z_2){
        if(z2>z_1 && z_1>z1){
            c=z2-z_1;
        }
        if(z2<z_2 && z_2<z1){
            c=z_2-z2;
        } 
    }
    if(z_1>z2 && z2>z_2){
         if(z1>z_1 && z_1>z2){
            c=z_1-z2;
        }
        if(z1<z_2 && z_2<z2){
            c=z2-z_2;
        }  
    }
    if(z_1<=z1 && z1<=z_2 && z_1<=z2 && z2<=z_2){    //for the cuboid(smaller square)  //means z1 z2 square inside z_1 z_2
        if(z1>z2){c=z1-z2;}
        else{c=z2-z1;}
    }
    if(z1<=z_1 && z_1<=z2 && z1<=z_2 && z_2<=z2){    //for the cuboid(smaller square)  //means z_1 z_2 square inside z1 z2
        if(z_1>z_2){c=z_1-z_2;}
        else{c=z_2-z_1;}
    }
    if(z_2<=z1 && z1<=z_1 && z_2<=z2 && z2<=z_1){    //for the cuboid(smaller square)  
        if(z1>z2){c=z1-z2;}
        else{c=z2-z1;}
    }
    if(z2<=z_1 && z_1<=z1 && z2<=z_2 && z_2<=z1){    //for the cuboid(smaller square)  
        if(z_1>z_2){c=z_1-z_2;}
        else{c=z_2-z_1;}
    }
    }
    return a*b*c;
}

void Block::rotate(int p, bool d){
    //idea: declare Block item and send it to block rotate function to do
    if(p=0 || (p!=1 && p!=2)){                    // rotate to x
        if(d=0){                //rotate clockwise
            if(z1>=0 && z2>0){              //if z1=0 z2 will never be 0
                if(y1>=0 && y2>0){
                    z1=(-1*z1); //change z
                    z2=(-1*z2);
                }
                else if(y1<=0 && y2<0){
                     y1=(-1*y1); //change y
                     y2=(-1*y2); 
                }   
            }
            if(z1<=0 && z2<0)  {                                             //** =0 situation haven been considered
                if(y1<=0 && y2<0){
                    z1=(-1*z1); //change z
                    z2=(-1*z2); 
                }
                else if(y1>=0 && y2>0){
                     y1=(-1*y1); //change y
                     y2=(-1*y2); 
                }
            }
        }
        if(d=1){                //rotate counterclockwise
            if(z1>=0 && z2>0){
                if(y1>=0 && y2>0){
                    y1=(-1*y1); //change y
                    y2=(-1*y2); 
                }
                else if(y1<=0 && y2<0){
                    z1=(-1*z1); //change z
                    z2=(-1*z2); 
                }   
            }
            if(z1<=0 && z2<0)  {                                             //** =0 situation haven been considered
                if(y1<=0 && y2<0){
                    y1=(-1*y1); //change y
                    y2=(-1*y2);  
                }
                else if(y1>=0 && y2>0){
                   z1=(-1*z1); //change z
                    z2=(-1*z2); 
                }
            }
        }  
    }
    if(p=1){    //rotate to y
        if(d=0){                
            if(z1>=0 && z2>0){              //if z1=0 z2 will never be 0
                if(x1>=0 && x2>0){
                    z1=(-1*z1); //change z
                    z2=(-1*z2);
                }
                else if(x1<=0 && x2<0){
                     x1=(-1*x1); //change x
                     x2=(-1*x2); 
                }   
            }
            if(z1<=0 && z2<0)  {                                             //** =0 situation haven been considered
                if(y1<=0 && y2<0){
                    z1=(-1*z1); //change z
                    z2=(-1*z2); 
                }
                else if(x1>=0 && x2>0){
                     x1=(-1*x1); //change x
                     x2=(-1*x2); 
                }
            }
        }
        if(d=1){                
            if(z1>=0 && z2>0){
                if(x1>=0 && x2>0){
                    x1=(-1*x1); //change x
                    x2=(-1*x2); 
                }
                else if(y1<=0 && y2<0){
                    z1=(-1*z1); //change z
                    z2=(-1*z2); 
                }   
            }
            if(z1<=0 && z2<0)  {                                             //** =0 situation haven been considered
                if(x1<=0 && x2<0){
                    x1=(-1*x1); //change x
                    x2=(-1*x2); 
                }
                else if(x1>=0 && x2>0){
                    z1=(-1*z1); //change z
                    z2=(-1*z2); 
                }
            }
        } 
    }
    if(p=2){    //rotate to z
        if(d=0){                
            if(y1>=0 && y2>0){              
                if(x1>=0 && x2>0){
                    y1=(-1*y1); //change y
                    y2=(-1*y2);  
                }
                else if(x1<=0 && x2<0){
                    x1=(-1*x1); //change x
                    x2=(-1*x2); 
                }   
            }
            if(y1<=0 && y2<0)  {                                             //** =0 situation haven been considered
                if(x1<=0 && x2<0){
                    y1=(-1*y1); //change y
                    y2=(-1*y2);  
                }
                else if(x1>=0 && x2>0){
                     x1=(-1*x1); //change x
                     x2=(-1*x2); 
                }
            }
        }
        if(d=1){                
            if(y1>=0 && y2>0){
                if(x1>=0 && x2>0){
                    x1=(-1*x1); //change x
                    x2=(-1*x2); 
                }
                else if(x1<=0 && x2<0){
                    y1=(-1*y1); //change y
                    y2=(-1*y2);  
                }   
            }
            if(y1<=0 && y2<0)  {                                             //** =0 situation haven been considered
                if(x1<=0 && x2<0){
                    x1=(-1*x1); //change x
                    x2=(-1*x2);  
                }
                else if(x1>=0 && x2>0){
                    y1=(-1*y1); //change y
                    y2=(-1*y2);  
                }
            }
        } 
    }
} 

