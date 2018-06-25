////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-01 22:40:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5444
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2000KB
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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e9+7;
int cnt;
char ans[1111];
struct tree
{
	int v;
	tree *l,*r;
	tree()
	{
		l=r=NULL;
	}
}*root;
tree *insert(int v,tree *p)
{
	if(p==NULL)
	{
		p=new tree;
		p->v=v;
		return p;
	}
	if(v<p->v) p->l=insert(v,p->l);
	else if(v>p->v) p->r=insert(v,p->r);
	return p;
}
void find(int key,tree *p)
{
	if(p!=NULL)
	{
		if(p->v==key) return;
		if(key<p->v)
		{
			ans[cnt++]='E';
			find(key,p->l);
		}
		else if(key>p->v)
		{
			ans[cnt++]='W';
			find(key,p->r);
		}
	}
}
int main()
{
	int t,n,i,a,q,x;
	scanf("%d",&t);
	while(t--)
	{
		root=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			root=insert(a,root);
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&x);
			mem(ans,0);
			cnt=0;
			find(x,root);
			ans[cnt]='\0';
			puts(ans);
		}
	}
	return 0;
}