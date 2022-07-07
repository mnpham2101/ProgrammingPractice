#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define MAX_N	(10000)
#define MAX_LEN (20)

int N;
string words[MAX_N+1];

string sol_word;
vector<int> sol_seq;

struct  word_priority {
	string word;
	int occurance=0;
	int sumOrder=0;
	int firstOccurance=0;
	vector<int> wordPosition;

};

static bool compare(word_priority A, word_priority B){
	bool result = false;
	if (A.occurance != B.occurance)
		return (A.occurance>B.occurance);
	else if (A.occurance == B.occurance && A.sumOrder != B.sumOrder)
		return (A.sumOrder > B.sumOrder);
	else if (A.occurance == B.occurance && A.sumOrder == B.sumOrder && A.firstOccurance !=B.firstOccurance)
		return (A.firstOccurance < B.firstOccurance);
	return result;
}

vector<word_priority> wordList;			           // word properties for sorting
unordered_map<string, int> wordSet; 						// word set to check if word occurs
																								// string: word
																								// int: index to position of the word in wordList

void Input_Data(void) {
	int i;
	cin >> N;
	// wordList.resize(N+1);					// create wordList of size N+1 since index start=1
	int wordListIndex =0;
	for (i = 1; i <= N;i++) {
		cin >> words[i];
		auto foundWord = wordSet.find(words[i]);
		if (foundWord == wordSet.end()){
			// cout<<"insert "<<i<<" "<<words[i]<<" ";
			wordSet.insert({words[i], wordListIndex});
			wordListIndex++;
			// add properties
			word_priority myword;
			myword.word = words[i];
			myword.occurance++;
			myword.sumOrder = i;
			myword.firstOccurance = i;
			myword.wordPosition.push_back(i);
			wordList.push_back(myword);
			// cout<<myword.occurance++<<" "<< myword.sumOrder << " " << myword.firstOccurance <<endl;
		}
		else{

			int index = foundWord->second;
			word_priority myword;
			myword = wordList[index];
			myword.word = words[i];
			myword.occurance++;
			myword.sumOrder += i;
			myword.wordPosition.push_back(i);
			// cout<<"foundWord "<<myword.word<<" ";
			// cout<<myword.occurance<<" "<< myword.sumOrder << " " << myword.firstOccurance <<endl;
			wordList[index]=myword;
		}
	}
	// log:
	sort (wordList.begin(), wordList.end(), compare);
	for (auto i = wordList.begin(); i != wordList.end(); i++){
		cout<<"word: "<<i->word<<" ";
		cout<<"occurance: "<<i->occurance<<" ";
		cout<<"sumOrder: "<<i->sumOrder<<" ";
		cout<<"firstOccurance: "<<i->firstOccurance<<" "<<endl;
	}
}

void Print_Output(void) {

	auto i = wordList.begin();
	sol_word = i->word;
	sol_seq = i->wordPosition;
	cout << sol_word << '\n';
	for (int i = 0; i < sol_seq.size();i++) {
		cout << sol_seq[i] << ' ';
	}
	// cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input_Data(); // Input part

	// Start preparing from here


	Print_Output(); // Output part

	return 0;
}