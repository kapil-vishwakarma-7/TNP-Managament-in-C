#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#define user "kapil1"
#define pass "kapil2"

/**
Project : Training & Placement Management
Developed By Kapil Vishwakarma.
Computer Science and Engineering
2nd Year.
Sagar Institue of Science Technology and Engineering

*/


FILE * f1 ;

struct mdate{
int dd,mm,yy;
};

struct student {
float package;
char name[30],branch[3],city[20],placement[20],roll[13];
int sem;
};                 //structure for student
struct company{
struct mdate date;
char name[15],type[4],post[10];
int vacancy,selection;
float package;
};
struct event{
char name[30],type[15],review[50];
struct mdate date;
int duration;

};
//Function Declarations
void acess();
void login();
void header(char *);
int menu();
void addStudent();
void showStudent();
void removeStudent();
void addCompanyRec();
void showCompanyRec();
void event();
void companyList();
void updateStudent();
void loading(int,int);
void loadPage();
void status();
void about();


void main(int argc , const char * argv[]){
char username[7],password[7];
	if(argc == 2){  //if Arguments are Passed to main function
		if(strcmp(argv[1],"login")==0){
		 clrscr();
			printf("Enter UserName : ");scanf("%s",&username);
			printf("Enter Password : ");scanf("%s",&password);
		 if(strcmp(username,user) == 0 && strcmp(password,pass) == 0)
		 loading(0,1);
		 acess();
		}
	}
	else{
	loading(1,3);
	getch();
  }
}

void about(){
int i;
clrscr();
textcolor(WHITE);
gotoxy(20,5);for(i=1;i<40;i++) cprintf("*");
gotoxy(25,6);cprintf("Training & Placement Management");
gotoxy(26,12);cprintf("Developed By Kapil Vishwakarma");
gotoxy(36,13);cprintf("Branch CSE");
gotoxy(16,15);cprintf("Sagar Institute of Science, Technlogy & Engineering");
gotoxy(26,14);cprintf("Guided By Prof. Umesh Kumar Sahu");
getch();
}



void loading(int pm,int r)
{
 int x,y,i,j,c,e;
 int g=DETECT, d;
 char *per=NULL;
 initgraph(&g, &d,"C:\\TURBOC3\\BGI");
 setcolor(9);
 outtextxy(10,450,"Training & Placement Management");
 outtextxy(385,450,"Developed by Kapil Vishwakarma");
 setviewport(150,130,600,400,1);
 setcolor(3);
 delay(1);
 for( i=0;i<r;i++)
 {
   c=150;
   for(j=0;j<50;j++)
	  {
	    sprintf(per,"%d\%",j);
	    clearviewport();
	    circle(170,120,2*150-c--+30);
	    circle(170,120,2*150%c+30);
	    settextstyle(TRIPLEX_FONT,0,5);
	    outtextxy(100,100,"Loading");
	    settextstyle(SMALL_FONT,0,5);
	    outtextxy(170,150,per);
	    delay(1);
	  }
}
 closegraph();
 if(pm) login();

}

void login(){
int i=50,j;
char c,username[20],password[20];
clrscr();

textcolor(RED);gotoxy(9,10);cprintf("\xDB\xDB");textcolor(WHITE+BLINK);cprintf("Login ");textcolor(2);while(i--) cprintf("\xDB");
textcolor(WHITE+BLINK);gotoxy(15,13);cprintf("Username : ");
textcolor(WHITE);gotoxy(15,15);cprintf("Password : ");
textcolor(WHITE);gotoxy(2,25);cprintf("Developed By Kapil Vishwakarma");
textcolor(WHITE);gotoxy(45,25);cprintf("Training & Placement Management");
gotoxy(26,13);scanf("%s",&username);
textcolor(GREEN);gotoxy(15,13);cprintf("Username : ");
textcolor(WHITE+BLINK);gotoxy(15,15);cprintf("Password : ");

gotoxy(26,15);
i=0;
while((c = getch()) != 13){
	printf("*");
	password[i] = c;
	i++;
}
password[i] = '\0';
textcolor(GREEN);gotoxy(15,15);cprintf("Password : ");
if(strcmp(username,user) == 0 && strcmp(password,pass) == 0){
	 clrscr();
	 textcolor(GREEN+BLINK);gotoxy(30,16);cprintf("Acess Granted. ");
	 delay(1300);
	 acess();
 }
 else{
	 clrscr();
	 textcolor(RED+BLINK); gotoxy(30,16);cprintf("Acess Denied........");
	 getch();
 }

}


