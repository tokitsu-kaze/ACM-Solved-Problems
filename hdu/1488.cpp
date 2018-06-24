////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-31 23:43:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1488
////Problem Title: 
////Run result: Accept
////Run time:1934MS
////Run memory:11624KB
//////////////////System Comment End//////////////////
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
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=50000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	
	ll n,a,b,temp,cnt,i;
	while(~scanf("%I64d",&n)&&n)
	{
		scanf("%I64d%I64d",&a,&b);
	    map<ll,ll> m;
	    stack<ll> s;
        temp=1;
        i=0;
		while(1)
		{
			i=(a*(i*i%n)+b)%n;
			if(m[i]==1) break;
			m[i]++;
			s.push(i);
		}
		cnt=1;
		while(s.top()!=i)
		{
			s.pop();
			cnt++;
		}
		printf("%I64d\n",n-cnt);
	}
}