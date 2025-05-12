#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char mp[44][44];
int main()
{
	int T,n,i,j,fi,fj;
	char tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		n*=2;
		fi=0;
		for(i=1;i<=n;i+=2)
		{
			fj=fi;
			for(j=1;j<=n;j+=2)
			{
				if(fj==0) tmp='#';
				else tmp='.';
				mp[i][j]=mp[i+1][j]=mp[i][j+1]=mp[i+1][j+1]=tmp;
				fj^=1;
			}
			fi^=1;
		}
		for(i=1;i<=n;i++)
		{
			mp[i][n+1]='\0';
			puts(mp[i]+1);
		}
	}
	return 0;
}
