#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;

class day
{
	public:
	void skipToDay (int d)
	{
        return skip(3*d);
    }


      void skip (int i)
	  {
        while (i > 0)
	   {
            cout << " ";
            i = i - 1;
        }
      }

   };

class month:public day
{
  	public:
    void printMonth (int numDays, int &weekDay)
	 {
        int day = 1;
        skipToDay(weekDay);
        //cout<<"\t";
        while (day <= numDays)
		 {
            cout<<setw(2)<<day<<" ";
            if (weekDay == 6)
			{
            	cout<<endl;//<<"\t";
                weekDay = 0;
            }
        	else weekDay = weekDay + 1;
       		day = day + 1;
        }
    }
};
class year:public month
{ public:
  int  firstDayofNewYearAndMonth(int year)
   {	//LOGIC TO CALULATE THE STARTING DATE AS 0,1,2,3,4,5,6
        int day_start;
        int x1, x2, x3;
        x1 = (year - 1)/ 4;
        x2 = (year - 1)/ 100;
        x3 = (year - 1)/ 400;
        day_start = (year + x1 - x2 + x3) %7;
        return day_start;
    }
    void printHeader (int m,int sleep)
	{
		if(sleep==0)
		{
		Sleep(1000);
		}
		else
		{
		Sleep(0);
		}
        if (m == 1)
	cout << "\tJANUARY" << endl;
    else if (m == 2) 
         cout << "\tFEBRUARY" << endl; 
    else if (m == 3) 
         cout << "\tMARCH" << endl; 
    else if (m == 4) 
         cout << "\tAPRIL" << endl; 
    else if (m == 5) 
         cout << "\tMAY" << endl; 
    else if (m == 6) 
         cout << "\tJUNE" << endl; 
    else if (m == 7) 
         cout << "\tJULY" << endl; 
    else if (m == 8) 
         cout << "\tAUGUST" << endl; 
    else if (m == 9) 
         cout << "\tSEPTEMBER" << endl; 
    else if (m == 10) 
         cout << "\tOCTOBER" << endl; 
    else if (m == 11) 
         cout << "\tNOVEMBER" << endl; 
    else if (m == 12) 
    	{    
		cout << "\tDECEMBER" << endl; 
		Sleep(1500);
		}
	cout << "_____________________"<<endl; //new design
    cout << "S  M  T  W  T  F  S" <<endl;
    cout << "_____________________" << endl;
	}                   
     int numOfDaysInAMonth (int m,int y)
	 {

        if (m == 1)
           return(31);
        else if (m == 2)
        {				//calculated for leap year
        	if(y%4==0)
        	{
			return(29);
        	}
			else
        	{
			return(28);
			}
        }
		else if (m == 3)
             return(31);
        else if (m == 4)
             return(30);
        else if (m == 5)
             return(31);
        else if (m == 6)
             return(30);
        else if (m == 7)
             return(31);
        else if (m == 8)
            return(31);
        else if (m == 9)
            return(30);
        else if (m == 10)
            return(31);
        else if (m == 11)
            return(30);
        else if (m == 12)
            return(31);
    }
};

class text		//getting the username and password
{
	public:
		int num;
		string name,pwd;
};
void printline()
{
	cout<<"*******************************************\n";
}
void printline1()
{
	cout<<"___________________________________________\n";
}
main()
{	
	system("color b0");	// light aqua with black font :-)
	//system("color F0");
	//system("mode 60,60");
//------------------------------------------------------------
// quote declaration
//quote
ifstream qin;
	qin.open("quote.txt");
	string q[10];




int qr=0;

int qo=0;

	while(!(qin.eof()))
	{
		getline(qin,q[qo]);
		qo++;
	}

qin.close();
//----------------------------------------------------------------
	//font size changed
	PCONSOLE_FONT_INFOEX console_info = new CONSOLE_FONT_INFOEX;
    console_info->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, console_info);
    console_info->dwFontSize.X = 24; //default 8
    console_info->dwFontSize.Y = 22; //default 12 
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, console_info);
//-----------------------------------------------------------------------------------------
//loading details
	int ll=0;		// ll refers to loading variable
	cout<<"\t\t\t\t\t\tLOADING APPLICATION:";
	for(ll=1;ll<=100;)
	{
		if(ll<10)
		{
		cout<<ll<<"%";
		Sleep(200);
		ll++;
		cout<<'\b';
		cout<<'\b';
		}
		if(ll>=10&&ll<=100)
		{
			cout<<ll<<"%";
			Sleep(50);
			ll++;
			cout<<'\b';
			cout<<'\b';
			cout<<'\b';
	    }
	}
