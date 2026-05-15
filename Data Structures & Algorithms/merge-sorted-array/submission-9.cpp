class Solution {
public:
    void swap(vector<int>& nums1,vector<int>& nums2,int i1,int i2){
        int temp=nums1[i1];
        nums1[i1]=nums2[i2];
        nums2[i2]=temp;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=m-1;i>=0;i--){
            nums1[n+i]=nums1[i];
        } for (int i=0;i<n;i++){nums1[i]=0;}
        for (int num:nums1)cout<<num<<' ';
        cout<<endl;
        int count1=n;int count2=0;
        int pos=0;
        while (count1<m+n && count2<n){
            if (nums1[count1]<=nums2[count2]){
                nums1[pos]=nums1[count1];
                count1++;
            } else {
                nums1[pos]=nums2[count2];
                count2++;
            } pos++;
        }
        while (count1<m+n){
            nums1[pos]=nums1[count1];
            count1++;
            pos++;
        }
        while (count2<n){
            nums1[pos]=nums2[count2];
            count2++;
            pos++;
        }
        
        
    }
};