void acess(){
int ch=1;
char * sem;

while(ch != 10){
  ch = menu();
  switch(ch){
	  case 1:
		addCompanyRec();
		break;
	  case 2:
		showCompanyRec();
		break;
	  case 3:
		showStudent("all");
		break;
	  case 4:
		addStudent();
		break;
	  case 5:
		updateStudent();
		break;
	  case 6:
		removeStudent();
		break;
	  case 7:
		event();
		break;
	  case 8:
		status();
		break;
	  case 9:
		about();
		break;
	  case 10:
		exit(0);

	  case 11:
		showStudent("all");
		break;
	  case 12:
		companyList();
		break;
	  case 13:
		showStudent("placed");
		break;
	  case 14:
		showStudent("no");
		break;
	  case 15:
		gotoxy(50,15);cprintf("Enter Sem : ");scanf("%s",sem);
		showStudent(sem);
	  break;
	  case 16:
		break;
	  default :
		clrscr();
		cprintf("enter Correct Oprion.");
		getch();

 }
}
}

void header(char msg[] ){
int i;
textcolor(BLUE);gotoxy(1,1);for(i=0;i<79;i++) cprintf("\xDB");
textcolor(WHITE+BLINK);gotoxy(32,1);cprintf("%s",msg);
textcolor(WHITE);
}

int showStudentMenu(){
int select=1;
char ch=1;
	do{
	  textcolor(WHITE);
	  switch(ch){
	    case 80://down
	    if(select == 6)
	    select=1;
	    else
	    select++;
	    break;
	    case 72: //up
	     if(select == 1)
	       select=6;
	     else
	       select--;
	    break;

	  }
	  textbackground(BLACK);
	  gotoxy(50,8);cprintf("1.All Student.");
	  gotoxy(50,9);cprintf("2.By Comapany Selection..");
	  gotoxy(50,10);cprintf("3.Placed Student.");
	  gotoxy(50,11);cprintf("4.Not Placed Student.");
	  gotoxy(50,12);cprintf("5.Sem wise Student");
	  gotoxy(50,13);cprintf("6.Hide.");
	  textbackground(RED);

	  switch(select){
	  case 1:
		gotoxy(50,8);cprintf("1.All Student.");
		break;
	  case 2:
	  	gotoxy(50,9);cprintf("2.By Comapany Selection..");
	  	break;
	  case 3:
	  	gotoxy(50,10);cprintf("3.Placed Student.");
	  	break;
	  case 4:
	  	gotoxy(50,11);cprintf("4.Not Placed Student.");
		break;
	  case 5:
		gotoxy(50,12);cprintf("5.Sem wise Student");
		break;
	  case 6:
	  	gotoxy(50,13);cprintf("6.Hide.");
		break;
	  }

	  }while((ch = getch()) != 13);
   textbackground(BLACK);
   return 10+select;
}

