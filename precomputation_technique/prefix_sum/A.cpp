#include <iostream>
using namespace std;

const int N = 200002;

int prefix_sum[N];

int main() {

    int n,k,q; cin>>n>>k>>q;
    
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        prefix_sum[l]++;
        prefix_sum[r+1]--;
    }
    for(int i=1;i<N;i++){
        prefix_sum[i]+=prefix_sum[i-1];
    }
    for(int i=1;i<N;i++){
        prefix_sum[i]=(prefix_sum[i]>=k)?1:0;
        prefix_sum[i]+=prefix_sum[i-1];
    }
    while(q--){
        int l, r; cin>>l>>r;
        cout<<prefix_sum[r]-prefix_sum[l-1]<<endl;
    }
    
	return 0;
}
