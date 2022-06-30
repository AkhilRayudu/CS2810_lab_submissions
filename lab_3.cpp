#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class node{
    public:
    node<T>* left;
    node<T>* right;
    T variable;
};

template<typename T>
class dll{
    public:
    void push_end(T val){
        if(tail==NULL){
            node<T>* temp= new node<T> ;
            temp->variable=val;
            temp->left=NULL;
            temp->right=NULL;
            head=temp;
            tail=temp;
            size++;
        }
        else{
            node<T>* temp = new node<T>;
            temp->variable=val;
            temp->left=tail;
            temp->right=NULL;
            tail->right=temp;
            tail=temp;
            size++;
        }
    }; 
    void push_front(T val){
        if(head==NULL){
            node<T>* temp= new node<T>;
            temp->left=NULL;
            temp->right=NULL;
            temp->variable=val;
            tail=temp;
            head=tail;
            size++;
        }
        else{
            node<T>* temp= new node<T>;
            temp->left=NULL;
            temp->right=head;
            temp->variable=val;
            head->left=temp;
            head=temp;  
            size++;
        }
        
    }
    T pop_front(){
        if(head->right==NULL){
            T temp;
            temp = head->variable;
            delete(head);
            head=NULL;
            tail=NULL;
            size--;
            return temp;
        }
        else{
            T temp;
            temp = head->variable;
            node<T>* ptr = head->right;
            (ptr)->left=NULL;
            delete(head);
            head = ptr;
            size--;
            return temp;
        }
    }
    T pop_end(){
        if(tail->left==NULL){
            T temp;
            temp = tail->variable;
            delete(tail);
            head=NULL;
            tail=NULL;
            size--;
            return temp;
        }
        else{
            T temp;
            temp = tail->variable;
            node<T>* ptr = tail->left;
            (ptr)->right=NULL;
            delete(tail);
            tail=ptr;
            size--;
            return temp;
        }
    }
    int Size(){
        return size;
    }
    private:
    node<T>* head = NULL;
    node<T>* tail = NULL;
    int size = 0;
    
};

template<typename T>
class stack{
    public:
    void push(T val){
       s.push_front(val);
    }
    T pop(){
       return s.pop_front();
    }
    T top(){
        T temp = s.pop_front();
        s.push_front(temp);
        return temp;        
    }
    int size()
    {
        return s.Size();
    }
    bool compare(T n)
    {
        if(n>s.top()) return true;
        else return false;
    }
    private:
        dll<T> s;
};

template<typename T>
void encrypt(stack<T> p,int n){
        for(int i=0;i<n;i++){
            T temp;
            cin>>temp;
            if(p.size()==0){
                p.push(temp);
            }
            else if(temp>p.top()){
                p.push(temp);
            }
            else if(temp<=p.top()){
                while(p.size()>0 && temp<=p.top()){
                    cout<<p.pop();
                }
                p.push(temp);
            }
                
        }
        while(p.size()!=0){
            cout<<p.pop();
        }
        
    }

int main() {
    int n;
    char c;
    cin>>n;
    cin>>c;
    if(c=='I'){
       stack<int> p;  
       encrypt(p,n);
    }
    if(c=='C'){
       stack<char> p;  
       encrypt(p,n);
    }
    if(c=='F'){
       stack<float> p;  
       encrypt(p,n);
    }
}