#include "global.h"

/**
 * @brief 
 * SYNTAX: R <- CROSS relation_name relation_name
 */
bool syntacticParseCROSSTRANSPOSE()
{
    logger.log("syntacticParseCROSSTRANSPOSE");
    if (tokenizedQuery.size() != 3)
    {
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = CROSSTRANSPOSE;
    parsedQuery.crossFirstRelationName = tokenizedQuery[1];
    parsedQuery.crossSecondRelationName = tokenizedQuery[2];
    return true;
}

bool semanticParseCROSSTRANSPOSE()
{
    logger.log("semanticParseCROSSTRANSPOSE");
    //Both tables must exist
    if (!matrixCatalogue.isMatrix(parsedQuery.crossFirstRelationName) || !matrixCatalogue.isMatrix(parsedQuery.crossSecondRelationName))
    {
        cout << "SEMANTIC ERROR: Cross relations don't exist" << endl;
        return false;
    }
    return true;
}

void executeCROSSTRANSPOSE()
{
    logger.log("executeCROSSTRANSPOSE");

    Matrix matrix1 = *(matrixCatalogue.getMatrix(parsedQuery.crossFirstRelationName));
    Matrix matrix2 = *(matrixCatalogue.getMatrix(parsedQuery.crossSecondRelationName));

    int maxi = matrix1.bi_max;
    int maxj = matrix1.bj_max;
    if(matrix1.columnCount!=matrix1.rowCount || matrix2.columnCount!=matrix2.rowCount || matrix1.columnCount!=matrix2.rowCount)
    {
        cout<<" MATRICES INCOMPATIBLE FOR CROSS TRANSPOSE \n";
        return;
    }
    vector<vector<int>> tmp(matrix1.maxRowsPerBlock,vector<int>(matrix1.maxColPerBlock,0));
    int columnCount = matrix1.columnsPerBlockCount[0][0]; 
    int rowCount = matrix2.rowsPerBlockCount[0][0];
    //cout<<columnCount<<" "<<rowCount<<" "<<endl;

    for(int i=0;i<maxi;i++)
    {
        for(int j=0;j<maxj;j++)
        {
            PageMatrix page1 = bufferManagerMatrix.getPage(matrix1.MatrixName, i,j);
            PageMatrix page2 = bufferManagerMatrix.getPage(matrix2.MatrixName, j,i);
            int page1_rows = page1.rowCount;
            int page1_cols = page1.columnCount;
            //cout<<page1_cols<<" "<<page1_rows<<endl;
            vector<vector<int>> page1_vec = page1.getallRows();
            vector<vector<int>> page2_vec = page2.getallRows();
            
            //cout<<page1_vec.size()<<" "<<page1_vec[0].size()<<endl;
            //cout<<page2_vec.size()<<" "<<page2_vec[0].size()<<endl;
            // N*M becomes M*N
            for(int row = 0;row<page1_cols;row++)
            {
                for(int col=0;col<page1_rows;col++)
                {
                    tmp[col][row] = page2_vec[row][col];
                }
            }

            for(int row=0;row<page1_rows;row++)
            {
                for(int col=0;col<page1_cols;col++)
                {
                    page2_vec[col][row] = page1_vec[row][col];
                }
            }


            /*for(int row = 0;row<page1_rows;row++)
            {
                for(int col=0;col<page1_cols;col++)
                {
                    cout << page1_vec[row][col] << " ";
                }
                cout<<endl;
            }

            for(int row = 0;row<page1_cols;row++)
            {
                for(int col=0;col<page1_rows;col++)
                {
                    cout << page2_vec[row][col] << " ";
                }
                cout<<endl;
            }*/

            string pageName1 = "../data/temp/" + matrix1.MatrixName + "_Page" + to_string(i) + "_" + to_string(j);
            string pageName2 = "../data/temp/" + matrix2.MatrixName + "_Page" + to_string(j) + "_" + to_string(i);
            bufferManagerMatrix.deleteFile(pageName1);
            bufferManagerMatrix.deleteFile(pageName2);

            //cout<<page1_rows<<" "<<page1_cols<<endl;
            bufferManagerMatrix.writePage(matrix1.MatrixName, i, j, tmp,page1_rows,page1_cols);
            bufferManagerMatrix.writePage(matrix2.MatrixName, j, i, page2_vec,page1_cols,page1_rows);
        }
    }
    bufferManagerMatrix.clearPool();
    //matrix1.makePermanent();
    //matrix2.makePermanent();

    return;
}