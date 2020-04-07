// A program to draw a character (A), using Bitmap method.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{

	int gd=DETECT,gm,i,j,c=2;  //c is for colour
	int a[14][9]={{0,0,0,0,1,0,0,0,0},
				{0,0,0,1,1,1,0,0,0},
				{0,0,1,1,0,1,1,0,0},
				{0,1,1,0,0,0,1,1,0},
				{1,1,0,0,0,0,0,1,1},
				{1,1,0,0,0,0,0,1,1},
				{1,1,0,0,0,0,0,1,1},
				{1,1,1,1,1,1,1,1,1},
				{1,1,0,0,0,0,0,1,1},
				{1,1,0,0,0,0,0,1,1},
				{1,1,0,0,0,0,0,1,1},
				{1,1,0,0,0,0,0,1,1},
				{1,1,0,0,0,0,0,1,1},
				{1,1,0,0,0,0,0,1,1},
			};

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	outtext("Bitmap method");
	for(i=0;i<14;i++) 
	{
		for(j=0;j<9;j++)
		{
			putpixel(50+j,20+i,c*a[i][j]);
		}
	}
getch();
closegraph();
}