#include <iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
void print(int**arr,int n){
    int i,j;
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j){
            if(arr[i][j]<10){cout<<" ";}
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void cut(int**arr,int c,int n){
    int i,j;
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j){
            if(arr[i][j]==c){
                arr[i][j]=0;
            }
        }
    }
    return;
}

bool find(int**arr,int m,int n){
    int i,j;
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j){
            if(arr[i][j]==m){
                return 1;
            }
        }
    }
    return 0;
}

void check(int**arr,int n,int*p){
    *p=0;
    int i,j;
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j){
            if(arr[i][j]!=0){
                break;
            }
        }
        if(j==n){
            ++*p;
        }
    }
    for(j=0; j<n; ++j){
        for(i=0; i<n; ++i){
            if(arr[i][j]!=0){
                break;
            }
        }
        if(i==n){
            ++*p;
        }
    }
    
    for(i=0; i<n; ++i){
        if(arr[i][i]!=0){
            break;
        }
    }
    if(i==n){
        ++*p;
    }
    for(i=0,j=n-1; i<n&&j>=0; ++i,--j){
        if(arr[i][j]!=0){
            break;
        }
    }
    if(i==n){
        ++*p;
    }
    return;
}

void cutAI(int**arr,int**ar,int n){
    int i,j;
    int numOFzFD=0;
    int numOFzBD=0;
    int r[n+1][n];
    int c[n+1][n];
    int tt;
    int numOFz;
    for(i=0,numOFz=0,tt=0; i<n; ++i,numOFz=0,tt=0){
        for(j=0; j<n; ++j){
            if(arr[i][j]==0){
                ++numOFz;
            }
            else{
                ++tt;
                r[tt][i]=j;
            }
        }
        r[0][i]=numOFz;
    }
    
    for(j=0,numOFz=0,tt=0; j<n; ++j,numOFz=0,tt=0){
        for(i=0; i<n; ++i){
            if(arr[i][j]==0){
                ++numOFz;
            }
            else{
                ++tt;
                c[tt][j]=i;
            }
        }
        c[0][j]=numOFz;
    }
    for(i=0; i<n; ++i){
        if(arr[i][i]==0){
            ++numOFzFD;
        }
    }
    for(i=0; i<n; ++i){
        if(arr[i][n-i-1]==0){
            ++numOFzBD;
        }
    }
    if(numOFzBD==n){ numOFzBD=0; }
    if(numOFzFD==n){ numOFzFD=0; }
    int maxZinR=-1;
    int maxZinC=-1;
    for(j=0; j<n; ++j){
        if(r[0][j]>maxZinR&&r[0][j]!=n){
            maxZinR=r[0][j];
        }
        if(c[0][j]>maxZinC&&c[0][j]!=n){
            maxZinC=c[0][j];
        }
    }
    int maxZ;
    maxZ=max(max(numOFzBD,numOFzFD),max(maxZinR,maxZinC));
    int I,J;
    int MAX=-1;
    if(maxZ==maxZinR){
        for(j=0; j<n; ++j){
            if(r[0][j]==maxZ){
                for(i=1;i<=(n-maxZ); ++i){
                    if(c[0][r[i][j]]>MAX){
                        MAX=c[0][r[i][j]];
                        I=j;
                        J=r[i][j];
                    }
                    if(r[i][j]==j&&numOFzFD>MAX){
                        MAX=numOFzFD;
                        I=j;
                        J=r[i][j];
                    }
                    if((n-1-j)==r[i][j]&&numOFzBD>MAX){
                        MAX=numOFzBD;
                        I=j;
                        J=r[i][j];
                    }
                }
            }
        }
    }
    if(maxZ==maxZinC){
        for(j=0; j<n; ++j){
            if(c[0][j]==maxZ){
                for(i=1;i<=(n-maxZ); ++i){
                    if(r[0][c[i][j]]>MAX){
                        MAX=r[0][c[i][j]];
                        I=c[i][j];
                        J=j;
                    }
                
                     if(c[i][j]==j&&numOFzFD>MAX){
                        MAX=numOFzFD;
                        I=c[i][j];
                        J=j;
                    }
                    if((n-1-c[i][j])==j&&numOFzBD>MAX){
                        MAX=numOFzBD;
                        I=c[i][j];
                        J=j;
                    }
                }
            }
        }
    }
    if(maxZ==numOFzBD){
        for(i=0; i<n; ++i){
           if(arr[i][n-i-1]!=0&&(c[0][n-i-1]+r[0][i])>MAX){
               MAX=(c[0][n-i-1]+r[0][i]);
               I=i;
               J=n-i-1;
           }
        }
    }
    if(maxZ==numOFzFD){
        for(i=0; i<n; ++i){
           if(arr[i][i]!=0&&(c[0][i]+r[0][i])>MAX){
               MAX=(c[0][i]+r[0][i]);
               I=i;
               J=i;
           }
        }
    }
    cout<<"\nI cut number ----------> "<<arr[I][J]<<endl;
        cut(ar,arr[I][J],n);
        arr[I][J]=0;
}

