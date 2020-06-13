#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll xorSum(int arr[],int n){
    ll sum = 0;
    for(int i=0;i<32;i++){  /// assuming every number is in 32 bit range
        int zc , oc;
        zc = oc = 0;
        for(int j=0;j<n;j++){
            if((arr[j]>>i)&1) oc++;
            else zc++;
        }
        ll cur = oc*zc*(1<<i);
        sum += cur;
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll ans = xorSum(arr,n);
    cout<<ans<<endl;

}
