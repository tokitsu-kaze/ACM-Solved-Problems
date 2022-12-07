#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
typedef vector<string> VS;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int h[MAX],dp[MAX],mxh[MAX],n;
void dfs1(TreeNode* x)
{
	n++;
	mxh[x->val]=h[x->val];
	if(x->left)
	{
		h[x->left->val]=h[x->val]+1;
		dfs1(x->left);
		mxh[x->val]=max(mxh[x->val],mxh[x->left->val]);
	}
	if(x->right)
	{
		h[x->right->val]=h[x->val]+1;
		dfs1(x->right);
		mxh[x->val]=max(mxh[x->val],mxh[x->right->val]);
	}
}
void dfs(TreeNode* x)
{
	if(x->left&&x->right)
	{
		dp[x->left->val]=max(dp[x->val],mxh[x->right->val]);
		dp[x->right->val]=max(dp[x->val],mxh[x->left->val]);
		dfs(x->left);
		dfs(x->right);
		
	}
	else if(x->left)
	{
		dp[x->left->val]=max(dp[x->val],h[x->val]);
		dfs(x->left);
	}
	else if(x->right)
	{
		dp[x->right->val]=max(dp[x->val],h[x->val]);
		dfs(x->right);
	}
}
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    	mem(h,0);
    	mem(dp,0);
    	mem(mxh,0);
    	n=0;
        h[root->val]=0;
        dfs1(root);
        dp[root->val]=0;
        dfs(root);
        VI res;
        for(auto it:queries) res.pb(dp[it]);
        for(int i=1;i<=n;i++) printf("i:%d dp:%d h:%d mxh:%d\n",i,dp[i],h[i],mxh[i]);
        return res;
    }
};
