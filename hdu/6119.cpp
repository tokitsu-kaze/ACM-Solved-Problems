////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-13 17:55:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6119
////Problem Title: 
////Run result: Accept
////Run time:202MS
////Run memory:2216KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int l,r;
	friend bool operator <(node a,node b)
	{
		if(a.l==b.l) return a.r<b.r;
		return a.l<b.l;
	}
}a[MAX],res[MAX];
int main()
{
	int n,m,k,i,l,r,cnt,ans,now;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].l,&a[i].r);
		}
		sort(a,a+n);
		l=a[0].l;
		r=a[0].r;
		cnt=0;
		for(i=1;i<n;i++)
		{
			if(a[i].l>=l&&a[i].l<=r+1) r=max(r,a[i].r);
			else
			{
				res[cnt].l=l;
				res[cnt].r=r;
				cnt++;
				l=a[i].l;
				r=a[i].r;
			}
		}
		res[cnt].l=l;
		res[cnt].r=r;
		cnt++;
	//	for(i=0;i<cnt;i++) cout<<res[i].l<<" "<<res[i].r<<endl;
		now=ans=0;
		l=0;
		now=res[0].r-res[0].l+1;
		k=m;
		for(i=1;i<cnt;i++)
		{
			while(l<i-1&&k<res[i].l-res[i-1].r-1)
			{
				k+=res[l+1].l-res[l].r-1;
				now-=res[l+1].l-res[l].l;
				l++;
			}
			if(k>=res[i].l-res[i-1].r-1)
			{
				now=res[i].r-res[l].l+1;
				k-=res[i].l-res[i-1].r-1;
			}
			else
			{
				ans=max(ans,now+k);
				now=res[i].r-res[i].l+1;
				k=m;
				l=i;
			}
	//		cout<<ans<<" "<<now<<" "<<k<<endl;
			ans=max(ans,now+k);
		}
		ans=max(ans,now+k);
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 1
1 2
4 5
7 8

2 1
1 2
4 5

2 1
1 2
4 5

3 5
1 2
7 8
11 1000000000

3 1
1 1
2 2
3 3

1 1000000000
1000000000 1000000000

3 3
1 1
4 5
8 10000000

3 4
1 2
5 6
100 100
*/