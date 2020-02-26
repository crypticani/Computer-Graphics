#include<graphics.h>
#include<math.h>

#define PI 3.1415

main()
{
	int gd=DETECT,gm;
	int x=50,y=50,r=20;
	float d,i;
	d=PI/180;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	setcolor(GREEN);
	circle(50,50,20);
	for(i=0;i<360;i++)
	{
		putpixel(x+r*cos(i*d),y+r*sin(i*d),RED);
	}
	getch();
	closegraph();

}
