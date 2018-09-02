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
const int MAX=(1L<<20)+10;
const ll mod=1e9+7;
/*
int main()
{
	int flag[]={1,-1,1},nn[]={0,20};
	freopen("in.txt","w",stdout);
	srand(time(0));
	int t=20;
	while(t--)
	{
		int n=(rand()+7)%20;
		if(n==0) n=nn[rand()%2];
		if(!t) n=20;
		int temp=(1<<n);
		printf("%d\n",temp);
		if(!t)
		{
			temp--;
			printf("-1000000 ");
		}
		while(temp--)
		{
			int v=(rand()%1000000)*flag[rand()%3];
			if(temp) printf("%d ",v);
			else printf("%d\n",v);
		}
	}
	return 0;
}
*/
int a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,now,p;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		now=a[1];
		sort(a+1,a+n+1);
		p=upper_bound(a+1,a+1+n,now)-a;
		p--;
		int cnt=0;
		while(p)
		{
			p>>=1;
			cnt++;
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}