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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e6;
struct Treap
{
	int v;
	int w,size,fix;
	Treap *l,*r;
	Treap()
	{
		w=size=1;
		l=r=NULL;
		fix=rand();
	}
	void calsize()
	{
		size=(l==NULL?0:l->size)+(r==NULL?0:r->size)+w;
	}
}*root;
void LRotate(Treap *&p)
{
	Treap *q;
	q=p->r;
	p->r=q->l;
	q->l=p;
	q->size=p->size;
	p->calsize();
	p=q;
}
void RRotate(Treap *&p)
{
	Treap *q;
	q=p->l;
	p->l=q->r;
	q->r=p;
	q->size=p->size;
	p->calsize();
	p=q;
}
void Insert(Treap *&p,int v)
{
	if(p==NULL)
	{
		p=new Treap;
		p->v=v;
	}
	else
	{
		if(v==p->v) p->w++;
		else if(v<p->v)
		{
			Insert(p->l,v);
			if(p->l!=NULL&&p->l->fix<p->fix) RRotate(p);
		}
		else if(v>p->v)
		{
			Insert(p->r,v);
			if(p->r!=NULL&&p->r->fix<p->fix) LRotate(p);
		}
	}
	p->calsize();
}
void Delete(Treap *&p,int v)
{
	if(p==NULL) return;
	if(v<p->v) Delete(p->l,v);
	else if(v>p->v) Delete(p->r,v);
	else
	{
		if(p->w>1) p->w--;
		else if(p->l!=NULL&&p->r!=NULL)
		{
			if(p->l->fix<p->r->fix) LRotate(p);
			else RRotate(p);
			Delete(p,v);
		}
		else
		{
			Treap *q=p;
			if(p->l==NULL) p=p->r;
			else p=p->l;
			delete q;
			return;
		}
	}
	p->calsize();
}
int Find(Treap *p)
{
	if(p!=NULL)
	{
		if(p->l==NULL) return p->v;
		return Find(p->l);
	}
	return -1;
}
char ans[MAX][22];
int res[MAX];
int main()
{
	int n,v,cnt,i;
	char op[22];
	while(~scanf("%d",&n))
	{
		root=NULL;
		cnt=0;
		while(n--)
		{
			scanf("%s",op);
			if(op[0]=='i')
			{
				scanf("%d",&v);
				Insert(root,v);
				strcpy(ans[cnt],"insert ");
				res[cnt]=v;
				cnt++;
			}
			else if(op[0]=='r')
			{
				if(root==NULL)
				{
					Insert(root,111);
					strcpy(ans[cnt],"insert ");
					res[cnt]=111;
					cnt++;
					v=111;
				}
				else v=Find(root);
				Delete(root,v);
				strcpy(ans[cnt],"removeMin");
				cnt++;
			}
			else if(op[0]=='g')
			{
				scanf("%d",&v);
				int temp=Find(root);
				while(temp<v)
				{
					if(root==NULL) break;
					Delete(root,temp);
					strcpy(ans[cnt],"removeMin");
					cnt++;
					temp=Find(root);
				}
				if(temp!=v)
				{
					Insert(root,v);
					strcpy(ans[cnt],"insert ");
					res[cnt]=v;
					cnt++;
				}
				strcpy(ans[cnt],"getMin ");
				res[cnt]=v;
				cnt++;
			}
		}
		printf("%d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			printf("%s",ans[i]);
			if(ans[i][0]=='g'||ans[i][0]=='i') printf("%d",res[i]);
			puts("");
		}
	}
	return 0;
}