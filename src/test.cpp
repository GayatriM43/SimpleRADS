#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> ab={1};
    ab.insert(ab.begin()+1,2);
    for(int i=0;i<ab.size();i++)
        cout<<ab[i]<<" ";
    return 0;
}