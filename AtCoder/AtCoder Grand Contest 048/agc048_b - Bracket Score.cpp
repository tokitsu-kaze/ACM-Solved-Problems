#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],b[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	vector<int> res[2];
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=a[i];
		res[i&1].push_back(b[i]-a[i]);
	}
	sort(res[0].begin(),res[0].end());
	sort(res[1].begin(),res[1].end());
	for(i=0;i<res[0].size();i++) ans+=max(0,res[0][i]+res[1][i]);
	printf("%lld\n",ans);
	return 0;
}
/*
手玩发现同类型括号每次匹配必定下标奇偶性不同。
猜测任意 奇数下标个数=偶数下标个数 的同类型括号一定能构造出解。
实现时先默认选一种括号，然后贪心看看改成另一种是否更优。
*/
