////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-15 21:35:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4883
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:2072KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=10000+10;
const ll mod=1e6;
struct node1
{
	int st,et,v;
	friend bool operator<(node1 a,node1 b)
	{
		return a.st<b.st;
	}
}a1[MAX];
struct node2
{
	int t,v,n;
	friend bool operator<(node2 a,node2 b)
	{
		if(a.t==b.t) return a.n<b.n;
		return a.t<b.t;
	}
}t[2*MAX];
int main()
{
	int tt,n,i,a,b,c,d,k,flag[MAX];
	while(~scanf("%d",&tt))
	{
		while(tt--)
		{
			scanf("%d",&n);
			mem(a1,0);
			for(i=0;i<n;i++)
			{
				scanf("%d %d:%d %d:%d",&a1[i].v,&a,&b,&c,&d);
				int temp;
				temp=a*60+b;
				a1[i].st=temp;
				temp=c*60+d;
				a1[i].et=temp;
			}
			sort(a1,a1+n);
			mem(t,0);
			k=0;
			for(i=0;i<n;i++)
			{
	//			cout<<a1[i].st<<endl;
				t[k].n=i;
				t[k].t=a1[i].st;
				t[k++].v=a1[i].v;
				t[k].n=i;
				t[k].t=a1[i].et;
				t[k++].v=a1[i].v;
			}
			sort(t,t+k);
			int ans=0,cnt=0;
			mem(flag,0);
			for(i=0;i<k;i++)
			{
				if(!flag[t[i].n])
				{
					flag[t[i].n]=1;
					cnt+=t[i].v;
				}
				else
				{
					flag[t[i].n]=0;
					cnt-=t[i].v;
				}
				ans=max(ans,cnt);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
} 