// A program to draw concentric shapes.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void mycircle();
void myrectangle();
void mytriangle();
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	outtext("This is a program to draw shapes within shapes");
	//calling the 3 shapes
	mycircle();
	myrectangle();
	mytriangle();

	getch();
	closegraph();
}

void mycircle()
{
	int i,x=80,y=100,r=10;
	setcolor(RED);  //sets the outline colour RED
	for(i=0;i<=60;i+=10) //each circle having a difference of radius 10p
	{
		circle(x,y,r+i);
	}
}

void myrectangle()
{
	int i,x1=50,y1=200,x2=280,y2=330;
	setcolor(GREEN); //sets the outline colour GREEN
	for(i=0;i<=60;i+=10)//each rectangle having a difference of length 10p
	{
		rectangle(x1+i,y1+i,x2-i,y2-i);
	}
}

void mytriangle()
{
	int i,x1=230,y1=30,x2=310,y2=170,x3=150,y3=170;
	setcolor(BLUE);  //sets the outline colour GREEN
	for(i=0;i<=60;i+=10) //each rectangle having a difference of length 10p
	{
		line(x1,y1+i,x2-i,y2-i); //right arm of the triangle
		line(x2-i,y2-i,x3+i,y3-i);//base of the triangle
		line(x3+i,y3-i,x1,y1+i); //left arm of the triangle
	}
}
