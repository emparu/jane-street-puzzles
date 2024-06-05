#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
std::set<ll> fibSet;

// Function to generate all Fibonacci numbers less than 10^11
void generateFibonacci() {
    ll a = 0, b = 1;
    fibSet.insert(a);
    fibSet.insert(b);
    ll c = a + b;
    while (c <= 100000000000LL) {  // 10^11
        fibSet.insert(c);
        a = b;
        b = c;
        c = a + b;
    }
}
	vector<vector<int>> board_positions=
	{
	{1,1,1,2,2,2,3,3,4,4,4},
	{1,5,5,5,2,2,3,4,4,4,6},
	{1,5,5,2,2,2,3,4,4,4,6},
	{1,5,5,2,2,7,7,4,6,6,6},
	{1,5,2,2,4,4,7,4,6,9,6},
	{1,4,4,4,4,4,4,4,9,9,10},
  {11,4,4,4,4,0,0,4,9,9,9},
  {11,11,12,4,12,0,0,4,4,9,4},	
  {11,11,12,12,12,0,0,4,4,4,4},
  {11,12,12,11,11,11,0,4,4,4,13},
  {11,11,11,11,11,0,0,0,4,4,13}		
	};

// Function to check if the current board configuration is valid

// Function to determine if a number is a perfect square

// Helper function to check if a number is a palindrome

// Function to check if a number is prime
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to compute the integer nth root of a number
ll nthRoot(ll x, ll n) {
    if (x == 0) return 0;
    if (n == 1) return x;
    if (n >= 62) return 1; // For large n, the nth root of x is 1 for any x >= 1

    ll low = 1, high = pow(x, 1.0 / n) + 2;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        ll power = 1;
        bool overflow = false;

        for (int i = 0; i < n; ++i) {
            if (power > x / mid) { // Check for overflow
                overflow = true;
                break;
            }
            power *= mid;
        }

        if (overflow || power > x) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low - 1;
}

// Function to check if a number is a prime raised to a prime power
bool isPrimeRaisedToPrimePower(ll x) {
    if (x <= 1) return false;

    for (ll i = 2; i <= 61; ++i) {
        if (isPrime(i)) { // Ensure only prime powers are considered
            ll root = nthRoot(x, i);
            if (root < 2) continue; // The nth root is less than 2, skip
            
            // Calculate root^i
            ll power = 1;
            for (ll j = 0; j < i; ++j) {
                if (power > x / root) { // Check for overflow
                    power = x + 1;
                    break;
                }
                power *= root;
            }

            // Check if power matches x and root is a prime
            if (power == x && isPrime(root)) {
                return true;
            }
        }
    }

    return false;
}

