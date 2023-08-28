class Solution {
    int getPivot (vector<int>& arr){
        int s=0,e=arr.size()-1;
        int mid = s+(e-s)/2;
        
        while(s < e){
            
            if(arr[mid] >= arr[0]){
                s = mid + 1;
            }
            else{
                e = mid;
                
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
    
    int binarySearch(vector<int>& arr, int start,int end, int target){
        int s = start, e = end;
        int mid = s + (e-s)/2;
        
        while ( s <= e){
            
            if(arr[mid] == target){
                return mid;
            }
            else if( target > arr[mid])
            {
                s = mid + 1;
                
            }
            else{
                e = mid -1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        
        int pivot = getPivot(nums);
        // cout << pivot;
        if(  target >= nums[pivot] && target <= nums[nums.size() - 1]){
            return binarySearch(nums,pivot,nums.size()-1,target);
        }
        else{
            return binarySearch(nums,0,pivot,target);
        }
    }
};