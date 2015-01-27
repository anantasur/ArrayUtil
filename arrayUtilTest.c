#define SIZEOF_INT sizeof(int)
#define SIZEOF_FLOAT sizeof(float)
#define SIZEOF_CHAR sizeof(char)
#define SIZEOF_DOUBLE sizeof(double)
#define CHAR_SIZE sizeof(char)
#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)

#define log(test_description) int log = (printf("\t     %s\n\n", test_description))
#define sizeOf_char sizeof(char)
#define sizeOf_float sizeof(float)
#define sizeOf_double sizeof(double)
#define sizeOf_String sizeof(String)
#define sizeOf_Student sizeof(Student)
#define sizeOf_int10 sizeof(int10)
#define sizeOf_float5 sizeof(float5)
#define sizeOf_void_star sizeof(void_star)
#define sizeOf_char_star sizeof(char_star)
#define sizeOf_int_star sizeof(int_star)
#define sizeOf_float_star sizeof(float_star)

#include "arrayUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr_assert.h"

typedef int int10[10];
typedef float float5[5];
typedef struct Stud { char name[27]; int std; float percentage; } Student;

int array_1[1] = {1};
int array_1_2[2] = {1, 2};
int array_1_3[2] = {1, 3};
int array_0_0[2] = {0, 0};
int array_1_0[2] = {1, 0};
char array_null_null[2] = {'\0', '\0'};
float array_flt_flt[2] = {0, 0};
double array_dble_dble[2] = {0, 0};
String array_empty_strings[2] = {"", ""};
void_star array_void_stars[1] = {0x0};
char_star array_char_stars[1] = {(char *)('\0')};
int_star array_int_stars[1] = {(int *)(0)};

int10 array_int10_0s[1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
float5 array_float5_0s[1] = {{0.0, 0.0, 0.0, 0.0, 0.0}};
Student array_Students[1] = {{"", 0, 0.0}};



ArrayUtil utils[3],util,newUtil, resultUtil, expectedUtil,util1,util2;
int sample[] = {1,2,3,4,5};

typedef struct Student{
    int rollno;
    float age;
} student;


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

void test_resize_add_0_to_the_new_places_created_in_integer_array(){
	int array[] = {1,2,3}, arr[] = {1,2,3,0,0};
	ArrayUtil array2, util1 = {array, SIZEOF_INT, 3};
	ArrayUtil expected = {arr, SIZEOF_INT ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}

void test_resize_sets_new_elements_to_zero_in_double(){
	double expectedArray[] = {1.0,0.0};
	ArrayUtil b = {expectedArray,sizeof(double),2};
	util = create(sizeof(double),1);
	((double*)util.base)[0] = 1.0;
	newUtil = resize(util, 2);
	assert(areEqual(b, newUtil));
}

void test_to_change_the_length_of_float_array_to_greater_length(){
	int newLength = 5;
	float *num;
	float number[] = {1.0,0.2,3.0,0,0};
	ArrayUtil a1 = create(sizeof(float),3);
	ArrayUtil a3;
	ArrayUtil expected = {number,sizeof(float), 5};
	num = a1.base;
	num[0]=1.0;
	num[1]=0.2,num[2]=3.0;
	a3 = resize(a1, newLength);
	assert(areEqual(expected,a3));
}

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

int isUpperCase(void* a,void *b){
	return (*((char*)b) >= 'A' && *((char*)b) <= 'Z') ? 1 : 0;	
}


void test_findFirst_returns_the_first_element_if_there_is_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','C','D','e'},sizeof(char),5};
	int x = 'S';
	assertEqual(*((char*)findFirst(a,isUpperCase,&x)),'C');
}

int isDivisible(void* hint, void* item){
	int* _hint = (int*)hint;
	int* _item = (int*)item;
	// printf("%d %d ---- %d\n",*_item,*_hint,(*_item % *_hint) == 0 ? 1 : 0);
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

void test_to_get_count_even_elements_from_the_array(){
	int array[6] = {3,5,6,7,8,9};
	int x;
	int result;
	util = create(sizeof(int),6);
	util.base = array;
	result = count(util,&isEven,&x);
	assertEqual(result,2);
}

void test_to_get_count_of_elements_from_the_array_which_is_divisible_by_3(){
	int array[6] = {10,2,15,4,5,6};
	int x = 5;
	int result;
	util = create(sizeof(int),6);
	util.base = array;
	result = count(util,&isDivisible,&x);
	assertEqual(result,3);
}

void intAddOperation(void* hint, void* item) {
	*((int *)item) = *((int *)hint) + *((int *)item);	
}
void intConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*((int *)destinationItem) = *((int *)hint) + *((int *)sourceItem);
}

void charConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*((char*)destinationItem) = *((char*)sourceItem) - 32;
}



