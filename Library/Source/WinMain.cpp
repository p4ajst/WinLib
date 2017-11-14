// ------------------------------------------------------------------------------------------------ //
// @ file	 : WinMain.cpp                                                                          //
// @ brief	 : ウインドウを描画するためのエントリーポイント                                         //
// @ date	 : 2017/10/30                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* ヘッダファイルのインクルード */
// 標準ライブラリ
#include <Windows.h>
// 自作ヘッダファイル
#include "../System/Library/Window.h"
#include "../System/Library/Direct3D.h"
#include "../System/Library/Device.h"

/* 名前空間 */
// 自作名前空間
using namespace mnLib;

/* 定数の定義 */
// ウインドウサイズ
static const int windowWidth = 1280;
static const int windowHeight = 960;

/* 関数の定義 */
// ----------------------------------------------------------------------------------------------- //
// @ brief  : メイン関数                                                                           //
// @ param  : HINSTANCE hInstance...アプリケーションの識別                                         //
// @ param  : HINSTANCE hPrevInstance                                                              //
// @ param  : LPSTR lpCmdLine...コマンドラインから受け取った引数                                   //
// @ param  : int nShowCmd...ウインドウの表示するための値                                          //
// @ return : int...整数値                                                                         //
// @ note   : WINAPI...Windowsの関数の呼び出し規約。Windowsの関数を呼び出すときは必ず頭につく      //
// ----------------------------------------------------------------------------------------------- // 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// 戻り値
	HRESULT hrlt;

	// ウインドウクラスのインスタンス
	Window* window;
	// インスタンスを生成
	window = new Window();
	// 初期化
	hrlt = window->WindowsInitialize(hInstance, nShowCmd, windowWidth, windowHeight);
	// 失敗処理
	if (FAILED(hrlt))
	{
		return 0;
	}

	// DirectX関連のクラスのインスタンス
	Direct3D* direct3d;
	// インスタンスの生成
	direct3d = new Direct3D();
	// 初期化
	hrlt = direct3d->Initialize(window->GetWindowHandle());
	// 失敗処理
	if (FAILED(hrlt))
	{
		return 0;
	}
	// 画面サイズの設定
	direct3d->SetWidth(windowWidth);
	direct3d->SetHeight(windowHeight);
	// レンダーターゲットの生成
	direct3d->CreateRenderTargetView();
	// 深度バッファの生成
	direct3d->CreateDepthStencilView();

	// メインループ
	while (window->MessageLoop() != false)
	{
		//const char* str = "あいうえおかきくけこ";
		//// 文字列の大きさ
		//auto length = strlen(str);
		//// 文字の表示
		//TextOut(GetDC(window->GetWindowHandle()), 0, 0, (LPCWCHAR)str, length);
		if (Input::Keyboard::Touch(VK_BACK))
		{
			const char* str = "あいうえお";
			// 文字列の大きさ
			auto length = strlen(str);
			// 文字の表示
			TextOut(GetDC(window->GetWindowHandle()), 0, 0, (LPCWCHAR)str, length);
		}
		if (Input::Keyboard::Touch(VK_ESCAPE))
		{
			const char* str = "かきくけこ";
			// 文字列の大きさ
			auto length = strlen(str);
			// 文字の表示
			TextOut(GetDC(window->GetWindowHandle()), 0, 0, (LPCWCHAR)str, length);
		}
		if (Input::Mouse::Click(VK_RBUTTON))
		{
			const char* str = "かたくりこ";
			// 文字列の大きさ
			auto length = strlen(str);
			// 文字の表示
			TextOut(GetDC(window->GetWindowHandle()), 0, 0, (LPCWCHAR)str, length);
		}

		direct3d->SwapBackBaffer();
	}


	// デバイスの消失処理
	hrlt = direct3d->GetDevice()->GetDeviceRemovedReason();
	switch (hrlt)
	{
	case S_OK:
		// 正常
		break;
	case DXGI_ERROR_DEVICE_HUNG:
	case DXGI_ERROR_DEVICE_RESET:
		// Direct3Dの解放（アプリケーション定義）
		
		// Direct3Dの初期化（アプリケーション定義）
		hrlt = direct3d->Initialize(window->GetWindowHandle());
		// 失敗判定
		if (FAILED(hrlt))
		{
			// アプリケーションの終了
			return false;
		}
		break;
	case DXGI_ERROR_DEVICE_REMOVED:
	case DXGI_ERROR_DRIVER_INTERNAL_ERROR:
	case DXGI_ERROR_INVALID_CALL:
	default:
		// どうしようもないので、アプリケーションの終了
		return false;
	}


	// インスタンスを破棄
	delete window;
	delete direct3d;
	// 正常終了
	return 0;
}
