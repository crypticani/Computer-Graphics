// A program in C to draw a bar graph.

#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void main()
{
	int gd=DETECT,gm,x,y;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	outtextxy(150,20,"A bar graph");
	line(130,321,400,321);  //x-axis
	line(130,321,130,60);	//y-axis

	setfillstyle(SOLID_FILL,RED); //filling style and colour
	bar(150,200,180,320);
	bar(200,90,230,320);
	bar(250,120,280,320);
	bar(300,180,330,320);
	bar(350,150,380,320);
	getch();
	closegraph();

}