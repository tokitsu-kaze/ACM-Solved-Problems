#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
vector<int> pos[MAX];
int main()
{
	int T,n,i,j,ok,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) pos[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			pos[b[i]].push_back(i);
		}
		ok=1;
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(pos[i].size()==0) continue;
			if(pos[i].size()%i) ok=0;
			for(j=0;j<pos[i].size();j++)
			{
				if(j%i==0) tot++;
				a[pos[i][j]]=tot;
			}
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
