#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
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
		void work(char *s,int n)
		{
			int i,j;
			assert(n<=m);
			ha[0].resize(n+1);
			ha[1].resize(n+1);
			ha[0][0]=ha[1][0]=0;
			for(i=1;i<=n;i++)
			{
				ha[0][i]=(1LL*ha[0][i-1]*sd0+s[i]-'a'+1)%p0;
				ha[1][i]=(1LL*ha[1][i-1]*sd1+s[i]-'a'+1)%p1;
			}
		}
		vector<type> get(int l,int r)
		{
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
HASH::hash_table ha;
/*
HASH::init(m);
ha.work(s,n);   // n<=m
*/
int n;
char s[MAX];
int work(int i,int l)
{
	int j;
	const int p0=HASH::p0;
	const int p1=HASH::p1;
	auto ha1=ha.get(1,i);
	if(l<=i)
	{
		ha1[0]=((ha1[0]-1LL*(s[l]-'a'+1)*HASH::tmp[0][i-l])%p0+p0)%p0;
		ha1[1]=((ha1[1]-1LL*(s[l]-'a'+1)*HASH::tmp[1][i-l])%p1+p1)%p1;
	}
	auto ha2=ha.get(n-i+1,n);
	if(l>=n-i+1)
	{
		ha2[0]=((ha2[0]-1LL*(s[l]-'a'+1)*HASH::tmp[0][n-l])%p0+p0)%p0;
		ha2[1]=((ha2[1]-1LL*(s[l]-'a'+1)*HASH::tmp[1][n-l])%p1+p1)%p1;
	}
	for(j=0;j<26;j++)
	{
		if(l<=i)
		{
			ha1[0]+=HASH::tmp[0][i-l];
			if(ha1[0]>=p0) ha1[0]-=p0;
			ha1[1]+=HASH::tmp[1][i-l];
			if(ha1[1]>=p1) ha1[1]-=p1;
		}
		if(l>=n-i+1)
		{
			ha2[0]+=HASH::tmp[0][n-l];
			if(ha2[0]>=p0) ha2[0]-=p0;
			ha2[1]+=HASH::tmp[1][n-l];
			if(ha2[1]>=p1) ha2[1]-=p1;
		}
		if(ha1==ha2) return 1;
	}
	return 0;
}
int main()
{
	int i,j,ans,l,r,mid;
	scanf("%s",s+1);
	n=strlen(s+1);
	HASH::init(n);
	ha.work(s,n);
	ans=0;
	for(i=n-1;i;i--)
	{
		l=0;
		r=i;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ha.get(1,mid+1)==ha.get(n-i+1,(n-i+1)+mid)) l=mid+1;
			else r=mid;
		}
		if(l==i)
		{
			ans=i;
			break;
		}
		l++;
		if(work(i,l) || work(i,(n-i+1)+l-1))
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
枚举答案，二分找到第一个不相等的，改改试试
*/
