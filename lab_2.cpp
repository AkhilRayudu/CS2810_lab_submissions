#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Book{
    public:
    string title;
    string author;
    int year;
    int price;
    Book* next;
    Book(string a,string b,int c,int d){
        this->title=a;
        this->author=b;
        this->year=c;
        this->price=d;
    }
        
};

class Bookshelf{
    
    public:
    Book* head=NULL;
    Book* tail=NULL; 
    bool checkEmpty(){
        if(head==NULL||tail==NULL) return true;
        else return false;
    }
};

class VerticalBookshelf:public Bookshelf{
    public:
    void addBook(string a,string b,int c,int d){
        if(head==NULL){
            Book*temp =new Book(a,b,c,d);
            head=temp;
            tail=head;
            tail->next=NULL;
        }
        else{
            Book* temp=new Book(a,b,c,d);
            temp->next=head;
            head=temp;  
        }
    }
    void removeBook(){
        if(head==NULL) cout<<"e"<<endl;
        else if(head==tail){
            head=NULL;
            tail=NULL;
        }
        else{
            Book* temp = head;
            head=temp->next;
            delete temp;   
        }
    }
    void list(){
        if(head==NULL){
            cout<<"e"<<endl;
            return;    
        }
        else{
            Book* temp=head;
            while(temp!=NULL){   
                cout<<temp->title<<","<<temp->author<<","<<temp->year<<","<<temp->price<<endl;
                temp=temp->next;
            }
        }
    }
    void findCheap(){
        if(head==NULL){
            cout<<"e"<<endl;
            return;
        }
        else{
            Book* temp=head;
            int small;
            small=head->price;
            while(temp!=NULL){
                if(small<temp->price){
                    if(temp->next!=NULL)
                        cout<<small<<",";
                    if(temp->next==NULL)
                        cout<<small<<endl;
                }
                else{
                    small=temp->price;
                    if(temp->next!=NULL)
                        cout<<"-1,";
                    if(temp->next==NULL)
                        cout<<"-1"<<endl;
                }
                temp=temp->next;
            }
        }
    }
    void reverseUnique(){
        Book* temp = head;
        while(temp != NULL){
            Book* temp1 = temp;
            while(temp1!=NULL){ 
                Book*temp2=temp1->next;
                if(temp2!=NULL && temp->title==temp2->title && temp->author==temp2->author && temp->year==temp2->year && temp->price==temp2->price){
                    if(temp2->next!=NULL){
                        temp1->next=temp2->next;
                        delete temp2;
                        continue;
                    }
                    if(temp2->next==NULL){
                        temp1->next=NULL;
                        delete temp2;
                        continue;
                    }
                }
                temp1=temp1->next;
            }
            temp=temp->next;
        }
        
        VerticalBookshelf v;
        Book* temp3 =head;
        while(temp3 != NULL){
            v.addBook(temp3->title,temp3->author,temp3->year,temp3->price);
            temp3=temp3->next;
        }
        tail=head;
        head=v.head;
    }
};
class HorizontalBookshelf: public Bookshelf{
    public:
    void addBook(string a,string b,int c,int d){
        if(head==NULL){
            Book* temp=new Book(a,b,c,d);
            temp->next=NULL;
            head=temp;
            tail=head;
        }
        else{
            Book* temp1 =new Book(a,b,c,d);
            tail->next=temp1;
            tail=tail->next;
        }
    }
    void removeBook(){
        if(head==NULL) cout<<"e"<<endl;
        if(head!=NULL){
            Book* temp = head;
            head=temp->next;
            delete temp;
        }
    }
    void list(){ 
        if(head==NULL){
            cout<<"e"<<endl;
            return;
        }
        else{
            Book*temp=head;
            while(temp!=NULL){
                cout<<temp->title<<","<<temp->author<<","<<temp->year<<","<<temp->price<<endl;
                temp=temp->next;
            }
        }
    }
    void findCheap(){
        if(head==NULL){
            cout<<"e"<<endl;
            return;
        }
        else{
            Book* temp=head;
            int small;
            small=head->price;
            while(temp!=NULL){
                if(small<temp->price){
                    if(temp->next!=NULL) cout<<small<<",";
                    if(temp->next==NULL) cout<<small<<endl;
                }
                else{
                    small=temp->price;
                    if(temp->next!=NULL) cout<<"-1,";
                    if(temp->next==NULL) cout<<"-1"<<endl;
                }
                temp=temp->next;
            }
        }    
    }
    void reverseUnique(){
        Book* temp=head;
        while(temp!=NULL){
            Book* temp1=temp;
            while(temp1!=NULL){    
                Book * temp2=temp1->next;
                if(temp2!=NULL && temp->title==temp2->title && temp->author==temp2->author && temp->year==temp2->year && temp->price==temp2->price){
                    if(temp2->next!=NULL){
                        temp1->next=temp2->next;
                        continue;
                    }
                    if(temp2->next==NULL){
                        temp1->next=NULL;
                        continue;
                    }
                }
                temp1=temp1->next;
            } 
            temp=temp->next;
        }
         
        VerticalBookshelf v;
        Book* temp3 =head;
        while(temp3 != NULL){
            v.addBook(temp3->title,temp3->author,temp3->year,temp3->price);
            temp3=temp3->next;
        }
        tail=head;
        head=v.head;
        
        HorizontalBookshelf h;
        Book* temp4 =v.head;
        while(temp4 != NULL){
            h.addBook(temp4->title,temp4->author,temp4->year,temp4->price);
            temp4=temp4->next;
        }
        tail=h.tail;
        head=h.head;
    }
};

int main() {
    int Q;
    cin>>Q;
    HorizontalBookshelf h;
    VerticalBookshelf v;
    for(int i=0;i<Q;i++){
        string l;
        cin>>l;
        if(l=="ADD"){
            char x;
            string a;
            string b;
            int c;
            int d;
            cin>>x>>a>>b>>c>>d;
            if(x=='h') h.addBook(a,b,c,d);
            if(x=='v') v.addBook(a,b,c,d);
        }
        if(l=="REMOVE"){
            char x;
            int n;
            cin>>n;
            cin>>x;
            if(x=='h'){
                for(i=0;i<n;i++) h.removeBook();
            }
            if(x=='v'){
                for(i=0;i<n;i++) v.removeBook();
            }
        }
        if(l=="LIST"){
            char x;
            cin>>x;
            if(x=='h') h.list();
            if(x=='v') v.list();    
        }
        if(l=="FINDC"){
            char x;
            cin>>x;
            if(x=='h') h.findCheap();
            if(x=='v') v.findCheap();
        }
        if(l=="REVUNI"){
            char x;
            cin>>x;
            if(x=='h') h.reverseUnique();
            if(x=='v') v.reverseUnique();
       }
    
   }
    return 0;
}
