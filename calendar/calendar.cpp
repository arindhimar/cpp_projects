#include<iostream>
#include<iomanip>
using namespace std;

void dprint()
{
    //FOR PRINTING DAYS
    cout<<"\n\n SUN MON TUE WED THU FRI SAT";
}

int getfday(int y)
{
    int fday=(((y-1)*365)+((y-1)/4)-((y-1)/100)+((y/400)+1))%7;
    return fday;
}

int main()
{
    int year;
    cout<<"\nENTER YEAR         ";
    cin>>year;

    int dom[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    string moy[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};

    int day,month,fday;



    if(year%400==0)
    {
        dom[1]=29;
    }
    else if(year%100==0)
    {
        dom[1]=28;
    }
    else if(year%4==0)
    {
        dom[1]=29;
    }



    int i,wday=0;
    cout<<"\n\t\t\t"<<year;


    int l=getfday(year);


    //cout<<fday;


    for(i=0;i<12;i++)
    {


        cout<<"\n======================"<<moy[i]<<"==========================="<<endl;
        cout<<"\nSUN      MON     TUE     WED     THU     FRI     SAT"<<endl;

        for(wday=0;wday<l;wday++)
        {
            cout<<"      -";
        }



        for(day=1;day<=dom[i];day++)
        {
            if(wday>6)
            {
                cout<<endl;
                wday=0;
            }
            cout<<setw(7)<<day;
            wday++;
            //fday=getfday(year);
        }

        l=wday;
    }
    return 0;
}
