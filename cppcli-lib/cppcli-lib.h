#pragma once

#include <functional>
#include <string>

DLL_CPPCLI_LIB_API bool ShowWinFormsDialog(std::function<std::wstring(const std::wstring &)> stringReverser);