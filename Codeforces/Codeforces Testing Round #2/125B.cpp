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
typedef long long ll;
int main()
{
	int i,j,k,h,tag[1111],t;
	char temp[11],a[1111],c;
	while(gets(a))
	{
		mem(temp,0);
		mem(tag,0);
		k=h=t=0;
		map<int,int> mp;
		map<char,int> cm;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]>='a'&&a[i]<='z')
			{
				if(a[i-1]=='/')
				{
					h--;
					tag[t]=tag[mp[a[i]+cm[a[i]]*100]];
					mp[a[i]+cm[a[i]]*100]=0;
					cm[a[i]]--;
					t++;
				}
				else
				{
					cm[a[i]]++;
					h++;
					mp[a[i]+cm[a[i]]*100]=t;
					tag[t++]=h;
				}
			}
		}
		t=0;
		for(i=0;i<strlen(a);i++)
		{
			temp[k++]=a[i];
			if(a[i]=='>')
			{
				for(j=0;j<tag[t]*2-2;j++)
				{
					printf(" ");
				}
				t++;
				printf("%s\n",temp);
				mem(temp,0);
				k=0;
			}
		}
	}
    return 0;
}