int menu(){
int ch,ch1,select=1;
char c=0;

clrscr();
header("Dashboard");
textbackground(BLACK);

do{
textbackground(BLACK);
switch(c){
	 case 72:    //ASCII value For UP Arrow Key
	   if(select == 1 ) select =10;
	   else select--;
	   break;

	case 80: //down
	   if(select == 10) select=1;
	   else select++;
       break;
	case 75://left
	   break;
	case 77://right
	   break;
	case '1':
	  return 1;
	case '2':
	  return 2;
	case '3':
	  return 3;
	case '4':
	  return 4;
	case '5':
	  return 5;
	case '6':
	  return 6;
	case '7':
	  return 7;
	case '8':
	  return 8;
	case '9':
	  return 9;
	case '0':
	  return 10;
	}

 if(select == 1){
  textcolor(RED+BLINK);gotoxy(50,22);cprintf("USE ARROW KEYS");
 }
else{
  textcolor(WHITE);gotoxy(50,22);cprintf("              ");
}


textbackground(BLACK);
textcolor(WHITE);gotoxy(20,4);cprintf("\xDB\xDB\xB2 1.Add Company Recurtement.");
textcolor(WHITE);gotoxy(20,6);cprintf("\xDB\xDB\xB2 2.Show Company Recurtement.");
textcolor(WHITE);gotoxy(20,8);cprintf("\xDB\xDB\xB2 3.show students List.");
textcolor(WHITE);gotoxy(20,10);cprintf("\xDB\xDB\xB2 4.Add Student.");
textcolor(WHITE);gotoxy(20,12);cprintf("\xDB\xDB\xB2 5.Update Placement Status.");
textcolor(WHITE);gotoxy(20,14);cprintf("\xDB\xDB\xB2 6.Remove Student.");
textcolor(WHITE);gotoxy(20,16);cprintf("\xDB\xDB\xB2 7.Event.");
textcolor(WHITE);gotoxy(20,18);cprintf("\xDB\xDB\xB2 8.Status.");
textcolor(WHITE);gotoxy(20,20);cprintf("\xDB\xDB\xB2 9.About.");
textcolor(WHITE);gotoxy(20,22);cprintf("\xDB\xDB\xB2 10.Exit.");
textcolor(WHITE);gotoxy(20,24);cprintf("Choice : %d ",select);
//gotoxy(29,22);scanf("%d",&ch);
textbackground(BLUE);
switch(select){
case 1:textcolor(WHITE);gotoxy(20,4);cprintf("\xDB\xDB\xB2 1.Add Company Recurtement.");
	   break;
case 2:textcolor(WHITE);gotoxy(20,6);cprintf("\xDB\xDB\xB2 2.Show Company Recurtement.");
	   break;
case 3:textcolor(WHITE);gotoxy(20,8);cprintf("\xDB\xDB\xB2 3.show students List.");
	   break;
case 4:textcolor(WHITE);gotoxy(20,10);cprintf("\xDB\xDB\xB2 4.Add Student.");
	   break;
case 5:textcolor(WHITE);gotoxy(20,12);cprintf("\xDB\xDB\xB2 5.Update Student Status.  ");
	   break;
case 6:textcolor(WHITE);gotoxy(20,14);cprintf("\xDB\xDB\xB2 6.Remove Student.");
	   break;
case 7:textcolor(WHITE);gotoxy(20,16);cprintf("\xDB\xDB\xB2 7.Event.");
	   break;
case 8:textcolor(WHITE);gotoxy(20,18);cprintf("\xDB\xDB\xB2 8.Status.");
	   break;
case 9:textcolor(WHITE);gotoxy(20,20);cprintf("\xDB\xDB\xB2 9.About.");
	   break;
case 10:textcolor(WHITE);gotoxy(20,22);cprintf("\xDB\xDB\xB2 10.Exit.");
	   break;
}

}while((c = getch()) != 13);
 textbackground(BLACK);
 if(select == 3)
   select = showStudentMenu();
return select;
}





