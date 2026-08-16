class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1=0, ptr2=numbers.size()-1;
        int sum=numbers[ptr1]+numbers[ptr2];
        while(sum !=target){
            sum=numbers[ptr1]+numbers[ptr2];
            if(sum>target) ptr2--;
            else if(sum<target) ptr1++;
        }
        return {1+ptr1,1+ptr2};
    }
};
