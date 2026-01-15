class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        int fast=0;
        while(fast<nums.size())
        {
            if(nums[fast]!=0){
                int temp=nums[slow];
                nums[slow]=nums[fast];
                nums[fast]=temp;
                slow++;
            }
            fast++;
        }
    }
};


void moveZerosEnd(vector<int>&arr)
{
    int i=0,indx=0;
    while(true)
    {
        if(arr[i]==0)
        {
            for(int j=i;j<arr.size();j++)
            {
                if(arr[j]!=0)
                {
                    indx=j;
                    break;
                }
            }
            swap(arr[i],arr[indx]);
        }
        i++;
        if(i==arr.size()-1)break;
    }
        for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

