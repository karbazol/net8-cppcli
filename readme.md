This repository is for reproduction of a crash in an c++/cli mfc interop scenario on .NET 8.

* To reproduce, open the solution file and build everything.
* Choose `cpp-mfcapp` as startup project
* Start it and choose *Test|Open WinForms Control Embedding View* from the app's main menu.
* Now the app crashes

**Update** Crash was fixed by commit cd71c79a66efcf002901f3c45465eede6e22c323. A better fix is by commit ae6a172dd2ac4a37f4df9017dd7dbae9180dfe44.


It is also intended to play around with a couple of interop scenarios between Windows Forms, C++ 32 Apps and C++ MFC Apps using C++/CLI as interop layer. All on .NET 8 on the managed side.
For more detailed background information see `cpp-cli-net8-evaluation.md`.
