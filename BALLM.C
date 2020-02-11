#include<graphics.h>
#include<process.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

main()
{
	int gd=DETECT,gm,i,j,ch,x=0,y=-1;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");


	for(i=0;i<640;i+=10)
	{
	     for(j=0;j<480;j+=10)
	     {

		while(1)
		{
		line(320,0,320,480);
		setcolor(GREEN);
		circle(10+i,395+j,5);
		circle(30+i,395+j,5);
		rectangle(0+i,370+j,40+i,395+j);
		rectangle(5+i,375+j,10+i,380+j);
		rectangle(15+i,375+j,20+i,380+j);
		rectangle(25+i,375+j,30+i,380+j);
		rectangle(33+i,375+j,37+i,387+j);
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
		delay(10);

		cleardevice();
		if(i==640){
			     i=0;


		}
		if(i==0){
			i=640;
		}
	      /*	if(j==0){
			j=400;

		}
		if(j==400){
			j=0;
		}*/
	}
	}     }
		rectangle(50,350,70,400);
		rectangle(55,370,60,390);
		rectangle(120,340,140,400);
		rectangle(125,360,130,390);


	}

	getch();

	closegraph();
}