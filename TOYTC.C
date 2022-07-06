/* A basic 2D game with terminal animation in C & BGI */
/* With a keyboard-controlled humanoid (obj), semi-intelligently-moving monster (teras), cage (keli), ladder (skala), button, laser, gate, and key */
/* @lxndroc '96 */
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
void drawteras(int,int,int);void drawobj(int,int,int,int,int);void moveteras(int,int,int *,int);
void eaten(void);void getobj(int,int,int,int);void getimg(int,int,int,int,void **);
void drawkeli(void);void drawskala(void);void getscala(void);void pushbutton(int);
void drawkey(void);void getkey(void);void drawlaser(void);void drawgate(void);void init(void);void buttons(void);
int radius,c,lefteras,righteras,lefterd,righterd; float ratio; void *p,*q,*r,*s,*t;
int a,b,xasp,yasp,leftman,rightman,topman,size,rule,get,getd,dun;char d;
 int it,itd,i,getsk,pushed,pushd,putsk,leftsk,upsk,j;
 int onsk,maxj,getkl,freeg,freed,maxupsk,gate;float tport;
void main()
{ init();
  }
void init()
{ rule=1,get=-1,getd=-1,dun=0;d='g';
 it=1,itd=1,i=-1,getsk=-1,pushed=0,pushd=0,putsk=0,leftsk=-1,upsk=0,j=0;
 onsk=0,maxj=-1,getkl=-1,freeg=0,freed=0,maxupsk=-1,gate=0;tport=1.0;randomize(); a=DETECT; initgraph(&a,&b,""); getaspectratio(&xasp,&yasp);
  ratio=(float) xasp/yasp; rectangle(0,0,getmaxx(),getmaxy());
  line(getmaxx()/100,getmaxy()/1.49,getmaxx()/1.01,getmaxy()/1.49);
  radius=getmaxx()/25; circle(getmaxx()/15,getmaxy()/1.785,radius);
  line(getmaxx()/15,getmaxy()/1.5-ratio*radius,getmaxx()/15+radius,getmaxy()/1.5);
  line(getmaxx()/15,getmaxy()/1.5-ratio*radius,getmaxx()/15-radius,getmaxy()/1.5);
  size=imagesize(getmaxx()/15-radius,getmaxy()/1.785-ratio*radius,getmaxx()/15+radius,getmaxy()/1.5);
  p=(void *)malloc(size);
  getimage(getmaxx()/15-radius,getmaxy()/1.785-ratio*radius,getmaxx()/15+radius,getmaxy()/1.5,p);
  topman=getmaxy()/1.785-ratio*radius;leftman=getmaxx()/15-radius; rightman=getmaxx()/15+radius;
  drawteras(14*getmaxx()/15,getmaxy()/1.785,getmaxy()/1.5);
  getimg(14*getmaxx()/15-radius,getmaxy()/1.785-1.01*ratio*radius,2*radius,getmaxy()/1.501,&q);
  lefteras=14*getmaxx()/15-radius;righteras=lefteras+2*radius;
  lefterd=14*getmaxx()/15-radius;righterd=lefterd+2*radius; drawobj(2*getmaxx()/3,getmaxy()/1.785,radius/3,ratio*radius/2,0);
  drawteras(14*getmaxx()/15,1.59*getmaxy()/1.785,getmaxy()/1.003);
  drawobj(14*getmaxx()/15-radius/3,1.59*getmaxy()/1.785-1.25*ratio*radius,radius/3,ratio*radius/2,1);
  line(getmaxx()/2,getmaxy()/1.495,getmaxx()/2,getmaxy()/9+4*ratio*radius);
  line(getmaxx()/2-0.75*radius,getmaxy()/9+4*ratio*radius,getmaxx()/2+0.75*radius,getmaxy()/9+4*ratio*radius);buttons();}
