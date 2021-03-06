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
#include <Windows.h>
#include "../Helpers/Memory.hpp"
#include "../ModLoader/inc/ModLoader.hpp"

MOD_NAMESPACE_BEGIN() {
   void MODLOADER_API OnLoad() {
      MODLOADER_MAKE_FUNCTION_ACCESSIBLE();
      Memory::Init();
      Memory::writeJMP(0x586AA1, false, // right after "if (this.ShouldSuppressBreathEffect()) return;"
                       0x586B5D, false  // "if (GameManager.GetPlayerAnimationComponent().IsAiming() && GameManager.GetFreezingComponent().IsFreezing())"
      );
   }
} MOD_NAMESPACE_END()

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
   MODLOADER_DISABLE_THREAD_CALLS(hModule, reason);
   return TRUE;
}
