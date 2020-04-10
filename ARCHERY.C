
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

union REGS i,o;
int f;
struct arccoordstype arcinfo;
int t,flag=0;
int
gm=0,gd=DETECT,*button,*a,*b,c,bc,j,k,jk,h,x3,y3,alh=0,s,scor=0,sp=0,e,m=2
;
main()
{

//initgraph(&gm,&gd,"c:\\turboc3\\bgi");
front();
closegraph();
//delay(10);
//sta();
 a:
initgraph(&gd,&gm,"c:\\turboc3\\bgi ");
flag=0;
setbkcolor(0);
s=-60;e=60;

sound(221.38);
for(f=1;f<=20;f++)
 {
 setcolor(BLUE);
 line(280,f+360,360,f+360);
       }
       setcolor(RED);
       settextstyle(SMALL_FONT,HORIZ_DIR,4);
       outtextxy(305,364,"SHOOT");
arrows(0);

setcolor(GREEN+WHITE);
rectangle(5,5,634,474);
rectangle(6,6,633,473);
setcolor(YELLOW);
rectangle(7,7,632,472);
setcolor(GREEN+WHITE);
rectangle(8,8,631,471);
rectangle(9,9,630,470);
rectangle(10,10,629,469);

setcolor(YELLOW);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(530,20,"SCORE");
scor=0;
score(200);
m=6;
equip();
arrow1(0,14);
alh=0;
mousereg();
while(m>1)         /* while start */
{
	    //button=0;
    for(j=-70;j<=70;j+=2)           /* start for*/
       {   c=1;
	   tar(j,c);
	   delay(10);



	   getmouseptr(&button,&a,&b);

	   if(button==1)
		{     x3=a;y3=b;
		if((x3>280 && x3<360 )|| (y3>361 && y3<379))
		     {
			bc=1;
		     }
		 }
		       if(bc==1)

			{  //sound(277.38);
	   //		delay(10);
			nosound();
			   arrow1(0,0);
			setcolor(YELLOW);
			line(40+sp+36,240,80+sp+36,240);
			line(80+sp+36,240,75+sp+36,235);
			line(80+sp+36,240,75+sp+36,245);
			line(40+sp+36,241,80+sp+36,241);
			line(79+sp+36,240,74+sp+36,236);
			line(79+sp+36,241,74+sp+36,245);

			line(46+sp+36,240,41+sp+36,236);
			line(46+sp+36,241,41+sp+36,245);
			line(42+sp+36,240,37+sp+36,236);
			line(42+sp+36,241,37+sp+36,245);

			delay(8);
			setcolor(0);
			line(40+sp+36,240,80+sp+36,240);
			line(80+sp+36,240,75+sp+36,235);
			line(80+sp+36,240,75+sp+36,245);
			line(40+sp+36,241,80+sp+36,241);
			line(79+sp+36,240,74+sp+36,236);
			line(79+sp+36,241,74+sp+36,245);
			line(46+sp+36,240,41+sp+36,236);
			line(46+sp+36,241,41+sp+36,245);
			line(42+sp+36,240,37+sp+36,236);
			line(42+sp+36,241,37+sp+36,245);
			if((42+sp+36)>=116 && (42+sp+36)<=136)
			{
			equip();
			}
			sp=sp+3;
			}
				  if((sp+80+36)>=579)
				     {  arrow1(0,14);
					score(j);
					bc=0; sp=0;
					alh++;
					button=0;
					setcolor(YELLOW);
					arrows(alh);
					m--;
				   }
			      //	sp=sp+3;
				c=0;
				tar(j,c);
	}    					   /* for end */



	}/* while end */
	sleep(1.5);
      closegraph();
      gaover();
      setcolor(GREEN);
      setcolor(1);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
      outtextxy(255,117,"SCORE");
     setcolor(14+BLUE);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
      for(t=0;t<=360;t++)
      { setcolor(random(15));
      ellipse(300,200,t,t+2,30,22);
       delay(1);
       setcolor(random(15));
      ellipse(300,200,t,t+2,35,25);
      }
      setcolor(GREEN);
      select(scor,-250,133);
      for(t=0;t<=50;t++)
      {
      setcolor(14);
   line(40+t,230,40+t,250);
   line(560+t,230,560+t,250);
   }
   settextstyle(SMALL_FONT,HORIZ_DIR,4);
   setcolor(BLUE);
   outtextxy(45,235,"Continue");
   outtextxy(575,235,"Quit");
   restrictmouseptr(0,80,640,440);
   flag=0;
   while(flag==0)
   {
    showmouseptr();
    getmouseptr(&button,&a,&b);
	   if(button==1)
		{     x3=a;y3=b;
		if((x3>41 && x3<79 )&& (y3>231 && y3<249))
		   {
		    flag=1;
		    //break;
		    }
		else if((x3>=561 && x3<=599 )&& (y3>=231 && y3<=249))
		    {
		     flag=2;
		    //break;
		      }
		  }
       }

	       if(flag==1)
		 goto a;
	       else
		 {if(flag==2)
		  {initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		  finalwindow();
		  closegraph();
		  goto b;}}

    //  next();




    b:   getch();
 }//ending of main function



	   /* sub function target starting*/

 arrow1(int sp,int col)
 { setcolor(col);            //sound(277.38);
			line(40+sp+36,240,80+sp+36,240);
			line(80+sp+36,240,75+sp+36,235);
			line(80+sp+36,240,75+sp+36,245);
			line(40+sp+36,241,80+sp+36,241);
			line(79+sp+36,240,74+sp+36,236);
			line(79+sp+36,241,74+sp+36,245);

			line(46+sp+36,240,41+sp+36,236);
			line(46+sp+36,241,41+sp+36,245);
			line(42+sp+36,240,37+sp+36,236);
			line(42+sp+36,241,37+sp+36,245);
			nosound();

   }

   tar(j,c)
 {
   setcolor(c*4);
   ellipse(579,240+j,0,360,40,90);
   setcolor(c*3);
   ellipse(579,240+j,0,360,33,75);
   setcolor(c*5);
   ellipse(579,240+j,0,360,26,60);
   setcolor(c*9);
   ellipse(579,240+j,0,360,19,45);
   setcolor(c*8);
   ellipse(579,240+j,0,360,12,30);
   setcolor(c*10);
   ellipse(579,240+j,0,360,5,15);
 }
 initmouse()
 {
 i.x.ax=0;
 int86(0x33,&i,&o);
 return(o.x.ax);
 }
 showmouseptr()
 {
 i.x.ax=1;
 int86(0x33,&i,&o);
 }
 restrictmouseptr(int x1,int y1,int x2,int y2)
 {
 i.x.ax=7;
 i.x.cx=x1;
 i.x.dx=x2;
 int86(0x33,&i,&o);
 i.x.ax=8;
 i.x.cx=y1;
 i.x.dx=y2;
 int86(0x33,&i,&o);
 }
 getmouseptr(int *button,int *a,int *b)
 {
 i.x.ax=3;
 int86(0x33,&i,&o);
 *button=o.x.bx;
 *a=o.x.cx;
 *b=o.x.dx;
 }

 mousereg()
 {
 int x1,x2,y1,y2,ce,k;
 initmouse();
 showmouseptr();
 restrictmouseptr(281,361,359,379);
 }


