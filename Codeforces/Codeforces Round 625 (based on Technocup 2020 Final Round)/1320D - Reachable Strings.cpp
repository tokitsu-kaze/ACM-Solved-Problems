#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
namespace HASH
{
	#define type int
	int m;
	const int sd0=131;
	const int sd1=233;
	const int p0=402653189;
	const int p1=805306457;
	vector<type> tmp[2];
	void init(int _m)
	{
		int i,j;
		m=_m;
		tmp[0].resize(m+1);
		tmp[1].resize(m+1);
		tmp[0][0]=tmp[1][0]=1;
		for(i=1;i<=m;i++)
		{
			tmp[0][i]=1LL*tmp[0][i-1]*sd0%p0;
			tmp[1][i]=1LL*tmp[1][i-1]*sd1%p1;
		}
	}
	struct hash_table
	{
		vector<type> ha[2];
		void work(int *s,int n)
		{
			int i,j;
			assert(n<=m);
			ha[0].resize(n+1);
			ha[1].resize(n+1);
			ha[0][0]=ha[1][0]=0;
			for(i=1;i<=n;i++)
			{
				ha[0][i]=(1LL*ha[0][i-1]*sd0+s[i])%p0;
				ha[1][i]=(1LL*ha[1][i-1]*sd1+s[i])%p1;
			}
		}
		vector<type> get(int l,int r)
		{
			if(l>r) return {-1,-1};
			vector<type> res(2);
			res[0]=(ha[0][r]-1LL*ha[0][l-1]*tmp[0][r-l+1])%p0;
			if(res[0]<0) res[0]+=p0;
			res[1]=(ha[1][r]-1LL*ha[1][l-1]*tmp[1][r-l+1])%p1;
			if(res[1]<0) res[1]+=p1;
			return res;
		}
	};
	#undef type
}
HASH::hash_table ha[2];
/*
HASH::init(m);
ha.work(s,n);   // n<=m
*/
char s[MAX];
int a[MAX],b[MAX],pos[MAX];
int main()
{
	int n,i,q,l1,l2,len,tot,l,r,cnt1,cnt2;
	scanf("%d",&n);
	scanf("%s",s+1);
	HASH::init(n);
	tot=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			tot++;
			a[tot]=i%2;
			b[tot]=(a[tot]^1);
			pos[tot]=i;
		}
	}
	ha[1].work(a,tot);
	ha[0].work(b,tot);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&l1,&l2,&len);
		l=lower_bound(pos+1,pos+1+tot,l1)-pos;
		r=upper_bound(pos+1,pos+1+tot,l1+len-1)-pos-1;
		cnt1=r-l+1;
		auto res1=ha[l1&1].get(l,r);
		
		l=lower_bound(pos+1,pos+1+tot,l2)-pos;
		r=upper_bound(pos+1,pos+1+tot,l2+len-1)-pos-1;
		cnt2=r-l+1;
		auto res2=ha[l2&1].get(l,r);
		
		if(cnt1==cnt2 && res1==res2) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
发现操作不改变 0 位置的奇偶性和相对位置。
把序列转化一下，把 0 的位置的奇偶性拉出来变成新的序列。
查询时二分找到起点，然后用hash维护。
注意需要判个数。
*/
