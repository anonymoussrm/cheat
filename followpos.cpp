#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
string p[20],first[20],temp,s;
static string follow;
int n;	
void abc(string ,char);
string Firstpos(char a)
{int i=0; string str;
	while(first[i][0]!=NULL)
	 {
	 	if(first[i][0]==a)
	 	 str=first[i];
	 	 i++;
	 }
	 str.erase(str.begin());
	 return str;
}
void follow_append(char c)
{
 if(follow.find(c)==-1)
  follow.push_back(c);
}
void Followpos(char c)
{ 
	for(int j=0;j<n;j++)
		 abc(p[j],c);
}
void abc(string str1,char c)
{
char a,d='%';
string str;
a=c;
for(int k=1;k<str1.length();k++)
  {
  	if(a==str1[k])
  	{  if(d!=str1[k+1])
 		{
 		if(c==p[0][0])
  	      follow_append('$');
     	  if(isupper(str1[k+1]))
     		 {
    		  str=Firstpos(str1[k+1]);
			  int l=0;
			  while(str[l]!=NULL)
			  {
			  	if(str[l]=='e')
			  	{
                str1.erase(str1.begin()+k+1);
                abc(str1,c);
			    }
		  	else
			  	follow_append(str[l]);
		  	l++;
		  }
		   }
		else if(str1[k+1]==NULL)
	  if(str1[0]==str1[k])
    continue;
		   else
    Followpos(str1[0]);
 		else
 		 follow_append(str1[k+1]);
  		d=str1[k+1];}
	  }
  }
}
int main()
{	
    static	char a;
    int i,j,l,k=0;
	cout<<"Enter number of production rules: ";
	cin>>n;
	fflush(stdin);
	for(int i=0;i<n;i++)//jagged array
	    getline(cin,p[i]);
	i=0;l=0;
	while(i<n)    
	{
		temp.clear();
		while(p[i][0]==p[l][0])
		{
		a=p[l][1];
		s=a;
	     if(!isupper(a))
			  temp.append(s);
	   	 else
		 for(int j=l+1;j<n;j++)
		 {
			if((p[j][0])==a)
			 if(!isupper(p[j][1]))
			   {s=p[j][1];
			   temp.append(s);}
			  else
			   { a=p[j][1]; s=a;}
		 }
		l++;
	    }
	    s=p[i][0];
	    first[k].append(s);
	    first[k].append(temp);
	    k++;
	    i=l;
	}
	i=0;
	while(first[i][0]!=NULL)
	{   cout<<"follow of "<<first[i][0]<<": ";
	   follow.clear();
	  Followpos(first[i][0]);
	  cout<<follow;
	  cout<<endl;
	i++;
	}
}
