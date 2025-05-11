#define IDM_HIRAGANA  100
#define IDM_FULL_KATAKANA 101
#define IDM_FULL_ASCII 102
#define IDM_HALF_KATAKANA 103
#define IDM_HALF_ASCII 104
#define IDM_ROMAN_INPUT 105
#define IDM_KANA_INPUT 106
#define IDM_ADD_WORD 107
#define IDM_RECONVERT 108
#define IDM_IME_PAD 109
#define IDM_PROPERTY 110
#define IDM_ABOUT 111

typedef struct tagMYMENUITEM
{
    INT nCommandID;
    LPCTSTR pszString;
    BOOL bDisabled;
    BOOL bChecked;
} MYMENUITEM, *PMYMENUITEM;
static const MYMENUITEM top_menu_items[] =
{
    {IDM_HIRAGANA, TEXT("IDM_HIRAGANA"), FALSE},
    {IDM_FULL_KATAKANA, TEXT("IDM_FULL_KATAKANA"), FALSE, TRUE},
    {IDM_FULL_ASCII, TEXT("IDM_FULL_ASCII"), FALSE},
    {IDM_HALF_KATAKANA, TEXT("IDM_HALF_KATAKANA"), FALSE},
    {IDM_HALF_ASCII, TEXT("IDM_HALF_ASCII"), FALSE},
    {-1, NULL},
    {IDM_ROMAN_INPUT, TEXT("IDM_ROMAN_INPUT"), FALSE},
    {IDM_KANA_INPUT, TEXT("IDM_KANA_INPUT"), FALSE},
    {-1, NULL},
    {IDM_ADD_WORD, TEXT("IDM_ADD_WORD"), TRUE},
    {IDM_RECONVERT, TEXT("IDM_RECONVERT"), TRUE},
    {IDM_IME_PAD, TEXT("IDM_IME_PAD"), FALSE},
    {-1, NULL},
    {IDM_PROPERTY, TEXT("IDM_PROPERTY"), TRUE},
    {IDM_ABOUT, TEXT("IDM_ABOUT"), FALSE},
};
DWORD WINAPI ImeGetImeMenuItems(HIMC hIMC, DWORD dwFlags, DWORD dwType,
                                LPIMEMENUITEMINFO lpImeParentMenu,
                                LPIMEMENUITEMINFO lpImeMenu, DWORD dwSize)
{
    DWORD ret = 0;

    if (lpImeMenu == NULL) {
        if (lpImeParentMenu == NULL) {
            ret = _countof(top_menu_items);
        }
        return ret;
    }

    if (lpImeParentMenu == NULL) {
        BOOL bOpen = TRUE;
        DWORD dwConversion = 0, dwSentence = 0;

        for (size_t i = 0; i < _countof(top_menu_items); ++i) {
            const MYMENUITEM *pItem = &top_menu_items[i];
            lpImeMenu[i].cbSize = sizeof(IMEMENUITEMINFO);
            lpImeMenu[i].fState = 0;
            switch (pItem->nCommandID) {
            case -1:
                lpImeMenu[i].fType = IMFT_SEPARATOR;
                break;
            case IDM_HIRAGANA:
                lpImeMenu[i].fType = IMFT_RADIOCHECK;
                lpImeMenu[i].fState = IMFS_CHECKED;
                break;
            case IDM_FULL_KATAKANA:
                lpImeMenu[i].fType = 0;
                lpImeMenu[i].fState = IMFS_CHECKED;
                break;
            case IDM_FULL_ASCII:
                lpImeMenu[i].fType = 0;
                if (dwFlags & IGIMIF_RIGHTMENU)
                    lpImeMenu[i].fState = IMFS_CHECKED;
                break;
            case IDM_HALF_KATAKANA:
                lpImeMenu[i].fType = IMFT_RADIOCHECK;
                break;
            case IDM_HALF_ASCII:
                lpImeMenu[i].fType = IMFT_RADIOCHECK;
                break;
            case IDM_ROMAN_INPUT:
            case IDM_KANA_INPUT:
                lpImeMenu[i].fType = IMFT_RADIOCHECK;
                break;
            default:
                lpImeMenu[i].fType = 0;
                break;
            }
            if (pItem->bDisabled) {
                lpImeMenu[i].fState |= MFS_GRAYED;
            }
            lpImeMenu[i].wID = pItem->nCommandID;
            lpImeMenu[i].hbmpChecked = NULL;
            lpImeMenu[i].hbmpUnchecked = NULL;
            if (pItem->nCommandID == IDM_FULL_ASCII)
            {
                lpImeMenu[i].hbmpChecked = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(1));
                lpImeMenu[i].hbmpUnchecked = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(2));
            }
            if (pItem->pszString)
                lstrcpy(lpImeMenu[i].szString, pItem->pszString);
            else
                lpImeMenu[i].szString[0] = 0;
            lpImeMenu[i].hbmpItem = NULL;
        }
        ret = _countof(top_menu_items);
    }

    return ret;
}
