#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],res[20][MAX];
int main()
{
	int T,n,q,i,j,l,k,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			res[0][i]=a[i];
		}
		for(i=1;i<20;i++)
		{
			for(j=1;j+(1<<(i-1))<=n;j++)
			{
				res[i][j]=(res[i-1][j]&res[i-1][j+(1<<(i-1))]);
			}
		}
		scanf("%d",&q);
		vector<int> ans;
		while(q--)
		{
			scanf("%d%d",&l,&k);
			now=(1<<30)-1;
			for(i=19;~i;i--)
			{
				if(l+(1<<i)-1<=n && (now&res[i][l])>=k)
				{
					now&=res[i][l];
					l+=(1<<i);
				}
			}
			if(now==(1<<30)-1) ans.push_back(-1);
			else ans.push_back(l-1);
		}
		for(i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
	}
	return 0;
}