void buttons()
{
 while ((c=getch())!='1'&&freed!=4)
 {
  switch (c)
 {case 'w':if(putsk==1&&leftman==leftsk&&rule==1&&topman>getmaxy()/9+2*ratio*radius) {
	   onsk=1;putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	   ++j;upsk+=ratio*radius;topman-=ratio*radius;
	   putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	   if (topman<=getmaxy()/9+2*ratio*radius) {maxj=j;maxupsk=upsk;}
	   } else if(topman>getmaxy()/9+2*ratio*radius) {
	   putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	   putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-2*ratio*radius,p,1);
	   topman-=ratio*radius; delay(100);
	   if (rightman>=14*getmaxx()/15&&topman==(int) (1.59*getmaxy()/1.785-2*ratio*radius)&&getd==-1)
	   {getobj(14*getmaxx()/15-radius/3,1.59*getmaxy()/1.785-1.25*ratio*radius,ratio*radius/2,1);getd=1;}
	   moveteras(14*getmaxx()/15,getmaxy()/1.785,&it,random(2));
	   moveteras(14*getmaxx()/15,1.59*getmaxy()/1.785,&itd,random(2));
	   putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-2*ratio*radius,p,1);
	   putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	   topman+=ratio*radius; }  break;
 case 'a':if (leftman>getmaxx()/15-radius) {
          if(onsk==1) {putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	  --i;putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	  while (upsk) {
	  putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	  upsk-=0.2*ratio*radius;putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	  }	  onsk=0; j=0; topman=getmaxy()/1.785-ratio*radius;
	  leftman-=radius; rightman-=radius;
	  if(freeg>0&&freed==0) {putimage(7.05*getmaxx()/8+0.5*radius,getmaxy()/9+0.9*ratio*radius,p,1);
	  putimage(getmaxx()/15+(i+1)*radius,getmaxy()/1.785-ratio*radius-maxupsk,p,1);freed=1;}}
	  else {putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  if(freed==2) putimage(getmaxx()/15+(i+1)*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  --i;putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  if(freed==2) putimage(getmaxx()/15+(i+1)*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  leftman-=radius; rightman-=radius;} moveteras(14*getmaxx()/15,getmaxy()/1.785,&it,random(2));
	  moveteras(14*getmaxx()/15,1.59*getmaxy()/1.785,&itd,random(2));
	  if(rightman<getmaxx()-2*radius&&rightman>getmaxx()-3*radius&&freed==1&&rule==1)
	  {int g=i;putimage(getmaxx()/15+(g+2)*radius,getmaxy()/1.785-ratio*radius-maxupsk,p,1);
	  putimage(getmaxx()/15+(g+1)*radius,getmaxy()/1.785-ratio*radius-maxupsk,p,1);
	  while (maxupsk) {
	  putimage(getmaxx()/15+(g+1)*radius,getmaxy()/1.785-ratio*radius-maxupsk,p,1);
	  maxupsk-=0.2*ratio*radius;putimage(getmaxx()/15+(g+1)*radius,getmaxy()/1.785-ratio*radius-maxupsk,p,1);
	  } ++freed;}} break;
 case 'd':if (rightman<getmaxx()-radius) {
          if(onsk==1) {putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	  ++i;putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	  while (upsk) {
	  putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	  upsk-=0.2*ratio*radius;putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius-upsk,p,1);
	  }	  onsk=0; j=0; topman=getmaxy()/1.785-ratio*radius;
	  leftman+=radius; rightman+=radius; }
	  else {putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  if(freed==2) putimage(getmaxx()/15+(i+1)*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  ++i;putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  if(freed==2) putimage(getmaxx()/15+(i+1)*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  rightman+=radius; leftman+=radius;} moveteras(14*getmaxx()/15,getmaxy()/1.785,&it,random(2));
	  moveteras(14*getmaxx()/15,1.59*getmaxy()/1.785,&itd,random(2));} break;
 case 's':if (leftman==getmaxx()/15-radius&&rule==0&&pushd==0&&dun==0)
	  {pushbutton(0);drawkey();pushd=1;
	  getimg(getmaxx()/2-0.65*radius,getmaxy()/9+3.4*ratio*radius,1.3*radius,getmaxy()/9+3.9*ratio*radius,&s);}
	  else if (leftman==getmaxx()/15-radius&&rule==0&&dun==1&&pushed==0)
	  {pushbutton(1);drawskala();pushed=1;} else
	  if(leftman==getmaxx()/15-radius&&rule==1&&getsk==-1&&pushed==1)
	  {getscala();getsk=1;} else
	  if (onsk==1) { if (j==maxj)
	  {if (leftman<getmaxx()/2-0.3*ratio*radius&&rightman>getmaxx()/2+0.3*ratio*radius&&getkl==-1&&pushd==1)
	  {getkey();getkl=1;} else if(rightman>=14*getmaxx()/15&&freeg==0&&getkl==1)
	  {putimage(7.05*getmaxx()/8+1,getmaxy()/9+1,t,1);freeg=1;
	  setviewport(7.05*getmaxx()/8+0.9*radius,getmaxy()/9+0.19*ratio*radius,7.05*getmaxx()/8+0.9*radius+textwidth("HELP"),getmaxy()/9+0.19*ratio*radius+0.7*textheight("HELP"),1);
	  clearviewport();setviewport(0,0,getmaxx(),getmaxy(),1);}}} else
	  if (get==1) {if (topman==(int) (getmaxy()/1.785-ratio*radius)) {tport=1.59;
	  putimage(getmaxx()/15+i*radius,getmaxy()/1.785-ratio*radius,p,1);
	  if(freed==2) putimage(getmaxx()/15+(i+1)*radius,getmaxy()/1.785-ratio*radius,p,1);rule=0;}
	  if (topman==(int) (1.59*getmaxy()/1.785-ratio*radius)) {tport=1.0;
	  putimage(getmaxx()/15+i*radius,1.59*getmaxy()/1.785-ratio*radius,p,1);
	  if(freed==2) putimage(getmaxx()/15+(i+1)*radius,1.59*getmaxy()/1.785-ratio*radius,p,1);rule=1;}
	  putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  if(freed==2) putimage(getmaxx()/15+(i+1)*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  topman=tport*getmaxy()/1.785-ratio*radius;  }	   break;
 case 'e':if(!onsk&&freed!=2) {  if (rightman<getmaxx()-radius) {
	  putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);++i;
	  putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-2*ratio*radius,p,1);
	  topman-=ratio*radius;delay(100);leftman+=radius;rightman+=radius;
	  if (rightman>=14*getmaxx()/15&&topman==(int) (1.59*getmaxy()/1.785-2*ratio*radius)&&getd==-1)
	  {getobj(14*getmaxx()/15-radius/3,1.59*getmaxy()/1.785-1.25*ratio*radius,ratio*radius/2,1);getd=1;}
	  moveteras(14*getmaxx()/15,getmaxy()/1.785,&it,random(2));
	  moveteras(14*getmaxx()/15,1.59*getmaxy()/1.785,&itd,random(2));
	  putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-2*ratio*radius,p,1);
	  if (rightman<getmaxx()-1.5*radius) {++i;leftman+=radius;rightman+=radius;}
	  putimage(getmaxx()/15+i*radius,tport*getmaxy()/1.785-ratio*radius,p,1);
	  topman+=ratio*radius; }} break;
 case 'x':if(j==0) {
	  if(putsk==0&&rule==1&&getsk==1) {putimage(getmaxx()/15+i*radius,getmaxy()/9+4*ratio*radius,r,1);
	  putsk=1;leftsk=leftman;} else
	  if(rule==1&&leftsk==leftman&&freed%3==0) {putimage(getmaxx()/15+i*radius,getmaxy()/9+4*ratio*radius,r,1);
	  putsk=0;} } break;
 } if (rightman>=2*getmaxx()/3&&get==-1) {getobj(2*getmaxx()/3,getmaxy()/1.785,ratio*radius/2,0);
 sound(500); delay(50); sound(200); delay(50); get=1;
 drawobj(7.05*getmaxx()/8,getmaxy()/9+4*ratio*radius,3*radius,4*ratio*radius,1);
 getimg(7.05*getmaxx()/8+1,getmaxy()/9+1,3*radius-2,getmaxy()/9+4*ratio*radius-1,&t);
  nosound();}
 if (rightman>=lefteras&&rule==1&&leftman<=righteras||rightman>=lefterd&&rule==0&&leftman<=righterd) {eaten(); break;}
 if(leftman<=getmaxx()/2+0.75*radius&&rightman>=getmaxx()/2+0.75*radius&&rule==1&&freeg==2) {eaten();break;}
 if (getd==1&&dun==0) {drawkeli();dun=1; }
 if (freeg==1) {drawlaser();++freeg;}
 if (freed==2&&!gate) {drawgate();++gate;rightman+=radius;}
 if (leftman==getmaxx()/15-radius&&rule==1&&gate&&(freed==2||putsk==0))
 { sound(2000);delay(150);sound(1000);delay(200);nosound();leftman+=radius;
 putimage(getmaxx()/15-radius,getmaxy()/1.785-ratio*radius,p,1);++i;++freed;}
   } if(freed==4) {setviewport(1,1,getmaxx()-1,getmaxy()-1,1);
   clearviewport();setviewport(0,0,getmaxx(),getmaxy(),1);outtextxy(2*getmaxx()/5,2*getmaxy()/5,"CONGRATULATIONS!!!");
   outtextxy(2*getmaxx()/5,2*getmaxy()/5+textheight("T"),"Another game pal? :-) (y/n)");
   while(d!='y'&&d!='n') {if((d=getch())=='y') init(); } }}
