#include "global.h"

BufferManagerMatrix::BufferManagerMatrix()
{
    logger.log("BufferManagerMatrix::BufferManagerMatrix");
}

/**
 * @brief Function called to read a page from the buffer manager. If the page is
 * not present in the pool, the page is read and then inserted into the pool.
 *
 * @param MatrixName 
 * @param pageIndex 
 * @return PageMatrix 
 */
PageMatrix BufferManagerMatrix::getPage(string MatrixName, int bi,int bj)
{
    logger.log("BufferManagerMatrix::getPage");
    string pageName = "../data/temp/"+MatrixName + "_Page" + to_string(bi) + "_" + to_string(bj);
    if (this->inPool(pageName))
        return this->getFromPool(pageName);
    else
        return this->insertIntoPool(MatrixName, bi,bj);
}

/**
 * @brief Checks to see if a page exists in the pool
 *
 * @param pageName 
 * @return true 
 * @return false 
 */
bool BufferManagerMatrix::inPool(string pageName)
{
    logger.log("BufferManagerMatrix::inPool");
    for (auto page : this->pages)
    {
        if (pageName == page.pageName)
            return true;
    }
    return false;
}

/**
 * @brief If the page is present in the pool, then this function returns the
 * page. Note that this function will fail if the page is not present in the
 * pool.
 *
 * @param pageName 
 * @return PageMatrix 
 */
PageMatrix BufferManagerMatrix::getFromPool(string pageName)
{
    //cout<<"HEllo"<<endl;
    logger.log("BufferManagerMatrix::getFromPool");
    for (auto page : this->pages)
        if (pageName == page.pageName)
            return page;
}

/**
 * @brief Inserts page indicated by MatrixName and pageIndex into pool. If the
 * pool is full, the pool ejects the oldest inserted page from the pool and adds
 * the current page at the end. It naturally follows a queue data structure. 
 *
 * @param MatrixName 
 * @param bi
 * @param bj
 * @return PageMatrix 
 */
PageMatrix BufferManagerMatrix::insertIntoPool(string MatrixName, int bi,int bj)
{
    logger.log("BufferManagerMatrix::insertIntoPool");
    PageMatrix page(MatrixName, bi,bj);
    if (this->pages.size() >= BLOCK_COUNT)
        pages.pop_front();
    pages.push_back(page);
    return page;
}

/**
 * @brief The buffer manager is also responsible for writing pages. This is
 * called when new tables are created using assignment statements.
 *
 * @param MatrixName 
 * @param pageIndex 
 * @param rows 
 * @param rowCount 
 */
void BufferManagerMatrix::writePage(string MatrixName, int bi, int bj, vector<vector<int>> rows, int rowCount,int colCount)
{
    logger.log("BufferManagerMatrix::writePage");
    PageMatrix page(MatrixName, bi,bj, rows, rowCount,colCount);
    page.writePage();
    //cout<<"done"<<endl;
}

void BufferManagerMatrix::clearPool()
{
    logger.log("BufferManagerMatrix::clearPool");
    pages.clear();
    //cout<<"done"<<endl;
}

/**
 * @brief Deletes file names fileName
 *
 * @param fileName 
 */
void BufferManagerMatrix::deleteFile(string fileName)
{
    
    if (remove(fileName.c_str()))
        logger.log("BufferManagerMatrix::deleteFile: Err");
        else logger.log("BufferManagerMatrix::deleteFile: Success");
}

/**
 * @brief Overloaded function that calls deleteFile(fileName) by constructing
 * the fileName from the MatrixName and pageIndex.
 *
 * @param MatrixName 
 * @param pageIndex 
 */
void BufferManagerMatrix::deleteFile(string MatrixName, int bi, int bj)
{
    logger.log("BufferManagerMatrix::deleteFile");
    string fileName = "../data/temp/"+MatrixName + "_Page" + to_string(bi) + "_" + to_string(bj);
    this->deleteFile(fileName);
}