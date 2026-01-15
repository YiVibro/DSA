class Solution {
public:
    int maxArea(vector<int>& height) {
       int i=0,j=height.size()-1;
       int maxWater=0;
       while(i<j)
       {
        maxWater=max(maxWater,min(height[i],height[j])*(j-i));
        if(height[i]<height[j])
        {
            i++;
        }else{
            j--;
        }

       }
        return maxWater;
    }
};