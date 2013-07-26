
#include <cstring> // string.h for some
#include <cctype>
#include "string2.h" // includes <iostream>

String operator+(const String & s1, const String & s2){
	String ret;
	if (ret.len < s1.len + s2.len) {
		delete [] ret.str;
		ret.str = new char [s1.len + s2.len + 1];
		ret.len = s1.len + s2.len;
	}
	strcpy(ret.str, s1.str);
	strcat(ret.str, s2.str);
	return ret;
}

void String::stringup(){
	char * tp = str;
	while(*tp){
		*tp = toupper(*tp);
		tp++;
	}
}

void String::stringlow(){
	char * tp = str;
	while(*tp){
		*tp = tolower(*tp);
		tp++;
	}
}

int String::has(char c) const{
	int ret = 0;
	char * tp = str;
	while(*tp){
		if(*tp == c){
			ret++;
		}
		tp++;
	}
	return ret;
}
