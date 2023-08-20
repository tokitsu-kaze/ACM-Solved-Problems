////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-27 18:23:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6015
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
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
#define MAX 100000+10
using namespace std;
typedef long long ll;
struct lesson
{
	char name[21];
	int v;
}l[110];
int cmp(lesson a,lesson b)
{
	if(strcmp(a.name,b.name)==0) return a.v>b.v;
	return strcmp(a.name,b.name)<0;
}
int main()
{
    int t,n,i,sum,flag;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
			{
				getchar();
				scanf("%s %d",l[i].name,&l[i].v);
			}
			sort(l,l+n,cmp);
			sum=l[0].v;
			flag=1;
			for(i=1;i<n;i++)
			{
				if(strcmp(l[i].name,l[i-1].name)==0)
				{
					if(flag<2)
					{
						flag++;
						sum+=l[i].v;
					}
					else continue;
				}
				else
				{
					flag=1;
					sum+=l[i].v;
				}
			}
			cout<<sum<<endl;
		}
	}
    return 0;
}