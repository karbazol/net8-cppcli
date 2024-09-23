#include "StringReverse.h"

#include <algorithm>
#include <iostream>

using namespace std;

std::wstring StringReverse(const std::wstring& str)
{
  wstring result = str;

  // Reverse the string using the reverse() function
  std::reverse(result.begin(), result.end());

  return result;
}

