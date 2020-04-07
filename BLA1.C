#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void bla(int, int, int, int);
main()
{
	int x1,x2,y1,y2;
	clrscr();
	{
		printf("Enter the value of x1 and y1 :\n");
		scanf("%d%d",&x1,&y1);
		printf("\n\nEnter the value of x2 and y2 : \n");
		scanf("%d%d",&x2,&y2);
		bla(x1,y1,x2,y2);
	}
}

void bla(int x1, int y1, int x2, int y2)
{
	int gd=DETECT,gm;
	int dx,dy,dp;

	dy=y2-y1;   //difference in y-coordinates
	dx=x2-x1;   //difference in x-coordinates

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	//line(x1,y1,x2,y2);
	outtext("Line drawn using Bressenhem's Line Algorithm.");

	dp=2*dy-dx;   //decision parameter

	while(x1<x2)
	{
		if(dp>=0)
		{
			putpixel(x1,y1,RED);
			y1=y1+1;
			dp=dp+2*dy-2*dx;
		}
		else
		{
			putpixel(x1,y1,RED);
			dp=dp+2*dy;
		}
		x1=x1+1;
	}
	getch();
	closegraph();
}