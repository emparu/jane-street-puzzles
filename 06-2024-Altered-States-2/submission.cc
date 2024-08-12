#include <bits/stdc++.h>
using namespace std;
std::random_device device;
std::mt19937 engine(device()); // Seed the random number engine
std::discrete_distribution<> dist({300,7,62,50,173,22,54,68,260,9,43,104,54,249,208,20,0,138,185,101,35,27,55,31,54,7}); // Create the distribution



bool findWord_rec(vector<string>&v, string word,int i, int j, bool allowOne){
	if((i>4||i<0)||(j>4||j<0)){
		return false;
	}
	
	if(word.size()==1)
		return (v[i][j]==word[0])||allowOne;
	
	
	if(v[i][j]!=word[0]){
		if(!allowOne)
			return false;
		else
			allowOne=false;
	}
	
	
	for (int x=i-1;x<=i+1;x++){
		for (int y=j-1;y<=j+1;y++){
			if(!(x==i&&y==j)){
				if(findWord_rec(v,word.substr(1,int(word.size()-1)),x,y,allowOne)){
					return true;
				}
			}
		}
	}
	return false;
	
}

bool findWord(vector<string>&v, string word){

	for (int x=0;x<5;x++){
		for (int y=0;y<5;y++){
			if(findWord_rec(v,word,x,y,true)){
				return true;
			}
		}
	}
	return false;
}


int scorePrint(vector<string>& v) {
    unordered_map<string, int> statePopulation = {
        {"CALIFORNIA", 39538223}, 
        {"TEXAS", 29145505}, {"FLORIDA", 21538187}, 
        {"NEWYORK", 20201249}, {"PENNSYLVANIA", 13002700}, {"ILLINOIS", 12812508}, 
        {"OHIO", 11799448}, {"GEORGIA", 10711908}, {"NORTHCAROLINA", 10439388}, 
        {"MICHIGAN", 10077331}, {"NEWJERSEY", 9288994}, {"VIRGINIA", 8631393}, 
        {"WASHINGTON", 7705281}, {"ARIZONA", 7151502}, {"MASSACHUSETTS", 7029917}, 
        {"TENNESSEE", 6910840}, {"INDIANA", 6785528}, {"MARYLAND", 6177224}, 
        {"MISSOURI", 6154913}, {"WISCONSIN", 5893718}, {"COLORADO", 5773714}, 
        {"MINNESOTA", 5706494}, {"SOUTHCAROLINA", 5118425}, {"ALABAMA", 5024279}, 
        {"LOUISIANA", 4657757}, {"KENTUCKY", 4505836}, {"OREGON", 4237256}, 
        {"OKLAHOMA", 3959353}, {"CONNECTICUT", 3605944}, {"UTAH", 3271616}, 
        {"IOWA", 3190369}, {"NEVADA", 3104614}, {"ARKANSAS", 3011524}, 
        {"MISSISSIPPI", 2961279}, {"KANSAS", 2937880}, {"NEWMEXICO", 2117522}, 
        {"NEBRASKA", 1961504}, {"IDAHO", 1839106}, {"WESTVIRGINIA", 1793716}, 
        {"HAWAII", 1455271}, {"NEWHAMPSHIRE", 1377529}, {"MAINE", 1362359}, 
        {"RHODEISLAND", 1097379}, {"MONTANA", 1084225}, {"DELAWARE", 989948}, 
        {"SOUTHDAKOTA", 886667}, {"NORTHDAKOTA", 779094}, {"ALASKA", 733391},
        {"VERMONT", 643077}, {"WYOMING", 576851}
    };

    int totalScore = 0;
    for (auto statea : statePopulation) {
		string state=statea.first;
		
        if (findWord(v, state)) {
			cout<<state<<"\n";
            totalScore += statea.second;
            
        }
    }
    return totalScore;
}

