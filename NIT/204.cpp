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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	ll i,j,len,s;
	char a[MAX];
	while(~scanf("%s",a))
	{
		s=0;
		len=strlen(a);
		map<char,ll> m;
		map<char,ll> ::iterator it;
		for(i=0;i<len;i++)
		{
			m[a[i]]++;
		}
		for(it=m.begin();it!=m.end();it++)
		{
			s+=(it->second*it->second);
		}
		printf("%lld\n",s);
	}
	return 0;
}