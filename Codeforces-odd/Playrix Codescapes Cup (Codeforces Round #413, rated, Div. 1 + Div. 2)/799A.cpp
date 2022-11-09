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
const double eps=1e-12;
const int MAX=2e6+10;
const ll mod=1e6;
int main()
{
	int n,t,k,d,s,sp;
	while(~scanf("%d%d%d%d",&n,&t,&k,&d))
	{
		if(k>=n)
		{
			puts("NO");
			continue;
		}
		s=0;
		while(s*k<n)
		{
			s++;
		}
		s*=t;
		sp=1;
		while(sp*k+((sp*t+d)/t)*k<n)
		{
			sp++;
		}
	//	cout<<sp*t+d<<" "<<s<<endl;
		if(sp*t+d<s) puts("YES");
		else puts("NO");
	} 
	return 0;
}