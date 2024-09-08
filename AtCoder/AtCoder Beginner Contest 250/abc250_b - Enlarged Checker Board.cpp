#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char mp[111][111];
int main()
{
	int n,i,j,k,l,a,b,f,f2;
	scanf("%d%d%d",&n,&a,&b);
	f=0;
	for(l=0;l<n;l++)
	{
		f2=f;
		for(k=0;k<n;k++)
		{
			for(i=1+l*a;i<=a+l*a;i++)
			{
				for(j=1+k*b;j<=b+k*b;j++)
				{
					if(f2) mp[i][j]='#';
					else mp[i][j]='.';
				}
			}
			f2^=1;
		}
		f^=1;
		for(i=1+l*a;i<=a+l*a;i++)
		{
			mp[i][n*b+1]='\0';
			puts(mp[i]+1);
		}
	}
	return 0;
}
