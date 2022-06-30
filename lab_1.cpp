#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    private:
    int row;
    int column;
    int** mat;
    
    public:
    Matrix();
    Matrix(int row,int column);
    Matrix(int row,int column,int** mat);
    
        
    void setValue(int row,int col,int val){
        mat[row-1][column-1]=val;
    }
    int getValue(int row,int col){
        return mat[row-1][column-1];
    }
    int getNoRows(){
        return row;
    }
    int getNoColumns(){
        return column;
    }
    
    void printSpiral(){
         
        int a=0,b=0;
        int c=row-1,d=column-1;
        
        while(a<=c && b<=d){
            for(int i=b;i<=d;i++){
                cout<<mat[a][i]<<" ";
            }
            a++;
            for(int i=a;i<=c;i++){
                cout<<mat[i][d]<<" ";
            }
            d--;
            if(a<=c){
                for(int i=d;i>=b;i--){
                    cout<<mat[c][i]<<" ";
                }
                c--;
            }
            if(b<=d){
                for(int i=c;i>=a;i--){
                    cout<<mat[i][b]<<" ";
                }
            b++;
            }
        } 
    }
    
    int trace(){
        if(row==column){
            int sum=0;
            for(int i=0;i<row;i++){
                sum +=mat[i][i];
            }
            return sum;
        }
        else{
            return -1;
        }
    }
    
    bool checkTriangular(){
        if(row!=column)return false;
        else{
            int flag1=0;
            int flag2=0;
            for(int i=1;i<row;i++){
                for(int j=0;j<i;j++){
                    if(mat[i][j]!=0)flag1=1;
                }
            }
            for(int j=1;j<column;j++){
                for(int i=0;i<j;i++){
                    if(mat[i][j]!=0)flag2=1;
                }
            }
            int flag=flag1*flag2;
            if (flag==0)return true;
            else return false;
        }
    }

    bool isSpecialMatrix(){
        
        int a=0;
        int b=0;
        int flag=0;
        for(int i=0;i<row;i++){
            a+=mat[i][0];
        }
         for(int j=0;j<column;j++){
            b+=mat[0][j];
        }
        if(a!=b){flag=1;}
        for(int i=0;i<row;i++){
            int c=0;
            for(int j=0;j<column;j++){
                c += mat[i][j];
            }
            if(c!=b){flag=1;break;}
            
        }
        for(int j=0;j<column;j++){
            int d=0;
            for(int i=0;i<row;i++){
                d += mat[i][j];
            }
            if(d!=a){flag=1;break;}
            
        }
        if (flag==0)return true;
        else return false;
    }
    
} ;
    
   Matrix::Matrix(){
       this->row=0;
       this->column=0;
       this->mat=NULL;
   }

   Matrix::Matrix(int row,int column){
       this->row=row;
       this->column=column;
       mat= new int*[row];
       for(int i=0;i<row;i++){
           mat[i]=new int[column];
           }
       for(int i=0;i<row;i++){
           for(int j=0;j<column;j++){
               mat[i][j]=0;
           }
       }
   }



   Matrix::Matrix(int row,int column,int** matrix){
        this->row=row;
       this->column=column;
       mat=matrix;
   }

int main() {
    int a,b;
    cin>>a;
    cin>>b;
    int** A;
    A = new int* [a];
    for(int i=0;i<a;i++){
        A[i]= new int[b];
        }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>A[i][j];
        }
    }
    
    Matrix M(a,b,A);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){ 
       int op;
       cin>>op;
       if(op==1){
           M.printSpiral();
           cout<<endl;  
       }
       else if(op==2){
           cout<<M.trace()<<endl;  
       }
       else if(op==3){
           if(M.checkTriangular())cout<<"true"<<endl;
           else cout<<"false"<<endl;
           
       }
       else{
           if(M.isSpecialMatrix())cout<<"true"<<endl;
           else cout<<"false"<<endl;

       }    
    }
    return 0;
}