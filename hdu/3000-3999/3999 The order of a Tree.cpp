////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-01 19:05:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3999
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:4860KB
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
void preorder(tree *p)
{
	if(p!=NULL)
	{
		if(p==root) printf("%d",p->v);
		else printf(" %d",p->v);
		preorder(p->l);
		preorder(p->r);
	}
}
int main()
{
	int n,i,a;
	while(~scanf("%d",&n))
	{
		root=NULL;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			root=insert(a,root);
		}
		preorder(root);
		puts("");
	}
	return 0;
}