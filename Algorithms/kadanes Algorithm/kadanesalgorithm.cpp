    // KADANE'S ALGORITHM 

#include<bits/stdc++.h>
using namespace std;
int maxsumsubarray(int arr[],int n){
int maxsum=0;
int currsum=0;
for (int i = 0; i < n; i++)
{
    currsum=currsum+arr[i];
    if (currsum>maxsum)
    {
        maxsum=currsum;
    }
    if (currsum<0)
    {
        currsum=0;
    }   
}
    return maxsum;
}

int main(){
int size;
cin>>size;
int a[100];
for (int i = 0; i < size; i++)
{
    cin>>a[i];
}
cout<<maxsumsubarray(a,size);
return 0;
}