bool isPalindrome(ll number) {
    std::string s = std::to_string(number);
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Function to check if a number is 1 more than a palindrome
bool isOneMoreThanPalindrome(ll number) {
    return isPalindrome(number - 1);
}

// Function to check if a number is 1 less than a palindrome
bool isOneLessThanPalindrome(ll number) {
    return isPalindrome(number + 1);
}

bool isPerfectSquare(ll num) {
    ll root = static_cast<ll>(std::sqrt(num));
    return root * root == num;
}

// Function to check if a number is a Fibonacci number
bool isFibonacci(ll num) {
    // Check if the number is in the set of Fibonacci numbers
    return fibSet.find(num) != fibSet.end();
}

// Function to check if the number formed in row is a perfect square, ignoring 10s
bool hasSquare(std::vector<int>& board) {

    ll number = 0;
    for (ll digit : board) {
        if (digit != 10) {
            number = number * 10 + digit;
        }
    }

    return isPerfectSquare(number);
}
// Function to check if the number formed in row is a perfect square, ignoring 10s
bool hasOneMoreThanPalindrome(std::vector<int>& board) {

    ll number = 0;
    for (ll digit : board) {
        if (digit != 10) {
            number = number * 10 + digit;
        }
    }

    return isOneMoreThanPalindrome(number);
}
bool hasOneLessThanPalindrome(std::vector<int>& board) {

    ll number = 0;
    for (ll digit : board){
        if (digit != 10) {
            number = number * 10 + digit;
        }
    }

    return isOneLessThanPalindrome(number);
}

bool hasPrimePower(std::vector<int>& board) {

    ll number = 0;
    for (ll digit : board) {
        if (digit != 10) {
            number = number * 10 + digit;
        }
    }

    return isPrimeRaisedToPrimePower(number);
}

bool hasPalindrome23(std::vector<int>& board) {

    ll number = 0;
    for (ll digit : board) {
        if (digit != 10) {
            number = number * 10 + digit;
        }
    }

    return isPalindrome(number)&&((number%23)==0);
}

bool hasFibonacci(std::vector<int>& board) {

    ll number = 0;
    for (ll digit : board) {
        if (digit != 10) {
            number = number * 10 + digit;
        }
    }

    return isFibonacci(number);
}

bool hasMultiple(std::vector<int>& board, int k) {

    ll number = 0;
    for (ll digit : board) {
        if (digit != 10) {
            number = number * 10 + digit;
        }
    }

    return ((number%k)==0);
}

bool hasProductEndsIn1(std::vector<int>& board) {

    ll number = 1;
    for (ll digit : board) {
        if (digit != 10) {
            number = (number * digit) % 10;
        }
    }

    return (number==1);
}

bool hasSum7(std::vector<int>& board) {

    ll number = 0;
    for (ll digit : board) {
        if (digit != 10) {
            number = number+digit;
        }
    }

    return (number==7);
}


bool has_valid_numbers(std::vector<std::vector<int>>& board, int i, int j) {
    if (i < 0 || i >= int(board.size()) || j < 0 || j > int(board[i].size()))
        return false;

    bool foundFirstNonTen = false;
    bool validFirstNumber = true;
    int nonTenCount = 0;

    for (int col = 0; col < j; ++col) {
        int value = board[i][col];
        
        if (value == -1)
            continue;

        if (value != 10) {
            nonTenCount++;
            if (!foundFirstNonTen) {
                foundFirstNonTen = true;
                if (value == 0) {
                    validFirstNumber = false;
                }
            }
        }
    }

    if (!validFirstNumber)
        return false;

    if (j == 10 && nonTenCount < 2)
        return false;

    return true;
}

std::vector<int> getNumber(std::vector<int> v, int i) {
    std::vector<int> result;

    // Iterate backward from the end of the vector to the index `i`
    for (int j = i; j >= 0; --j) {
        // Stop at the first occurrence of `10`
        if (v[j] == 10 && j<i) {
            break;
        }
        // Add elements to the result
        if(v[j] != 10)
			result.push_back(v[j]);
    }

    // Reverse the result to maintain the original order
    std::reverse(result.begin(), result.end());

    // Remove the last element if it is `10`
    //if (!result.empty() && result.back() == 10) {
    //    result.pop_back();
    //}

    return result;
}

bool is_valid(vector<vector<int>>& board,  int i, int j) {
    // Implement your validation logic here
    // This should check if the board is still valid with board[i][j] just placed

    // Example check: Ensure no duplicate in the same row or column
    /*int n = board.size();
    for (int k = 0; k < n; k++) {
        // Check the row
        if (k != j && board[i][k] == board[i][j]) {
            return false;
        }
        // Check the column
        if (k != i && board[k][j] == board[i][j]) {
            return false;
        }
    }*/
    
    // Add more checks if necessary (e.g., sub-grid in Sudoku, diagonal in N-Queens, etc.)
    
    if(board[i][j]==-1){
		return false;
	}
	
	
    
	if(j+1<11){
		int i1=i;
		int j1=j+1;
		if(board[i1][j1]!=board[i][j] && board_positions[i1][j1]==board_positions[i][j] && board[i][j]!=10 && board[i1][j1]!=10 && board[i][j]!=-1 && board[i1][j1]!=-1){
			return false;
		}
		if(board[i1][j1]==board[i][j] && board_positions[i1][j1]!=board_positions[i][j] && board[i][j]!=10 && board[i1][j1]!=10 && board[i][j]!=-1 && board[i1][j1]!=-1){
			return false;
		}
		if(board[i1][j1]==board[i][j] && board[i][j]==10){
			return false;
		}
	}
	if(j-1>=0){
		int i1=i;
		int j1=j-1;
		if(board[i1][j1]!=board[i][j] && board_positions[i1][j1]==board_positions[i][j] && board[i][j]!=10 && board[i1][j1]!=10 && board[i][j]!=-1 && board[i1][j1]!=-1){
			return false;
		}
		if(board[i1][j1]==board[i][j] && board_positions[i1][j1]!=board_positions[i][j] && board[i][j]!=10 && board[i1][j1]!=10 && board[i][j]!=-1 && board[i1][j1]!=-1){
			return false;
		}
		if(board[i1][j1]==board[i][j] && board[i][j]==10){
			return false;
		}
	}
	
	if(i+1<11){
		int i1=i+1;
		int j1=j;
		if(board[i1][j1]!=board[i][j] && board_positions[i1][j1]==board_positions[i][j] && board[i][j]!=10 && board[i1][j1]!=10 && board[i][j]!=-1 && board[i1][j1]!=-1){
			return false;
		}
		if(board[i1][j1]==board[i][j] && board_positions[i1][j1]!=board_positions[i][j] && board[i][j]!=10 && board[i1][j1]!=10 && board[i][j]!=-1 && board[i1][j1]!=-1){
			return false;
		}
		if(board[i1][j1]==board[i][j] && board[i][j]==10){
			return false;
		}
	}
	if(i-1>=0){
		int i1=i-1;
		int j1=j;
		if(board[i1][j1]!=board[i][j] && board_positions[i1][j1]==board_positions[i][j] && board[i][j]!=10 && board[i1][j1]!=10 && board[i][j]!=-1 && board[i1][j1]!=-1){
			return false;
		}
		if(board[i1][j1]==board[i][j] && board_positions[i1][j1]!=board_positions[i][j] && board[i][j]!=10 && board[i1][j1]!=10 && board[i][j]!=-1 && board[i1][j1]!=-1){
			return false;
		}
		if(board[i1][j1]==board[i][j] && board[i][j]==10){
			return false;
		}
	}
	
	if(!has_valid_numbers(board,i,j)){
		return 0;
	}
	vector<int> v;
	
	if(board[i][j]==10||j==10){
		v=getNumber(board[i],j);
	}else{
		return true;
	}
	if(int(v.size())==0){
		return true;
	}
	if(int(v.size())<2||v[0]==0){
		return false;
	}
	
	/*for(int k=0;k<v.size();k++){
		cout<<v[k]<<" ";
	}
	cout<<"\n";*/
	
	if(i==0){
		if(!hasSquare(v)){
			return false;
		}
	}
	if(i==1){
		if(!hasOneMoreThanPalindrome(v)){
			return false;
		}
	}
	if(i==2){
		if(!hasPrimePower(v)){
			return false;
		}
	}
	if(i==3){
		if(!hasSum7(v)){
			return false;
		}
	}
	if(i==4){
		if(!hasFibonacci(v)){
			return false;
		}
	}
	if(i==5){
		if(!hasSquare(v)){
			return false;
		}
	}
	
	if(i==6){
		if(!hasMultiple(v,37)){
			return false;
		}
	}
	if(i==7){
		if(!hasPalindrome23(v)){
			return false;
		}
	}
	if(i==8){
		if(!hasProductEndsIn1(v)){
			return false;
		}
	}
	if(i==9){
		if(!hasMultiple(v,88)){
			return false;
		}
	}
    if(i==10){
		if(!hasOneLessThanPalindrome(v)){
			return false;
		}
	}
    return true;
}


long long sumBoard(std::vector<std::vector<int>>& board) {
    long long sum = 0;
    for (const auto& row : board) {
        long long num = 0;
        for (int cell : row) {
            if (cell == 10) { // separator
                if (num != 0) {
                    sum += num;
                    std::cout << "Detected number: " << num << std::endl;
                    num = 0;
                }
            } else if (cell >= 0 && cell <= 9) { // digit
                num = num * 10 + cell;
            }
        }
        if (num != 0) {
            sum += num;
            std::cout << "Detected number: " << num << std::endl;
        }
    }
    return sum;
}

// Backtracking function to try placing numbers in the board
void backtrack(vector<vector<int>>& board, int i, int j, int& count) {
    int n = board.size();

    // Move to the next cell
    int next_i = i, next_j = j + 1;
    if (next_j == n) { // Move to the next row if we reached the end of the current row
        next_i++;
        next_j = 0;
    }

    // If we have filled all rows, the board is complete
    if (i == n) {
        count++;
        cout << "Solution " << count << ":" << endl;
        for (const auto& row : board) {
            for (int num : row) {
				if(num!=10)
					cout << num << " ";
				else
					cout << "a" << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout<<sumBoard(board)<<"\n";
        
        
        
        return;
    }

    // Try placing numbers from 0 to 10 in board[i][j]
    for (int num = -1; num <= 10; num++) {
        board[i][j] = num;
        if (is_valid(board, i, j)) {
            backtrack(board, next_i, next_j, count);
        }
        // Backtrack
        board[i][j] = -1;
    }
}

// Function to initialize the board and start the backtracking process
void solve_board(vector<vector<int>>& board) {
    int count = 0;
    backtrack(board, 0, 0, count);
    if (count == 0) {
        cout << "No solutions found." << endl;
    } else {
        cout << "Total solutions found: " << count << endl;
    }
}




int main() {
	generateFibonacci();
	
	int n=11;

    vector<vector<int>> board(n, vector<int>(n, -1));

    solve_board(board);


    return 0;
}
