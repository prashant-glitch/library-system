#include<bits/stdc++.h>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
gotoxy(int x,int y)
{
	cout<<setw(x);
	for(;y>0;y--)
	cout<<endl;
}
class book{
	char bno[10];
	char bname[50];
	char aname[20];
	public:
		void createbook()
		{
			cout<<"\n new book entry....\n";
			cout<<"\n enter the book number"<<endl;
			cin>>bno;
			cout<<"\n enter the book name"<<endl;
			fflush(NULL);
			gets(bname);
			cout<<"\n enter the book auther's name"<<endl;
			gets(aname);
			cout<<endl<<"book created!!!"<<endl;
		}
		void showbook()
		{
			cout<<"\nbook number:: "<<bno;
			cout<<"\nbook name:: ";
			puts(bname);
			cout<<"\nauther name:: ";
			puts(aname);
		}
		void modifybook()
		{
			cout<<"\n book number: "<<bno;
			cout<<"\n modify book name"<<endl;
			gets(bname);
			cout<<"\nmodify authers name"<<endl;
			gets(aname);
			
		}
		char* returnbno()
		{
			return bno;//return book number
		}
		void report()
		{
			cout<<bno<<setw(10)<<bname<<setw(10)<<aname<<endl;
		}
};
//book class ends here


//*******************************************************************************************
class student{
	char admno[10];//roll number of student
	char name[20];//student name
	char stbno[6];//which book student has issued
	int token;//total no od books students have
	public:
		void createstudent()
		{
			system("CLS");
			cout<<"\nnew student entery...."<<endl;
			cout<<"\nenter admission number\n";
			cin>>admno;
			fflush(NULL);
			cout<<"\nenter student name\n";
			gets(name);
			fflush(NULL);
			token=0;
			stbno[0]={0};
			cout<<"\n\nstudent record created..."<<endl;
		}
		void showstudent()
		{
			cout<<"\nadmission number: "<<admno;
			cout<<"\nstudent name:  ";
			puts(name);	
			cout<<"\nNo of book issued: "<<token;
			if(token==1)
			cout<<"\n book number: "<<stbno;
		}
		void modifystudent()
		{
			cout<<"\nadmission number: "<<admno;
			cout<<"\nmodify student name : "<<endl;
			gets(name);
		}
		char* returnadmno()
		{
			return admno;
		}
		char* resbno()
		{
			return stbno;
		}
		int rettoken()
		{
			return token;
		}
		void gettocken()
		{
			token=1;
		}
		void resettoken()
		{
			token=0;
		}
		void getstbno(char t[])
		{
			strcpy(stbno,t);
		}
		void report()
		{
			cout<<"\t"<<admno<<setw(10)<<name<<setw(10)<<token<<endl;
		}
};
//student class ended
//FILE HANDLING WORK FROM HERE

///**********************************************************************************************
//FILE                   HANDLING

