#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,p,q;
    cin>>n;
    int a[n];
    int maxi;
    int j,r,s,t;
    r=0;
    s=0;
    int b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>p;
    for(int diff=1;diff<n-1;diff++){
        for(int i=1;i<n-diff;i++){
            j=diff+i;
            int maxi=0;
            for(int k=i;k<=j-1;k++){
                q=b[i][k]+b[k+1][j]+a[i-1]*a[k]*a[j];
                if(q>maxi){
                    maxi=q;
                    r=a[i-1];
                    s=a[j];
                }
            }
            b[i][j]=maxi;
        }
    }
    t=b[1][n-1]+r*s+max(r,s);
    cout<<t<<endl;
    if(t>=p) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}