void addStudent(){
int i;
char c;
struct student st,st1;
while(1){
	clrscr();
	i=40;
	textbackground(BLACK);
	textcolor(RED);gotoxy(9,5);cprintf("\xDB\xDB");textcolor(WHITE);cprintf("Student Information");textcolor(2);while(i--) cprintf("\xDB");
	textcolor(WHITE);gotoxy(15,7);cprintf("Enrollment Number ");
	textcolor(WHITE);gotoxy(15,9);cprintf("Name  ");
	textcolor(WHITE);gotoxy(15,11);cprintf("City :  ");
	textcolor(WHITE);gotoxy(15,13);cprintf("Branch ");
	textcolor(WHITE);gotoxy(15,15);cprintf("Semester  ");
	textcolor(WHITE);gotoxy(15,17);cprintf("Placement Status  ");

	gotoxy(34,7);scanf("%s",&st.roll);
	gotoxy(34,9);scanf("\n%[^\n]",&st.name);
	gotoxy(34,11);scanf("%s",&st.city);
	gotoxy(34,13);scanf("%s",&st.branch);
	gotoxy(34,15);scanf("%d",&st.sem);
	gotoxy(34,17);scanf("\n%[^\n]",&st.placement);
	if(strcmp("NO",st.placement) != 0 && strcmp("no",st.placement) != 0){
	  textcolor(WHITE);gotoxy(15,19);cprintf("Package ");
	  gotoxy(34,19);scanf("%f",&st.package);
	  }

	f1 = fopen("data.dat","ab+");
	 while(fread(&st1,sizeof(st1),1,f1) == 1){
		  if( strcmp(st.roll,st1.roll) == 0){
		  textcolor(RED);cprintf("\nStudent Already Exist..");
		  getch();
		  return;
	  }

	}
	 fwrite(&st,sizeof(st),1,f1);
	fclose(f1);
	textcolor(GREEN+BLINK);gotoxy(25,22);cprintf("Student Added. Press Y to Add more.");
	textcolor(WHITE);
	   c = getch();
	   if(!(c == 'y' || c == 'Y'))  break;

}

}

void showStudent(char condition[]){
struct student st[100],temp,t1;
int i=1,j,k=1,flag;
char ch;
clrscr();
f1 = fopen("data.dat","rb");
if(f1 == NULL)  {
  printf("\nFile Cannot Open!!!!!");
  getch();
  return;
}
header("Student List ");
rewind(f1);
textbackground(BLACK+BLINK);
for(i=1;fread(&temp,sizeof(temp),1,f1) == 1;i++){
  for(j=i-1; j>=0 && strcmp(temp.roll,st[j].roll) < strcmp(st[j].roll,temp.roll) ; j--)
  st[j+1] = st[j];

 st[j+1] = temp;

}

fclose(f1);
textbackground(BLACK);
textcolor(WHITE);gotoxy(1,3);cprintf("Enrollment No.");
textcolor(WHITE);gotoxy(17,3);cprintf("Name of student");
textcolor(WHITE);gotoxy(40,3);cprintf("Semester");
textcolor(WHITE);gotoxy(50,3);cprintf("Branch");
textcolor(WHITE);gotoxy(58,3);cprintf("Placement");
textcolor(WHITE);gotoxy(70,3);cprintf("Package");
j=1;
while(1){
   flag = 0;
   if(strcmp("all",condition) == 0){
     temp = st[j]; flag=1;
   }
   else if(strcmp(condition,"placed") == 0){

      if(strcmp("NO",st[j].placement) != 0 )
	 {temp = st[j];flag=1;}

   }else if(strcmp(condition, "no") == 0){

      if(!strcmp(st[j].placement,"NO"))
	 {temp = st[j]; flag=1;}


   }else if((condition[0]-48) < 9 || (condition[0]-48) > 0){
	 if((condition[0]-48) == st[j].sem )
	  {temp = st[j];flag = 1;}
   }
   if(flag && j < i){
	   textcolor(WHITE);gotoxy(1,3+k);cprintf("%s",temp.roll);
	   textcolor(WHITE);gotoxy(17,3+k);cprintf("%s",temp.name);
	   textcolor(WHITE);gotoxy(43,3+k);cprintf("%d",temp.sem);
	   textcolor(WHITE);gotoxy(52,3+k);cprintf("%s",temp.branch);
	   textcolor(WHITE);gotoxy(58,3+k);cprintf("%s",temp.placement);
	   textcolor(WHITE);gotoxy(70,3+k);cprintf("%.1f",temp.package);
	   k++;
   }
   if(k > 20 && (j > 0 && j<= i)){
    ch =  getch();
     if(ch == 72)//up
     {
	  j -= k;
	  k = 1;
     }
     else if(ch == 80) //down
     {
      j -=20;
      k = 1;
     }
     else if(ch == 13){
     return;
     }
     clrscr();
     header("Student List");
     textcolor(WHITE);gotoxy(1,3);cprintf("Enrollment No.");
     textcolor(WHITE);gotoxy(17,3);cprintf("Name of student");
     textcolor(WHITE);gotoxy(40,3);cprintf("Semester");
     textcolor(WHITE);gotoxy(50,3);cprintf("Branch");
     textcolor(WHITE);gotoxy(58,3);cprintf("Placement");
     textcolor(WHITE);gotoxy(70,3);cprintf("Package");

   }
j++;
if( j > i || j < 0) {
  ch = getch();
  if(ch == 13) return;
 }
}
}

