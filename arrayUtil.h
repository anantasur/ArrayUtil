#define sizeOf_int sizeof(int)

typedef struct arrayUtil ArrayUtil;
typedef char * base_ptr;
typedef void * void_ptr;
typedef char * _String;
typedef char String[256];
typedef void *void_star;
typedef char *char_star;
typedef int *int_star;
typedef float *float_star;

struct arrayUtil{
	void *base;
	int typeSize;
	int length;
};

typedef char* string;

int areEqual(ArrayUtil a, ArrayUtil b);

ArrayUtil create(int typeSize, int length); 

ArrayUtil resize(ArrayUtil util, int length);

int findIndex(ArrayUtil util, void* element);

void dispose(ArrayUtil util);

typedef int (MatchFunc)(void *, void *);

void* findFirst(ArrayUtil util, MatchFunc*, void* hint);

void* findLast(ArrayUtil util, MatchFunc*, void* hint);

int count(ArrayUtil util, MatchFunc* match, void* hint); 

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );

typedef void (ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);

typedef void (OperationFunc)(void* hint, void* item);

void forEach(ArrayUtil util, OperationFunc* operation, void* hint);

typedef void* ReducerFunc(void* hint, void* previousItem, void* item);

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);