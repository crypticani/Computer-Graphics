/* First Complete version of the game "Drag 'n' Drive (A car racing game)
	version 1.14*/

/* Copyright 2020 Rupali Singh and Aniket Kumar

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at : 
   http://www.apache.org/licenses/LICENSE-2.0 
   
   Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.  */


#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>    // for rand() function.
#include<stdlib.h>  // for rand() function.
#include<dos.h>      // for delay() and exit() function.
#define N 10   // Number of high scores
#define FNAME "myscore.txt"  // creates a file named myscore.txt in bin folder.

int a=0; // for score
char scr[50];  // for printing score using sprintf.
int cars=0;  // for car selection
int life=3;  //provides 3 chances to players.
int D=50;  //delay
int score[N];
int count=0;
FILE *fp;   // file pointer
int myscore;

void loading();
void car(int);
void track(int);
void play();
void menu();
void high_score();
void instructions();
void about();
void text();
void text1();
void heart1();
void heart2();
void heart3();
void speed();
void info();
void h1();
void h2();
void select_car();
void car_choice();
void car1();
void car2();
void car3();
void car4();
void mycar1(int);
void mycar2(int);
void mycar3(int);
void mycar4(int);

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	loading();  //loading screen
	menu();
	return 0;
}

void play()
{
	int i,j,k,l,r,s,ch;
	cleardevice();
	setbkcolor(8);

		r=210+rand()%150; // generates a random number between 210 and 210+150
		s=210+rand()%150;

	for(k=0;k<433;k+=1)
	{
	for(l=-200;l<433;l+=1)
	{
		for(i=205;i<345;i++)
		{
		for(j=0;j<500;j++)
		{
			track(k);
			speed();
			info();
			switch(life)   //to show the hearts corressponding to remaining life.
			{
				case 1: heart1();
				break;
				case 2: heart2();
				break;
				case 3: heart3();
				break;
			}
			switch(cars)
			{
				case 1 : mycar1(i);
				break;
				case 2 : mycar2(i);
				break;
				case 3 : mycar3(i);
				break;
				case 4 : mycar4(i);
				break;
				default : outtextxy(200,200,"No car selected.");
			}

		rectangle(r,k,r+50,50+k);
		rectangle(s,l,s+50,50+l);

			if(i+50>=r&&i<=(r+40)&&k>=265&&k<=415)
			{
				cleardevice();
				if(life!=1)
				{
				settextstyle(1,0,3);
				outtextxy(200,getmaxy()/2,"One Chance Lost!");
				circle(420,250,15);
				circle(426,246,1);
				circle(414,246,1);
				arc(420,259,10,160,5);
				life=life-1;   //Reduces life.
				outtextxy(200,180,"Current Score :");
				outtextxy(380,180,scr);
				outtextxy(190,300,"Press Enter to Continue!");
				kbhit();
				  while(getch()!=13)  //to hold the screen till enter is pressed
				  {
					getch();
				  }
				play();
				}
				else if(life==1)
				{
					settextstyle(1,0,6);
					outtextxy(160,160,"GAME OVER");
					settextstyle(1,0,3);
					outtextxy(180,getmaxy()/2,"Your Score: ");
					outtextxy(340,getmaxy()/2,scr);
					score[count]=a;
					count=count+1;
					fp=fopen(FNAME,"wb");
					if(a>myscore)
					{
						myscore=a;
						putw(myscore,fp);
					}
					else
					{
						myscore=myscore;
						putw(myscore,fp);
					}
					fclose(fp);
					a=0;     //resets score to 0.
					life=3;
					D=50;   //delay resets to 50
					outtextxy(120,360,"Press Enter to return to the main Menu.");
					kbhit();
					while(getch()!=13)  //to hold the screen till enter is pressed
					{
						getch();
					}
				menu();
				}
			}
			if(i+50>=s&&i<=(s+40)&&l>=265&&l<=415)
			{
				cleardevice();
				if(life!=1)
				{
				settextstyle(1,0,3);
				outtextxy(200,getmaxy()/2,"One Chance Lost!");
				circle(420,250,15);
				circle(426,246,1);
				circle(414,246,1);
				arc(420,259,10,160,5);

				life=life-1;   //Reduces life.
				outtextxy(200,150,"Current Score: ");
				outtextxy(380,150,scr);
				outtextxy(200,350,"Press Enter to Continue!");
				kbhit();
				  while(getch()!=13)  //to hold the screen till enter is pressed
				  {
					getch();
				  }
				play();
				}
				else if(life==1)
				{
					settextstyle(1,0,6);
					outtextxy(160,160,"GAME OVER");
					settextstyle(1,0,3);
					outtextxy(220,230,"Your Score :");
					outtextxy(300,150,scr);
					score[count]=a;
					count=count+1;
					fp=fopen(FNAME,"wb");
					if(a>myscore)
					{
						myscore=a;
						putw(myscore,fp);
					}
					else
					{
						myscore=myscore;
						putw(myscore,fp);
					}
					fclose(fp);
					a=0;     //resets score to 0.
					life=3;  //resets life to 3.
					D=50;   //delay resets to 50.
					outtextxy(120,360,"Press Enter to return to the main Menu.");
					kbhit();
					while(getch()!=13)  //to hold the screen till enter is pressed
					{
						getch();
					}
				menu();
				}
			}

			if(k==430)
			{
				k=0;
				a=a+10;
				if(a>=50&&a<100)
				{
					D=45;
				}
				else if (a>=100&&a<200)
				{
					D=40;
				}
				else if(a>=200&&a<300)
				{
					D=35;
				}
				else if(a>=300&&a<400)
				{
					D=30;
				}
				else if(a>=400&&a<600)
				{
					D=25;
				}
				else if(a>=600)
				{
					D=20;
				}
				r=210+rand()%150;   // generates a random number between 210 and 210+150
			}
			else if(l==430)
			{
				l=0;
				a=a+10;
				if(a>=50&&a<100)
				{
					D=45;
				}
				else if (a>=100&&a<200)
				{
					D=40;
				}
				else if(a>=200&&a<300)
				{
					D=35;
				}
				else if(a>=300&&a<400)
				{
					D=30;
				}
				else if(a>=400&&a<600)
				{
					D=25;
				}
				else if(a>=600)
				{
					D=20;
				}
				s=210+rand()%150;
			}
			else
			{
				k+=10;
				l+=10;
			}

			if(kbhit())
			{
				ch=getch();
				sound(400);
				delay(10);
				if(ch==32) //space button
				{
					nosound();
					settextstyle(1,0,3);
					outtextxy(250,200,"GAME PAUSED");
					outtextxy(250,150,"Current Score :");
					outtextxy(450,150,scr);
					outtextxy(200,250,"Press Space bar to Resume");
					while(getch()!=32) //to hold the screen till Space is pressed
					{
						getch();
					}
				}
				if(ch==75&&i>214)  //move left
				{
					if(i==230)
					{
						i=250;
					}
					i-=20;
				}

				if(ch==77&&i<331) //move right
				{
					if(i==330) //max value of x coordinate of car
					{
						i=310; // to remain on the track
					}
					i+=20;
				}

				if(ch==27) //escape key is pressed
				{
					nosound();
					menu();
				}
				nosound();
			}
			delay(D);
			cleardevice();
		}
		}
	}
	}
	getch();
}

