#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;

struct dsu
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
int flag[MAX];

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int ans=0;
        int i;
        dsu.init(sz(nums)+1);
        for(i=1;i<=sz(nums)-1;i++) flag[i]=0;
        queue<PII > q;
        for(i=0;i<sz(nums)-1;i++)
        {
            if(nums[i]>nums[i+1]) q.push(MP(i+1,i+1));
        }
        while(!q.empty())
        {
            int sz=sz(q);
            ans++;
            int ok=0;
            while(sz--)
            {
                PII t=q.front();
                q.pop();
                t.se=dsu.find(t.fi)+1;
                
                if(t.se<=sz(nums)&&nums[t.fi-1]>nums[t.se-1]) ok=1;
                else continue;
                printf("%d %d\n",t.fi,t.se);
                flag[t.se]=1;
                dsu.merge(t.fi,t.se);
                t.se=dsu.find(t.fi);
                if(t.se<=sz(nums)&&nums[t.fi-1]>nums[t.se-1]&&!flag[t.fi]) q.push(t);
            }
            if(!ok) ans--;
            printf("%d\n",ans);
        }
        puts("***");
        return ans;
    }
};
