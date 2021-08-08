#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b)
{
  a=a+b;
  b=a-b;
  a=a-b;
}

void bubbleSort(vector<int>&v)
{
  for(int i=0;i<v.size();i++)
    for(int j=0;j<v.size()-1-i;j++) 
      if(v[j]>v[j+1])
        swap(v[j],v[j+1]);
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
  bubbleSort(v);
  // print it
  for(int i:v)
    cout<<i<<" ";

  return 0;
}