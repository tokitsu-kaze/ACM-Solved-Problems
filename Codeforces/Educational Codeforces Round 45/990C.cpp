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
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
char st[MAX],tmp[MAX];
int main()
{
	int n,i,tot,j;
	ll ans;
	string s;
	while(~scanf("%d",&n))
	{
		ans=0;
		map<string,int> mp;
		for(i=0;i<n;i++)
		{
			cin>>s;
			tot=0;
			for(j=0;j<s.length();j++)
			{
				if(s[j]=='(') st[tot++]=s[j];
				else
				{
					if(!tot) st[tot++]=s[j];
					else if(st[tot-1]=='(') tot--;
					else st[tot++]=s[j];
				}
			}
			st[tot]='\0';
			for(j=0;j<tot;j++)
			{
				if(st[j]=='(') tmp[j]=')';
				else tmp[j]='(';
			}
			tmp[tot]='\0';
			ans+=mp[tmp];
			mp[st]++;
			if(strcmp(tmp,st)==0) ans+=mp[tmp];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
