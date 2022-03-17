#include "CString.h"

enum { MaxStrLength = 1024 };

CString::CString() : m_str(nullptr), m_size(0) {}

CString::CString(const char *str) : m_str(nullptr), m_size(0) {
  m_size = strlen(str);
  m_str = new char[m_size + 1];
  memcpy(m_str, str, m_size);
  m_str[m_size] = '\0';
}

CString::CString(char c) : m_str(new char[2]), m_size(1) {
    m_str[0] = c;
    m_str[m_size] = '\0';
}

CString::~CString() {
  if (m_str)
    delete[] m_str;
}

CString::CString(const CString &other)
    : m_str(new char[other.m_size + 1]), m_size(other.m_size) {

  memcpy(m_str, other.m_str, m_size);
  m_str[m_size] = '\0';
}

CString &CString::operator=(const CString &other) {
  if (this == &other)
    return *this;

  if (m_size != other.m_size) {
    m_size = other.m_size;
    if (m_str)
      delete[] m_str;
    m_str = new char[m_size + 1];
  }

  memcpy(m_str, other.m_str, m_size);
  m_str[m_size] = '\0';
  return *this;
}

CString::CString(CString &&other) noexcept
    : m_str(new char[other.m_size + 1]), m_size(other.m_size) {

  memcpy(m_str, other.m_str, m_size);
  m_str[m_size] = '\0';

  memset(other.m_str, 0, other.m_size);
  other.m_str = nullptr;
  other.m_size = 0;
}

CString &CString::operator=(CString &&other) noexcept {
  if (this == &other)
    return *this;

  if (m_size != other.m_size) {
    m_size = other.m_size;
    if (m_str)
      delete[] m_str;
    m_str = new char[m_size + 1];
  }

  if (m_str) {
      memcpy(m_str, other.m_str, m_size);
      m_str[m_size] = '\0';
  }

  memset(other.m_str, 0, other.m_size);
  other.m_str = nullptr;
  other.m_size = 0;

  return *this;
}

CString &CString::operator=(const char *str) {
  auto len = strlen(str);

  if (len != m_size) {
    m_size = len;
    if (m_str)
      delete[] m_str;
    m_str = new char[m_size + 1];
  }

  memcpy(m_str, str, m_size);
  m_str[m_size] = '\0';

  return *this;
}

size_t CString::size() const { return m_size; }

CString& CString::append(char c) {
    *this += CString(c);
    return *this;
}

CString& CString::append(const char* str) {
    *this += CString(str);
    return *this;
}

CString& CString::append(const CString& str) {
    *this += str;
    return *this;
}

CString& CString::reverse() {
    char tmp;
    size_t n = m_size - 1;

    for (size_t i = 0; i < (m_size / 2); i++) {
        tmp = m_str[i];
        m_str[i] = m_str[n];
        m_str[n] = tmp;
        n--;
    }

    return *this;
}

CString& CString::operator+=(const CString& rhs) {
    size_t newsize = m_size + rhs.m_size;
    char* new_str = new char[newsize + 1];

    memcpy(new_str, m_str, m_size);

    for (size_t i = 0; i < rhs.m_size; i++) {
        new_str[m_size + i] = rhs.m_str[i];
    }

    delete[] m_str;
    m_str = new_str;
    m_size = newsize;

    m_str[m_size] = '\0';

    return *this;
}

CString operator+(const CString &lhs, const CString &rhs) {
    return CString(lhs) += rhs;
}
CString operator+(const CString &lhs, const char *rhs) {
    return lhs + CString(rhs);
}
CString operator+(const CString &lhs, char *rhs) {
    return lhs + CString(rhs);
}
CString operator+(const char *lhs, const CString &rhs) {
    return CString(lhs) + rhs;
}
CString operator+(char *lhs, const CString &rhs) {
    return CString(lhs) + rhs;
}

std::ostream &operator<<(std::ostream &os, const CString &cstr) {

  if (cstr.m_str != nullptr)
    os << cstr.m_str;
  else
    os << "";

  return os;
}

std::istream& operator>>(std::istream& is, CString& cstr) {
    char* tmp = new char[MaxStrLength];
    is >> tmp;
    cstr.append(tmp);
    delete[] tmp;
    return is;
}
