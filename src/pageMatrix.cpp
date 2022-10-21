#include "global.h"
/**
 * @brief Construct a new Page object. Never used as part of the code
 *
 */
PageMatrix::PageMatrix()
{
    this->pageName = "";
    this->MatrixName = "";
    this->bi = -1;
    this->bj = -1;
    //this->pageIndex = -1;
    this->rowCount = 0;
    this->columnCount = 0;
    this->rows.clear();
}

/**
 * @brief Construct a new Page:: Page object given the table name and page
 * index. When tables are loaded they are broken up into blocks of BLOCK_SIZE
 * and each block is stored in a different file named
 * "<MatrixName>_Page<pageindex>". For example, If the Page being loaded is of
 * table "R" and the pageIndex is 2 then the file name is "R_Page2". The page
 * loads the rows (or tuples) into a vector of rows (where each row is a vector
 * of integers).
 *
 * @param MatrixName 
 * @param bi
 * @param bj
 */
PageMatrix::PageMatrix(string MatrixName, int bi, int bj)
{
    logger.log("Page::Page");
    this->MatrixName = MatrixName;
    this->bi = bi;
    this->bj = bj;
    this->pageName = "../data/temp/" + this->MatrixName + "_Page" + to_string(this->bi) + "_" + to_string(this->bj);
    
    Matrix matrix = *matrixCatalogue.getMatrix(MatrixName);
    
    this->columnCount = matrix.columnsPerBlockCount[this->bi][this->bj]; 
    this->rowCount = matrix.rowsPerBlockCount[this->bi][this->bj];
    //cout<<"Page"<<endl;
    //cout<<matrix.columnsPerBlockCount[this->bi][this->bj]<<" "<<matrix.rowsPerBlockCount[this->bi][this->bj]<<endl;
    uint maxRowCount = matrix.maxRowsPerBlock;
    vector<int> row(columnCount, 0);
    this->rows.assign(rowCount, row);

    ifstream fin(pageName, ios::in);
    
    int number;
    for (uint rowCounter = 0; rowCounter < this->rowCount; rowCounter++)
    {
        for (int columnCounter = 0; columnCounter < columnCount; columnCounter++)
        {
            fin >> number;
            this->rows[rowCounter][columnCounter] = number;
        }
    }
    fin.close();
}

/**
 * @brief Get row from page indexed by rowIndex
 * 
 * @param rowIndex 
 * @return vector<int> 
 */
vector<int> PageMatrix::getRow(int rowIndex)
{
    logger.log("Page::getRow");
    vector<int> result;
    result.clear();
    if (rowIndex >= this->rowCount)
        return result;
    return this->rows[rowIndex];
}

vector<vector<int>> PageMatrix::getallRows()
{
    logger.log("Page::getallRows");
    return this->rows;
}

PageMatrix::PageMatrix(string MatrixName, int bi, int bj, vector<vector<int>> rows, int rowCount,int colCount)
{
    logger.log("PageMatrix::PageMatrix");
    this->MatrixName = MatrixName;
    this->bi = bi;
    this->bj = bj;
    this->rows = rows;
    this->rowCount = rowCount;
    this->columnCount = colCount;
    this->pageName = "../data/temp/" + this->MatrixName + "_Page" + to_string(this->bi) + "_" + to_string(this->bj);

}

/**
 * @brief writes current page contents to file.
 * 
 */
void PageMatrix::writePage()
{
    logger.log("PageMatrix::writePage");
    ofstream fout(this->pageName, ios::trunc);
    //cout<<this->rowCount << " "<<this->columnCount<<endl;
    /*cout<<rows.size()<<endl;
    cout<<rows[0].size()<<endl;*/

    for (int rowCounter = 0; rowCounter < this->rowCount; rowCounter++)
    {
        for (int columnCounter = 0; columnCounter < this->columnCount; columnCounter++)
        {
            if (columnCounter != 0)
                fout << " ";
            fout << this->rows[rowCounter][columnCounter];
        }
        fout << endl;

    }
    fout.close();
    //cout<<"DONE"<<endl;
}
