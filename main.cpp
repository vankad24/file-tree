#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
/* 
for (const auto &entry: filesystem::directory_iterator(path) ){
		cout << entry.path() << "\n";
		cout << entry.is_directory() << "\n";
		cout << entry.is_regular_file() << "\n";
		cout << entry.path()/"folder" << "\n";
		
	}
 */
//g++.exe main.cpp -o main.exe -std=c++17
//g++ main.cpp Utils.h -o main.exe -O2

int rsum(string path){
	int sum = 0;
	for (const auto &entry: filesystem::directory_iterator(path) ){
		if (entry.is_directory())sum+=rsum(entry.path().string());
		else{
			ifstream file;
			file.open(entry.path());
			int n;
			if (file.is_open()){
				while(!file.eof()){//end of file
					file >> n;
					sum+=n;
				}
			}
			file.close();
			
		}
	}
	return sum;
}

int main() {
	
	string path = "./data";
	cout << rsum(path);
	// for (int i = 0; i < n; i++){
	
	return 0;
}