void addCompanyRec(){
int i;
struct company com;
char *name;
clrscr();
header("Add Recrutement");
textcolor(WHITE);gotoxy(10,4);cprintf("Date (DD MM YYYY)");
textcolor(WHITE);gotoxy(10,6);cprintf("Company Name ");
textcolor(WHITE);gotoxy(10,8);cprintf("Company type");
textcolor(WHITE);gotoxy(10,10);cprintf("Postion Name");
textcolor(WHITE);gotoxy(10,12);cprintf("Vacancy");
textcolor(WHITE);gotoxy(10,14);cprintf("Package");
textcolor(WHITE);gotoxy(10,16);cprintf("Number of selection");
gotoxy(30,4);scanf("%d%d%d",&com.date.dd,&com.date.mm,&com.date.yy);
gotoxy(30,6);scanf("\n%[^\n]",&com.name);
gotoxy(30,8);scanf("%s",&com.type);
gotoxy(30,10);scanf("%s",&com.post);
gotoxy(30,12);scanf("%d",&com.vacancy);
gotoxy(30,14);scanf("%f",&com.package);
gotoxy(30,16);scanf("%d",&com.selection);
f1 = fopen("companylist.dat","ab+");
fwrite(&com,sizeof(com),1,f1);
fclose(f1);
clrscr();

 header("Selected Students");;
 f1 = fopen(strcat(com.name,".dat"),"ab+");
 gotoxy(1,4);cprintf("Enter Name");
 for( i=0;i<com.selection;i++){
   gotoxy(12,4+i);scanf("\n%[^\n]",name);
    fwrite(name,30,1,f1);

 }
 fclose(f1);

getch();
}

void showCompanyRec(){
int i=1;
struct company com;
clrscr();
header("Comapny Rec");

textcolor(WHITE);
textbackground(BLACK);
gotoxy(1,3);cprintf("SN.");
gotoxy(6,3);cprintf("Date");
gotoxy(16,3);cprintf("Company name");
gotoxy(35,3);cprintf("Post Name");
gotoxy(49,3);cprintf("selection");
gotoxy(60,3);cprintf("Vacancy");
gotoxy(70,3);cprintf("Package");
f1 = fopen("companylist.dat","ab+");
rewind(f1);
while(fread(&com,sizeof(com),1,f1) == 1){
	gotoxy(1,4+i);printf("%d",i);
	gotoxy(4,4+i);printf("%d.%d.%d",com.date.dd,com.date.mm,com.date.yy);
	gotoxy(16,4+i);printf("%s",com.name);
	gotoxy(37,4+i);printf("%s",com.post);
	gotoxy(53,4+i);printf("%d",com.selection);
	gotoxy(64,4+i);printf("%d",com.vacancy);
	gotoxy(72,4+i);printf("%.1f",com.package);
    i++;
  }
getch();
}

