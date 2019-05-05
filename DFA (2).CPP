#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
int i,j,p,k,m[10];
char l[20],o[20][20];
cout<<"enter the no of states";
cin>>p;
cout<<"enter the states";
for(i=0;i<p;i++)
{
 cin>>l[i];
}
cout<<"\n enter the no of inputs";
cin>>k;
cout<<"\n enter the inputs";
for(i=0;i<k;i++)
 cin>>m[i];
cout<<"\n enter the table contents";
for(i=0;i<p;i++)
 for(j=0;j<k;j++)
  {
	cout<<l[i]<<"->"<<m[j]<<"= ";
	cin>>o[i][j];
  }
for(i=0;i<p;i++)
 for(j=0;j<k;j++)
  cout<<"\n"<<l[i]<<"->"<<m[j]<<"->"<<o[i][j]<<"\n";

for(i=0;i<k;i++)
cout<<"\t\t"<<m[i];
for(i=0;i<p;i++)
{
 cout<<"\n"<<l[i];
  for(j=0;j<k;j++)
  {
   cout<<"\t\t"<<o[i][j];
  }
}
return 0;
}
