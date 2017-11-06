// ------------------------------------------------------------------------------------------------ //
// @ file   : Direct3D.h                                                                           //
// @ brief  : DirectX関連のクラス                                                                  //
// @ date   : 2017/10/29                                                                           //
// @ author : Madoka Nakajima                                                                      //
// @ note   :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* ヘッダファイルのインクルード */
// 自作ヘッダファイル
#include "Direct3D.h"
#include "../../Utility/Color.h"

/* 名前空間 */
// 自作名前空間
using namespace mnLib;

/* マクロの定義 */
#pragma region DefinitionMacro
// 開放用マクロ
#define SAFE_RELEASE(x){if(x){(x)->Releace();(x) = NULL}}
#pragma endregion マクロの定義


/* メンバ関数の定義 */
// ------------------------------------------------------------------------------------------------ //
// @ brief   : 初期化                                                                               //
// @ param   : HWND whandle....ウインドウハンドル                                                   //
// @ return  : HRESULT....HRESULTが０なら正常、それ以外の値なら異常。                               //
// @ note    :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 
HRESULT Direct3D::Initialize(HWND windowHandle)
{
	// 戻り値
	HRESULT hrlt;
#pragma region InitMemberVariable
	mHwnd = windowHandle;
	pDevice.Reset();
	pContext.Reset();
	pSwapChain.Reset();
	pRenderTargetView.Reset();
	pBackBuffer.Reset();
	pDepthStencil.Reset();
	pDepthStencilView.Reset();
	pInterface.Reset();
	pAdapter.Reset();
	pFactory.Reset();

	mWidth = 0;
	mHeight = 0;
#pragma endregion メンバ変数の初期化

#pragma region SetScreenSize
	// クライアント領域を格納する変数
	RECT rc;

	// クライアント領域の取得
	GetClientRect(mHwnd, &rc);
	// 幅の計算
	mWidth = rc.right - rc.left;
	// 高さの計算
	mHeight = rc.bottom - rc.top;

#pragma endregion クライアント領域を取得して画面サイズを算出

#pragma region FunctionLevel
	// シェーダーモデル５などのDirect3D 11.0 でサポートされている機能をターゲットとする
	// 機能レベルの配列
	D3D_FEATURE_LEVEL featureLevel[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};
	// デバイス作成時に返される機能レベル
	D3D_FEATURE_LEVEL featureLevelSupported = D3D_FEATURE_LEVEL_11_0;
#pragma endregion 機能レベルの配列

#pragma region SetSwapChain

	/* デバイスとスワップチェインの設定 */
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	// 構造体の値を初期化
	SecureZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	// バックバッファの数
	swapChainDesc.BufferCount = 2;
	/// ディスプレイモードを設定する構造体
	// バックバッファの幅
	swapChainDesc.BufferDesc.Width = 640;
	// バックバッファの高さ
	swapChainDesc.BufferDesc.Height = 480;
	// ディスプレイフォーマット
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	// リフレッシュレート（分子）
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	// リフレッシュレート（分母）
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	// スキャンライン描画モード
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	// スケーリングモード
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	/// バックバッファの使われ方を指定するフラグ
	/// バックバッファはシェーダ入力または描画ターゲットとして使うことができる
	// バックバッファの使用法
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	/// 出力先ウインドウのハンドル
	// 関連付けるウインドウ
	swapChainDesc.OutputWindow = windowHandle;
	// マルチサンプルの数
	swapChainDesc.SampleDesc.Count = 1;
	// マルチサンプルのクオリティ
	swapChainDesc.SampleDesc.Quality = 0;
	/// スワップ効果を指定するフラグ
	/// 画面モードの設定
	/// ウインドウモードであれば「TRUE」
	/// フルスクリーンモードであれば「False」
	// ウインドウモード
	swapChainDesc.Windowed = TRUE;
	// スワップ効果
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	// モードの自動切り替え
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

#pragma endregion スワップチェインの設定

#pragma region CreateDeviceAndSwapChain
	// @brief  : 「ID3D11Deviceインターフェース」と「ID3D11DiveceContextインターフェース」と「IDXGISwapChainインターフェース」を同時に作成
	// @param  : IDXGIAdapter* pAdapter....表示に使うディスプレイデバイスを指定
	// @param  : D3D_DRIVER_TYPE DriverType....デバイスのドライバタイプを指定
	// @param  : HMODULE SoftWare....ソフトウェアラスタライザが実装されているDLLのハンドルを指定
	// @param  : UINT Flags....使用するDirect3D 11のAPIレイヤーを列挙型の組み合わせで指定する
	// @param  : const D3D_FEATURE_LEVEL* pFeatureLevel....作成を試みる機能レベルを優先順位の高い順に並べた配列
	// @param  : UINT FeatureLevels....pFeatureLevelで指定した配列の要素数
	// @param  : UINT SDKVersion....SDKバージョンを指定
	// @param  : const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc....作るスワップチェインの設定を記述する構造体を渡す
	// @param  : IDXGISwapChain** ppSwapChain....作られたスワップチェインのインターフェースを受け取る変数のポインタを渡す
	// @param  : ID3D11Device ppDevice....作ったデバイスのインターフェースを受け取る変数のポインタを渡す
	// @param  : D3D_FEATURE_LEVEL* pFeatureLevel....サポートされている機能レベルを受け取る変数のポインタ
	// @param  : ID3D11DeviceContext** ppImmidiateContext....作ったデバイスコンテキストのインターフェースを受け取る変数のポインタを渡す
	// @return : HRESULT型の変数
	hrlt = D3D11CreateDeviceAndSwapChain
	(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		0,
		D3D11_CREATE_DEVICE_BGRA_SUPPORT,
		featureLevel,
		ARRAYSIZE(featureLevel),
		D3D11_SDK_VERSION,
		&swapChainDesc,
		pSwapChain.GetAddressOf(),
		pDevice.GetAddressOf(),
		&featureLevelSupported,
		pContext.GetAddressOf()
	);
	if (FAILED(hrlt))
	{
		hrlt = D3D11CreateDeviceAndSwapChain
		(
			nullptr,
			D3D_DRIVER_TYPE_WARP,
			0,
			D3D11_CREATE_DEVICE_BGRA_SUPPORT,
			featureLevel,
			ARRAYSIZE(featureLevel),
			D3D11_SDK_VERSION,
			&swapChainDesc,
			pSwapChain.GetAddressOf(),
			pDevice.GetAddressOf(),
			&featureLevelSupported,
			pContext.GetAddressOf()
		);
	}

#pragma endregion デバイスとスワップチェインの作成

#pragma region GetBackBuffer
	// @brief  : スワップチェインから最初のバックバッファを取得
	// @param  : UINT buffer...バックバッファの番号
	// @param  : REFIID riid...バッファにアクセスするインターフェース
	// @param  : void** ppSurface...バッファを受け取る変数
	// @return : HRESULT型の変数
	hrlt = pSwapChain->GetBuffer
	(
		0,
		__uuidof(ID3D11Texture2D),
		(LPVOID*)&pBackBuffer
	);
	// 失敗判定
	if (FAILED(hrlt))
	{
		// 関数を抜ける
		return false;
	}
#pragma endregion スワップチェインのバックバッファを取得

#pragma region CreateRenderTarget
	// @brief  : バックバッファのレンダーターゲットを作る
	// @param  : ID3D11Resource* pResource...ビューでアクセスするリソース
	// @param  : const D3D11_RENDER_TARGET_VIEW_DESC* pDesc...描画ターゲットビューの定義
	// @param  : ID3D11_RenderTagetView* ppRTView...描画ターゲットビューを受け取る変数
	// @return : HRESULT型の変数
	hrlt = pDevice->CreateRenderTargetView
	(
		pBackBuffer.Get(),
		nullptr,
		&pRenderTargetView
	);
	// 失敗判定
	if (FAILED(hrlt))
	{
		// 関数を抜ける
		return false;
	}
#pragma endregion バックバッファから描画ターゲットを生成



#pragma region SetRenderTarget
	// @brief  : 描画ターゲットビューを出力マージャーの描画ターゲットとして設定
	// @param  : UINT 描画ターゲットの数
	// @param  : 描画ターゲットビューの配列
	// @param  : 深度／ステンシルビューを設定しない
	pContext->OMSetRenderTargets
	(
		1,
		&pRenderTargetView, 
		nullptr
	);
#pragma endregion 描画ターゲットとして設定




#pragma region SetViewport
	// ビューポートの設定
	D3D11_VIEWPORT viewPort[1];

	// ビューポート領域の左上のｘ座標
	viewPort[0].TopLeftX = 0.0f;
	// ビューポート領域の左上のｙ座標
	viewPort[0].TopLeftY = 0.0f;
	// ビューポート領域の幅
	viewPort[0].Width = 640.0f;
	// ビューポート領域の高さ
	viewPort[0].Height = 480.0f;
	// ビューポート領域の深度値の最小値
	viewPort[0].MinDepth = 0.0f;
	// ビューポート領域の深度値の最大値
	viewPort[0].MaxDepth = 1.0f;

	// ラスタライザにビューポートを設定
	pContext->RSSetViewports(1, viewPort);

#pragma endregion ビューポートの設定

#pragma region StencilTexture
	// 深度／ステンシルテクスチャの作成
	D3D11_TEXTURE2D_DESC depthStencilDesc;
	// 幅
	depthStencilDesc.Width = mWidth;
	// 高さ
	depthStencilDesc.Height = mHeight;
	// ミップマップレベル数
	depthStencilDesc.MipLevels = 1;
	// 配列サイズ
	depthStencilDesc.ArraySize = 1;
	// フォーマット（深度のみ）
	depthStencilDesc.Format = DXGI_FORMAT_D32_FLOAT;
	// マルチサンプリングの設定
	depthStencilDesc.SampleDesc.Count = 1;
	// マルチサンプリングの品質
	depthStencilDesc.SampleDesc.Quality = 0;
	// デフォルトの使用法
	depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
	// 深度／ステンシルとして使用
	depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	// CPUからアクセスする
	depthStencilDesc.CPUAccessFlags = 0;
	// その他の設定なし
	depthStencilDesc.MiscFlags = 0;

	// @brief  : バックバッファのレンダーターゲットを作る
	// @param  : 作成する２Dテクスチャの設定
	// @param  : 
	// @param  : 作成したテクスチャを受け取る変数
	// @return : HRESULT型の変数
	hrlt = pDevice->CreateTexture2D
	(
		&depthStencilDesc,
		nullptr,
		&pDepthStencil
	);

	// 失敗判定
	if (FAILED(hrlt))
	{
		// 関数を抜ける
		return false;
	}
#pragma endregion ステンシル用テクスチャ

#pragma region StencelTarget
	// 深度／ステンシルビューの作成
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	// ビューのフォーマット
	depthStencilViewDesc.Format = depthStencilDesc.Format;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Flags = 0;
	depthStencilViewDesc.Texture2D.MipSlice = 0;

	// @brief  : バックバッファのレンダーターゲットを作る
	// @param  : 深度／ステンシルビューを作るテクスチャ
	// @param  : 深度／ステンシルビューの設定
	// @param  : 作成したビューを受け取る変数
	// @return : HRESULT型の変数
	hrlt = pDevice->CreateDepthStencilView
	(
		pDepthStencil.Get(),
		&depthStencilViewDesc,
		&pDepthStencilView
	);

	// 失敗判定
	if (FAILED(hrlt))
	{
		// 関数を抜ける
		return false;
	}

	// @brief  : 深度／ステンシルビューの使用
	// @param  : 設定するターゲットビューの数
	// @param  : 設定する描画ターゲットビューの配列
	// @param  : 設定する深度／ステンシルビュー
	pContext->OMSetRenderTargets
	(
		1,
		&pRenderTargetView,
		pDepthStencilView.Get()
	);


#pragma endregion ステンシルターゲット

#pragma region GetInterface
	hrlt = pDevice.As(&pInterface);
	// 失敗判定
	if (FAILED(hrlt))
	{
		// 関数を抜ける
		return false;
	}
#pragma endregion インターフェースを取得

#pragma region GetAdapter
	hrlt = pInterface->GetAdapter(&pAdapter);
	// 失敗判定
	if (FAILED(hrlt))
	{
		// 関数を抜ける
		return false;
	}
#pragma endregion アダプタを取得

#pragma region GetFactory
	hrlt = pAdapter->GetParent(__uuidof(IDXGIFactory1), (void**)&pFactory);
	// 失敗判定
	if (FAILED(hrlt))
	{
		// 関数を抜ける
		return false;
	}
#pragma endregion ファクトリを取得

#pragma region ArrowFullScreen
	hrlt = pFactory->MakeWindowAssociation(mHwnd, 0);
	// 失敗判定
	if (FAILED(hrlt))
	{
		// 関数を抜ける
		return false;
	}
#pragma endregion フルスクリーンを許可

	// 関数を抜ける
	return hrlt;
}

