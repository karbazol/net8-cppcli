This repository is for reproduction of a crash in an c++/cli mfc interop scenario on .NET 8.

* To reproduce, open the solution file and build everything.
* Choose `cpp-mfcapp` as startup project
* Start it and choose *Test|Open WinForms Control Embedding View* from the app's main menu.
* Now the app crashes


It is also intended to play around with a couple of interop scenarios between Windows Forms, C++ 32 Apps and C++ MFC Apps using C++/CLI as interop layer. All on .NET 8 on the managed side.
For more detailed background information see `cpp-cli-net8-evaluation.md`.
