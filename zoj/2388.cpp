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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 1000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
    int a,b,c,d,t;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>a>>b;
			c=(a+b)>>1;
			d=c-b;
			if(c+d==a&&c-d==b&&c>=0&&d>=0) cout<<c<<" "<<d<<endl;
			else puts("impossible");
		}
	}
    return 0;
}