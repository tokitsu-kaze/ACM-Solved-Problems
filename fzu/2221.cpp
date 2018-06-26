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
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll; 
int main()
{ 
	int t,n,m;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			if(m%2==0&&n>=m/2*3-1) puts("Yes");
			else if(m%2!=0&&n>=m/2*3) puts("Yes");
			else puts("No");
		}
	}
    return 0;
}