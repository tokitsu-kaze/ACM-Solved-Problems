int cal(int k,int op)
{
    if(k==1 || op==1) return op+1;
    else return cal(k-1,op-1)+cal(k,op-1);
}
class Solution {
public:
    int superEggDrop(int k, int n) {
        int op=1;
        while(cal(k,op)<=n) op++;
        return op;
    }
};