arrows(alh)
{   int z=0,r;
     r=5-alh;
     setcolor(YELLOW);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 outtextxy(30,20,"ARROWS REMAINING");
 for(f=r,z=0;f>0;f--)
{
 line(40,60+z*10,80,60+z*10);
 line(80,60+z*10,75,55+z*10);
 line(80,60+z*10,75,65+z*10);
 z=z+1;
 }
 for(f=alh,z=0;f>0;f--)
 {
 setcolor(0);
 line(40,60+z*10,80,60+z*10);
 line(80,60+z*10,75,55+z*10);
 line(80,60+z*10,75,65+z*10);
 z=z+1;
 }
 }

 score (int j)
  {
    if( (j>=-90 && j<=-74) || (j>=74 && j<=90))
       scor=scor+10;

    else if((j>=-72 && j<=-60) || (j>=60 && j<=72))
	  scor=scor+20;
    else  if((j>=-58 && j<=-42) || (j>=42 && j<=58))
	 scor=scor+30;
    else  if((j>=-40 && j<=-32) || (j>=32 && j<=40))
       scor=scor+40;
     else  if((j>=-30 && j<=-18) || (j>=18 && j<=30))
	 scor=scor+50;
     else  if((j>=-16 && j<=0) || (j>=0 && j<=16))
	 scor=scor+60;
     else if (j == 300)
	 scor=0;

	 for(jk=50;jk<=120;jk++)
	 {setcolor(0);
	  line(530,jk,620,jk);
	  }
	  setcolor(YELLOW);
	  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		 select(scor,0,0);
		 }



 front1()
{
int gm=0,gd=DETECT,i,j,k,jk,gh;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setcolor(MAGENTA);
rectangle(10,10,639,469);
rectangle(12,12,637,467);
for(i=12;i<=627;i+=12)
{

setcolor(YELLOW);
line(i,12,i,467);
//clearviewport();

for(j=15;j<=464;j+=5)
ellipse(i+6,j,-180,0,6,4);

}
for(i=3;i<=452;i+=5)
{ for(j=15;j<=627;j+=3)
  {setcolor(0);
   ellipse(j,467-i,-180,0,3,4);
   }delay(40);
   setcolor(BLACK);
   for(k=1;k<=5;k++)
   {
   line(12,467-i+k,637,467-i+k); }
 //setcolor(25);
  setcolor(GREEN+MAGENTA+WHITE+BLUE+YELLOW);
rectangle(10,10,639,469);
rectangle(12,12,637,467);

}
setcolor(2);
	 rectangle(290,370,350,380);
	 rectangle(292,372,348,378);
	 gh=292; //gh<=388;

for(j=1;j<=56;j+=1)
   { /* for(i=24;i<=627;i+=12)
	{setcolor(i);
	   circle(i,23,3);
	  delay(1);
	 } */  jk=20;
      for(i=24;i<=627;i+=12)
	{setcolor(random(15));
	 circle(i,23,3);
	sound(440+jk);
	 delay(10);
	 nosound();

	 setcolor(YELLOW);
	 rectangle(gh,372,gh,378);
		 //rectangle(282,362,358,388);}
	jk+=40;
 if(jk>=880)
 { jk=440;}

}
gh=gh+1;
nosound();
}
sleep(.1);
closegraph();
}


 equip()
 {
    int kl=2;
   int midx, midy,i,j,k,y=90,c;
  // int stangle = 45, endangle = 270;

	    c=y/2;

	    for(c=50;c<=52;c+=1)
	    {      setcolor(kl);
	     line(26+c,170,26+c,310);
	     }
	     for(c=50;c<=54;c+=1)
	    {      setcolor(kl);
	     line(60+c,222,60+c,255);
	     }

	     for(c=180;c<=270;c++)
	     {
	    // arc(80,92,c,c+1,20);
	     setcolor(0);
	   arc(86,166,c,c+1,10);
	   getarccoords(&arcinfo);
	   setcolor(kl);
	   circle(arcinfo.xend, arcinfo.yend,2);
    }

	     for(c=-50;c<=110;c++)
	     {
	    // arc(80,92,c,c+1,20);
	     setcolor(0);
	   arc(96,201,c,c+1,28);
	   getarccoords(&arcinfo);
	   setcolor(kl);
	   circle(arcinfo.xend, arcinfo.yend,2);
    }
	     for(c=50,i=4;c>=-110;c--)
	     {
	    // arc(80,92,c,c+1,20);
	     setcolor(0);
	     line(127,170,127,315);
	     line(126,170,126,315);
	   arc(96,278,c,c+1,28);
	   getarccoords(&arcinfo);
	   setcolor(kl);
	   i=i+2;
	   if(i>14)
	   {i=2;}
	   circle(arcinfo.xend,arcinfo.yend,2);
	    }
       for(c=90;c<=180;c++)
	     {
	    // arc(80,92,c,c+1,20);
	     setcolor(0);
	   arc(86,314,c,c+1,10);
	   getarccoords(&arcinfo);
	   setcolor(kl);
	   circle(arcinfo.xend, arcinfo.yend,2);
	   //setcolor(2);

    }

    }

