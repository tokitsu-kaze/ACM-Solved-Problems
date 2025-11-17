#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n;
int ask1(int x)
{
	int i,res;
	printf("?");
	for(i=1;i<n;i++) printf(" %d",n);
	printf(" %d\n",x);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}
int ask2(int a)
{
	int i,res;
	printf("?");
	for(i=1;i<n;i++) printf(" %d",a+1);
	printf(" %d\n",1);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}
int ask3(int a)
{
	int i,res;
	printf("?");
	for(i=1;i<n;i++) printf(" %d",1);
	printf(" %d\n",a+1);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}
int main()
{
	int i,p[105];
	scanf("%d",&n);
	p[n]=1;
	for(i=1;i<n;i++)
	{
		if(ask1(i))
		{
			p[n]=1+n-i;
			break;
		}
	}
	if(p[n]>1)
	{
		for(i=1;i<=p[n]-1;i++) p[ask2(i)]=p[n]-i;
	}
	if(p[n]<n)
	{
		for(i=1;i<=n-p[n];i++) p[ask3(i)]=p[n]+i;
	}
	printf("! ");
	for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	fflush(stdout);
	return 0;
}
