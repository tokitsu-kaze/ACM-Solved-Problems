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
const ll mod=1e6;
struct node
{
	int x,y,tag;//tag=1 x tag=2 y 
}a[5];
char s[1010][1010];
int main()
{
	int i,maxx,pos,tag,p[3],cnt,j,k,l,flag;
	maxx=0;
	for(i=0;i<3;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x<a[i].y) swap(a[i].x,a[i].y);
		if(a[i].x>maxx)
		{
			maxx=a[i].x;
			pos=i;
			tag=1;
		}
		if(a[i].y>maxx)
		{
			maxx=a[i].y;
			pos=i;
			tag=2;
		}
		a[i].tag=0;
	} 
	a[pos].tag=tag;
	cnt=0;
	flag=0;
	for(i=0;i<3;i++)
	{
		if(i==pos) continue;
		p[cnt++]=i;
	}
		if(a[p[0]].x==a[p[1]].x&&a[p[0]].x==a[pos].x)//1 1
		{
			for(j=0;j<a[pos].y;j++)
			{
				for(k=0;k<a[pos].x;k++)
				{
					s[j][k]='A'+pos;
				}
			}
			for(l=0;l<a[p[0]].y;j++,l++)
			{
				for(k=0;k<a[p[0]].x;k++)
				{
					s[j][k]='A'+p[0];
				}
			}
			for(l=0;l<a[p[1]].y;j++,l++)
			{
				for(k=0;k<a[p[1]].x;k++)
				{
					s[j][k]='A'+p[1];
				}
			}
			if(j==k)
			{
				flag=1;
				goto end;
			}
		}
		if(a[p[0]].x==a[p[1]].x&&a[p[0]].y+a[p[1]].y==a[pos].x)//2 2
		{
			for(j=0;j<a[pos].y;j++)
			{
				for(k=0;k<a[pos].x;k++)
				{
					s[j][k]='A'+pos;
				}
			}
			for(l=0;l<a[p[0]].x;l++,j++)
			{
				for(k=0;k<a[p[0]].y;k++)
				{
					s[j][k]='A'+p[0];
				}
				for(i=0;i<a[p[1]].y;k++,i++)
				{
					s[j][k]='A'+p[1];
				}
			}
			if(j==k)
			{
				flag=1;
				goto end;
			}
		}
		if(a[p[0]].x+a[p[1]].y==a[pos].x&&a[p[0]].y==a[p[1]].x)//1 2
		{
			for(j=0;j<a[pos].y;j++)
			{
				for(k=0;k<a[pos].x;k++)
				{
					s[j][k]='A'+pos;
				}
			}
			for(l=0;l<a[p[0]].y;l++,j++)
			{
				for(k=0;k<a[p[0]].x;k++)
				{
					s[j][k]='A'+p[0];
				}
				for(i=0;i<a[p[1]].y;k++,i++)
				{
					s[j][k]='A'+p[1];
				}
			}
			if(j==k)
			{
				flag=1;
				goto end;
			}
		}
		if(a[p[0]].y+a[p[1]].x==a[pos].x&&a[p[0]].x==a[p[1]].y)//2 1
		{
			for(j=0;j<a[pos].y;j++)
			{
				for(k=0;k<a[pos].x;k++)
				{
					s[j][k]='A'+pos;
				}
			}
			for(l=0;l<a[p[0]].x;l++,j++)
			{
				for(k=0;k<a[p[0]].y;k++)
				{
					s[j][k]='A'+p[0];
				}
				for(i=0;i<a[p[1]].x;k++,i++)
				{
					s[j][k]='A'+p[1];
				}
			}
			if(j==k)
			{
				flag=1;
				goto end;
			}
		}
		if(a[p[0]].y==a[p[1]].y&&a[p[0]].x+a[p[1]].x==a[pos].x)//1 1
		{
			for(j=0;j<a[pos].y;j++)
			{
				for(k=0;k<a[pos].x;k++)
				{
					s[j][k]='A'+pos;
				}
			}
			for(l=0;l<a[p[0]].y;l++,j++)
			{
				for(k=0;k<a[p[0]].x;k++)
				{
					s[j][k]='A'+p[0];
				}
				for(i=0;i<a[p[1]].x;k++,i++)
				{
					s[j][k]='A'+p[1];
				}
			}
			if(j==k)
			{
				flag=1;
				goto end;
			}
		}
		if(a[p[0]].y==a[p[1]].y&&a[p[0]].y==a[pos].x)//2 2
		{
			for(j=0;j<a[pos].y;j++)
			{
				for(k=0;k<a[pos].x;k++)
				{
					s[j][k]='A'+pos;
				}
			}
			for(l=0;l<a[p[0]].x;j++,l++)
			{
				for(k=0;k<a[p[0]].y;k++)
				{
					s[j][k]='A'+p[0];
				}
			}
			for(l=0;l<a[p[1]].x;j++,l++)
			{
				for(k=0;k<a[p[1]].y;k++)
				{
					s[j][k]='A'+p[1];
				}
			}
			if(j==k)
			{
				flag=1;
				goto end;
			}
		}
		if(!flag)
		{
			puts("-1");
			return 0;
		}
		end:
			printf("%d\n",j);
			for(i=0;i<j;i++)
			{
				puts(s[i]);
			}
		
	return 0;
}