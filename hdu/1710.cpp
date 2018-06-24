////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-01 16:20:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1710
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4928KB
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
const int MAX=3e5+10;
const ll mod=1e9+7;
struct tree
{
	int v;
	tree *l,*r;
	tree()
	{
		l=r=NULL;
	}
}*root;
tree *build(int *a,int *b,tree *p,int n)
{
	int i;
	p=new tree;
	for(i=0;i<n;i++)
	{
		if(a[0]==b[i])
		{
			p->v=a[0];
			p->l=build(a+1,b,p->l,i);
			p->r=build(a+i+1,b+i+1,p->r,n-i-1);
			return p;
		}
	}
	return NULL;
}
void postorder(tree *p)
{
	if(p!=NULL)
	{
		postorder(p->l);
		postorder(p->r);
		if(p==root) printf("%d\n",p->v);
		else printf("%d ",p->v);
	}
}
int main()
{
	int n,i,a[1111],b[1111];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		root=build(a,b,root,n);
		postorder(root);
	}
	return 0;
}
