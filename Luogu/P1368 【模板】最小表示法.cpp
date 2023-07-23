#include <bits/stdc++.h>
using namespace std;
const int MAX=3e5+10;
int min_representation(int *s,int n) // s[0..n-1]
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
int a[MAX],res[MAX];
int main()
{
	int n,i,j,pos;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	pos=min_representation(a,n);
	j=0;
	for(i=pos;i<n;i++) res[++j]=a[i];
	for(i=0;i<pos;i++) res[++j]=a[i];
	for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}