void event(){
struct event ev;
int select=1,j=1;
char ch=1;
clrscr();
header("EVENTS of T&P");
do{
	switch(ch){
	case 72://up
	if(select > 1 && select <= 4) select--;
	else
	select = 4;
	break;
	case 80: //down
	if(select < 4) select++;
	else
	select = 1;
	break;
	}

textcolor(WHITE);gotoxy(20,4);cprintf("\xDB\xDB\xB2 1.Create Event.");
textcolor(WHITE);gotoxy(20,6);cprintf("\xDB\xDB\xB2 2.View Events.");
textcolor(WHITE);gotoxy(20,8);cprintf("\xDB\xDB\xB2 3.Back");
textcolor(WHITE);gotoxy(20,10);cprintf("\xDB\xDB\xB2 4.Exit.");
textcolor(WHITE);gotoxy(20,12);cprintf("Choice :%d ",select);

textbackground(GREEN);
switch(select){
case 1:
textcolor(WHITE);gotoxy(20,4);cprintf("\xDB\xDB\xB2 1.Create Event.");
break;
case 2:
textcolor(WHITE);gotoxy(20,6);cprintf("\xDB\xDB\xB2 2.View Events.");
break;
case 3:
textcolor(WHITE);gotoxy(20,8);cprintf("\xDB\xDB\xB2 3.Back");
break;
case 4:
textcolor(WHITE);gotoxy(20,10);cprintf("\xDB\xDB\xB2 4.Exit.");
break;
}

textbackground(BLACK);
}while((ch = getch()) != 13);

f1 = fopen("event.dat","ab+");
switch(select){
int i;
char c;
case 1:
       //create Event
       clrscr();
       header("create a Event");
       textcolor(WHITE);
	gotoxy(3,3);cprintf("Event Name : ");
	gotoxy(3,5);cprintf("Event Date : ");
	gotoxy(3,7);cprintf("Event Type : ");
	gotoxy(3,9);cprintf("Event Duration(Days) : ");
	gotoxy(3,11);cprintf("Event Review :(max 50) ");
	gotoxy(25,3);scanf("\n%[^\n]",&ev.name);
	gotoxy(25,5);scanf("%d%d%d",&ev.date.dd,&ev.date.mm,&ev.date.yy);
	gotoxy(25,7);scanf("%s",&ev.type);
	gotoxy(25,9);scanf("%d",&ev.duration);
	gotoxy(25,11);scanf("\n%[^\n]",&ev.review);
	if(fwrite(&ev,sizeof(ev),1,f1) == 1){
	 textcolor(GREEN);cprintf("Insertion Successful..");
	}

break;
case 2:
  clrscr();
  header("Events List");
  textcolor(WHITE);
  printf("\n");

  while(fread(&ev,sizeof(ev),1,f1) ==  1){
   printf("\n\n%d.%d.%d",ev.date.dd,ev.date.mm,ev.date.yy);
   printf("\t\t\tEVENT NAME : %s",ev.name);
   printf("\nTYPE : %s",ev.type);
   printf("\t\t  DURATION : %d %s",ev.duration,(ev.duration > 1)? "days" : "day");
   printf("\nREVIEW : %s\n",ev.review);
   for(i=0;i<70;i++)
    cprintf("_");
    j++;
    if(j > 4){
     c = getch();
    if(c == 13){ break ;}
     else if(c == 80){clrscr(); j = 1;}
    }
  }
  getch();
break;
case 3:
break;
case 4:
exit(0);
}

fclose(f1);

}
void companyList(){
struct company com;
int i=1,ch;
char* names[50];
char *name;
f1 = fopen("companylist.dat","ab+");
clrscr();
if(f1 == NULL){printf("File Cannot Open"); return;}
header("Companies List");
rewind(f1);
textcolor(WHITE);
while(fread(&com,sizeof(com),1,f1) == 1){
 name = (char *) malloc(sizeof(com.name));
 strcpy(name,com.name);
 names[i] =  name;
 gotoxy(4,3+i);printf("%d. %s",i,com.name);
 i++;
}
fclose(f1);
printf("\n\nEnter Choice : ");scanf("%d",&ch);
f1 = fopen(strcat(names[ch],".dat"),"ab+");
 clrscr();
 header(names[ch]);
 i=1;
 if( f1 == NULL){printf("Cannot Open file ");return;}
 while(fread(name,30,1,f1) == 1){
 gotoxy(3,2+i);printf("%d. %s",i,name);
 i++;
 }
 fclose(f1);
getch();

}
void updateStudent(){
char roll[13];
struct student st;
int flag=0;
clrscr();
header("Update Student");
gotoxy(2,3);cprintf("Enter EnrollNumber : ");
gotoxy(23,3);scanf("%s",&roll);
f1 = fopen("data.dat","rb+");
rewind(f1);
while(fread(&st,sizeof(st),1,f1) == 1){
  int size = sizeof(st);
  if(strcmp(st.roll,roll) == 0)
    {
      gotoxy(4,5);cprintf("Enter Company name :");
      gotoxy(4,7);cprintf("Enter Package      :");
      gotoxy(25,5);scanf("\n%[^\n]",&st.placement);
      gotoxy(25,7);scanf("%f",&st.package);

      fseek(f1,-size,SEEK_CUR);
      fwrite(&st,size,1,f1);
      flag=1;
      break;
    }

}
fclose(f1);
if(flag){
 textcolor(GREEN);cprintf("\nUpdatation Done.");
}
else {
 textcolor(RED);cprintf("\nRecord Not Found.");
}
 getch();
}


