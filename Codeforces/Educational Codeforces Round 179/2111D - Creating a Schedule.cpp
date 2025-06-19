#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct node{int flr,id;}a[MAX];
vector<int> res[MAX];
int main()
{
	int T,n,m,i,j,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a[i].id);
			a[i].flr=a[i].id/100;
		}
		sort(a+1,a+1+m,[](node x,node y){
			return x.flr<y.flr;
		});
		for(i=1;i<=n;i++) res[i].clear();
		l=1;
		r=m;
		for(i=1;i<=n;i+=2)
		{
			for(j=0;j<6;j+=2)
			{
				res[i].push_back(a[l].id);
				res[i].push_back(a[r].id);
				res[i+1].push_back(a[r].id);
				res[i+1].push_back(a[l].id);
			}
			l++;
			r--;
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<6;j++) printf("%d%c",res[i][j]," \n"[j+1==6]);
		}
	}
	return 0;
}
