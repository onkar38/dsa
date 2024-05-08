#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

struct node{
    char name[10];
    int count;
    struct node *child[10];
}*root;

class BST{
    public:
    int chapters;
    void createtree();
    void display(node * r1);
    BST(){
        root=NULL;
    }
};

void BST ::createtree(){
    root = new node();
    cout<<"Enter name of book\n";
    cin>>root->name;
    cout<<"Enter no. of chapters in book\n";
    cin>>chapters;
    root->count = chapters;
    for(int i=0;i<chapters;i++){
        root->child[i]= new node;
        cout<<"Enter chapter name\n";
        cin>>root->child[i]->name;
        cout<<"Enter no. of sections in chapter"<<root->child[i]->name;
        cin>>root->child[i]->count;
        for(int j=0;j<root->child[i]->count;j++){
            root->child[i]->child[j]= new node;
            cout<<"Enter section "<<j+1<<" name\n";
            cin>>root->child[i]->child[j]->name;
        }
    }
}

void BST::display(node * r1){
    if(r1 != NULL){
        cout<<"\n--BOOK HIERARCHY--\n";
        cout<<"Book title :"<<r1->name;
        chapters = r1->count;
        for(int i=0;i<chapters;i++){
            cout<<"\n Chapter "<<i+1;
            cout<<" "<<r1->child[i]->name;
            cout<<"\n Section\n";
            for(int j=0;j<r1->child[i]->count;j++){
                cout<<" "<<r1->child[i]->child[j]->name;
            }
        }
        cout<<endl;
    }
}

int main(){
    int ch;
    BST  bst;
    while(1){
        cout<<"Book Tree Creation"<<endl;
        cout<<" 1.Create  2.Display  3.Quit"<<endl;
        cout<<"Enter choice :";
        cin>>ch;
        switch(ch){
            case 1:
                bst.createtree();
            case 2:
                bst.display(root);
                break;
            case 3:
                exit(1);
            default:
                cout<<"Wrong Choice"<<endl;
        }
    }
}