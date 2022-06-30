#include <iostream>

using namespace std;

template<typename T>
class queue{
    public:
    queue(){
        Q= new T[101];
        capacity=101;
        t=-1;
    }
    void enqueue(T document){
        Q[++t]=document;
    }
    T dequeue(){
        T a;
        a = Q[0]; 
        for(int i=0;i<t;i++){
            Q[i]=Q[i+1];
        }
        t--;
        return a;
    }
    int size(){
        return (t+1);
    }
    
    bool isEmpty(){
        if(t<0) return true;
        else return false;
    }
    
    private:
    int capacity;
    int t;
    T* Q;
    
};
template <typename T>
class printer{
    public:
    printer(int cap,int ink){
        this->capacity=cap;
        this->ink=ink;
    }
    void addDocument(T document){
        if(q.size()==capacity){
            throw printerBusy("PRINTER_BUSY");
        }
        q.enqueue(document);
    }
    T printDocument(){
        if(q.size()==0){
            throw noDocument("NO_DOCUMENT");
            
        }
        if(this->ink==0){
            throw insufficientInk("INSUFFICIENT_INK");
        }
        T a;
        a=q.dequeue();
        this->ink=this->ink-1;
        return a;
    }
    void fillInk(int a){
        this->ink=a;
    }
    
    class insufficientInk{
        public:
        insufficientInk(string reason){
            cout<<reason<<endl;
       
        }
    };
    class printerBusy{
        public:
        printerBusy(string reason){
            cout<<reason<<endl;    
        }
    };
    class noDocument{
        public:
        noDocument(string reason){
            cout<<reason<<endl;
        }
    };
    
    private:
    int ink;
    int capacity;
    queue<T> q;

};


int main() {
    int m,n,q;
    char t;
    int command;
    cin>>m>>n>>t;
    cin>>q;
    if(t=='C'){
    printer<char> p(m,n);
    for(int i=0;i<q;i++){
        cin>>command;
        try{
        if(command==1){
            char doc;
            cin>>doc;
            p.addDocument(doc); 
        }
        if(command==2){
            char doc;
            doc = p.printDocument();
            cout<<doc<<endl;
        }
        if(command==3){
            int j;
            cin>>j;
            p.fillInk(j);
        }
        }
        catch(printer<char>::insufficientInk){}
        catch(printer<char>::noDocument){}
        catch(printer<char>::printerBusy){}

    }
    }
    if(t=='I'){
        printer<int> p(m,n);
        for(int i=0;i<q;i++){
        cin>>command;
        try{
        if(command==1){
            int doc;
            cin>>doc;
            p.addDocument(doc); 
        }
        if(command==2){
            int doc;
            doc = p.printDocument();
            cout<<doc<<endl;
        }
        if(command==3){
            int j;
            cin>>j;
            p.fillInk(j);
        }
        }
        catch(printer<int>::insufficientInk){}
        catch(printer<int>::noDocument){}
        catch(printer<int>::printerBusy){}

    }
    }
    if(t=='F'){
    printer<float> p(m,n);
    for(int i=0;i<q;i++){
        cin>>command;
        try{
        if(command==1){
            float doc;
            cin>>doc;
            p.addDocument(doc); 
        }
        if(command==2){
            float doc;
            doc = p.printDocument();
            cout<<doc<<endl;
        }
        if(command==3){
            int j;
            cin>>j;
            p.fillInk(j);
        }
        }
        catch(printer<float>::insufficientInk){}
        catch(printer<float>::noDocument){}
        catch(printer<float>::printerBusy){}

    }       
    }
    
 
    return 0;
}