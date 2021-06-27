	int solve(int arr[], int n, int x, int a){
	    int low = 0, high = n-1;
	    int idx = -1;
	    
	    while(low <= high){
	        int mid = high - (high-low)/2;
	        if(arr[mid]==x){
	            idx = mid;
	            if(a) high = mid-1;
	            else low = mid+1;
	        }
	        else if(arr[mid] < x){
	            low = mid+1;
	        }else{
	            high = mid-1;
	        }
	    }
	    return idx;
	    
	}
	
	int count(int arr[], int n, int x) {
	    int low = solve(arr, n, x, 1);
	    if(low == -1) return 0;
	    int high = solve(arr, n, x, 0);
	    return (high - low) + 1;
	}
