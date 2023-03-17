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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=500000+10;
const ll mod=10000;
char c[MAX];
typedef long long ll;
int main()
{
	int n,m,x,sx[999],sy[999],i,j,k,l,cnt,t,flag,mp[333];
	char a[33][33];
	while(~scanf("%d%d%d",&n,&m,&x))
	{
		mem(a,0);
		mem(sx,0);
		mem(sy,0);
		mem(mp,0);
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='S')
				{
					sx[k]=i;
					sy[k++]=j;
				}
				else mp[a[i][j]]=1;
			}
		}
		if(k)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(a[i][j]=='S') continue;
					for(l=0;l<k;l++)
					{
						if(!mp[a[i][j]-'a'+'A']) mp[a[i][j]-'a'+'A']=(i-sx[l])*(i-sx[l])+(j-sy[l])*(j-sy[l]);
						else mp[a[i][j]-'a'+'A']=min(mp[a[i][j]-'a'+'A'],(i-sx[l])*(i-sx[l])+(j-sy[l])*(j-sy[l]));
					}
				}
			}
		}
		cnt=flag=0;
		scanf("%d %s",&t,c);
		x*=x;
		for(i=0;i<t;i++)
		{
			if(flag) continue;
			if(!mp[c[i]]) flag=1;
			else
			{
				if(c[i]>='A'&&c[i]<='Z')
				{
					if(mp[c[i]]>x) cnt++;
				}
			}
		}
		if(flag) puts("-1");
		else printf("%d\n",cnt);
	}
    return 0;
}