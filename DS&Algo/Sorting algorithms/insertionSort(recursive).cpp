#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b) 
{
  int tmp;
  tmp=a;
  a=b;
  b=tmp;
}

void insertionSort(vector<int>&v,int n)
{
    if(n==v.size()) 
    return;
    int j=n-1;
    int tmp=v[n];
    while(j>=0&&v[j]>tmp)
    {
      v[j+1]=v[j];
      j--;
    }
    v[j+1]=tmp; 
    insertionSort(v,n+1);
}
int main()
{
  int n;
  cin>>n;

  vector<int>v(n); 
  for(int&i:v)
  cin>>i;

  insertionSort(v,1);

  for(int&i:v)
  cout<<i<<" "; 

  return 0;
}