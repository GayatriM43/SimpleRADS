#include "global.h"
#define rowSizeinBlock=2;

/**
 * @brief Construct a new Matrix:: Matrix object
 *
 */
Matrix::Matrix()
{
    logger.log("Matrix::Matrix");
}

/**
 * @brief Construct a new Matrix:: Matrix object used in the case where the data
 * file is available and LOAD command has been called. This command should be
 * followed by calling the load function;
 *
 * @param MatrixName 
 */
Matrix::Matrix(string MatrixName)
{
    logger.log("Matrix::Matrix");
    this->sourceFileName = "../data/" + MatrixName + ".csv";
    this->MatrixName = MatrixName;
}

/**
 * @brief Construct a new Matrix:: Matrix object used when an assignment command
 * is encountered. To create the Matrix object both the Matrix name and the
 * columns the Matrix holds should be specified.
 *
 * @param MatrixName 
 * @param columns 
 */
/*Matrix::Matrix(string MatrixName, vector<string> columns)
{
    logger.log("Matrix::Matrix");
    this->sourceFileName = "../data/temp/" + MatrixName + ".csv";
    this->MatrixName = MatrixName;
    //this->columns = columns;
    this->columnCount = columns.size();
    this->maxRowsPerBlock = (uint)((BLOCK_SIZE * 1000) / (sizeof(int) * columnCount));
    this->writeRow<string>(columns);
}*/

/**
 * @brief The load function is used when the LOAD command is encountered. It
 * reads data from the source file, splits it into blocks and updates Matrix
 * statistics.
 *
 * @return true if the Matrix has been successfully loaded 
 * @return false if an error occurred 
 */
bool Matrix::load()
{
    logger.log("Matrix::load");
    fstream fin(this->sourceFileName, ios::in);
    string line;
    if (getline(fin, line))
    {
        fin.close();
        if (this->getStatistics(line))
            if (this->blockify())
                return true;
    }
    fin.close();
    return false;
}

/**
 * @brief Function extracts column names from the header line of the .csv data
 * file. 
 *
 * @param line 
 * @return true if column names successfully extracted (i.e. no column name
 * repeats)
 * @return false otherwise
 */
bool Matrix::getStatistics(string firstLine)
{
    logger.log("Matrix::extractColumnNames");
    string word;
    stringstream s(firstLine);
    while (getline(s, word, ','))
    {
        this->columnCount++;
    }

    this->maxRowsPerBlock = 32;
    this->maxColPerBlock = 32;
    this->bj_max=ceil((double)columnCount/(double)maxColPerBlock);
    
    return true;
}

/**
 * @brief This function splits all the rows and stores them in multiple files of
 * one block size. 
 *
 * @return true if successfully blockified
 * @return false otherwise
 */
