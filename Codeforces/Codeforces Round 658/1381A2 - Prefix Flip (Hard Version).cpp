#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char a[MAX],b[MAX];
int main()
{
	int T,n,i,l,r,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		vector<int> res;
		l=1;
		r=n;
		f=0;
		for(i=n;i>1;i--)
		{
			if((a[r]^f)!=b[i])
			{
				if((a[l]^f)==b[i]) res.push_back(1);
				res.push_back(i);
				swap(l,r);
				f^=1;
			}
			if(r<l) r++;
			else r--;
//			printf("%d %d\n",l,r);
		}
		assert(l==r);
		if((a[l]^f)!=b[1]) res.push_back(1);
		printf("%d",res.size());
		for(i=0;i<res.size();i++) printf(" %d",res[i]);
		puts("");
	}
	return 0;
}
