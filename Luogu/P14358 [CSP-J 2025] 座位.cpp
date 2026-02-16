#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+11;
struct node{int v,id;};
int main()
{
	int n,m,i,j,k,x,rx,ry;
	scanf("%d%d",&n,&m);
	vector<node> res;
	for(i=1;i<=n*m;i++)
	{
		scanf("%d",&x);
		res.push_back({x,i});
	}
	sort(res.begin(),res.end(),[](node x,node y){
		return x.v>y.v;
	});
	k=0;
	for(j=1;j<=m;j++)
	{
		if(j&1)
		{
			for(i=1;i<=n;i++)
			{
				if(res[k].id==1)
				{
					rx=i;
					ry=j;
				}
				k++;
			}
		}
		else
		{
			for(i=n;i;i--)
			{
				if(res[k].id==1)
				{
					rx=i;
					ry=j;
				}
				k++;
			}
		}
	}
	printf("%d %d\n",ry,rx);
	return 0;
}
