#include "header_files.h"
using namespace std;

//Global Function Prototyping
void gotoxy(int,int);

//Class Declaration 
class display_panel;
class core_panel;

//Class Defination.
class display_panel{
	public:
		void frame(); //Frame Size (110,40)
		void welcome_display();
		int flow(string s,int x ,int y);
		void exit_scr();
		char *date_time();	
		int visitor_counter();

}disp;

class core_panel:public display_panel{
	private:
		int user_id ;
		int pwd;
	public:
		void main_menu();
		void cust_page();
		void admin_login();
		void check_login();
		void admin_panel();
}core;

//Member Function Defination

int display_panel::visitor_counter()
{
	int v;
	fstream file("Visitor_Counter.dll",ios::in);
	while(file)
	{
	file>>v;
    }
	file.close();
	++v;
	fstream file1("Visitor_Counter.dll",ios::out);
	file1<<v;
	file1.close();
	return v;
}
void core_panel::check_login()
{
	if(admin_user_id == user_id && admin_pass == pwd)
	{
		admin_panel();
	}
	else
	{
		frame();
		flow("You Have Entered Wrong Credentials.",30,15);
		flow("Press Any Key To Go To Main Menu...",30,16);
		getchar();
		main_menu();
	}
}
void core_panel::admin_panel()
{
	frame();
	flow("------------------ADMIN PANEL------------------",30,15);
//	flow("1.Add ");
}
void core_panel::cust_page()
{
	frame();
	flow("------------------CUSTOMER PAGE------------------",30,15);
	flow("1.    :  ",45,17);
	cin>>user_id;
	flow("Enter Password  :  ",45,18);
	cin>>pwd;
	flow("Exit ",45,19);
	flow("Enter Your Choice : ",45,21);
	
}
void core_panel::admin_login()
{
	frame();
	flow("------------------ADMIN LOGIN------------------",30,15);
	flow("User Id : ",45,17);
	cin>>user_id;
	flow("Enter Password : ",45,18);
	cin>>pwd;
	check_login();
}
char* display_panel::date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;		//Returns local time and date
}
void display_panel::frame()
{
			system("cls");
			system("COLOR FC");
			for(int i=1;i<=39;i++)
			{
				gotoxy(110,i);
				Sleep(1);
				cout<<"|";
				gotoxy(0,i);
				Sleep(1);
				cout<<"|";
			}
			for(int i=0;i<=110;i++)
			{
				gotoxy(i,0);
				Sleep(1);
				cout<<"|";
				gotoxy(i,40);
				Sleep(1);
				cout<<"|";
			}
			string c="Powered By InkedImpression.com .";
				
			gotoxy(1,39);
			cout<<c;
			
			gotoxy(1,1);
			char s[20];
			strcpy(s,date_time());
			cout<<s;
			int v;
			v=visitor_counter();
			string d="Visitor Counter --: ";
			gotoxy(89,1);
			cout<<d<<v;
}
void display_panel::welcome_display()
{
			frame();
			string a="Welcome To Community Health Care Management System.";
			string b="Developed By : Manas Bhardwaj | 11704118.";
			string c="Press Any Key To Continue.. ";
			int x=a.length();
			int y=b.length();
			int z=c.length();
			for(int i=0 ,j=30; a[i]!='\0' && j<=30+x ;i++,j++)
			{
				gotoxy(j,20);
				Sleep(10);
				cout<<a[i];
			}	
			PlaySoundA(TEXT("welcome.wav"), NULL, SND_SYNC);
			for(int k=0 ;b[k]!='\0';k++)
			{
				gotoxy(k+35,21);
				Sleep(10);
				cout<<b[k];
			}
			for(int m=0;c[m]!='\0';m++)
			{
				gotoxy(m+40,22);
				Sleep(10);
				cout<<c[m];
			}
			getchar();
}
void core_panel::main_menu()
{

	frame();
	flow("------------------MAIN MENU------------------",30,15);
	flow("1.Customer Page ",45,17);
	flow("2.Admin Login ",45,18);
	flow("3.Exit ",45,19);
	PlaySoundA(TEXT("mainmenu.wav"), NULL, SND_SYNC);
	flow("Enter Your Choice : ",45,21);
	int x;
	cin>>x;
	switch(x){
		case 1: cust_page(); break;
		case 2: admin_login(); break;
		case 3: exit_scr(); break;
		default:
		{
		flow("Please Enter Correct Choice. ",45,23);
		getchar();
		getchar();
		main_menu();
		}
	}
	getchar();	
}
int display_panel::flow(string s,int x,int y)
{
	for(int k=0 ;s[k]!='\0';k++)
			{
				gotoxy(k+x,y);
				Sleep(1);
				cout<<s[k];
			}	
	//getchar();
}
void display_panel::exit_scr()
{
	int msgboxID = MessageBox(NULL,"Do You Want To Exit?","Exit Window",MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON1);
	switch (msgboxID)
    {
    case IDYES:
	frame();
	flow("THANK YOU.!",45,20);
	PlaySoundA(TEXT("thankyou.wav"), NULL, SND_SYNC);
	getchar();
	getchar();
	exit(1);        
    break;
    case IDNO:
    welcome_display();    
    break;
    }

}
int main()
{
	core.welcome_display();
	core.main_menu();
	return 0;
}

//Global Function Declaration
void gotoxy (int x, int y)		//Gotoxy Defination And Declaration.
{
    COORD coord;
	coord.X = x;				//X Coordinates.
    coord.Y = y;				//Y Coordinates.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