sta()
{
 int x,y=200,i,st,kl;
 //initgraph(&gd,&gm,"");
  setcolor(5);

 for(st=190,i=2;st>=-20;st-=9,i+=3)
 {
 setcolor(GREEN);
 arc(320,290,st,st+2,190);
	   getarccoords(&arcinfo);
			  delay(5);
	   x=arcinfo.xend;
	   y=arcinfo.yend;
	   sound(300-st);
      star(x,y);
      delay(24);
 }
 for(st=190,i=2;st>=-17;st-=9,i+=3)
 {
 setcolor(YELLOW);
 arc(320,285,st,st+2,230);
	   getarccoords(&arcinfo);
			  delay(5);
	   x=arcinfo.xend;
	   y=arcinfo.yend;
	   sound(320-st);
      star(x,y);
      delay(24);
 }
 nosound();
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);

 for(i=140;i>=20;i-=10)
 {

 setcolor(8);
 delay(13);
 ya(i);
 delay(13);
 setcolor(4);
 r(i);
 delay(13);
 setcolor(2);
 e1(i);
 delay(13);
 h1(i);
 delay(13);
 c1(i);
 delay(13);
 r1(i);
 delay(13);
 a1(i);
 delay(13);


 /*line(320,240,325,233);    // /1
 line(325,233,330,240);    // 1
 line(330,240,337,240);    // right hori
 line(320,240,313,240); //left hori
 line(313,240,318,247);  // left horiz to right 
 line(337,240,332,247); // right horiz to left /
 line(332,247,334,253); // left / to right 
 line(318,247,316,253); // right  to left /
 line(316,253,325,247);
 line(334,253,325,247);*/



// getch();
 }
 }
 ya(int i)
 {
  if(i==120)
  {

  delay(1);
  setcolor(4);
 // delay(800);
outtextxy(300+i,230,"Y");
  }setcolor(14);
  delay(1);
  outtextxy(420,230,"Y");  //440
 }

 r(int i)
 {
  if(i==90)
  {

  setcolor(2);
  delay(1);
 outtextxy(300+i,230,"R");
  }setcolor(14);
  delay(1);
  outtextxy(390,230,"R");   // 420
 }
 e1(int i)
 {
  if(i==60)
  {

  setcolor(2);
  delay(1);
 outtextxy(300+i,230,"E");
  }setcolor(14);
  delay(1);
  outtextxy(360,230,"E");  //400
 }
 h1(int i)
 {
  if(i==30)
  {

  setcolor(2);
  delay(1);
 outtextxy(300+i,230,"H");
  }setcolor(14);
  delay(1);
  outtextxy(330,230,"H"); //380
 }

 c1(int i)
 {
  if(i==60)
  {

  setcolor(2);
  delay(1);
 outtextxy(300+i-i,230,"C");
  }setcolor(14);
  delay(1);
  outtextxy(300,230,"C");  //360
 }
 r1(int i)
 {
  if(i==40)
  {

  setcolor(2);
  delay(1);
 outtextxy(300+i-70,230,"R");
  }setcolor(14);
  delay(1);
  outtextxy(270,230,"R");     // 340
 }

 a1(int i)
 {
  if(i==20)
  {

  setcolor(2);
  delay(1);
 outtextxy(300+i-80,230,"A");
  }setcolor(14);
  delay(1);
  outtextxy(240,230,"A");   //320
 }
 star(x,y)
 {
 delay(80);
 line(x,y,x+5,y-7);    // /1     x=320, y=240
 line(x+5,y-7,x+10,y);    // 1
 line(x+10,y,x+17,y);    // right hori
 line(x,y,x-7,y); //left hori
 line(x-7,y,x-2,y+7);  // left horiz to right 
 line(x+17,y,x+12,y+7); // right horiz to left /
 line(x+12,y+7,x+14,y+13); // left / to right 
 line(x-2,y+7,x-4,y+13); // right  to left /
 line(x-4,y+13,x+5,y+7);
 line(x+14,y+13,x+5,y+7);
 }
