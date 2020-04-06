// A program in C to draw a grid.

#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void main()
{
	int gd=DETECT,gm,i,j;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	for(i=0;i<=200;i+=10)
	{
		line(20+i,50,20+i,250); //vertical lines
	}
	for(j=0;j<=200;j+=10)
	{
		line(20,50+j,220,50+j); //horizontal lines
	}
	getch();
	closegraph();

}