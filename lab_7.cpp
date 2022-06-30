#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int OneCharOff(string word1,string word2){
    if(word1.size()!=word2.size()) return 0;
    int dif=0;
    for(long unsigned int i=0;i<word1.size();i++){
        if(word1[i]!=word2[i])
            dif++;
    }
    if(dif > 1) return 0;
    else return 1;
}
class Dictionary{
    public:
    void buildDict(vector<string> words) {
        for(long unsigned int i=0; i<words.size(); i++){
            m[words[i]]=i;
        }
    }
    void addWordToDict(string word){
        int b=0;
        map<string,int,less<string>>::iterator iter;
        for(iter=m.begin(); iter!=m.end(); iter++) b++;
        m[word]=b;
    }
    bool search(string target){
        bool akhil=false;
        map<string,int,less<string>>::iterator iter;
        for(iter=m.begin(); iter!=m.end(); iter++){
            if((*iter).first==target) return true;
        }
        return akhil;
    }
    set<string> getWordsAfterReplace(string target){
        map<string,int,less<string>>::iterator iter;
        set<string,less<string>> s;
        for(iter=m.begin(); iter!=m.end(); iter++){
            if(OneCharOff(target,(*iter).first)){
             s.insert((*iter).first);   
            }
        }
        return s;
    }
    set<string> getWordsAfterSwap(string target){
        map<string,int,less<string>>::iterator iter;
        set<string,less<string>> s;
                char temp;
                for(long unsigned int j=0; j<(target.size()-1); j++){
                temp=target[j];
                target[j]=target[j+1];
                target[j+1]=temp;
                for(iter=m.begin(); iter!=m.end(); iter++){
                    if((*iter).first==target) s.insert((*iter).first);
                }
                target[j+1]=target[j];
                target[j]=temp;
            }
        return s;
    } 
    int maxChangeableWord(){
        long unsigned int max=0;
        int maxi=0;
        map<string,int,less<string>>::iterator iter;
        set<string,less<string>> s;
        for(iter=m.begin(); iter!=m.end();iter++){
           s=this->getWordsAfterReplace((*iter).first);
           if(max<s.size()){
               max=s.size();
           }
        }
        for(long unsigned int i=0;i<max;i++) maxi++;
        return maxi-1;
    }
    int maxSwappableWord(){
        long unsigned int max=0;
        int maxi=0;
        map<string,int,less<string>>::iterator iter;
        set<string,less<string>> s;
        for(iter=m.begin(); iter!=m.end();iter++){
           s=this->getWordsAfterSwap((*iter).first);
           if(max<s.size()){
               max=s.size();
           }
        }
        for(long unsigned int i=0;i<max;i++) maxi++;
        return maxi;
    }
    private:
    map<string,int,less<string>> m;
};

int main() {
    Dictionary D;
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    D.buildDict(v);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string str;
        int x;
        cin>>x;
        if(x==1){
            cin>>str;
            D.addWordToDict(str);
        }
        if(x==2){
            cin>>str;
            if(D.search(str)==1) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        if(x==3){
            cin>>str;
            set<string,less<string>> s;
            set<string,less<string>>::iterator iter;
            s=D.getWordsAfterReplace(str);
            if(!s.empty()){
                for(iter=s.begin(); iter!=s.end(); iter++){
                cout<<(*iter)<<" ";
                }
            }
            else cout<<"-1";
            cout<<endl;
        }
        if(x==4){
            cin>>str;
            set<string,less<string>> s;
            set<string,less<string>>::iterator iter;
            s=D.getWordsAfterSwap(str);
            if(!s.empty()){
                for(iter=s.begin(); iter!=s.end(); iter++){
                cout<<(*iter)<<" ";
                }
            }
            else cout<<"-1";
            cout<<endl;
        }
        if(x==5){
            cout<<D.maxChangeableWord()<<endl;
        }
        if(x==6){
            cout<<D.maxSwappableWord()<<endl;    
        }
    }
    return 0;
}