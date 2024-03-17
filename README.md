# WinRAR 7.0 DLL Hijack
DLL Hijacking is possible in WinRAR 7.0 allowing you to execute code on a target machine and gain persistence. Attack requirements are Windows 11 and also WinRAR installed on the machine. You also need to be an administrator on the machine or be able to write to `C:\Program Files\WinRAR\`

WinRAR looks for a file called `amsi.dll` inside of the path `C:\Program Files\WinRAR\` if you analyse this with procmon you will see it returns the status "NAME NOT FOUND" meaning we can hijack it. All we have to do is create a new Visual Studio solution (PoC code has been provided here) and then copy the dll into the path `C:\Program Files\WinRAR\`. On Windows 11, WinRAR is loaded in the right click menu, so every time a user right clicks a file WinRAR file fire and so will the payload making it a perfect persistence technique. Same goes for is the user opens a .rar file or WinRAR itself.

## Steps to create DLL
1. Download Visual Studio
2. Create a new Dynamic Link Library solution make sure you select your programming language as C++
3. Copy and paste amsi.cpp from this repo into your solution
4. Build the DLL
5. Drag and drop the dll into the path `C:\Program Files\WinRAR` and close the file explorer
6. Congrats!

