#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
};
class LRUCache : Cache {
  public:
  LRUCache(int capacity) {
    this->cp = capacity;
    tail = NULL;
    head = NULL;
  }
  void set(int key, int value) {
    Node* temp = new Node(key, value);
    map<int, Node*>::iterator it;
    it = mp.find(key);
    // if the size of the cache is not full
    if(mp.size()< cp) {
        // find if the key is already in the cache !
        if(it == mp.end()) {    // the key was not found so its a new data 
            mp.insert({key,temp});  // insert to the map
            if (head == NULL){    // add the node as a the first node if the list is NULL
                head = tail = temp;
            }else {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }else {
        // if we find the elemnt in the map we need to move it (in the linked list ) to the top 
          it->second->value = value;
          if(it->first != head->key){
          Node* iter = head;
            if(it->first != tail->key) {
                while(iter->key != it->first) {
                    iter = iter->next;
                }
                Node* node1 = iter->prev;
                Node* node2 = iter->next;
                node1->next = node2;
                node2->prev = node1;
                iter->prev = NULL;
                iter->next = head;
                head->prev = iter;
                head = iter;
                head->value = it->second->value;

            }else {
              Node* t = tail->prev;
              t->next = NULL;
              tail->next = head;
              tail->prev = NULL;
              head->prev = tail;
              head = tail;
              tail = t;
              head->value = it->second->value;
            }
          }else {
            head->value = it->second->value;
          }
          
        }  
    }else {
      // else perform if the cache is full 
        Node* deleteNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
        mp.erase(deleteNode->key);
         delete(deleteNode);
    }
  }
  int get(int key) {
    map<int,Node*>::iterator it;
    it = mp.find(key);
    if(it != mp.end()) {
      return it->second->value;
    }
    return -1;

  }
};
int main() {

    ios_base::sync_with_stdio(false);
  	//cin.tie(NULL);
		#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n=3, capacity=1,i;
    cin >>n>> capacity;

    LRUCache l(capacity);

    for(i=0;i<n;i++) {
      
      string command;
      cin >> command;
      if(command == "get") {
        int key;
        cin >> key;
        cout << l.get(key) << endl;
      } 
      else if(command == "set") 
      {
        int key, value;
        cin >> key >> value;
        l.set(key,value);
      }    
    }  


  return 0;

}
