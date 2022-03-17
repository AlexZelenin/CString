#include <iostream>
#include <stdio.h>

#include "CString.h"
#include "TestListStr.h"

#ifdef WIN32
#include <Windows.h>
#endif

int main(int, char **) {

#ifdef WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

/*  FILE* fptr = fopen("C:\\Program Files\\7-Zip\\readme.txt", "rb");
  CString str;
  
  if (!fptr) {
    perror("File opening failed");
    return 1;
  }
  
  int c;
  while ((c = fgetc(fptr)) != EOF) {
    str.append(c);
  }
  fclose(fptr);

  std::cout << str << "\n" << "Size: " << str.size() << std::endl; */

    TestListStr test;


  return test.exec();
}