#pragma once

#include <list>

#include "CString.h"


class TestListStr {
public:
	TestListStr();
	~TestListStr();

	int exec();

private:
	std::list<CString> m_strList;
};

