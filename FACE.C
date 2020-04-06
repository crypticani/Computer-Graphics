// A program in C to draw a face using primitive shapes.

#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void main()
{
	int gd=DETECT,gm,x,y;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	outtextxy(90,100,"A face using primitive shapes");
	setcolor(YELLOW);
	circle(200,200,80);   //face
	ellipse(170,180,0,360,12,8);    //left eye
	ellipse(230,180,0,360,12,8);    //right eye
	line(200-5,195,200-10,230);     //nose
	ellipse(198,230,0,360,8,3);
	arc(200,215,220,320,40);        //mouth
	arc(200,265,40,135,20);         //toungue
	getch();
	closegraph();

}