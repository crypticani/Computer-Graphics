// A program to demonstrate flood fill.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void flood_fill(int, int, int, int);

void main()
{
	int gd=DETECT,gm;
	int x1=50,y1=50,x2=120,y2=100; //coordinates of the rectangle
	int x0=x1+20,y0=y1+20;    //coordinate, from where to start
	int bk_col=0, fill_col=1; //old colour and colour to be filled

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	outtext("This is Flood Fill.");
	rectangle(x1,y1,x2,y2);
	flood_fill(x0,y0,bk_col,fill_col); //calling the recursive function

	getch();
	closegraph();
}

void flood_fill(int x, int y, int bk_col, int fill_col)
{
	if(getpixel(x,y)==bk_col)//checks for the old/background colour
	{
		delay(2);
		putpixel(x,y,fill_col);//the starting pixel
		flood_fill(x+1,y,bk_col,fill_col);//right pixel
		flood_fill(x-1,y,bk_col,fill_col);//left pixel
		flood_fill(x,y+1,bk_col,fill_col);//bottom pixel
		flood_fill(x,y-1,bk_col,fill_col);//upward pixel
		flood_fill(x+1,y+1,bk_col,fill_col);//bottom right pixel
		flood_fill(x-1,y+1,bk_col,fill_col);//bottom left pixel
		flood_fill(x+1,y-1,bk_col,fill_col);//top right pixel
		flood_fill(x-1,y-1,bk_col,fill_col);//top left pixel
	}
}






















