#include "pch.h"

#include "cppcli-lib.h"

#include <msclr/marshal_cppstd.h>
using namespace System;
using namespace msclr::interop;

ref class StringReverserWrapper : winforms_lib::IStringReverser
{
public:
  StringReverserWrapper(std::function<std::wstring(const std::wstring&)>& stringReverser)
    : mStringReverser(stringReverser)
  {}

  virtual System::String^ Reverse(System::String^ str)
  {
    std::wstring nativeString = marshal_as<std::wstring>(str);
    std::wstring nativeStringReversed = mStringReverser(nativeString);
    return marshal_as<System::String ^>(nativeStringReversed);
  }

  std::function<std::wstring(const std::wstring&)>& mStringReverser;
};

bool ShowWinFormsDialog(std::function<std::wstring(const std::wstring&)> stringReverser)
{
  StringReverserWrapper stringReverserWrapper(stringReverser);

  winforms_lib::Form1^ form = gcnew winforms_lib::Form1();
  form->StringReverser = %stringReverserWrapper;

  System::Windows::Forms::DialogResult dialogResult = form->ShowDialog();
  return dialogResult == System::Windows::Forms::DialogResult::OK;
}