void status(){
int companyvisit=0,total=0,placed=0,events=0,i=0;
float package=0.0f;
struct company com;
struct event ev;
struct student st;
f1 = fopen("companylis.dat","rb+");
   rewind(f1);
  while(fread(&com,sizeof(com),1,f1) == 1){
   companyvisit++;
  }
fclose(f1);

 f1 = fopen("event.dat","rb+");
 rewind(f1);
while(fread(&ev,sizeof(ev),1,f1) == 1){
 events++;
}
fclose(f1);

f1 = fopen("data.dat","rb+");
while(fread(&st,sizeof(st),1,f1) == 1 ){
 if(strcmp("NO",st.placement)) placed++;
  total++;
 if(package  < st.package)
   package = st.package;
}

 clrscr();
 header("\xDBStatus");
 textcolor(WHITE);
 gotoxy(3,4);cprintf("Total Students : %d ",total);
 gotoxy(3,6);cprintf("Placed Students : %d ",placed);
 gotoxy(3,8);cprintf("Not Placed Students : %d ",total-placed);
 gotoxy(3,10);cprintf("No. of Events : %d ",events);
 gotoxy(3,12);cprintf("Total company visit: %d ",companyvisit);
 gotoxy(3,14);cprintf("Highest Placement Package: %.1f ",package);

while(i<total){
 textcolor(BLUE);gotoxy(15+i,20);cprintf("\xDB");
 textcolor(BLUE);gotoxy(15+i,21);cprintf("\xDB");
 i++;
}

i=0;
while(i<placed){
 textcolor(GREEN);gotoxy(15+i,20);cprintf("\xDB");
 textcolor(GREEN);gotoxy(15+i,21);cprintf("\xDB");
 i++;
}

getch();

}

void removeStudent(){
struct student st;
int i,flag;
char str[13];
FILE * f2;
clrscr();
header("Remove Student");
gotoxy(3,4);cprintf("Enter Enrollment Number : ");
gotoxy(28,4);scanf("%s",&str);
f1 = fopen("data.dat","rb");
f2 = fopen("newdata.dat","wb+");
rewind(f1);
while(fread(&st,sizeof(st),1,f1) == 1){
  if(strcmp(st.roll,str) != 0){
    fwrite(&st,sizeof(st),1,f2);
  }
  else{
   flag=1;
  }

}
 fclose(f1);
 fclose(f2);
 remove("data.dat");
 rename("newdata.dat","data.dat");
if(flag == 1)
{
 textcolor(GREEN+BLINK);cprintf("\nRecord Deleted Successful.");
}
else{
 textcolor(RED+BLINK);cprintf("\nRecord Not Found.");}
 getch();
}
