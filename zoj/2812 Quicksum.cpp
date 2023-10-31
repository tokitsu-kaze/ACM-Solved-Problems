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
int main()
{
    int x,i,s;
    char a[1000];
    while(gets(a))
    {
        if(strcmp(a,"#")==0) break;
        s=0;
        x=strlen(a);
        for(i=0;i<x;i++)
        {
            if(a[i]!=' ')
            {
                s=s+(i+1)*(a[i]-64);
            }
            else if(a[i]==' ')
            {
                s=s;
            }
        }
        printf("%d\n",s);
    }
    return 0;
}