#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
mt19937 rd(time(0));
ll a[MAX];
const int LIMT=50;
set<ll> s;
void work(ll x)
{
	ll i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			s.insert(i);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) s.insert(x);
}
ll cal(int n,ll tar)
{
	int i;
	ll res,tmp;
	res=0;
	for(i=1;i<=n;i++)
	{
		tmp=(a[i]+tar-1)/tar*tar;
		if(tmp==tar) res+=tmp-a[i];
		else res+=min(tmp-a[i],a[i]-(tmp-tar));
	}
	return res;
}
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	shuffle(a+1,a+1+n,rd);
	s.clear();
	for(i=1;i<=min(n,LIMT);i++)
	{
		work(a[i]);
		work(a[i]-1);
		work(a[i]+1);
	}
	ans=n;
	for(auto &it:s) ans=min(ans,cal(n,it));
	printf("%lld\n",ans);
	return 0;
}
/*
考虑比较暴力的做法：枚举质数去检查答案。
只要枚举的质数是最终 gcd 的质因数，那么就成功。
但如何选出要去check的质数？没有头绪。
找找性质，首先发现 ans<=n。这里需要猜一手随机化，才能比较好想到正解。
能够证明，最终答案构成的序列，至少有一半的数，要么不变，要么+1或者-1。
反证：否则会有一半多的数至少操作两次，这样就违背了 ans<=n。
所以随机一些数，不变，+1或者-1。求出质因数。
最终 gcd 的质因数很大概率在里面。
*/
