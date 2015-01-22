typedef struct arrayUtil ArrayUtil;
typedef char * base_ptr;
typedef void * void_ptr;
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