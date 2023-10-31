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
    int i,s;
    char a[10001];
    while(~scanf("%s",a))
    {
		if(a[0]=='0') break;
		s=0;
		for(i=0;i<strlen(a);i++)
		{
			s+=a[i]-'0';
		}
		if(s%9==0) puts("9");
		else printf("%d\n",s%9);
    }
    return 0;
}