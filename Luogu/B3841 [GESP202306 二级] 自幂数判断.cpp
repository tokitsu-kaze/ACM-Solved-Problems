#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int qpow(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main()
{
	int T,n,i,sum,sz;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		string tmp=to_string(n);
		sz=tmp.size();
		sum=0;
		for(auto &it:tmp) sum+=qpow(it-'0',sz);
		if(sum==n) puts("T");
		else puts("F");
	}
	return 0;
}
