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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
struct node
{
	char name[31];
	int exp;
}a[44];
int cmp(node a,node b)
{
	return strcmp(a.name,b.name)<0;
}
int main()
{
	int n,m,i,t,cnt;
	double k;
	char s[31];
	while(~scanf("%d%d%lf",&n,&m,&k))
	{
		k*=100;
		for(i=1;i<=40;i++)
		{
			mem(a[i].name,0);
			a[i].exp=0;
		}
		map<string,int> mp;
		cnt=n;
		for(i=1;i<=n;i++)
		{
			getchar();
			scanf("%s %d",a[i].name,&a[i].exp);
			mp[a[i].name]=i;
			a[i].exp=(int)a[i].exp*(k+eps)/100;
			if(a[i].exp<100)
			{
				a[i].exp=-1;
				cnt--;
			}
		}
		t=n;
		for(i=0;i<m;i++)
		{
			getchar();
			scanf("%s",s);
			if(!mp[s])
			{
				strcat(a[++t].name,s);
				a[t].exp=0;
				mp[s]=t;
				cnt++;
			}
			else if(a[mp[s]].exp==-1)
			{
				a[mp[s]].exp=0;
				cnt++;
			}
		}
		sort(a+1,a+1+t,cmp);
		printf("%d\n",cnt);
		for(i=1;i<=t;i++)
		{
			if(a[i].exp!=-1) printf("%s %d\n",a[i].name,a[i].exp);
		}
	}
    return 0;
}