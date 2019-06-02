// ------------------------------------------------------------------------------------------------ //
// @ file	 : Window.h                                                                             //
// @ brief	 : ウインドウの生成に関するクラス                                                       //
// @ date	 : 2019/05/29                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* ヘッダファイルのインクルード */
// 自作ヘッダファイル
#include "Window.h"
#include "../Library/Device.h"

/* 名前空間 */
// 自作名前空間
using namespace mnLib;

/* メンバ関数の定義 */
// ----------------------------------------------------------------------------------------------- //
// @ brief	: ウインドウの初期化                                                                   //
// @ param	: HINSTANCE hInstance....ウインドウのインスタンス                                      //
// @ param	: int nShowCmd....ショーコマンド                                                       //
// @ return : HRESULT....HRESULTが０なら正常、それ以外の値なら異常。                               //
// @ note	: 無し                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
HRESULT Window::WindowsInitialize(HINSTANCE hInstance, int nShowCmd)
{
	// ウインドウの情報を格納した構造体
	WNDCLASSEX wce;

	// 構造体の全ての項目を０で初期化する
	SecureZeroMemory(&wce, sizeof(wce));
	// 構造体の後ろに動的に確保される余分なメモリ。０で初期化
	wce.cbClsExtra = 0;
	// 構造体の大きさ
	wce.cbSize = sizeof(wce);
	// ウィンドウインスタンスの後ろに動的に確保される余分なメモリ。０で初期化
	wce.cbWndExtra = 0;
	// 背景色(黒に設定)
	wce.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
	// マウスカーソル
	wce.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	// アイコン(デスクトップ等に描画される)
	wce.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// アイコン(タスクバーなどに表示される)
	wce.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	// アプリケーションのインスタンスハンドル
	wce.hInstance = hInstance;
	// メッセージを受け取るWinProc関数へのポインタを渡す。
	wce.lpfnWndProc = BaseWindowProcedure;
	// ウインドウクラスの名前
	wce.lpszClassName = "Window";
	// ウインドウが持つデフォルトのメニューのリソース名
	wce.lpszMenuName = NULL;
	// ウィンドウの基本性質を設定
	wce.style = CS_HREDRAW | CS_VREDRAW;

	// WNDCLASSEXの登録
	if (!RegisterClassEx(&wce))
	{
		// できなかったら0を返す
		return 0;
	}

	// ウインドウハンドル
	HWND windowHandle;

	// @brief  : メインのウインドウを作成する
	// @param  : DWORD dwExStyle....拡張するウィンドウの見た目の細かなスタイル
	// @param  : LPCTSTR lpClassName....ウィンドウクラスで登録した名前
	// @param  : LPCTSTR lpWindowName....作成するウィンドウに付けられる名前
	// @param  : DWORD dwStyle....作成するウィンドウの見た目の細かなスタイル
	// @param  : int x....ウィンドウの左上の位置
	// @param  : int y....ウィンドウの左上の位置
	// @param  : int nWidth....ウィンドウの幅
	// @param  : int nHeight....ウィンドウの高さ
	// @param  : HWND hWndParent....親ウインドウ
	// @param  : HWND hMenu....ウインドウにつくメニューハンドル
	// @param  : HINSTANCE hInstance....アプリケーションのインスタンスハンドル
	// @param  : LPVOID lpParam....マルチドキュメントインターフェースウインドウを作成するときに使用(シングルドキュメントインターフェースのウインドウの場合はNULLにする)
	windowHandle = CreateWindowEx
	(NULL
		, TEXT("Window")
		, TEXT("メインウインドウ")
		, WS_OVERLAPPEDWINDOW | WS_VISIBLE
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, 640
		, 480
		, NULL
		, NULL
		, hInstance
		, this);
	if (windowHandle != NULL)
	{
		ShowWindow(windowHandle, SW_SHOW);
	}

	// ウインドウハンドル
	mHwnd = windowHandle;
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: ウインドウの初期化                                                                   //
// @ param	: HINSTANCE hInstance....ウインドウのインスタンス                                      //
// @ param	: int nShowCmd....ショーコマンド                                                       //
// @ param	: int width....ウインドウの幅                                                          //
// @ param	: int height....ウインドウの高さ                                                       //
// @ return : HRESULT....HRESULTが０なら正常、それ以外の値なら異常。                               //
// @ note	: 無し                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
HRESULT Window::WindowsInitialize(HINSTANCE hInstance, int nShowCmd, int width, int height)
{

	// ウインドウの情報を格納した構造体
	WNDCLASSEX wce;

	// 構造体の全ての項目を０で初期化する
	SecureZeroMemory(&wce, sizeof(wce));
	// 構造体の後ろに動的に確保される余分なメモリ。０で初期化
	wce.cbClsExtra = 0;
	// 構造体の大きさ
	wce.cbSize = sizeof(wce);
	// ウィンドウインスタンスの後ろに動的に確保される余分なメモリ。０で初期化
	wce.cbWndExtra = 0;
	// 背景色(黒に設定)
	wce.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
	// マウスカーソル
	wce.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	// アイコン(デスクトップ等に描画される)
	wce.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// アイコン(タスクバーなどに表示される)
	wce.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	// アプリケーションのインスタンスハンドル
	wce.hInstance = hInstance;
	// メッセージを受け取るWinProc関数へのポインタを渡す。
	wce.lpfnWndProc = BaseWindowProcedure;
	// ウインドウクラスの名前
	wce.lpszClassName = "Window";
	// ウインドウが持つデフォルトのメニューのリソース名
	wce.lpszMenuName = NULL;
	// ウィンドウの基本性質を設定
	wce.style = CS_HREDRAW | CS_VREDRAW;

	// WNDCLASSEXの登録
	if (!RegisterClassEx(&wce))
	{
		// できなかったら0を返す
		return 0;
	}

	// ウインドウハンドル
	HWND windowHandle;

	// @brief  : メインのウインドウを作成する
	// @param  : DWORD dwExStyle....拡張するウィンドウの見た目の細かなスタイル
	// @param  : LPCTSTR lpClassName....ウィンドウクラスで登録した名前
	// @param  : LPCTSTR lpWindowName....作成するウィンドウに付けられる名前
	// @param  : DWORD dwStyle....作成するウィンドウの見た目の細かなスタイル
	// @param  : int x....ウィンドウの左上の位置
	// @param  : int y....ウィンドウの左上の位置
	// @param  : int nWidth....ウィンドウの幅
	// @param  : int nHeight....ウィンドウの高さ
	// @param  : HWND hWndParent....親ウインドウ
	// @param  : HWND hMenu....ウインドウにつくメニューハンドル
	// @param  : HINSTANCE hInstance....アプリケーションのインスタンスハンドル
	// @param  : LPVOID lpParam....マルチドキュメントインターフェースウインドウを作成するときに使用(シングルドキュメントインターフェースのウインドウの場合はNULLにする)
	windowHandle = CreateWindowEx
	(WS_EX_COMPOSITED
		, TEXT("Window")
		, TEXT("メインウインドウ")
		, WS_OVERLAPPEDWINDOW | WS_VISIBLE
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, width
		, height
		, NULL
		, NULL
		, hInstance
		, this);
	if (windowHandle != NULL)
	{
		ShowWindow(windowHandle, SW_SHOW);
	}

	// ウインドウハンドル
	mHwnd = windowHandle;
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: コールバック関数                                                                     //
// @ param	: HWND hwnd....ウインドウハンドル                                                      //
// @ param	: UINT messege = unsigned int messege....ウインドウメッセージを格納                    //
// @ param	: WPARAM wparam....ウインドウメッセージごとに色んな値が入る                            //
// @ param	: LPARAM lparam....ウインドウメッセージごとに色んな値が入る                            //
// @ return : HRESULT....HRESULTが０なら正常、それ以外の値なら異常。                               //
// @ note	: CALLBACK....CALLBACK関数として定義するため                                           //
// ----------------------------------------------------------------------------------------------- // 
LRESULT CALLBACK Window::WindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		// 生成
	case WM_CREATE:
		break;
		// 終了処理
	case WM_QUIT:
		break;
		// ウインドウを閉じる（×ボタンが押されたら呼び出される）
	case WM_CLOSE:
		break;
		// ウインドウを閉じる（WM_CLOSEの処理が終わったら呼び出される）
	case WM_DESTROY:
		// ウインドウを閉じる
		PostQuitMessage(0);
		// プログラムを終了させる
		exit(0);
		break;
		// キーが押されたとき
	case WM_KEYDOWN:
		break;
		// システムキーが押されたとき
	case WM_SYSKEYDOWN:
		break;
		// 左クリックがされたら
	case WM_LBUTTONDOWN:
		break;
		// 右クリックがされたら
	case WM_RBUTTONDOWN:
		break;
		// 真ん中のボタンが押されたら
	case WM_MBUTTONDOWN:
		break;
		// ウインドウ内でカーソル移動
	case WM_SETCURSOR:
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, message, wparam, lparam);
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: コールバック関数                                                                     //
// @ param	: HWND hwnd....ウインドウハンドル                                                      //
// @ param	: UINT messege = unsigned int messege....ウインドウメッセージを格納                    //
// @ param	: WPARAM wparam....ウインドウメッセージごとに色んな値が入る                            //
// @ param	: LPARAM lparam....ウインドウメッセージごとに色んな値が入る                            //
// @ return : HRESULT....HRESULTが０なら正常、それ以外の値なら異常。                               //
// @ note	: CALLBACK....CALLBACK関数として定義するため                                           //
// ----------------------------------------------------------------------------------------------- // 
LRESULT Window::BaseWindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	// 自身のポインタ
	Window* window;
	/*
		ウインドウ生成するときに設定した値を受け取る
		(Window*)....自身のポインタ型でキャスト
		(GetWindowLongPtr(hwnd, GWLP_USERDATA)....CreateWindowExの最後の引数(自分のポインタ)を取得
	 */
	window = (Window*)(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	// 自身のポインタに値が入っていなかったら
	if (window == nullptr)
	{
		// メッセージを確認(WM_CREATEだったら)
		if (message == WM_CREATE)
		{
			// lparamの値をもらう
			window = (Window*)(((LPCREATESTRUCT)lparam)->lpCreateParams);
		}
		// 自身のポインタに値が入っていたら
		if (window != nullptr)
		{
			// ウインドウハンドルの値を設定する
			window->SetPointer(hwnd);
		}
	}
	// 自身のポインタに値が入っていたら
	if (window != nullptr)
	{
		// オーバーライドしたウインドウプロシージャ
		return window->WindowProcedure(hwnd, message, wparam, lparam);
	}
	else
	{
		// デフォルトのウインドウプロシージャ
		return DefWindowProc(hwnd, message, wparam, lparam);
	}
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: メッセージループ                                                                     //
// @ param	: なし                                                                                 //
// @ return : なし                                                                                 //
// @ note	: なし                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
void Window::MessageLoop()
{
	/*
		メッセージループを受け取る
		LPMSG lpMesg....メッセージ情報(MSG構造体のポインタ)
		HWND hWnd....ウインドウハンドル
		UINT wMsgFilterMin....取得対象メッセージの最小値(０を指定する)
		Uint wMsgFilterMax....取得対象メッセージの最大値(０を指定する)
	*/

	// メッセージ
	MSG msg;

	// 構造体を０で初期化
	ZeroMemory(&msg, sizeof(msg));

	// 取得したメッセージが来ているか
	if (PeekMessage(&msg, mHwnd, 0, 0, PM_REMOVE))
	{
		// メッセージの翻訳
		TranslateMessage(&msg);
		// 取得したメッセージをウインドウプロシージャに送る
		DispatchMessage(&msg);
	}
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: 値を設定する                                                                         //
// @ param	: HWND hwnd....ウインドウハンドル                                                      //
// @ return : なし                                                                                 //
// @ note	: なし                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
void Window::SetPointer(HWND hwnd)
{
	/*
	値を設定
	hwnd....ウインドウハンドル
	GWLP_USERDATA....CreateWindowExの最後の引数(自分のポインタ)
	reinterpret_cast<LONG_PTR>(this)....強制的にLONG_PTR型にキャストされた自分のポインタ
	*/
	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	// 引数でもらったウインドウハンドルをメンバ変数のウインドウハンドルに代入
	this->mHwnd = hwnd;
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: ウインドウを閉じるかどうか                                                           //
// @ param	: なし                                                                                 //
// @ return : bool型                                                                               //
// @ note	: なし                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
bool Window::QuitWindow()
{
	//// メッセージループを呼ぶ
	//MessageLoop();

	if (mnLib::Input::Keyboard::Touch(VK_ESCAPE))
	{
		// ウインドウを閉じる
		PostQuitMessage(0);

		return true;
	}
	else
	{
		// メッセージループを呼ぶ
		MessageLoop();
		// ウインドウは閉じない
		return false;
	}
}



// ----------------------------------------------------------------------------------------------- //
// @ brief	: ウインドウハンドルの取得                                                             //
// @ param	: なし                                                                                 //
// @ return : HWND hwnd....ウインドウハンドル                                                      //
// @ note	: なし                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
HWND Window::GetWindowHandle()
{
	return mHwnd;
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: 終了処理                                                                             //
// @ param	: HINSTANCE hInstance...解放したいウインドウクラスのインスタンス                       //
// @ return : なし                                                                                 //
// @ note	: なし                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
void Window::Finalize(HINSTANCE hInstance)
{
	// ウインドウクラス解放
	UnregisterClass("Window", hInstance);
}
/* 関数の定義 */
