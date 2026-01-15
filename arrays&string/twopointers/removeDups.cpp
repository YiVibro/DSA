class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast=0;
        int slow=0;
        int arrSize=0;
       while(fast<nums.size())
        {
            if(nums[fast]==nums[slow])
            {
                fast++;
            }else{
                nums[++slow]=nums[fast++];
                arrSize++;
            }
        }
        return arrSize+1;
    }
};