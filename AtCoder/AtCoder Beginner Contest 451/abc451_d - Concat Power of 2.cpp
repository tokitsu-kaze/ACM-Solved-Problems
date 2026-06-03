#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int LIMT=1e9;
string sd[33];
map<int,int> mp;
vector<int> res;
void bfs()
{
	int i,x;
	queue<int> q;
	for(i=0;(1<<i)<=LIMT;i++)
	{
		q.push(1<<i);
		mp[(1<<i)]=1;
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		res.push_back(x);
		string s=to_string(x);
		for(i=0;(1<<i)<=LIMT;i++)
		{
			ll nex=stoll(s+sd[i]);
			if(nex>LIMT) continue;
			if(mp.count(nex)) continue;
			q.push(nex);
			mp[nex]=1;
		}
	}
}
int main()
{
	int n,i,len;
	res.clear();
	for(i=0;(1<<i)<=LIMT;i++) sd[i]=to_string(1<<i);
	bfs();
	sort(res.begin(),res.end());
//	printf("%d\n",(int)res.size());
	scanf("%d",&n);
	printf("%d\n",res[n-1]);
	return 0;
}
