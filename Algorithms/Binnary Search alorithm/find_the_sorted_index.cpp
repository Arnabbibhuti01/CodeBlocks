#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int partation(int arr[],int s,int e){
int p=arr[s];
int ct=0;
int n=e-s+1;
for (int i = 0; i < n; i++)
{
  if(arr[i]<p)ct++;
}
// fix pivot
int pivot_index=s+ct;
swap(arr[s],arr[pivot_index]);
int i=s;
int j=e;
while (i<pivot_index && j>pivot_index)
{
  while (arr[i]<arr[pivot_index])
  {
  i++;
  }
  while (arr[j]>arr[pivot_index])
  {
    j--;
  }
  if(i<pivot_index && j>pivot_index){
    swap(arr[i],arr[j]);
  }

}
return pivot_index;

}
void quick_sort(int arr[],int s,int e ){
if(s>=e)return;
int p=partation(arr,s,e);
quick_sort(arr,s,p-1);
quick_sort(arr,p+1,e);

}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
int arr[n];
fi(0,n){
    cin>>arr[i];

}
quick_sort(arr,0,n-1);
fi(0,n)cout<<arr[i]<<" ";
return 0;
}