//senthoraa senthoraa
//notification declaration
//*************************************
	string notname,notf;
	ofstream rfile;
    ifstream rfile1;
  	int notnum,usr;
//notifcation details  ends
//*************************************  
  
//*************************************
	int firstday,currentMonth,numDays,log=0;		//variables for displaying calener 
	year y;
	text t[100];	//object for account info
//*************************************
	//file functions
	ifstream fin;
	fin.open("accountinfo.txt",ios::app);		//predefined file which contains name and the password
//*************************************	
	string name,pwd;
	int count=0;
	//old place for time display 
	int i=0;
	int x;
x:	//goto function used for switch user
	count--;
	//new place
	//time (current ) functions	:-)
	time_t now = time(0);
	 tm *ltm = localtime(&now);
	// time claculation end :-*
//**************************************
	while(1)
	{    
		fin>>t[i].num;
		fin>>t[i].name;
		fin>>t[i].pwd;
		if(t[i].name=="END" || t[i].pwd=="END")
		{
			break;
		}
		++i;
    }
//---------------------------------------------------------
//ecofriend variables
	int ey,em;		// e represents that ecofriend
//----------------------------------------------------------
    //case 3 variabeles and file function
    int rmon,rday,ryr;
			string rs;
			ofstream fout;
			ifstream rfin;
			fout.open("remainder.txt",ios::app);
			rfin.open("remainder.txt");	
//----------------------------------------------------------
	//case 8 variables
				string de;
				fstream dfin;
				dfin.open("des.txt");
//----------------------------------------------------------
			
	//case 9 variabeles
	string pl="";
	    	int a=0;
	    	string dr;	//to display the remainder
//-----------------------------------------	
	string usrnm,pass;
	char ch;//to use ofr getch()
	char c='_';
	int check;
	//int count;
	int l=i;	//i-no.
	//goto function	for switch user
	cout<<"\n";
	system("c:\\aud\\welcome.wav");//welcome address audio
	printline();
//*********************************************
cout<<"\nWELCOME TO CALENDER APPLICATION\n";
	printline();
cout<<"\nKEEP YOUR PASSWORD SECURE\n";
	printline();
cout<<"\nUSERNAME:";
cin>>usrnm;
Sleep(550);
cout<<"\nPASSWORD:";
ch=_getch();
//going to disappear the tye text by * :P
while(ch != 13)
   {//character 13 is enter
      pass.push_back(ch);		//usage of push_back
      cout<<" ";				// like our telnet :P
      cout<<'\b';
      ch = _getch();
   }
