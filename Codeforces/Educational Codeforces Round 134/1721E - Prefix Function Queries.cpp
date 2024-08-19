#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+20;
struct KMP_Automaton
{
	#define type char
	static const int K=26;
	int nex[MAX],len,lst[MAX][K];
	type t[MAX];
	int get_id(char c){return c-'a';} //may need change
	void get_next(type *s,int n)
	{
		int i,j,k;
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
		memset(lst[0],0,sizeof lst[0]);
		for(i=1;i<=len;i++)
		{
			for(k=0;k<K;k++) lst[i][k]=lst[nex[i]][k];
			if(i+1<=len) lst[i][get_id(s[i+1])]=i;
		}
	}
	void get_next_new(type *s,int n)
	{
		int i,j;
		for(i=len+1;i<=n;i++) t[i]=s[i];
		t[n+1]=0;
		j=nex[len];
		for(i=len+1;i<=n;i++)
		{
			while(j&&t[j+1]!=s[i])
			{
				if(j<=len)
				{
					j=lst[j][get_id(s[i])];
					break;
				}
				else j=nex[j];
			}
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
	}
	#undef type
}kmp;
/*
kmp.get_next(t,len); // t[1..len]
*/
char s[MAX],t[12];
int main()
{
	int n,m,q,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	kmp.get_next(s,n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",t+1);
		m=strlen(t+1);
		for(i=n+1;i<=n+m;i++) s[i]=t[i-n];
		kmp.get_next_new(s,n+m);
		for(i=n+1;i<=n+m;i++) printf("%d%c",kmp.nex[i]," \n"[i==n+m]);
	}
	return 0;
}

