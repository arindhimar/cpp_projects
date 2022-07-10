#include<iostream>
#include<cstring>
using namespace std;


class bankdb
{
    struct details
    {
        char name[20],locality[20],upass[20];
        int acc_no;
        float bal,add,with;
    }d[100];

    int acc_no,flag;
    char apass[20],tpass[20];


    public:

    //DATA MEMBERS
    struct details temp;
    int n=0;

    //MEMBER FUNCTION


    //PASS CHECK
    int napass(char s[20])
    {
        cout<<"\nENTER PREVIOUS PASSWORD        ";
        cin>>tpass;
        if(strcmp(s,tpass)==0)
        {

            strcpy(apass,tpass);
            return 0;
        }
        else
        {
            cout<<"\n\t\tPASSWORDS DONT MATCH\n";
            cout<<"\n\t\tFAILED TO CREATE DATABASE";
            return 1;
        }
    }


    //NEW ACCOUNT
    void ccreate(struct details t)
    {
        d[n-1]=t;
    }


    //DISP
    void disp(int i)
    {
            cout<<"\nACCOUNT NO     :   "<<d[i].acc_no;
            cout<<"\nACCOUNT HOLDER NAME     :   "<<d[i].name;
            cout<<"\nACCOUNT HOLDER LOCALITY     :   "<<d[i].locality;
            cout<<"\nACCOUNT BALANCE     :   "<<d[i].bal;
    }



    //ACCOUNT AVAILABILITY
    int accck(int n)
    {
        for(i=0;i<n;i++)
        {
            if(d[i].acc_no==n)
            {
                return 0;
            }
        }
        return 0;
    }



};





class admin:public bankdb
{
    char s[20];
    int ck,i;
    public:

    void npass()
    {
        cout<<"\nENTER PASSWORD TO CREATE A DATABASE        ";
        cin>>s;
        ck=napass(s);
        if(ck==1)
        {
            exit(-1);
        }
        else
            cout<<"\n\t\tDATABASE CREATED !!!\n";
    }

    //CREATING ACCOUNT
    void create()
    {
        n=n+1;
        temp.acc_no=n;
        cout<<"\nENTER NAME         : ";
        cin>>temp.name;
        cout<<"\nENTER LOCALITY     : ";
        cin>>temp.locality;
        do
        {
            cout<<"\nENTER PASSWORD FOR ACCOUNT         ";
            cin>>s;
            ck=napass(s);
            if(ck==0)
            {
                cout<<"\n\t\tACCOUND CREATED";
            }
        }while(ck!=0);
        ccreate(temp);
    }



    //DISPLAY ALL ACCOUNT
    void dispacc()
    {
        for(i=0;i<n;i++)
        {
            disp(i);
        }
    }



    //SEARCH
    int s_acc;
    void searchacc()
    {
        cout<<"\nENTER ACCOUNT NO TO SEARCH         ";
        cin>>s_acc;
        ck=accck(s_acc);
        if(ck==1)
        {
            disp(s_acc);
        }
        else
            cout<<"\n\tNO ACCOUNT FOUND";
    }


}a;


class user:public bankdb
{
    int ck;

    char s[20];
    public:


    //NEW DATABASE
    void ucpass()
    {

    }






}u;

struct trans
{
    int t_no,db_ac;
    float db_credit,db_debit,db_bal;
}t[1000];


void amenu()
{
    cout<<"\n\t\t ADMIN PANEL"<<endl;
    cout<<"\n\t 1 - CREATE ACCOUNT"<<endl;
    cout<<"\n\t 2 - VIEW ALL ACCOUNT DETAILS"<<endl;
    cout<<"\n\t 3 - SEARCH ACCOUNT"<<endl;
    cout<<"\n\t 4 - BLOCK ACCOUNT"<<endl;
    cout<<"\n\t 5 - VIEW ALL TRANSACTIONS"<<endl;
    cout<<"\n\t 6 - ACCOUNT WISE TRANSACTIONS"<<endl;
    cout<<"\n\t 7 - RETURN TO MAIN MENU"<<endl;
}


void umenu()
{
    cout<<"\n\t\t USER PANEL"<<endl;
    cout<<"\n\t 1 - VIEW ACCOUNT DETAILS"<<endl;
    cout<<"\n\t 2 - DEBIT MONEY"<<endl;
    cout<<"\n\t 3 - WITHDRAW MONEY"<<endl;
    cout<<"\n\t 4 - UPDATE NAME/LOCALITY"<<endl;
    cout<<"\n\t 5 - CLOSE ACCOUNT"<<endl;
    cout<<"\n\t 6 - RETURN TO MAIN MENU"<<endl;
}


int main()
{
    //a.npass();
    int opt;
    mn:
    do
    {
        cout<<"\n\t\tMAIN PANEL";
        cout<<"\n\t 1 - LOGIN AS ADMIN";
        cout<<"\n\t 2 - LOGIN AS USER";
        cout<<"\n\t 3 - EXIT DATABASE";
        cout<<"\n\t SELECT OPTION ===>>>        ";
        cin>>opt;
        switch(opt)
        {
            case 1:
                goto admn;
                break;
            case 2:
                goto usr;
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"\nINVALID MENU OPTION";
        }

    }while(opt!=3);







    int aopt,uopt;



    //ADMIN PANEL FXNS
    admn:
        do
        {
            amenu();
            cout<<"\n\t SELECT OPTION ===>>>        ";
            cin>>aopt;
            switch(aopt)
            {
                case 1:
                    a.create();
                    break;
                case 2:
                    a.dispacc();
                    break;
                case 3:
                    a.searchacc();
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    goto mn;
                    break;
                default:
                    cout<<"\n\t INVALID USER PANEL OPTION"<<endl;
            }
        }while(aopt!=7);




    //USER PANEL FXNS
    usr:
        do
        {
            umenu();
            cout<<"\n\t SELECT OPTION ===>>>        ";
            cin>>uopt;
            switch(uopt)
            {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    goto mn;
                    break;
                default:
                    cout<<"\n\t INVALID USER PANEL OPTION"<<endl;

            }
        }while(uopt!=6);

    return 0;
}
