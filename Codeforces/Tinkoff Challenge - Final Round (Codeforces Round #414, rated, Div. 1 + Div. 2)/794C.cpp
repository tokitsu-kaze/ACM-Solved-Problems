#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
char a[MAX],b[MAX],ans[MAX];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	int len,l,r,ai,aj,bi,bj;
	while(~scanf("%s %s",a,b))
	{
		len=strlen(a);
		sort(a,a+len);
		sort(b,b+len,cmp);
		ai=bi=l=0;
		aj=bj=(len-1)/2;
		if(len%2) bj--;
		r=len-1;
	//	puts(a);
	//	puts(b);
		while(l<=r)
		{
			if(a[ai]>=b[bi]) ans[r--]=a[aj--];
			else ans[l++]=a[ai++];
			if(l>r) break;
			if(b[bi]<=a[ai]) ans[r--]=b[bj--];
			else ans[l++]=b[bi++];
		}
		ans[len]='\0';
		puts(ans);
	}
	return 0;
}