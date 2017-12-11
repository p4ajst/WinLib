﻿// ------------------------------------------------------------------------------------------------ //
// @ file	 : Device.h                                                                             //
// @ brief	 : 入力デバイス関連のクラス                                                             //
// @ date	 : 2017/11/06                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* 多重インクルードの防止 */
#pragma once 

/* ヘッダファイルのインクルード */
// 標準ライブラリ
#include <Windows.h>

/* 定数の定義 */
/* 変数の定義 */
/* 列挙体の定義 */
/* 構造体の定義 */
/* 関数のプロトタイプ宣言 */
/* 名前空間の宣言 */
// 自作名前空間
namespace mnLib
{
	namespace Input
	{
		namespace Keyboard
		{
			/* 関数のプロトタイプ宣言 */
			// キーの入力（連打）
			bool __stdcall Touch(DWORD key);
			// キーの入力（長押し）
			bool __stdcall Press(DWORD key);
		}
		namespace Mouse
		{
			/* 関数のプロトタイプ宣言 */
			// クリック処理
			bool __stdcall Click(DWORD click);
		}
	}
}
