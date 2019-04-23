XCOPY "..\sln\%1\VTFCmd\Win32\Release\VTFCmd.exe" "..\bin\x86\" /Y
XCOPY "..\sln\%1\VTFEdit\Win32\Release\VTFEdit.exe" "..\bin\x86\" /Y
XCOPY "..\sln\%1\VTFLib\Win32\Release\VTFLib.dll" "..\bin\x86\" /Y
XCOPY "..\sln\%1\VTFLib\Win32\Release\VTFLib.lib" "..\lib\x86\" /Y

XCOPY "..\sln\%1\VTFCmd\x64\Release\VTFCmd.exe" "..\bin\x64\" /Y
XCOPY "..\sln\%1\VTFEdit\x64\Release\VTFEdit.exe" "..\bin\x64\" /Y
XCOPY "..\sln\%1\VTFLib\x64\Release\VTFLib.dll" "..\bin\x64\" /Y
XCOPY "..\sln\%1\VTFLib\x64\Release\VTFLib.lib" "..\lib\x64\" /Y
