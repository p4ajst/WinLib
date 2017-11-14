// ------------------------------------------------------------------------------------------------ //
// @ file	 : Device.cpp                                                                           //
// @ brief	 : 入力デバイス関連のクラス                                                             //
// @ date	 : 2017/11/06                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* ヘッダファイルのインクルード */
// 自作ヘッダファイル
#include "Device.h"

/* 定数の定義 */
/* 変数の定義 */
/* 列挙体の定義 */
/* 構造体の定義 */
/* 名前空間の定義 */
// 自作名前空間
using namespace mnLib::Input;
/* メンバ関数の定義 */
/* 関数の定義 */
// ------------------------------------------------------------------------------------------------ //
// @ brief   : 初期化                                                                               //
// @ param   : HWND whandle....ウインドウハンドル                                                   //
// @ return  : HRESULT....HRESULTが０なら正常、それ以外の値なら異常。                               //
// @ note    :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 
bool __stdcall Keyboard::Touch(DWORD key)
{
	// トリガー処理用に前のキーを保存
	DWORD prevKey;
	// キーを保存
	prevKey = key;
	// どのキーが押されたか
	switch (key)
	{
	case VK_BACK:
	case VK_TAB:

	case VK_CLEAR:
	case VK_RETURN:

	case VK_SHIFT:
	case VK_CONTROL:
	case VK_MENU:
	case VK_PAUSE:
	case VK_CAPITAL:

	case VK_KANA:
	case VK_KANJI:

	case VK_ESCAPE:

	case VK_CONVERT:
	case VK_NONCONVERT:
	case VK_ACCEPT:
	case VK_MODECHANGE:

	case VK_SPACE:
	case VK_PRIOR:
	case VK_NEXT:
	case VK_END:
	case VK_HOME:
	case VK_LEFT:
	case VK_UP:
	case VK_RIGHT:
	case VK_DOWN:
	case VK_SELECT:
	case VK_PRINT:
	case VK_EXECUTE:
	case VK_SNAPSHOT:
	case VK_INSERT:
	case VK_DELETE:
	case VK_HELP:

	case VK_LWIN:
	case VK_RWIN:
	case VK_APPS:

	case VK_SLEEP:

	case VK_NUMPAD0:
	case VK_NUMPAD1:
	case VK_NUMPAD2:
	case VK_NUMPAD3:
	case VK_NUMPAD4:
	case VK_NUMPAD5:
	case VK_NUMPAD6:
	case VK_NUMPAD7:
	case VK_NUMPAD8:
	case VK_NUMPAD9:

	case VK_MULTIPLY:
	case VK_ADD:
	case VK_SEPARATOR:
	case VK_SUBTRACT:
	case VK_DECIMAL:
	case VK_DIVIDE:

	case VK_F1:
	case VK_F2:
	case VK_F3:
	case VK_F4:
	case VK_F5:
	case VK_F6:
	case VK_F7:
	case VK_F8:
	case VK_F9:
	case VK_F10:
	case VK_F11:
	case VK_F12:
	case VK_F13:
	case VK_F14:
	case VK_F15:
	case VK_F16:
	case VK_F17:
	case VK_F18:
	case VK_F19:
	case VK_F20:
	case VK_F21:
	case VK_F22:
	case VK_F23:
	case VK_F24:

	case VK_NUMLOCK:
	case VK_SCROLL:

	case VK_OEM_FJ_JISHO:
	case VK_OEM_FJ_MASSHOU:
	case VK_OEM_FJ_TOUROKU:
	case VK_OEM_FJ_LOYA:
	case VK_OEM_FJ_ROYA:

	case VK_LSHIFT:
	case VK_RSHIFT:
	case VK_LCONTROL:
	case VK_RCONTROL:
	case VK_LMENU:
	case VK_RMENU:

	case VK_BROWSER_BACK:
	case VK_BROWSER_FORWARD:
	case VK_BROWSER_REFRESH:
	case VK_BROWSER_STOP:
	case VK_BROWSER_SEARCH:
	case VK_BROWSER_FAVORITES:
	case VK_BROWSER_HOME:

	case VK_VOLUME_MUTE:
	case VK_VOLUME_DOWN:
	case VK_VOLUME_UP:
	case VK_MEDIA_NEXT_TRACK:
	case VK_MEDIA_PREV_TRACK:
	case VK_MEDIA_STOP:
	case VK_MEDIA_PLAY_PAUSE:
	case VK_LAUNCH_MAIL:
	case VK_LAUNCH_MEDIA_SELECT:
	case VK_LAUNCH_APP1:
	case VK_LAUNCH_APP2:

	case VK_OEM_1:
	case VK_OEM_PLUS:
	case VK_OEM_COMMA:
	case VK_OEM_MINUS:
	case VK_OEM_PERIOD:
	case VK_OEM_2:
	case VK_OEM_3:

	case VK_OEM_4:
	case VK_OEM_5:
	case VK_OEM_6:
	case VK_OEM_7:
	case VK_OEM_8:

	case VK_OEM_AX:
	case VK_OEM_102:
	case VK_ICO_HELP:
	case VK_ICO_00:

	case VK_OEM_RESET:
	case VK_OEM_JUMP:
	case VK_OEM_PA1:
	case VK_OEM_PA2:
	case VK_OEM_PA3:
	case VK_OEM_WSCTRL:
	case VK_OEM_CUSEL:
	case VK_OEM_ATTN:
	case VK_OEM_FINISH:
	case VK_OEM_COPY:
	case VK_OEM_AUTO:
	case VK_OEM_ENLW:
	case VK_OEM_BACKTAB:

	case VK_ATTN:
	case VK_CRSEL:
	case VK_EXSEL:
	case VK_EREOF:
	case VK_PLAY:
	case VK_ZOOM:
	case VK_NONAME:
	case VK_PA1:
	case VK_OEM_CLEAR:

	default:
		break;
	}
	// トリガー処理
	if (prevKey == key)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool __stdcall Keyboard::Press(DWORD key)
{
	switch (key)
	{
	case VK_BACK:
	case VK_TAB:

	case VK_CLEAR:
	case VK_RETURN:

	case VK_SHIFT:
	case VK_CONTROL:
	case VK_MENU:
	case VK_PAUSE:
	case VK_CAPITAL:

	case VK_KANA:
	case VK_KANJI:

	case VK_ESCAPE:

	case VK_CONVERT:
	case VK_NONCONVERT:
	case VK_ACCEPT:
	case VK_MODECHANGE:

	case VK_SPACE:
	case VK_PRIOR:
	case VK_NEXT:
	case VK_END:
	case VK_HOME:
	case VK_LEFT:
	case VK_UP:
	case VK_RIGHT:
	case VK_DOWN:
	case VK_SELECT:
	case VK_PRINT:
	case VK_EXECUTE:
	case VK_SNAPSHOT:
	case VK_INSERT:
	case VK_DELETE:
	case VK_HELP:

	case VK_LWIN:
	case VK_RWIN:
	case VK_APPS:

	case VK_SLEEP:

	case VK_NUMPAD0:
	case VK_NUMPAD1:
	case VK_NUMPAD2:
	case VK_NUMPAD3:
	case VK_NUMPAD4:
	case VK_NUMPAD5:
	case VK_NUMPAD6:
	case VK_NUMPAD7:
	case VK_NUMPAD8:
	case VK_NUMPAD9:

	case VK_MULTIPLY:
	case VK_ADD:
	case VK_SEPARATOR:
	case VK_SUBTRACT:
	case VK_DECIMAL:
	case VK_DIVIDE:

	case VK_F1:
	case VK_F2:
	case VK_F3:
	case VK_F4:
	case VK_F5:
	case VK_F6:
	case VK_F7:
	case VK_F8:
	case VK_F9:
	case VK_F10:
	case VK_F11:
	case VK_F12:
	case VK_F13:
	case VK_F14:
	case VK_F15:
	case VK_F16:
	case VK_F17:
	case VK_F18:
	case VK_F19:
	case VK_F20:
	case VK_F21:
	case VK_F22:
	case VK_F23:
	case VK_F24:

	case VK_NUMLOCK:
	case VK_SCROLL:

	case VK_OEM_FJ_JISHO:
	case VK_OEM_FJ_MASSHOU:
	case VK_OEM_FJ_TOUROKU:
	case VK_OEM_FJ_LOYA:
	case VK_OEM_FJ_ROYA:

	case VK_LSHIFT:
	case VK_RSHIFT:
	case VK_LCONTROL:
	case VK_RCONTROL:
	case VK_LMENU:
	case VK_RMENU:

	case VK_BROWSER_BACK:
	case VK_BROWSER_FORWARD:
	case VK_BROWSER_REFRESH:
	case VK_BROWSER_STOP:
	case VK_BROWSER_SEARCH:
	case VK_BROWSER_FAVORITES:
	case VK_BROWSER_HOME:

	case VK_VOLUME_MUTE:
	case VK_VOLUME_DOWN:
	case VK_VOLUME_UP:
	case VK_MEDIA_NEXT_TRACK:
	case VK_MEDIA_PREV_TRACK:
	case VK_MEDIA_STOP:
	case VK_MEDIA_PLAY_PAUSE:
	case VK_LAUNCH_MAIL:
	case VK_LAUNCH_MEDIA_SELECT:
	case VK_LAUNCH_APP1:
	case VK_LAUNCH_APP2:

	case VK_OEM_1:
	case VK_OEM_PLUS:
	case VK_OEM_COMMA:
	case VK_OEM_MINUS:
	case VK_OEM_PERIOD:
	case VK_OEM_2:
	case VK_OEM_3:

	case VK_OEM_4:
	case VK_OEM_5:
	case VK_OEM_6:
	case VK_OEM_7:
	case VK_OEM_8:

	case VK_OEM_AX:
	case VK_OEM_102:
	case VK_ICO_HELP:
	case VK_ICO_00:

	case VK_OEM_RESET:
	case VK_OEM_JUMP:
	case VK_OEM_PA1:
	case VK_OEM_PA2:
	case VK_OEM_PA3:
	case VK_OEM_WSCTRL:
	case VK_OEM_CUSEL:
	case VK_OEM_ATTN:
	case VK_OEM_FINISH:
	case VK_OEM_COPY:
	case VK_OEM_AUTO:
	case VK_OEM_ENLW:
	case VK_OEM_BACKTAB:

	case VK_ATTN:
	case VK_CRSEL:
	case VK_EXSEL:
	case VK_EREOF:
	case VK_PLAY:
	case VK_ZOOM:
	case VK_NONAME:
	case VK_PA1:
	case VK_OEM_CLEAR:

	default:
		break;
	}
	return false;
}

bool __stdcall Mouse::Click(DWORD click)
{
	// トリガー処理用にマウスのボタンを保存
	DWORD prevBotton;
	// マウスのボタンを保存
	prevBotton = click;
	switch (click)
	{
		// マウスの左ボタン
	case VK_LBUTTON:
		// マウスの右ボタン
	case VK_RBUTTON:
		// マウスの真ん中のボタン
	case VK_MBUTTON:
	default:
		break;
	}

	// トリガー処理
	if (prevBotton == click)
	{
		return false;
	}
	else
	{
		return true;
	}

}


