////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-01 20:04:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1622
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1708KB
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
int ans[1111],flag;
struct tree
{
	int v;
	tree *l,*r;
	tree()
	{
		v=-1;
		l=r=NULL;
	}
}*root;
tree *insert(int v,tree *p,char *op,int len)
{
	if(p==NULL) p=new tree;
	if(len==0)
	{
		if(p->v!=-1&&p->v!=v) flag=1;
		p->v=v;
		return p;
	}
	if(op[0]=='L') p->l=insert(v,p->l,op+1,len-1);
	else if(op[0]=='R') p->r=insert(v,p->r,op+1,len-1);
	return p;
}
int bfs()
{
	int cnt=0;
	tree *temp;
	queue<tree*> q;
	q.push(root);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp!=NULL)
		{
			if(temp->v==-1) return -1;
			else ans[cnt++]=temp->v;
			q.push(temp->l);
			q.push(temp->r);
		}
	}
	return cnt;
}
int main()
{
	int v,len,i;
	char t[333],op[333];
	while(1)
	{
		root=new tree;
		flag=0;
		while(1)
		{
			if(scanf("%s",t)==EOF) return 0;
			if(strcmp(t,"()")==0) break;
			mem(op,0);
			sscanf(t,"(%d,%s",&v,op);
			len=strlen(op)-1;
			if(len==0) root->v=v;
			else root=insert(v,root,op,len);
		}
		if(flag) puts("not complete");
		else
		{
			int n=bfs();
			if(n==-1) puts("not complete");
			else
			{
				for(i=0;i<n;i++)
				{
					if(!i) printf("%d",ans[i]);
					else printf(" %d",ans[i]);
				}
				puts("");
			}
		}
	}
	return 0;
}