void select_car()
{
	int x1=95,y1=50,x2=195,y2=391,z=120,c=0;
	cleardevice();
	setbkcolor(0);
	while(1)
	{
	car_choice();
	car1();
	car2();
	car3();
	car4();
	rectangle(x1,y1,x2,y2);  //cursor

		if(kbhit())
		{
			c=getch();
			if(c==27)      //esc is pressed
			{
				menu();
			}
			else if(c==75&&x1==95) //left arrow key and cursor at the left most box
			{
				cleardevice();
				car_choice();
				car1();
				car2();
				car3();
				car4();
				x1=455;
				x2=555;
			       //	setcolor(RED);
				rectangle(x1,y1,x2,y2);
			}
			else if(c==75) //left arrow key
			{
				cleardevice();
				car_choice();
				car1();
				car2();
				car3();
				car4();
				x1=x1-z;
				x2=x2-z;
			       //	setcolor(RED);
				rectangle(x1,y1,x2,y2);
			}
			else if(c==77&&x1==455) //right arrow key and the cursor at the rightmost box
			{
				cleardevice();
				car_choice();
				car1();
				car2();
				car3();
				car4();
				x1=95;
				x2=195;
				//setcolor(RED);
				rectangle(x1,y1,x2,y2);
			}
			else if(c==77)   //right arrow key
			{
				cleardevice();
				car_choice();
				car1();
				car2();
				car3();
				car4();
				x1=x1+z;
				x2=x2+z;
				//setcolor(RED);
				rectangle(x1,y1,x2,y2);
			}

			else if(c==13)   // if Enter key is pressed.
			{
				if(x1==95)   //position of the cursor
				{
					cars=3;
					play();  //car to be selected
				}
				else if(x1==215)
				{
					cars=1;
					play();
				}
				else if(x1==335)
				{
					cars=2;
					play();
				}
				else if(x1==455)
				{
					cars=4;
					play();
				}
			}
		}
	}
}

