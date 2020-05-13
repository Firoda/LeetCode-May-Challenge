class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
       int start = 0;
       int end = nums.size() - 1;
        
       while(start<=end)
       {
           int mid = start + (end - start)/2;
if(((mid > 0 and nums[mid]!= nums[mid-1]) or(mid == 0)) and ((mid+1<nums.size() and nums[mid]!=nums[mid+1]) or (mid == nums.size()-1)))
               return nums[mid];
           
           else if(mid+1<nums.size() and nums[mid] == nums[mid+1]){
               
               if((nums.size()-1 - mid+1)%2 == 0)
                   end = mid - 1;
               else
                   start = mid + 1;
           }
           else if(mid>0 and nums[mid] == nums[mid-1]){
               
               if((mid-1 - 0)%2 == 0)
                   start = mid + 1;
               else 
                   end = mid - 1;
           }
       }
        return -1;
    }
};
