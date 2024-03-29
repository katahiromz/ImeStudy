﻿# Windows IME/IMM Study by katahiromz

このレポジトリは、WindowsのIME/IMMに関する研究をまとめたものです。

- [ARTICLES](ARTICLES/README.md) - 日本語の記事です。
- [STUDY](STUDY/README.md) - 研究らしきものです。

## What is IME?

IME is Input Method Editor, that is text conversion software for Far East Asian Windows users.
IME allows the Far East Asian users to input Far East Asian text.

The body of an IME is a DLL file that is registered as an IME in the operating system.
An IME can provide the functions whose names begin with `"Ime"`, and `NotifyIME` function.

Usually, the IME software has to provide its IME installer to register itself into the system.

For more details, see IME Hackerz (`REF011` and `REF012`).

## What is IMM?

IMM is Input Method Manager for Windows, that provides the interface between the user and an IME software.

## What is IMM32?

IMM32 is 32-bit IMM for Windows. That is a DLL file that is located in `C:\Windows\system32` as the name of "imm32.dll".

IMM32 provides API functions whose names begin with `"Imm"`. For more details, see IME Hackerz.

## How to use IMM32 in my program?

First, please include `<imm.h>` and link to `imm32.dll` as follows:

```c
#include <windows.h>
#include <imm.h>
#pragma comment(lib, "imm32.lib")
```

And then use the following basic form:

```c
HIMC hImc = ImmGetContext(hWnd);
...(Use IMM functions against hImc)...
ImmReleaseContext(hWnd, hImc);
```

The IMM function has a name that begins with `Imm`, those are listed at https://katahiromz.web.fc2.com/colony3rd/imehackerz/en/functions.html .

## What is "keyboard layout"?

The key code system differs depending on the keyboard or the keyboard language.
The position of the physical key may change.
Also, the key code mapping may change.

Usually, Japanese people uses Japanese keyboards.
Chinese people uses Chinese or English keyboards.
Korean people uses Korean keyboards.
Japanese user doesn't want to use English keyboard to input Japanese text.

## What is Chinese?

That is Asian people and/or languages, that is mainly living in the continent of Far East.
They use Chinese characters.
Many Chinese are not Japanese nor Korean.

See also `REF020`.

## What is Japanese?

That is Asian people and/or languages, that is mainly living in the islands of Far East.
They use Hiragana, Katakana, Kanji and English characters.
Many Japanese are not Chinese nor Korean.

See also `REF021`.

## What is Korean?

That is Asian people and/or language, that is mainly living in the peninsula of Far East.
They use Hangul characters (like 김정은) and English characters.
Many Korean are not Chinese nor Japanese.

See also `REF022`.

## What is Zenkaku or Hankaku?

A Hankaku (半角) character is a single-byte character in Shift_JIS (except UTF-8).
A non-Hankaku character is a Zenkaku (全角) character (in Traditional Japanese).
Traditionally, a non-single-byte character (in Shift_JIS encoding) has double width of a Hankaku character.
A Japanese fixed-width font should follow this traditional rule.

## What is Hiragana and Katakana?

- Hiragana (ひらがな) is a Japanese phonetic character collection (like あいうえお etc.).
- Katakana (カタカナ) is a Japanese phonetic character collection (like アイウエオ etc.).

## Why so many characters in Japanese?

Japanese text was born as a domestic international language through exchanges with China and neighboring countries.

1. Japanese didn't have any characters in the initial time. Japanese was sounds only.
2. The character of Katakana is derived from part(s) of Chinese Kanji, to write pronunciation of foreign word.
3. The character of Hiragana is derived from a deformation of Chinese Kanji, to write Japanese word.
4. Many Kanji characters also continued to be used frequently.

## What is Kana?

Kana (かな/カナ) is Hiragana and/or Katakana.

## What is Kanji?

The Kanji (漢字) characters in Japanese originate on the Chinese characters (like 亜阿唖).

## What is Kanji radical?

The Kanji radical (部首) is a systematic component of the Chinese character (or a Kanji character).

## What is Romaji conversion?

Romaji conversion (ローマ字変換) is a translation from English alphabet text into Kana character text.

## What is Kana-Kanji conversion?

Kana-Kanji conversion (かな漢字変換) is a conversion from Kana text into Kanji or something text.
A normal Japanese keyboard cannot type the Kanji characters directly.

