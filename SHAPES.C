// A program in C to draw some primitive shapes viz.,
 //	circle, rectangle, line, ellipse, sector and polygon

#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void main()
{
	int gd=DETECT,gm;
	int arr[]={340,150,470,180,400,240,340,150}; //coordinates for the polygon
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");   // iniatilizes the graphics driver

	circle(50,60,50);    //(x,y,radius)
	outtextxy(25,120,"Circle");
	rectangle(150,20,300,100);   //(left top, right bottom)
	outtextxy(180,120,"Rectangle");
	line(350,30,480,80);        //(x1,y1,x2,y2)
	outtextxy(400,120,"Line");
	ellipse(100,200,0,360,80,40);//(x-mid,y-mid,st_angle,end angle,x-radius,y-radius)
	outtextxy(70,260,"Ellipse");
	sector(250,200,0,240,50,50);//(x-mid,y-mid,st_angle,end angle,x-radius,y-radius)
	outtextxy(240,260,"Sector");
	drawpoly(4,arr);            //(no of points, name of array)
	outtextxy(350,260,"Polygon (Triangle)");

	getch();
	closegraph();

}