void car_choice()
{
	int i=120;
	bar3d(325-i-i,45,325+i+i,45,2,1);
	bar3d(325-i-i,396,325+i+i,396,2,1);

	bar3d(325,45,327,396,2,1);
	bar3d(325-i,45,327-i,396,2,1);
	bar3d(325-i-i,45,327-i-i,396,2,1);
	bar3d(325+i,45,327+i,396,2,1);
	bar3d(325+i+i,45,327+i+i,396,2,1);

	settextstyle(7,0,5);//font_direction_fontsize
	outtextxy(265-i,80,"1");
	outtextxy(265,80,"2");
	outtextxy(265+i,80,"3");
	outtextxy(265+i+i,80,"4");

	setcolor(GREEN);
	settextstyle(7,0,4);
	outtextxy(200,410,"Select your car");
	settextstyle(1,0,2);
	outtextxy(180,450,"Use arrow keys to navigate.");
}

void car1()
{
	setcolor(RED);
	rectangle(250,250,280,290); //roof
	rectangle(245,290,285,300);
	setcolor(GREEN);
	rectangle(235,230,295,320);      //main outline of car
	arc(265,250,10,170,35);     //side mirror's
	arc(265,190,10,170,15);     //front light

	line(235,230,250,250); //top_right_corner
	line(295,230,280,250); //top_left_corner
	line(245,300,235,320); //bottom_left_corner
	line(285,300,295,320); //bottom_right_corner

	setcolor(GREEN);
	ellipse(265,320,180,360,30,20);//trunk lid
	ellipse(265,230,0,180,30,55);//bonet
}

void mycar1(int i)
{
	setcolor(RED);
	rectangle(20+i,350,40+i,380); //roof
	rectangle(15+i,380,45+i,385);
	setcolor(GREEN);
	rectangle(10+i,340,50+i,395);      //main outline of car
	arc(30+i,355,10,170,24);     //side mirror's
	arc(30+i,320,10,170,10);     //front light

	line(50+i,340,40+i,350); //top_right_corner
	line(10+i,340,20+i,350); //top_left_corner
	line(15+i,385,10+i,395); //bottom_left_corner
	line(45+i,385,50+i,395); //bottom_right_corner

	setcolor(GREEN);
	ellipse(30+i,395,180,360,20,10);//trunk lid
	ellipse(30+i,340,0,180,20,30);//bonet
}

void car2()
{
	int i=120;
	setcolor(BLUE);
	rectangle(250+i,250,280+i,290); //roof
	rectangle(245+i,290,285+i,300);
	setcolor(YELLOW);
	rectangle(235+i,230,295+i,320);      //main outline of car
	arc(265+i,250,10,170,35);     //side mirror's
	arc(265+i,190,10,170,15);     //front light

	line(235+i,230,250+i,250); //top_right_corner
	line(295+i,230,280+i,250); //top_left_corner
	line(245+i,300,235+i,320); //bottom_left_corner
	line(285+i,300,295+i,320); //bottom_right_corner

	setcolor(YELLOW);
	ellipse(265+i,320,180,360,30,20);//trunk lid
	ellipse(265+i,230,0,180,30,55);//bonet
}

void mycar2(int i)
{
	setcolor(BLUE);
	rectangle(20+i,350,40+i,380); //roof
	rectangle(15+i,380,45+i,385);
	setcolor(YELLOW);
	rectangle(10+i,340,50+i,395);      //main outline of car
	arc(30+i,355,10,170,24);     //side mirror's
	arc(30+i,320,10,170,10);     //front light

	line(50+i,340,40+i,350); //top_right_corner
	line(10+i,340,20+i,350); //top_left_corner
	line(15+i,385,10+i,395); //bottom_left_corner
	line(45+i,385,50+i,395); //bottom_right_corner

	setcolor(YELLOW);
	ellipse(30+i,395,180,360,20,10);//trunk lid
	ellipse(30+i,340,0,180,20,30);//bonet
}

