
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
	vector<int> vec;
	int vertex, count;

	data.open("data2.txt");
	
	if(!data.is_open()){
		cout << "File failed to open\n";
		return 2;
	}


	while(!data.eof()){
		getline(data, line);
			s.str(line);
			while(s >> line){
				vertex = stoi(line);
				vec.push_back(vertex);
			}
			graph.push_back(vec);
			vec.clear();
			s.clear();
					
	}

	for(int i = 0; i < graph.size(); i++){
		for (int j = 0; j < graph[i].size(); j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}	

