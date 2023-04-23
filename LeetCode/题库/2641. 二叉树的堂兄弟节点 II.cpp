#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
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
int tot;
int h[MAX],sum[MAX],subval[MAX];
void dfs(TreeNode* x,int pre)
{
	if(x==NULL) return;
	int id=++tot;
	h[id]=h[pre]+1;
	sum[h[id]]+=x->val;
	subval[id]=0;
	if(x->left) subval[id]+=x->left->val;
	if(x->right) subval[id]+=x->right->val;
	dfs(x->left,id);
	dfs(x->right,id);
//	printf("%d %d %d\n",id,x->val,subval[id]);
}
void dfs2(TreeNode* x,int pre)
{
	if(x==NULL) return;
	int id=++tot;
	h[id]=h[pre]+1;
	dfs2(x->left,id);
	dfs2(x->right,id);
	x->val=sum[h[id]]-subval[pre];
}
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
    	tot=0;
    	h[0]=0;
    	memset(sum,0,sizeof sum);
        dfs(root,0);
    /*    for(int i=1;i<=tot;i++)
        {
        	printf("%d %d\n",i,sum[i]);
		}*/
        tot=0;
    	h[0]=0;
        dfs2(root,0);
        if(root) root->val=0;
        return root;
    }
};
