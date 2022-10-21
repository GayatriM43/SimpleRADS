#include "cursorMatrix.h"

/*enum IndexingStrategy
{
    BTREE,
    HASH,
    NOTHING
};*/

/**
 * @brief The Matrix class holds all information related to a loaded Matrix. It
 * also implements methods that interact with the parsers, executors, cursors
 * and the buffer manager. There are typically 2 ways a Matrix object gets
 * created through the course of the workflow - the first is by using the LOAD
 * command and the second is to use assignment statements (SELECT, PROJECT,
 * JOIN, SORT, CROSS and DISTINCT). 
 *
 */
class Matrix
{
    vector<unordered_set<int>> distinctValuesInColumns;

public:
    string sourceFileName = "";
    string MatrixName = "";
    //vector<string> columns;
    //vector<uint> distinctValuesPerColumnCount;
    long long int columnCount = 0;
    long long int rowCount = 0;
    uint bi_max = 0;
    uint bj_max = 0;
    uint maxRowsPerBlock = 0;
    uint maxColPerBlock = 0;
    uint cur_block_j=0;
    uint cur_block_i=0;
    vector<vector<int>> columnsPerBlockCount;
    vector<vector<int>> rowsPerBlockCount;
    bool indexed = false;
    string indexedColumn = "";
    IndexingStrategy indexingStrategy = NOTHING;
    
    bool getStatistics(string firstLine);
    bool blockify();
    void updateStatistics(vector<int> row);
    Matrix();
    Matrix(string MatrixName);
    Matrix(string MatrixName, vector<string> columns);
    bool load();
    bool isColumn(string columnName);
    void renameColumn(string fromColumnName, string toColumnName);
    void print();
    void makePermanent();
    bool isPermanent();
    void getNextPage(CursorMatrix *cursor,int restart);
    CursorMatrix getCursor();
    int getColumnIndex(string columnName);
    void unload();

    /**
 * @brief Static function that takes a vector of valued and prints them out in a
 * comma seperated format.
 *
 * @tparam T current usaages include int and string
 * @param row 
 */
template <typename T>
void writeRow(vector<T> row, ostream &fout, int last)
{
    logger.log("Matrix::printRow");
    for (int columnCounter = 0; columnCounter < row.size(); columnCounter++)
    {
        fout << row[columnCounter];
        //cout<<" "<<row[columnCounter]<<" ";
        if(columnCounter!=row.size()-1 || last==0)
            fout<<" ";
    }
    if (last == 1)
        fout << endl;
}

/**
 * @brief Static function that takes a vector of valued and prints them out in a
 * comma seperated format.
 *
 * @tparam T current usaages include int and string
 * @param row 
 */
template <typename T>
void writeRow(vector<T> row,int last)
{
    logger.log("Matrix::printRow");
    ofstream fout(this->sourceFileName, ios::app);
    this->writeRow(row, fout,last);
    fout.close();
}
};