bool Matrix::blockify()
{
    logger.log("Matrix::blockify");
    ifstream fin(this->sourceFileName, ios::in);
    string line, word;
    
    
    int pageCounter = 0;
    unordered_set<int> dummy;
    dummy.clear();

   // int cur_col=0; // Current Column in Entire Matrix
    int cur_row=0; // Current Row in Entire Matrix
    int prev_end=0; // Previous Stored Row
    int i=0; // Current Column in Entire Matrix 
    int columnCounter=0; // Current Column in Current Block
    this->cur_block_i=0; // Block's Row Index
    //cout<<"Iterator"<<bj_max<<endl;
    for(this->cur_block_j=0;this->cur_block_j<this->bj_max;this->cur_block_j++)
    {
        //cout<<"Cur_Block_J"<<cur_block_j<<endl;
        cur_row=0,prev_end=0;
        this->cur_block_i=0;
        ifstream fin(this->sourceFileName, ios::in);
        vector<int> row(this->maxColPerBlock, 0);
        vector<vector<int>> rowsInPage(this->maxRowsPerBlock, row);
        
        while(getline(fin,line))
        {
            //cout<<"WHere are you?"<<endl;
            stringstream s(line);
            //cout<<"Line:"<<line<<endl;
            
            for(i=0;i<(cur_block_j)*this->maxColPerBlock;i++)
                getline(s,word,',');

            for(columnCounter=0;i<(cur_block_j+1)*this->maxColPerBlock && i<this->columnCount;i++,columnCounter++)
            {
                getline(s,word,',');
                row[columnCounter] = stoi(word);
                rowsInPage[cur_row-prev_end][columnCounter] = row[columnCounter];
            }
            cur_row++;
            if (cur_row - prev_end == this->maxRowsPerBlock)    
            {
                this->cur_block_i++;
                //cout<<rowsPerBlockCount.size()<<" "<<cur_block_i<<endl;
                if(rowsPerBlockCount.size()<cur_block_i)
                    this->rowsPerBlockCount.emplace_back(vector<int>(bj_max,0));
                this->rowsPerBlockCount[this->cur_block_i-1][this->cur_block_j]=cur_row-prev_end;
                
                //cout<<columnsPerBlockCount.size()<<" "<<cur_block_i<<endl;
                if(columnsPerBlockCount.size()<cur_block_i)
                    this->columnsPerBlockCount.emplace_back(vector<int>(bj_max,0));
                this->columnsPerBlockCount[this->cur_block_i-1][this->cur_block_j]=columnCounter;
                bufferManagerMatrix.writePage(this->MatrixName, this->cur_block_i-1,this->cur_block_j, rowsInPage, cur_row-prev_end,columnCounter);
                
                prev_end=cur_row;
            }
        }
        this->rowCount=cur_row;
        if (prev_end<this->rowCount)
        {
            this->cur_block_i++;
            
            //cout<<rowsPerBlockCount.size()<<" "<<cur_block_i<<endl;
            if(rowsPerBlockCount.size()<cur_block_i)
                this->rowsPerBlockCount.emplace_back(vector<int>(bj_max,0));
            //cout<<this->rowsPerBlockCount.size()<<" "<<rowsPerBlockCount[0].size()<<" "<<cur_block_j<<endl;
            this->rowsPerBlockCount[this->cur_block_i-1][this->cur_block_j]=cur_row-prev_end;
            
            //cout<<columnsPerBlockCount.size()<<" "<<cur_block_i<<endl;
            if(columnsPerBlockCount.size()<cur_block_i)
                this->columnsPerBlockCount.emplace_back(vector<int>(bj_max,0));
            this->columnsPerBlockCount[this->cur_block_i-1][this->cur_block_j]=columnCounter;

            bufferManagerMatrix.writePage(this->MatrixName, this->cur_block_i-1,this->cur_block_j, rowsInPage, cur_row-prev_end,columnCounter);
            prev_end=cur_row=0;
        }
    }
    this->bi_max=this->cur_block_i;
    

    if (this->rowCount == 0)
        return false;
    return true;
}

/**
 * @brief Given a row of values, this function will update the statistics it
 * stores i.e. it updates the number of rows that are present in the column and
 * the number of distinct values present in each column. These statistics are to
 * be used during optimisation.
 *
 * @param row 
 */
void Matrix::updateStatistics(vector<int> row)
{
    this->rowCount++;
}

/**
 * @brief Checks if the given column is present in this Matrix.
 *
 * @param columnName 
 * @return true 
 * @return false 
 */
// bool Matrix::isColumn(string columnName)
// {
//     logger.log("Matrix::isColumn");
//     for (auto col : this->columns)
//     {
//         if (col == columnName)
//         {
//             return true;
//         }
//     }
//     return false;
// }

/**
 * @brief Renames the column indicated by fromColumnName to toColumnName. It is
 * assumed that checks such as the existence of fromColumnName and the non prior
 * existence of toColumnName are done.
 *
 * @param fromColumnName 
 * @param toColumnName 
 */
// void Matrix::renameColumn(string fromColumnName, string toColumnName)
// {
//     logger.log("Matrix::renameColumn");
//     for (int columnCounter = 0; columnCounter < this->columnCount; columnCounter++)
//     {
//         if (columns[columnCounter] == fromColumnName)
//         {
//             columns[columnCounter] = toColumnName;
//             break;
//         }
//     }
//     return;
// }

/**
 * @brief Function prints the first few rows of the Matrix. If the Matrix contains
 * more rows than PRINT_COUNT, exactly PRINT_COUNT rows are printed, else all
 * the rows are printed.
 *
 */