void Direct3D::Update()
{
}

void Direct3D::Render()
{
}

void Direct3D::CleanUp()
{
}

// ------------------------------------------------------------------------------------------------ //
// @ brief   : レンダーターゲットビューの生成                                                       //
// @ param   : なし                                                                                 //
// @ return  : なし                                                                                 //
// @ note    :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 
void Direct3D::CreateRenderTargetView()
{
	// @brief  : 描画ターゲットのクリア
	// @param  : クリアする描画ターゲット
	// @param  : クリアする値（RGBA）
	pContext->ClearRenderTargetView
	(
		pRenderTargetView.Get(),
		DxColors::FloralWhite
	);
}

// ------------------------------------------------------------------------------------------------ //
// @ brief   : 深度バッファの生成                                                                   //
// @ param   : なし                                                                                 //
// @ return  : なし                                                                                 //
// @ note    :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 
void Direct3D::CreateDepthStencilView()
{
	// @brief  : 深度／ステンシルのクリア
	// @param  : クリアする深度／ステンシルビュー
	// @param  : 深度値だけクリアする
	// @param  : 深度バッファをクリアする値
	// @param  : ステンシルバッファをクリアする値（この場合、無関係）
	pContext->ClearDepthStencilView
	(
		pDepthStencilView.Get(), 
		D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 
		1.0f,
		0
	);
}

// ------------------------------------------------------------------------------------------------ //
// @ brief   : バックバッファのスワップ                                                             //
// @ param   : なし                                                                                 //
// @ return  : なし                                                                                 //
// @ note    :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 
void Direct3D::SwapBackBaffer()
{
	// @brief  : バックバッファのスワップ
	// @param  : 画面を更新するタイミング（垂直回帰との同時処理を設定する）
	// @param  : 画面を実際に更新する
	pSwapChain->Present(0, 0);
}