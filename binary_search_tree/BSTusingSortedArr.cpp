/*
Construct BST using sorted array
*/

Node* buildBSTformSortedArr(int arr[], int l, int r){
    
    if(l>r) return NULL;
    
    int mid = (l+r)/2;
    Node* node = new Node(arr[mid]);
    
    node->left = buildBSTformSortedArr(arr, l, mid-1);
    node->right = buildBSTformSortedArr(arr, mid+1, r);
    
    return node;
    
}
