//#include "shell.h"
#include "head.h"
struct  node{
	char* c;
	struct node* left;
	struct node* right;
};

void init(struct node* a){
	memset(a->c,'\0',100);
	a->left=NULL;
	a->right=NULL;
}

int compare(char* a , char* b){
		while(a!=NULL&&b!=NULL){
			if(*a!=*b)return 0;
			a++;
			b++;
		}
		if(a==NULL&&b!=NULL)return 0;
		if(a!=NULL&&b==NULL)return 0;
		return 1;
}

struct node* operate(char** buffer,int left , int right){
	if(left==right){
		struct node* root = (struct node*)malloc(sizeof(struct node));
		root->c=buffer[left];
		root->right=NULL;
		root->left=NULL;
		return root;
	}
	int n = right ;
	while(n>0){
		if(buffer[n][0]=='<'||buffer[n][0]=='>'||buffer[n][0]=='|'){
			break;
		}
		n--;
	}
	struct node* root =(struct node*) malloc(sizeof(struct node));
	root->c=buffer[n];
	root->left=operate(buffer,left,n-1);
	root->right=operate(buffer,n+1,right);
	return root;
}

void deal(struct node* root){
	if(*(root->c)=='|'||*(root->c)=='>'){
		deal(root->left);
		deal(root->right);
		
	}

	else if(*(root->c)=='<'){
		deal(root->right);
		deal(root->right);
	}

	else
	 return excute(root);
	
}

void readnode(struct node* root){
	if(root==NULL)return;
	readnode(root->left);
	printf("%s ",root->c);
	readnode(root->right);
}

