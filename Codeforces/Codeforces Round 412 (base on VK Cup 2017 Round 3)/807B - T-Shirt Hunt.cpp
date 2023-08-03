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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
map<int,int> m;
void make(int s)
{
	int t,i;
	t=(s/50)%475;
	for(i=0;i<25;i++)
	{
		t=(t*96+42)%475;
		m[t+26]=1;
	}
}
int main()
{
	int p,x,y,t,ans,flag,cnt;
	while(~scanf("%d%d%d",&p,&x,&y))
	{
		t=x;
		ans=0;
		flag=0;
		while(t>=y)
		{
			m.clear();
			make(t);
			if(m[p])
			{
				flag=1;
				break;
			}
			t-=50;
		}
		if(flag)
		{
			printf("%d\n",ans);
			continue;
		}
		t=x;
		cnt=0;
		while(1)
		{
			t+=100;
			ans++;
			m.clear();
			make(t);
			if(m[p]) break;
			t-=50;
			cnt++;
			m.clear();
			make(t);
			if(m[p]) break;
		}
		printf("%d\n",ans-cnt/2);
	}
	return 0;
}