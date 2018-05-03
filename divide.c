#include"head.h"
#include "shell.h"
char* next1(char* p){
	if(*p=='|'||*p=='>'||*p=='<'){
		p++;
		return p;
	}
	while(*p!='|'&&*p!='>'&&*p!='<'&&*p!=0){
		p++;
	}
	return p;
}

void copy1(char* from , char* to){
	if(*from=='|'||*from=='<'||*from=='>'){
		*to = *from;
		return ;
	}
	while(*from!='|'&&*from!='<'&&*from!='>'&&*from!=0){
		*to = *from;
		to++;
		from++;
	}

}

int divide(char* buffer,char* a[ARGC]){
	int i = 0;
	for(int i1 = 0 ; i1 < ARGC ;i1++)a[i1]=0;
	while(*buffer!=0){
		a[i]=(char*)malloc(sizeof(char)*ARGL);
		for(int k = 0 ; k < ARGL ; k++)a[i][k]=0;
		copy1(buffer,a[i]);
		buffer = next1(buffer);
		i++;		
	}
	return i ;
}


/*

   the divide() will didide the command into serveral part;
   for example: cat < file | ps -aux | wc -c will be portioned into 7 part
   cat 
   <
    file 
	|
	ps -aux 
	|
	wc -c
 */  
