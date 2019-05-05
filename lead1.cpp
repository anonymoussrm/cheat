#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
string p[20];
int n; 
void lead(char);
void trail(char);
int main()
{   int c=0,x=0,j; static char nt[10];
	cout<<"Enter number of production rules: ";
	cin>>n;
	fflush(stdin);
	for(int i=0;i<n;i++)//jagged array
	{
	  getline(cin,p[i]);
	  for(j=0;j<=x;j++)
	  	if(nt[j]==p[i][0])
	  	 break;
	  if(j==x+1)	 
	   nt[x++]=p[i][0];
	}
    for(c=0;c<x;c++)
     {
     	cout<<"Trailing("<<nt[c]<<") : (";
		 trail(nt[c]);
		 cout<<")"<<endl;
	 }
	 
	  /*for(c=0;c<x;c++)
     {
     	cout<<"Leading("<<nt[c]<<") : (";
		 lead(nt[c]);
		 cout<<")"<<endl;
	 }*/
}
void lead(char x)
{
	for(int i=0;i<n;i++)
	 if(p[i][0]==x)
	  if(isupper(p[i][2]))
	  { 
	    if(p[i][3])
	  	cout<<p[i][3];
	  	
	  	if(p[i][0]!=p[i][2])
	  	 lead(p[i][2]);
	  }
	  else
	   cout<<p[i][2];
}
void trail(char x)
{ char a=NULL;
	for(int i=0;i<n;i++)
	 if(p[i][0]==x)
	 {int j=0;
	 	while(p[i][j++]);
	 	if(a==p[i][j-2])
	 	 break;
	 	a=p[i][j-2];
	  if(isupper(p[i][j-2]))
	  { 
	    if(!isupper(p[i][j-3]))
	  	cout<<p[i][j-3];
	  	if(p[i][0]!=p[i][j-2])
	  	 trail(p[i][j-2]);
	  }
	  else
	   cout<<p[i][j-2];
	 }
}