void car3()
{
	int i=120;
	setcolor(RED);
	rectangle(250-i,250,280-i,290); //roof
	setcolor(RED);
	rectangle(235-i,230,295-i,320);      //main outline of car
	arc(265-i,250,10,170,35);     //side mirror's
	arc(265-i,190,10,170,15);     //front light

	line(235-i,230,250-i,250); //top_right_corner
	line(295-i,230,280-i,250); //top_left_corner
	line(250-i,290,235-i,320); //bottom_left_corner
	line(280-i,290,295-i,320); //bottom_right_corner

	setcolor(RED);
	ellipse(265-i,320,180,360,30,20);//trunk lid
	ellipse(265-i,230,0,180,30,55);//bonet
}
void mycar3(int i)
{
	setcolor(RED);
	rectangle(20+i,350,40+i,380); //roof
	setcolor(RED);
	rectangle(10+i,340,50+i,395);      //main outline of car
	arc(30+i,355,10,170,24);     //side mirror's
	arc(30+i,320,10,170,10);     //front light

	line(50+i,340,40+i,350); //top_right_corner
	line(10+i,340,20+i,350); //top_left_corner
	line(20+i,380,10+i,395); //bottom_left_corner
	line(40+i,380,50+i,395); //bottom_right_corner

	setcolor(RED);
	ellipse(30+i,395,180,360,20,10);//trunk lid
	ellipse(30+i,340,0,180,20,30);//bonnet
}

void car4()
{
	int i=120;
	setcolor(GREEN);
	rectangle(250+i+i,250,280+i+i,290); //roof
	rectangle(245+i+i,290,285+i+i,300);
	setcolor(WHITE);
	rectangle(235+i+i,230,295+i+i,320);      //main outline of car
	arc(265+i+i,250,10,170,35);     //side mirror's
	arc(265+i+i,190,10,170,15);     //front light

	line(235+i+i,230,250+i+i,250); //top_right_corner
	line(295+i+i,230,280+i+i,250); //top_left_corner
	line(245+i+i,300,235+i+i,320); //bottom_left_corner
	line(285+i+i,300,295+i+i,320); //bottom_right_corner

	setcolor(WHITE);
	ellipse(265+i+i,320,180,360,30,20);//trunk lid
	ellipse(265+i+i,230,0,180,30,55);//bonnet
}
void mycar4(int i)
{
	setcolor(GREEN);
	rectangle(20+i,350,40+i,380); //roof
	rectangle(15+i,380,45+i,385);
	setcolor(WHITE);
	rectangle(10+i,340,50+i,395);      //main outline of car
	arc(30+i,355,10,170,24);     //side mirror's
	arc(30+i,320,10,170,10);     //front light

	line(50+i,340,40+i,350); //top_right_corner
	line(10+i,340,20+i,350); //top_left_corner
	line(15+i,385,10+i,395); //bottom_left_corner
	line(45+i,385,50+i,395); //bottom_right_corner

	setcolor(WHITE);
	ellipse(30+i,395,180,360,20,10);//trunk lid
	ellipse(30+i,340,0,180,20,30);//bonnet
}

void track(int k)
{
		setcolor(WHITE);
		bar3d(120,0,125,478,5,3);//left boundary
		bar3d(480,0,485,478,5,3);//right boundary
		line(280,0,280,getmaxy());  //lanes
		line(340,0,340,getmaxy());

			// for moving tracks
			setcolor(WHITE);
			bar3d(200,-420+k,205,-380+k,5,3);
			bar3d(410,-420+k,405,-380+k,5,3);
			bar3d(200,-360+k,205,-320+k,5,3);
			bar3d(410,-360+k,405,-320+k,5,3);
			bar3d(200,-300+k,205,-260+k,5,3);
			bar3d(410,-300+k,405,-260+k,5,3);
			bar3d(200,-240+k,205,-200+k,5,3);
			bar3d(410,-240+k,405,-200+k,5,3);
			bar3d(200,-180+k,205,-140+k,5,3);
			bar3d(410,-180+k,405,-140+k,5,3);
			bar3d(200,-120+k,205,-80+k,5,3);
			bar3d(410,-120+k,405,-80+k,5,3);
			bar3d(200,-60+k,205,-20+k,5,3);
			bar3d(410,-60+k,405,-20+k,5,3);
			bar3d(200,0+k,205,40+k,5,3);
			bar3d(410,0+k,405,40+k,5,3);
			bar3d(200,60+k,205,100+k,5,3);
			bar3d(410,60+k,405,100+k,5,3);
			bar3d(200,120+k,205,160+k,5,3);
			bar3d(410,120+k,405,160+k,5,3);
			bar3d(200,180+k,205,220+k,5,3);
			bar3d(410,180+k,405,220+k,5,3);
			bar3d(200,240+k,205,280+k,5,3);
			bar3d(410,240+k,405,280+k,5,3);
			bar3d(200,300+k,205,340+k,5,3);
			bar3d(410,300+k,405,340+k,5,3);
			bar3d(200,360+k,205,400+k,5,3);
			bar3d(410,360+k,405,400+k,5,3);
			bar3d(200,420+k,205,460+k,5,3);
			bar3d(410,420+k,405,460+k,5,3);
}

