#include "bits/stdc++.h"
using namespace std;
vector<pair<pair<int,int>,int>> pos;

bool isSummable(int num,vector<int>&v,int size){
	if(size==0){
		return num==0;
	}else{
		return(isSummable(num-v[size-1],v,size-1)||isSummable(num,v,size-1));
	}
}

int sumv(vector<int>&v){
	int a=0;
	for(int i=0;i<int(v.size());i++){
		a+=v[i];
	}
	return a;
}

bool checkNumbers(vector<vector<int>>& board){
	for(int i=0;i<int(pos.size());i++){
		vector<int> nums;
		int k=0;
		if(pos[i].first.first+1<9&&pos[i].first.second<9){
			nums.push_back(board[pos[i].first.first+1][pos[i].first.second]);
			if(board[pos[i].first.first+1][pos[i].first.second]!=0){
				k++;
			}
		}
		if(pos[i].first.first>=0&&pos[i].first.second+1<9){
			nums.push_back(board[pos[i].first.first][pos[i].first.second+1]);
			if(board[pos[i].first.first][pos[i].first.second+1]!=0){
				k++;
			}
		}
		if(pos[i].first.first<9&&pos[i].first.second-1>=0){
			nums.push_back(board[pos[i].first.first][pos[i].first.second-1]);
			if(board[pos[i].first.first][pos[i].first.second-1]!=0){
				k++;
			}
		}
		if(pos[i].first.first-1>=0&&pos[i].first.second>=0){
			nums.push_back(board[pos[i].first.first-1][pos[i].first.second]);
			if(board[pos[i].first.first-1][pos[i].first.second]!=0){
				k++;
			}
		}
		int n=int(nums.size());
		if(n==k){
			if(!isSummable(pos[i].second,nums,n)){
				return false;
			}
		}else{
			int s = sumv(nums);
			return(s>=pos[i].second-9*(n-k));
		}
	}
	return true;
}

bool checkNumbers1(vector<vector<int>>& board){
	for(int i=0;i<int(pos.size());i++){
		vector<int> nums;
		int k=0;
		if(pos[i].first.first+1<9&&pos[i].first.second<9){
			nums.push_back(board[pos[i].first.first+1][pos[i].first.second]);
			if(board[pos[i].first.first+1][pos[i].first.second]!=0){
				k++;
			}
		}
		if(pos[i].first.first>=0&&pos[i].first.second+1<9){
			nums.push_back(board[pos[i].first.first][pos[i].first.second+1]);
			if(board[pos[i].first.first][pos[i].first.second+1]!=0){
				k++;
			}
		}
		if(pos[i].first.first<9&&pos[i].first.second-1>=0){
			nums.push_back(board[pos[i].first.first][pos[i].first.second-1]);
			if(board[pos[i].first.first][pos[i].first.second-1]!=0){
				k++;
			}
		}
		if(pos[i].first.first-1>=0&&pos[i].first.second>=0){
			nums.push_back(board[pos[i].first.first-1][pos[i].first.second]);
			if(board[pos[i].first.first-1][pos[i].first.second]!=0){
				k++;
			}
		}
		int n=int(nums.size());
		if(n==k){
			if(!isSummable(pos[i].second,nums,n)){
				for(int i=0;i<int(nums.size());i++){
					cout<<nums[i]<<" ";
				}
				cout<<"\n";
				return false;
			}
		}else{
			int s = sumv(nums);
			return(s>=pos[i].second-9*(n-k));
		}
	}
	return true;
}

