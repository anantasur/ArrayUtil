#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"	

int areEqual(ArrayUtil a, ArrayUtil b){
	int i;
	base_ptr a_base = a.base, b_base = b.base;
	if(a.length != b.length||a.typeSize != b.typeSize){
		return 0;
	}
	for(i = 0;i < (a.length*a.typeSize);i++){
		if(a_base[i] != b_base[i]){
			return 0;
		}
	}
	return 1;	
}

ArrayUtil create(int typeSize, int length){
	void_ptr  array = calloc(length,typeSize);
	ArrayUtil util;
	util.length = length;
	util.typeSize = typeSize;
	util.base = array;
	return util;
}

ArrayUtil resize(ArrayUtil util,int length) {
	int i,len;
	ArrayUtil newUtil = create( util.typeSize, length);
	if(util.length == length) return util;
	len = (length>util.length) ? util.length : length;
	for(i=0;i<len*util.typeSize;i++) {
		((base_ptr)newUtil.base)[i] = ((base_ptr)util.base)[i];
	}
	return newUtil;
}

int findIndex(ArrayUtil util, void* element){
	int i,count=0;
	char ele = *((char *)element);
	for(i=0;i<util.length*util.typeSize;i=i+util.typeSize){
		if(((char *)util.base)[i]==ele){
			return count;
		}
		count++;
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
}

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	int i;
	base_ptr array = (base_ptr)util.base;
	void_ptr element;
	for(i=0;i<util.length;i++){
		element = &(array[i*util.typeSize]);;
		if(match(hint, element))
			return element;
	}
	return NULL;
}

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	int i;
	base_ptr array = (base_ptr)util.base;
	void_ptr element;
	for(i=(util.length-1);i>=0;i--){
		element = &(array[i*util.typeSize]);;
		if(match(hint, element))
			return element;
	}
	return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int i,count=0;
	base_ptr array = (base_ptr)util.base;
	void_ptr element;
	for(i=0;i<util.length;i++){
		element = &(array[i*util.typeSize]);;
		if(match(hint, element))
			count++;
	}
	return count;
}