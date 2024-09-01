#include "str.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 

Str::Str(int leng){ 

	if(leng<0){
		
		cout<<"Error : Length must be greater than zero"<<endl;
		exit(0);
	}
	else{
		len=leng;
		str=new char[len+1];
	}
}

Str::Str(char *neyong){

	if(neyong==NULL){
		
		cout<<"Error : neyong is NULL "<<endl;
		exit(0);
	}	
	else{
		
		len=strlen(neyong);
		str = new char[len+1];
		strcpy(str,neyong);
	}
}

Str::~Str(){
	
	delete[] str;
}

int Str::length(void){

	return len;
}

char* Str::contents(void){

	return str;
}

int Str::compare(class Str& a){

	return strcmp(str,a.contents());
}

int Str::compare(char *a){

	return strcmp(str,a);
}

void Str::operator=(char *a){

	if(a==NULL){

		cout<<"Error : str is NULL)"<<endl;
		exit(0);
	}
	else{
	
		delete[] str;
		len=strlen(a);
		str=new char[len+1];
		strcpy(str,a);
	}
}

void Str::operator=(class Str& a){

	delete[] str;
	len=a.length();
	str=new char[len+1];
	strcpy(str,a.contents());
}
