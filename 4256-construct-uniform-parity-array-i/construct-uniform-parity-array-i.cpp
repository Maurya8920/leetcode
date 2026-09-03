class Solution {
public:
bool check(vector<int> n2 , int n){
    for(int i=0 ; i<n ; i++){
        if(n2[i]%2!=0) return false;
    }
    return true;
}
    bool uniformArray(vector<int>& nums1) {
        int n= nums1.size();
    vector<int>  nums2(n);
        int i=0;
        int j=i+1;
        while(i<n && j<n ){
            if(nums1[n-1]%2!=0){
                nums2[i]= nums2[i]-nums2[j];
            }
            else if(nums1[n-1]%2==0){
                nums2[i]=nums1[i];
            }
            i++;
            j++;
        }
        if(check(nums2,n)==true) return true;
        if(check(nums2,n)==false) return true;
         return false;
    
    }
};