#include <iostream>
#include <stdlib.h>
#include "dictionarylist.h"

using namespace std;



//Constructor
template <typename key, typename info>
list<key,info>::list(const list<key,info> &theList) {
  *this = theList;
}



//Destructor
template <typename key, typename info>
list<key,info>::~list() {

  int num = 0;
  list_node *node = head;
  list_node *curr = head;

  while(node != NULL) {
    curr = node;
    node = node->next;
    delete curr;
    curr = NULL;
    num++;
  }

  head = NULL;
  tail = NULL;

  cout<<"The list is being deleted. Number of nodes in this list was:  "<<num<<endl;

}



//If the list is empty, returns true
template <typename key, typename info>
bool list<key,info>::empty() const {

  if(head==NULL) {
  return true;    
  }

  return false;   

};



//Returns the length of the list
template <typename key, typename info>
int list<key,info>::length() const {

  //checks if the list is empty  
  if(empty()) {
    return 0;
  } 
  
  //if not empty
  int count = 0;
  list_node *node = head;

  while(node != NULL) {
    count++;
    node = node->next;
  }

  return count;

}



//Removes all nodes from the list
template <typename key, typename info>
void list<key,info>::clear() {
  
  //checks if the list is empty
  if(empty()) {
    return;
  }  
  
  //if not empty
  list_node *node = head;
  list_node *curr = head;

  while(node != NULL) {
    curr = node;
    node = node->next;
    delete curr;
    curr = NULL;
  }

  head = NULL;
  tail = NULL;

}


//Searches for the node with the given key and prints it's info
template <typename key, typename info>
void list<key,info>::search_print(key _key) const {
  
  //checks if the list is empty
  if(empty()) {
    cout<<"Error: The list is empty"<<endl;
    return;
  }
  
  //if not empty
  list_node *node = head;

  while(node != NULL) {

    if(_key == node->_key) {
     cout<<"Found the node with the key: "<<_key<<" and info: "<<node->_info<<endl;
     return; 
    }

    node=node->next;
  }
  //if the key cannot  be found on the list
  cout<<"Error: Node with the key: "<<_key<<" does not exist on this list"<<endl;

}


//Assignment operator
template <typename key, typename info>
void list<key,info>::operator=(const list<key,info> &lista) {

  if(&lista != this) {
    list_node* p;
    this->clear();
    p = lista.head;

    while(p!=NULL) {
      this->forced_push_back(p->_key, p->_info);
      p = p->next;
    }

  }

}


//Adds one list to another (A + B), if the nodes with the same keys are found, these nodes from list B will be skipped
template <typename key, typename info>
list<key,info> &list<key,info>::operator+(const list<key,info> &lista) {

  list<key,info>* new_list = new list<key,info>;
  list_node* n;
  n = this->head;

  //copies the first list onto new list "n"
  while(n != NULL) {
    new_list->forced_push_back(n->_key,n->_info);
    n = n->next;
  }
  
  //adds nodes from the second list to the list "n" (if the are nodes from the second list that have the same keys as the nodes from list "n", those nodes will me skipped
  list_node* p;
  p = lista.head;

  while(p != NULL) {
  new_list->push_back(p->_key,p->_info);
  p = p->next;
  }

  return *new_list; 

}


//If two lists are identical, returns true
template <typename key, typename info>
bool list<key,info>::operator==(const list<key,info> &lista) {
  
  //length of lists are not the same
  if(this->length() != lista.length()) {
    return false; 
  }
  
  //if the lists are the same lengths
  list_node* local = this->head;
  list_node* second = lista.head;
  
  //checking if nodes are the same
  while(local != NULL) {

    //if not - false
    if(local->_info != second->_info || local->_key != second->_key) {
      return false;  
    }

    local = local->next;
    second = second->next;
  }

  return true;

}


//Joins two lists together, if the nodes have the same key, infos of those nodes will be merged
template <typename key, typename info>
void list<key,info>::join(const list<key,info> &list1,const list<key,info> &list2) {

  //Copies the first list to the target one
  if(&list1 !=this) {
    list_node* ptr;
    this->clear();
    ptr = list1.head;

    while(ptr != NULL) {
    this->forced_push_back(ptr->_key,ptr->_info);
    ptr = ptr->next;
    }

  }

  list_node *ptr2 = list2.head;
  list_node *local = head;
  int success = 0;
    
  //Copies the second list to the target one, if the keys repeat - the infos will be merged
  while(ptr2 != NULL) {

    while(local != NULL) {
      
      //checking if the keys are the same, merges infos if yes
      if(ptr2->_key == local->_key) {
        local->_info = local->_info + ptr2->_info; 
        success = 1;
      }

      local = local->next;

    }

    if(success == 0) {
      this->forced_push_back(ptr2->_key,ptr2->_info);  
    }

    success = 0;
    local = head;
    ptr2 = ptr2->next;
  }

}   


//If the key is not unique, returns true
template <typename key, typename info>
bool list<key,info>::key_not_unique(key _key)const {
  
  //if list is empty
  if(head == NULL) {
    return false; 
  }
  
  //checking if the key can be found on the list
  list_node *n;
  n = head;

  while(n != NULL) {

    if(n->_key == _key) {
      return true; 
    }

  n = n->next; 
  }

  return false;

}


