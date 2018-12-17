//���������Լ�������"d3dUtility.h"ͷ�ļ�
#include "d3dUtility.h"
 
ID3D11Device* device = NULL;                    //D3D11�豸ָ��
IDXGISwapChain* swapChain = NULL;               //������ָ��
ID3D11DeviceContext* immediateContext = NULL;   //�豸������ָ��
ID3D11RenderTargetView* renderTargetView = NULL;//��ȾĿ����ͼָ��  


//**************����Ϊ��ܺ���******************
bool Setup()
{
	// ������setup����û�����ݣ��Ժ��ʵ���л���������д����.
	return true;
}

void Cleanup()
{
	//�ͷ�ָ��
	if(renderTargetView) renderTargetView->Release();
	if(immediateContext) immediateContext->Release();
	if(swapChain)        swapChain->Release();
	if(device)           device->Release();
}

bool Display(float timeDelta)
{
	if( device )     
	{
		//����һ����������ɫ��Ϣ��4��Ԫ�طֱ��ʾ�죬�̣����Լ�alpha
		float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; 
		//�����ȾĿ����ͼ
		immediateContext->ClearRenderTargetView( renderTargetView, ClearColor );
		//��ʾ��Ⱦ�õ�ͼ����û�
		swapChain->Present( 0,  //ָ�����ͬ����ʾ������0��ʾ��ͬ����ʾ
			                0 );//��ѡ�����0��ʾΪ��ÿ����������ʾһ֡
	}
	return true;
}
//**************��ܺ�����д����*****************


//
// �ص���������ʵ��һ�еĻص���������һ��
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
// ������WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
	
	//��ʼ��
	//**ע��**:������������4��ָ�룬��������Ϊ��������InitD3D����
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

	//ִ����Ϣѭ����������Display��ָ����Ϊ��������
	d3d::EnterMsgLoop( Display );

	Cleanup();

	return 0;
}