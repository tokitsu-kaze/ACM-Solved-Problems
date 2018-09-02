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
	int i,j,k,l,max,flag,flag2;
	char a[1001];
	while(cin>>a)
	{
		max=INT_MIN;
		flag2=0;
		for(j=0;j<strlen(a);j++)
		{
			for(i=strlen(a)-1;i>j;i--)
			{
				if(a[j]==a[i])
				{
					for(k=j,flag=0,l=i;k<=j+(i-j)/2;k++,l--)
					{
						if(a[k]!=a[l])
						{
							flag=1;
							break;
						}
					}
					if(!flag&&i-j>max)
					{
						max=i-j;
						flag2=1;
					}					
				}
			}
		}
		if(flag2) cout<<max+1<<endl;
		else cout<<1<<endl;
	}
    return 0;  
}