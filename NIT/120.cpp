#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int main()  
{
	long long n,i,j,k,len;
	char s[22],c[101][10];
	memset(c,' ',sizeof(c));
	for(i=0;i<=9;i++)
	{
		for(j=2;j<=6;j++)
		{
			if(i==1||i==4) break;
			c[i*7][j]='-';
		}
		if(i==0||i==4||i==8||i==9)
		{
			c[i*7+1][1]=c[i*7+1][7]='|';
			c[i*7+2][1]=c[i*7+2][7]='|';
		}
		else if(i==1||i==2||i==3||i==7)
		{
			c[i*7+1][7]='|';
			c[i*7+2][7]='|';
		}
		else
		{
			c[i*7+1][1]='|';
			c[i*7+2][1]='|';
		}
		if(i==1||i==7);
		else if(i==0)
		{
			c[i*7+3][1]=c[i*7+3][7]='|';
		}
		else
		{
			for(j=2;j<=6;j++)
			{
				c[i*7+3][j]='-';
			}
		}
		if(i==0||i==6||i==8)
		{
			c[i*7+4][1]=c[i*7+4][7]='|';
			c[i*7+5][1]=c[i*7+5][7]='|';
		}
		else if(i==1||i==3||i==4||i==5||i==7||i==9)
		{
			c[i*7+4][7]='|';
			c[i*7+5][7]='|';
		}
		else
		{
			c[i*7+4][1]='|';
			c[i*7+5][1]='|';
		}
		if(i==0||i==2||i==3||i==5||i==6||i==8||i==9)
		{
			for(j=2;j<=6;j++)
			{
				c[i*7+6][j]='-';
			}
		}
	}
	
	while(cin>>n)
	{	
		sprintf(s,"%lld",n);
		len=strlen(s);
		for(k=1;k<=7;k++)
		{
			for(j=0;j<len;j++)
			{
				if(k==1)
				{
					for(i=1;i<=7;i++)
					{
						cout<<c[7*(s[j]-'0')][i];
					}
				}
				if(k==2||k==3)
				{
					for(i=1;i<=7;i++)
					{
						cout<<c[7*(s[j]-'0')+k-1][i];
					}
				}
				if(k==4)
				{
					for(i=1;i<=7;i++)
					{
						cout<<c[7*(s[j]-'0')+k-1][i];
					}
				}
				if(k==5||k==6)
				{
					for(i=1;i<=7;i++)
					{
						cout<<c[7*(s[j]-'0')+k-1][i];
					}
				}
				if(k==7)
				{
					for(i=1;i<=7;i++)
					{
						cout<<c[7*(s[j]-'0')+k-1][i];
					}
				}
			}
			cout<<endl;
		}
    }
    return 0;  
}  
  