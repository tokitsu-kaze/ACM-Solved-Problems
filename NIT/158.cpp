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
const int MAX=40000+10;
const ll mod=1e6;
struct node
{
	char name[22];
	int e,m,h;
	friend bool operator <(node a,node b)
	{
		return strcmp(a.name,b.name)<0;
	}
}a[111],b[111];
int main()
{
	int n,i;
	double e,m,h;
	while(~scanf("%d",&n))
	{
		mem(a,0);
		e=m=h=0;
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%s %d%d%d",a[i].name,&a[i].e,&a[i].m,&a[i].h);
			e+=a[i].e;
			m+=a[i].m;
			h+=a[i].h;
		}
		e/=n;
		m/=n;
		h/=n;
		int cnt=0;
		for(i=0;i<n;i++)
		{
			if(a[i].e<e&&a[i].m<m&&a[i].h<h) b[cnt++]=a[i];
		}
		sort(b,b+cnt);
		printf("%d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			printf("%s\n",b[i].name);
		}
	}
	return 0;
}