#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	scanf("%d",&n);
	vector<int> res;
	for(i=0;i<30;i++)
	{
		if(n>=(1<<i))
		{
			res.push_back(1<<i);
			n-=(1<<i);
		}
	}
	if(n)
	{
		if(n==1) res.push_back(n);
		else
		{
			for(auto &it:res)
			{
				if(n==it)
				{
					n--;
					res.back()++;
					break;
				}
			}
			res.push_back(n);
		}
	}
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	return 0;
}
