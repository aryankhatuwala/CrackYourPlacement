class Solution {
public:
    void merge(int low, int mid, int high,vector<int>& nums, int n,
    int &ans)
    {
        vector<int>temp;
        int i=low,j=mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j])
                j++;
        
        ans += j-(mid+1);
        }

        i=low,j=mid+1;
        while(i<=mid and j<=high)
        {
            if(nums[i]<nums[j])
            {
                temp.push_back(nums[i]); 
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i]); 
            i++;
        }
        while(j<=high)
        {
            temp.push_back(nums[j]);
            j++;
        }
        int k=0;
        for(int i=low;i<=high;i++)
        nums[i]=temp[k++];
    }
    void mergeSort(int low, int high,vector<int>& nums, int &ans )
    {
        int n=nums.size();
        if(low<high)
        {
            int mid=(low+high)>>1;
            mergeSort(low,mid,nums,ans);
            mergeSort(mid+1,high,nums,ans);
            merge(low,mid,high,nums,n,ans);
        }
        return;
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergeSort(0,nums.size()-1,nums,ans);
        // for(auto it:nums) cout<<it<<" ";
        return ans;
    }
};