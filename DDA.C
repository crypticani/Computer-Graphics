// A program to print a line using DDA (Digital Differential Algorithm) Algorithm.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void dda(float, float, float, float);
main()
{

	float x0,x1,y0,y1;
	clrscr();
	{
		printf("Enter the value of x1 and y1 :\n");
		scanf("%f%f",&x0,&y0);
		printf("\n\nEnter the value of x2 and y2 : \n");
		scanf("%f%f",&x1,&y1);
		dda(x0,x1,y0,y1);
	}
}
void dda(float x0,float x1,float y0,float y1)
{
	int gd=DETECT,gm;
	float dx,dy,i,xinc,yinc,step;

		dx=(x1-x0); //difference between x-coordinates
		dy=(y1-y0); //difference between y-coordinates

		//assigning the value of step
		if (abs(dx)>abs(dy))
		{
			step=abs(dx);
		}
		else
		{
			step=abs(dy);
		}
		xinc=dx/step;  //increment in x-coordinate
		yinc=dy/step;  //increment in y-coordinate

		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		outtext("Line drawn using DDA Algorithm.");

		for(i=0;i<step;i++)
		{
			putpixel(x0,y0,RED);
			x0=x0+xinc;
			y0=y0+yinc;
		}

	//line(x0,y0,x1,y1);
	getch();
	closegraph();
}