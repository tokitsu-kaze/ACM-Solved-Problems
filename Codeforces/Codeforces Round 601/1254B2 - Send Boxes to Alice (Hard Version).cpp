#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[MAX];
ll work(int n,ll g)
{
	int i;
	ll bit,res;
	bit=res=0;
	for(i=1;i<=n;i++)
	{
		bit+=a[i];
		bit%=g;
		res+=min(bit,g-bit);
	}
	return res;
}
int main()
{
	int n,i;
	ll sum,ans;
	scanf("%d",&n);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	vector<ll> g;
	for(i=2;1LL*i*i<=sum;i++)
	{
		if(sum%i==0)
		{
			g.push_back(i);
			while(sum%i==0) sum/=i;
		}
	}
	if(sum>1) g.push_back(sum);
	ans=LLINF;
	for(auto &it:g) ans=min(ans,work(n,it));
	if(ans==LLINF) ans=-1;
	printf("%lld\n",ans);
	return 0;
}
/*
任意次操作，每次可以把一个1左右移动1位，求操作后gcd>1。
发现gcd一定是sum的因数，更确切说应该是质因数。
把sum分解后，最多只有11个质因数，枚举它。
接下来考虑知道gcd后怎么做。
经典套路，做个前缀和，把操作转化成单点加减1。
由于要满足ai%gcd=0，所以前缀和si%gcd也=0。
答案就是sum{min(si,gcd-si)}。
*/
