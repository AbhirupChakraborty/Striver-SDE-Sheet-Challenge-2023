//One of the helpful article link: https://www.enjoyalgorithms.com/blog/maximum-subarray-sum
//Approach:: Brute -> Better -> Optimal
//Brute: using three nested loops --- TC: O(N^3) SC: O(1)
//Better: using two nested loops --- TC: O(N^2) SC: O(1) ... slide modification
//Optimal: using Kadane's Algorithm
//         whenever sum < 0 just discard it and make sum = 0
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=nums[0];
        for(auto it: nums){
            sum+=it;
            
            maxi=max(sum,maxi);
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
};
