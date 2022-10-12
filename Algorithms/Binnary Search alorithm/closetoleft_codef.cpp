#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
vector<int>v;
int n,k;
cin>>n>>k;
fi(0,n){
int x;cin>>x;
v.push_back(x);
}
fi(0,k){
    int x;cin>>x;
    int l=-1;
    int r=n; 
    while (r>l+1)
    {
        int m=(r+l)/2;
        if(x>v[m])
        l=m;
        else
        r=m;
    }
    cout<<r+1<<"\n";
    
}
return 0;
}