void loading() //loading screen
{
	int i,j;
	for(j=0;j<20;j++) // For Blinking of text
	{
		settextstyle(4,0,8);
		setcolor(j);
		outtextxy(70,100,"Drag 'N' Drive");
		delay(100);
	}
	settextstyle(6,0,2);
	outtextxy((getmaxx()/2)-30,getmaxy()-130,"LOADING");
	for(i=0;i<400;i+=2) //loading animation
	{
		setcolor(RED);
		rectangle((getmaxx()/2)-200+i,getmaxy()-100,(getmaxx()/2)+200,getmaxy()-80);
		delay(10);
	}
}
void menu()
{
	int i,k,x1=210,y1=200,x2=440,y2=247;
	cleardevice();
	setbkcolor(1);
	while(1)
	{
		h1();
		h2();
		setcolor(RED);
		rectangle(x1,y1,x2,y2);   //cursor

	if(kbhit()) // detects the pressing of key
	{
	   k=getch();
		if(k==72&&y1==200) //cursor at the top
		{
			y1=200+160;     //sends the cursor to bottom
			y2=247+160;
			cleardevice();
			h1();
			h2();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80&&y2==407) //cursor at the bottom and moves to the top
		{
			x1=210; //resets the cursor position to top
			y1=200;
			x2=440;
			y2=247;
			cleardevice();
			h1();
			h2();
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}
		else if(k==80) //cursor moves downward
		{
			cleardevice();
			h1();
			h2();
			y1=y1+40;
			y2=y2+40;
			rectangle(x1,y1,x2,y2);
		}
		else if(k==72) //cursor moves upward
		{
			cleardevice();
			h1();
			h2();
			y1=y1-40;
			y2=y2-40;
			setcolor(RED);
			rectangle(x1,y1,x2,y2);
		}

		else if(k==13) //Enter key is pressed
		{
			if(y1==200)  // cursor on the first option
			{
				cleardevice();
				select_car(); // opens the game
			}
			else if(y1==240)   //High Score
			{
				cleardevice();
				high_score();
			}
			else if(y1==280)
			{
				cleardevice();
				instructions(); //Instructions
			}
			else if(y1==320)
			{
				cleardevice();
				about(); //About
			}
			else if(y1==360)
			{
				exit(0);
				closegraph();
			}
		}
	}
	}
}

void high_score()
{
	int p,q,tmp,score1,score2,score3,score4,score5;
	char as[100],ss[100]; //for sprintf
	setbkcolor(0);     //Black
	fp=fopen(FNAME, "rb");
		for (p=0;p<N;p++)
		{
			for(q=p+1;q<N;q++)
			{
				if (score[p]<score[q])
				{
					tmp = score[p];
					score[p] = score[q];
					score[q] = tmp;
				}
			}
		}
		myscore=getw(fp);
		score1=score[0];
		score2=score[1];
		score3=score[2];
		score4=score[3];
		score5=score[4];

		sprintf(as," %d ",myscore);
		fclose(fp);
		sprintf(ss,"1. %d  |  2. %d  |  3. %d  |  4. %d  |  5. %d ",score1,score2,score3,score4,score5); // stores high score in buffer

	settextstyle(4,0,7);
	setcolor(GREEN);
	outtextxy(150,20,"High Scores");
	bar3d(50,120,550,125,3,1);
	settextstyle(8,0,3);
	setcolor(BLUE);
	outtextxy(60,150," All time High Score :");
	settextstyle(8,0,2);
	setcolor(WHITE);
	outtextxy(80,180,as); // displays the high score
	settextstyle(8,0,3);
	setcolor(BLUE);
	outtextxy(60,260,"Current High Scores :");
	settextstyle(8,0,2);
	setcolor(WHITE);
	outtextxy(60,300,ss);
	setcolor(RED);
	bar3d(50,420,550,415,3,1);
	settextstyle(1,0,1);
	outtextxy(100,455,"Press Esc to return to the Main Menu");

	kbhit();
	while(getch()!=27)     //Esc key
	{
		getch();
	}
	cleardevice();
	menu();
}

