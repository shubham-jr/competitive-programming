struct Node
{
  Node*link[26]={nullptr}; 
  bool flag;

  bool containsKey(char c){ 
    return link[c-'a']!=nullptr;
  }

  void put(char c, Node*node){
    link[c-'a']=node;
  }

  Node* get(char c){
    return link[c-'a'];
  }

  void setEnd(){
    flag=true;
  }

  bool isEnd(){
    return flag;
  }

};

class Trie{

 Node*root;

  public:

    Trie(){
      root=new Node();  
    }

  void insert(string word){
    Node*node=root;
    fo(0,word.size())
    {
      if(!node->containsKey(word[i])){
        node->put(word[i],new Node);
      }
      node=node->get(word[i]);
    }
    node->setEnd();
  }  

  bool search(string word){
    Node*node=root;
    fo(0,word.size())
    {
      if(!node->containsKey(word[i]))
      return false;
      node=node->get(word[i]);  
    }
    return node->isEnd();
  }

  bool startsWith(string prefix){
    Node*node=root;
    fo(0,prefix.size()){
      if(!node->containsKey(prefix[i]))
      return false;
      node=node->get(prefix[i]);   
    }
    return true;
  }
};