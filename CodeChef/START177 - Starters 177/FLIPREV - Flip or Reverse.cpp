#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
struct opt{int op,l,r;};
char a[MAX],b[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		vector<opt> res;
		for(i=2;i<=n;i+=2)
		{
			if(a[i-1]==b[i-1] && a[i]==b[i]) continue;
			if(a[i-1]==b[i-1]) res.push_back({1,i,i});
			else if(a[i]==b[i]) res.push_back({1,i-1,i-1});
			else res.push_back({1,i-1,i});
		}
		if(n&1)
		{
			if(a[n]!=b[n]) res.push_back({1,n,n});
		}
		printf("%d\n",(int)res.size());
		for(auto &it:res) printf("%d %d %d\n",it.op,it.l,it.r);
	}
	return 0;
}
