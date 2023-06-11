# Dutch National Flag Algorithm: 
Approaches: Brute -> Better -> Optimal
<br>
Brute: using C++ STL inbuild sort function -- TC: O(nlogn), SC: O(N) <br>
Better: using 3-variable: cnt0, cnt1, cnt2 --- TC: O(2N) -> O(N) to deteremine the no of zeros, ones amd twos + O(N) to modify the array, SC: O(1) <br>

**Optimal: Dutch National Flag Algorithm** 
<br>
Four part/rules: <br>
[0.....low-1] ----> 0 <br>
[low....mid-1]---> 1 <br>
[mid....high]----> Unsorted part {OBJECTIVE: we have to sort this part} <br>
[high+1.....n-1]--> 2 <br>
<br>
<img width="623" alt="image" src="https://github.com/AbhirupChakraborty/Striver-SDE-Sheet-Challenge-2023/assets/59620162/bc1f07ae-abe9-4ca8-91c8-3f290656ca4e">
<br>
Code:
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0, mid=0, hi=nums.size()-1;

        while(mid<=hi){
            switch(nums[mid]){
                //If the element is 0
                case 0: swap(nums[lo++],nums[mid++]);
                        break;
                //If the element is 1
                case 1: mid++;
                        break;
                //If the element is 2
                case 2: swap(nums[mid],nums[hi--]);
                        break;
            }
        }
    }
};
//TC: O(N)
//SC: O(1)
```
