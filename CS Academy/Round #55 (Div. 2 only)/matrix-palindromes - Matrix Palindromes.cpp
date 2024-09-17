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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int work(int k,vector<PII > v)
{
	int i,res=0;
	for(i=0;i<sz(v);i++)
	{
		if(k>0) res+=v[i].fi;
		k-=2;
		res+=v[i].se;
	}
	return res;
}
string s[MAX];
int main()
{
	int t,n,m,k,i,j,i1,i2,j1,j2,c1,c2,cnt[26],mx,ans;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=0;i<n;i++) cin>>s[i];
		vector<PII > res;
		for(j1=0,j2=m-1;j1<m/2;j1++,j2--)
		{
			c1=c2=0;
			for(i1=0,i2=n-1;i1<n/2;i1++,i2--)
			{
				c2+=(s[i1][j1]!=s[i1][j2]);
				c2+=(s[i2][j1]!=s[i2][j2]);
				mem(cnt,0);
				cnt[s[i1][j1]-'a']++;
				cnt[s[i1][j2]-'a']++;
				cnt[s[i2][j1]-'a']++;
				cnt[s[i2][j2]-'a']++;
				mx=0;
				for(i=0;i<26;i++) mx=max(mx,cnt[i]);
				c1+=4-mx;
			}
			if(n&1)
			{
				i1=n/2;
				mem(cnt,0);
				cnt[s[i1][j1]-'a']++;
				cnt[s[i1][j2]-'a']++;
				mx=0;
				for(i=0;i<26;i++) mx=max(mx,cnt[i]);
				c1+=2-mx;
				c2+=(s[i1][j1]!=s[i1][j2]);
			}
	//		cout<<c1<<" "<<c2<<endl;
			res.pb(MP(c1-c2,c2));
		}
		sort(all(res));
		ans=work(k,res);
		if(m&1)
		{
			j=m/2;
			c1=0;
			for(i1=0,i2=n-1;i1<n/2;i1++,i2--) c1+=(s[i1][j]!=s[i2][j]);
			if(k==m) ans=work(k-1,res)+c1;
			else ans=min(ans,work(k-1,res)+c1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
10
5 1 1
a
d
c
b
a
*/