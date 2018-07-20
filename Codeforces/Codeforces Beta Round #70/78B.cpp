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
#define eps 1e-9
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,i,t;
	while(cin>>n)
	{
		t=n/7;
		while(t--)
		{
			cout<<"ROYGBIV";
		}
		n%=7;
		for(i=1;i<=n;i++)
		{
			if(i%4==1) cout<<"G";
			else if(i%4==2) cout<<"B";
			else if(i%4==3) cout<<"I";
			else if(i%4==0) cout<<"V";
		}
		puts("");
	}
    return 0;
}