void heart1()
{
	int h1[]={517,75,506,60,510,50,515,51,517,60,520,51,525,50,529,60,517,75};
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(9,h1);
}
void heart2()
{
	int h1[]={517,75,506,60,510,50,515,51,517,60,520,51,525,50,529,60,517,75};
	int h2[]={557,75,546,60,550,50,555,51,557,60,560,51,565,50,569,60,557,75};
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(9,h1);
	fillpoly(9,h2);
}
void heart3()
{
	int h1[]={517,75,506,60,510,50,515,51,517,60,520,51,525,50,529,60,517,75};
	int h2[]={557,75,546,60,550,50,555,51,557,60,560,51,565,50,569,60,557,75};
	int h3[]={597,75,586,60,590,50,595,51,597,60,600,51,605,50,609,60,597,75};
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(9,h1);
	fillpoly(9,h2);
	fillpoly(9,h3);
}
void speed()
{
			if(D==50)
			{
				settextstyle(8,0,2);
				outtextxy(500,320,"Speed:");
				settextstyle(7,0,2);
				outtextxy(500,350,"100 mph");
			}
			else if(D==45)
			{
				settextstyle(8,0,2);
				outtextxy(500,320,"Speed:");
				settextstyle(7,0,2);
				outtextxy(500,350,"110 mph");
			}
			else if(D==40)
			{
				settextstyle(8,0,2);
				outtextxy(500,320,"Speed:");
				settextstyle(7,0,2);
				outtextxy(500,350,"120 mph");
			}
			else if(D==35)
			{
				settextstyle(8,0,2);
				outtextxy(500,320,"Speed:");
				settextstyle(7,0,2);
				outtextxy(500,350,"130 mph");
			}
			else if(D==30)
			{
				settextstyle(8,0,2);
				outtextxy(500,320,"Speed:");
				settextstyle(7,0,2);
				outtextxy(500,350,"140 mph");
			}
			else if(D==25)
			{
				settextstyle(8,0,2);
				outtextxy(500,320,"Speed:");
				settextstyle(7,0,2);
				outtextxy(500,350,"150 mph");
			}
			else if(D==20)
			{
				settextstyle(8,0,2);
				outtextxy(500,320,"Speed:");
				settextstyle(7,0,2);
				outtextxy(500,350,"160 mph");
			}
}
void info()
{
			bar3d(10,0,630,0,5,2);  // for boundaries of playing screen
			bar3d(10,0,10,475,5,2);
			bar3d(10,475,630,475,5,2);
			bar3d(630,0,630,475,5,2);

			settextstyle(4,0,2);
			outtextxy(20,50,"Controls:");
			settextstyle(13,0,5);
			outtextxy(20,100,"Left arrow:");
			outtextxy(20,120,"Move left");
			outtextxy(20,150,"Right arrow:");
			outtextxy(20,170,"Move right");
			outtextxy(20,200,"Space bar:");
			outtextxy(20,220,"Pause/Resume");
			outtextxy(20,250,"Esc:");
			outtextxy(20,270,"Exit");


			//prints score to the screen.
			settextstyle(8,0,2);
			outtextxy(500,150,"Score:");
			sprintf(scr,"%d ",a);
			settextstyle(7,0,2);
			outtextxy(500,180,scr);
			settextstyle(13,0,3);
			outtextxy(500,30,"Remaining Life:");
}

void h1() //prints the "MENU"
	{
		settextstyle(7,0,8);
		setcolor(GREEN);
		outtextxy(215,50,"MENU");
		setcolor(RED);
		bar3d(20,145,620,150,5,2);
	}
void h2()  // prints options
	{
		settextstyle(3,0,5);
		setcolor(GREEN);
		outtextxy(220,195,"Play Game");
		outtextxy(220,235,"High Score");
		outtextxy(220,275,"Instructions");
		outtextxy(220,315,"About");
		outtextxy(220,355,"Exit");
	}

