#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
struct node{int l,r;};
int a[MAX];
int main()
{
	int T,n,i,j,pos,len,l;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		vector<node> res;
		for(i=1;i<=n;i++)
		{
			while(a[i]!=i)
			{
				for(j=i+1;j<=n;j++)
				{
					if(a[j]==i)
					{
						pos=j;
						break;
					}
				}
				len=pos-i+1;
				if(len&1)
				{
					if(pos==n)
					{
						l=i+1;
						len--;
					}
					else
					{
						l=i;
						len++;
						pos++;
					}
				}
				else l=i;
				res.push_back({l,pos});
				len/=2;
				for(j=l;j+len<=pos;j++) swap(a[j],a[j+len]);
//				for(j=1;j<=n;j++) printf("%d%c",a[j]," \n"[j==n]);
			}
		}
		printf("%d\n",(int)res.size());
		for(auto &it:res) printf("%d %d\n",it.l,it.r);
	}
	return 0;
}
/*
每次模拟次数是nlogn级别，复杂度呢？
感觉常数很小。
*/
