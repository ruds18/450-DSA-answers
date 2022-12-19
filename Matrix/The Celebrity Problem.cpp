// Approach 1 - Brute Force
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
      int potentialCeleb = -1;
      // Brute Force Approach
      for(int row =0 ; row<n;row++){
          
          int cntc =0 , cntr =0;
          
          for(int col =0; col<n;col++){
              // diagonal always zero
              if(row==col) continue;
              
              if(M[row][col] == 0) cntr++;
              if(M[col][row] == 1) cntc++;
          }
          if(cntr == n-1 && cntc == n-1) potentialCeleb = row;
      }

      return potentialCeleb;
    }
};

// Approach 2 - using Stack
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        // Step 1  - push all possile candiates in stack
        for(int i=0; i<n; i++){
            st.push(i);
        }
        // Step 2 - check if A knows B or B knows A
        while(st.size() > 1){
            int a  = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            // A knows B -> A ❌   B ✅
            if(M[a][b] == 1){
                st.push(b);
            }else{
                // B knows A -> B ❌  A ✅
                st.push(a);
            }
        }
        //potential candiate remaining
        int ans = st.top();
        st.pop();
        // Step 3 - Verify -> row's -> all zero && column -> all one's excluding diagonal elements
        int rowCount =0 , colCount = 0;
        // Row Check
        for(int col =0 ;col<n;col++){
            if(M[ans][col] == 0 ) rowCount++;
        }
        if(rowCount != n) return -1;
        
        // Col Check
        for(int row =0 ;row<n;row++){
            if(M[row][ans] == 1) colCount++;
        }
        if(colCount != n-1) return -1;
        
        return ans;
    }