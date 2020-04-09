// This a program to translate an object

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void  x_translate(int, int, int, int, int);
void  y_translate(int, int, int, int, int);
void  translate(int, int, int, int, int);

void main()
{
	int gd=DETECT,gm;
	int x1=50,y1=50,x2=150,y2=100,T,choice;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	outtext("This is a program for translation.");
	outtextxy(50,30,"Press any key to continue");
	rectangle(x1,y1,x2,y2); //original shape
	getch();
	closegraph();

	printf("Enter Your Choice :");
	printf("\n1. Translate Horizontally");
	printf("\n2. Translate Vertically");
	printf("\n3. Translate Diagonally]\n\n");
	scanf("%d",&choice);
	printf("\n\nEnter the translation factor :  ");
	scanf("%d",&T);

	switch(choice) //calling the functions according to the choice
	{
		case 1: x_translate(x1,y1,x2,y2,T);
		break;
		case 2: y_translate(x1,y1,x2,y2,T);
		break;
		case 3: translate(x1,y1,x2,y2,T);
		break;
		default: printf("\nInvalid Choice!");
	}
	getch();
	closegraph();
}

void x_translate(int x1, int y1, int x2, int y2, int T)
{
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	rectangle(x1,y1,x2,y2);//original shape
	x1=x1+T;             //horizontal translation
	x2=x2+T;
	setcolor(RED);      //changing the color to red
	rectangle(x1,y1,x2,y2);//translated shape
}

void y_translate(int x1, int y1, int x2, int y2, int T)
{
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	rectangle(x1,y1,x2,y2); //original shape
	y1=y1+T;          //vertical translation
	y2=y2+T;
	setcolor(RED);   //changing the colour to red
	rectangle(x1,y1,x2,y2); //translated shape
}

void translate(int x1, int y1, int x2, int y2, int T)
{
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	rectangle(x1,y1,x2,y2); //original shape
	x1=x1+T;            //horizontal
	x2=x2+T;            //translation
	y1=y1+T;            //vertical
	y2=y2+T;            //translation
	setcolor(RED);      //changing the colour to red
	rectangle(x1,y1,x2,y2);//translated shape
}
