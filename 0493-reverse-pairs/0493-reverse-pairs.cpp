class Solution {
public:
    long long sum=0;
    void merge(vector<int>&arr,int st,int mid,int end){
    int i=st;
    int j=mid+1;
    vector<long long> temp;
    while(i<=mid && j<=end){
        long long right=2*long(arr[j]);
        long long left=arr[i];
        if(left>right){
            sum+=(mid-i+1);
            // temp.push_back(arr[j]);
            j++;
        }
        else{
            // temp.push_back(arr[i]);
            i++;
        }
    }
    i=st;
    j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=end) temp.push_back(arr[j++]);
    i=st,j=mid+1;
    int k=0;
    while(i<=mid) arr[i++]=temp[k++];
    while(j<=end) arr[j++]=temp[k++];

}
void helper(vector<int>&arr,int st,int end){
    if(st>=end) return;
    int mid=(st+end)/2;
    helper(arr,st,mid);
    helper(arr,mid+1,end);
    merge(arr,st,mid,end);
}
    int reversePairs(vector<int>& arr) {
        helper(arr,0,arr.size()-1);
        return sum;
    }
};