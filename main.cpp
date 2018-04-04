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
		int aUserId ,apwd ,counter_login;
	public:
		core_panel()
		{
		counter_login=0;
		} 
		void main_menu();
		void cust_login();
		void admin_login();
		void check_login();
		void admin_panel();
		void dr_details();
		void charge();
		void facilities();
		void help();
		void about_us();
//		void read_pInfo();
//		void add_pInfo();
//		void add_dr();
//		void dlt_all();
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
	
		if(admin_user_id == aUserId && admin_pass == apwd)
	{
		admin_panel();
	}
	else
	{
		frame();
		++counter_login;
		if(counter_login == 3)
		{
			flow("You Have Exceeded The Limit And The Database Is Shutting Down...",25,15);
			Sleep(10);
			exit(1);
		}
		flow("You Have Entered Wrong Credentials.",30,15);
		flow("Press Any Key To Go To Main Menu...",30,16);
		getchar();
		getchar();
		main_menu();
	}
	
}
void core_panel::admin_panel()
{
	frame();
	flow("------------------ADMIN PANEL------------------",30,15);
	flow("1.Show Patient Info",30,17);
	flow("2.Add Patient Info",30,18);
	flow("3.Add New Doctor's Information",30,19);
	flow("4.Clear All The Information In The Database.",30,20);
	flow("5.Display The Details Of All The Doctors",30,21);
	flow("6.LogOut",30,22);
	flow("7.Exit",30,23);
	flow("Enter Your Choice...",30,24);
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
//				read_pInfo();
				admin_panel();
				break;
			}
		case 2:
			{
//				add_pInfo();
				admin_panel();
				break;
			}
		case 3:
			{
//				add_dr();
				admin_panel();
				break;
			}
		case 4:
			{
//				dlt_all();
				admin_panel();
				break;
			}
		case 5:
			{
//				dr_details();
				admin_panel();
				break;
			}
		case 6:
			{
				frame();
				flow("You Have Succesfully Logged out..",30,50);
				flow("Please Wait While We Redirect You To Main Menu",30,51);
				Sleep(300);
				main_menu();
			}
		case 7:
			{
				exit_scr();
				break;
			}
		default :
			{
				frame();
				flow("You Have Entered Wrong Choice...",30,20);
				flow("Press any key to go back to Customer Page...",30,22);
				getchar();
				getchar();
				admin_panel();
			}
	}
}
void core_panel::cust_login()
{
	frame();
	flow("------------------CUSTOMER PAGE------------------",30,15);
	flow("1.Show Available Doctors And There Specialization.",30,16);
	flow("2.Our Charges",30,17);
	flow("3.Availabe Facilities.",30,18);
	flow("4.Help",30,19);
	flow("5.About US",30,20);
	flow("6.Exit",30,21);
	flow("Enter Your Choice... ",30,24);
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: 
			{
			dr_details();
			cust_login();
			break;
		    }
		case 2:
			{
			charge();
			cust_login();
			break;
			}
		case 3:
			{
			facilities();
			cust_login();
			break;
			}
		case 4:
			{
			help();
			cust_login();
			break;
			}
		case 5:
			{
			about_us();
			cust_login();
			break;
			}
		case 6:
			{
			exit_scr();
			break;	
			}
		default :
			{
				frame();
				flow("You Have Entered Wrong Choice...",30,20);
				flow("Press any key to go back to Customer Page...",30,22);
				getchar();
				getchar();
				cust_login();
			}
	}
}
////void core_panel::add_pInfo()
//{
//	int name, age;
////	fstream file;
////	file.open("Patient_Info.txt",ios::app);
//	
//}
void core_panel::about_us()
{
	system("COLOR FC");
	ifstream fin;
    fin.open("AboutUs.txt");
    char ch; 
    while(fin)
    {
       
        fin.get(ch);
        cout<<ch;
    }
    getchar();
    getchar();
    fin.close();
}
void core_panel::help()
{
	system("COLOR FC");
	ifstream fin;
    fin.open("Help.txt");
    char ch; 
    while(fin)
    {
       
        fin.get(ch);
        cout<<ch;
    }
    getchar();
    getchar();
    fin.close();
}
void core_panel::facilities()
{
	system("COLOR FC");
	ifstream fin;
    fin.open("Facilities.txt");
    char ch; 
    while(fin)
    {
       
        fin.get(ch);
        cout<<ch;
    }
    getchar();
    getchar();
    fin.close();
}
void core_panel::charge()
{
	system("COLOR FC");
	ifstream fin;
    fin.open("Charge.txt");
    char ch; 
    while(fin)
    {
       
        fin.get(ch);
        cout<<ch;
    }
    getchar();
    getchar();
    fin.close();	
}
void core_panel::dr_details()
{
	system("COLOR FC");
	ifstream fin;
    fin.open("Doctor_Details.txt");
    char ch; 
    while(fin)
    {
       
        fin.get(ch);
        cout<<ch;
    }
    getchar();
    getchar();
    fin.close();
}
void core_panel::admin_login()
{
	frame();
	flow("------------------ADMIN LOGIN------------------",30,15);
	flow("User Id : ",45,17);
	cin>>aUserId;
	flow("Enter Password : ",45,18);
	cin>>apwd;
	check_login();
}
char* display_panel::date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;		//Returns local time and date
}
inline void display_panel::frame()
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
			gotoxy(88,1);
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
		case 1: cust_login(); break;
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
inline int display_panel::flow(string s,int x,int y)
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
