#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;

std::vector<int> lv,rv;

int handleInput(string line);
bool cmp(int a, int b);
void readLineToLists(string line);

void readLineToLists(string line)
{
	string  dlm  = "   ";
	// split line into two strings -> left and righti
	size_t dp = line.find(dlm);
	int l = stoi(line.substr(0,dp));
	int r = stoi(line.substr(dp + dlm.length()));

	// take each 	string put it on a list -> left and right list
	lv.push_back(stoi(line.substr(0,dp)));
	rv.push_back(stoi(line.substr(dp + dlm.length())));
	
}

bool cmp(int a , int b ) {return a>b;}

int calculate()
{
	// sort lists
	std::sort(lv.begin(),lv.end(),cmp);
	std::sort(rv.begin(),rv.end(),cmp);

	// abstract one list from another and add it to totalSum
	int sum = 0; 
	for(auto i=0;i < lv.size();i++)
	{
		sum += lv[i] > rv[i] ? lv[i] - rv[i] : rv[i] - lv[i];
	} 

	return sum;
}

int main (){
	std::string f = "input.txt";
	//open file
	ifstream mf(f);
	std::string line; 

	std::cout << "-----------Starting-------------\n";
	if (!mf.is_open())
	{
		std::cerr << "Failed to open file" << endl;
		return 1;
	}	
	while (std::getline(mf,line) )
	{
		readLineToLists(line);
	}
	

	std::cout << calculate() << endl;
	mf.close();
	std::cout << "-----------Finish---------------\n";
}
