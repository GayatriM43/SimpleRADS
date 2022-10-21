#include"bufferManagerMatrix.h"
/**
 * @brief The cursor is an important component of the system. To read from a
 * table, you need to initialize a cursor. The cursor reads rows from a page one
 * at a time.
 *
 */
class CursorMatrix{
    public:
    PageMatrix page;
    int pageIndex;
    string MatrixName;
    int pagePointer;
    int bi;
    int bj;
    int restartRowIndex;

    public:
    CursorMatrix(string MatrixName, int bi,int bj);
    vector<int> getNext(int last);
    void nextPage(int bi,int bj, int restart);
};