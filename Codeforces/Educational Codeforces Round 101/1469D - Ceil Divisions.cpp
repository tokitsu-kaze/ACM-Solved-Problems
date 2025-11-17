#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int x,y;};
int main()
{
	int T,n,i,sq;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<node> res;
		while(n>2)
		{
			sq=sqrt(n);
			while(sq*sq<n) sq++;
			for(i=sq+1;i<n;i++) res.push_back({i,n});
			res.push_back({n,sq});
			res.push_back({n,sq});
			n=sq;
		}
		printf("%d\n",res.size());
		for(auto &it:res) printf("%d %d\n",it.x,it.y);
	}
	return 0;
}
