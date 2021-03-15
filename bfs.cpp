
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
	ifstream data;
	string line;
	stringstream s;
	vector<vector<int>> graph;
	int vertex;

	data.open("data2.txt");
	
	if(!data.is_open()){
		cout << "File failed to open\n";
		return 2;
	}
	
	int i = 0;
	while(getline(data, line)){
		s.str(line);
		
		while(s >> line){
			s >> vertex;	
			graph[i].push_back(vertex);
		}
		i++;
	}

	for(i = 0; i < graph.size(); i++){
		for (int j = 0; j < graph[i].size(); j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}	

