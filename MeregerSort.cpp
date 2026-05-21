    #include<bits/stdc++.h>
    using namespace std;
    void Merge(vector<int>&arr,int n,int low,int mid,int high){
        int left = low;
        int right = mid+1;
        vector<int>temp;
        while(left <= mid && right <= high){
            if(arr[left]>arr[right]){
                temp.push_back(arr[right]);
                right++;
            }
            else {
                temp.push_back(arr[left]);
                left++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low ;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    void merge_sort(vector<int>&arr,int n,int low,int high){
        if(low >= high)return;
        int mid = (low+high)/2;
        merge_sort(arr,n,low,mid);
        merge_sort(arr,n,mid+1,high);
        Merge(arr,n,low,mid,high);
    }

    int main(){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<"Unsorted array:\n";
        for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
        merge_sort(arr,n,0,n-1);
        cout<<"\nSorted array:\n";
        for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
        return 0;
}
