//Better Solution:
//TC: O(2*N*M)
//SC: O(M+N)
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

//Optimal Solution::
//TC: O(2*M*N)
//SC: O(1) bcz col0 is contant space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(); //no of rows
        int m=matrix[0].size(); //no of columns

        //vector<int> row(n,0); // row array -> matrix[..][0] 
        //vector<int> col(m,0); // col array -> matrix[0][..]

        int col0 = 1;
        // step 1: Traverse the matrix and
        // mark 1st row & col accordingly:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // mark i-th row:
                    matrix[i][0] = 0;

                    // mark j-th column:
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
        // here we mark all the cells except 1st row and 1st col
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    // check for col & row:
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        //step 3: Finally mark the 1st col & then 1st row:
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0; //1st row
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0; //1st col
            }
        }
    }
};