front()
{
int gm=0,gd=DETECT,i,j,k,jk,gh;
initgraph(&gd,&gm,"c:\\turboc3\\bgi ");
setcolor(MAGENTA);
rectangle(10,10,639,469);
rectangle(12,12,637,467);
for(i=12;i<=627;i+=12)
{

setcolor(YELLOW);
line(i,12,i,467);
//clearviewport();
for(j=15;j<=464;j+=5)
ellipse(i+6,j,-180,0,6,4);

}
for(i=3;i<=452;i+=5)
{ for(j=15;j<=627;j+=3)
  {setcolor(0);
   ellipse(j,467-i,-180,0,3,4);
   }delay(40);
   setcolor(BLACK);
   for(k=1;k<=5;k++)
   {
   line(12,467-i+k,637,467-i+k); }
 //setcolor(25);
  setcolor(GREEN+MAGENTA+WHITE+BLUE+YELLOW);
rectangle(10,10,639,469);
rectangle(12,12,637,467);

}
setcolor(2);
	 rectangle(290,370,350,380);
	 rectangle(292,372,348,378);
	 gh=292; //gh<=388;

for(j=1;j<=56;j+=1)
   { /* for(i=24;i<=627;i+=12)
	{setcolor(i);
	   circle(i,23,3);
	  delay(1);
	 } */  jk=20;
      for(i=24;i<=627;i+=12)
	{setcolor(random(15));
	 circle(i,23,3);
	sound(200-i);
	 delay(1);
	 nosound();

	 setcolor(YELLOW);
	 rectangle(gh,372,gh,378);
		 //rectangle(282,362,358,388);}
	jk+=40;
 if(jk>=880)
 { jk=440;}

}
gh=gh+1;
nosound();
}
//printf("sdfs");
sta();
sleep(.1);
//closegraph();
}
gaover()
{
int gm=0,gd=DETECT,i,j;
initgraph(&gd,&gm,"c:\\turboc3\\bgi ");

for(i=1;i<=51;i+=4)
{
setcolor(i);
sound(400-i);
outtextxy(260,340,"GAME OVER");
if(i==49)
{
setcolor(YELLOW);
outtextxy(260,340,"GAME OVER");
}
nosound();
go(0,60,20,80,random(15),random(15));
delay(3);
go(400,460,420,480,random(15),random(15));
}

//getch();
}

