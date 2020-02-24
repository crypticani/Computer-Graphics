// A program in C to display the resolution of the Screen.

#include<graphics.h>
#include<stdio.h>
#include<conio.h>

main()
{
	int gd=DETECT,gm,x,y;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	x=getmaxx();
	y=getmaxy();
	gotoxy(20,getmaxy()/2);
	printf("Resolution of the screen is :  %d * %d Pixels",x,y);
	getch();
	closegraph();

}
