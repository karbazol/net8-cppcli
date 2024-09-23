SDK Version ist 8.0.302

## Projekt-Setup

Möglichst viel mit der dotnet cli machen. CMake erstmal nicht.

Zunächst ein neues Verzeichnis anlegen und dort hineinwechseln:
```bash
mkdir net8-cppcli
cd net8-cppcli
```

Anlegen des WinForms-Bibliothek-Projekts `winforms-proj.csproj` im entsprechen Unterordner:
```bash
dotnet new winformslib -o winforms-lib
``` 

Die Projektdatei hat folgenden Inhalt:
```xml 
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>WinExe</OutputType>
    <TargetFramework>net8.0-windows</TargetFramework>
    <RootNamespace>winforms_proj</RootNamespace>
    <Nullable>enable</Nullable>
    <UseWindowsForms>true</UseWindowsForms>
    <ImplicitUsings>enable</ImplicitUsings>
  </PropertyGroup>
</Project>
```

Anlegen einer Solution und Hinzufügen des Projekts
```
dotnet new solution -n net8-cppcli
dotnet sln net8-cppcli.sln add winforms-lib/winforms-lib.csproj
```

Öffnen mit Visual Studio

Hinzufügen einer c++/cli-Bibliothek `cppcli-lib` über die Projektvorlage `CLR Class Library (.NET)` (nicht `CLR Class Library (.NET Framework)`). Hinzufügen einer Referenz von `cppcli-proj` auf `winforms-proj`.
Wesentliche Inhalte der c++/cli-Projektdatei:

```xml
<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup Label="ProjectConfigurations">
    <ProjectConfiguration Include="Debug|Win32">
      <Configuration>Debug</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|Win32">
      <Configuration>Release</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Debug|x64">
      <Configuration>Debug</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|x64">
      <Configuration>Release</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
  </ItemGroup>
  <PropertyGroup Label="Globals">
    <VCProjectVersion>17.0</VCProjectVersion>
    <EnableManagedPackageReferenceSupport>true</EnableManagedPackageReferenceSupport>
    <ProjectGuid>{8A09BB41-67DE-4AF4-A6E6-C493A6CBFE66}</ProjectGuid>
    <Keyword>NetCoreCProj</Keyword>
    <RootNamespace>cppcliproj</RootNamespace>
    <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>
    <TargetFramework>net8.0</TargetFramework>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'" Label="Configuration">
    <ConfigurationType>DynamicLibrary</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
    <CLRSupport>NetCore</CLRSupport>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'" Label="Configuration">
    ...
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'" Label="Configuration">
    ...
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'" Label="Configuration">
    ...
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ImportGroup Label="ExtensionSettings">
  </ImportGroup>
  <ImportGroup Label="Shared">
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <PropertyGroup Label="UserMacros" />
  <PropertyGroup />
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <ClCompile>
      <PrecompiledHeader>Use</PrecompiledHeader>
      <PrecompiledHeaderFile>pch.h</PrecompiledHeaderFile>
      <WarningLevel>Level3</WarningLevel>
      <PreprocessorDefinitions>_DEBUG;%(PreprocessorDefinitions)</PreprocessorDefinitions>
    </ClCompile>
    <Link>
      <AdditionalDependencies />
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <ClCompile>
      ...
    </ClCompile>
    <Link>
      <AdditionalDependencies />
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <ClCompile>
      ...
    </ClCompile>
    <Link>
      <AdditionalDependencies />
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <ClCompile>
      ...
    </ClCompile>
    <Link>
      <AdditionalDependencies />
    </Link>
  </ItemDefinitionGroup>
  <ItemGroup>
    <ClInclude Include="cppcli-proj.h" />
    <ClInclude Include="pch.h" />
    <ClInclude Include="Resource.h" />
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="AssemblyInfo.cpp" />
    <ClCompile Include="cppcli-proj.cpp" />
    <ClCompile Include="pch.cpp">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">Create</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">Create</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">Create</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|x64'">Create</PrecompiledHeader>
    </ClCompile>
  </ItemGroup>
  <ItemGroup>
    <ResourceCompile Include="app.rc" />
  </ItemGroup>
  <ItemGroup>
    <Image Include="app.ico" />
  </ItemGroup>
  <ItemGroup>
    <ProjectReference Include="..\winforms-lib\winforms-lib.csproj">
      <Project>{7a85c0bc-32eb-4317-b766-cf1becc48cc7}</Project>
    </ProjectReference>
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>
```

