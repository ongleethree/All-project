#include <iostream>

using namespace std;

float x,y,answer;
char process;
//--------------------------
float sum(float x,float y);
float mul(float x,float y);
float minue(float x,float y);
float Div(float x,float y);
//...........................

void display_manu()
{
  cout<<"value of x ="<<'\n';
   cin>>x;
   cout<<"value of y ="<<'\n';
   cin>>y;
   cout<<"+,-,*,/"<<'\n';
   cin>>process;
}

void process_operator()
{
  switch(process)
   {
    case 43:
    
    answer=sum(x,y);
    cout<<"x+y="<<answer<<"\r\n";
    break;

    case 45:
    
    answer=minue(x,y);
    cout<<"x-y="<<answer<<"\r\n";
    break;

    case 42:
    
    answer=mul(x,y);
    cout<<"x*y="<<answer<<"\r\n";
    break;

    case 47:
    
    answer=Div(x,y);
    cout<<"x/y="<<answer<<"\r\n";
    break;

    default:
    cout<<"error status cannot calculate";
   }
}

float sum(float x,float y)
{
  return(x+y);
}
float mul(float x,float y)
{
  return(x*y);
}
float minue(float x,float y)
{
  return(x-y);
}
float Div(float x,float y)
{
  return(x/y);
}
int main()
 {
   display_manu();
   process_operator();
   
   return 0;
 }