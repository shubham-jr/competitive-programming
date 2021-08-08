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

void selectionSort(vector<int>&v,int w)
{
  int n=v.size();
  if(w==n-1)
  return;  
  int index=w;
  int i;
  for(i=w+1;i<n;i++)
  {
      if(v[index]>v[i])
      index=i;
  }
  swap(v[index],v[w]);
  selectionSort(v,w+1);
}
int main()
{
  int n;
  cin>>n;

  vector<int>v(n);
  for(int&i:v)
  cin>>i;

  selectionSort(v,0);

  for(int&i:v)
  cout<<i<<" "; 

  return 0;
}