void drawteras(int xter,int yter,int down)
{line(xter,yter-ratio*radius,xter-radius,yter); moveto(xter-radius,yter);
 linerel(radius,0);lineto(xter-radius,down-ratio*radius);
 linerel(radius,0); linerel(0,ratio*radius); linerel(radius,0);
 lineto(xter+radius,yter-ratio*radius); linerel(-radius,0);}
void getimg(int xter,int yter,int length,int down,void **ptrg)
  {int sizeter;
   sizeter=imagesize(xter,yter,xter+length,down);
   *ptrg=(void *)malloc(sizeter);
   getimage(xter,yter,xter+length,down,*ptrg); }
void moveteras(int xmter,int ymter,int *d,int flag)
 {int lefter,righter;  if (ymter>1.3*getmaxy()/1.785) {lefter=lefterd; righter=righterd;}
  else {lefter=lefteras; righter=righteras;}
  if (lefter>getmaxx()/15&&flag==1) {
  putimage(xmter-*d*radius,ymter-ratio*radius,q,1);++*d;
  putimage(xmter-*d*radius,ymter-ratio*radius,q,1);
  if (ymter>1.3*getmaxy()/1.785) {lefterd-=radius;righterd-=radius;}
  else {lefteras-=radius;righteras-=radius;}} else flag=0;
  if (righter<xmter+radius&&flag==0) {
  putimage(xmter-*d*radius,ymter-ratio*radius,q,1);--*d;
  putimage(xmter-*d*radius,ymter-ratio*radius,q,1);
  if (ymter>1.3*getmaxy()/1.785) {lefterd+=radius;righterd+=radius;} else
  {lefteras+=radius;righteras+=radius;} if (righteras<xmter+radius) flag=0;else flag=1;}
 }
