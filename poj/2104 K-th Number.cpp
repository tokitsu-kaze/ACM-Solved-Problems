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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int l,r,sum;
}tree[20*MAX];
int root[MAX],a[MAX],hash[MAX],tot;
void insert(int l,int r,int &id,int pre,int pos)
{
	int mid;
	tree[++tot]=tree[pre];
	tree[tot].sum++;
	id=tot;
	if(l==r) return;
	mid=(l+r)/2;
	if(mid>=pos) insert(l,mid,tree[id].l,tree[pre].l,pos);
	else insert(mid+1,r,tree[id].r,tree[pre].r,pos);
}
int query(int l,int r,int id,int pre,int k)
{
	int mid,temp;
	if(l==r) return hash[l];
	mid=(l+r)/2;
	temp=tree[tree[pre].l].sum-tree[tree[id].l].sum;
	if(temp>=k) return query(l,mid,tree[id].l,tree[pre].l,k);
	else return query(mid+1,r,tree[id].r,tree[pre].r,k-temp);
}
int main()
{
	int n,m,l,r,k,i,pos;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			hash[i]=a[i];
		}
		tot=0;
		sort(hash+1,hash+n+1);
		for(i=1;i<=n;i++)
		{
			pos=lower_bound(hash+1,hash+n+1,a[i])-hash;
			insert(1,n,root[i],root[i-1],pos);
		}
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",query(1,n,root[l-1],root[r],k));
		}
	}
	return 0;
}