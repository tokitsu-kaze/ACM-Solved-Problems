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
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
    int i,a,flag=0;
	for(i=0;i<3;i++)
	{
		scanf("%d",&a);
		if(a<168)
		{
			printf("CRASH %d\n",a);
			flag=1;
			break;
		}
	}
	if(!flag) printf("NO CRASH\n");
    return 0;
}