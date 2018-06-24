////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-05 22:28:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1251
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:45392KB
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
	int v;
	trie *next[26];
	trie()
	{
		v=0;
		for(int i=0;i<26;i++)
		{
			next[i]=NULL;
		}
	}
}*root;
void insert(trie *p,char *s)
{
	int i=0,t;
	while(s[i])
	{
		t=s[i]-'a';
		if(p->next[t]==NULL) p->next[t]=new trie;
		p=p->next[t];
		p->v++;
		i++;
	}
}
int find(trie *p,char *s)
{
	int i=0,t;
	while(s[i])
	{
		t=s[i]-'a';
		if(p->next[t]==NULL) return 0;
		p=p->next[t];
		i++;
	}
	return p->v;
}
int main()
{
	char s[11];
	root=new trie;
	while(gets(s)&&strlen(s))
	{
		insert(root,s);
	}
	while(gets(s))
	{
		printf("%d\n",find(root,s));
	}
	return 0;
}