void test_create_returns_same_array_if_array_lengths_are_same_and_values_are_same() {
	ArrayUtil a,b;
	int expected = 1,actual;
	a = create(sizeof(int),2);
	b = create(sizeof(int),2);
	assert(areEqual(a,b) == 1);
}

// void test_findLast_returns_null_if_there_is_no_match_in_integer_array(){
// 	ArrayUtil a = {(int[]){1,3,5,7,9},sizeof(int),5};
// 	int x = 2;
// 	assertEqual(findLast(a,isEven,&x),NULL);
// }

void test_findLast_returns_the_last_element_if_there_is_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','C','D','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(*((char*)findLast(a,isUpperCase,&x)),'D');
}

void test_findLast_returns_the_last_element_if_there_is_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,8,10},sizeof(int),5};
	int x = 2;
	assertEqual(*((int*)findLast(a,isEven,&x)),10);
}

void test_that_function_creates_new_array_or_not(){
	ArrayUtil array = create(sizeof(int),3);
	int *createArray  = (int*)array.base;
	assertEqual(createArray[0], 0);
	assertEqual(createArray[2], 0);
	assertEqual(array.length, 3);
	assertEqual(array.typeSize, 4);
}

int isCapital(void *hint, void *item) {
    return((*(char *)item >=65) && (*(char *)item <= 91));
}

int isGreaterThan5(void *hint, void *item) {
    return(*(float *)item > 5);
}