fstream fp,fp1;
book bk;
student st;
void writebook()
{
	char ch;
	fp.open("book.dat",ios::out|ios::in);
	do{
		system("CLS");
		bk.createbook();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\ndo you want to add more record (y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

///*******************************************************************************************
///studen        file handling
void writstudent()
{
	char ch;
	fp.open("student.dat",ios::out|ios::in);
	do{
		system("CLS");
		st.createstudent();
		fp.write((char*)&st,sizeof(student));
		cout<<"\ndo you want to add more record (y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
///*************************************************************************************
//specific book ko kaise read karna hai
void displayspb(char n[])
{
	cout<<"\nbook details"<<endl;
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read ((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.returnbno(),n)==0)
		{
			bk.showbook();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"book does not exit"<<endl;
}
//*******************************************************************************************
//kaise kisi specific student ko read kr skate hai
void displaysps(char n[])
{
	cout<<"\nstudent details"<<endl;
	int flag=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char *)&st,sizeof(student)))
	{
		if(strcmpi(st.returnadmno(),n)==0)
		{
			st.showstudent();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"student does not exit"<<endl;
}
//*********************************************************************************************
//modify book
void modifybook()
{
	char n[6];
	int found =0;
	system("cls");
	cout<<"\nmodify book record"<<endl;
	cout<<"\nenter the book number"<<endl;
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book))&&found==0)
	{
		if(strcmpi(bk.returnbno(),n)==0)
		{
			bk.showbook();
			cout<<"enter new details of book"<<endl;
			bk.modifybook();
			int pos=-1*sizeof(bk);fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(book));
			cout<<"\n\nrecord updated"<<endl;
			found=1;
		}
	}
	fp.close();
	if(found==0)
	cout<<"\n\n record not found"<<endl;
}
//**************************************************************
//student modify
void modifystudent()
{
	char n[6];
	int found =0;
	system("cls");
	cout<<"\nmodify student record"<<endl;
	cout<<"\nenter the admission number"<<endl;
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student))&&found==0)
	{
		if(strcmpi(st.returnadmno(),n)==0)
		{
			st.showstudent();
			cout<<"enter new details of student"<<endl;
			st.modifystudent();
			int pos=-1*sizeof(st);fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\nrecord updated"<<endl;
			found=1;
		}
	}
	fp.close();
	if(found==0)
	cout<<"\n\n record not found"<<endl;
}
//**********************************************************************
//delete student
void deletestudent()
{
	char n[10];
	int flag=0;
	system("cls");
	cout<<"\n\ndelete student\n";
	cout<<"\nenter the admission no\n";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("temp.dat",ios::out);
	fp.seekg(0,ios::beg);///kha se file kholna hai like begning;
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.returnadmno(),n)!=0)
		{
			fp2.write((char*)&st,sizeof(student));
		}
		else
		{
			flag=1;
		}
	}
	
	if(flag==1)
	{
		cout<<"\n\nrecord deleted\n";
	}
	else
	{
		cout<<"\n\nrecrod not found\n";
	}
	fp2.close();
	fp.close();
	delete("student.dat");
	rename("temp.dat","student.dat");
}
////**********************************************************************************************************
//delete     booookkkkkkk
void deletebook()
{
	char n[10];
	int flag=0;
	system("cls");
	cout<<"\n\ndelete book\n";
	cout<<"\nenter the book no\n";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("temp.dat",ios::out);
	fp.seekg(0,ios::beg);///kha se file kholna hai like begning;
	while(fp.read((char*)&st,sizeof(book)))
	{
		if(strcmpi(st.resbno(),n)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
		else
		{
			flag=1;
		}
	}
	
	if(flag==1)
	{
		cout<<"\n\nrecord deleted\n";
	}
	else
	{
		cout<<"\n\nrecrod not found\n";
	}
	fp2.close();
	fp.close();
	delete("book.dat");
	rename("temp.dat","book.dat");
}

//**************************************************************************************************************************
//    show all student

void displayalls()
{
	system("cls");
	fp.open("student.dat",ios::in);
	if(!fp)
	{
		cout<<"file could not open"<<endl;
		return;
	}
	cout<<"\n\nstudent list:::\n";
	cout<<"\n-----------------------------------------------------------------------------------------------\n";
	cout<<"\tadmission no"<<setw(10)<<"name"<<setw(20)<<"book issued\n";
	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}
	fp.close();	
}
//**************************************************************************************************************************
//    show all book

