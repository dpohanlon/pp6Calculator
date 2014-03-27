#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include <sstream>
#include <string>

class MyFileReader {
public:

  MyFileReader(const char* filename);
  MyFileReader(const std::string& filename);

  bool nextLine();

  template<typename T>
  bool getField(const int n, T & rval)
  {
    failed = false;

    std::istringstream ist(line);
    this->skip_fields(ist, n-1);

    ist >> rval;

    if (ist.fail()) failed = true;
    
    return failed;
  }

bool inputFailed() const;
bool isValid() const;

void reset();

private:

  void skip_fields(std::istringstream& ist, const int n);
  std::ifstream file;
  std::string line;
  bool failed;

};

#endif
