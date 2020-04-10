// A program to demonstrate midpoint circle algorithm

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void midpoint_circle(int, int, int);
void main()
{
	int gd=DETECT, gm;
	int x,y,r;
	
	//getting the coordinates and radius as input
	printf("This a program to demonstrate Midpoint Circle Algorithm");
	printf("\nEnter the coordinates of the center (X and Y):\n");
	scanf("%d%d",&x,&y);
	printf("\nEnter the radius of circle: ");
	scanf("%d",&r);
	
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	midpoint_circle(x,y,r); //calling the required function
	
	getch();
	closegraph();
}

void midpoint_circle(int x, int y, int r)
{
	int s=0,dp=0; //decision parameters
	
	while(r>=s)
	{
		// 8 midpoints of the circle, calling recursively
		putpixel(x+r,y+s,RED);
		putpixel(x+s,y+r,RED);
		putpixel(x-s,y+r,RED);
		putpixel(x-r,y+s,RED);
		putpixel(x-r,y-s,RED);
		putpixel(x-s,y-r,RED);
		putpixel(x+s,y-r,RED);
		putpixel(x+r,y-s,RED);
		
		//conditions for decision parameters
		if(dp<=0)
		{
			s=s+1; //increasing the value after 1 iteration
			dp=dp+2*s+1;
		}
		else
		{
			r=r-1; //increasing the value after 1 iteration
			dp=dp-2*r+1;
		}
	}
}