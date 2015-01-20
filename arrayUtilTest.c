#include "arrayUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include "expr_assert.h"

void test_When_length_of_two_arrays_are_different_are_compared_we_get_0(){
	ArrayUtil a,b;

	a.typeSize=sizeof(int);
	a.length=2;
	
	b.typeSize=sizeof(int);
	b.length=3;

	assertEqual(areEqual(a, b), 0);
}

void test_when_two_arrays_are_compared_with_same_elements_gives_one(){
	int *a1;
	int *a2;
	ArrayUtil a,b;

	a1=(int *)malloc(sizeof(int)*2);
	a1[0]=1;
	a1[1]=2;
	a.base=(a1);
	a.typeSize=sizeof(int);
	a.length=2;
	
	a2=(int *)malloc(sizeof(int)*2);
	a2[0]=1;
	a2[1]=2;
	b.base=(a2);
	b.typeSize=sizeof(int);
	b.length=2;

	assertEqual(areEqual(a, b), 1);
}

void test_when_two_arrays_are_compared_with_different_elements_gives_0(){
	int *a1;
	int *a2;
	ArrayUtil a,b;

	a1=(int *)malloc(sizeof(int)*2);
	a1[0]=1;
	a1[1]=2;
	a.base=((void *)a1);
	a.typeSize=sizeof(int);
	a.length=2;
	
	a2=(int *)malloc(sizeof(int)*2);
	a2[0]=1;
	a2[1]=3;
	b.base=((void *)a2);
	b.typeSize=sizeof(int);
	b.length=2;

	assertEqual(areEqual(a, b), 0);
}

void test_when_two_arrays_of_float_are_compared_with_same_elements_gives_1(){
	float *a1;
	float *a2;
	ArrayUtil a,b;

	a1=(float *)malloc(sizeof(float)*2);
	a1[0]=1;
	a1[1]=2;
	a.base=((void *)a1);
	a.typeSize=sizeof(float);
	a.length=2;
	
	a2=(float *)malloc(sizeof(float)*2);
	a2[0]=1;
	a2[1]=2;
	b.base=((void *)a2);
	b.typeSize=sizeof(float);
	b.length=2;

	assertEqual(areEqual(a, b), 1);
}

void test_when_two_arrays_of_float_are_compared_with_different_elements_gives_0(){
	float *a1;
	float *a2;
	ArrayUtil a,b;

	a1=(float *)malloc(sizeof(float)*2);
	a1[0]=1;
	a1[1]=2;
	a.base=((void *)a1);
	a.typeSize=sizeof(float);
	a.length=2;
	
	a2=(float *)malloc(sizeof(float)*2);
	a2[0]=1;
	a2[1]=3;
	b.base=((void *)a2);
	b.typeSize=sizeof(float);
	b.length=2;

	assertEqual(areEqual(a, b), 0);
}