//When the uniqueness of the key does not matter, this function will be called
template <typename key, typename info>
void list<key,info>::forced_push_back(key Newkey,info Newinfo) {
  
  //adding node to the empty list
  if(empty()) {
    list_node *node;
    node = new list_node;
    node->_key = Newkey;
    node ->_info = Newinfo;
    node->next = NULL;
    head = node;
    tail = head;  
  }
  
  //adding node to the end of the list
  else {
    list_node *node;
    node = new list_node;
    node->_key = Newkey;
    node ->_info = Newinfo;
    tail->next = node;
    tail = node;
    node->next = NULL;
  }

};


//Adds new node with the given key and info at the end of the list, only if the key is unique
template <typename key, typename info>
void list<key,info>::push_back(key Newkey,info Newinfo) {
  
  //checking if the key is unique
  if(key_not_unique(Newkey)) {
    cout<<"Error: the key "<<Newkey<< " is not unique"<<endl;
    return;
  }
  
  //adding node to the end of the list
  forced_push_back(Newkey,Newinfo);

};


//Adds new node with the given key and info at the beggining of the list, only if the key is unique
template <typename key, typename info>
void list<key,info>::push_front(key Newkey,info Newinfo) {
  
  //adding node to the empty list
  if(empty()) {
    list_node *node;
    node = new list_node;
    node->_key = Newkey;
    node ->_info = Newinfo;
    node->next = NULL;
    head = node;
    tail = head;  
  }

  else {
    
    //checking if the key is unique
    if(key_not_unique(Newkey)) {
      cout<<"Error: the key "<<Newkey<<" is not unique"<<endl;
      return;
    }
    
    //adding node to the front of the list
    list_node *node;
    node = new list_node;
    node->_key = Newkey;
    node ->_info = Newinfo;
    node->next = head;
    head = node;
    
  }

}


//Removes the last node of the list
template <typename key, typename info>
void list<key,info>::pop_back() {

    //checks if the list is empty
    if(empty()) {
    cout<<"Error: The list is empty"<<endl;
    return; 
    }

    else {
    //Only one node in the list
    if(head == tail) {
        delete head;
        head=NULL;
        tail=NULL;
        return;
    }

    //More nodes in the list
    list_node *temp=head;

    while(temp->next!=tail) {
        temp=temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;
    temp = NULL;
    }

};


//Removes the first node of the list
template <typename key, typename info>
void list<key,info>::pop_front() {

  if(empty()) {
    cout<<"Error: The list is empty"<<endl;
    return; 
  }

  else {
    //Only one node in the list
    if(head == tail) {
      delete head;
      head = NULL;
      tail = NULL;
      return;
    }

    //More nodes in the list
    list_node *temp = head->next;
    delete head;
    head = temp;
  }

};


//Removes the node with the given key
template <typename key, typename info>
void list<key,info>::remove_by_key(key given_key) {

  if(empty()) {
    cout<<"Error: The list is empty"<<endl;
    return;
  }

  //Only one node in the list
  if(head == tail) {

    if(given_key == head->_key) {
      delete head;
      head = NULL;
      tail = NULL;
      return;
    }
  
    else {
      cout<<"Error: The key: "<<given_key<<" does not exist on this list"<<endl;
      return; 
    }

  }

  //More nodes in the list, targeted node is first or last on the list
  list_node *current;
  current = head;

  if(given_key == head->_key) {  
    current = current->next;
    delete head;
    head = current;
    current = NULL;
    return;
  } 

  if(tail->_key == given_key) {

    while(current->next != tail) {
      current = current->next; 
    }

    delete tail;
    tail = current;
    current->next = NULL;
    return;
  }

  //More nodes in the list, targeted node is somewhere in the middle of the list
  while(current->next!=NULL) {

    if(current->next->_key == given_key) {
      list_node *prev;
      prev = NULL;
      prev = current;
      current = current->next;
      prev->next = current->next;
      delete current; 
      current=NULL;
      return; 
    }

    current=current->next;
  }

  cout<<"Error: The key: "<<given_key<<" does not exist on this list"<<endl;

}


//Prints the list
template <typename key, typename info>
void list<key,info>::print() const {

  if(empty()) {
    cout<<"Error: The list is empty"<<endl;
    return;    
  }

  list_node *current;
  current = head;
  cout<< endl;
  cout<<"--------------------"<<endl;
  cout<<"------THE LIST------"<<endl;

  while(current!=NULL)
  {
   cout<<"Key: "<<current->_key<<" Info: "<<current->_info<<endl;
   current=current->next;
  }
  cout<<"------||||||||------"<<endl;
  cout<<"--------------------"<<endl<<endl;

}


//Adds new node with the given key and info at the end of the dictionary
template <typename key, typename info>
void dictionary<key,info>::add(key k, info i) {
  _list.push_back(k,i);   
}


//Prints the dictionary
template <typename key, typename info>
void dictionary<key,info>::print() const {
  _list.print();   
}


//Removes the node with the given key
template <typename key, typename info>
void dictionary<key,info>::remove_by_key(key k) {
  _list.remove_by_key(k);   
}


//Searches for the node with the given key and prints it's info
template <typename key, typename info>
void dictionary<key,info>::find_by_key(key k) {
  _list.search_print(k);   
}


//Joins two dictionaries together, if the nodes have the same key, infos of those nodes will be merged
template <typename key, typename info>
void dictionary<key,info>::join(const dictionary<key, info>& first,const dictionary<key, info>& second) {
  _list.join(first._list,second._list);   
}