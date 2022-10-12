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
    int x;
    cin>>x;
    v.push_back(x);
}


for (int i = 0; i < k; i++)
{
  // taking the diffrent input
  int x;
  cin>>x;
  // initialising the left and right element with -1 and n just for sake
int l=-1; //pointing to the element less than x
int r=n;// pointing element greater or equal to x
// iterating the loop till the l and r does'nt reach the adjecent positon
  while (r>l+1)
  {
    // evaluating the middle element
    int m=(l+r)/2;
    // if the middle element is less or equal to x then shift the left to mid
    if(v[m]<x){
      l=m;
    }
    else{
      // if not then shift the element to right 
      r=m;
    }
     
  }
  cout<<r+1<<"\n";
}

    

return 0;
}
