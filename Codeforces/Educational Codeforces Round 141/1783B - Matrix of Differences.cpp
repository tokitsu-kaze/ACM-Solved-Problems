#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mp[55][55];
int main()
{
	int T,n,i,j,f,l,r,res;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		f=0;
		l=1;
		r=n*n;
		for(i=1;i<=n;i++)
		{
			if(i&1)
			{
				for(j=1;j<=n;j++)
				{
					if(!f) res=l++;
					else res=r--;
					mp[i][j]=res;
					f^=1;
				}
			}
			else
			{
				for(j=n;j;j--)
				{
					if(!f) res=l++;
					else res=r--;
					mp[i][j]=res;
					f^=1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) printf("%d%c",mp[i][j]," \n"[j==n]);
		}
	}
	return 0;
}