void test_areEqual_returns_0_if_typeSize_of_two_arrays_are_not_equal(){
    int array1[] = {1,2,3,4};
    char array2[] = {'m','a','h','e'};
    ArrayUtil util1 = {array1,sizeof(int),4};
    ArrayUtil util2 = {array2,sizeof(char),4};
    assertEqual(areEqual(util1, util2), 0);
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_capital(){
    char array1[] = {'k','M','k'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual(*(char *)(findFirst(util1,&isCapital,0)), 'M');
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_even(){
    int array1[] = {1,2,3,4,5};
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(*(int *)(findFirst(util1,&isEven, 0)), 2);
}

void test_findFirst_returns_the_adsdress_of_first_element_in_the_array_greater_than_5() {
    float array1[] = {1.1,6.6,5.5,8.8,2.2};
    ArrayUtil util1 ={array1, sizeof(float),5};
    assertEqual(*(float *)(findFirst(util1,&isGreaterThan5,0)), (float)6.6);
}

void test_findIndex_returns_index_of_the_String_element_where_it_presents(){
    String array1[] = {"Mahesh","Kumar","Kolla"};
    String element = "Kumar";
    ArrayUtil util1 = {array1,sizeof(String),3};
    assertEqual(findIndex(util1,&element), 1);
}

void test_findIndex_returns_index_of_the_char_element_where_it_presents(){
    char array1[] = {'m','a','h','e','s','h'};
    char element = 's';
    ArrayUtil util1 = {array1,sizeof(char),6};
    assertEqual(findIndex(util1,&element), 4);
}

void test_findIndex_returns_index_of_the_integer_element_where_it_presents(){
    int array1[] = {1,2,3,4,5};
    int element = 2;
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(findIndex(util1,&element), 1);
}

void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_putting_0s_in_new_created_spaces(){
    String array1[] = {"Mahesh","Kumar"}, array2[] = {"Mahesh","Kumar",0,0,0};
    ArrayUtil util1 = {array1,sizeof(char *),2};
    ArrayUtil util2 = {array2,sizeof(char *),5};
    assertEqual(areEqual(resize(util1, 5), util2), 1);    
}
void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_removing_extra_values(){
    String array1[] = {"Mahesh","Kumar","Kolla"}, array2[] = {"Mahesh","Kumar"};
    ArrayUtil util1 = {array1,sizeof(char *),3};
    ArrayUtil util2 = {array2,sizeof(char *),2};
    assertEqual(areEqual(resize(util1, 2), util2), 1);    
}

//-------------------------------------------------------------------------------------------

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_double(){
	double a [] = {2.34};
	double b [] = {2.34};
	ArrayUtil array1 = {a, sizeof(double), 1};
	ArrayUtil array2 = {b, sizeof(double), 1};

	assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_string(){
	String a [] = {"hello"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};

	assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_not_be_equal_String(){
	String a [] = {"hallo"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};

	assertEqual(areEqual(array1,array2),0);
};

int compare(void *hint,void* item){
	if(*(char*)item=='a')
		return 1;
	return 0;
};

int isEqual(void* hint, void* item){
	if(*(int*)item==8 ||*(float*)item == 9.0 || *(double*)item==8.9)
		return 1;
	return 0;
}

int stringCompare(void *hint, void* item){
	_String str ="hello";
	_String getItem = *(_String*)item;
	if(getItem==str)
		return 1;
	return 0;
}

//----------------------------------------------------------------------------------------

void test_areEqual_returns_1_if_two_int_array_are_equal(){
	int array1[] = {1,2,3};
	int array2[] = {1,2,3};
	ArrayUtil a1 = create(4,3);
	ArrayUtil a2 = create(4,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_int_array_are_not_equal(){
	int array1[] = {1,2,4};
	int array2[] = {1,2,3};
	ArrayUtil a1 = create(4,3);
	ArrayUtil a2 = create(4,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_1_if_two_char_array_are_equal(){
	char array1[] = {'a','b','c'};
	char array2[] = {'a','b','c'};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_char_array_are_not_equal(){
	char array1[] = {'a','a','c'};
	char array2[] = {'a','b','c'};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_1_if_two_float_array_are_equal(){
	float array1[] = {1.0,0.2,3.4};
	float array2[] = {1.0,0.2,3.4};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_float_array_are_not_equal(){
	float array1[] = {1.0,1.2,3.4};
	float array2[] = {1.0,0.2,3.4};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_create_creates_an_int_array_initializes_with_0(){
	int typeSize = 4,length = 3;
	int arrOf0[3] = {0,0,0};
	ArrayUtil array = create(typeSize,length);
	ArrayUtil array1;
    array1.base = arrOf0;
    array1.typeSize = 4;
    array1.length = 3;
	assertEqual(areEqual(array, array1),1);
}

void test_create_creates_char_array_initializes_with_0(){
	int typeSize = 1,length = 4;
	char arrOf0[4] = {0,0,0,0};
	ArrayUtil array = create(typeSize,length);
	ArrayUtil array1;
	array1.base = arrOf0;
	array1.typeSize = 1;
	array1.length = 4;
	assertEqual(areEqual(array, array1),1);
}

void test_to_create_int_with_array_diffferent_typeSize_initializes_with_0(){
	int typeSize = 3,length = 4,*result;
	ArrayUtil array = create(typeSize,length);
    result=(int*)array.base;
	assertEqual(*result,0);
	assertEqual(*(result+1),0);
	assertEqual(*(result+2),0);
	assertEqual(array.typeSize,3);
}	

void test_to_change_the_length_of_int_array_to_greater_length(){
	int newLength = 5,*num;
	int number[] = {1,2,3,0,0};
	ArrayUtil a1 = create(SIZEOF_INT,3);
	ArrayUtil a3;
	ArrayUtil expected = {number,sizeof(int), 5};
	num = a1.base;
	num[0]=1;num[1]=2,num[2]=3;
	a3 = resize(a1, newLength);
	assert(areEqual(expected,a3));
}

void test_to_change_the_length_of_array_to_small_array_length(){
	int newLength = 3,*num;
	int number[] = {1,2,3};
	ArrayUtil a1 = create(SIZEOF_INT,5);
	ArrayUtil a3;
	ArrayUtil expected = {number,sizeof(int), 3};
	num = a1.base;
	num[0]=1;num[1]=2,num[2]=3,num[3]=4,num[4]=5;
	a3 = resize(a1, newLength);
	assert(areEqual(expected,a3));
}

void increment(void* hint, void* sourceItem, void* destinationItem){
	int *hintPtr = (int*)hint;
	int *numberPtr = (int*)sourceItem;
	int *resultPtr = (int*)destinationItem;

	*resultPtr = *numberPtr + *hintPtr;
}

void toChar(void* hint, void* sourceItem, void* destinationItem){
	int *numberPtr = (int*)sourceItem;
	int *charPtr = (int*)destinationItem;
	*charPtr = *numberPtr;
}

void test_create_should_set_the_length_and_typeSize_fields_of_array_to_the_values_passed_to_create_function(){
	ArrayUtil a = create(1,3);
	assert(a.length == 3);
	assert(a.typeSize == 1);
	dispose(a);
}

void test_resize_should_grow_length_of_array_and_set_them_to_zero_when_new_size_is_more(){
	ArrayUtil a = create(4,2);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	for (i = 0; i < 20; ++i)
	{
		assert(((char*)a.base)[i] == 0);
	}
	dispose(a);
}
void test_resize_should_not_change_length_of_array_when_new_size_is_same_as_old_size(){
	ArrayUtil a = create(1,5);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	dispose(a);
}


//------------------------jp-----------------------------------------------

void test_array_util_areEqual_returns_0_if_both_array_are_not_equal_in_length_and_elements(){
	int a[]={0,3,8,5,2,3,4,5}, b[]={1,5,2,3,7};
	ArrayUtil a_array = {a,sizeof(int),8};
	ArrayUtil b_array = {b,sizeof(int),5};
	assertEqual(areEqual(a_array, b_array),0);
}
void test_create_allocates_space_for_DOUBLE_array_and_assigns_zero_to_all_bytes(){
	double doubleArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){doubleArray,sizeof(double),4};
	util = create(sizeof(double),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}

void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o'},sizeof(char),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(char []){'a','e','i','o',0,0},sizeof(char),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o','u'},sizeof(char),5};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(char []){'a','e'},sizeof(char),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89,0,0},sizeof(double),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111},sizeof(double),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_FLOAT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89},sizeof(float),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89,0,0},sizeof(float),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_INT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(int []){1,2,3,4},sizeof(int),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(int []){1,2,3,4,0,0},sizeof(int),6}; 
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

//------------------------------------vikas-pal----------------------------------------

int isLessThanTheHints(void* hint,void* element){
    return (*(float*)element) < (*(float*)hint);

}
void test_findIndex_retruns_the_index_of_an_element_in_an_string_array(){
    char array[]= {"heloo"};
    char element ='o';
    ArrayUtil util = {array,sizeof(char),4};
    assertEqual(findIndex(util,&element),3);
};
void test_for_the_ArrayUtil_for_charecter_and_int_are_not_equal(){
    char first_array[]={'c','d','e','f'};
    int second_array[]={2,5,8,4};
    ArrayUtil array1 = {first_array,sizeof(char),4};
    ArrayUtil array2 = {second_array,sizeof(int),4};
	assertEqual(areEqual(array1, array2),0);
};
void test_resize_an_existing_array_to_resize_decrease_its_length(){
    int *resArray;
    ArrayUtil array,resizeArray;
    array = create(sizeof(int),5);
    ((int*)array.base)[0]=90;
    ((int*)array.base)[1]=40;
    ((int*)array.base)[2]=550;
    ((int*)array.base)[3]=550;
    ((int*)array.base)[4]=40;
    resizeArray=resize(array,4);
    resArray = resizeArray.base;
    assertEqual(resArray[2],550);
    assertEqual(areEqual(resizeArray,array),0);
};


void test_resize_an_existing_array_to_resize_increase_its_length(){
    ArrayUtil array = create(sizeof(int),3),resultArray;
    ((int*)array.base)[0]=90;
    ((int*)array.base)[1]=40;
    ((int*)array.base)[2]=550;
    resultArray = resize(array,5);
    assertEqual(((int *)resultArray.base)[0],90);
    assertEqual(((int *)resultArray.base)[1],40);
    assertEqual(((int *)resultArray.base)[2],550);
    assertEqual(((int *)resultArray.base)[3],0);
    assertEqual(((int *)resultArray.base)[4],0);
};

void test_for_findLast_gives_the_last_element_of_less_than_float_value_an_array(){
    float hint = 6.3;
    float *result;
    MatchFunc *match = &isLessThanTheHints;
    ArrayUtil util = {(float[]){2.3,4.5,6.3,4.5,6.0},sizeof(float),5};
    result = findFirst(util,match,&hint);
    assertEqual(*result,(float)2.3);
};

//------------------------------cyberfrog-------------------------------------------

void test_create_Structures_with_all_fields_NULL(){
    student temp = {0,0.0};
    student Student[1] = {temp};
    ArrayUtil expected = {Student,sizeof(student),1};
   util1 = create(sizeof(student),1);    
    assert(areEqual(expected,util1));
};

//-----------------------------------krati------------------------------------------

int isGreaterThanHint (void* hint, void* element) {
	printf("%d\n", (*((float*)element) > *((float*)hint)) ? 1 : 0);
	return (*((float*)element) > *((float*)hint)) ? 1 : 0;
}

void test_Create_creates_new_array_of_float_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(float[]){0,0},FLOAT_SIZE,2};
	ArrayUtil newUtil = create(FLOAT_SIZE, 2);
	assertEqual(areEqual(expectedUtil,newUtil ), 1);
	dispose(newUtil);
}
void test_Create_creates_new_charArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(char[]){0,0,0},CHAR_SIZE,3};
	ArrayUtil newUtil =create(CHAR_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
dispose(newUtil);
}

void test_Create_creates_new_intArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(int[]){0,0,0},INT_SIZE,3};
	ArrayUtil newUtil =create(INT_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}

void test_Create_creates_new_floatArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil util = {(float[]){0,0},FLOAT_SIZE,2};
	ArrayUtil newUtil =create(FLOAT_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}
void test_findFirst_gives_occurence_of_first_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	MatchFunc *match = &isGreaterThanHint;
	
	ArrayUtil util = {(float[]){3.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,(float)8.3);
}
void test_findLast_gives_occurence_of_last_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){7.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findLast(util,match,(void*)&hint);
	assertEqual(*result,(float)8.3);
}

//-----------------------------------------------------------------------------------

void test_findIndex_will_return_the_minus_1_if_array_element_is_not_present(){
	int array[]={1,2,3,4,5};
	int x=7;
	ArrayUtil arr={array,sizeof(int),5};
	assertEqual(findIndex(arr,&x),-1);
}

void test_resize_should_contain_the_initial_array_element(){
	int src[]={5,3},i;
	ArrayUtil util={src,sizeof(int),4},array;
	int* base;
	array = resize(util,15);
	base = (int *)(array.base);
	assertEqual(base[0], 5);
	assertEqual(base[1], 3);
	assertEqual(base[14], 0);

	free(array.base);
};

void test_areEqual_returns_0_when_length_is_equal_but_typeSize_is_not_equal(){
	int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}
//-------------------------------------------------------------------------

void test_create_001(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int");
	ArrayUtil util1 = {array_0_0, sizeOf_int, 2};
	ArrayUtil util2 = create(sizeOf_int, 2);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_002(){
	log("returns an ArrayUtil with bytes initialized to NULL for char");
	ArrayUtil util1 = {array_null_null, sizeOf_char, 2};
	ArrayUtil util2 = create(sizeOf_char, 2);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_003(){
	log("returns an ArrayUtil with bytes initialized to ZERO for float");
	ArrayUtil util1 = {array_flt_flt, sizeOf_float, 2};
	ArrayUtil util2 = create(sizeOf_float, 2);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_004(){
	log("returns an ArrayUtil with bytes initialized to ZERO for double");
	ArrayUtil util1 = {array_dble_dble, sizeOf_double, 2};
	ArrayUtil util2 = create(sizeOf_double, 2);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_005(){
	log("returns an ArrayUtil with bytes initialized to ZERO for char[256]");
	ArrayUtil util1 = {array_empty_strings, sizeOf_String, 2};
	ArrayUtil util2 = create(sizeOf_String, 2);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_006(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int[10]");
	ArrayUtil util1 = {array_int10_0s, sizeOf_int10, 1};
	ArrayUtil util2 = create(sizeOf_int10, 1);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_007(){
	log("returns an ArrayUtil with bytes initialized to ZERO for float[5]");
	ArrayUtil util1 = {array_float5_0s, sizeOf_float5, 1};
	ArrayUtil util2 = create(sizeOf_float5, 1);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_008(){
	log("returns an ArrayUtil with bytes initialized to ZERO for struct");
	ArrayUtil util1 = {array_Students, sizeOf_Student, 1};
	ArrayUtil util2 = create(sizeOf_Student, 1);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_009(){
	log("returns an ArrayUtil with bytes initialized to ZERO for void *");
	ArrayUtil util1 = {array_void_stars, sizeOf_void_star, 1};
	ArrayUtil util2 = create(sizeOf_void_star, 1);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_010(){
	log("returns an ArrayUtil with bytes initialized to ZERO for char *");
	ArrayUtil util1 = {array_char_stars, sizeOf_char_star, 1};
	ArrayUtil util2 = create(sizeOf_char_star, 1);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}
void test_create_011(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int *");
	ArrayUtil util1 = {array_int_stars, sizeOf_int_star, 1};
	ArrayUtil util2 = create(sizeOf_int_star, 1);
	assertEqual(areEqual(util1, util2), 1);
	dispose(util2);
}

void test_filter_gives_D_E_for_a_b_c_D_E() {
	ArrayUtil a = {(char[]){'a','b','c','D','E'},sizeof(char),5};
	char *result,hint = 'a',*lIst;
	void* list;
	int count;
	list = malloc(5*sizeof(char));
	count =  filter(a,isUpperCase,&hint,&list,2);
	lIst = (char*)list;
	assert(count==2);
	assertEqual(lIst[0],'D');
	assertEqual(lIst[1],'E');
}

void test_filter_populate_destination_array_with_evenNumbers(){
    int maxItem=6;
    int *evens[maxItem];
    util1 = (ArrayUtil){(int[]){101,22,12,13},sizeof(int),4};
   	 
	 assertEqual(filter(util1,isEven,0,(void**)evens,maxItem),2);
	 assertEqual(*(evens[0]),22);
	 assertEqual(*(evens[1]),12);
}

void test_filter_populate_destination_array_until_hits_max_size_and_return_no_element_added_to_id(){
    int maxItem=2;
    int *evens [maxItem];
    util1 = (ArrayUtil){(int[]){101,22,12,14},sizeof(int),4};   	 

	 assertEqual(filter(util1,isEven,0,(void**)evens,maxItem),2);
	 assertEqual(*(evens[0]),22);
	 assertEqual(*(evens[1]),12);    
}

void multiplyBy(void* hint, void* sourceItem, void* destinationItem){
    *(int*)destinationItem = *(int*)sourceItem * *(int*)(hint);
}

void test_map_converts_each_element_source_array_and_put_it_to_destination_array(){
    int hint =10;
    ArrayUtil expected={(int[]){10,20,30,40,50},sizeof(int),5};
    util1=(ArrayUtil){(int[]){1,2,3,4,5},sizeof(int),5};
    util2 =create(sizeof(int),5);
    
    map(util1,util2,multiplyBy,&hint);
    assert(areEqual(expected, util2));
}

void test_map_gives_2_3_4_5_6_for_1_2_3_4_5_for_integer_array(){
	ArrayUtil src = {(int[]){1,2,3,4,5},sizeof(int),5},dest = create(sizeof(int),5);
	ArrayUtil tmp = {(int[]){2,3,4,5,6},sizeof(int),5};
	int hint = 1;
	map(src,dest,intConvertFunc,&hint);
	assert(areEqual(dest,tmp)==1);
	dispose(dest);
}

void test_map_gives_A_B_C_D_E_for_a_b_c_d_e_for_character_array(){
	ArrayUtil src = {(char[]){'a','b','c','d','e'},sizeof(char),5},dest = create(sizeof(char),5);
	ArrayUtil tmp = {(char[]){'A','B','C','D','E'},sizeof(char),5};
	char hint = 32;
	map(src,dest,charConvertFunc,&hint);
	assertEqual(areEqual(dest,tmp),1);
	dispose(dest);
}

void test_forEach_gives_2_3_4_5_6_for_1_2_3_4_5_in_same_array(){
	ArrayUtil src = create(sizeof(int),5);
	int *arr,i,hint = 1,*list;
	arr = (int*)src.base;
	for(i=0;i<5;i++){
		arr[i] = i+1;
	}
	list = ((int*)src.base);
	forEach(src,intAddOperation,&hint);
	assertEqual(list[0],2);
	assertEqual(list[1],3);
	assertEqual(list[2],4);
	assertEqual(list[3],5);
	assertEqual(list[4],6);
	dispose(src);
}

void element_into_element_plus_one(void* hint, void* item){
	*((int *)item)= *((int *)item) * ((*((int *)item))+1);
}


void test_forEach_does_multiplication_of_item_with_item_plus_one(){
	void *hint;
	int array[]={1,2,3,4,5};
	int incremented[]={2,6,12,20,30};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={incremented,INT_SIZE,5};
	forEach(util,element_into_element_plus_one,&hint);
	assert(areEqual(util,expected));
}

void *add_all(void* hint, void* previousItem, void* item){
	*((int*)item)= *((int*)previousItem) + *((int*)item);
	return ((int*)item);
}


void test_reduce_gives_15_when_elements_are_1_2_3_4_5_and_initial_value_is_0(){
	void *hint;
	int intialValue=0;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),15);
}

void test_reduce_gives_30_when_elements_are_1_2_3_4_5_and_initial_value_is_15(){
	void *hint;
	int intialValue=15;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),30);
}

void* sum (void* hint, void* pv, void* cv){
	int* _pv = (int*)pv;
	int* _cv = (int*)cv;
	int* result = (int*)malloc(INT_SIZE); 
	*result = *_pv + *_cv;
	return result;
}

void test_reduce_returns_sum_of_all_integers_of_array (){
	int hint = 2,result;
	int initial_value = 0;
	int array[] = {1,2,3};
	void* (*fn_ptr)(void*,void*,void*) = &sum;
	ArrayUtil util = create(INT_SIZE,3);
	util.base = (void*)array;
	result = *(int*)reduce(util,fn_ptr,(void*)&hint,(void*)&initial_value);
	assertEqual(result,6);
}