void drawobj(int xobj,int yobj,int xwidth,int yheight,int x)
 { rectangle(xobj,yobj,xobj+xwidth,yobj-yheight);if (x) {
  line(xobj,yobj-yheight,xobj+xwidth,yobj);
  line(xobj,yobj,xobj+xwidth,yobj-yheight);} }
void eaten(void)
 {sound(200);delay(350);sound(300);delay(350);sound(250);sleep(1);nosound();}
void getobj(int obj,int yobj,int ygheight,int gx)
 { sound(500);delay(50);nosound();
 setviewport(obj,yobj-ygheight,obj+radius/3,yobj,1);
 clearviewport();setviewport(0,0,getmaxx(),getmaxy(),1);/*setwritemode(1);
 line(getmaxx()/1.45,getmaxy()/1.49,getmaxx()/1.28,getmaxy()/1.49);setwritemode(0);*/
 drawobj(getmaxx()/100,getmaxy()/1.1,radius/3,ratio*radius/2,gx);}
void drawkeli(void)
 { int i;
 putimage(7.05*getmaxx()/8+0.5*radius,getmaxy()/9+0.9*ratio*radius,p,1);
 for(i=0;i<3;++i) {
 outtextxy(7.05*getmaxx()/8+0.9*radius,getmaxy()/9+0.19*ratio*radius,"HELP");
 sound(2000);delay(250); if(i==2) {nosound();break;}
 setviewport(7.05*getmaxx()/8+0.9*radius,getmaxy()/9+0.19*ratio*radius,7.05*getmaxx()/8+0.9*radius+textwidth("HELP"),getmaxy()/9+0.19*ratio*radius+0.7*textheight("HELP"),1);
 clearviewport();sound(100);delay(50);setviewport(0,0,getmaxx(),getmaxy(),1);
 nosound(); }}
