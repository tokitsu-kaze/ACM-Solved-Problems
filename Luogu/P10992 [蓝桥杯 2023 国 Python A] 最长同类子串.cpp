#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct hash_map
{
	#define key_type pair<int,int>
	#define val_type int
	static const int N=MAX;
	static const int p=999917;
	key_type val[N];
	val_type w[N];
	int tot,head[p],nex[N];
	int top,st[N];
	hash_map(){top=tot=0;}
	void clear(){tot=0;while(top) head[st[top--]]=0;}
	void add(int x,key_type y){val[++tot]=y;nex[tot]=head[x];head[x]=tot;w[tot]=0;}
	bool count(key_type y)
	{
		int x=y.first%p;
		for(int i=head[x];i;i=nex[i])
		{
			if(y==val[i]) return 1;
		}
		return 0;
	}
	val_type& operator [](key_type y)
	{
		int x=y.first%p;
		for(int i=head[x];i;i=nex[i])
		{
			if(y==val[i]) return w[i];
		}
		add(x,y);
		st[++top]=x;
		return w[tot];
	}
	#undef key_type
	#undef val_type
}mp;
namespace HASH
{
	#define type int
	int m;
	const int sd0=133331;
	const int sd1=233333;
	const int p0=402653189;
	const int p1=805306457;
	vector<type> sdpw[2];
	void init(int _m)
	{
		int i,j;
		m=_m;
		sdpw[0].resize(m+1);
		sdpw[1].resize(m+1);
		sdpw[0][0]=sdpw[1][0]=1;
		for(i=1;i<=m;i++)
		{
			sdpw[0][i]=1LL*sdpw[0][i-1]*sd0%p0;
			sdpw[1][i]=1LL*sdpw[1][i-1]*sd1%p1;
		}
	}
	struct hash_table
	{
		vector<type> ha[2];
		void work(int n,int *s)
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
		pair<type,type> get(int l,int r)
		{
			if(l>r) return {-1,-1};
			vector<type> res(2);
			res[0]=(ha[0][r]-1LL*ha[0][l-1]*sdpw[0][r-l+1])%p0;
			if(res[0]<0) res[0]+=p0;
			res[1]=(ha[1][r]-1LL*ha[1][l-1]*sdpw[1][r-l+1])%p1;
			if(res[1]<0) res[1]+=p1;
			return {res[0],res[1]};
		}
	};
	#undef type
}
/*
HASH::init(m);
ha.work(n,s);   // n<=m
*/
using HASH::sdpw;
using HASH::sd0;
using HASH::sd1;
using HASH::p0;
using HASH::p1;

int n,m;
char s[MAX],t[MAX];
int pre_s[MAX],nex_s[MAX];
int pre_t[MAX],nex_t[MAX];
int ck(int k)
{
	int i,r,p;
	ll ha0,ha1;
	mp.clear();
	ha0=ha1=0;
	for(i=1;i<=k;i++)
	{
		ha0=ha0*sd0%p0;
		ha1=ha1*sd1%p1;
		if(pre_s[i]>=1)
		{
			ha0+=i-pre_s[i];
			if(ha0>=p0) ha0-=p0;
			ha1+=i-pre_s[i];
			if(ha1>=p1) ha1-=p1;
		}
	}
	mp[{ha0,ha1}]=1;
	for(i=2;i<=n-k+1;i++)
	{
		r=i+k-1;
		ha0=ha0*sd0%p0;
		ha1=ha1*sd1%p1;
		p=nex_s[i-1];
		if(p<r)
		{
			ha0=(ha0-1LL*(p-pre_s[p])*sdpw[0][r-p])%p0;
			if(ha0<0) ha0+=p0;
			ha1=(ha1-1LL*(p-pre_s[p])*sdpw[1][r-p])%p1;
			if(ha1<0) ha1+=p1;
		}
		if(pre_s[r]>=i)
		{
			ha0+=r-pre_s[r];
			if(ha0>=p0) ha0-=p0;
			ha1+=r-pre_s[r];
			if(ha1>=p1) ha1-=p1;
		}
		mp[{ha0,ha1}]=1;
	}
	
	ha0=ha1=0;
	for(i=1;i<=k;i++)
	{
		ha0=ha0*sd0%p0;
		ha1=ha1*sd1%p1;
		if(pre_t[i]>=1)
		{
			ha0+=i-pre_t[i];
			if(ha0>=p0) ha0-=p0;
			ha1+=i-pre_t[i];
			if(ha1>=p1) ha1-=p1;
		}
	}
	if(mp.count({ha0,ha1})) return 1;
	for(i=2;i<=m-k+1;i++)
	{
		r=i+k-1;
		ha0=ha0*sd0%p0;
		ha1=ha1*sd1%p1;
		p=nex_t[i-1];
		if(p<r)
		{
			ha0=(ha0-1LL*(p-pre_t[p])*sdpw[0][r-p])%p0;
			if(ha0<0) ha0+=p0;
			ha1=(ha1-1LL*(p-pre_t[p])*sdpw[1][r-p])%p1;
			if(ha1<0) ha1+=p1;
		}
		if(pre_t[r]>=i)
		{
			ha0+=r-pre_t[r];
			if(ha0>=p0) ha0-=p0;
			ha1+=r-pre_t[r];
			if(ha1>=p1) ha1-=p1;
		}
		if(mp.count({ha0,ha1})) return 1;
	}
	return 0;
}
int main()
{
	int i,l,r,mid,pos[26];
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	HASH::init(max(n,m));
	
	memset(pos,0,sizeof(pos));
	for(i=1;i<=n;i++)
	{
		pre_s[i]=pos[s[i]-'a'];
		pos[s[i]-'a']=i;
	}
	memset(pos,0x3f,sizeof(pos));
	for(i=n;i>=1;i--)
	{
		nex_s[i]=pos[s[i]-'a'];
		pos[s[i]-'a']=i;
	}
	
	memset(pos,0,sizeof(pos));
	for(i=1;i<=m;i++)
	{
		pre_t[i]=pos[t[i]-'a'];
		pos[t[i]-'a']=i;
	}
	memset(pos,0x3f,sizeof(pos));
	for(i=m;i>=1;i--)
	{
		nex_t[i]=pos[t[i]-'a'];
		pos[t[i]-'a']=i;
	}
	
	l=0;
	r=min(n,m);
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
/*
二分答案，用 hash 滑窗动态维护前驱数组。
*/
