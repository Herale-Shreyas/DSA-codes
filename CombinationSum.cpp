class Solution {
  private:
    void findAns(int sum, vector<int> A, int index, vector<int> &sequence, vector<vector<int>> &ans){


        //Base condition .. if index and the array size are same, check for sum condition
        if(index == A.size()){
            if(sum == 0) ans.push_back(sequence);
            return;
        }
      
        // Check for the sum condition 
        if(A[index] <= sum) {

            // if the condition is true, add it to the sum.. and call the recursion again for the same index
            sequence.push_back(A[index]);
            findAns(sum-A[index], A, index, sequence, ans);

            // Remove the recently added element so as to check the case for subsequent cases
            sequence.pop_back();
        }
        findAns(sum, A, index + 1, sequence, ans);
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int sum) {
        vector<vector<int> > ans;
        
        vector<int> sequence;

        // Sorting so that the number of recursive calls get reduced in search of the desired values
        sort(A.begin(), A.end());

        // removing duplicates
        A.erase(unique(A.begin(), A.end()), A.end());
        findAns(sum, A, 0, sequence, ans);
        
        return ans;
        
    }
};
