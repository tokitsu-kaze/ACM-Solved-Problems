#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
struct abc
{
	int a,b,c;
}t[1001];
int cmp(abc a,abc b)
{
	if(a.a!=b.a) return a.a>b.a;
	if(a.b!=b.b) return a.b>b.b;
	if(a.c!=b.c) return a.c>b.c;
}
int main()
{
	int n,i;
    while(cin>>n)
    {
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
		}
		sort(t,t+n,cmp);
		printf("%d %d %d\n",t[0].a,t[0].b,t[0].c);
    }
    return 0;
}