void Matrix::print()
{
    /*logger.log("Matrix::print");
    int count_rows = min((long long)PRINT_COUNT, this->rowCount);
    int count_cols = min((long long)PRINT_COUNT, this->colCount);
    int col_blocks = -1;
    int row_blocks = -1
    if(count_cols % maxColCount == 0)
    {
        col_blocks = (int)(count_cols/maxColCount);
    }
    else
    {
        col_blocks = (int)(count_cols/maxColCount) + 1; 
    }

    if(count_rows % maxRowCount == 0)
    {
        row_blocks = (int)(count_rows/maxRowCount);
    }

    else
    {
        row_blocks = (int)(count_rows/maxRowCount) + 1; 
    }

    
    vector<int> row;
    
    for (int colCounter = 0; colCounter < col_blocks; colCounter++)
    {
        for (int rowCounter = 0; rowCounter < count; rowCounter++)
        {
            Cursor cursor(this->MatrixName, colCounter,0);
            row = cursor.getNext();
            this->writeRow(row, cout,last);
        }
    }
    printRowCount(this->rowCount);*/
    PageMatrix page = bufferManagerMatrix.getPage(this->MatrixName, 0, 0);
    for(int i=0;i<min(this->rowCount,PRINT_COUNT);i++)
    {
        vector<int> row=page.getRow(i);
        for(int j=0;j<min(this->columnCount,PRINT_COUNT);j++)
            cout<<row[j]<<" ";
        cout<<"\n";
    }
}



/**
 * @brief This function returns one row of the Matrix using the cursor object. It
 * returns an empty row is all rows have been read.
 *
 * @param cursor 
 * @return vector<int> 
 */
void Matrix::getNextPage(CursorMatrix *cursor,int restart)
{
    logger.log("Matrix::getNext");
    
    if(restart == 1)
    {
        if(cursor->restartRowIndex != bi_max)
        {
            cursor->nextPage(cursor->restartRowIndex + 1,0,restart);
        }
        
    }
    else
    {
        if(cursor->bj < bj_max-1)
        {
            cursor->nextPage(cursor->bi,cursor->bj + 1,restart);
        }
        else//Blockcount is total number of blocks
        {
            cursor->nextPage(cursor->restartRowIndex,0,restart);
        }
    }
    
}



/**
 * @brief called when EXPORT command is invoked to move source file to "data"
 * folder.
 *
 */
void Matrix::makePermanent()
{
    logger.log("Matrix::makePermanent");
    if(!this->isPermanent())
        bufferManagerMatrix.deleteFile(this->sourceFileName);
    string newSourceFile = "../data/" + this->MatrixName + ".csv";
    ofstream fout(newSourceFile, ios::out);

    //print headings
    // this->writeRow(this->columns, fout);

    CursorMatrix cursor(this->MatrixName, 0, 0);
    vector<int> row;
    //cout<<"Hello into makepermanent() "<<this->rowCount<<" "<<this->MatrixName<<"\n";
    for (int rowCounter = 0; rowCounter < this->rowCount; rowCounter++)
    {
       // cout<<rowCounter<<" "<<bi_max<<"\n";
        int j = 0;
        int last = 0;
        for(int i=0;i<bi_max;i++)
        {
            //cout<<"i is "<<i<<"\n";
            if(i == bi_max-1)
            {
                last = 1;
            }
            // getNextPage()
            row = cursor.getNext(last);
            //cout<<"Row"<<endl;
            //for(int i=0;i<row.size();i++)
                //cout<<row[i]<<" ";
            //cout<<endl;
            this->writeRow(row, fout,last);
        }
        
    }
    //cout<<endl;
    fout.close();
}

/**
 * @brief Function to check if Matrix is already exported
 *
 * @return true if exported
 * @return false otherwise
 */
bool Matrix::isPermanent()
{
    logger.log("Matrix::isPermanent");
    if (this->sourceFileName == "../data/" + this->MatrixName + ".csv")
    return true;
    return false;
}

/**
 * @brief The unload function removes the Matrix from the database by deleting
 * all temporary files created as part of this Matrix
 *
 */
void Matrix::unload(){
    logger.log("Matrix::~unload");
    for (int pageCounter = 0; pageCounter < this->bi_max; pageCounter++)
        for (int pageCounter2 = 0; pageCounter2 < this->bj_max; pageCounter2++)
            bufferManagerMatrix.deleteFile(this->MatrixName, pageCounter,pageCounter2);
    if (!isPermanent())
        bufferManagerMatrix.deleteFile(this->sourceFileName);
}

/**
 * @brief Function that returns a cursor that reads rows from this Matrix
 * 
 * @return Cursor 
 */
CursorMatrix Matrix::getCursor()
{
    logger.log("Matrix::getCursor");
    CursorMatrix cursor(this->MatrixName, 0,0);
    return cursor;
}
/**
 * @brief Function that returns the index of column indicated by columnName
 * 
 * @param columnName 
 * @return int 
 */
// int Matrix::getColumnIndex(string columnName)
// {
//     logger.log("Matrix::getColumnIndex");
//     for (int columnCounter = 0; columnCounter < this->columnCount; columnCounter++)
//     {
//         if (this->columns[columnCounter] == columnName)
//             return columnCounter;
//     }
// }
