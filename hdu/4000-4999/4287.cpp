////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 21:50:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4287
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:15844KB
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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
struct trie
{
	int v,flag;
	trie *next[10];
	trie()
	{
		v=0;
		flag=0;
		for(int i=0;i<10;i++)
		{
			next[i]=NULL;
		}
	}
}*root;
map<char,int> mp;
void insert(char *s)
{
	int i=0,t;
	trie *p=root;
	while(s[i])
	{
		t=mp[s[i]];
		if(p->next[t]==NULL) p->next[t]=new trie;
		p=p->next[t];
		p->v++;
		i++;
	}
	p->flag=1;
}
int find(char *s)
{
	int i=0,t;
	trie *p=root;
	while(s[i])
	{
		t=s[i]-'0';
		if(p->next[t]==NULL) break;
		p=p->next[t];
		i++;
	}
	if(p->flag) return p->v;
	else return 0;
}
int main()
{
	int t,n,m,i;
	char c[11],s[5010][11];
	mp['a']=2;
	mp['b']=2;
	mp['c']=2;
	mp['d']=3;
	mp['e']=3;
	mp['f']=3;
	mp['g']=4;
	mp['h']=4;
	mp['i']=4;
	mp['j']=5;
	mp['k']=5;
	mp['l']=5;
	mp['m']=6;
	mp['n']=6;
	mp['o']=6;
	mp['p']=7;
	mp['q']=7;
	mp['r']=7;
	mp['s']=7;
	mp['t']=8;
	mp['u']=8;
	mp['v']=8;
	mp['w']=9;
	mp['x']=9;
	mp['y']=9;
	mp['z']=9;
	scanf("%d",&t);
	while(t--)
	{
		root=new trie;
		mem(c,0);
		mem(s,0);
		scanf("%d%d",&n,&m);
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%s",c);
			insert(c);
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",find(s[i]));
		}
	}
	return 0;
}
