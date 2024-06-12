#include "stdafx.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <string.h> 
#include <malloc.h> 
#include <clocale> 
#include <windows.h>
 
using namespace System; 
 
#define ENTER 13 
#define ESC 27 
#define UP 72 
#define DOWN 80 



 
 
struct z { 
 char coin[30]; 
 long price; 
 char bir[30]; 
 long cap; 
 char data[11]; 
}; 

struct sp { 
 char fio[20]; 
 long cap; 
 struct sp* sled;
 struct sp* pred;
} *spisok; 
 
int menu(int); 
void maxim(struct z*, int); 
void kolvo(struct z*, int); 
void alfalist(struct z*, int); 
void diagram(struct z*, int); 
void hard_question(struct z*, int);
void vstavka(struct z*, char*, int);
 
 
 
 
int main(array<System::String ^> ^args) 
{
	char dan[7][100] = { 
  "Какая самая дорогая монета на бирже Binance?         ", 
  "Сколько монет прошло листинг на бирже?               ", 
  "Есть ли у разных бирж монеты одинаковой цены         ", 
  "Алфавитный список                                    ", 
  "Диаграмма                                            ", 
  "Выход                                                " 
    }; 

char BlankLine[]="                                                       "; 
int NC;
 int i,n; 
 FILE *in; 
 struct z *clients = 0; 
 setlocale(LC_CTYPE,"Russian"); 
 Console::CursorVisible::set(false); 
 Console::BufferHeight=Console::WindowHeight; 
 Console::BufferWidth=Console::WindowWidth; 
 if((in=fopen("cripto.dat","r"))==NULL) 
 { 
  printf("\nФайл Vclad.dat не открыт !"); 
  getch(); exit(1); 
 } 
 fscanf(in,"%d",&NC); 
 clients=(struct z*)malloc(NC*sizeof(struct z)); 

 for(i=0;i<NC;i++) 
  fscanf(in,"%s%ld%s%ld%s",clients[i].coin, 
   &clients[i].price, clients[i].bir, 
   &clients[i].cap, 
   clients[i].data); 
 for(i=0;i<NC;i++) 
  printf("\n%-15s %-15ld %-15s %-15ld %s", 
   clients[i].coin, 
   clients[i].price, clients[i].bir, 
   clients[i].cap, 
   clients[i].data); 

 getch(); 
 ; 
 while(1)  
   {  
    Console::ForegroundColor=ConsoleColor::Gray;  
	Console::BackgroundColor=ConsoleColor::DarkMagenta;  
    Console::Clear();  
    Console::ForegroundColor=ConsoleColor::White;  
 Console::BackgroundColor=ConsoleColor::DarkGreen;  
    Console::CursorLeft=10;  
    Console::CursorTop=4;  
    printf(BlankLine);  
    for(i=0;i<6;i++)  
    {  
  Console::CursorLeft=10;  
  Console::CursorTop=i+5;  
  printf(" %s ",dan[i]);  
    }  
    Console::CursorLeft=10;  
    Console::CursorTop=11;  
    printf(BlankLine);  
   
    n=menu(6);  
    switch(n) {  
  case 1: maxim(clients, NC); break;  
  case 2: kolvo(clients, NC); break;  
  case 3: hard_question(clients, NC);break; 
  case 4: alfalist(clients, NC);break; 
  case 5: diagram(clients, NC);break; 
  case 6: exit(0);  
    }  
   }   
  
   
 return 0;  
}  
  
int menu(int n)  
{  
char dan[7][100] = { 
  "Какая самая дорогая монета на бирже Binance?         ", 
  "Сколько монет прошло листинг на бирже?               ", 
  "Есть ли у разных бирж монеты одинаковой цены         ", 
  "Алфавитный список                                    ", 
  "Диаграмма                                            ", 
  "Выход                                                " 
    }; 
 
char BlankLine[]="                                                       "; 

 int y1=0,y2=n-1;  
 char c=1;  
 while (c!=ESC)  
 {  
   switch(c) {  
   case DOWN: y2=y1; y1++; break;  
   case UP: y2=y1; y1--; break;  
   case ENTER: return y1+1;  
  }  
  if(y1>n-1){y2=n-1;y1=0;}  
  if(y1<0) {y2=0;y1=n-1;}  
  Console::ForegroundColor=ConsoleColor::White;  
  Console::BackgroundColor=ConsoleColor::Red;  
  Console::CursorLeft=11;  
  Console::CursorTop=y1+5;  
  printf("%s",dan[y1]);  
  Console::ForegroundColor=ConsoleColor::White;  
  Console::BackgroundColor=ConsoleColor::DarkGreen;  
  Console::CursorLeft=11;  
  Console::CursorTop=y2+5;  
  printf("%s",dan[y2]);  
  c=getch();  
 }; // конец while(c!=ESC)...  
 exit(0);  
};  
  
 
void maxim(struct z* client, int NC) 
{ 
int i=0; struct z best; 
strcpy(best.coin,client[0].coin); 
best.price=client[0].price; 
for(i=1;i<NC;i++) 
 if (client[i].price>best.price) 
 { 
 strcpy(best.coin,client[i].coin); 
 best.price=client[i].price; 
 } 
Console::ForegroundColor=ConsoleColor::Red; 
Console::BackgroundColor=ConsoleColor::Black; 
Console::CursorLeft=10; 
Console::CursorTop=15; 
printf("Самая дорогая монета %ld $",best.price);
Console::CursorLeft=10; 
Console::CursorTop=16; 
printf("Название монеты %s",best.coin); 
getch(); 
} 
 
  
void kolvo(struct z *client, int NC)
{
 int i,k=0;
 char birza[40];

 Console::ForegroundColor=ConsoleColor::Red;
 Console::BackgroundColor=ConsoleColor::Black;
 Console::Clear();

 printf("\n\tВведите название биржи: ");
 SetConsoleCP(1251);
 gets(birza);
 SetConsoleCP(866);


 for(i=0;i<NC;i++)
 if (strcmp(client[i].bir,birza)==0)
 k++;
 Console::ForegroundColor=ConsoleColor::Red;
 Console::BackgroundColor=ConsoleColor::Black;
 Console::CursorLeft=10;
 Console::CursorTop=15;
 printf("\n\tБиржа %s", birza);
 printf("\n\tВсего: %d монет, которыми можно торговать",k);
 getch();
}
 
