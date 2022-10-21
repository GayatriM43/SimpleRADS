//#include"logger.h"
/**
 * @brief The Page object is the main memory representation of a physical page
 * (equivalent to a block). The page class and the page.h header file are at the
 * bottom of the dependency tree when compiling files. 
 *<p>
 * Do NOT modify the Page class. If you find that modifications
 * are necessary, you may do so by posting the change you want to make on Moodle
 * or Teams with justification and gaining approval from the TAs. 
 *</p>
 */

class PageMatrix{

    string MatrixName;
    string pageIndex;
    int bi;
    int bj;
    
    vector<vector<int>> rows;

    public:
    int columnCount = -1;
    int rowCount = -1;
    string pageName = "";
    PageMatrix();
    PageMatrix(string MatrixName, int bi, int bj);
    PageMatrix(string MatrixName, int bi, int bj, vector<vector<int>> rows, int rowCount,int colCount);
    vector<int> getRow(int rowIndex);
    vector<vector<int>> getallRows();
    void writePage();
};