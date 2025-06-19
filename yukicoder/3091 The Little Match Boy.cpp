#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX];
int main()
{
	int n,m,i,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) p[i]=i;
	set<pair<int,int>> s;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&z);
		x=p[z];
		y=p[z+1];
		if(x>y) swap(x,y);
		s.insert({x,y});
		swap(p[z],p[z+1]);
	}
	printf("%d\n",s.size());
	return 0;
}
