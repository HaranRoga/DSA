//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        int mx = 0;
        vector<int> leads;
        
        for(int i=n-1; i>=0; i--)
        {
            if(arr[i] >= mx)
            {
                mx = arr[i];
                leads.insert(leads.begin(), mx);
            }
        }
        return leads;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    ifstream fileIn;
    fileIn.open("01_leaders//fileInput1.txt");
    fileIn >> t; // testcases
    while (t--) {
        long long n = 0;
        fileIn >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            fileIn >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends