#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#define pi acos(-1.0)
using namespace std;
int main()
{
	int i,len,flag,k;
	char a[1201],b[1201];
	while(~scanf("%s",a))
	{
		memset(b,0,sizeof(b));
		len=strlen(a);
		k=0;
		for(i=0;i<len;i++)
		{
			flag=0;
			if(a[i]=='H')
			{
				if(a[i+1]=='U'&&a[i+2]=='B'&&a[i+3]=='A')
				{
					if(k!=0&&b[k-1]!=' '&&i!=len-4) b[k++]=' ';
					i+=3;
					flag=1;
				}
			}
			if(!flag) b[k++]=a[i];
		}
		k--;
		if(k==-1)
		{
			cout<<"OMG"<<endl;
			continue;
		}
		else cout<<b<<endl;
	}
}