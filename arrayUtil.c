#include <stdio.h>
#include "arrayUtil.h"	

int areEqual(ArrayUtil a, ArrayUtil b){
	int i,j=0;
	if (a.length==b.length && a.typeSize==b.typeSize){	
		for (i = 0; i < a.length; i++){
			if(((int *)a.base)[i]!=((int *)b.base)[i]){
				j=1;
				break;
			}
		}
	if(j==0) return 1;
	}
	return 0;
}