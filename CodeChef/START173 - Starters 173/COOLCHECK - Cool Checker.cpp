#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int N=1e7+10;
bool vis[N];
int a[MAX],b[MAX],id[MAX];
ll sum[MAX];
int main()
{
	srand(time(0));
	int T,n,m,i,j,k,x,limt;
	memset(vis,0,sizeof vis);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			id[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
			vis[b[i]]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(!vis[a[i]])
			{
				puts("1");
				printf("%d\n",a[i]);
				goto end;
			}
		}
		limt=30;
		while(limt--)
		{
			random_shuffle(id+1,id+1+n);
			sum[0]=0;
			for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[id[i]];
			for(k=2;k<=100;k++)
			{
				for(i=1;i+k-1<=n;i++)
				{
					if((sum[i+k-1]-sum[i-1])%k!=0 || !vis[(sum[i+k-1]-sum[i-1])/k])
					{
						printf("%d\n",k);
						vector<int> res;
						for(j=0;j<k;j++) res.push_back(id[i+j]);
						sort(res.begin(),res.end());
						for(j=0;j<k;j++) printf("%d%c",a[res[j]]," \n"[j==k-1]);
						goto end;
					}
				}
			}
		}
		puts("-1");
		end:;
		for(i=1;i<=m;i++) vis[b[i]]=0;
	}
	return 0;
}
