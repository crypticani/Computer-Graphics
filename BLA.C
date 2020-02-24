#include<stdio.h>
#include<conio.h>
#include<graphics.h>

main()
{
	int gd=DETECT,gm;
	float x,y,x1=10,x2=100,y1=20,y2=50,m,dx,dy,yk,yl,dp,d1,d2;

	dy=y2-y1;
	dx=x2-x1;
	m=dy/dx;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	for(y1;y1<y2;y1++)
	{
	for(x1;x1<x2;x1++)
	{
		yk=y1;
		yl=y1+1;

		putpixel(x1,y1,RED);
		x=x1+1;

		d1=y-yk;
		d2=yl-y;

		dp=d1-d2;

		if(dp<0)
		{
			x=x+1;
			y=yk;
			putpixel(x,y,RED);

		}
		if(dp>0)
		{
			x=x+1;
			y=yk+1;
			putpixel(x,y,RED);

		}
	 }
	 }
	 getch();
	 closegraph();
}
