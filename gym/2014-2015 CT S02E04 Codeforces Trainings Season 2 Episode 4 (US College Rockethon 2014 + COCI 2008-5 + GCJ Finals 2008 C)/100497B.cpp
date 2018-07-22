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
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
char a[MAX],b[MAX],*mid,temp[MAX],t[MAX];
vector<string> ans;
void check(char *a,char *b)
{
	int i;
	for(i=0;i<strlen(b);i++)
	{
		if(a[i]!=b[i]) return;
	}
//	cout<<a<<b<<endl;
	strcpy(temp,a);
	strcpy(t,b);
	reverse(t,t+strlen(t));
	strcat(temp,t);
	ans.pb(temp);
}
int main()
{
	int i,len;
	while(~scanf("%s",a))
	{
		ans.clear();
		mid=0;
		len=strlen(a);
		if(len&1) mid=&a[len/2];
		strcpy(b,a+(len+1)/2);
		reverse(b,b+strlen(b));
		a[(len+1)/2]='\0';
	//	cout<<a<<endl;
	//	cout<<b<<endl;
		len=strlen(b);
		vector<int> v;
		for(i=0;i<len;i++)
		{
			if(a[i]!=b[i]) v.pb(i);
		}
		if((int)sz(v)>3)
		{
			puts("0");
			continue;
		}
		if((int)sz(v)==1)
		{
			if(mid==0) puts("0");
			else
			{
				swap(a[v[0]],*mid);
				check(a,b);
				swap(a[v[0]],*mid);
				swap(b[v[0]],*mid);
				check(a,b);
				swap(b[v[0]],*mid);
				puts("1");
				cout<<ans[0]<<endl;
			}
			continue;
		}
		if((int)sz(v)==0)
		{
			puts("1");
			reverse(b,b+strlen(b));
			printf("%s%s\n",a,b);
			continue;
		}
		swap(a[v[0]],a[v[1]]);
		check(a,b);
		swap(a[v[0]],a[v[1]]);
		swap(b[v[0]],b[v[1]]);
		check(a,b);
		swap(b[v[0]],b[v[1]]);
		swap(a[v[0]],b[v[1]]);
		check(a,b);
		swap(a[v[0]],b[v[1]]);
		swap(b[v[0]],a[v[1]]);
		check(a,b);
		swap(b[v[0]],a[v[1]]);
		sort(all(ans));
		ans.resize(unique(all(ans))-ans.begin());
		printf("%d\n",(int)sz(ans));
		for(i=0;i<sz(ans);i++) cout<<ans[i]<<endl;
	}
	return 0;
}