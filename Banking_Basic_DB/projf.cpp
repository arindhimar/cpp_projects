/*
 * projf.cpp
 *
 *  Created on: 19-Sep-2022
 *      Author: root
 */

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


int no=11011;
class database{
protected:
	int acc_no,bal;
	char name[20],locality[20];

public:

	void menu()
	{
		cout<<"\nMAIN MENU";
		cout<<"\n1 - ADMIN";
		cout<<"\n2 - USER";
		cout<<"\n3 - EXIT";
	}

	void setacc()
	{
		fstream fin;
		fin.open("temp.dat",ios::in|ios::binary);

		fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{
			fin.read((char *)this,sizeof(*this));
		}
		no=++acc_no;
		fin.close();
	}

};

class admin:public database{
public:


	void createdet()
	{
		acc_no=no++;
		cout<<"\nAccount Number Allocated = 	"<<acc_no;
		cout<<"\nEnter Account Holder Name 		";
		cin>>name;
		cin.ignore();
		cout<<"\nEnter Account Holder Locality 	";
		cin>>locality;
		cin.ignore();
		cout<<"\nEnter Account Balace (bal>=500 && bal<=5000)";
		cin>>bal;
	}

	void create()
	{
		createdet();
		ofstream fout;
		fout.open("temp.dat",ios::app|ios::binary);
		fout.write((char *)this,sizeof(*this));
		fout.close();
	}

	void disp()
	{
		ifstream fin;
		fin.open("temp.dat",ios::in|ios::binary);

		fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{
			cout<<"\nACCOUNT NO			:		"<<acc_no;
			cout<<"\nACCOUNT NAME			:		"<<name;
			cout<<"\nACCOUNT LOCALITY		:		"<<locality;
			cout<<"\nACCOUNT BALANCE			:		"<<bal<<endl;

			fin.read((char *)this,sizeof(*this));
		}

	}

	void del()
	{
		int tep;
		cout<<"\nEnetr account number to delete		";
		cin>>tep;
		fstream fin,fin2;
		int pos;
		fin.open("temp.dat",ios::in|ios::binary);
		fin2.open("temp2.dat",ios::app|ios::binary);

		int tval;
		fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{

			if(acc_no!=tep)
			{
				fin2.write((char *)this,sizeof(*this));
			}
			fin.read((char *)this,sizeof(*this));	
		}
		fin.close();
		fin2.close();

		remove("temp.dat");
		rename("temp2.dat","temp.dat");
	}


	void menu()
	{
		cout<<"\nADMIN MENU";
		cout<<"\n1 - CREATE ACCOUNT";
		cout<<"\n2 - DISPLAY ALL ACCOUNT";
		cout<<"\n3 - SEARCH ACCOUNT";
		cout<<"\n4 - DELETE ACCOUNT";
		cout<<"\n5 - RETURN TO MAIN MENU";		
	}

	void search()
	{
		ifstream fin;
		fin.open("temp.dat",ios::in|ios::binary);
		int tep;
		cout<<"\nEnetr account number to search		";
		cin>>tep;
		fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{
			if(acc_no==tep)
			{
				cout<<"\nACCOUNT NO			:		"<<acc_no;
				cout<<"\nACCOUNT NAME			:		"<<name;
				cout<<"\nACCOUNT LOCALITY		:		"<<locality;
				cout<<"\nACCOUNT BALANCE			:		"<<bal<<endl;
				break;
			}
			fin.read((char *)this,sizeof(*this));
		}

	}

	


};

class user:public database{
public:

