# Experiment09

## Purpose

Inspect IME class window of Notepad with 'Search' dialog.

## Platform

Windows 2003.

## Tools

- WinSpy++
- MessageSpy

## Window Handles

- HWND 00070072, window class name "Notepad", window text "Untitled - Notepad"
- HWND 0004023C, window class name "#32770", window text "Find"
- HWND 000F0148, window class name "IME", window text "Default IME"
- HWND 0009010C, window class name "MSCTFIME UI", window text "M???..."

## Window Hierarchy

- HWND 00070072 ("Notepad") is the top-level window.
- HWND 0004023C ("#32770") is owned by of HWND 00070072.
- HWND 000F0148 ("IME") is owned by HWND 0004023C.
- HWND 0009010C ("MSCTFIME UI") is owned by HWND 000F0148.

## Screenshots

- [win2k3/IME-UI-7.png](win2k3/IME-UI-7.png)
