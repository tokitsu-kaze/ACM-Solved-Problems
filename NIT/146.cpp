#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
using namespace std;
int main()
{
	int t,i,j,len,flag,l;
	char a[1001];
	while(cin>>t)
	{
		while(t--)
		{
			cin>>a;
			flag=0;
			l=len=strlen(a);
			len=len/2;
			if(l%2)
			{
				for(i=0,j=l-1-i;i<len;i++,j--)
				{
					if(a[i]!=a[j])
					{
						flag=1;
						break;
					}
				}
			}
			else
			{
				if(a[0]==a[l-1])
				{
					for(i=0,j=l-1-i;i<len;i++,j--)
					{
						if(a[i]!=a[j]&&i!=l/2-1)
						{
							flag=1;
							break;
						}
					}
				}
				else if(a[0]==a[l-2])
				{
					for(i=0,j=l-2-i;i<len;i++,j--)
					{
						if(a[i]!=a[j])
						{
							flag=1;
							break;
						}
					}
				}
				else
				{
					for(i=1,j=l-1-i;i<len;i++,j--)
					{
						if(a[i]!=a[j])
						{
							flag=1;
							break;
						}
					}
				}
			}
			if(flag==1) puts("NO!");
			else puts("YES!");
		}
	}
    return 0;  
}