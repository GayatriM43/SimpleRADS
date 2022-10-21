#include "global.h"

CursorMatrix::CursorMatrix(string MatrixName, int bi,int bj)
{
    logger.log("Cursor::Cursor");
    this->page = bufferManagerMatrix.getPage(MatrixName, bi, bj);
    this->pagePointer = 0;
    this->MatrixName = MatrixName;
    this->bi= bi;
    this->bj= bj;
    this->restartRowIndex = 0;
}

/**
 * @brief This function reads the next row from the page. The index of the
 * current row read from the page is indicated by the pagePointer(points to row
 * in page the cursor is pointing to).
 *
 * @return vector<int> 
 */
vector<int> CursorMatrix::getNext(int last)
{
    logger.log("Cursor::getNext");
    vector<int> result = this->page.getRow(this->pagePointer);
    //cout<<this->pagePointer<<" "<<this->page.pageName<<"\n";
    if(last == 1)
    {
        this->pagePointer++;
    }
    if(result.empty()){
        matrixCatalogue.getMatrix(this->MatrixName)->getNextPage(this,true);
        if(!this->pagePointer){
            result = this->page.getRow(this->pagePointer);
        }
    }
    matrixCatalogue.getMatrix(this->MatrixName)->getNextPage(this,false);
    return result;
}
/**
 * @brief Function that loads Page indicated by pageIndex. Now the cursor starts
 * reading from the new page.
 *
 * @param pageIndex 
 */
void CursorMatrix::nextPage(int bi,int bj,int restart)
{
    logger.log("Cursor::nextPage");
    this->page = bufferManagerMatrix.getPage(this->MatrixName, bi, bj);
    this->bi = bi;
    this->bj = bj;
    if(restart == 1)
    {
        this -> restartRowIndex = this -> restartRowIndex + 1;
        this->pagePointer = 0;
    }
}