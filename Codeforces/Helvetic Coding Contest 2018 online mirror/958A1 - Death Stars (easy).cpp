#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=5e5+10;
const ll mod=1e9+7;
int n;
char a[22][22],b[22][22],tmp[22][22];
int check()
{
	int i,j,flag;
	flag=0;
	for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
		{
			tmp[i][j]=a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(tmp[i],b[i])==0);
		else flag=1;
	}
	if(!flag) return 1;
	flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			tmp[j][n-i-1]=a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(tmp[i],b[i])==0);
		else flag=1;
	}
	if(!flag) return 1;
	flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			tmp[n-i-1][n-j-1]=a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(tmp[i],b[i])==0);
		else flag=1;
	}
	if(!flag) return 1;
	flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			tmp[n-j-1][i]=a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(tmp[i],b[i])==0);
		else flag=1;
	}
	if(!flag) return 1;
	return 0;
}
int main()
{
	int i,j;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++) scanf("%s",a[i]);
		for(i=0;i<n;i++) scanf("%s",b[i]);
		if(check())
		{
			puts("Yes");
			continue;
		}
		for(i=0;i<n;i++)
	    {
			reverse(a[i],a[i]+n);
		}
		if(check())
		{
			puts("Yes");
			continue;
		}
		for(i=0;i<n;i++)
	    {
			reverse(a[i],a[i]+n);
		}
		for(i=0;i<n/2;i++)
		{
			for(j=0;j<n;j++)
			{
				swap(a[i][j],a[n-i-1][j]);
			}
		}
		if(check()) puts("Yes");
		else puts("No");
	}
	return 0;
}