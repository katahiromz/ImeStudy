# IME/IMM Study

## What are the window classes being used for IME support?

### Windows 10

- CONFIRMED: There is the IME window class whose window class name is `"IME"`.
- CONFIRMED: There is the IME UI window class whose window class name is `"MSCTFIME UI"`.

Evidence: [Experiment05.md](Experiment05.md).

### Windows 2003

- CONFIRMED: There is the IME window class whose window class name is `"IME"`.
- CONFIRMED: There is the IME UI window class whose window class name is `"MSCTFIME UI"`.

Evidence: [Experiment01.md](Experiment01.md).

### Windows XP Japanese

- CONFIRMED: There is the IME window class whose window class name is `"IME"`.
- CONFIRMED: There is the IME UI window class whose window class name is `"imejpstmain81"`.

Evidence: [Experiment07.md](Experiment07.md).

### Windows 2000 Japanese

- CONFIRMED: There is the IME window class whose window class name is `"IME"`.
- CONFIRMED: There is the IME UI window class whose window class name is `"msime98main"`.

Evidence: [Experiment03.md](Experiment03.md).

## What is `"IME"` window class?

### Windows 10

- CONFIRMED: It has the window class name of `"IME"`.
- CONFIRMED: It has `WS_POPUP | WS_DISABLED | WS_CLIPSIBLINGS` window styles.
- CONFIRMED: It has zero extended styles.
- CONFIRMED: It has zero class styles.
- CONFIRMED: It has the window text of `"Default IME"`.
- CONFIRMED: The process ID of the `IME` window is same as the process ID of the application.
- CONFIRMED: The the thread ID of the `IME` window is same as the thread ID of the application.

Evidence: [Experiment05.md](Experiment05.md).

### Windows 2003

- CONFIRMED: It has the window class name of `"IME"`.
- CONFIRMED: It has `WS_POPUP | WS_DISABLED | WS_CLIPSIBLINGS` window styles.
- CONFIRMED: It has zero extended styles.
- CONFIRMED: It has zero class styles.
- CONFIRMED: It has the window text of `"Default IME"`.
- CONFIRMED: The process ID of the `IME` window is same as the process ID of the application.
- CONFIRMED: The the thread ID of the `IME` window is same as the thread ID of the application.

Evidence: [Experiment01.md](Experiment01.md).

### Windows XP Japanese

- CONFIRMED: It has the window class name of `"IME"`.
- CONFIRMED: It has `WS_POPUP | WS_DISABLED | WS_CLIPSIBLINGS` window styles.
- CONFIRMED: It has zero extended styles.
- CONFIRMED: It has zero class styles.
- CONFIRMED: It has the window text of `"Default IME"`.
- CONFIRMED: The process ID of the `IME` window is same as the process ID of the application.
- CONFIRMED: The the thread ID of the `IME` window is same as the thread ID of the application.

Evidence: [Experiment07.md](Experiment07.md).

### Windows 2000 Japanese

- CONFIRMED: It has the window class name of `"IME"`.
- CONFIRMED: It has `WS_POPUP | WS_DISABLED | WS_CLIPSIBLINGS` window styles.
- CONFIRMED: It has zero extended styles.
- CONFIRMED: It has zero class styles.
- CONFIRMED: It has the window text of `"Default IME"`.
- CONFIRMED: The process ID of the `IME` window is same as the process ID of the application.
- CONFIRMED: The the thread ID of the `IME` window is same as the thread ID of the application.

Evidence: [Experiment03.md](Experiment03.md).

## What is the IME UI window?

### Windows 10

- CONFIRMED: Its window class is `"MSCTFIME UI"`.
- CONFIRMED: It has `WS_POPUP | WS_DISABLED | WS_CLIPSIBLINGS` window styles.
- CONFIRMED: It has zero extended styles.
- CONFIRMED: It has `CS_IME | CS_GLOBALCLASS` class styles.
- CONFIRMED: It has the window text of `"MSCTFIME UI"`.
- CONFIRMED: The process ID of it is same as the process ID of the application.
- CONFIRMED: The thread ID of it is same as the thread ID of the application.

