class Solution {
public:
    bool checkPowersOfThree(int n) {
		int i,now;
		now=1;
		for(i=1;i<16;i++) now*=3;
		while(now>0)
		{
			if(n>=now) n-=now;
			now/=3;
		}
		return n==0;
    }
};