Hinzufügen eines Win32-Projekts `cpp-desktopapp` über die Projektvorlage `Windows Desktop Application`. Hinzufügen einer Referenz von `cpp-desktopapp` auf `cppcli-lib`.
Generierte Projektdatei:

```XML
<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup Label="ProjectConfigurations">
    <ProjectConfiguration Include="Debug|Win32">
      <Configuration>Debug</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|Win32">
      ...
    </ProjectConfiguration>
    <ProjectConfiguration Include="Debug|x64">
      ...
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|x64">
      ...
    </ProjectConfiguration>
  </ItemGroup>
  <PropertyGroup Label="Globals">
    <VCProjectVersion>17.0</VCProjectVersion>
    <Keyword>Win32Proj</Keyword>
    <ProjectGuid>{45f8d951-1a45-433e-8844-7b9d5ccc416c}</ProjectGuid>
    <RootNamespace>cppdesktopapp</RootNamespace>
    <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'" Label="Configuration">
    ...
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'" Label="Configuration">
    ...
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'" Label="Configuration">
    ...
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ImportGroup Label="ExtensionSettings">
  </ImportGroup>
  <ImportGroup Label="Shared">
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <PropertyGroup Label="UserMacros" />
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <ClCompile>
      <WarningLevel>Level3</WarningLevel>
      <SDLCheck>true</SDLCheck>
      <PreprocessorDefinitions>WIN32;_DEBUG;_WINDOWS;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <ConformanceMode>true</ConformanceMode>
    </ClCompile>
    <Link>
      <SubSystem>Windows</SubSystem>
      <GenerateDebugInformation>true</GenerateDebugInformation>
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    ...
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    ...
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    ...
  </ItemDefinitionGroup>
  <ItemGroup>
    <ClInclude Include="cpp-desktopapp.h" />
    <ClInclude Include="framework.h" />
    <ClInclude Include="Resource.h" />
    <ClInclude Include="targetver.h" />
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="cpp-desktopapp.cpp" />
  </ItemGroup>
  <ItemGroup>
    <ResourceCompile Include="cpp-desktopapp.rc" />
  </ItemGroup>
  <ItemGroup>
    <Image Include="cpp-desktopapp.ico" />
    <Image Include="small.ico" />
  </ItemGroup>
  <ItemGroup>
    <ProjectReference Include="..\cppcli-lib\cppcli-lib.vcxproj">
      <Project>{6e65105c-0fac-4a12-b855-16fc304d4c65}</Project>
    </ProjectReference>
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>
```

Konfigurationsmatrix:

winforms-lib: `Debug`, `Release` x `AnyCPU`
cpp-clilib: `Debug`, `Release` x `x64`, `Win32`
cpp-desktopapp: `Debug`, `Release` x `x64`, `Win32`

Solution: `Debug`, `Release` x `AnyCPU`, `x64`, `x86`   (`AnyCPU` mappt bei den cpp-Projekten auf `x64`)

## Anzeige eines Dialogs vom desktopapp-Projekt aus

Hinzufügen eines neuen Dialogs `Form1` mit `Ok`-Button und `Cancel`-Button im `winforms-lib`-Projekt. Verknüpfung der Form-Eigenschaften `buttonOk`, `buttonCancel` mit den beiden Buttons. 

```C#
namespace winforms_lib
{
  public partial class Form1 : Form
  {
    ...
  }
}  
```

Hinzufügen einer Aufrufsmethode, um den Dialog anzuzeigen, im `cppcli-lib`-Projekt. Im Header kein c++/cli:

```c++
bool DLL_CPPCLI_LIB_API ShowWinFormsDialog();
```

Dabei DLL_CPPCLI_LIB_API entweder als __declspec(dllexport) im Projekt `cppcli-lib` bzw. als __declspec(dllimport) im Projekt `cpp-desktopapp` definieren. 

```c++
using namespace System;

bool ShowWinFormsDialog()
{
  winforms_lib::Form1^ form = gcnew winforms_lib::Form1();
  System::Windows::Forms::DialogResult dialogResult = form->ShowDialog();
  return dialogResult == System::Windows::Forms::DialogResult::OK;
}
```

Im `cpp-desktopapp`-Projekt bei den Include-Verzeichnissen noch `../cppcli-lib` ergänzen. Den Header `#include "cppcli-lib.h"` inkludieren und anstelle des About-Dialogs die Form aufrufen.
Damit es kein unresolved external gibt, im Projekt `cppcli-lib` unter Linker / General / Ignore Import Library = No setzen..

ToDo : Ok-Button does not close the form.
