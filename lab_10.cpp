#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class dp_base{
    public:
    void n_set(int x){
        this->n=x;
    }
    virtual void max_val(int n,int r[],int w[],int W){
        cout<<"You can't print me"<<endl;
    }
    private:
    int max;
    int n; 
};

class dp_derived:public dp_base{
    public:
    virtual void max_val(int n,int r[],int w[],int W){
        dp[0]=0;
        int temp;
        for(int i=1;i<=W;i++){
            temp=0;
            for(int j=0;j<n;j++){
                if(w[j]<=i){
                    if((dp[i-w[j]]+r[j])>temp) temp=dp[i-w[j]]+r[j];
                }
            }
            dp[i]=temp;
        }
        cout<<dp[W]<<endl;  
    }
    private:
    int dp[10000];
};

int main() {
    int capacity;
    cin>>capacity;
    int n;
    cin>>n;
    int revenue[n];
    int weight[n];
    for(int i=0;i<n;i++) cin>>revenue[i];
    for(int i=0;i<n;i++) cin>>weight[i];
    dp_derived der;
    der.max_val(n,revenue,weight,capacity);
    return 0;
}