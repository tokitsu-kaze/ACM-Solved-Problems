#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int B=300;
struct hash_map
{
	#define type int
	#define TA pair<type,type>
    static const int p=999917;
    static const int N=MAX*B;
    TA val[N];
	type w[N];
    int tot,head[p],nex[N];
    int top,st[N];
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
}mp;
const int V=1e5;
int n,a[MAX],cnt[MAX];
int solve1()
{
	int i,k,ans;
	ans=0;
	for(k=-B;k<=B;k++)
	{
		mp.clear();
		for(i=1;i<=n;i++)
		{
			mp[{a[i]-k*i,0}]++;
			ans=max(ans,mp[{a[i]-k*i,0}]);
		}
	}
	return n-ans;
}
int solve2()
{
	int i,j,k,len,ans,x;
	mp.clear();
	ans=0;
	for(len=1;len<=V/B;len++)
	{
		for(i=1;i+len<=n;i++)
		{
			j=i+len;
			if((a[i]-a[j])%(i-j)) continue;
			k=(a[i]-a[j])/(i-j);
			if(abs(k)>B)
			{
				mp[{a[i]-k*i,k}]++;
				x=mp[{a[i]-k*i,k}];
				if(cnt[x]!=-1) ans=max(ans,cnt[x]);
			}
		}
	}
	return n-ans;
}
int main()
{
	int i;
	scanf("%d",&n);
	memset(cnt,-1,sizeof cnt);
	for(i=1;i*(i-1)/2<MAX;i++) cnt[i*(i-1)/2]=i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",min(solve1(),solve2()));
	return 0;
}
/*
设 公差为 k，则 (ai-aj)=k*(i-j)。
至少有 2 个数可以不动，并且要满足 (ai-aj)%(i-j)==0。
n,V=1e5，时限 5s，考虑根号分治。
(i-j)>=根号，说明 k 不超过根号，枚举 k 直接计算即可。
(i-j)<根号，
- 计算出的 k 如果不超过根号，不管；
- k 超过根号，保留下来的数很少，并且在枚举(i-j)时能够覆盖到所有的情况。
发现枚举时，保留下来的数个数 x 会被枚举到 x*(x-1)/2 次，于是能计算出 x。
*/
