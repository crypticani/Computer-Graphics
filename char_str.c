// A program to draw a character (A), using Stroke method.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	outtext("Stroke method");
	setcolor(RED);
	line(100,50,50,150);
	line(100,50,150,150);
	line(75,100,125,100);
getch();
closegraph();
}