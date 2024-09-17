#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
string s[MAX];
int bit[333],temp[333];
int main()
{
	int n,i,j,ans;
	while(~scanf("%d",&n))
	{
		mem(bit,0);
		ans=0;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			bit[s[i][0]]++;
		}
		for(i=0;i<n;i++)
		{
			bit[s[i][0]]--;
			mem(temp,0);
			for(j=0;j<s[i].length();j++)
			{
				temp[s[i][j]]++;
			}
			int flag=1;
			for(j='a';j<='z';j++)
			{
				if(temp[j]>bit[j]) flag=0;
			}
			bit[s[i][0]]++;
			ans+=flag;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5
abc
bcad
cabd
cba
dzzz
3
gnu
not
unix
4
a
aa
aaaa
aaaaa
2
ab
ba
*/