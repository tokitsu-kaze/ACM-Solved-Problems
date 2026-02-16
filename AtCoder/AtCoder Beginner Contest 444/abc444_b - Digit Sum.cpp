#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int cal(int x)
{
	string s=to_string(x);
	int res=0;
	for(auto &it:s) res+=it-'0';
	return res;
}
int main()
{
	int n,k,i,ans;
	scanf("%d%d",&n,&k);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(cal(i)==k) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
