//这是我们自己创建的"d3dUtility.h"头文件
#include "d3dUtility.h"
 
ID3D11Device* device = NULL;                    //D3D11设备指针
IDXGISwapChain* swapChain = NULL;               //交换链指针
ID3D11DeviceContext* immediateContext = NULL;   //设备上下文指针
ID3D11RenderTargetView* renderTargetView = NULL;//渲染目标视图指针  


//**************以下为框架函数******************
bool Setup()
{
	// 本例中setup函数没有内容，以后的实验中会往里面填写内容.
	return true;
}

void Cleanup()
{
	//释放指针
	if(renderTargetView) renderTargetView->Release();
	if(immediateContext) immediateContext->Release();
	if(swapChain)        swapChain->Release();
	if(device)           device->Release();
}

bool Display(float timeDelta)
{
	if( device )     
	{
		//声明一个数组存放颜色信息，4个元素分别表示红，绿，蓝以及alpha
		float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; 
		//清楚渲染目标视图
		immediateContext->ClearRenderTargetView( renderTargetView, ClearColor );
		//显示渲染好的图像给用户
		swapChain->Present( 0,  //指定如何同步显示，设置0表示不同步显示
			                0 );//可选项，设置0表示为从每个缓存中显示一帧
	}
	return true;
}
//**************框架函数编写结束*****************


//
// 回调函数，和实验一中的回调函数基本一样
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
		
	case WM_KEYDOWN:
		if( wParam == VK_ESCAPE )
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

//
// 主函数WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
	
	//初始化
	//**注意**:最上面声明的4个指针，在这里作为参数传给InitD3D函数
	if(!d3d::InitD3D(hinstance,
		            800,
					600,
					&renderTargetView,
		            &immediateContext,
		            &swapChain,     
		            &device))
	{
		::MessageBox(0, L"InitD3D() - FAILED", 0, 0);
		return 0;
	}
		
	if(!Setup())
	{
		::MessageBox(0, L"Setup() - FAILED", 0, 0);
		return 0;
	}

	//执行消息循环，将函数Display的指针作为参数传递
	d3d::EnterMsgLoop( Display );

	Cleanup();

	return 0;
}