## How is the Japanese keyboard?

The current Japanese keyboard standard is 109-keyboard.
It can type English alphabet and Hiragana characters, and some Japanese symbols and punctuations.
Additionally it has the `VK_KANJI`, `VK_KANA`, `VK_CONVERT`, and `VK_NONCONVERT` virtual keys.

- `VK_KANJI` (半角／全角) key is Hankaku/Zenkaku key to toggle Hankaku input mode and Zenkaku input mode.
- `VK_KANA` (かな) key is Kana key to begin the Kana (Hiragana and Katakana) input or toggle the Hiragana mode and the Katakana mode. These two modes are exclusive.
- `VK_CONVERT` (変換) is Convert key to convert the text.
- `VK_NONCONVERT` (無変換) is Don't-Convert key to revert conversion.

Some punctuation key mapping differs from English key mapping.

## How is the Chinese keyboard?

It can type English alphabet and the Chinese radical symbols.
Chinese keyboard is usually compatible to English keyboard.
Optionally, the Chinese radical symbols are printed on key tops.

## How is the Korean keyboard?

It can type English alphabet and the Hangul radical symbols.
Additionally, it has `VK_HANGUL`, `VK_JUNJA` and `VK_HANJA` virtual keys.

- `VK_HANGUL` is the Hangul input mode key (same as `VK_KANA`).
- `VK_JUNJA` is the Junja mode key.
- `VK_HANJA` is the Hanja mode key.

## How to input Japanese text?

A normal Japanese keyboard cannot type the Kanji characters directly.
The Japanese user inputs the Hiragana text (or Romaji-converted text) into IME and converts into Kanji or something text by the IME.

There is Romaji input mode and Kana input mode. These modes are exclusive. You can toggle these modes by `Alt+VK_KANA` key.
In Romaji input mode, typing Alphabet key makes translation from English Alphabet to Kana.
In Kana input mode, typing actual Hiragana key makes Hiragana character input.

To begin Japanese text, press `Alt+VK_KANJI` (or simply `VK_KANJI` in new Windows).
It enables Zenkaku mode and "あ" will be displayed on Taskbar or IME bar.
Pressing `Alt+VK_KANJI` again, it disables Zenkaku mode and "A" will be displayed on Taskbar or IME bar (Hankaku mode).

In Zenkaku mode, the Zenkaku characters that the user typed is displayed with underlined text (indeterminated composition text).
Then `Space` key or `VK_CONVERT` key makes Kana-Kanji conversion of that text.
Then the conversion candidates will be displayed with highlighted text.
Pressing `Space` or `VK_CONVERT` key again makes next Kana-Kanji conversion (it might show the list of the candidates).
Pressing `Enter` key commits the conversion text and that the selected candidate text will be actually entered the text box.
`Esc` key in Zenkaku mode makes cancellation of conversion.

## How to input Chinese text?

The Chinese user enters the Kanji radicals into IME.
The IME in Kanji mode automatically converts them into Kanji characters.

## Where is free Japanese IME?

See `REF013` (`mzimeja`).

## What is `DefWindowProc`?

`DefWindowProc` is the default window procedure.
There are two versions of it, as `DefWindowProcA` (ANSI version) and `DefWindowProcW` (Unicode version).
If the application window doesn't process the window message, then the window message will be processed by `DefWindowProc`.

## What is `EDIT` control?

The `EDIT` control is a text box, that is a child window whose window class name is `"Edit"`.

## What is standard IME message?

The standard IME messages are the Windows messages whose names begin with `"WM_IME_"`.

## What is Cicero?

Cicero is the code name of TSF.

## What is TSF?

TSF stands for "Text Services Framework".
TSF appears on Windows XP and later.
It has many other names, such as "Text Framework", "Text Services", "Text Frame Service" etc.
TSF is an empowered framework over IMM32.
TSF has COM (Component Object Model)-based design.

Old IMM32-based IME runs under "CUAS" emulation layer of TSF.
New IMM32 has `ImmDisableTextFrameService` API to disable TSF in the thread. See `REF024`.

## What is CUAS?

CUAS (Cicero Unaware Application Support) is an emulation layer that connects between the old IMM32-based application and a TSF TIP.

## What is COM (Component Object Model)?

See `REF023`.

## What does an IME installer?

It copys the IME-related files into the system, writes some settings in the registry, and call the `ImmInstallIME` function.

