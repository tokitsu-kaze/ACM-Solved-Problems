////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-12 22:13:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
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
#include <vector>
#include <set>
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=10000;
struct node
{
	int a,b;
	node(){}
	node(int c,int d)
	{
		a=c;
		b=d;
	}
}m[33];
int main()
{
	int n,i,t1,t2;
	char c,s[1111];
	scanf("%d",&n);
	mem(m,0);
	for(i=0;i<n;i++)
	{
		getchar();
		scanf("%c %d %d",&c,&t1,&t2);
		m[c-'A'].a=t1;
		m[c-'A'].b=t2;
	}
	while(~scanf("%s",s))
	{
		stack<node> sk;
		node a,b;
		int flag=0,sum=0;
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]!='('&&s[i]!=')')
			{
				sk.push(m[s[i]-'A']);
			}
			else
			{
				if(s[i]=='(') continue;
				b=sk.top();
				sk.pop();
				a=sk.top();
				sk.pop();
				if(a.b==b.a)
				{
					sum+=a.a*a.b*b.b;
					sk.push(node(a.a,b.b));
				}
				else
				{
					flag=1;
					break;
				}
			}
		}
		if(flag) puts("error");
		else printf("%d\n",sum);
	}
	return 0;
}