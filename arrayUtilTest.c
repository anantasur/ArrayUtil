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
	a1[0]=1.1;
	a1[1]=2.1;
	a.base=((void *)a1);
	a.typeSize=sizeof(float);
	a.length=2;
	
	a2=(float *)malloc(sizeof(float)*2);
	a2[0]=1.1;
	a2[1]=2.1;
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
	a1[0]=1.0;
	a1[1]=2.0;
	a.base=((void *)a1);
	a.typeSize=sizeof(float);
	a.length=2;
	
	a2=(float *)malloc(sizeof(float)*2);
	a2[0]=1.0;
	a2[1]=3.1;
	b.base=((void *)a2);
	b.typeSize=sizeof(float);
	b.length=2;

	assertEqual(areEqual(a, b), 0);
}

void test_to_create_int_array(){
	int size = sizeof(int);
	int length = 3;
	ArrayUtil array = create(size,length);
	int *result;
	result=(int*)array.base;
	assertEqual(result[0],0);
	assertEqual(result[1],0);
	assertEqual(result[2],0);
	assertEqual(sizeof(result),4);
}

void test_to_create_float_array(){
	int size = sizeof(float);
	int length = 3;
	ArrayUtil array = create(size,length);
	int *result;
	result=(int*)array.base;
	assertEqual(result[0],0);
	assertEqual(result[1],0);
	assertEqual(result[2],0);
	assertEqual(sizeof(result),4);
}

void test_to_create_char_array(){
	int size = sizeof(char);
	int length = 3;
	ArrayUtil array = create(size,length);
	int *result;
	result=(int*)array.base;
	assertEqual(result[0],0);
	assertEqual(result[1],0);
	assertEqual(result[2],0);
	assertEqual(sizeof(result),4);
	assertEqual(array.length, 3);
}

void test_when_an_array_is_resized_into_smaller_size_the_array_is_trimmed(){
	int size = sizeof(char);
	int length = 3;
	int *result;
	ArrayUtil resizedArray;
	ArrayUtil array = create(size,length);
	((char *)array.base)[0]=1;
	resizedArray = resize(array, 2);
	result=(int *)resizedArray.base;
	assertEqual(result[0],1);
	assertEqual(result[1],0);
	assertEqual(resizedArray.length, 2);
}

void test_when_an_array_is_resized_into_larger_size_the_array_populated_by_zeros(){
	int size = sizeof(char);
	int length = 3;
	int *result;
	ArrayUtil resizedArray;
	ArrayUtil array = create(size,length);
	((char *)array.base)[0]=1;
	((char *)array.base)[1]=2;
	((char *)array.base)[2]=3;
	resizedArray = resize(array, 4);
	result=(resizedArray.base);
	assertEqual(((char *)result)[0],1);
	assertEqual(((char *)result)[1],2);
	assertEqual(((char *)result)[2],3);
	assertEqual(((char *)result)[3],0);
	assertEqual(resizedArray.length, 4);
}

void test_in_an_array_1_2_3_4_5_indexOf_3_gives_2(){
	int size = sizeof(int);
	int length = 5;
	ArrayUtil array = create(size,length);
	int x=3;
	((int *)array.base)[0]=1;
	((int *)array.base)[1]=2;
	((int *)array.base)[2]=3;
	assertEqual(findIndex(array, &x), 2);
}

void test_in_an_array_1_2_3_4_5_indexOf_7_gives_neg_1(){
	int size = sizeof(int);
	int length = 5;
	ArrayUtil array = create(size,length);
	int x=7;
	((int *)array.base)[0]=1;
	((int *)array.base)[1]=2;
	((int *)array.base)[2]=3;
	assertEqual(findIndex(array, &x), -1);
}