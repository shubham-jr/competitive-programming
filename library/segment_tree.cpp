vector<int>tree,lazy;

void build(vector<int>&v,int index,int start,int end){
  if(start==end)
  {tree[index]=v[end];return;}
  int mid=(start+end)>>1;
  build(v,2*index+1,start,mid);
  build(v,2*index+2,mid+1,end);
  tree[index]=min(tree[2*index+1],tree[2*index+2]);
}

int query(int index,int start,int end,int low,int high){
  if(lazy[index])
  {
    int val=lazy[index];
    lazy[index]=0;
    tree[index]+=(end-start+1)*val;
    if(start!=end)
    {
      lazy[2*index+1]+=val;
      lazy[2*index+2]+=val;
    }  
  }
  debug2(start,end);
  if(start==low&&end==high)            // if(start==low&&end==high) this is if we want to find an element say [3,3]
  return tree[index]; 
  
  if(start>high||end<low)
  return 0; 
  
  int mid=(start+end)>>1;
  int left=query(2*index+1,start,mid,low,high);
  int right=query(2*index+2,mid+1,end,low,high);  
  debug2(left,right);
  return left+right;  

}

void point_update(int index,int start,int end,int i,int val){
  if(start==end)
  {tree[index]+=val;return;}
  
  int mid=(start+end)>>1;
  if(i>=start&&i<=mid)
  point_update(2*index+1,start,mid,i,val);
  else
  point_update(2*index+2,mid+1,end,i,val); 
  tree[index]=min(tree[2*index+1],tree[2*index+2]);   
}

void rangeUpdate(int index,int start,int end,int low,int high,int val){
  if(start>high||end<low)
  return;
  if(start>=low&&end<=high)
  {
    tree[index]+=(end-start+1)*val;
    if(start!=end)
    {
      lazy[2*index+1]+=val;
      lazy[2*index+2]+=val;
    }
    return;
  }  
  int mid=(start+end)>>1;
  rangeUpdate(2*index+1,start,mid,low,high,val);
  rangeUpdate(2*index+2,mid+1,end,low,high,val);
  tree[index]=min(tree[2*index+1],tree[2*index+2]);
}