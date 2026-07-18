class Solution {
public:
    int search(vector<int>& nums, int target) {
    int l=0,r=nums.size()-1,result= -1;
    bool check=false;
    while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<nums[r]){
                r=mid;
            }
            else if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r--;
            }
        }
        int l1,r1;
        if(l==0){
            if(nums[0]==target) return 0;
            l1=0,r1=nums.size()-1;
        }
        else if(target>=nums[0] && target<=nums[l-1]){
            l1=0,r1=l-1;
        }
        else{
            l1=l,r1=nums.size()-1;
        }
        if(nums[l]==target){
            result=l;
        }
        else{
            while(l1<=r1){
                int mid=l1+(r1-l1)/2;
                if(nums[mid]==target){result=mid; check=true; break;}
                else if(nums[mid]>target){
                    r1=mid-1;
                }
                else{
                    l1=mid+1;
                }
            }
        }
        return result;
    }
};