#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define MAX 10000+1
using namespace std;
typedef long long ll;
ll isprime[MAX],prime[MAX];
ll a[101],count1=0;
struct tongxun
{
	char name[11];
	ll id,qq,wx,w,pid,flag,evenodd,pri,weishu,flagpri,tel,cj;
}tx[20010];
ll countprime(ll a)
{
	ll i,sum=0;
	for(i=0;i<count1;i++)
	{
		if(a%prime[i]==0)
		{
			sum++;
			while(a%prime[i]==0)
			{
				a/=prime[i];
			}
		}
		if(a==1) break;
	}
	return sum;
}
ll cmp(tongxun a,tongxun b)
{
	if(a.w!=b.w) return a.w>b.w;
	if(strcmp(a.name,b.name)) return strcmp(a.name,b.name)<0;
	if(a.tel!=b.tel) return a.tel>b.tel;
	if(a.flag!=b.flag) return a.flag>b.flag;
	if(a.evenodd!=b.evenodd) return a.evenodd<b.evenodd;
	if(a.id!=b.id) return a.id>b.id;
	a.pri=countprime(a.cj);
	b.pri=countprime(b.cj);
	if(a.pri!=b.pri) return a.pri>b.pri;
	if(a.weishu!=b.weishu) return a.weishu>b.weishu;
	return a.pid<b.pid;
}
int main ()
{
    ll t,n,i,j;
    for(i=3;i<MAX;i+=2)
	{
		isprime[i]=1;
	}
	isprime[2]=1;
	for(i=2;i<sqrt(MAX);i++)
	{
		if(isprime[i])
		{
			for(j=i+i;j<MAX;j+=i)
			{
				isprime[j]=0;
			}
		}
	}
	for(i=2;i<MAX;i++)
	{
		if(isprime[i]) prime[count1++]=i;
	}
	memset(a,0,sizeof(a));
	for(i=1;i<=10;i++)
	{
		a[i*i]=1;
	}
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
			{
				tx[i].flagpri=tx[i].w=tx[i].evenodd=0;
				tx[i].pid=i+1;
				scanf("%s%lld%lld%lld%lld",tx[i].name,&tx[i].tel,&tx[i].id,&tx[i].qq,&tx[i].wx);
				if(tx[i].id%2) tx[i].evenodd=1;
				tx[i].cj=(long long)tx[i].qq*tx[i].wx;
				tx[i].flag=a[tx[i].id];
				for(j=0;j<strlen(tx[i].name);j++)
				{
					if(tx[i].name[j]=='w') tx[i].w++;
				}
				tx[i].weishu=tx[i].cj%2;
			}
			sort(tx,tx+n,cmp);
			for(i=0;i<n;i++)
			{
				printf("%lld\n",tx[i].pid);
			}
		}
	//	cout<<count1<<endl;
    }
    return 0;
}