## What is registry key `"Run"`?

Registry key `"Run"` is as follows:

- In cases of Windows 95/98/Me: `"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run"`
- In the other cases: `"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run"`

This registry key contains the list of the registered start-up entries.
The key of an entry is the start-up program name. The value of an entry is a start-up command line.

## What is `internat.exe`?

`internat.exe` is an old program that is called "international keyboard/language indicator applet".
Windows 95, Windows 98, Windows Me, and Windows 2000 had `internat.exe`.
This program can display and choose a keyboard / IME from notification area of task bar.
It creates an invisible window `"Indicator"`.
It is a start-up program.
Some keyboard/IME settings can register `internat.exe` to registry key `"Run"`.
It manages keyboard layout list.

## What is `ctfmon.exe`?

`ctfmon.exe` is Language Bar front-end and a replacement of `internat.exe`.
This program can also display and choose a keyboard / IME from Language Bar.
`ctfmon.exe` hates `internat.exe`.
`ctfmon.exe` kills `internat.exe` process, `"Indicator"` window, and registry key `"Run"` entry of `internat.exe`.
`ctfmon.exe` is a start-up program.
`ctfmon.exe` registers itself as a start-up program to registry key `"Run"`.

See `$(REACTOS)/base/applications/ctfmon` .

## What is `HKL`?

A handle of keyboard layout.

The LOWORD of an HKL is a language ID.

```txt
#define IS_IME_HKL(hKL)     ((((ULONG_PTR)(hKL)) & 0xF0000000) == 0xE0000000)
#define IS_SPECIAL_HKL(hKL) ((((ULONG_PTR)(hKL)) & 0xF0000000) == 0xF0000000)
```

If `IS_IME_HKL(hKL)` is `TRUE`, then `hKL` is a handle for an IME keyboard layout.
If `IS_SPECIAL_HKL(hKL)` is `TRUE`, then `hKL` is a handle for a special keyboard layout.

See `$(REACTOS)/dll/cpl/input/layout_list.c` and registry key `"Keyboard Layouts"` for details.

## What is registry key `"Keyboard Layouts"`?

The registry key `"Keyboard Layouts"` is located at:

- `HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Keyboard Layouts` .

See `$(REACTOS)/dll/cpl/input/layout_list.c`.

## What is a keyboard layout list?

A "keyboard layout list" is the list of HKLs that can obtain from `USER32!GetKeyboardLayoutList` function.
`internat.exe` manages the keyboard layout list.

## What is CTF?

CTF stands for "Collaborative Translation Framework".

CTF provides `msctf.dll`, `msctfime.ime`, CTF IMEs etc.

## What is IMM IME?

It is a DLL file that contains the following exported functions:

- `ImeInquire`
- `ImeConversionList`
- `ImeRegisterWord`
- `ImeUnregisterWord`
- `ImeGetRegisterWordStyle`
- `ImeEnumRegisterWord`
- `ImeConfigure`
- `ImeDestroy`
- `ImeEscape`
- `ImeProcessKey`
- `ImeSelect`
- `ImeSetActiveContext`
- `ImeToAsciiEx`
- `NotifyIME`
- `ImeSetCompositionString`
- `ImeGetImeMenuItems`

And it must have a version info in the following conditions (See `IMM32!ImmLoadLayout`):

- The `FILETYPE` value must be `VFT_DRV` (`0x3`).
- The `FILESUBTYPE` value must be `VFT2_DRV_INPUTMETHOD` (`0xB`).
- The `StringFileInfo` block must contain correct codepage, language, and `FileDescription` values.

Usually an installed IME file is in `%WINDIR%\system32`.
The filename extension is `".ime"`.

See `$(REACTOS)/sdk/include/reactos/imetable.h` and `$(REACTOS)/dll/win32/imm32/utils.c` .

## What is CTF IME?

It is an extension of "IMM IME". It contains the IMM IME functions and the following exported functions:

- `CtfImeInquireExW`
- `CtfImeSelectEx`
- `CtfImeEscapeEx`
- `CtfImeGetGuidAtom`
- `CtfImeIsGuidMapEnable`

See `$(REACTOS)/sdk/include/reactos/imetable.h` and `$(REACTOS)/dll/win32/imm32/ctf.c` .

## How to export functions?

Just define the functions and add a `.DEF` file to your DLL file project.

## What is TIP?

