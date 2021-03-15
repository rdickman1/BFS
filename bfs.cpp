
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<list>
using namespace std;

int main(){
	ifstream data;
	ofstream out;
	string line;
	stringstream s;
	vector<vector<int>> graph;
	vector<int> vec;
	int vertex, count = 0;
	list<int> BFSqueue;

	data.open("data2.txt");
	out.open("out2.txt");
	
	if(!data.is_open()){
		cout << "Data file failed to open\n";
		return 1;
	}

	if (!out.is_open()) {
		cout << "Output file failed to open\n";
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
			count++;
	}

	bool *visit = new bool[count];
	for (int i = 1; i <= count; i++) {
		visit[i] = false;
	}

	vertex = 2;
	visit[vertex] = true;
	BFSqueue.push_back(vertex);
	
	while (!BFSqueue.empty()) {
	
		for (int i = 0; i < graph.size(); i++) {
			
			if (graph[i][0] == BFSqueue.front()) {
				for (int j = 1; j < graph[i].size(); j++) {
					vertex = graph[i][j];
					if (visit[vertex] == false) {
						visit[vertex] = true;
						BFSqueue.push_back(vertex);
					}
				}
			}
			
		}
		BFSqueue.pop_front();
	}

	for (int i = 1; i <= count; i++) {
		if (visit[i] == false) {
			out << "Graph not connected.\n";
			return 3;
		}
	}

	out << "Graph connected.\n";

	data.close();
	out.close();


	return 0;
}	

