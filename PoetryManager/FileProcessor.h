#pragma once

#include <direct.h>
#include <string>
#include <vector>
#include <io.h>

using namespace std;

string getDir() {
	char buffer[1024];
	auto c = _getcwd(buffer, 1024);
	return string(buffer);
}

vector<string> getFiles(std::string path) {
	intptr_t  hFile = 0;
	_finddata_t fileinfo;
	std::string p;
	vector<string> files;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1){
		do {
			if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
				files.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	return files;
}