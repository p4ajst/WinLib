// ------------------------------------------------------------------------------------------------ //
// @ file	 : Window.h                                                                             //
// @ brief	 : ウインドウの生成に関するクラス                                                       //
// @ date	 : 2019/05/29                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* 多重インクルードの防止 */
#pragma once
/* ヘッダファイルのインクルード */
// 標準ライブラリ
#include <Windows.h>
// 自作ヘッダファイル
#include "../../Utility/Utility.h"

/* 名前空間の宣言 */
// 自作名前空間
namespace mnLib
{
	/* クラスの宣言 */
	class Window
	{
	private:
		/* メンバ変数 */
		// ウインドウハンドル
		HWND mHwnd;
		// 自身のポインタ
		Window* mSelf;


		DELETE_COPY_AND_ASSIGN(Window)

	public:
		/* メンバ関数 */
		// コンストラクタ
		Window() {}
		// デストラクタ
		~Window() {}
		// 初期化
		HRESULT WindowsInitialize(HINSTANCE hInstance, int nShowCmd);
		HRESULT WindowsInitialize(HINSTANCE hInstance, int nShowCmd, int width, int height);
		// ウインドウプロシージャ
		LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		// 静的ウインドウプロシージャ
		static LRESULT CALLBACK BaseWindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		// メッセージループ
		void MessageLoop();
		// 値の設定
		void SetPointer(HWND hwnd);
		// ウインドウを閉じるかどうか
		bool QuitWindow();
		// ウインドウハンドルを取得
		HWND GetWindowHandle();
		// 終了処理
		void Finalize(HINSTANCE hInstance);
	};
}
