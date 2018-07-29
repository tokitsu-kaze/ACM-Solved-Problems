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
struct card
{
	char s;
	int id;
}c,ans[110];
void oprt()
{
	if(c.s=='U') c.s='D';
	else c.s='U';
}
int main()
{
    int n,i,k,t=1,qs,m,l,r;
    char op;
	while(cin>>n&&n)
	{
		getchar();
		stack<card> s[110];
		k=1;
		for(i=0;i<n;i++)
		{
			scanf("%c",&c.s);
			c.id=k++;
			s[i].push(c);
		}
		getchar();
		l=0;
		r=n-1;
		for(i=0;i<n-1;i++)
		{
			scanf("%c",&op);
			if(op=='L')
			{
				while(!s[l].empty())
				{
					c=s[l].top();
					s[l].pop();
					oprt();
					s[l+1].push(c);
				}
				l++;
			}
			else if(op=='R')
			{
				while(!s[r].empty())
				{
					c=s[r].top();
					s[r].pop();
					oprt();
					s[r-1].push(c);
				}
				r--;
			}
		}
		i=1;
		while(!s[l].empty())
		{
			ans[i++]=s[l].top();
			s[l].pop();
		}
		printf("Pile %d\n",t++);
		cin>>m;
		while(m--)
		{
			cin>>qs;
			printf("Card %d is a face ",qs);
			if(ans[qs].s=='U') printf("up %d.\n",ans[qs].id);
			else if(ans[qs].s=='D') printf("down %d.\n",ans[qs].id);
		}
	} 
    return 0;
}