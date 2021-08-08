#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b)
{
  a=a+b;
  b=a-b;
  a=a-b;
}

void bubbleSort(vector<int>&v,int n)
{
  // base case
  if(n==1)
  return;  

  for(int i=0;i<n-1;i++) 
  if(v[i]>v[i+1])
  swap(v[i],v[i+1]);
  // recursive call for size n-1 because after one pass the 
  // last element is sorted. So, no need to sort that.
  bubbleSort(v,n-1);    
}

int main() 
{
  // size of vector
  int n;
  cin>>n;

  // initialize the vector 
  vector<int>v(n);
  for(int&i:v)
  cin>>i; 
  // sort it 
  bubbleSort(v,n);
  // print it
  for(int i:v)
    cout<<i<<" ";
  return 0;
}