void instructions()
{
	setbkcolor(BLACK);
	settextstyle(4,0,7);
	setcolor(GREEN);
	outtextxy(150,20,"Instructions");
	bar3d(50,120,550,125,3,1);
	settextstyle(4,0,4);
	setcolor(BLUE);
	outtextxy(60,135,"Objective:");
	settextstyle(8,0,3);
	setcolor(GREEN);
	outtextxy(60,165,"Save your car from the obstacles.");
	bar(50,200,550,202);
	settextstyle(4,0,4);
	setcolor(BLUE);
	outtextxy(60,203,"Controls:");
	settextstyle(8,0,3);
	setcolor(GREEN);
	outtextxy(60,235,"Left arrow key : Move left");
	outtextxy(60,265,"Right arrow key: Move right");
	outtextxy(60,295,"Up arrow key   : Move Up");
	outtextxy(60,325,"Down arrow key : Move Down");
	outtextxy(60,355,"space bar      : Pause/Resume game");
	outtextxy(60,385,"Enter          : Select/Choose/Continue");
	outtextxy(60,415,"Esc            : return to menu");

	bar3d(50,448,550,452,3,1);
	settextstyle(1,0,1);
	setcolor(RED);
	outtextxy(100,455,"Press esc to return to the main menu");
	kbhit();
	while(getch()!=27)
	{
		getch();
	}
	cleardevice();
	menu();
}

void about()
{

	setbkcolor(BLACK);
	settextstyle(4,0,7);
	setcolor(GREEN);
	outtextxy(150,20,"About");
	bar3d(50,120,550,125,3,1);
	setcolor(GREEN);
	bar3d(50,460,550,465,3,1);
	text();
	getch();
	cleardevice();
	text1();
	settextstyle(4,0,7);
	setcolor(GREEN);
	outtextxy(150,20,"About");
	bar3d(50,120,550,125,3,1);
	settextstyle(1,0,1);
	setcolor(RED);
	outtextxy(100,455,"Press esc to return to the main menu");

	kbhit();
	while(getch()!=27)
	{
		getch();
	}
	cleardevice();
	menu();
}

void text()
{

	settextstyle(4,0,4);
	setcolor(BLUE);
	outtextxy(40,130,"The Game: ");
	settextstyle(8,0,1);
	setcolor(GREEN);
	outtextxy(40,170,"Hope, You have played this game and enjoyed it.");
	outtextxy(40,190,"If not, then try it and score as much as you can.");
	outtextxy(40,220,"Drag'N'drive, as the name suggests, you will have to");
	outtextxy(40,240,"drag your car away from the obstacles in order to");
	outtextxy(40,260,"drive further. You have to select one of the four");
	outtextxy(40,280,"given cars and drive it to score points by avoiding");
	outtextxy(40,300,"the obstacles.");
	outtextxy(40,330,"Each obstacle avoided will award you 10 points. You ");
	outtextxy(40,350,"also have 3 lives, which means you have 3 chances.");
	outtextxy(40,380,"You can also give us your valuable suggestions via");
	outtextxy(40,400,"the details provided in the next page.");
	setcolor(WHITE);
	settextstyle(13,0,5);
	outtextxy(450,440,"Version 1.14");
}

void text1()
{
	settextstyle(4,0,4);
	setcolor(BLUE);
	outtextxy(40,130,"The Developers: ");
	settextstyle(8,0,1);
	outtextxy(40,320,"Aniket.kumar@hotmail.com");
	outtextxy(40,350,"rupalisingh2709@gmail.com");
	outtextxy(400,380,"bit.ly/dragndrive");
	setcolor(GREEN);
	outtextxy(40,170,"This game is a part of Computer Graphics Project work.");
	outtextxy(40,190,"We have tried to reduce as much technical or logical ");
	outtextxy(40,210,"errors as we can. However, it may contain some bugs.");
	outtextxy(40,240,"It is developed by Rupali Singh and Aniket Kumar,");
	outtextxy(40,260,"students of BCA (DSVV,Haridwar).");
	outtextxy(40,290,"You can mail us your valuable suggestions at: ");
	outtextxy(40,380,"The repository of this game is at: ");
	outtextxy(40,410,"So, what are you waiting for?");
	outtextxy(40,430,"Go & score as much as you can.");
}
