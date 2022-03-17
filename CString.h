#pragma once

#include <istream>
#include <ostream>

class CString {
  char *m_str;

public:
  CString();
  CString(const char *);
  CString(char c);

  ~CString();

  CString(const CString &);
  CString &operator=(const CString &);

  CString(CString &&) noexcept;
  CString &operator=(CString &&) noexcept;

  CString &operator=(const char *);

  size_t size() const;

  CString &append(char c);
  CString &append(const char *);
  CString &append(const CString &);

  CString &reverse();

  CString &operator+=(const CString &);

  friend CString operator+(const CString &lhs, const CString &rhs);
  friend CString operator+(const CString &lhs, const char *rhs);
  friend CString operator+(const CString &lhs, char *rhs);
  friend CString operator+(const char *lhs, const CString &rhs);
  friend CString operator+(char *lhs, const CString &rhs);

  friend std::ostream &operator<<(std::ostream &os, const CString &cstr);
  friend std::istream &operator>>(std::istream &is, CString &cstr);

private:
  size_t m_size;
};
