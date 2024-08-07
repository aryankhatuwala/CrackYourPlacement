class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1,j=n-1, end=n+m-1;
        while(i>=0 and j>=0 and end>=0)
        {
            if(nums1[i]>nums2[j]){
            nums1[end--]=nums1[i]; 
            i--;
            }
            else
            {
                nums1[end--]=nums2[j--];
            }
        }
        if(i==-1)
        {
            while(end>=0) nums1[end--]=nums2[j--];
        }
    }
};