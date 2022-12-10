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
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
char s[MAX];
struct node
{
	int id;
	int n;
}a[31];
int cmp(node a,node b)
{
	return a.n>b.n;
}
int main()
{
	int k,i,len,cnt;
	while(~scanf("%s%d",s,&k))
	{
		len=strlen(s);
		if(len<=k)
		{
			puts("0");
			continue;
		}
		for(i=0;i<26;i++)
		{
			a[i].id=i;
			a[i].n=0;
		}
		for(i=0;i<len;i++)
		{
			a[s[i]-'a'].n++;
		}
		sort(a,a+26,cmp);
		k=len-k;
		map<char,int> mp;
		for(i=0;i<26&&k;i++)
		{
			if(k-a[i].n>=0)
			{
				mp[a[i].id+'a']=a[i].n;
				k-=a[i].n;
			}
			else
			{
				mp[a[i].id+'a']=a[i].n;
				k=0;
			}
			cnt=i+1;
		}
		printf("%d\n",cnt);
		for(i=0;i<len;i++)
		{
			if(mp[s[i]])
			{
				printf("%c",s[i]);
				mp[s[i]]--;
			} 
		}
		puts("");
	}
    return 0;
}