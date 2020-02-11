// A program in C to print a line using putpixel() function.

#include<graphics.h>
#include<stdio.h>
#include<conio.h>

int main()
	{
		int gd=DETECT, gm;
		float x,y,x1,y1,x2,y2,m,c,i;

		printf("X1:");
		scanf("%f",&x1);
		printf("Y1:");
		scanf("%f",&y1);
		printf("X2:");
		scanf("%f",&x2);
		printf("Y2:");
		scanf("%f",&y2);

		m=(y2-y1)/(x2-x1);
		c=y1-(m*x1);


		initgraph(&gd,&gm,"c:\\tc\\bgi");

		line(x1,y1,x2,y2);

		if(x2<x1)
		{
		    x=x1;
		    x1=x2;
		    x2=x;
		    y=y1;
		    y1=y2;
		    y2=y;

		for(i=x1;i<=x2;i++)
		{
			putpixel(i,(i*m)+c,RED);
		}
		}


		else
		{

		for(i=x1;i<=x2;i++)
		{
			putpixel(i,(i*m)+c,RED);
		}
		}
		outtextxy(0,420,"Coordinates of the line are : (x1,y1),(x2,y2)");
		outtextxy(0,430,"Slope of the line is m.");


		getch();
		closegraph();

	}
