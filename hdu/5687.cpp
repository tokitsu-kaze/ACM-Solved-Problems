////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-04 15:51:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5687
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:79984KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=9973;
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
		if(p->next[t]==NULL)
		{
//			puts("null");
			p->next[t]=new trie;
		}
		p=p->next[t];
		p->v++;
//		cout<<s[i]<<" "<<p->v<<endl;
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
		if(p->v==0) return 0;
//		cout<<p->v<<endl;
		i++;
	}
	return 1;
}
void del(char *s)
{
	int i=0,t,temp;
	trie *p,*pre;
	pre=p=root;
	while(s[i])
	{
		t=s[i]-'a';
		if(p->next[t]==NULL) return;
		if(!s[i+1])
		{
			temp=p->next[t]->v;
			p->next[t]=NULL;
			break;
		}
		pre=p;
		p=p->next[t];
		i++;
	}
//	cout<<temp<<endl;
	i=0;
	p=root;
	while(s[i])
	{
		t=s[i]-'a';
		if(p->next[t]==NULL) return;
		p=p->next[t];
		p->v-=temp;
//		cout<<s[i]<<" "<<p->v<<endl;
		i++;
	}
}
int main()
{
	int n;
	char op[111],a[111];
	while(~scanf("%d",&n))
	{
		root=new trie;
		while(n--)
		{
			scanf("%s %s",op,a);
			if(op[0]=='i') insert(root,a);
			else if(op[0]=='d') del(a);
			else if(op[0]=='s')
			{
				if(find(root,a)) puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}
/*
9
search h
delete hee
insert hello
delete h
search h
insert hehe
search h
delete he
search h
8
insert abcd
delete ab
search abcd
insert abc
search abcd
search abc
delete ab
search a
*/