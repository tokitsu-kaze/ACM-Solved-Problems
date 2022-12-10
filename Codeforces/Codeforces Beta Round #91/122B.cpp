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
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int i,s,q;
    char a[55];
    while(gets(a))
    {
		s=q=0;
    	for(i=0;i<strlen(a);i++)
    	{
			if(a[i]=='4') s++;
			if(a[i]=='7') q++;
		}
		if(s>q) puts("4");
		else if(s<q) puts("7");
		else if(s==q&&s) puts("4");
		else puts("-1");
    }
    return 0;
}