	void menu()
	{
		cout<<"\nUSER MENU";
		cout<<"\n1 - DISPLAY ACCOUNT";
		cout<<"\n2 - DEPOSIT MONEY";
		cout<<"\n3 - WITHDRAW MONEY";
		cout<<"\n4 - RETURN TO MAIN MENU";		
	}
	void disp(int tep)
	{
		fstream fin;
		fin.open("temp.dat",ios::in|ios::binary);
		cout<<tep;

		fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{
			if(acc_no==tep)
			{

				cout<<"\nACCOUNT NO			:		"<<acc_no;
				cout<<"\nACCOUNT NAME			:		"<<name;
				cout<<"\nACCOUNT LOCALITY		:		"<<locality;
				cout<<"\nACCOUNT BALANCE			:		"<<bal<<endl;
				break;
			}

				fin.read((char *)this,sizeof(*this));
		}
	}

	void deposit(int tep)
	{
		fstream fin,fin2;
		int pos;
		fin.open("temp.dat",ios::in|ios::binary);
		fin2.open("temp2.dat",ios::app|ios::binary);

		int tval;
		fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{

			if(acc_no==tep)
			{
				cout<<"\nEnter amount to deposit	";
				cin>>tval;
				bal=bal+tval;
				fin2.write((char *)this,sizeof(*this));
			}
			else
			{
				
				fin2.write((char *)this,sizeof(*this));
			}
			fin.read((char *)this,sizeof(*this));
			
		}
		fin.close();
		fin2.close();

		remove("temp.dat");
		rename("temp2.dat","temp.dat");
	}


	void withdraw(int tep)
	{
		fstream fin,fin2;
		int pos;
		fin.open("temp.dat",ios::in|ios::binary);
		fin2.open("temp2.dat",ios::app|ios::binary);

		int tval;
		fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{

			if(acc_no==tep)
			{
				cout<<"\nEnter amount to withdraw	";
				cin>>tval;
				if(tval<=bal)
				{
					bal=bal-tval;
					
				}
				else
				{
					cout<<"\nNot Enough Balance";
				}
				fin2.write((char *)this,sizeof(*this));
			}
			else
			{
				
				fin2.write((char *)this,sizeof(*this));
			}
			fin.read((char *)this,sizeof(*this));	
		}
		fin.close();
		fin2.close();

		remove("temp.dat");
		rename("temp2.dat","temp.dat");
	}



	int verify(int tep)
	{
		ifstream fin;
		fin.open("temp.dat",ios::in|ios::binary);

		fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{
			if(acc_no==tep)
			{
				return 1;
			}
			fin.read((char *)this,sizeof(*this));
		}
		return 0;

	}

};



int main()
{

	database d;
	admin a;
	user u;

	int opt;

	d.setacc();



	db:
	do
	{	
		d.menu();
		cout<<"\nWANT TO LOGIN AS		";
		cin>>opt;
		switch(opt)
		{
			case 1:
			goto addb;
			break;
			case 2:
			goto usdb;
			break;
			case 3:
			exit(0);
			default:
			cout<<"\nINVAID MAIN MENU OPTION";
		}

	}while(opt!=3);

	addb:
	do
	{	
		a.menu();
		cout<<"\nSELECT ADMIN MENU OPTION		";
		cin>>opt;
		switch(opt)
		{
			case 1:
			a.create();
			break;
			case 2:
			a.disp();
			break;
			case 3:
			a.search();
			break;
			case 4:
			a.del();
			break;
			case 5:
			goto db;
			break;
			default:
			cout<<"\nINVAID MAIN MENU OPTION";
		}

	}while(opt!=5);

	int tacc,t;
	usdb:

	cout<<"\nEnter Account Number To Login		";
	cin>>tacc;

	t=u.verify(tacc);
	if(t==0)
	{
		cout<<"\nACCOUNT NUMBER NOT FOUND!!";
		goto db;	
	}
	do
	{	
		u.menu();

		cout<<"\nSELECT USER MENU OPTION		";
		cin>>opt;
		switch(opt)
		{
			case 1:
			u.disp(tacc);
			break;
			case 2:
			u.deposit(tacc);
			break;
			case 3:
			u.withdraw(tacc);
			break;
			case 4:
			goto db;
			break;
			default:
			cout<<"\nINVAID MAIN MENU OPTION";
		}

	}while(opt!=4);


	return 0;
}


