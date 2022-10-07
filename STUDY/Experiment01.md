# Experiment01

## Purpose

Inspect IME class window of Notepad.

## Platform

Windows 2003.

## Tools

- WinSpy++
- MessageSpy
- [../FocusCheck](../FocusCheck)

## Window Handles

- HWND 00070072, window class name "Notepad", window text "Untitled - Notepad"
- HWND 000B011E, window class name "Edit", window text ""
- HWND 000F0148, window class name "IME", window text "Default IME"
- HWND 0009010C, window class name "MSCTFIME UI", window text "M???..."

## Window Hierarchy

- HWND 00070072 ("Notepad") is the top-level window.
- HWND 000B011E ("Edit") is child window of HWND 00070072.
- HWND 000F0148 ("IME") is owned by HWND 00070072.
- HWND 0009010C ("MSCTFIME UI") is owned by HWND 000F0148.

## Screenshots

- [win2k3/IME-class-1.png](win2k3/IME-class-1.png)
- [win2k3/IME-class-2.png](win2k3/IME-class-2.png)
- [win2k3/IME-class-3.png](win2k3/IME-class-3.png)
- [win2k3/IME-class-4.png](win2k3/IME-class-4.png)
- [win2k3/IME-class-5.png](win2k3/IME-class-5.png)
- [win2k3/IME-class-6.png](win2k3/IME-class-6.png)