int score(vector<string>& v) {
    unordered_map<string, int> statePopulation = {
        {"CALIFORNIA", 39538223},
        {"TEXAS", 29145505}, {"FLORIDA", 21538187}, 
        {"NEWYORK", 20201249}, {"PENNSYLVANIA", 13002700}, {"ILLINOIS", 12812508}, 
        {"OHIO", 11799448}, {"GEORGIA", 10711908}, {"NORTHCAROLINA", 10439388}, 
        {"MICHIGAN", 10077331}, {"NEWJERSEY", 9288994}, {"VIRGINIA", 8631393}, 
        {"WASHINGTON", 7705281}, {"ARIZONA", 7151502}, {"MASSACHUSETTS", 7029917}, 
        {"TENNESSEE", 6910840}, {"INDIANA", 6785528}, {"MARYLAND", 6177224}, 
        {"MISSOURI", 6154913}, {"WISCONSIN", 5893718}, {"COLORADO", 5773714}, 
        {"MINNESOTA", 5706494}, {"SOUTHCAROLINA", 5118425}, {"ALABAMA", 5024279}, 
        {"LOUISIANA", 4657757}, {"KENTUCKY", 4505836}, {"OREGON", 4237256}, 
        {"OKLAHOMA", 3959353}, {"CONNECTICUT", 3605944}, {"UTAH", 3271616}, 
        {"IOWA", 3190369}, {"NEVADA", 3104614}, {"ARKANSAS", 3011524}, 
        {"MISSISSIPPI", 2961279}, {"KANSAS", 2937880}, {"NEWMEXICO", 2117522}, 
        {"NEBRASKA", 1961504}, {"IDAHO", 1839106}, {"WESTVIRGINIA", 1793716}, 
        {"HAWAII", 1455271}, {"NEWHAMPSHIRE", 1377529}, {"MAINE", 1362359}, 
        {"RHODEISLAND", 1097379}, {"MONTANA", 1084225}, {"DELAWARE", 989948}, 
        {"SOUTHDAKOTA", 886667}, {"NORTHDAKOTA", 779094}, {"ALASKA", 733391},
        {"VERMONT", 643077}, {"WYOMING", 576851}
    };

    int totalScore = 0;
    for (auto statea : statePopulation) {
		string state=statea.first;
		
        if (findWord(v, state)) {
            totalScore += statea.second;
            
        }
    }
    return totalScore;
}

void printv(vector<string>v){
	for(int i=0;i<int(v.size());i++){
		cout<<v[i]<<"\n";
	}
}

vector<string> generateRandomMatrix(int rows, int cols) {
    // Seed the random number generator
    
    
    vector<string> matrix(rows, "AAAAA");
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            char randomChar = 'A' + rand() % 26;  // Generate random uppercase letter
            matrix[i][j] = randomChar; // Convert char to string and store in matrix
        }
    }
    return matrix;
}

bool improveBoard(vector<string>& matrix) {
    int currentScore = score(matrix);
    int firstScore = currentScore;
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<string> tempMatrix = matrix;

    for(int m=0;m<4500;m++) {
        // Create a copy of the matrix to work on
        tempMatrix = matrix;

        // Store the positions changed
        vector<pair<int, int>> changedPositions;

        // Change n random positions
        for (int i = 0; i < (6000-m)/1500; ++i) {
            int row, col;
            do {
                row = rand() % rows;
                col = rand() % cols;
            } while (find(changedPositions.begin(), changedPositions.end(), make_pair(row, col)) != changedPositions.end());

            changedPositions.push_back(make_pair(row, col));
            tempMatrix[row][col] = 'A' + dist(engine);
        }

        // Calculate the new score
        int newScore = score(tempMatrix);

        // If the score improved, update the original matrix and exit the loop
        if (newScore > currentScore) {
            matrix = tempMatrix;
            currentScore=newScore;
            break;
        }

        // Otherwise, discard the changes and continue
    }
    
	for(const auto& row : tempMatrix) {
		cout<<row<<"\n";
	}
    
    cout<<currentScore<<"\n";
    return currentScore>firstScore;
}

void improveBoardRecursive(deque<vector<string>>& matrixList) {
	if(matrixList.empty()){
		matrixList.emplace_back(generateRandomMatrix(5, 5));
	}
	
	vector<string> end=matrixList.back();
	//matrixList.pop_back();
	
	if(improveBoard(end)){
		matrixList.push_back(end);
	}else{
		for(int i=0;i<rand()%matrixList.size();i++){
			if(!matrixList.empty()){
				matrixList.pop_back();
			}
		}
	}
	improveBoardRecursive(matrixList);
}


int main(){
	srand(time(0));
	
	deque<vector<string>> matrixList;
	improveBoardRecursive(matrixList);
	

}
