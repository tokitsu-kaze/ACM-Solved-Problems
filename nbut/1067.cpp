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
#define MAX 100000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int pow2(int a)
{
    int b,c;
    b=a;
    a=a%10;
    c=1;
    while(b>0)
    {
        if(b%2!=0)
        {
            c=c*a%10;
        }
        a=a*a%10;
        b=b/2;
    }
    return c;
}
int main()
{
    int n,i,a;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            printf("%d\n",pow2(a));
        }
    }
    return 0;
}