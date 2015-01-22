#include "arrayUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include "expr_assert.h"

ArrayUtil util,newUtil;

// typedef struct{
// 	char name[3];
// 	int roll;
// 	float percentage;
// } student;

void test_____________________v_1_0__________________________(){}

void test_When_length_of_two_arrays_are_different_are_compared_we_get_0(){
	ArrayUtil a,b;

	a.typeSize=sizeof(int);
	a.length=2;
	
	b.typeSize=sizeof(int);
	b.length=3;

	assertEqual(areEqual(a, b), 0);
}

void test_when_two_arrays_are_compared_with_same_elements_gives_one(){
	int a1[]={1,2}, a2[]={1,2};
	ArrayUtil util1={a1, sizeof(int), 2}, util2={a2, sizeof(int), 2}; 

	assert(areEqual(util1, util2));
}

void test_when_two_arrays_are_compared_with_different_elements_gives_0(){
	int a1[]={1,2}, a2[]={1,3};
	ArrayUtil util1={a1, sizeof(int), 2}, util2={a2, sizeof(int), 2}; 

	assert(!areEqual(util1, util2));
}

void test_when_two_arrays_of_float_are_compared_with_same_elements_gives_1(){
	float a1[]={1.0,2.1}, a2[]={1.0,2.1};
	ArrayUtil util1={a1, sizeof(float), 2}, util2={a2, sizeof(float), 2}; 

	assert(areEqual(util1, util2));
}

void test_when_two_arrays_of_float_are_compared_with_different_elements_gives_0(){
	float a1[]={1.0,2.1}, a2[]={1.0,3.1};
	ArrayUtil util1={a1, sizeof(float), 2}, util2={a2, sizeof(float), 2}; 

	assert(!areEqual(util1, util2));
}

