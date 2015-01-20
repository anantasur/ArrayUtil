#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"	

int areEqual(ArrayUtil a, ArrayUtil b){
	int i,j=0;
	if (a.length==b.length && a.typeSize==b.typeSize){	
		for (i = 0; i < a.length*a.typeSize; i++){
			if(((char *)a.base)[i]!=((char *)b.base)[i]){
				j=1;
				break;
			}
		}
	if(j==0) return 1;
	}
	return 0;
}

ArrayUtil create(int typeSize, int length){
	ArrayUtil newArray;
	newArray.typeSize=typeSize;
	newArray.length=length;
	newArray.base=calloc(length,typeSize);
	return newArray;
}

ArrayUtil resize(ArrayUtil util, int length){
	int i;
	ArrayUtil resizedArray;
	resizedArray.typeSize=util.typeSize;
	resizedArray.length=length;
	resizedArray.base=calloc(length, resizedArray.typeSize);
	for(i=0;i<length*resizedArray.typeSize;i++){
		if(i>util.length) ((char *)resizedArray.base)[i]=0; 
		if(i<util.length) ((char *)resizedArray.base)[i]=((char *)util.base)[i];
	}
	free(util.base);
	return resizedArray;
}

int findIndex(ArrayUtil util, void* element){
	int i,count=0;
	int ele = *((char *)element);
	for(i=0;i<util.length*util.typeSize;i=i+util.typeSize){
		if(((char *)util.base)[i]==ele){
			return count;
		}
		count++;
	}
	return -1;
}