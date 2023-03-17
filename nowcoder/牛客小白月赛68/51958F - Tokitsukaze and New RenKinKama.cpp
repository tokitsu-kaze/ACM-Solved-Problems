#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;

int v[MAX],n,k;

vector<int> get_bad_pos()
{
	int i;
	vector<int> res;
	if(abs(v[0]-v[n-1])>k || abs(v[0]-v[1])>k) res.push_back(0);
	for(i=1;i<n-1;i++)
	{
		if(abs(v[i]-v[i-1])>k || abs(v[i]-v[i+1])>k) res.push_back(i);
	}
	if(abs(v[n-1]-v[n-2])>k || abs(v[n-1]-v[0])>k) res.push_back(n-1);
	return res;
}
int main()
{
	int T,i,j,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++) scanf("%d",&v[i]);
		if(n==1)
		{
			puts("0");
			continue;
		}
		vector<int> res,res2;
		res=get_bad_pos();
		if(res.size()==0)
		{
			puts("0");
			continue;
		}
		if(res.size()>12)
		{
			puts("-1");
			continue;
		}
		
		for(auto &it:res)
		{
			for(i=0;i<n;i++)
			{
				if(it==i) continue;
				
				swap(v[it],v[i]);
				res2=get_bad_pos();
				if(res2.size()==0)
				{
					puts("1");
					printf("%d %d\n",it+1,i+1);
					goto end;
				}
				if(res2.size()>6)
				{
					swap(v[it],v[i]);
					continue;
				}
				for(auto &it2:res2)
				{
					for(j=0;j<n;j++)
					{
						if(it2==j) continue;
						swap(v[it2],v[j]);
						ok=1;
						for(auto &pos:res2)
						{
							if(abs(v[pos]-v[(pos-1+n)%n])>k) ok=0;
							if(abs(v[pos]-v[(pos+1)%n])>k) ok=0;
						}
						if(abs(v[j]-v[(j-1+n)%n])>k) ok=0;
						if(abs(v[j]-v[(j+1)%n])>k) ok=0;
						if(ok)
						{
							
							puts("2");
							printf("%d %d\n",it+1,i+1);
							printf("%d %d\n",it2+1,j+1);
							goto end;
						}
						swap(v[it2],v[j]);
					}
				}
				swap(v[it],v[i]);
			}
		}
		puts("-1");
		end:;
	}
	return 0;
}

