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

void insertionSort(vector<int>&v)
{
  int n=v.size();
  for(int i=1;i<n;i++)
  {
    int j=i-1;
    int tmp=v[i];
    while(j>=0&&v[j]>tmp)
    {
      v[j+1]=v[j];
      j--;
    }
    v[j+1]=tmp;

  }  
}
int main()
{
  int n;
  cin>>n;

  vector<int>v(n);
  for(int&i:v)
  cin>>i;

  insertionSort(v);

  for(int&i:v)
  cout<<i<<" "; 

  return 0;
}