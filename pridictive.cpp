#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
     {
       char tmp[15];
       char str[15], csf[15];
       int ssm=0, i, j, v, k, pos=0, a;
       
       char pt[6][5][4]={"" , "i" , "+" , "*" , "/",
             "E", "TX", "n" , "n" , "n",
             "X", "n" , "+TX", "n" , "" ,
             "T", "VY", "n" , "n" , "n",
             "Y", "n" , ""  , "*VY", "" ,
             "V", "i" , "n" , "n" , "n"};
     cout<<"\n Enter An Expression: "<<endl;
     cin>>str;
     strcpy(csf,"E");
     while(1)
    {
      pos=0;
      while(csf[pos]!='E' &&         
        csf[pos]!='X' &&
        csf[pos]!='T' &&
        csf[pos]!='Y' &&
        csf[pos]!='V' && csf[pos]!='\0')
        pos++;
      ssm=pos;
    if (csf[pos]=='\0')             

    for(i=1; i<6; i++)              
      {
        if(csf[pos]==pt[i][0][0])
           break;
      }
       for(j=1; j<5; j++)            
      {
         if(str[ssm]==pt[0][j][0])
        break;
      }

       if(strcmp(pt[i][j],"n")==0)     
       {
          cout<<"\n Production does not exist: "<<endl;
          cout<<pt[i][j];
          exit(0);
       }

       for(k=0; k<pos; k++)              
       tmp[k]=csf[k];
       tmp[k]='\0';
       strcat(tmp, pt[i][j]);
       int l=strlen(tmp);

       for(a=pos+1; csf[a]!='\0'; a++, l++)
       tmp[l]=csf[a];
       tmp[l]='\0';
       strcpy(csf, tmp);
       cout<<"\n"<<str[ssm]<<"\t"<<csf;
       getch();
 }
       strcat(csf, "/");

       cout<<"\t\tcsf ::"<<csf;

     if(strcmp(csf, str)==0)
         {
         cout<<"\n Valid Expression: "<<endl;
         }
     else
         {
          cout<<"\n Invalid Expression:"<<endl;
         }
      getch();
      return 0;
}

