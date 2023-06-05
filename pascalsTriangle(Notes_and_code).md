# Pascal's Triangle:
![image](https://github.com/AbhirupChakraborty/Striver-SDE-Sheet-Challenge-2023/assets/59620162/6ef8a5a8-f4d8-4b03-b908-9869cb845c4b)

**Majorly Three Types of Question:**
![image](https://github.com/AbhirupChakraborty/Striver-SDE-Sheet-Challenge-2023/assets/59620162/c88ba4d5-efc6-47eb-91f0-a416aa658eb2)
# TYPE-1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
  **Naive::** We have an easier formula to find out the element i.e. r-1Cc-1.
          The time complexity will be O(n)+O(r)+O(n-r).
  **Optimal::** We have a shortcut formula:: nCr = (n x n-1 x n-2 x ..... r times) / 1 x 2 x 3 x ... till r
            means 5c2 = (5 x 4) / (2 x 1)
  **Code:**
  TC: O(r) where r is the given column number
  SC: O(1)
  int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);    //(n / 1)*((n-1) / 2)*.....*((n-r+1) / r)
        res = res / (i + 1);    //(n / 1)*((n-1) / 2)*.....*((n-r+1) / r)
    }
    return res;
}
# TYPE-2: Given the row number n. Print the n-th row of Pascal’s triangle.
  **Naive:** In this approach, for every column from 1 to n, we will calculate the element (n, c)
         (where n is the given row number and c is the column number that will vary from 1 to n) using the previous method. Thus, we will print the row.
  Code:
  TC: O(n * r)
  SC: O(1)
  void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
  }
  **Optimal: **
  
  ![image](https://github.com/AbhirupChakraborty/Striver-SDE-Sheet-Challenge-2023/assets/59620162/03db364e-c2c0-4c4f-afc6-4570df91670d)
  
  Formula: Current element = prevElement * (rowNumber - colIndex) / colIndex
  Code:
  TC: O(N)
  SC: O(1)
  void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
  }

# TYPE-3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
  **Naive:**
  Code:
  TC: O(nxnxr) ~ O(N^3)
  SC: O(1)
  int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
  }
  vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
  }
  **Optimal: **
  Code:
  TC: O(N^2) where n=no of rows
  SC: O(1)
class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); //inserting the 1st element

        //calculate the rest of the elements:
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        //store the entire pascal's triangle:
        for (int row = 1; row <= n; row++)
            ans.push_back(generateRow(row));
        return ans;
    }
};
