#pragma once
#include <memory>

using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;

template<class Type>
struct Node{
    Type data;
    //Node<Type> *next;
    shared_ptr <Node<Type> > next;
};

template<class Type>
class LinkedList;

template<class Type>
ostream& operator<< (ostream& out, const LinkedList<Type>& list);

template<class Type>
class LinkedList{
    public:
        LinkedList(): front(nullptr), back(nullptr), cou(0) {}// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
        //~LinkedList();           //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
        void insert(Type data);  //Adds to the back of the list
        Type peek(int ndx)const ;//Looks at an element at the given ndx value
        void remove(int ndx);    //Removes an element at the given ndx position
        friend ostream& operator<< <>(ostream& out, const LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList
    protected:
        //Node<Type> *front;
        //Node<Type> *back;
        shared_ptr <Node<Type> > front;
        shared_ptr <Node<Type> > back;
        int cou;



};

template<class Type>
void LinkedList<Type>::insert(Type data){
    auto temp = make_shared<Node<Type>> ();
    temp->data = data;
    temp ->next = nullptr;
    if(!front){
        front = temp;
        back = temp;
    }
    else{
        back->next = temp;
        back = temp;
    }
    cou++;
} 

template<class Type>
Type LinkedList<Type>::peek(int ndx)const{
    if(ndx >= cou || ndx < 0){
        throw runtime_error("Out of range");
    }

    int currNodeNum = 0;
    auto currentNode = front;

    while(currNodeNum < ndx){
        currNodeNum++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<class Type>
void LinkedList<Type>::remove(int ndx){
   if(ndx >= cou || ndx < 0){
        throw runtime_error("Out of range");
    }

    if(ndx == 0) {
        auto toDelete = front;
        front = toDelete -> next;
        return;
    }
    int currNodeNum = 0;
    auto currentNode = front;

    while(currNodeNum < ndx-1){
        currNodeNum++;
        currentNode = currentNode->next;
    
    }  
    auto toDelete = currentNode->next;

    if(toDelete->next){
        currentNode->next = toDelete->next;
    }
    else{
        currentNode->next = nullptr;
        back = currentNode;
    }
    cou --;


}

template<class Type>
ostream& operator<< (ostream& out, const LinkedList<Type>& list){
    auto curr = list.front;

    while(curr){
        out << curr->data;
        if(curr->next){
            out << " ";
        }
        curr = curr->next;
    }
    return out;
}
