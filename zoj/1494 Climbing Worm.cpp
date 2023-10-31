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
	int n,u,d,min;
	while(cin>>n>>u>>d&&(n+u+d))
	{
		for(min=0;;min+=2)
		{
			if(n-u<=0) break;
			n-=u-d;
		}
		cout<<min+1<<endl;
	}
	return 0;
}