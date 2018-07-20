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
int main()
{
	int n,i,t,b[1111],k,flag,ans;
	char a[1111][55];
	while(~scanf("%d",&n))
	{
		map<string,int> m,mp;
		t=0;
		mem(a,0);
		mem(b,0);
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%s %d",a[i],&b[i]);
			m[a[i]]+=b[i];
		}
		for(i=0;i<n;i++)
		{
			t=max(t,m[a[i]]);
		}
		flag=0;
		for(i=0;i<n;i++)
		{
			if(m[a[i]]==t)
			{
				flag++;
				ans=i;
				mp[a[i]]=1;
			}
		}
		if(flag==1)
		{
			puts(a[ans]);
			continue;
		}
		m.clear();
		for(i=0;i<n;i++)
		{
			m[a[i]]+=b[i];
			if(m[a[i]]>=t&&mp[a[i]])
			{
				puts(a[i]);
				break;
			}
		}
	}
	return 0;
}