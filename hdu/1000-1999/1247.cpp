////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 18:28:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1247
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:13812KB
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
char s[50010][50];
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
void insert(char *s)
{
	int i=0,t;
	trie *p=root;
	while(s[i])
	{
		t=s[i]-'a';
		if(p->next[t]==NULL) p->next[t]=new trie;
		p=p->next[t];
		i++;
	}
	p->v++;
}
int find(char *s)
{
	int i=0,j,flag,t;
	trie *p=root,*q;
	char *temp;
	while(s[i])
	{
		t=s[i]-'a';
		if(p->next[t]==NULL) return 0;
		p=p->next[t];
		i++;
		if(p->v)
		{
			temp=s;
			q=root;
			j=i;
			flag=1;
			while(s[j])
			{
				t=s[j]-'a';
				if(q->next[t]==NULL)
				{
					flag=0;
					break;
				}
				q=q->next[t];
				j++;
			}
			if(q->v&&flag) return 1;
			s=temp;
		}	
	}
	return 0;
}
int main()
{
	int n=0,i,j;
	root=new trie;
	mem(s,0);
	while(~scanf("%s",s[n]))
	{
		insert(s[n]);
		n++;
	}
	for(i=0;i<n;i++)
	{
		if(find(s[i])) puts(s[i]);
	}
	return 0;
}
