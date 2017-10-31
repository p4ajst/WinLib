//// ------------------------------------------------------------------------------------------------ //
//// @ file   : Direct3D.h                                                                           //
//// @ brief  : DirectX関連のクラス                                                                  //
//// @ date   : 2017/10/29                                                                           //
//// @ author : Madoka Nakajima                                                                      //
//// @ note   :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//
///* ヘッダファイルのインクルード */
//// 自作ヘッダファイル
//#include "Direct3D.h"
//#include "../../Utility/Color.h"
//
///* 名前空間 */
//// 自作名前空間
//using namespace mnLib;
//
///* マクロの定義 */
//#pragma region DefinitionMacro
//// 開放用マクロ
//#define SAFE_RELEASE(x){if(x){(x)->Releace();(x) = NULL}}
//#pragma endregion マクロの定義
//
//
///* 定数の定義 */
///* 変数の定義 */
///* 列挙体の定義 */
///* 構造体の定義 */
///* メンバ関数の定義 */
///* 関数の定義 */
//
//// ------------------------------------------------------------------------------------------------ //
//// @ brief   : 初期化                                                                               //
//// @ param   : HWND whandle....ウインドウハンドル                                                   //
//// @ return  : HRESULT....HRESULTが０なら正常、それ以外の値なら異常。                               //
//// @ note    :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//HRESULT Direct3D::Initialize(HWND windowHandle)
//{
//	// 戻り値
//	HRESULT hrlt;
//#pragma region InitMemberVariable
//	mHwnd = windowHandle;
//	//pDevice.Reset();
//	//pContext.Reset();
//	//pSwapChain.Reset();
//	//pRenderTargetView.Reset();
//	//pBackBuffer.Reset();
//	//pDepthStencil.Reset();
//	//pDepthStencilView.Reset();
//	//pInterface.Reset();
//	//pAdapter.Reset();
//	//pFactory.Reset();
//	
//	pDevice = nullptr;
//	pContext = nullptr;
//	pSwapChain = nullptr;
//	pRenderTargetView = nullptr;
//	pBackBuffer = nullptr;
//	pDepthStencil = nullptr;
//	pDepthStencilView = nullptr;
//	pInterface = nullptr;
//	pAdapter = nullptr;
//	pFactory = nullptr;
//
//	mWidth = 0;
//	mHeight = 0;
//#pragma endregion メンバ変数の初期化
//
//#pragma region SetScreenSize
//	// クライアント領域を格納する変数
//	RECT rc;
//
//	// クライアント領域の取得
//	GetClientRect(mHwnd, &rc);
//	// 幅の計算
//	mWidth = rc.right - rc.left;
//	// 高さの計算
//	mHeight = rc.bottom - rc.top;
//
//#pragma endregion クライアント領域を取得して画面サイズを算出
//
//#pragma region FunctionLevel
//	// シェーダーモデル５などのDirect3D 11.0 でサポートされている機能をターゲットとする
//	// 機能レベルの配列
//	D3D_FEATURE_LEVEL dfl[] =
//	{
//		D3D_FEATURE_LEVEL_11_1,
//		D3D_FEATURE_LEVEL_11_0,
//		D3D_FEATURE_LEVEL_10_1,
//		D3D_FEATURE_LEVEL_10_0,
//		D3D_FEATURE_LEVEL_9_3,
//		D3D_FEATURE_LEVEL_9_2,
//		D3D_FEATURE_LEVEL_9_1,
//	};
//	// 配列の要素数
//	UINT featurelefels = 7;
//	// デバイス作成時に返される機能レベル
//	D3D_FEATURE_LEVEL dfl_Supported = D3D_FEATURE_LEVEL_11_1;
//#pragma endregion 機能レベルの配列
//
//#pragma region SetSwapChain
//
//	/* デバイスとスワップチェインの設定 */
//	DXGI_SWAP_CHAIN_DESC swapChainDesc;
//	// 構造体の値を初期化
//	SecureZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
//	// バックバッファの数
//	swapChainDesc.BufferCount = 2;
//	/// ディスプレイモードを設定する構造体
//	// バックバッファの幅
//	swapChainDesc.BufferDesc.Width = 640;
//	// バックバッファの高さ
//	swapChainDesc.BufferDesc.Height = 480;
//	// ディスプレイフォーマット
//	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//	// リフレッシュレート（分子）
//	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
//	// リフレッシュレート（分母）
//	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
//	// スキャンライン描画モード
//	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
//	// スケーリングモード
//	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
//	/// バックバッファの使われ方を指定するフラグ
//	/// バックバッファはシェーダ入力または描画ターゲットとして使うことができる
//	// バックバッファの使用法
//	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//	/// 出力先ウインドウのハンドル
//	// 関連付けるウインドウ
//	swapChainDesc.OutputWindow = windowHandle;
//	// マルチサンプルの数
//	swapChainDesc.SampleDesc.Count = 1;
//	// マルチサンプルのクオリティ
//	swapChainDesc.SampleDesc.Quality = 0;
//	/// スワップ効果を指定するフラグ
//	/// 画面モードの設定
//	/// ウインドウモードであれば「TRUE」
//	/// フルスクリーンモードであれば「False」
//	// ウインドウモード
//	swapChainDesc.Windowed = TRUE;
//	// スワップ効果
//	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
//	// モードの自動切り替え
//	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
//
//#pragma endregion スワップチェインの設定
//
//#pragma region CreateDeviceAndSwapChain
//	// @brief  : 「ID3D11Deviceインターフェース」と「ID3D11DiveceContextインターフェース」と「IDXGISwapChainインターフェース」を同時に作成
//	// @param  : IDXGIAdapter* pAdapter....表示に使うディスプレイデバイスを指定
//	// @param  : D3D_DRIVER_TYPE DriverType....デバイスのドライバタイプを指定
//	// @param  : HMODULE SoftWare....ソフトウェアラスタライザが実装されているDLLのハンドルを指定
//	// @param  : UINT Flags....使用するDirect3D 11のAPIレイヤーを列挙型の組み合わせで指定する
//	// @param  : const D3D_FEATURE_LEVEL* pFeatureLevel....作成を試みる機能レベルを優先順位の高い順に並べた配列
//	// @param  : UINT FeatureLevels....pFeatureLevelで指定した配列の要素数
//	// @param  : UINT SDKVersion....SDKバージョンを指定
//	// @param  : const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc....作るスワップチェインの設定を記述する構造体を渡す
//	// @param  : IDXGISwapChain** ppSwapChain....作られたスワップチェインのインターフェースを受け取る変数のポインタを渡す
//	// @param  : ID3D11Device ppDevice....作ったデバイスのインターフェースを受け取る変数のポインタを渡す
//	// @param  : D3D_FEATURE_LEVEL* pFeatureLevel....サポートされている機能レベルを受け取る変数のポインタ
//	// @param  : ID3D11DeviceContext** ppImmidiateContext....作ったデバイスコンテキストのインターフェースを受け取る変数のポインタを渡す
//
//
//
//#pragma endregion デバイスとスワップチェインの作成
//
//
//
//#pragma region StencilTexture
//
//
//#pragma endregion ステンシル用テクスチャ
//
//#pragma region StencelTarget
//
//#pragma endregion ステンシルターゲット
//
//#pragma region GetBackBuffer
//
//#pragma endregion スワップチェインのバックバッファを取得
//
//#pragma region CreateRenderTarget
//
//#pragma endregion バックバッファから描画ターゲットを生成
//
//#pragma region SetContext
//
//#pragma endregion 描画ターゲットをコンテキストに設定
//
//#pragma region SetViewport
//
//#pragma endregion ビューポートの設定
//
//#pragma region GetInterface
//
//#pragma endregion インターフェースを取得
//
//#pragma region GetAdapter
//
//#pragma endregion ファクトリを取得
//
//#pragma region ArrowFullScreen
//
//
//#pragma endregion フルスクリーンを許可
//
//
//
//
//
//	return hrlt;
//}
//
//void Direct3D::Update()
//{
//}
//
//void Direct3D::Render()
//{
//}
//
//void Direct3D::CleanUp()
//{
//	delete pDevice;
//	delete pContext;
//	delete pSwapChain;
//	delete pRenderTargetView;
//	delete pBackBuffer;
//	delete pDepthStencil;
//	delete pDepthStencilView;
//	delete pInterface;
//	delete pAdapter;
//	delete pFactory;
//}
//
//// ------------------------------------------------------------------------------------------------ //
//// @ brief   : レンダーターゲットビューの生成                                                       //
//// @ param   : なし                                                                                 //
//// @ return  : なし                                                                                 //
//// @ note    :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//void Direct3D::CreateRenderTargetView()
//{
//	// 生成
//	//pContext->ClearRenderTargetView(pRenderTargetView.Get(), DxColors::FloralWhite);
//	pContext->ClearRenderTargetView(pRenderTargetView, DxColors::FloralWhite);
//
//}
//
//// ------------------------------------------------------------------------------------------------ //
//// @ brief   : 深度バッファの生成                                                                   //
//// @ param   : なし                                                                                 //
//// @ return  : なし                                                                                 //
//// @ note    :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//void Direct3D::CreateDepthStencilView()
//{
//	// 生成
//	//pContext->ClearDepthStencilView(pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
//	pContext->ClearDepthStencilView(pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
//}
//
//// ------------------------------------------------------------------------------------------------ //
//// @ brief   : バックバッファのスワップ                                                             //
//// @ param   : なし                                                                                 //
//// @ return  : なし                                                                                 //
//// @ note    :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//void Direct3D::SwapBackBaffer()
//{
//	// バックバッファのスワップ
//	pSwapChain->Present(0, 0);
//}
