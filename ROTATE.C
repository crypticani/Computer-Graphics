// This a program to rotate a line

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415

void  rotate(int, int, int, int);

void main()
{
	int gd=DETECT,gm;
	int x1=200,y1=200,x2=400,y2=200;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	outtext("This is a program for Rotation.");
	outtextxy(50,30,"Press any key to continue");
	line(x1,y1,x2,y2); //original shape
	getch();
	clearviewport();
	closegraph();

	rotate(x1,y1,x2,y2); //calling the function for rotation

	getch();
	closegraph();
}

void rotate(int x1, int y1, int x2, int y2)
{
	int gd=DETECT,gm;
	float r,c,s,angle;
	r=PI/180; //for converting degree to radian

	printf("Enter the angle to be rotated :");
	scanf("%f",&angle);
	//printf("%f",angle);
	//getch();

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	outtext("Rotation : ");
	line(x1,y1,x2,y2);//original shape

	c=cos(angle*r); //cos(radian)
	s=sin(angle*r); //sin(radian)

	//rotating the coordinates.
	x2=(int)(x1+((x2-x1)*c-(y2-y1)*s));
	y2=(int)(y1+((x2-x1)*s+(y2-y1)*c));

	setcolor(RED);      //changing the color to red
	line(x1,y1,x2,y2);//rotated shape
}