//*********************************************
	cout<<"\n";
	printline();
	Sleep(300);
	cout<<"\n";
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
for(check=0;check<=l-1;check++)
{
	if((usrnm==t[check].name)&&(pass==t[check].pwd))
 	{
 	usr=check+1;
 	count=0;			//verification of login and details :-P
	}
}
if(count==0)
{
        cout<<"\nlogin success\n";
        // LOGGED IN DETAILS FOR TIME 
		cout<<"LOGGED IN AT : "<< ltm->tm_hour << ":";
   		cout << ltm->tm_min << ":";
   		cout << ltm->tm_sec << endl;	
   		Sleep(2500);
		//cout<<"\n"<<usr<<"\n";	
		int tyear,op;
//quote function
	 //quotes
	qr++;
	if(qr<6)
	{
	
		cout<<"\n**********************************************************************************";
			cout<<"\nQUOTE OF THE DAY:\n"; 
         	cout<<q[qr];
         	    cout<<"\n**********************************************************************************";
         	cout<<"\n";
    }
	 while(1)
     {        //__________________________________________
     	//system("CLS");		//clear screen
     	Sleep(750);
	 	printline1(); 
     	cout<<"|1 |.DISPLAY CALENDER FOR ANY YEAR          |\n";//<<endl;
		//printline1();
		cout<<"|2 |.ECOFRIEND OPTION                       |\n";
     	cout<<"|3 |.DISPLAY YOUR LOGGED IN  DATE AND TIME  |\n";//<<endl;
     	//printline1();
     	cout<<"|4 |.CHECK NOTIFICATION                     |\n";//"<<endl;
     	//printline1();
		cout<<"|5 |.SET REMAINDER FOR YOUR GROUP           |\n";//"<<endl;
		//printline1();  
     	cout<<"|6 |.SEND NOTIFICATION TO YOUR GROUP MEMBERS|\n";//"<<endl;
     	//printline1();
     	cout<<"|7 |.REMAINDER DETAILS OF THE GROUP         |\n";//"<<endl;
     	//printline1();
		cout<<"|8 |.SWITCH USER                            |\n";//"<<endl;
		cout<<"|9 |.DESCRIPTION                            |\n";
		//printlne1();
     	cout<<"|10|.CLOSE                                  |\n";//"<<endl;
     	printline();
     	Sleep(250);
     	
     	cout<<"\n\n ENTER YOUR OPTION : ";
	 	cin>>op;   
        switch(op)
        {
        case 1:				//display calender for any year
        cout<<"ENTER YEAR FOR DISPLAY CALENDER \n";
        cin>>tyear;
    
        firstday=y.firstDayofNewYearAndMonth(tyear);
      	 currentMonth=1;
      	
      		while (currentMonth <= 12)
		 {
        	 numDays = y.numOfDaysInAMonth(currentMonth,tyear);
       		 y.printHeader(currentMonth,0);
       		 y.printMonth(numDays, firstday);
        	cout <<endl<<endl<<endl;
        	currentMonth = currentMonth + 1;
         }

       	cout << endl;
       	Sleep(1000);
        break;
        //**********************************
        //ecofriend option 
        //i.e to specfic display of any month of the year gven by the user
        case 2:
        	cout<<"\nENTER THE YEAR TO SPECIFY THE MONTH\n";
        	cin>>ey;
    		cout<<"\nENTER MONTH FOR YOUR DISPLAY\n";
    		cin>>em;
			firstday=y.firstDayofNewYearAndMonth(ey);
			currentMonth=1;
			
			//cout<<"\n dai first day parru:"<<firstday<<endl;
			//firstday=firstday-3;//sample o/p
			while(currentMonth<=12)
			{
			numDays = y.numOfDaysInAMonth(currentMonth,ey);
      		
      		cout<<"\n";
      		if(currentMonth!=em)
      		{
      			y.printHeader(currentMonth,1);
      			y.printMonth(numDays, firstday);
      			system("CLS");
      			currentMonth=currentMonth+1;
			}
			else
			{
				cout<<"\nYEAR:"<<ey<<"\tMONTH:"<<em<<endl;
				printline();
				y.printHeader(currentMonth,1);
      			y.printMonth(numDays, firstday);
      			cout<<endl;
      			printline();
				//currentMonth=currentmonth+1;
				cout<<endl;
				break;	
			}
			}
      		break;
        //display of current year discovered
		case 3:		//current date ,year,month,day;
			cout<<"\n\n";
			cout<<"YOUR LOGGEDIN TIME AND DETAILS\n";
			printline();
			cout << "USERNAME:"<<usrnm<<"\t";
			cout << "DAY: "<<  ltm->tm_mday <<"\t";
			cout << "MONTH: "<< 1 + ltm->tm_mon<<"\t";
			cout << "YEAR:" << 1900 +ltm->tm_year<<endl;
   			cout << "\t\tTIME: "<< ltm->tm_hour << ":";
   			cout << ltm->tm_min << ":";
   			cout << ltm->tm_sec << endl;
   			printline();
   			Sleep(2000);
 		break;
 		
 		
 		case 4:
	    		//check notification
	    rfile1.open("notification.txt");
		cout<<"\n NOTIFICATIONS: \n";
		printline1();
		cout<<"SENDED BY|MESSAGE"<<endl;
		printline();
		 while(!(rfile1.eof()))
		 {
		 	//if(rfile1.eof())
		 	//break;
		 	rfile1>>notnum;
		 	//cout<<"notnum:"<<notnum<<endl;
		 	//	cin.ignore();
           
		    getline(rfile1,notf);
           	//rfile1>>notf;
           
            if(notnum==usr)
            {   
                
             	cout<<notf<<endl;
             	break;		//i will correct it
            }
	    }
		 	rfile1.close();
		 	Sleep(1500);
	    break;
	    
	    
		case 5://setting remainder
			
			cout<<"\nENTER DAY//MONTH//YEAR TO SET REMAINDER FOR YOUR GROUP\n";
			cout<<"DD/MM/YYYY:";cin>>rday;cin>>rmon;cin>>ryr;
			cout<<"\nENTER YOUR REMANINDER DETAILS FOR YOUR GROUP\n";
			cin.ignore();	//to new line
			getline(cin,rs);
			fout<<usrnm<<"\t\t"<<rday<<"\t"<<rmon<<"\t"<<ryr<<"\t"<<rs;
			    //REMAINDED BY   DAY  	MONTH  	YEAR  	DETAILS		 
			fout<<endl;
			break;
	    
		case 6:	//sending notification
			
			
			rfile.open("notification.txt",ios::app);
			cout<<"\nSENDING NOTIFICATION:\n";
   			cout<<"Enter name whom you you want to send notification:";
   			cin>>notname;
     		for(int j=0;j<i;j++)
      		{
        	 if(notname==t[j].name)
        	 {
            cout<<"\nEnter your message:\n";
            cin.ignore();
            getline(cin,notf);
           	rfile<<t[j].num<<" ";
            rfile<<usrnm<<"  ";
			rfile<<notf<<endl;
       		 }
       		/* else if(i>4)	//4 indicates that total number of account
       		 {
       		 cout<<"\nenter correct username :-P";
       		 Sleep(1000);
			 break;
       		 }*/	
			}
        rfile.close();
			break;
			
		case 7:	//to display the remainder details :-)
		cout<<"\t\tREMAINDER DETAILS\n";
		printline1();
		cout<<"REMAINDED BY   DAY  	MONTH  	YEAR  	DETAILS\n";
	   	printline();
		while(!(rfin.eof()))
	   	{
  		getline(rfin,dr);
		cout<<dr<<endl;		
		if(rfin.eof())
		break;
		}
		//cout<<"\n\n";
		Sleep(2500);
		break;
				
		case 8:	//switch user
			cout<<"_____________________________________________________________________________________________\n";
			cout<<"\t\t\t\t\t\t"<<usrnm<<"   BYE :-*\n ";
			cout<<"_____________________________________________________________________________________________\n";
			Sleep(2000);
			system("CLS");		// clear screen
			system("color 8F");
			//system("color F0");
			goto x;
	    break;
	    
	    case 9:
	    		system("CLS");
				while(!(dfin.eof()))
				{
				//cin.ignore();
				getline(dfin,de);
				cout<<de<<endl;
				Sleep(3000);
				}
				system("CLS");
				break;
	    case 10:	//close
	    	cout<<"_____________________________________________________________________________________________\n";
	    	cout<<"\t\t\t\t\tTHANKYOU FOR USING MY CALENDER \n";
	    	cout<<"_____________________________________________________________________________________________\n";
	    	Sleep(2000);
			cout<<usrnm<<" BYE :-* ";
		 	system("c:\\aud\\conclusion.wav");
	    	exit(0);
	    
	    
		default :
			cout<<"\n enter a valid option\n";
        }
}
}
	 else
        {
		cout<<"login failed\n\n\n";
		Sleep(2500);
		system("CLS");
		goto x;
		}
 }



