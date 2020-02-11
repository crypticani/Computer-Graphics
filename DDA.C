// A program to print a line using DDA ( Digital Differential Algorithm) Algorithm.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void dda(int, int, int, int);
main()
{

	float x0=10,x1=10,y0=20,y1=50;

	dda(x0,x1,y0,y1);

}
void dda(x0,x1,y0,y1){
	int gd=DETECT,gm;
	float dx,dy,i,xinc,yinc,step;

		dx=(x1-x0);

		dy=(y1-y0);

		if (abs(dx)>abs(dy)){
			step=abs(dx);
		}
		else{
			step=abs(dy);
		}
		xinc=dx/step;
		yinc=dy/step;

		initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	for(i=0;i<step;i++){
		putpixel(x0,y0,RED);
		x0=x0+xinc;
		y0=y0+yinc;
	}


	line(100,20,10,50);
	getch();
	closegraph();
}