pair<int,int> fillL(vector<vector<int>>& board,int n,int k,int x,int y,int val){
	if(k==0){
		for(int i=x;i<x+n;i++){
			board[i][y+n-1]=val;
		}
		for(int i=y;i<y+n;i++){
			board[x+n-1][i]=val;
		}
		return {x,y};
	}
	if(k==1){
		for(int i=x;i<x+n;i++){
			board[i][y]=val;
		}
		for(int i=y;i<y+n;i++){
			board[x+n-1][i]=val;
		}
		return {x,y+1};
	}
	if(k==2){
		for(int i=x;i<x+n;i++){
			board[i][y+n-1]=val;
		}
		for(int i=y;i<y+n;i++){
			board[x][i]=val;
		}
		return {x+1,y};
	}
	if(k==3){
		for(int i=x;i<x+n;i++){
			board[i][y]=val;
		}
		for(int i=y;i<y+n;i++){
			board[x][i]=val;
		}
		return {x+1,y+1};
	}
}

void buildBoard(vector<vector<int>>& board,vector<pair<int,int>> seq){
	int n=9;
	int x=0;
	int y=0;
	for(int i=0;i<int(seq.size());i++){
		pair<int,int> p = fillL(board,n,seq[i].first,x,y,seq[i].second);
		x=p.first;
		y=p.second;
		n--;
	}
}
void printBoard(vector<vector<int>> board){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

bool checkSeq(vector<pair<int,int>> seq){
	vector<int> seq1;
	for(int i=0;i<int(seq.size());i++){
		seq1.push_back(seq[i].second);
	}
	sort(seq1.begin(),seq1.end());
	
	for(int i=0;i<int(seq.size());i++){
		if(i>0){
			if(seq1[i]==seq1[i-1]){
				return false;
			}
		}
		if(seq[i].second==1&&i!=8){
			return false;
		}
		if(seq[i].second==2&&i!=7){
			return false;
		}
		if(seq[i].second>(2*(8-i)+1)){
			return false;
		}
	}
	vector<vector<int>> board(9,vector<int>(9,0));
	buildBoard(board,seq);
	if(int(seq.size())==9&&checkNumbers(board)){
		printBoard(board);
		cout<<"-------------"<<"\n";
	}
	return(checkNumbers(board));
}


void printSeq(vector<pair<int,int>>& seq){
	for(int i=0;i<int(seq.size());i++){
		cout<<"{"<<seq[i].first<<", "<<seq[i].second<<"}"<<", ";
	}
	cout<<"\n";
}

void backtrack(vector<pair<int,int>>& seq,int n){
	
	if(n==2){
		//printSeq(seq);
		for(int i=0;i<4;i++){
			seq.push_back(pair<int,int>(i,2));
			if(checkSeq(seq)){
				backtrack(seq,n-1);
			}
			seq.pop_back();
		}
		return;
	}
	if(n==1){
		//printSeq(seq);
		seq.push_back(pair<int,int>(0,1));
		if(checkSeq(seq)){
			backtrack(seq,n-1);
		}
		seq.pop_back();
		
		return;
	}
	if(n==0){
		printSeq(seq);
		return;
	}
	for(int i=0;i<4;i++){
		for(int j=1;j<=9;j++){
			seq.push_back(pair<int,int>(i,j));
			
			if(checkSeq(seq)){
				
				backtrack(seq,n-1);
			}
			seq.pop_back();
		}
	}
}

int main(){
	vector<vector<int>> boardNums={{0,18,0,0,0,0,7,0,0},
							   {0,0,0,0,12,0,0,0,0},
							   {0,0,9,0,0,0,0,31,0},
							   {0,0,0,0,0,0,0,0,0},
							   {0,5,0,11,0,22,0,22,0},
							   {0,0,0,0,0,0,0,0,0},
							   {0,9,0,0,0,0,19,0,0},
							   {0,0,0,0,14,0,0,0,0},
							   {0,0,22,0,0,0,0,15,0}};
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(boardNums[i][j]>0){
				pos.push_back({{i,j},boardNums[i][j]});
			}
		}
	}
	
	vector<vector<int>> board(9,vector<int>(9,0));
	vector<pair<int,int>> seq={};
	backtrack(seq,9);
	
	return 0;
}
