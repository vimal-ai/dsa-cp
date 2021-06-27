	int findKRotation(int arr[], int n) {
	    int low =0, high = n-1;
	    if(n==1) return 0;
	    while(low <= high){
	        
	        int mid = (high+low)/2;
	        
	        int next = (mid+1)%(n);
	        int pre = (mid-1)%(n);
	        
	        
	        if(arr[mid]<arr[next] && arr[mid] < arr[pre]){
	            return mid;
	        }
	        if(arr[mid]<arr[n-1]){
	            high = mid-1;
	        }
	        else{
	            low = mid+1;
	        }
	    }
	}
