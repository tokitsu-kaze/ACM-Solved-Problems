#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<ll> res;
		res.push_back(1LL);
		for(i=1;i<n;i++)
		{
			if(res.back()>1e9) break;
			res.push_back(res.back()*3LL);
		}
		if(res.size()!=n || res.back()>1e9) puts("NO");
		else
		{
			puts("YES");
			for(i=0;i<n;i++) printf("%lld%c",res[i]," \n"[i+1==n]);
		}
	}
	return 0;
}
/*
ai+aj<=2*(ai-aj)
3aj<=ai
*/