go(int sy1,int ey1,int sy2,int ey2,int k,int h)
{
int i,j;
for(j=sy1;j<=ey1;j+=40)        //120
{

for(i=0;i<=640;i+=40)
{

setcolor(k);
rectangle(i,1+j,20+i,21+j);
setfillstyle(SOLID_FILL,k);
floodfill(10+i,10+j,k);
setcolor(h);
rectangle(20+i,1+j,40+i,21+j);
setfillstyle(SOLID_FILL,h);
floodfill(25+i,10+j,h);
}
}
for(j=sy2;j<=ey2;j+=40)
{

for(i=0;i<=640;i+=40)
{

setcolor(h);
rectangle(i,1+j,20+i,21+j);
setfillstyle(SOLID_FILL,h);
floodfill(10+i,10+j,h);
setcolor(k);
rectangle(20+i,1+j,40+i,21+j);
setfillstyle(SOLID_FILL,k);
floodfill(25+i,10+j,k);
}
}
//
}

select(int scor,int p,int q)
{
switch(scor)
     { case 0: outtextxy(530+p,50+q,"0");
		       break;
       case 10: outtextxy(530+p,50+q,"10");
	       break;
       case 20: outtextxy(530+p,50+q,"20");
	       break;
       case 30: outtextxy(530+p,50+q,"30");
	       break;
       case 40: outtextxy(530+p,50+q,"40");
	       break;
      case 50: outtextxy(530+p,50+q,"50");
	       break;
      case 60: outtextxy(530+p,50+q,"60");
	       break;
      case 70: outtextxy(530+p,50+q,"70");
	       break;
      case 80: outtextxy(530+p,50+q,"80");
	       break;
      case 90: outtextxy(530+p,50+q,"90");
	       break;
      case 100: outtextxy(530+p,50+q,"100");
	       break;
      case 110: outtextxy(530+p,50+q,"110");
	       break;
      case 120: outtextxy(530+p,50+q,"120");
	       break;
      case 130: outtextxy(530+p,50+q,"130");
	       break;
      case 140: outtextxy(530+p,50+q,"140");
	       break;
      case 150: outtextxy(530+p,50+q,"150");
	       break;
      case 160: outtextxy(530+p,50+q,"160");
	       break;
      case 170: outtextxy(530+p,50+q,"170");
	       break;
      case 180: outtextxy(530+p,50+q,"180");
	       break;
      case 190: outtextxy(530+p,50+q,"190");
	       break;
      case 200: outtextxy(530+p,50+q,"200");
	       break;
      case 210: outtextxy(530+p,50+q,"210");
	       break;
      case 220: outtextxy(530+p,50+q,"220");
	       break;
      case 230: outtextxy(530+p,50+q,"230");
	       break;
      case 240: outtextxy(530+p,50+q,"240");
	       break;
      case 250: outtextxy(530+p,50+q,"250");
	       break;
      case 260: outtextxy(530+p,50+q,"260");
	       break;
      case 270: outtextxy(530+p,50+q,"270");
	       break;
      case 280: outtextxy(530+p,50+q,"280");
	       break;
      case 290: outtextxy(530+p,50+q,"290");
	       break;
      case 300: outtextxy(530+p,50+q,"300");
	       break;
      case 310: outtextxy(530+p,50+q,"310");
	       break;
      case 320: outtextxy(530+p,50+q,"320");
	       break;
      case 330: outtextxy(530+p,50+q,"330");
	       break;
      case 340: outtextxy(530+p,50+q,"340");
	       break;
      case 350: outtextxy(530+p,50+q,"350");
	       break;
      case 360: outtextxy(530+p,50+q,"360");
	       break;
 }		 }

