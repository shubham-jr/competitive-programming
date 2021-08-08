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

void selectionSort(vector<int>&v)
{
  int n=v.size();
  for(int i=0;i<n;i++)
  {
    int index=i;
    for(int j=i;j<n;j++)
    {
      if(v[index]>v[j])
        index=j;
    }
    swap(v[index],v[i]);
  }
}
int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int&i:v)
  cin>>i;
  selectionSort(v);
  for(int&i:v)
  cout<<i<<" ";  
  return 0;
}