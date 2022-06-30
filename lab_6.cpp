#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Node{
    private:
    bool isEnd = false;
    vector<Node *> next;
    public:
    Node(){
        next.resize(26);
        for(int i=0; i<26;i++){
            next[i]=NULL;
        }
    }
    bool getIsEnd(Node* tmp){
        return tmp->isEnd;
    }
    void setIsEnd(Node* tmp){
        tmp->isEnd=true;
        return;
    }
    vector<Node*> getNext(Node* tmp){
        return tmp->next;
    }
    Node* setNext(Node* temp, int n){
        Node* tmp = new Node;
        temp->next[n]=tmp;    
        return tmp;
    }
    
};

class Trie{
    public:
    Trie(){
        Node* temp=new Node;
        this->root=temp;
    }
    void insert(string str){
        Node* temp=root;
        long unsigned int i=0;
        while(i<str.size()){
            if(temp->getNext(temp)[str[i]-97]==NULL){
                int n= str[i]-97;
                temp=temp->setNext(temp,n);
            }
            else{
                temp=temp->getNext(temp)[str[i]-97]; 
            }
            i++;
        }
        temp->setIsEnd(temp);
    }
    string check(string& str,string& str1){
        Node* temp=root;
        long unsigned int i=0;
        int flag=0;
        while(i<str1.size()){
            if(temp->getNext(temp)[str1[i]-97]==NULL) flag=1; 
            else if(i<(str1.size()-1) && temp->getIsEnd(temp)==true) flag=1;
            else temp=temp->getNext(temp)[str1[i]-97];
            i++;
        }
        if(flag==0){
            i=0;
            while(i<str1.size()){
                if(str[i]!=str1[i]) flag=1; 
                i++;
            }
        }
        if(flag==0){
            return str1;
        }
        string s="";
        return s;
    }
    private:
    Node* root;
} ;

int main() {
    Trie t;
    int p;
    cin>>p;
    string str;
    vector<string> v;
    vector<string> u;
    for(int i=0; i<p; i++){
        cin>>str;
        v.push_back(str);
    }
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>str;
        u.push_back(str);
    }
    for(int i=0; i<n; i++){
        t.insert(u[i]);
    }
    for(int i=0; i<n; i++){
    vector<string> w;
    for(int j=0; j<p; j++){
         w.push_back(t.check(u[i],v[j]));
    }
    long unsigned int k=0;
    long unsigned int max=0;
    while(k<w.size()){
        if(w[k].size()>w[max].size()) max=k;
        k++;
    }
    if(w[max].size()!=0) u[i]=w[max];
}
    for(int i=0; i<n; i++){
        cout<<u[i]<<" ";
    }
    return 0;
}