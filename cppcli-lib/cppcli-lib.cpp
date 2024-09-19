#include "pch.h"

#include "cppcli-lib.h"

using namespace System;

bool ShowWinFormsDialog()
{
  winforms_lib::Form1^ form = gcnew winforms_lib::Form1();
  System::Windows::Forms::DialogResult dialogResult = form->ShowDialog();
  return dialogResult == System::Windows::Forms::DialogResult::OK;
}
