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
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t;
    double n,sum;
    while(cin>>n&&n)
    {
		sum=0;
		t=1;
		while(n>sum)
		{
			t++;
			sum+=1.0/t;
		}
		printf("%d card(s)\n",t-1);
	}
    return 0;
}