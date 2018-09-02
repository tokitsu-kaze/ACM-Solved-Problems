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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*
int main()
{
	freopen("in.txt","w",stdout);
	string a[8]={"AC","CE","WA","RE","MLE","TLE","OLE","PE"};
	srand(time(0));
	printf("%d\n",1000);
	int t=1000;
	while(t--)
	{
		int n=(rand()+66)%100;
		if(n==0) n=66;
		printf("%d\n",n);
		while(n--)
		{
			int p=(rand()+66)%8;
			cout<<a[p]<<endl;
		}
	}
	return 0;
}
*/

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,t,i,flag,ans;
	char s[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=0;
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			if(flag) continue;
			if(strcmp(s,"AC")==0) flag=1;
			else if(strcmp(s,"CE")==0);
			else ans++;
		}
		if(flag) printf("%d\n",ans*20);
		else puts("-1");
	}
	return 0;
}
/*
2
5
WA
TLE
CE
AC
MLE
3
WA
TLE
CE
*/
