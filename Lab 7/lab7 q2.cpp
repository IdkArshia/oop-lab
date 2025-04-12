#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Shape{
protected:
int x,y;
string color;
float borderThickness;
public:
Shape(int xPos,int yPos,string c,float border=1.0f):x(xPos),y(yPos),color(c),borderThickness(border){}
virtual void draw()=0;
virtual float calculateArea()=0;
virtual float calculatePerimeter()=0;
void getInfo(){
cout<<"Pos:("<<x<<","<<y<<") Color:"<<color<<" Border:"<<borderThickness<<"\n";
}
};

class Circle:public Shape{
float radius;
public:
Circle(int x,int y,string c,float r,float b=1.0f):Shape(x,y,c,b),radius(r){}
void draw(){
cout<<"Circle @("<<x<<","<<y<<") radius "<<radius<<"\n";
}
float calculateArea(){
return 3.14159f*radius*radius;
}
float calculatePerimeter(){
return 2*3.14159f*radius;
}
};

class Rectangle:public Shape{
float w,h;
public:
Rectangle(int x,int y,string c,float width,float height,float b=1.0f):Shape(x,y,c,b),w(width),h(height){}
void draw(){
cout<<"Rect @("<<x<<","<<y<<") w:"<<w<<" h:"<<h<<"\n";
}
float calculateArea(){
return w*h;
}
float calculatePerimeter(){
return 2*(w+h);
}
};

class Triangle:public Shape{
float a,b,c;
public:
Triangle(int x,int y,string col,float s1,float s2,float s3,float br=1.0f):Shape(x,y,col,br),a(s1),b(s2),c(s3){}
void draw(){
cout<<"Tri @("<<x<<","<<y<<") sides "<<a<<","<<b<<","<<c<<"\n";
}
float calculateArea(){
float s=(a+b+c)/2;
return sqrt(s*(s-a)*(s-b)*(s-c));
}
float calculatePerimeter(){
return a+b+c;
}
};

int main(){
Circle c1(10,20,"Red",5.5);
Rectangle r1(0,0,"Blue",10,4);
Triangle t1(5,5,"Green",3,4,5);

c1.draw();
cout<<"Area:"<<c1.calculateArea()<<"\n";
cout<<"Perim:"<<c1.calculatePerimeter()<<"\n\n";

r1.draw();
cout<<"Area:"<<r1.calculateArea()<<"\n";
cout<<"Perim:"<<r1.calculatePerimeter()<<"\n\n";

t1.draw();
cout<<"Area:"<<t1.calculateArea()<<"\n";
cout<<"Perim:"<<t1.calculatePerimeter()<<"\n";

return 0;
}
