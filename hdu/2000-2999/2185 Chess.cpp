////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-09 19:36:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2185
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1704KB
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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	int a,b,id;
}a[1111];
bool cmp1(node a,node b)
{
	return max(a.a,a.b)>max(b.a,b.b);
}
bool cmp2(node a,node b)
{
	return a.a>b.a;
}
bool cmp3(node a,node b)
{
	return a.b>b.b;
}
int main()
{
	int ans,i,cnt=0,cnt1,cnt2;
	while(~scanf("%d%d",&a[cnt].a,&a[cnt].b)) a[cnt].id=cnt++;
	ans=0;
	sort(a,a+cnt,cmp1);
	cnt1=cnt2=15;
	for(i=0;i<cnt;i++)
	{
//		cout<<a[i].id<<endl;
		if(a[i].a>a[i].b)
		{
			ans+=a[i].a;
			cnt1--;
			a[i].a=a[i].b=-1;
		}
		else
		{
			ans+=a[i].b;
			cnt2--;
			a[i].a=a[i].b=-1;
		}
		if(!cnt1||!cnt2) break;
	}
	if(cnt1)
	{
		sort(a,a+cnt,cmp2);
		for(i=0;i<cnt;i++)
		{
			ans+=a[i].a;
			cnt1--;
			if(!cnt1) break;
		}
	}
	else if(cnt2)
	{
		sort(a,a+cnt,cmp3);
		for(i=0;i<cnt;i++)
		{
//			cout<<a[i].id<<endl;
			ans+=a[i].b;
			cnt2--;
			if(!cnt2) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}