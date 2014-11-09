#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct player
{
int a[10],secretno,attempts;
char name[20],result;
}p1,p2;

void welcome()
{
clrscr();
gotoxy(25,21);/*used to put pointer to a specific location of screen*/
cout<<"THIS IS A NUMBER GUESSING GAME.";
gotoxy(18,23);
cout<<"GUESS THE CORRECT NUMBER BEFORE OTHER PLAYER.";
gotoxy(26,25);
cout<<"WISH U ALL THE BEST....... :-)";
getch();
}
void p1turn()
{
randomize();
cout<<"\n\t\t It's "<<p1.name<<"'s turn\n\n";
cout<<"Try to guess a number from 1 to 1000";
p1.secretno=random(1000)+1;
int i=0;
do
{
cout<<"\nEnter the no"<<i+1<<":    ";
cin>>p1.a[i];
if(p1.a[i]<p1.secretno)
{
if(p1.a[i]+10>=p1.secretno)
cout<<"Your entered no. is smaller but u are very close";
else
cout<<"No. you entered is very small";
}
else if(p1.a[i]>p1.secretno)
{
if(p1.a[i]<=p1.secretno+10)
cout<<"Your entered no. is greater but u are very close";
else
cout<<"Your no. is very big";
}
else if(p1.a[i]==p1.secretno)
{
cout<<"CONGURATULATIONS YOU HAVE GUESSED THE CORRECT NUMBER";
p1.attempts=i+1;
getch();
break;
}
if(i==9)
{
cout<<"\nOh........u just missed it.\n you lost.correct number was"<<p1.secretno;
p1.attempts=i+1;
}
i++;
}
while(i<10);
}

void p2turn()
{
randomize();
cout<<"\n\n\n\n\n\t\tNOW it's "<<p2.name<<"'s turn\n\n";
cout<<"Try to guess a number from 1 to 1000";
p2.secretno=random(1000)+1;
int i=0;
do
{
cout<<"\nEnter the no"<<i+1<<":    ";
cin>>p2.a[i];
if(p2.a[i]<p2.secretno)
{
if(p2.a[i]+10>=p2.secretno)
cout<<"Your entered no. is smaller but u are very close";
else
cout<<"No. you entered is very small";
}
else if(p2.a[i]>p2.secretno)
{
if(p2.a[i]<=p2.secretno+10)
cout<<"Your entered no. is greater but u are very close";
else
cout<<"Your no. is very big";
}
else if(p2.a[i]==p2.secretno)
{
cout<<"CONGURATULATIONS YOU HAVE GUESSED THE CORRECT NUMBER";
p2.attempts=i+1;
getch();
break;
}
if(i==9)
{
cout<<"\nOh........u just missed it.\n you lost.correct number was"<<p2.secretno;
p2.attempts=i+1;
}
i++;
}
while(i<10);
}
void game()
{
clrscr();
char b[20];
cout<<"\nEnter name of player 1:     " ;
gets(b);
for(int z=0;z<=strlen(b);z++)
p1.name[z]=toupper(b[z]);
cout<<"\nEnter name of player 2:     " ;
gets(b);
for(z=0;z<=strlen(b);z++)
p2.name[z]=toupper(b[z]);
cout<<"Now press any key to start the game......";
getch();
clrscr();
p1turn();
p2turn();
if(p1.attempts<p2.attempts)
{
p1.result='w';
p2.result='l';
int w=(p2.attempts-p1.attempts);
cout<<"\n"<<p1.name<<" won by "<<w<<" attempts.";
}
else if(p1.attempts>p2.attempts)
{
p2.result='w';
p1.result='l';
int w=(p1.attempts-p2.attempts);
cout<<"\n"<<p2.name<<" won by "<<w<<" attempts.";
}
else if(p1.attempts==p2.attempts)
{
p1.result='d';
p2.result='d';
cout<<"\n This match is a draw.";
}
fstream fout("game.ank",ios::binary|ios::app);
fout.write((char*)&p1,sizeof(p1));
fout.write((char*)&p2,sizeof(p2));
fout.close();
}

