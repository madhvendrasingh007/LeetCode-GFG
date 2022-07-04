class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(); //number of children
        if(n==0 or n==1)return n; //base case
        //create an array to store the number of candies you are giving to children i.
        vector<int> candies(n,1); //minimum number candies you can give is 1
        /*
          To ensure that, children with a higher rating gets more candies than their neighbors:
          We can check from both the ends of array ratings and increase the number of candies
          wherever necessary.
        */
        for(int i=0;i<n-1;i++){ //checking from  left end
            if(ratings[i+1]>ratings[i])
                candies[i+1]=candies[i]+1;
        }
        for(int i=n-1;i>0;i--){ //checking form right end
            if(ratings[i-1]>ratings[i])
                candies[i-1]=max(candies[i-1],candies[i]+1);
        }
        //Now the candies array have all the given number candies. We can just add them now to get the answer.
        int ans=0;
        for(auto a:candies)ans+=a;
        return ans;
    }
};