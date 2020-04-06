// A program in C to draw a pie chart.

#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	outtextxy(150,100,"A pie chart");

	setfillstyle(SOLID_FILL,RED); //filling style and colour
	pieslice(200,200,0,150,80);   //150 degree
	outtextxy(200,200-40,"41.7%");

	setfillstyle(LINE_FILL,BLUE);
	pieslice(200,200,150,270,80);  //120 degree
	outtextxy(200-60,200+20,"33.33%");

	setfillstyle(XHATCH_FILL,GREEN);
	pieslice(200,200,270,330,80);   //60 degree
	outtextxy(200+10,200+40,"16.67%");

	setfillstyle(WIDE_DOT_FILL,YELLOW);
	pieslice(200,200,330,360,80);    //30 degree
	outtextxy(200+35,200+10,"8.33%");

	getch();
	closegraph();

}