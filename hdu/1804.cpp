////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 22:55:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1804
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
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
	char a[22];
	trie *next[26];
	trie()
	{
		mem(a,0);
		for(int i=0;i<26;i++)
		{
			next[i]=NULL;
		}
	}
}*root;
void insert(char *s,char *c)
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
	strcpy(p->a,c);
}
void find(char *s)
{
	int i=0,t,len;
	trie *p=root;
	len=strlen(s);
	while(s[i])
	{
		t=s[i]-'a';
		if(p->next[t]==NULL)
		{
			if(s[len-1]=='o'||s[len-1]=='s'||s[len-1]=='x'||(s[len-2]=='c'&&s[len-1]=='h')||(s[len-2]=='s'&&s[len-1]=='h'))
			{
				s[len]='e';
				s[len+1]='s';
				s[len+2]='\0';
			}
			else if(s[len-1]=='y'&&(s[len-2]!='a'&&s[len-2]!='e'&&s[len-2]!='i'&&s[len-2]!='o'&&s[len-2]!='u'))
			{
				s[len-1]='i';
				s[len]='e';
				s[len+1]='s';
				s[len+2]='\0';
			}	
			else
			{
				s[len]='s';
				s[len+1]='\0';
			}
			printf("%s\n",s);
			return;
		}
		p=p->next[t];
		i++;
	}
	printf("%s\n",p->a);
}
void freetrie(trie *p)
{
	if(p==NULL) return;
	for(int i=0;i<26;i++)
	{
		if(p->next[i]!=NULL) freetrie(p->next[i]);
	}
	free(p);
}
int main()
{
	int n,m,i;
	char a[22],b[22],s[22];
	while(~scanf("%d%d",&n,&m))
	{
		root=new trie;
		getchar();
		while(n--)
		{
			scanf("%s %s",a,b);
			insert(a,b);
		}
		for(i=0;i<m;i++)
		{
			scanf("%s",s);
			find(s);
		}
		freetrie(root);
	}
	return 0;
}