void drawskala(void)
 {int gap;
  line(getmaxx()/15-radius,getmaxy()/1.785-1.1*ratio*radius,getmaxx()/15-radius,2.9*ratio*radius-5*getmaxy()/9+getmaxy()/1.785);
  line(getmaxx()/15+radius,getmaxy()/1.785-1.1*ratio*radius,getmaxx()/15+radius,getmaxy()/1.785+2.9*ratio*radius-5*getmaxy()/9);
 for(gap=ratio*radius;getmaxy()/1.785-1.1*ratio*radius-gap>getmaxy()/1.785+2.9*ratio*radius-5*getmaxy()/9;gap+=ratio*radius)
 line(getmaxx()/15-radius,getmaxy()/1.785-1.1*ratio*radius-gap,getmaxx()/15+radius,getmaxy()/1.785-1.1*ratio*radius-gap);
 }
void pushbutton(int px)
 { sound(300);
  setviewport(getmaxx()/100,getmaxy()/1.1-ratio*radius/2,getmaxx()/100+radius/3,getmaxy()/1.1,1);
  clearviewport(); setviewport(0,0,getmaxx(),getmaxy(),1);
  drawobj(getmaxx()/100,getmaxy()/1.1,radius/6,ratio*radius/2,px);delay(70);nosound();}
void getscala(void)
 { getimg(getmaxx()/15-radius,getmaxy()/1.785+2.9*radius*ratio-5*getmaxy()/9,2*radius,getmaxy()/1.785-1.1*ratio*radius,&r);
  putimage(getmaxx()/15-radius,getmaxy()/1.785+2.9*radius*ratio-5*getmaxy()/9,r,1);
  sound(90);delay(100);sound(45);delay(70);  nosound();}
void drawkey(void)
 { drawobj(getmaxx()/2-0.6*radius,getmaxy()/9+3.9*ratio*radius,0.4*radius,0.45*ratio*radius,0);
  line(getmaxx()/2-0.2*radius,getmaxy()/9+3.675*ratio*radius,getmaxx()/2+0.6*radius,getmaxy()/9+3.675*ratio*radius);
  line(getmaxx()/2+0.6*radius,getmaxy()/9+3.675*ratio*radius,getmaxx()/2+0.6*radius,getmaxy()/9+3.9*ratio*radius);
  line(getmaxx()/2+0.45*radius,getmaxy()/9+3.675*ratio*radius,getmaxx()/2+0.45*radius,getmaxy()/9+3.9*ratio*radius);}
void getkey(void)
 { putimage(getmaxx()/2-0.65*radius,getmaxy()/9+3.4*ratio*radius,s,1);
  sound(700);delay(50);nosound();}
void drawlaser(void)
 {setlinestyle(2,0,3);
  line(getmaxx()/2+0.75*radius,getmaxy()/1.495,getmaxx()/2+0.75*radius,getmaxy()/9+4*ratio*radius);
  sound(2000);delay(250);nosound();}
void drawgate(void)
 { sound(100); delay(100); setlinestyle(0,0,3); nosound();
 drawobj(getmaxx()/15-1.1*radius,getmaxy()/1.48,2.2*radius,getmaxy()/1.48-getmaxy()/1.785+1.2*ratio*radius,0);
 outtextxy(getmaxx()/15-0.6*radius,getmaxy()/1.785-1.2*ratio*radius-textheight("EXIT"),"EXIT");}
