#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>

main()
{
	int gd=DETECT,gm,i=250,j=250,ch,x=0,y=-1;
	initgraph(&gd,&gm,"c:\\tc\\bgi");


		while(1)
		{
		 circle(i,j,10);
		 setcolor(RED);
	if(kbhit())
	{
		ch=getch();

		if(ch==72)
		{
			x=0;
			y=-1;

		}

		if(ch==75){
			x=-1;
			y=0;


		}
		if(ch==77){
			x=1;
			y=0;

		}
		if(ch==80){
		x=0;
		y=1;

		}
		if(ch==27)
		{
			exit(0);
		}
		i=i+x;
		j=j+y;
	       //	printf("%d,%d",i,j);
		delay(5);
		cleardevice();

	}    }
	getch();
     closegraph();
}