void displayallb()
{
	system("cls");
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"file could not open"<<endl;
		return;
	}
	cout<<"\n\nbook list:::\n";
	cout<<"\n-----------------------------------------------------------------------------------------------\n";
	cout<<"\t book no"<<setw(10)<<"book name"<<setw(20)<<"book author\n\n";
	while(fp.read((char*)&bk,sizeof(book)))
	{
		st.report();
	}
	fp.close();	
}
//****************************************************************************************************************
//book issue 
void bookissue()
{
	char sn[10],bn[10];
	int found =0,flag=0;
	system("cls");
	cout<<"\n\nbook issue::  \n";
	cout<<"enter student admission no.....\n";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student))&&found==0)
	{
		if(strcmpi(st.returnadmno(),sn))
		{
			found=1;
			if(st.rettoken()==0)
			{
				cout<<"\n\nenter boo number.:: \n";
				cin>>bn;
				while(fp.read((char*)&st,sizeof(student))&&flag==0)
				{
					if(strcmpi(bk.returnbno(),bn)==0)
					{
						flag=1;
						st.gettocken();
						st.getstbno(bk.returnbno());
						int pos=-1*sizeof(st);
						fp.seekg(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\nbook issued successfully\n";
						
					}
				}
				if(flag==0)
				{
					cout<<"book number does not exit\n";
				}
			}
			else
			{
				cout<<"you have not returened the last book\n\n";
			}
		}
	}
	if(found==0)
	{
		cout<<"student record not exit\n";
	}
	fp.close();
	fp1.close();
}
//*****************************************************************************************************************
//book deposite
void bookdeposite()
{
	int day,fine;
	char sn[10],bn[10];
	int found =0,flag=0;
	system("cls");
	cout<<"\n\nbook deposite::  \n";
	cout<<"enter student admission no.....\n";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student))&&found==0)
	{
		if(strcmpi(st.returnadmno(),sn))
		{
			found=1;
			if(st.rettoken()==1)
			{
				while(fp.read((char*)&st,sizeof(student))&&flag==0)
				{
					if(strcmpi(bk.returnbno(),st.resbno())==0)
					{
						flag=1;
						bk.showbook();
						cout<<"\n\nbook deposited in no of days\n";
						cin>>day;
						if(day>15)
						{
							fine=day-15;
							cout<<"\n fine has to be deposited rs. "<<fine;
						}
						st.resettoken();
						int pos=-1*sizeof(st);
						fp.seekg(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\nbook deposited  successfully\n";
						
					}
				}
				if(flag==0)
				{
					cout<<"book number does not exit\n";
				}
			}
			else
			{
				cout<<"no bok is issued\n\n";
			}
		}
	}
	if(found==0)
	{
		cout<<"student record not exit\n";
	}
	fp.close();
	fp1.close();
}

void start()
{
gotoxy(50,1);
cout<<"LIBRARY MANAGEMENT SYSTEM";

cout<<"\n\nDeveloper : Prashant kumar\n";
}
void adminmenu(){
	system("cls");
	char ch2;
	cout<<endl<<"administration menu"<<endl;
	cout<<"1. create student record"<<endl;
	cout<<"2. display student report"<<endl;
	cout<<"3. display specific student record"<<endl;
	cout<<"4. display specific student record"<<endl;
	cout<<"5. delete student record"<<endl;
	cout<<"6. create book"<<endl;
	cout<<"7. display all book"<<endl;
	cout<<"8. display specific book"<<endl;
	cout<<"9. modify book record"<<endl;
	cout<<"10. delete book record"<<endl;
	cout<<"11. back to main menu"<<endl;
	cout<<"please enter your choice 1-11"<<endl;
	cin>>ch2;
	switch(ch2)
	{
	case '1':
	writstudent();
	break;
	case '2':
	displayalls();
	case '3':
	char num;
	cout<<"enter roll number"<<endl;
	cin>>num;
	displaysps(&num);
	break;
	case '4':
	modifystudent();
	break;
	case '5':
	deletestudent();
	break;
	case '6':
	writebook();
	break;
	case '7':
	displayallb();
	break;
	case '8':
	 int n;
	cout<<"enter roll number"<<endl;
	cin>>n;
	displayspb(&num);
	break;
	case '9':
	modifybook();
	break;
	case '10':
	deletebook();
     break;
	case '11':
    return;
	default:
	cout<<"invalid choice try again"<<endl;	 
}
	adminmenu();
}
int main()
{
	system("cls");
	char ch;
    start();
    do{
    	cout<<"main menu"<<endl;
    	cout<<"01. book issue\n";
    	cout<<endl<<"02. book deposite\n";
    	cout<<endl<<"03. administration menu\n";
    	cout<<endl<<"04. exit\n";
    	cout<<endl<<"please select your option between 1-4\n";
    	ch=getche();
    	switch(ch)
    	{
    		case '1': 
    		bookissue();
    		break;
    		case '2':
      		bookdeposite();
    		break;
    		case '3':
      		adminmenu();
    		break;
    		case '4':
      		exit(0);
    		break;
    		default:
    			gotoxy(50,1);
    			cout<<endl<<"invalid choice"<<endl;
		}
	}while(ch!=4);
    return 0;
}
