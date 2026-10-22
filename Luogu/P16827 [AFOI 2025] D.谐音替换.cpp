#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	const int LOG=log2(MAX)+1;
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res+=bit[x];
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]+=v;
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}tr;
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
		void work(int n,char *s)
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
			res[0]=(ha[0][r]-1LL*ha[0][l-1]*tmp[0][r-l+1])%p0;
			if(res[0]<0) res[0]+=p0;
			res[1]=(ha[1][r]-1LL*ha[1][l-1]*tmp[1][r-l+1])%p1;
			if(res[1]<0) res[1]+=p1;
			return {res[0],res[1]};
		}
	};
	#undef type
}
HASH::hash_table ha;
/*
HASH::init(m);
ha.work(n,s);   // n<=m
*/
struct hash_map
{
	#define type int
	#define TA pair<type,type>
    static const int p=999917;
    TA val[MAX];
	type w[MAX];
    int tot,head[p],nex[MAX];
    int top,st[MAX];
    hash_map(){top=tot=0;}
    void clear(){tot=0;while(top) head[st[top--]]=0;}
    void add(int x,TA y){val[++tot]=y;nex[tot]=head[x];head[x]=tot;w[tot]=0;}
    bool count(TA y)
    {
        int x=abs(y.first)%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return 1;
		}
        return 0;
    }
    type& operator [](TA y)
    {
        int x=abs(y.first)%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return w[i];
		}
        add(x,y);
        st[++top]=x;
		return w[tot];
    }
    #undef TA
    #undef type
}premp,sufmp;
char s[MAX];
int pretag[MAX],suftag[MAX],presum[MAX],sufsum[MAX],lenl[MAX],lenr[MAX];
struct node{int x,v;};
vector<node> op[MAX];
int main()
{
	HASH::init(5e5);
	int n,m,i,len,l,r,mid;
	ll ra,rb,rc;
	scanf("%d%d",&n,&m);
	premp.clear();
	sufmp.clear();
	while(n--)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		ha.work(len,s);
		for(i=1;i<=len;i++)
		{
			premp[ha.get(1,i)]=1;
			sufmp[ha.get(i,len)]=1;
		}
	}
	while(m--)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		ha.work(len,s);
		pretag[0]=suftag[len+1]=0;
		for(i=1;i<=len;i++)
		{
			auto res=ha.get(1,i);
			if(premp.count(res) || sufmp.count(res)) pretag[i]=1;
			else pretag[i]=0;
			res=ha.get(i,len);
			if(premp.count(res) || sufmp.count(res)) suftag[i]=1;
			else suftag[i]=0;
		}
		presum[0]=sufsum[0]=0;
		for(i=1;i<=len;i++)
		{
			presum[i]=presum[i-1]+pretag[i];
			sufsum[i]=sufsum[i-1]+suftag[i];
		}
		for(i=1;i<=len;i++)
		{
			l=1;
			r=i;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(sufmp.count(ha.get(mid,i))) r=mid;
				else l=mid+1;
			}
			if(sufmp.count(ha.get(l,i))) lenl[i]=i-l+1;
			else lenl[i]=0;
			
			l=i;
			r=len;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(premp.count(ha.get(i,mid+1))) l=mid+1;
				else r=mid;
			}
			if(premp.count(ha.get(i,l))) lenr[i]=l-i+1;
			else lenr[i]=0;
		}
		ra=rb=0;
		for(i=2;i<=len-1;i++)
		{
			if(!pretag[i-1]) continue;
			r=min(len-1,i+lenr[i]-1);
			if(i<=r) ra+=sufsum[r+1]-sufsum[i];
		}
		for(i=len-1;i>=2;i--)
		{
			if(!suftag[i+1]) continue;
			l=max(2,i-lenl[i]+1);
			if(l<=i) rb+=presum[i-1]-presum[l-2];
		}
		
		for(i=1;i<=len;i++) op[i].clear();
		for(i=len-1;i>=2;i--)
		{
			if(!suftag[i+1]) continue;
			l=max(2,i-lenl[i]+1);
			if(l<=i)
			{
				op[l].push_back({i,1});
				op[i+1].push_back({i,-1});
			}
		}
		tr.init(len);
		rc=0;
		for(i=2;i<=len-1;i++)
		{
			for(auto &it:op[i]) tr.upd(it.x,it.v);
			if(!pretag[i-1]) continue;
			r=min(len-1,i+lenr[i]-1);
			if(i<=r) rc+=tr.ask(i,r);
		}
//		for(i=1;i<=len;i++) printf("%d %d %d\n",i,lenl[i],lenr[i]);
//		printf("res: %lld %lld %lld\n",ra,rb,rc);
		printf("%lld\n",ra+rb-rc);
	}
	return 0;
}
/*
可以预处理所有 S 的前后缀 hash，扔进 map 里。
从前往后枚举 AB 分割点，B 是某个前缀，C 是某个后缀；
从后往前枚举 BC 分割点，A 是某个前缀，B 是某个后缀。
这样的话，前缀与后缀都是单调的，可以二分。

具体一点，标记一下 T 的合法前缀 pretag[i]=0/1，合法后缀 suftag[i]=0/1。
二分+hash 求出 T 在每个下标最长能往后匹配多长 S 的前缀 r[i]，能往前匹配多长 S 的后缀 l[i]。
当前 BC 分割点为 y，y 是 B 的结尾，B 作为后缀合法：max(2,y-lenl[y]+1)<=x<=y 且 pretag[x-1]=1；
当前 AB 分割点为 x，x 是 B 的开头，B 作为前缀合法：x<=y<=min(len-1,x+lenr[x]-1) 且 suftag[y+1]=1。
对 pretag 和 suftag 做前后缀和，可以轻松求出来。当然要注意满足 A 和 C 的非空与合法。

再考虑减掉 B 同时作为前缀与后缀合法的情况，即两个条件同时满足。
相当于就是，前面一个点 后面一个区间，与前面一个区间 后面一个点，两个区间都分别包含对方的点。
画一下图发现，对于后面的点，前面的区间就是出现的时间。
从前往后扫描线，枚举 B 的开头 x，在区间左端点加入点，右端点删除点。
用树状数组维护，区间求和即可。

**注意：包含大小写英文字母。**
这题样例真拉。
*/
