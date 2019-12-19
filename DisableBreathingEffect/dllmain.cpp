/*
   MIT License

   Copyright (c) 2019 Berkay Yigit <berkay2578@gmail.com>
       Copyright holder detail: Nickname(s) used by the copyright holder: 'berkay2578', 'berkayylmao'.

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

DWORD WINAPI Init(LPVOID) {
   DWORD64 gaBase = NULL;
   while (!gaBase) {
      gaBase = (DWORD64)GetModuleHandle(L"GameAssembly.dll");
      Sleep(1000);
   }

   DWORD64* pInst = (DWORD64*)(gaBase + 0x3C6BF40); // SaveGameSlots class instance offset
   while (!pInst || !*pInst)
      Sleep(250);

   *(DWORD*)(*(DWORD64*)(_Notnull_ *pInst + 0xB8) + 0x3C) = 999;
   return FALSE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
   if (reason == DLL_PROCESS_ATTACH)
      CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Init, NULL, 0, 0);
   return TRUE;
}