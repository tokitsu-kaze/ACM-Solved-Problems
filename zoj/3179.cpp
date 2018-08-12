#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{
	int t,x,y,i,j,sum,f;
	char a[11][11];
	while(cin>>t)
	{
		while(t--)
		{
			cin>>x>>y;
			getchar();
			sum=f=0;
			for(i=x;i<=y;i++)
			{
				sum+=i;
			}
			mem(a,0);
			for(i=0;i<8;i++)
			{
				gets(a[i]);
			}
			for(j=5;j>=0;j--)
			{
				if(a[1][j]=='o') f+=5*pow(10,5-j);
			}
			for(i=7;i>=4;i--)
			{
				for(j=5;j>=0;j--)
				{
					if(a[i][j]=='|') f+=(i-3)*pow(10,5-j);
				}
			}
			if(f==sum) puts("No mistake");
			else puts("Mistake");
		}
	}
	return 0;
}