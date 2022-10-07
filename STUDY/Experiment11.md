# Experiment11

## Purpose

Inspect IME class window of Notepad with 'Search' dialog.

## Platform

Windows 2003.

## Tools

- WinSpy++
- MessageSpy

## Window Handles

- HWND 000A00E0, window class name "Notepad", window text "ñ≥ëË - ÉÅÉÇí†"
- HWND 000E00D4, window class name "#32770", window text "åüçı" ("Find" in Japanese)
- HWND 000B012A, window class name "IME", window text "Default IME"
- HWND 000A0108, window class name "imejpstmain81", window text "imejpstmain81"

## Window Hierarchy

- HWND 000A00E0 ("Notepad") is top-level window.
- HWND 000E00D4 ("#32770") is owned by HWND 000A00E0 ("Notepad")
- HWND 000B012A ("IME") is owned by HWND 000E00D4 ("Find" dialog).
- HWND 000A0108 ("imejpstmain81") is owned by HWND 000B012A.

## Screenshots

- [winxpjp/IME-class-7.png](winxpjp/IME-UI-7.png)
