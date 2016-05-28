#include "listFiles.h"

void ListFiles::listExtension(const fs::path& root, const string& ext, vector<string> *ret){
    if(!fs::exists(root) || !fs::is_directory(root)) return;

    fs::recursive_directory_iterator it(root);
    fs::recursive_directory_iterator endit;
    
    int cont = 0;
    string s;
    while(it != endit)
    {
        if(fs::is_regular_file(*it) && it->path().extension() == ext){
        	ret->push_back(it->path().filename().string());
        	cout << "[" << cont << "] - " << it->path().filename() << endl;
        }	
        ++it;
        cont ++;
    }
}