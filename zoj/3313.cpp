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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int main()
{ 
	int t,n;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			printf("%.2lf\n",n*1.0*480);
		}
	}
    return 0;
}