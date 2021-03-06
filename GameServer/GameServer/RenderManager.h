#pragma once
#include "Texture.h"
#include "Mesh.h"
#include "StaticMesh.h"
#include "DynamicMesh.h"
#include "TerrainMesh.h"
#include "NavMesh.h"

namespace PKH
{

	class RenderManager
	{
	private:
		RenderManager();
		~RenderManager();

	public:
		static RenderManager* GetInstance();
		static void Destroy();

		static HRESULT Initialize(int screenW, int screenH);
		static void Release();

		static void Clear();
		static void Present(HWND renderTarget = nullptr);

		static LPDIRECT3DDEVICE9 GetDevice();
		static LPD3DXSPRITE GetSprite();
		static Texture* GetTexture(const wstring& _key);
		static LPD3DXLINE GetLine();
		static TextureID GetTextureID(const wstring& _key);
		static wstring GetTextureKey(TextureID id);

		//================== 2D ======================
		static HRESULT LoadSprite(const wstring& filePath, const wstring& fileName, DWORD row=1, DWORD col=1);
		//=========================================

		//=================== SR ==================

		static HRESULT LoadTexture( const wstring& filePath, const wstring& fileName);
		static HRESULT LoadCubeTexture(const wstring& filePath, const wstring& fileName);
		static void SetTexture(const wstring& id);

		//=========================================

		//=================== Device 관련 ==================
		static void LockDevice();
		static void UnlockDevice();

		static HRESULT SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX* pMatrix);
		//static CreateVertexBuffer()

		//==================================================

		//======================= 3D =======================

		static HRESULT LoadStaticMesh(const WCHAR* pFilePath, const WCHAR* pFileName);
		static StaticMesh* CloneStaticMesh(const wstring& id);
		static HRESULT LoadDynamicMesh(const WCHAR* pFilePath, const WCHAR* pFileName);
		static DynamicMesh* CloneDynamicMesh(const wstring& id);
		static HRESULT LoadTerrainMesh(const WCHAR* pFilePath, const WCHAR* pFileName);
		static TerrainMesh* CloneTerrainMesh(const wstring& id);
		static HRESULT LoadNavMesh(const WCHAR* pFilePath, const WCHAR* pFileName);
		static NavMesh* CloneNavMesh(const wstring& id);

		//==================================================

	private:
		// 실질적으로 장치를 다룰 객체. 
		LPDIRECT3DDEVICE9 pDevice = nullptr;
		LPDIRECT3D9 pSDK = nullptr;
		LPD3DXSPRITE pSprite = nullptr;
		LPD3DXFONT	pFont = nullptr;
		LPD3DXLINE pLine = nullptr;



		map<wstring, Texture*> textureMap;
		map<TextureID, wstring> textureIDMap;
		map<wstring, StaticMesh*> staticMeshMap;
		map<wstring, DynamicMesh*> dynamicMeshMap;
		map<wstring, TerrainMesh*> terrainMeshMap;
		map<wstring, NavMesh*> navMeshMap;

		CRITICAL_SECTION csDevice;
		
	};


}
