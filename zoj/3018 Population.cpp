#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
int n;
//ÄÚ²ãÊ÷ 
int root[MAX],tot,ls[MAX],rs[MAX],v[MAX];
void init()
{
	mem(root,0);
	v[0]=ls[0]=rs[0]=0;
	tot=1;
}
int newnode()
{
	ls[tot]=rs[tot]=0;
	v[tot]=0;
	return tot++;
}
void Insert(int l,int r,int &id,int pos,int val)
{
	int mid;
	if(!id) id=newnode();
	if(l==r&&pos==l)
	{
		v[id]+=val;
		return;
	}
	mid=(l+r)>>1;
	if(pos<=mid) Insert(l,mid,ls[id],pos,val);
	else if(pos>=mid+1) Insert(mid+1,r,rs[id],pos,val);
	v[id]=v[ls[id]]+v[rs[id]];
}
int query2(int l,int r,int id,int x,int y)
{
	if(!id) return 0;
	if(l>=x&&r<=y) return v[id];
	int mid=(l+r)>>1;
	if(y<=mid) return query2(l,mid,ls[id],x,y);
	else if(x>=mid+1) return query2(mid+1,r,rs[id],x,y);
	else return query2(l,mid,ls[id],x,y)+query2(mid+1,r,rs[id],x,y);
	v[id]=v[ls[id]]+v[rs[id]];
}
//
 
void update(int l,int r,int id,int pos,int h,int v)
{
	int mid;
	Insert(1,n,root[id],h,v);
	if(l==r&&pos==l) return;
	mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,id<<1,pos,h,v);
	else if(pos>=mid+1) update(mid+1,r,id<<1|1,pos,h,v);
}
int query1(int l,int r,int id,int x,int y,int h1,int h2)
{
	int mid;
	if(l>=x&&r<=y) return query2(1,n,root[id],h1,h2);
	mid=(l+r)>>1;
	if(y<=mid) return query1(l,mid,id<<1,x,y,h1,h2);
	else if(x>=mid+1) return query1(mid+1,r,id<<1|1,x,y,h1,h2);
	else return query1(l,mid,id<<1,x,y,h1,h2)+query1(mid+1,r,id<<1|1,x,y,h1,h2);
}
int main()
{
	int a,b,c,x1,x2,y1,y2;
	char op[11],temp[11];
	n=20000;
	while(~scanf("%s",op))
	{
		init();
		while(1)
		{
			if(op[0]=='E') break;
			if(op[0]=='I')
			{
				while(1)
				{
					scanf("%s",temp);
					if(temp[0]>='0'&&temp[0]<='9') a=atoi(temp);
					else
					{
						strcpy(op,temp);
						break;
					}
					scanf("%d%d",&b,&c);
					update(1,n,1,a,b,c);
				}
			}
			else if(op[0]=='Q')
			{
				while(1)
				{
					scanf("%s",temp);
					if(temp[0]>='0'&&temp[0]<='9') x1=atoi(temp);
					else
					{
						strcpy(op,temp);
						break;
					}
					scanf("%d%d%d",&x2,&y1,&y2);
					printf("%d\n",query1(1,n,1,x1,x2,y1,y2));
				}
			}
		}
	}
	return 0;
}