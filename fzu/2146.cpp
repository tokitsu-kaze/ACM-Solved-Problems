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
    int t,i,cas;
    char a[11111];
    while(cin>>t)
    {
		cas=1;
		getchar();
		while(t--)
		{
			gets(a);
			printf("Case %d: ",cas++);
			if(strlen(a)%2) puts("Odd");
			else puts("Even");
		}
    }
    return 0;
}