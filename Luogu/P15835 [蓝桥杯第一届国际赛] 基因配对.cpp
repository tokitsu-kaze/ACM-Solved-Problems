#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
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
	int match(type *s,int n)
	{
		int i,j;
		for(i=1,j=0;i<=n;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			if(j==len) return i-len+1;
		}
		return 0;
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
	int n,m,i;
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='A') s[i]='T';
		else if(s[i]=='T') s[i]='A';
		else if(s[i]=='G') s[i]='C';
		else if(s[i]=='C') s[i]='G';
	}
	kmp.get_next(t,m);
	printf("%d\n",kmp.match(s,n));
	return 0;
}