void showdetails()
{
clrscr();
cout<<"\n Enter name of player whose details you want to see:";
char b[20];
gets(b);
for(int z=0;z<=strlen(b);z++)
b[z]=toupper(b[z]);
int p=1;
player s;
fstream fin("game.ank",ios::binary|ios::in);
if(!fin)
{
cout<<"File does not exist!!!!!!!";
getch();
exit(0);
}
while(fin.read((char*)&s,sizeof(s)))
{
if(strcmp(s.name,b)==0)
{
cout<<"\n\nMATCH "<<p<<":\n";
cout<<"Number player had to guess was: "<<s.secretno;
cout<<"\nValues he entered were: ";
for(int i=0;i<s.attempts;i++)
{
cout<<s.a[i]<<"  ";
}
cout<<"\n Result of this game was ";
{
if(s.result=='w')
cout<<"WINNER :-)";
else if(s.result=='l')
cout<<"LOOSER  :-(";
else if(s.result=='d')
cout<<"DRAW  :-@";
}
p++;
}
}
if(p==1)
{
cout<<"\nNo player with name entered found ";
}
fin.close();
}

void showall()
{ clrscr();
int p=1;
player r,s;
fstream fin("game.ank",ios::binary|ios::in);
if(!fin)
{
cout<<"File does not exist!!!!!!!!";
getch();
exit(0);
}
while(fin.read((char*)&r,sizeof(r)) && fin.read((char*)&s,sizeof(s)))
{
cout<<"\n\nGAME "<<p<<":\n";
cout<<"Game no. "<<p<<"  was between "<<r.name<<" $ "<<s.name<<"\n";
cout<<"\n\t"<<r.name<<" got 1st turn\nHe had to guess the no. : "<<r.secretno;
cout<<"\nValues he entered were: ";
for(int i=0;i<r.attempts;i++)
{
cout<<r.a[i]<<"  ";
}
cout<<"\n\n\t"<<s.name<<" got 2nd turn\nhe had to guess the no. : "<<s.secretno;
cout<<"\nValues he entered were: ";
for(i=0;i<s.attempts;i++)
{
cout<<s.a[i]<<"  ";
}
cout<<"\n\nClearly result of this game was ";
if(r.attempts<s.attempts)
{
int w=(s.attempts-r.attempts);
cout<<"\n"<<r.name<<" won by "<<w<<" attempts.:-)";
}
else if(r.attempts>s.attempts)
{
int w=(r.attempts-s.attempts);
cout<<"\n"<<s.name<<" won by "<<w<<" attempts.:-)";
}
else if(r.attempts==s.attempts)
{
cout<<"\n This match was a draw.:-@";
}
cout<<"\n\n\n";
p++;
}
fin.close();
}

void main()
{
welcome();

int i;
char c='y';
do
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\t\t\t\tMENU:\n\t\t\t1. PLAY GAME\n\t\t\t2. SHOW DETAILS OF ALL PLAYERS\n\t\t\t3. SHOW DETAILS OF A SPECIFIC PLAYER(BY NAME)\n\t\t\t4. EXIT\n\n";
cout<<"\n\tEnter option of your choice:  ";
cin>>i;
switch(i)
{
case 1:game();
	break;
case 2:showall();
	break;
case 3:showdetails();
	break;
case 4:
	clrscr();
	gotoxy(32,19);
	cout<<"GAME MADE BY:";
	gotoxy(33,22);
	cout<<"ANKIT GARG";
	getch();
	exit(0);
	break;
default:cout<<"wrong input";
	continue;
}
cout<<"\n\nDo you want to continue(Y/N)...........";
cin>>c;
}while(toupper(c)=='Y');
getch();
clrscr();
gotoxy(32,19);
cout<<"GAME MADE BY:";
gotoxy(33,22);
cout<<"ANKIT GARG";
getch();
}



