class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(); //no of rows
        int m=matrix[0].size(); //no of columns

        unordered_set<int> setRows;     //to store the row numbers where matrix[i][j]==0
        unordered_set<int> setCols;     //to store the col numbers where matrix[i][j]==0

        //in O(N^2) we determind the total no of 0's present in matrix
        //and put respective (i,j) in setRows and setCols 
        //so that later on we can make whole row and col filled with 0's
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    setRows.insert(i);
                    setCols.insert(j);
                }
            }
        }
        //For each element at position matrix[i][j], checks if i exists in setRows 
        //or j exists in  setColumns using the count() function. If either of them exists 
        //in their respective sets, the condition 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //setRows.count(i) > 0 or setColumns.count(j) > 0 will evaluate to true.
                //If the condition is true, the value at position matrix[i][j] is set to 0, 
                //effectively zeroing out the element.
                if(setRows.count(i)>0 || setCols.count(j)>0)
                    matrix[i][j]=0;
            }
        }
    }
};
