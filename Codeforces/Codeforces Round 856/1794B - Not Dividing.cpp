#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
int a[MAX],res[MAX];
int main()
{
	int T,n,i,j,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(j=0;j<=2;j++)
		{
			res[1]=a[1]+j;
			if(res[1]==1) continue;
			cnt=j;
			for(i=2;i<=n;i++)
			{
				res[i]=a[i];
				if(res[i]==1)
				{
					res[i]++;
					cnt++;
				}
				while(res[i]%res[i-1]==0)
				{
					res[i]++;
					cnt++;
				}
			}
			if(cnt<=2*n) break;
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