void gen(int**arr, int n,int ran){
    srand(ran);
    int tem,i,j;
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j){
a:
            tem=(rand()%(n*n))+1;
            if(find(arr,tem,n)==1){
                goto a;
                }
                arr[i][j]=tem;
            }
        }
}

int main()
{
    int i,j,c;
    srand(time(0));
    int botwin=0;
    int*p;
    p=&botwin;
    
    int youwin=0;
    int*q;
    q=&youwin;
    
    int n;
    cout<<"enter size\n";
    cin>>n;
    int**ar;
    ar=new int*[n];
    for(i=0; i<n; ++i){
        ar[i]=new int [n];
    }
    int man=0;
    cout<<"if you are want to make your matrix manually then enter 1 \nelse enter 0 to make randomly\n";
    cin>>man;
    if(man==1){
        b:
    cout<<"enter numbers of your matrix row by row\n";
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j){
            cin>>ar[i][j];
        }
    }
     for(i=1; i<=n*n; ++i){
        if(find(ar,i,n)==0){
            cout<<"ERROR\nr";
            goto b;
             }
        }
    }
    else{
        gen(ar,n,rand()%1000);
    }
    int**arr;
    arr=new int*[n];
    for(i=0; i<n; ++i){
        arr[i]=new int [n];
    }
    gen(arr,n,rand()%1000);
    int d=0;
c:
    ++d;
    cout<<d<<".______________________________________\n";
    print(ar,n);
d:
    cout<<"which number do you want to cut\n";
    cin>>c;
    if(find(ar,c,n)==0){
        cout<<"this number is not found\n";
        goto d;
    }
    cut(ar,c,n);
    check(ar,n,q);
    if(youwin>=n){
        cout<<"****BINGO****you are winner\n\a\a\a";
        cout<<"here is your matrix\n";
        print(ar,n);
        cout<<"this is my matrix\n";
        print(arr,n);
        cout<<endl;
        return 0;
    }
    cut(arr,c,n);
    check(arr,n,p);
    if(botwin>=n){
        cout<<"i am winner and here is my matrix\n\a\a\a";
        print(arr,n);
         cout<<"here is your matrix\n";
        print(ar,n);
        cout<<endl;
        return 0;
    }
    cutAI(arr,ar,n);
    check(arr,n,p);
    if(botwin>=n){
        cout<<"i am winner and here is my matrix\n\a\a\a";
        print(arr,n);
         cout<<"here is your matrix\n";
        print(ar,n);
        cout<<endl;
        return 0;
    }
    check(ar,n,q);
    if(youwin>=n){
        cout<<"****BINGO****you are winner\n\a\a\a";
        cout<<"here is your matrix\n";
        print(ar,n);
        cout<<"this is my matrix\n";
        print(arr,n);
        cout<<endl;
        return 0;
    }
    goto c;
}
