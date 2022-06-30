#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string> 
#include <ctime>
#include <time.h>
#include <cstdlib>
using namespace std;

template<typename T>
class node{
    public:
    node<T>* before;
    node<T>* after;
    node<T>* above;
    node<T>* below;
    T key;
    T value;
    node(){
        this->before=NULL;
        this->after=NULL;
        this->above=NULL;
        this->below=NULL;
    }
};

template<typename T>
class skiplist{
    public: 
    node<T>* start_left;
    int lvl;
    T minkey;
    T maxkey;
    int noOfEntries;
    void setup(T max,T min){
        this->maxkey=max;
        this->minkey=min;
        node<T>* start = new node<T>();
        node<T>* end = new node<T>();
        start->key=this->minkey;
        start->after=end;
        end->before=start;
        end->key=this->maxkey;
        this->lvl=0;
        this->start_left=start;
        this->noOfEntries=0; 
    };
    void insert1(T k,T v){
        node<T>* p = this->search(k);
        node<T>* q = new node<T>();
        node<T>* s = new node<T>();
        node<T>* t = new node<T>(); 
        node<T>* u = new node<T>();
        
        int i=-1;
        do{
            i++;
            if(i>=this->lvl && this->lvl<10){
                this->lvl=this->lvl+1;
                s->after=u;
                s->key=minkey;
                u->before=s;
                u->key=maxkey;
                t=(this->start_left)->after;
                t->above=u;
                u->below=t;
                (this->start_left)->above=s;
                s->below=(this->start_left);
                (this->start_left)=s;
            } 
            if(i==0){
                (p->after)->before=q;
                q->after=p->after;
                q->before=p;
                p->after=q;
                q->value=v;
                q->key=k;
            }
            else{
                while(p->above==NULL){
                    p=p->before;
                }
                p=p->above;
                q=insertAfterAbove(p,q,k,v); 
            }
            srand((unsigned)time(0));
        }
        while((rand())%2==1 && i<9);
        this->noOfEntries=this->noOfEntries+1;
        
    }
    void deletekey(T k){
        node<T>* p = this->search(k);
        if(p->key!=k) return;
        else{
            while(p!=NULL){
                node<T>* p1=p;
                (p->before)->after=p->after;
                (p->after)->before=p->before;
                p=p->above;
                delete(p1);
            }
            this->noOfEntries=this->noOfEntries-1;
        }
    }
    node<T>* insertAfterAbove(node<T>* &p,node<T>* &q,T k,T v){
        node<T>* r = new node<T>();
        r->value=v;
        r->key=k;
        (p->after)->before=r;
        r->after=p->after;
        p->after=r;
        r->before=p;
        q->above=r;
        r->below=q;
        return r;
    }
    node<T>* search(T k){
        node<T>* p =this->start_left;
        while(p->below!=NULL){
            p=p->below;
            while(k>=(p->after)->key){
                p=p->after;
            }
        }
        return p;
    }
    
};

template<typename T>
class Dictionary:public skiplist<T>{
    public:
    void empty(){
        if(skiplist<T>::noOfEntries==0) cout<<"True"<<endl;
        else cout<<"False"<<endl;
    }
    void insert(T k,T v){
        skiplist<T>::insert1(k,v);
    }
    void delkey(T k){
        skiplist<T>::deletekey(k);
    }
    void find(T k){
        node<T>* p = skiplist<T>::search(k);
        if(p->key==k){
            cout<<p->value<<endl;
        }
        else cout<<"NOT FOUND"<<endl;
    }
    void size(){
        cout<<skiplist<T>::noOfEntries<<endl;
    }
};

int main(){
   
    string dictype;
    string op;
    cin>>dictype;
    int p;
    cin>>p;
    if(dictype=="INTEGERDICT"){
        Dictionary<int> D;
        int k,v;
        int max=1000000000;
        int min=-1000000000;
        D.setup(max,min);
        for(int i=0;i<p;i++){
            cin>>op;
            if(op=="ISEMPTY"){
                D.empty();
            }
            else if(op=="INSERT"){
                cin>>k;
                cin>>v;
                D.insert(k,v);
            }
            else if(op=="DELETE"){
                cin>>k;
                D.delkey(k);
            }
            else if(op=="FIND"){
                cin>>k;
                D.find(k);
            }
            else{
                D.size();
            }
        }
    }
    if(dictype=="STRINGDICT"){
        Dictionary<string> D;
        string k,v;
        string max="{";
        string min="Z";
        D.setup(max,min);
        for(int i=0;i<p;i++){
            cin>>op;
            if(op=="ISEMPTY"){
                D.empty();
            }
            else if(op=="INSERT"){
                cin>>k;
                cin>>v;
                D.insert(k,v);
            }
            else if(op=="DELETE"){
                cin>>k;
                D.delkey(k);
            }
            else if(op=="FIND"){
                cin>>k;
                D.find(k);
            }
            else{
                D.size();
            }
        }  
    }
    return 0;
}