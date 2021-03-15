
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstreeam>
using namespace std;

main(){
	ifstream data;

	data.open("data2.txt");
	
	if(!data.is_open()){
		cout << "File failed to open\n";
		return 2;
	}



