    int searchInSorted(int arr[], int N, int K) 
    { 
    
       int low = 0, high = N-1;
       int idx=-1;
       while(low<=high){
           int mid = high - (high-low)/2;
           
           if(arr[mid]==K)idx=mid;
           if(arr[mid]<K){
               low = mid+1;
           }else{
               high = mid-1;
           }
       }
       return idx;
    }
