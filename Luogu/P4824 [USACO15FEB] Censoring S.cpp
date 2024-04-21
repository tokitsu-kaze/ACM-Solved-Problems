#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
struct KMP
{
	#define type char
	int nex[MAX],len;
	type t[MAX];
	void get_next(type *s,int n)
	{
		int i,j;
		len=n;
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]=0;
		nex[0]=nex[1]=0;
		j=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
	}
	int st[MAX],now[MAX];
	void match(type *s,int n)
	{
		int i,j,top;
		top=0;
		for(i=1,j=0;i<=n;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			st[top++]=i;
			now[i]=j;
			if(j==len)
			{
				top-=len;
				j=now[st[top-1]];
			}
		}
		string res;
		for(i=0;i<top;i++) res+=s[st[i]];
		cout<<res<<"\n";
	}
	#undef type
}kmp;
/*
kmp.get_next(t,len); // t[1..len]
kmp.match(s,n); // s[1..n] return all pos t in s 
*/
char s[MAX],t[MAX];
int main()
{
	int n,m;
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	kmp.get_next(t,m);
	kmp.match(s,n);
	return 0;
}
/*
ababaabz
abaab
*/
