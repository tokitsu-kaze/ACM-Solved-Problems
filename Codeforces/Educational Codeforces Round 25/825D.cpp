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
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e6;
char a[MAX],b[MAX];
int cnt[1111];
struct node
{
	char c;
	int k,cnt;
	node(){}
	node(char a,int b)
	{
		c=a;
		k=b;
	}
	friend bool operator <(node a,node b)
	{
		return a.k>b.k;
	}
}nd[1111];
int main()
{
	int i,lena,lenb,pos;
	node t;
	while(~scanf("%s%s",a,b))
	{
		priority_queue<node> q;
		for(i=0;i<333;i++)
		{
			nd[i].cnt=0;
		}
		mem(cnt,0);
		lena=strlen(a);
		lenb=strlen(b);
		for(i=0;i<lenb;i++)
		{
			cnt[b[i]]++;
			nd[b[i]].c=b[i];
		}
		for(i=0;i<lena;i++)
		{
			if(a[i]!='?')
			{
				if(cnt[a[i]]) nd[a[i]].cnt++;
			}
		}
		for(i=0;i<333;i++)
		{
			if(cnt[i])
			{
				nd[i].k=nd[i].cnt/cnt[i];
				q.push(nd[i]);
			}
		}
		for(i=0;i<lena;i++)
		{
			if(a[i]!='?') putchar(a[i]);
			else
			{
				if(!q.size()) putchar('a');
				else
				{
					t=q.top();
					q.pop();
					putchar(t.c);
					t.cnt++;
					t.k=t.cnt/cnt[t.c];
					q.push(t);
				}
			}
		}
		puts("");
	}
	return 0;
}