flower(int i,int j)
{
setcolor(14);
circle(320+i,240+j,10);
setfillstyle(SOLID_FILL,RED);
floodfill(323+i,241+j,14);
//1
setcolor(14);
//floodfill(316,223,13);
ellipse(310+i,220+j,90,-90,6,12);
ellipse(330+i,220+j,-90,90,6,12);
ellipse(320+i,207+j,180,0,8,2);
//2
ellipse(310+i,260+j,90,-90,6,12);
ellipse(330+i,260+j,-90,90,6,12);
ellipse(320+i,273+j,0,180,8,2);
//3
ellipse(298+i,248+j,180,0,12,6);
ellipse(298+i,233+j,0,180,12,6);
ellipse(286+i,240+j,-90,90,2,8);
//4
ellipse(342+i,247+j,180,0,12,6);
ellipse(342+i,233+j,0,180,12,6);
ellipse(354+i,240+j,90,-90,2,8);
}

finalwindow()
{
for(k=-285;k<=320;k+=70)
{ flower(k,-205);
  flower(k,+180);
  //clearviewport();
  delay(100);
}
for(k=-140;k<=180;k+=40)
{ flower(-285,k);
  flower(276,k);
  //clearviewport();
  delay(100);
  }

setcolor(2);
sleep(4);

}