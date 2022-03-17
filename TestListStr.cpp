#include "TestListStr.h"

#include <iostream>

TestListStr::TestListStr() {}
TestListStr::~TestListStr() {}


int TestListStr::exec() {
  std::cout << "Заполните список строками:" << std::endl;
  int i = 5;


  while (i) {
    std::cout << m_strList.size() + 1 << ": ";
    CString str;
    std::cin >> str;
    m_strList.push_back(str);
    i--;
  }

  for (auto &s : m_strList) {
    std::cout << s.reverse() << std::endl;
  }

  return 0;
}