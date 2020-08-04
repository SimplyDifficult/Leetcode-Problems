class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size(),l=0,r=n;
        if(n>m)return findMedianSortedArrays(nums2,nums1);
        
        
        while(l<=r){
            int i=(l+r)/2,j=(n+m+1)/2-i;
            if(i && nums1[i-1]>nums2[j])r=i-1;
            else if(i<n && nums2[j-1]>nums1[i])l=i+1;
            else{
                int lmax;
                if(i==0)lmax=nums2[j-1];
                else if(j==0)lmax=nums1[i-1];
                else lmax=max(nums1[i-1],nums2[j-1]);
                
                if((m+n)%2)return lmax;
                
                int rmin;
                if(i==n)rmin=nums2[j];
                else if(j==m)rmin=nums1[i];
                else rmin=min(nums1[i],nums2[j]);
                
                return (lmax+rmin)*0.5;
            }
        }
        return 0.0;
    }
};