TIP stands for "Text Input Processor".
The new-style IME of new design is called as TIP.
A TIP is a DLL file, that is built with many COM objects and interfaces.
The filename extension of a TIP is usually `.dll`.
Strictly saying, a TIP is not an IME file (Not IMM IME nor CTF IME!).

## What is `msctfime.ime`?

The system IME file `msctfime.ime` is the back-end of TIP.
`msctfime.ime` communicates with the current TIP.

You can find the name of `msctfime.ime` in registry key:

- `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\IMM`

of Windows XP/2003.

See `$(REACTOS)/dll/ime/msctfime` .

## What is `msutb.dll`?

`msutb.dll` is the back-end of TIP Bar.

## What is `msctf.dll`?

`msctf.dll` is the back-end of Language Bar.

See `$(REACTOS)/dll/win32/msctf` .

## Reference

- `REF000`: The Internet Archive: WayBack Machine: https://archive.org/web
- `REF001`: WineHQ (free Windows Emulator): https://www.winehq.org
- `REF002`: WineHQ Repository: https://github.com/wine-mirror/wine
- `REF003`: ReactOS (free Windows-compatible OS): https://www.reactos.org
- `REF004`: ReactOS Repository: https://github.com/reactos/reactos
- `REF005`: WineHQ IMM32 source: https://github.com/wine-mirror/wine/tree/master/dlls/imm32
- `REF006`: WineHQ USER32 source: https://github.com/wine-mirror/wine/tree/master/dlls/user32
- `REF007`: ReactOS IMM32 source: https://github.com/reactos/reactos/tree/master/dll/win32/imm32
- `REF008`: ReactOS USER32 source: https://github.com/reactos/reactos/tree/master/win32ss/user
- `REF009`: Win32 Multilingual IME Application Programming Interface Version 1.41 ([ime-api.pdf](ime-api.pdf))
- `REF010`: Win32 Multilingual IME Overview for IME Development Version 1.41 ([ime-overview.pdf](ime-overview.pdf))
- `REF011`: IME Hackerz (English): https://katahiromz.web.fc2.com/colony3rd/imehackerz/en
- `REF012`: IME Hackerz (Japanese): https://katahiromz.web.fc2.com/colony3rd/imehackerz/ja
- `REF013`: MZ-IME Japanese Input for Windows XP/2003 (mzimeja): https://github.com/katahiromz/mzimeja
- `REF014`: Wikipedia: Hiragana: https://en.wikipedia.org/wiki/Hiragana
- `REF015`: Wikipedia: Kanji: https://en.wikipedia.org/wiki/Kanji
- `REF016`: Wikipedia: Katakana: https://en.wikipedia.org/wiki/Katakana
- `REF017`: Wikipedia: Kanji: https://en.wikipedia.org/wiki/IME
- `REF018`: Wikipedia: Input method: https://en.wikipedia.org/wiki/Input_method
- `REF019`: Wikipedia: Keyboard layout: https://en.wikipedia.org/wiki/Keyboard_layout
- `REF020`: Wikipedia: Chinese language: https://en.wikipedia.org/wiki/Chinese_language
- `REF021`: Wikipedia: Japanese language: https://en.wikipedia.org/wiki/Japanese_language
- `REF022`: Wikipedia: Korean language: https://en.wikipedia.org/wiki/Korean_language
- `REF023`: Wikipedia: Component Object Model: https://en.wikipedia.org/wiki/Component_Object_Model
- `REF024`: Text Services Framework: https://docs.microsoft.com/ja-jp/windows/desktop/TSF/text-services-framework
- `REF025`: WinHier: Win32 spying utility: https://github.com/katahiromz/WinHier
- `REF026`: RisohEditor: Another free Win32 resource editor: https://github.com/katahiromz/RisohEditor
- `REF027`: MsgCrack: Code snippet for event handler: https://github.com/katahiromz/MsgCrack
- `REF028`: vkeycheck: Virtual Key checker: https://github.com/katahiromz/vkeycheck
- `REF029`: IME as a possible keylogger: https://www.virusbulletin.com/virusbulletin/2005/11/ime-possible-keylogger/
- `REF030`: dwendt/UniversalInject: https://github.com/dwendt/UniversalInject
- `REF031`: https://reactos.org/wiki/User:Alvinhochun/Localization/IME
- `REF032`: SampleIME: https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/IME/cpp/SampleIME
