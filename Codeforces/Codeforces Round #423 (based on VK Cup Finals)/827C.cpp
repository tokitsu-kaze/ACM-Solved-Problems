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
const int MAX=1e5+10;
const ll mod=1e6;
char a[MAX];
int mp[333];
int bit[11][11][5][MAX];
int lowbit(int x)
{
	return x&(-x);
}
void update(int a,int b,int c,int k,int v)
{
	while(k<=MAX)
	{
		bit[a][b][c][k]+=v;
		k+=lowbit(k);
	}
}
int getsum(int a,int b,int c,int k)
{
	int res=0;
	while(k)
	{
		res+=bit[a][b][c][k];
		k-=lowbit(k);
	}
	return res;
}
int main()
{
	int q,op,i,pos,l,r,ans,len,j;
	char b[22];
//	mem(mp,0);
	mp['A']=0;
	mp['T']=1;
	mp['C']=2;
	mp['G']=3;
	while(~scanf("%s",a+1))
	{
//		mem(bit,0);
		len=strlen(a+1);
		for(i=1;i<=len;i++)
		{
			for(j=1;j<=10;j++)
			{
				update(j,i%j,mp[a[i]],i,1);
			}
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%s",&pos,b);
				if(a[pos]==b[0]) continue;
				for(j=1;j<=10;j++)
				{
					update(j,pos%j,mp[a[pos]],pos,-1);
				}
				a[pos]=b[0];
				for(j=1;j<=10;j++)
				{
					update(j,pos%j,mp[a[pos]],pos,1);
				}
			}
			else if(op==2)
			{
				scanf("%d%d%s",&l,&r,b);
				ans=0;
				len=strlen(b);
				for(i=0;i<len;i++)
				{
					ans+=getsum(len,(l+i)%len,mp[b[i]],r)-getsum(len,(l+i)%len,mp[b[i]],l-1);
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}