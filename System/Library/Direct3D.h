// ------------------------------------------------------------------------------------------------ //
// @ file	 : Direct3D.h                                                                           //
// @ brief	 : DirectX関連のクラス                                                                  //
// @ date	 : 2019/06/30                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* 多重インクルードの防止 */
#pragma once

/* Direct3D 11関連ライブラリのリンク */
#pragma region LinkLibrary
// 「Direct3D 11」用ライブラリ
#pragma comment(lib,"d3d11.lib")
// デバッグビルドか？
#if defined(DEBUG)||defined(_DEBUG)
//// デバッグ版の「D3DX 11」用ライブラリをリンク
//#pragma comment(lib,"d3dx11d.lib")
#else
// リリース版の「D3DX 11」用ライブラリをリンク
#pragma comment(lib,"d3dx11.lib")
#endif
//// エラー処理ユーティリティ・ライブラリ
//#pragma comment(lib,"dxerr.lib")
#pragma endregion Direct3D_11関連ライブラリのリンク

/* ヘッダファイルのインクルード */
#pragma region IncludeHeaderFile
// 型チェックを厳密に行う
#define STRICT
// ヘッダーからあまり使われない関数を省く
#define WIN32_LEAN_AND_MEAN
// Windows.h
#include <Windows.h>
// Direct3D
#include <d3d11.h>
// Direct3D＆D3DX（内部で「d3d11.h」をインクルードしている）
//#include <d3dx11.h>
// DirectXのエラー処理ユーティリティ・ライブラリ
//#include <dxerr.h>
// 「MBCS（マルチ・バイト・キャラクタ・セット）文字セット」と「Unicode文字セット」の両方に対応できる
#include <tchar.h>
// Windows ランタイム C++ テンプレート ライブラリ
#include <WRL.h>
#pragma endregion ヘッダファイルのインクルード
// 自作ヘッダファイル
#include "../../Utility/Utility.h"



/* 名前空間の宣言 */
// 自作名前空間
namespace mnLib
{
	/* クラスの宣言 */
	class Direct3D
	{
	private:
		/* メンバ変数 */
		// ウインドウハンドル
		HWND mHwnd;
		// デバイス
		Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
		// デバイスコンテキスト
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> pContext;
		// スワップチェイン
		Microsoft::WRL::ComPtr<IDXGISwapChain> pSwapChain;
		// レンダーターゲットビュー
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> pRenderTargetView;
		// バックバッファ
		Microsoft::WRL::ComPtr<ID3D11Texture2D> pBackBuffer;
		// 深度ステンシル
		Microsoft::WRL::ComPtr<ID3D11Texture2D> pDepthStencil;
		// 深度ステンシルビュー
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> pDepthStencilView;
		// インターフェース
		Microsoft::WRL::ComPtr<IDXGIDevice1> pInterface;
		// アダプタ
		Microsoft::WRL::ComPtr<IDXGIAdapter> pAdapter;
		// ファクトリ
		Microsoft::WRL::ComPtr<IDXGIFactory1> pFactory;

		// 画面のサイズ（幅）
		int mWidth;
		// 画面のサイズ（高さ）
		int mHeight;

	private:
		DELETE_COPY_AND_ASSIGN(Direct3D)

	public:
		/* メンバ関数 */
		// コンストラクタ
		Direct3D() = default;
		// デストラクタ
		~Direct3D() = default;
		// 初期化処理
		HRESULT Initialize(HWND windowHandle);
		// 更新処理
		void Update();
		// 描画処理
		void Render();
		// 終了処理
		void CleanUp();

		// レンダーターゲットビューの生成
		void CreateRenderTargetView();
		// 深度バッファの生成
		void CreateDepthStencilView();
		// バックバッファのスワップ
		void SwapBackBaffer();

#pragma region Setter
		void SetWidth(int width) { mWidth = width; }
		void SetHeight(int height) { mHeight = height; }
#pragma endregion メンバ変数の設定関数群

#pragma region Getter
		HWND GetHandle() { return mHwnd; }
		ID3D11Device* GetDevice() { return pDevice.Get(); }
		ID3D11DeviceContext* GetContext() { return pContext.Get(); }
		IDXGISwapChain* GetSwapChain() { return pSwapChain.Get(); }
		ID3D11RenderTargetView* GetRenderTargetView() { return pRenderTargetView.Get(); }
		ID3D11Texture2D* GetBackBuffer() { return pBackBuffer.Get(); }
		ID3D11Texture2D* GetDepthStencil() { return pDepthStencil.Get(); }
		ID3D11DepthStencilView* GetDepthStencilView() { return pDepthStencilView.Get(); }
		IDXGIDevice1* GetInterface() { return pInterface.Get(); }
		IDXGIAdapter* GetAdapter() { return pAdapter.Get(); }
		IDXGIFactory1* GetFactory() { return pFactory.Get(); }

		int GetWidth() { return mWidth; }
		int GetHeight() { return mHeight; }
#pragma endregion メンバ変数の取得関数群
	};
}
