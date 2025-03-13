#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int ask(int x)
{
	printf("%d\n",x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int main()
{
	int T,n,i,x,res;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		set<int> s;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			s.insert(x);
		}
		res=0;
		while(s.count(res)) res++;
		while(1)
		{
			res=ask(res);
			if(res==-1) break;
			assert(res!=-2);
		}
	}
	return 0;
}