Evidence: [Experiment06.md](Experiment06.md).

### Windows 2003

- CONFIRMED: Its window class is `"MSCTFIME UI"`.
- CONFIRMED: It has `WS_POPUP | WS_DISABLED | WS_CLIPSIBLINGS` window styles.
- CONFIRMED: It has zero extended styles.
- CONFIRMED: It has `CS_IME | CS_GLOBALCLASS` class styles.
- CONFIRMED: It has the window text of `"M????"`.
- CONFIRMED: The process ID of it is same as the process ID of the application.
- CONFIRMED: The thread ID of it is same as the thread ID of the application.

Evidence: [Experiment02.md](Experiment02.md).

### Windows XP Japanese

- CONFIRMED: Its window class is `"imejpstmain81"`.
- CONFIRMED: It has `WS_POPUP | WS_DISABLED | WS_CLIPSIBLINGS` window styles.
- CONFIRMED: It has zero extended styles.
- CONFIRMED: It has `CS_IME | CS_HREDRAW | CS_VREDRAW` class styles.
- CONFIRMED: It has the window text of `"imejpstmain81"`.
- CONFIRMED: The process ID of it is same as the process ID of the application.
- CONFIRMED: The thread ID of it is same as the thread ID of the application.

Evidence: [Experiment08.md](Experiment08.md).

### Windows 2000 Japanese

- CONFIRMED: Its window class is `"msime98main"`.
- CONFIRMED: It has `WS_POPUP | WS_DISABLED | WS_CLIPSIBLINGS` window styles.
- CONFIRMED: It has zero extended styles.
- CONFIRMED: It has `CS_IME | CS_HREDRAW | CS_VREDRAW` class styles.
- CONFIRMED: It has the window text of `"msime98main"`.
- CONFIRMED: The process ID of it is same as the process ID of the application.
- CONFIRMED: The thread ID of it is same as the thread ID of the application.

Evidence: [Experiment04.md](Experiment04.md).

## How is the window hierarchy?

### Windows 10

- CONFIRMED: The GUI application has only one `"IME"` class window.
- CONFIRMED: The foreground window of the application owns an `"IME"` class window.
- CONFIRMED: If the focus was moved, then the application's `"IME"` window will be also moved.
- CONFIRMED: The `"IME"` class window owns the `"MSCTFIME UI"` class window.

Evidence: [Experiment05.md](Experiment05.md).

### Windows 2003

- CONFIRMED: The GUI application has only one `"IME"` class window.
- CONFIRMED: The foreground window of the application owns an `"IME"` class window.
- CONFIRMED: If the focus was moved, then the application's `"IME"` window will be also moved.
- CONFIRMED: The `"IME"` class window owns the `"MSCTFIME UI"` class window.

Evidence: [Experiment01.md](Experiment01.md).

### Windows XP Japanese

- CONFIRMED: The GUI application has only one `"IME"` class window.
- CONFIRMED: The foreground window of the application owns an `"IME"` class window.
- CONFIRMED: If the focus was moved, then the application's `"IME"` window will be also moved.
- CONFIRMED: The `"IME"` class window owns the `"imejpstmain81"` class window.

Evidence: [Experiment07.md](Experiment07.md).

### Windows 2000 Japanese

- CONFIRMED: The GUI application has only one `"IME"` class window.
- NOT CONFIRMED: The foreground window of the application owns an `"IME"` class window.
- NOT CONFIRMED: If the focus was moved, then the application's `"IME"` window will be also moved.
- CONFIRMED: The `"IME"` class window owns the `"msime98main"` class window.

## What does `DefWindowProc` for IME support?

## The list of IMM functions?

