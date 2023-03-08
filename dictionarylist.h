#include <iostream>
#include <stdlib.h>
#ifndef DICTIONARYLIST_H_INCLUDED
#define DICTIONARYLIST_H_INCLUDED

using namespace std;

template <typename key, typename info>
class list {
    
    struct list_node {
        key _key;
        info _info;
        list_node *next;   
    };  

    list_node*head;
    list_node*tail; 

    private:
    void forced_push_back(key,info);                                    //When the uniqueness of the key does not matter, this function will be called

    public:
    list(): head(NULL), tail(NULL){}                                    //Constructor
    list(const list<key,info>&theList);                                 //Copy constructor
    ~list();                                                            //Destructor

    bool empty() const;                                                 //If the list is empty, returns true
    bool key_not_unique(key)const;                                      //If the key is not unique, returns true
    bool operator==(const list<key,info>& );                            //If two lists are identical, returns true
    int length() const;                                                 //Returns the length of the list

    void push_back(key,info);                                           //Adds new node with the given key and info at the end of the list, only if the key is unique
    void push_front(key,info);                                          //Adds new node with the given key and info at the beggining of the list, only if the key is unique 

    void pop_back();                                                    //Removes the last node of the list
    void pop_front();                                                   //Removes the first node of the list
    void remove_by_key(key);                                            //Removes the node with the given key
    void clear();                                                       //Removes all nodes from the list

    void print()const;                                                  //Prints the list

    void search_print(key) const;                                       //Searches for the node with the given key and prints it's info
    
    void join(const list<key,info>&,const list<key,info>&);             //Joins two lists together, if the nodes have the same key, infos of those nodes will be merged
    void operator=(const list<key,info>&);                              //Assignment operator
    list<key,info>& operator+(const list<key,info>&);                   //Adds one list to another (A + B), if the nodes with the same keys are found, these nodes from list B will be skipped
    
    };

template <typename key, typename info>
class dictionary {
    list<key,info> _list;
    public:
        void add(key,info);                                                   //Adds new node with the given key and info at the end of the dictionary
        void print() const;                                                   //Prints the dictionary
        void remove_by_key(key);                                              //Removes the node with the given key
        void find_by_key(key);                                                //Searches for the node with the given key and prints it's info
        void join(const dictionary<key,info>&,const dictionary<key,info>&);   //Joins two dictionaries together, if the nodes have the same key, infos of those nodes will be merged
};

#endif