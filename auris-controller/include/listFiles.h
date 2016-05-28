#ifndef _LISTFILES_H
#define _LISTFILES_H

#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <string>

namespace fs = ::boost::filesystem;
using namespace std;

class ListFiles{

	public:
		void listExtension(const fs::path& root, const string& ext, vector<string> *ret);

};

#endif