- `ImmAssociateContext`
- `ImmAssociateContextEx`
- `ImmConfigureIME`
- `ImmCreateContext`
- `ImmCreateIMCC`
- `ImmCreateSoftKeyboard`
- `ImmDestroyContext`
- `ImmDestroyIMCC`
- `ImmDestroySoftKeyboard`
- `ImmDisableIME`
- `ImmDisableLegacyIME`
- `ImmDisableTextFrameService`
- `ImmEnumInputContext`
- `ImmEnumRegisterWord`
- `ImmEscape`
- `ImmGenerateMessage`
- `ImmGetCandidateList`
- `ImmGetCandidateListCount`
- `ImmGetCandidateWindow`
- `ImmGetCompositionFont`
- `ImmGetCompositionString`
- `ImmGetCompositionWindow`
- `ImmGetContext`
- `ImmGetConversionList`
- `ImmGetConversionStatus`
- `ImmGetDefaultIMEWnd`
- `ImmGetDescription`
- `ImmGetGuideLine`
- `ImmGetHotKey`
- `ImmGetIMCCLockCount`
- `ImmGetIMCCSize`
- `ImmGetIMCLockCount`
- `ImmGetIMEFileName`
- `ImmGetImeMenuItems`
- `ImmGetOpenStatus`
- `ImmGetProperty`
- `ImmGetRegisterWordStyle`
- `ImmGetStatusWindowPos`
- `ImmGetVirtualKey`
- `ImmInstallIME`
- `ImmIsIME`
- `ImmIsUIMessage`
- `ImmLockIMC`
- `ImmLockIMCC`
- `ImmNotifyIME`
- `ImmRegisterWord`
- `ImmReleaseContext`
- `ImmRequestMessage`
- `ImmReSizeIMCC`
- `ImmSetCandidateWindow`
- `ImmSetCompositionFont`
- `ImmSetCompositionString`
- `ImmSetCompositionWindow`
- `ImmSetConversionStatus`
- `ImmSetHotKey`
- `ImmSetOpenStatus`
- `ImmSetStatusWindowPos`
- `ImmShowSoftKeyboard`
- `ImmSimulateHotKey`
- `ImmUnlockIMC`
- `ImmUnlockIMCC`
- `ImmUnregisterWord`

## The list of IME functions?

- `ImeConfigure`
- `ImeConversionList`
- `ImeDestroy`
- `ImeEnumRegisterWord`
- `ImeEscape`
- `ImeGetImeMenuItems`
- `ImeGetRegisterWordStyle`
- `ImeInquire`
- `ImeProcessKey`
- `ImeRegisterWord`
- `ImeSelect`
- `ImeSetActiveContext`
- `ImeSetCompositionString`
- `ImeToAsciiEx`
- `ImeUnregisterWord`
- `NotifyIME`

## The list of standard IME messages?

- `WM_IME_STARTCOMPOSITION`
- `WM_IME_ENDCOMPOSITION`
- `WM_IME_COMPOSITION`
- `WM_IME_SETCONTEXT`
- `WM_IME_NOTIFY`
- `WM_IME_CONTROL`
- `WM_IME_COMPOSITIONFULL`
- `WM_IME_SELECT`
- `WM_IME_CHAR`
- `WM_IME_REQUEST`
- `WM_IME_KEYDOWN`
- `WM_IME_KEYUP`

## What is `imetip.dll`?

`imetip.dll` is a DLL file that is part of Microsoft IME TIP.

- Windows 10 has `imetip.dll` in `C:\Windows\WinSxS\wow64_microsoft-windows-d..me-eashared-coretip_31bf3856ad364e35_10.0.17134.1_none_69cbc7d426615b1b`.

## What is `imjptip.dll`?

`imjptip.dll` is a DLL file that is part of Japanese Microsoft IME TIP.

- Windows 10 has `imjptip.dll` in `C:\Windows\System32\IME\IMEJP`.

## What is `MSCTF.dll`?

`MSCTF.dll` is a DLL file that is the core runtime library of Text Services Framework (TSF).

- Windows 10 has `MSCTF.dll` in `C:\Windows\system32`.
