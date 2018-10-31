#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long  ll;
long long  pmod(long long  a, long long b, long long  n)
{
	long long  ret = 1;
	long long tmp = a;
	while (b)
	{
		if (b & 0x1) ret = ret*tmp%n;
		tmp = tmp*tmp%n;
		b >>= 1;
	}
	return ret;
}
char s[300000];
#include<bits/stdc++.h>
const long long mod=(long long )1e9+7;
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",s);
		int len=strlen(s);
		reverse(s,s+len);
		long long cnt=0;
		long long radix=1;
		for(int i=0;i<len;i++)
		{
			cnt=(cnt+(s[i]-'0')*radix%(mod-1));
			cnt%=(mod-1);
			radix=(radix*10)%(mod-1);
		}
		cnt-=1;
		cnt+=(mod-1);
		cnt%=(mod-1);
		cout<<pmod(2,cnt,mod)<<"\n";
	}
	return 0;
}