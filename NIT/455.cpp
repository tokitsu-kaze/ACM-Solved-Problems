#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
set<string> prob;
map<string, set<int> > cont;
map<int, vector<string> > contest_list;
map<int, int> isopen;
int main()
{
//	freopen("1.in","r",stdin); 
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		string tmp;
		for(int i = 0; i < n; i++)
		{
			cin >> tmp;
			//1 refer pub
			prob.insert(tmp);
		}
		int cmd;
		int tot = 0;
		for (int i = 0; i < q; i++)
		{
			scanf("%d",&cmd);
			if (cmd == 1)
			{
				cin >> tmp;
				if(cont.find(tmp) == cont.end()) puts("DoNotExist");
				else
				{
					int cnt = cont[tmp].size();
					for (int x: cont[tmp])
					{
						if (--cnt) printf("%d ",x);
						else printf("%d\n",x);
					}
				}
			}
			else if (cmd == 2)
			{
				cin >> tmp;
				if (prob.find(tmp) == prob.end()) puts("DoNotExist");
				else puts("Response");
			}
			else if (cmd == 3) isopen[++tot] = 1;
			else if (cmd == 4)
			{
				int id;
				scanf("%d",&id);
				if (isopen[id])
				{
					isopen[id] = 0;
					for (string x : contest_list[id])
					{
						cont[x].erase(id);
						if (cont[x].size() == 0)
						{
							prob.insert(x);
							cont.erase(x);
						}
					}
					contest_list.erase(id);
				}
				else puts("Invalid");
			}
			else if (cmd == 5)
			{
				int id;
				cin >> tmp;
				scanf("%d",&id);
				if (!isopen[id]) puts("Invalid");
				else
				{
					cont[tmp].insert(id);
					contest_list[id].push_back(tmp);
					if (prob.find(tmp) != prob.end()) prob.erase(tmp);
				}
			}
		}
	}
	return 0;
}