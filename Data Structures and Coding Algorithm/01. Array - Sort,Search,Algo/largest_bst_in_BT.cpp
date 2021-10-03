#include<bits/stdc++.h>
using namespace std;
typedef struct tree{
    int val;
    struct tree *left,*right;
    tree(int v){
        val=v;
        left=right=NULL;
    }
}* tptr;

void insert(tptr &t){
    int n;
    cin>>n;
    if(n!=-1){
        t=new tree(n);
        insert(t->left);
        insert(t->right);
    }
    else t=NULL;
}
int find(tptr t,int &mn,int &mx,int &size){
    if(t){
         //   cout<<t->val<<" \n";
        if(t->left==NULL&&t->right==NULL){
            mx=mn=t->val;
            return 1;
        }

        int sz=0;
        int mlx,mln;
        if(t->left){
            sz=find(t->left,mln,mlx,size);
        }
        int rsz=0,mrx,mrn;
        if(t->right){
            rsz=find(t->right,mrn,mrx,size);
        }
        if(sz==-1||rsz==-1)
        return -1;


        if(sz==0){
            if(t->val<mrn){
                mn = t->val;
                mx=mrx;
              //  cout<<rsz+1<<" rsz+1 "<<t->val<<endl;
                size=max(size,rsz+1);
                return rsz+1;
                
            }
            else return -1;
        }
        else{
            if(t->right){
                if(mlx<t->val&&t->val<mrn){
                    sz= sz+1+rsz;
                    //   cout<<sz<<" sz+1+rsz "<<t->val<<endl;
                     size=max(size,sz);
                     mn=mln;
                     mx=mrx;
                     return sz;
                }
                else return -1;
            }
            else{
                if(mlx<t->val){

                        mn = mln;
                        mx=t->val;
                           cout<<sz+1<<" sz+1 "<<t->val<<endl;
                        size=max(size,sz+1);
                        return sz+1;
                }
                else return -1;
            }
        }


    


    }

}
void ldr(tptr t){
    if(t){
        ldr(t->left);
        cout<<t->val<<" ";
        ldr(t->right);
    }
}
int main(){
    tptr root=NULL;
    insert(root);
    ldr(root);
    cout<<endl;
    int mn =INT_MIN,mx=INT_MAX,sz=1;
    find(root,mn,mx,sz);
    cout<<sz<<endl;
    return 0;
}