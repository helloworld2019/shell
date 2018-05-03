#include "head.h"

char* next(char* );
int push(char* , char*);
void blank(char* arg){
	char* tep = arg;
	int r = 0 ;
	while(1){
		if(tep[r]=='\n'){
			tep[r]=0;
			break;
		}
		r++;
	}
	char result[100];
	for(int i1 = 0 ; i1 < 100 ; i1++)result[i1]=0;
	char* tep1 = result;
	
	while(*tep==32){
		tep++;
	}

	while(*tep!='\0'){
		int n = push(tep,tep1);
		tep1 = tep1 + n ;
		*tep1=' ';
		tep1++;
		tep = next(tep);
	}	

	tep1--;
	*tep1=0;
	for(int c = 0 ; arg[c]!=0 ; c++)arg[c]=0;
	int k = 0;
	while(result[k]!='\0'){
		arg[k]=result[k];
		k++;
	}
	
}


char* next(char* type){
	while(*type!=32){
		if(*type==0)return type;
		type++;
	}
	while(*type==32){
		if(*type==0)return type;
		type++;
	}
	return type;
}

int push(char* from , char* to){
	int k = 0;
	while( from[k]!=32 && from[k]!='\0' ){
		to[k]=from[k];
		k++;
	}
	return k ;
}
