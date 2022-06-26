class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int start=k-1;
        int len=cardPoints.size()-1;
        int sum=0,res=0;
        for(int i=0;i<k;i++)
		{
				sum+=cardPoints[i];
        }
        res=sum;
        while(start>=0 && start<len){
            sum+=cardPoints[len]-cardPoints[start];
            res=max(res,sum);
            len--; 
            start--;
        }
        return res;
    
    }
};