void alfalist(struct z* client, int NC)
{
int i, n = 0;
struct sp* nt;
struct sp* z;
Console::ForegroundColor=ConsoleColor::Red;
Console::BackgroundColor=ConsoleColor::Black;
Console::Clear();
if(!spisok)
for(i=0;i<NC;i++)
vstavka(client,client[i].coin, NC);
Console::Clear();
printf("\n\t\t Алфавитный список и обратный список Монет");
printf("\n =================================================================================\n");



for(nt=spisok; nt!=0; nt=nt->sled)
printf("\n %-20s %ld",nt->fio,nt->cap);
for(nt = spisok, z=0; nt!=0; z=nt, nt = nt->sled);
for(nt=z;nt!=0;nt=nt->pred){
	Console::CursorLeft = 48;
	Console::CursorTop = 4+n;
	printf("%-20s %ld", nt->fio, nt->cap);
	n+=1;
}
getch();

}



void vstavka(struct z* client,char* fio, int NC)
{
int i;
struct sp *nov,*nt,*z=0;
for(nt=spisok; nt!=0 && strcmp(nt->fio,fio)<0; z=nt, nt=nt->sled);
	if(nt && strcmp(nt->fio,fio)==0) return;
		nov=(struct sp *) malloc(sizeof(struct sp));
strcpy(nov->fio,fio);
nov->cap=0;
nov->sled=nt;
nov->pred=z;
for(i=0;i<NC;i++){
	if(strcmp(client[i].coin,fio)==0)
		nov->cap+=client[i].cap;
		
}
if (!z) spisok = nov;
else z->sled=nov;
if(nt) nt->pred=nov;
nov->sled=nt;

return;
}

void diagram(struct z *client, int NC)
{
struct sp *nt;
int len,i,NColor,LEN;
long sum = 0 ;
char str1[30];
char str2[30];
System::ConsoleColor Color;
Console::ForegroundColor=ConsoleColor::Red;
Console::BackgroundColor=ConsoleColor::Black;
Console::Clear();
for(i=0;i<NC;i++) 
sum = sum+client[i].cap ;
if(!spisok)
 for(i=0;i<NC;i++)
  vstavka(client,client[i].coin, NC);
Color=ConsoleColor::Black; NColor=0;

for(i=0; i<NC; i++)
{
sprintf(str1,"%s",client[i].coin);
sprintf(str2,"%3.1f%%",(client[i].cap*100./sum));
Console::ForegroundColor=ConsoleColor::Red;
Console::BackgroundColor= ConsoleColor::Black;
Console::CursorLeft=5; Console::CursorTop=i+1;
printf(str1);
Console::CursorLeft=20;
printf("%s",str2);
Console::BackgroundColor=++Color; NColor++;
Console::CursorLeft=30;
LEN=client[i].cap*100./sum;
for(len=0; len<LEN; len++) printf(" ");
if(NColor==14)
{ Color=ConsoleColor::Black; NColor=0; }
}
getch();
return ;
}

void hard_question(struct z* client, int NC)
{
 int i,j;
 int flag = 0;
 Console::ForegroundColor=ConsoleColor::Red;
 Console::BackgroundColor=ConsoleColor::Black;
 Console::Clear();

 for(i=0;i<NC;i++)
 {
  for (j = i+1; j < NC; j++)
  {
   if (client[i].price == client[j].price)
   {
   printf("\n\tСтоимость монеты %s биржи %s равна стоимости монеты %s биржи %s",client[i].coin, client[i].bir, client[j].coin, client[j].bir);
   printf("\n\tЦена %ld \n", client[i].price);
   flag = 1;
   break;
   }
  }
  if (flag == 1) {break;}
 }
 if (flag == 0)
 {printf("Совпадений нет");}
 getch();
}
