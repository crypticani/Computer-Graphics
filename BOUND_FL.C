// A program to demonstrate boundary fill.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void boundary_fill(int, int, int, int);

void main()
{
	int gd=DETECT,gm;
	int x1=50,y1=50,x2=120,y2=120; //coordinates of the rectangle
	int x0=x1+20,y0=y1+20;    //coordinate, from where to start
	int bound_col=15, fill_col=5; //old colour and colour to be filled

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	outtext("This is Boundary fill.");
	rectangle(x1,y1,x2,y2);
	boundary_fill(x0,y0,bound_col,fill_col); //calling the recursive function

	getch();
	closegraph();
}

void boundary_fill(int x, int y, int bound_col, int fill_col)
{
	if(getpixel(x,y)!=bound_col && getpixel(x,y)!=fill_col)
	{
		delay(2);
		putpixel(x,y,fill_col);//starting pixel
		boundary_fill(x+1,y,bound_col,fill_col);//right pixel
		boundary_fill(x-1,y,bound_col,fill_col);//left pixel
		boundary_fill(x,y+1,bound_col,fill_col);//bottom pixel
		boundary_fill(x,y-1,bound_col,fill_col);//upward pixel
		boundary_fill(x+1,y+1,bound_col,fill_col);//bottom right pixel
		boundary_fill(x-1,y+1,bound_col,fill_col);//bottom left pixel
		boundary_fill(x+1,y-1,bound_col,fill_col);//top right pixel
		boundary_fill(x-1,y-1,bound_col,fill_col);//top left pixel
	}
}
