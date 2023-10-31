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
const double eps=1e-100;
int main()
{
	int k=1;;
	double a,b;
	while(cin>>a>>b)
	{
		printf("Case %d: ",k++);
		if(a-b>=eps) puts("Bigger");
		else if(a-b==0) puts("Same");
		else puts("Smaller");
	}
    return 0;
}