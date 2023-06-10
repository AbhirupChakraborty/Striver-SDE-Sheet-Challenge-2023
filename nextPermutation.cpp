//Three Approach: Brute -> Better -> Optimal
/*Brute: 1. Generate all permutaions in sorted order (N! total permutations)
         2. find the given permutation
         3. return the next one if it is the last one return the first permutation
 TC: O(N! x N)
*/
//Better: using C++ STL : next_permutation(A.begin(), A.end()); here, modify the A array to next permutation
//Optimal: implement this inbuilt next_permutation function:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),pnt,l;                                                                    //nums = [2, 1, 5, 4, 3, 0, 0]
        //find the break point or deep
        for(pnt=n-2;pnt>=0;pnt--){                                                                  //nums = [2, 1, 5, 4, 3, 0, 0]
            if(nums[pnt]<nums[pnt+1])                                                                            ^
                break;                                                                             //step-1:    pnt [it is pointing to the breaking point]
        }                                                                                          //(longest prefix match)
        //if there is no breaking point then its the last permutation so just
        //reverse it, it will give smallest permutation that will be the answer.
        if(pnt<0){
            reverse(nums.begin(),nums.end());     //suppose, nums=[5,4,3,2,1] -> no breaking point means if we just reverse the nums then we get next_permutation
        }else{                                    //         next_permutation = [1,2,3,4,5]                     pnt   
            for(l=n-1;l>pnt;l--){                                                                   //nums = [2, 1, | 5, 4, 3, 0, 0]
                if(nums[l]>nums[pnt])                                                   //step-2: find > 1, but the smallest one so that we stay close, here it is 3
                    break;                                                                          //nums = [2, 1, | 5, 4, 3, 0, 0]
            }                                                                                       //          pnt         l
            swap(nums[l],nums[pnt]);                                                    //step-3:swap them = [2, 3, | 5, 4, 1, 0, 0]    
            reverse(nums.begin()+pnt+1,nums.end());              //step-4: reverse the (pnt+1,end)  ////nums = [2, 3, 0, 0, 1, 4, 5]
        }                                                        //nums = [2, 1, 5, 4, 3, 0, 0]     --------> next_permutation = nums = [2, 3, 0, 0, 1, 4, 5]
    }
};
