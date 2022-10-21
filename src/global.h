#include"executor.h"

extern float BLOCK_SIZE;
extern uint BLOCK_COUNT;
extern long long int PRINT_COUNT;
extern vector<string> tokenizedQuery;
extern ParsedQuery parsedQuery;
extern TableCatalogue tableCatalogue;
extern MatrixCatalogue matrixCatalogue;
extern BufferManager bufferManager;
extern BufferManagerMatrix bufferManagerMatrix;