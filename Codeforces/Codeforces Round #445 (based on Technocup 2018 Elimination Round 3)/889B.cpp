#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
char a[MAX],ans[33];
int nex[333],pre[333];
int main()
{
	int n,i,j,k,len,flag[333],cnt,tag;
	while(~scanf("%d",&n))
	{
		mem(nex,0);
		mem(pre,0);
		tag=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			len=strlen(a);
			if(len>26) tag=1;
			mem(flag,0);
			for(j=0;j<len;j++)
			{
				if(flag[a[j]]) tag=1;
				flag[a[j]]++;
				if(j)
				{
					if(nex[a[j-1]]!=(int)a[j]&&nex[a[j-1]]>0) tag=1;
					if(pre[a[j]]!=(int)a[j-1]&&pre[a[j]]>0) tag=1;
					nex[a[j-1]]=(int)a[j];
					pre[a[j]]=(int)a[j-1];
				}
				if(nex[a[j]]==pre[a[j]]&&nex[a[j]]!=0) tag=1;
			}
			if(!nex[a[len-1]]) nex[a[len-1]]=-1;
		}
		if(tag) goto end;
		mem(flag,0);
		mem(ans,0);
		cnt=0;
		for(i='a';i<='z';i++)
		{
			if(!flag[i])
			{
				if(!pre[i]||pre[i]==(int)ans[cnt-1]);
				else continue;
				if(!nex[i]) continue;
				int temp=i;
				while(1)
				{
					if(temp==-1) break;
					ans[cnt++]=(char)temp;
					flag[temp]=1;
					temp=nex[temp];
				}
			}
		}
		for(i='a';i<='z';i++)
		{
			if(nex[i]>0&&!flag[i])
			{
				tag=1;
				goto end;
			}
		}
		if(tag) goto end;
		puts(ans);
		end:;
		if(tag) puts("NO");
	}
	return 0;
}
/*
2
ab
ba
3
ab
bc
ca
4
mail
ai
lru
4
ab
bc
ca
nm
cf
*/