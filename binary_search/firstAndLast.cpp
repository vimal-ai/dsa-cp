int solve(int arr[], int n, int x, bool a){
    int low = 0, high = n;
    int idx = -1;
    
    while(low <= high){
        int mid = high - (high-low)/2;
        if(arr[mid]==x){
            idx = mid;
            if(a) high = mid - 1;
            else low = mid+1;
        }
        else if(arr[mid]<x){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return idx;
}

vector<int> find(int arr[], int n , int x )
{
    vector<int>v;
    v.push_back(solve(arr, n-1, x, 1));
    v.push_back(solve(arr, n-1, x, 0));
    return v;
}
