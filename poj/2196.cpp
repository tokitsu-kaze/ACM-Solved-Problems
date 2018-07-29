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
void exchange(int a)
{
    int i,j=0,k=0,b,c;
    b=a;
    c=a;
    i=a/1000+a/100%10+a/10%10+a%10;
    while(b>0)
    {
        j=j+b%12;
        b=b/12;
    }
    while(c>0)
    {
        k=k+c%16;
        c=c/16;
    }
    if(i==j&&j==k) printf("%d\n",a);
}
int main()
{
    int i;
    for(i=2992;i<=9999;i++)
    {
        exchange(i);
    }
    return 0;
}