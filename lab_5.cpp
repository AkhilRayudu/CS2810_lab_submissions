#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
    public:
    node(){
        this->next=NULL;
    }
    int val;
    node* next;
};

class stack{
    public:
    stack(){
        head=NULL;
    }
    void push(int x){
        if(head==NULL){
            node* temp= new node;
            temp->val=x;
            head=temp;
        }
        else{
            node* temp = new node;
            temp->val=x;
            temp->next=head;
            head=temp;
        }
    }
    int pop(){
        if(isEmpty()) return -1;
        else{
            int temp=head->val;
            node *ptr = head;
            head=head->next;
            delete ptr;
            return temp;
            }
}

    int top(){
        if(isEmpty())return -1;
        else return head->val;
    }
            
    int isEmpty(){
        if(head==NULL) return 1;
        else return 0;
    }
    
    private:
    node* head;
};

class graph{
    public:
    graph(int n){
        adj = new int*[n];
        for(int i=0;i<n;i++){
            adj[i] = new int[n];
            for(int j=0;j<n;j++){
            adj[i][j]=0;
            }
        }
        visited = new int[n];
        vertices = n;
    }
    
    void operator +=(pair<int,int>p) {
       adj[p.first][p.second]=1;
       adj[p.second][p.first]=1;
       return;
   }
    
    void operator -=(pair<int,int>p){
       adj[p.first][p.second]=0;
       adj[p.second][p.first]=0;
       return;
   }
    int detectCyclemini(int** temp,int u){
        visited[u]=1;
            for(int i=0;i<vertices;i++){
                if(temp[u][i]==1 && visited[i]==1 ) return 1;
                if(temp[u][i]==1 && visited[i]==0){
                    temp[u][i]=0;
                    temp[i][u]=0;
                    detectCyclemini(temp,i);  
                }
            }
        return 0;
    }
    int detectCycle(){
        temp = new int*[vertices];
        for(int i=0;i<vertices;i++){
            temp[i] = new int[vertices];
            for(int j=0;j<vertices;j++){
            temp[i][j]=adj[i][j];
            }
        }
        for(int i=0;i<vertices;i++) visited[i]=0;
        int sum=0;
        for(int i=0;i<vertices;i++){
            int b=detectCyclemini(temp,i);
            for(int i=0;i<vertices;i++) visited[i]=0;
            sum = sum+b;
        }
        if(sum==0) return 0;
        else return 1;
    }
    int reach(int u, int v){
        int t;
        s.push(u);
        for(int i=0;i<vertices;i++) visited[i]=0;
        visited[u]=1;
        while(!s.isEmpty()){
            t=s.pop();
            for(int i=0;i<vertices;i++) {
                if(adj[t][i]==1 && visited[i]==0){
                    visited[i]=1;
                    if(i==v) return 1;                 
                    s.push(i);
                }

            }
            
        }
        return 0;
        }       
      
    friend ostream & operator <<(ostream & out, graph &G){
        for(int i=0;i<G.vertices;i++)
        {
            for(int j=0;j<G.vertices;j++) out<<G.adj[i][j]<<" ";
                out<<endl;
        }
        return out;
    }
    private:
    int vertices;
    int edges;
    int** adj;
    int** temp;
    int* visited;
    stack s;
};


  
int main() {
    int q;
    stack s;
    int n,m;
    cin>>q;
    for(int i=0;i<q;i++){
        string op;
        cin >>op;
        if(op=="push"){
           int x;
           cin>>x;
           s.push(x);
        }
        if(op=="pop"){
           cout<<s.pop()<<endl; 
        }
        if(op=="top"){
           cout<<s.top()<<endl; 
        }
        if(op=="empty"){
           cout<<s.isEmpty()<<endl; 
        }
    }
    cin>>n;
    graph g(n);
    cin>>m;
    for(int i=0;i<m;i++){
        string op;
        cin>>op;
        int u,v;
        if(op=="add"){
           cin>>u;
           cin>>v;
           g+=make_pair(u,v); 
        }
        if(op=="del"){
            cin>>u;
           cin>>v;
           g-=make_pair(u,v);
        }
        if(op=="cycle"){
           cout<<g.detectCycle()<<endl; 
        }
        if(op=="print"){
           cout<<g; 
        }
        if(op=="reach"){
            cin>>u;
            cin>>v;
            cout<<g.reach(u,v)<<endl;
        }

    }
    return 0;
}