void test_areEqual_returns_1_for_same_string_arrayUtils() {
	ArrayUtil a = {(string[]){"ab","cd"},sizeof(string),2},b = {(string[]){"ab","cd"},sizeof(string),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_1_for_same_double_arrayUtils() {
	ArrayUtil a = {(double[]){1.1,2.2},sizeof(double),2},b = {(double[]){1.1,2.2},sizeof(double),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_0_for_different_double_arrayUtils() {
	ArrayUtil a = {(double[]){1.1,2.2},sizeof(double),2},b = {(double[]){1.1,2.3},sizeof(double),2};
	assertEqual(areEqual(a,b),0);
}

void test_areEqual_returns_0_for_different_string_arrayUtils() {
	ArrayUtil a = {(string[]){"ab","cd"},sizeof(string),2},b = {(string[]){"ab","cD"},sizeof(string),2};
	assertEqual(areEqual(a,b),0);
}

void test_to_create_int_array(){
	int array[]={0,0,0};
	ArrayUtil expected = { (void *)array, sizeof(int), 3};
	ArrayUtil util = create( sizeof(int), 3);

	assert(areEqual(expected, util));
}

// void test_create_Structures_with_all_fields_NULL(){
// 	student temp = {"",0,0.0};
// 	student Student[1] = {temp};
// 	ArrayUtil expected = {Student,sizeof(student),1};
// 	util = create(sizeof(student),1);
// 	assert(areEqual(expected,util));
// }

void test_create_allocates_space_for_INT_array_and_assigns_zero_to_all_bytes(){
	ArrayUtil util = create(sizeof(int),4);
	int intArray[] = {0,0,0,0};
	ArrayUtil expectedUtil;
	expectedUtil.base = intArray;
	expectedUtil.typeSize = sizeof(int);
	expectedUtil.length = 4;

	assertEqual(areEqual(expectedUtil,util),1);
}

void test_to_create_float_array(){
	float array[]={0,0,0};
	ArrayUtil expected = { (void *)array, sizeof(float), 3};
	ArrayUtil util = create( sizeof(float), 3);\

	assert(areEqual(expected, util));
}

void test_to_create_char_array(){
	char array[]={0,0,0};
	ArrayUtil expected = { (void *)array, sizeof(char), 3};
	ArrayUtil util = create( sizeof(char), 3);

	assert(areEqual(expected, util));
}

void test_when_an_array_is_resized_into_smaller_size_the_array_is_trimmed(){
	ArrayUtil util = create( sizeof(char) , 3);
	ArrayUtil resizedUtil = resize(util, 2);
	char array[]={0,0,0};
	ArrayUtil expected = { (void *)array, sizeof(char), 2};

	assert(areEqual(expected, resizedUtil));
}

void test_when_an_array_is_resized_into_larger_size_the_array_populated_by_zeros(){
	ArrayUtil util = create( sizeof(char) , 3);
	ArrayUtil resizedUtil = resize(util, 4);
	char array[]={0,0,0,0};
	ArrayUtil expected = { (void *)array, sizeof(char), 4};

	assert(areEqual(expected, resizedUtil));
}

void test_resize_sets_new_elements_to_zero_in_double(){
	double expectedArray[] = {1.0,0.0};
	ArrayUtil b = {expectedArray,sizeof(double),2};
	util = create(sizeof(double),1);
	((double*)util.base)[0] = 1.0;
	newUtil = resize(util, 2);
	assert(areEqual(b, newUtil));
}

void test_____________________v_1_1___________________________(){}

void test_in_an_array_1_2_3_indexOf_3_gives_2(){
	ArrayUtil util = create( sizeof(int), 3);
	int x=3;
	int* base = (int*)util.base;
	base[0]=1;
	base[1]=2;
	base[2]=3;
	assertEqual(findIndex(util, &x), 2);
}

void test_in_an_array_1_2_3_4_5_indexOf_7_gives_neg_1(){
	ArrayUtil util = create( sizeof(int), 3);
	int x=4;
	int* base = (int*)util.base;
	base[0]=1;
	base[1]=2;
	base[2]=3;
	assertEqual(findIndex(util, &x), -1);
}

// void test_in_an_float_array_1_2_3_indexOf_3_gives_2(){
// 	ArrayUtil util = create( sizeof(float), 3);
// 	float x=3;
// 	float* base = (float*)util.base;
// 	base[0]=1;
// 	base[1]=2;
// 	base[2]=3;
// 	assertEqual(findIndex(util, &x), 2);
// }

// void test_in_an_float_array_1_2_3_4_5_indexOf_7_gives_neg_1(){
// 	ArrayUtil util = create( sizeof(float), 3);
// 	float x=4;
// 	float* base = (float*)util.base;
// 	base[0]=1;
// 	base[1]=2;
// 	base[2]=3;
// 	assertEqual(findIndex(util, &x), -1);
// }

void test_____________________v_1_3___________________________(){}

int isEven(void* hint, void* item){
	int* _item = (int *)item;
	if(*_item%2==0) return 1;
	return 0;
}

void test_to_get_first_even_element_from_the_array(){
	int array[6] = {3,5,6,7,8,9};
	int x;
	int *result;
	util = create(sizeof(int),6);
	util.base = array;
	result = (int*)findFirst(util,&isEven,&x);
	assertEqual(*result,6);
}

int isDivisible(void* hint, void* item){
	int* _hint = (int*)hint;
	int* _item = (int*)item;
	return (*_item % *_hint) == 0 ? 1 : 0;
}

void test_to_get_first_element_from_the_array_which_is_divisible_by_3(){
	int array[6] = {10,2,3,4,5,6};
	int x = 5;
	int *result;
	util = create(sizeof(int),6);
	util.base = array;
	result = (int*)findFirst(util,&isDivisible,&x);
	assertEqual(*result,10);
}

void test_____________________v_1_4___________________________(){}

void test_to_get_Last_even_element_from_the_array(){
	int array[6] = {3,5,6,7,8,9};
	int x;
	int *result;
	util = create(sizeof(int),6);
	util.base = array;
	result = (int*)findLast(util,&isEven,&x);
	assertEqual(*result,8);
}

void test_to_get_Last_element_from_the_array_which_is_divisible_by_3(){
	int array[6] = {1,2,3,4,5,6};
	int x = 2;
	int *result;
	util = create(sizeof(int),6);
	util.base = array;
	result = (int*)findLast(util,&isDivisible,&x);
	assertEqual(*result,6);
}

void test_____________________v_1_5___________________________(){}

