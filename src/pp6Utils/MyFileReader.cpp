#include <sstream>
#include "MyFileReader.hpp"

MyFileReader::MyFileReader(const char* filename)
  : file(filename), line(), failed(false)
{}

MyFileReader::MyFileReader(const std::string& filename)
  : file(filename.c_str()), line(), failed(false)
{}  

bool MyFileReader::isValid() const {
  if ( ! file )
    return false;
  else
    return true;
}

bool MyFileReader::nextLine(){
  getline(file, line);
  if (file.eof())
    return false;
  else 
    return true;
}

void MyFileReader::skip_fields(std::istringstream& ist, const int n) {
  if (n < 1)
    return;
  std::string tmp;
  for(int i = 1; i <= n; ++i) {
    ist >> tmp;
  }
}

bool MyFileReader::inputFailed() const {
  return failed;
}

void MyFileReader::reset() {
  file.clear();
  file.seekg(0, std::ios::beg);
}

