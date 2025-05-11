#pragma once

#define ID_STARTIMEMENU 1000

struct tagIMEMENUNODE;

typedef struct tagIMEMENUITEM
{
    IMEMENUITEMINFO m_Info;
    UINT m_nRealID;
    struct tagIMEMENUNODE *m_pSubMenu;
} IMEMENUITEM, *PIMEMENUITEM;

typedef struct tagIMEMENUNODE
{
    struct tagIMEMENUNODE *m_pNext;
    INT m_nItems;
    IMEMENUITEM m_Items[ANYSIZE_ARRAY];
} IMEMENUNODE, *PIMEMENUNODE;

PIMEMENUNODE CreateImeMenu(IN HWND hWnd, IN HIMC hIMC, IN OUT PIMEMENUITEMINFO lpImeParentMenu OPTIONAL, IN BOOL bRightMenu);
INT GetRealImeMenuID(IN const IMEMENUNODE *pMenu, INT nID);
HMENU MenuFromImeMenu(IN const IMEMENUNODE *pMenu);
VOID CleanupImeMenus(VOID);

DWORD
GetImeMenuItemsBase(
    IN HIMC hIMC,
    IN DWORD dwFlags,
    IN DWORD dwType,
    IN OUT PIMEMENUITEMINFO lpImeParentMenu OPTIONAL,
    OUT PIMEMENUITEMINFO pImeMenuItems OPTIONAL,
    IN DWORD cbItems);

DWORD
GetImeMenuItems(
    IN HIMC hIMC,
    IN DWORD dwFlags,
    IN DWORD dwType,
    IN OUT PIMEMENUITEMINFO lpImeParentMenu OPTIONAL,
    OUT PIMEMENUITEMINFO pImeMenuItems OPTIONAL,
    IN DWORD cbItems);

void *Alloc(size_t size);
void Free(void *ptr);
