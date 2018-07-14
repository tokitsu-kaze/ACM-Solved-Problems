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
const int MAX=1e3+10;
const ll mod=1e9+7;
struct node
{
	char x;
	int p[MAX];
	int k,tag;
	friend bool operator<(const node &a,const node &b)
	{
		if(a.k==b.k)
		{
			for(int i=a.k;i>=0;i--)
			{
					
				if(a.p[i]==b.p[i]) continue;
				else return a.p[i]>b.p[i];
			}
			return a.x>b.x;
		}
		else return a.k>b.k;
	}
}mp[26];
char a[MAX];
int main()
{
	int n,i,j,k,id,len,cas=1,f;
	ll ans,temp;
	while(~scanf("%d",&n))
	{
		for(i=0;i<10;i++)
		{
			mp[i].k=-1;
			mp[i].x='a'+i;
			mem(mp[i].p,0);
			mp[i].tag=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			len=strlen(a);
			for(j=len-1,k=0;j>=0;j--,k++)
			{
				if(j==0) mp[a[j]-'a'].tag=1;
				mp[a[j]-'a'].p[k]++;
				mp[a[j]-'a'].k=max(mp[a[j]-'a'].k,k);
				int pos=k;
				while(mp[a[j]-'a'].p[pos]>=10)
				{
					mp[a[j]-'a'].p[pos+1]+=mp[a[j]-'a'].p[pos]/10;
					mp[a[j]-'a'].p[pos]%=10;
					pos++;
					mp[a[j]-'a'].k=max(mp[a[j]-'a'].k,pos);
				}
			}
		}
		sort(mp,mp+10);
		f=0;
		for(i=0;i<10;i++)
		{
			if(mp[i].k!=-1)
			{
				if(!mp[i].tag) f=1;
			}
			else break;
		}
		if(f)
		{
			node t=mp[0];
			for(i=1;i<10;i++)
			{
				if(mp[i].k==-1) break;
				swap(t,mp[i]);
				if(t.tag==0) break;
			}
			mp[0]=t;
		}
		ans=0;
		for(i=f^1,id=0;i<10;i++,id++)
		{
			if(mp[id].k==-1) break;
			temp=1;
			for(j=0;j<=mp[id].k;j++)
			{
				ans+=temp*(ll)i*mp[id].p[j];
				temp*=10;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}