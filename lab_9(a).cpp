#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int retmin(int a,int b,int c){
    if(a <= b && a <= c) return a;
    else if(b <= c) return b;
    else return c;
}

int edit_distance(string a,string b){
    int p,q,r,diff;
    long unsigned int m,n;
    m=a.size();
    n=b.size();
    int arr[m+1][n+1];
    for(long unsigned int i=0;i<=m;i++){
        arr[i][0]=i;
    }
    for(long unsigned int i=0;i<=n;i++){
        arr[0][i]=i;
    }
    for(long unsigned int i=1;i<=m;i++){
        for(long unsigned int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]) diff=0;
                else diff=1;
                p=arr[i-1][j]+1;
                q=arr[i][j-1]+1;
                r=arr[i-1][j-1]+diff;
                arr[i][j]=retmin(p,q,r);
        }
    }
    return arr[m][n];
}

string LCS(string a,string b){
    int m,n;
    string str="EMPTY";
    m=a.size();
    n=b.size();
    int l[m+1][n+1];
    for(int i=0;i<=m;i++){
        l[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        l[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]) l[i][j]=l[i-1][j-1]+1;
            else l[i][j]=max(l[i][j-1],l[i-1][j]); 
        }
    }
    int len=l[m][n];
    if(len==0) return str;
    else{
        char lcs[len+1];
        lcs[len]='\0';
        int p=m;
        int q=n;
        while((p*q)!=0){
            if(a[p-1] == b[q-1]){
                lcs[len-1]= b[q-1];
                p=p-1;
                q=q-1;
                len=len-1;
            }
            else if (l[p][q-1] >= l[p-1][q]){
                q--;
            }
            else p--;
        }
        return lcs;
     }
}

int lcslen(string a,string b){
    int m,n;
    m=a.size();
    n=b.size();
    int l[m+1][n+1];
    for(int i=0;i<=m;i++){
        l[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        l[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]) l[i][j]=l[i-1][j-1]+1;
            else l[i][j]=max(l[i][j-1],l[i-1][j]); 
        }
    }
    return l[m][n];
}

void lcs_compare(string a,vector<string> v,int min){
    vector<string> lucky;
    int rrr[v.size()];
    int max= lcslen(a,v[0]);
    rrr[0]=max;
    for(int i=1;i<v.size();i++){
        rrr[i]=lcslen(a,v[i]);
        if(max<rrr[i]) max=rrr[i];
    }
    for(int i=0;i<v.size();i++){
        if(rrr[i]==max) lucky.push_back(v[i]);
    }
    for(int i=0;i<lucky.size();i++){
        cout<<a<<endl;
        cout<<lucky[i]<<endl;
        cout<<LCS(a,lucky[i])<<endl;
        cout<<min<<endl;
    }
    return;
}

void procedure(string a,vector<string> d){
    vector<string> vec;
    int arr[d.size()];
    int min = edit_distance(a,d[0]);
    arr[0]=min;
    for(int i=1;i<d.size();i++){
        arr[i]=edit_distance(a,d[i]);
        if(min>arr[i]) min=arr[i];
    }
    for(int i=0;i<d.size();i++){
        if(arr[i]==min) vec.push_back(d[i]);
    }
    if(vec.size()==1){
        cout<<a<<endl;
        cout<<vec[0]<<endl;
        cout<<LCS(a,vec[0])<<endl;
        cout<<min<<endl;
    }
    else{
        lcs_compare(a,vec,min);
    }
    
    return;
}

int main() {
    int n,d;
    cin>>n;
    string words[n];
    string str;
    vector<string> dictionary;
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    cin>>d;
    for(int i=0;i<d;i++){
        cin>>str;
        dictionary.push_back(str);
    } 
    for(int i=0;i<n;i++){
            procedure(words[i],dictionary);
    }
    return 0;
}