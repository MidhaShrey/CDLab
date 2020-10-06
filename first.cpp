#include <Iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
typedef struct treenode
{
    char info;
    treenode *left;
    treenode *right;
}node;


    node * proc_e(char input[],int &ssm);
    node * proc_t(char input[],int &ssm);
    node * proc_v(char input[],int &ssm);
    void traversal(node *temp);

int main()
{
    char input[20];
    int ssm=0;
    node *root;

    cout<<endl<<"ENTER THE STRING TO BE PARSED:";
    cin>>input;

    root = proc_e(input,ssm);
    cout<<endl<<"CONTENTS OF THE PARSE TREE:";
    traversal(root);


    getch();
    return 0;
}


void traversal(node *temp)
{


   if(temp != NULL)
   {
    traversal(temp->left);
    cout<<temp->info;
    traversal(temp->right);
    }
}

node * proc_e(char input[],int &ssm)
{
    node *a,*b;

    a=proc_t(input,ssm);

    while(input[ssm]=='+')
    {
        ssm++;
        b=proc_t(input,ssm);

        node *temp;
        temp=new node; 
        temp->info='+';
        temp->left=a;
        temp->right=b;

        a=temp;

    }

    return a;
}

node * proc_t(char input[],int &ssm)
{
    node *a,*b;

    a=proc_v(input,ssm);
    ssm = ssm + 1;

    while(input[ssm] == '*')
    {
        ssm++;
        b=proc_v(input,ssm);
        node *temp;
        temp=new node;//(node *)malloc(sizeof(node));
        temp->info='*';
        temp->left=a;
        temp->right=b;
        a=temp;
        ssm = ssm +1;
    }
    return a;
}

node * proc_v(char input[],int &ssm)
{
    node *a;

    if(input[ssm]=='I')
    {
        node *temp;
        temp=new node; 
        temp->info='I';
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else
    {
        cout<<endl<<"ERROR. INVALID SYMBOL "<<input[ssm];
        getch();
        exit(0);
    }
}