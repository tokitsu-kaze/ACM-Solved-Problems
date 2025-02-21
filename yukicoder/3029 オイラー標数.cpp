#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int q,a,b,c,x[3];
	scanf("%d",&q);
	set<int> v;
	set<pair<int,int>> e;
	set<tuple<int,int,int>> f;
	while(q--)
	{
		scanf("%d%d%d",&x[0],&x[1],&x[2]);
		sort(x,x+3);
		a=x[0];
		b=x[1];
		c=x[2];
		v.insert(a);
		v.insert(b);
		v.insert(c);
		e.insert({a,b});
		e.insert({b,c});
		e.insert({a,c});
		f.insert(tuple<int,int,int>{a,b,c});
	}
	printf("%d\n",(int)v.size()-(int)e.size()+(int)f.size());
	return 0;
}
