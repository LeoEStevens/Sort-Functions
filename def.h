#define DEF_H 1
#define CLOCK_START start = clock()
#define CLOCK_STOP stop = clock()
#define TIME (double)(stop - start) / ((1 > CLOCKS_PER_SEC) ? 1 : CLOCKS_PER_SEC)
#define AVERAGE(a,b,c) ((a + b + c) / 3)

static long long int quickMem = 0;
static long long int bubbleMem = 0;
static long long int radixMem = 0;
static long long int heapMem = 0;
static long long int mergeMem = 0;
static long long int baseArrayMem = 0;

