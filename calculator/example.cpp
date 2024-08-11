#include <stdio.h>
#include <iostream>
using namespace std;

int sale,value;
int commission;

int display_manu()
{
    cout<<"sale value==";
    cin>>sale;
    return 0;
}


int main()
{
    display_manu();

    if(sale<=5000)
    { 
      commission = sale*0.3;
    }
    else

    if(sale>5000&&sale<=10000)
    {
       commission = sale*0.5+200;
    }
    if(sale>10000&&sale<=20000)
    {
      commission = sale * 0.7+400;
    } 
    else
    if(sale>20000&&sale<=25000)
    {
       commission = sale * 0.9+600;
    }
    else
     {
        commission = sale*0.11+800;
     }

    cout<<"commission is="<<commission<<"\r\n";
    cout<<"back to input stream"<<"\r\n";
}