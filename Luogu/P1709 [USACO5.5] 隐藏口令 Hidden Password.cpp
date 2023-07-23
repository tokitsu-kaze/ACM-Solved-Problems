#include <bits/stdc++.h>
using namespace std;
const int MAX=5e6+10;
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
char s[MAX];
int main()
{
	int n,i;
	char ch;
	scanf("%d",&n);
	i=0;
	while(~scanf("%c",&ch))
	{
		if(ch=='\n'||ch=='\r'||ch==' ') continue;
		s[i++]=ch;
	}
	s[n]='\0';
	printf("%d\n",min_representation(s,n));
	return 0;
}
