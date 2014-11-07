#pragma once
#include <string>
#include <atlstr.h>

namespace Utilities
{
	inline const wchar_t* stringToWchar(const std::string& s)
	{
		return std::wstring(s.begin(), s.end()).c_str();
	}

	inline std::string cStringToString(const CString& s)
	{
		return std::string(CT2CA(s));
	}
}