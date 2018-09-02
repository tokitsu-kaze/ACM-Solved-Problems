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
	freopen("in.txt","w",stdout);
	srand(time(0));
	int t=1000;
	printf("%d\n",t);
	while(t--)
	{
		int n=rand()%20001;
		printf("%d\n",n);
	}
	return 0;
}
*/
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,cas=1,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		printf("Case #%d:\n",cas++);
		while(k--)
		{
			putchar('$');
		}
		puts("");
		if(t) puts("");
	}
	return 0;
}