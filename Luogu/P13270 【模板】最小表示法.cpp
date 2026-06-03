#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e7+10;
int min_representation(char *s,int n) // s[0..n-1]
{
	int i,j,k,tmp;
	i=k=0;
	j=1;
	while(i<n&&j<n&&k<n)
	{
		tmp=s[(i+k)%n]-s[(j+k)%n];
		if(!tmp) k++;
		else
		{
			if(tmp>0) i=i+k+1;
			else j=j+k+1;
			if(i==j) j++;
			k=0;
		}
	}
	return i<j?i:j;
}
char s[MAX],res[MAX];
int main()
{
	int n,i,pos,tot;
	scanf("%d",&n);
	scanf("%s",s);
	pos=min_representation(s,n);
	tot=0;
	for(i=pos;i<n;i++) res[tot++]=s[i];
	for(i=0;i<pos;i++) res[tot++]=s[i];
	res[tot]='\0';
	puts(res);
	return 0;
}
