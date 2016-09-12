/*!
 *@brief	ゲームテンプレート。
 */
#include "stdafx.h"
#include "lib/Camera.h"
#include "lib/Light.h"
#include "Player.h"
#include "Floor.h"

Player* player;
Floor* g_floor;
Camera* camera;
D3DXVECTOR3	toPosition;

//-----------------------------------------------------------------------------
// Name: ゲームを初期化。
//-----------------------------------------------------------------------------
void Init()
{
	camera = new Camera;
	player = new Player;
	g_floor = new Floor;
	player->Start();
	g_floor->Start();
	camera->Init();
	camera->SetEyePt(player->GetPos()+D3DXVECTOR3(0.0f,3.0f,6.0f));
	camera->SetLookatPt(player->GetPos());
	camera->Update();
	toPosition = camera->GetEyePt() - camera->GetLookatPt();
}
//-----------------------------------------------------------------------------
// Name: 描画処理。
//-----------------------------------------------------------------------------
VOID Render()
{
	// 画面をクリア。
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	//シーンの描画開始。
	g_pd3dDevice->BeginScene();

	player->Render();
	g_floor->Render();

	// シーンの描画終了。
	g_pd3dDevice->EndScene();
	// バックバッファとフロントバッファを入れ替える。
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
/*!-----------------------------------------------------------------------------
 *@brief	更新処理。
 -----------------------------------------------------------------------------*/

D3DXMATRIX				rotateMatrix;		//!<回転行列。
void Update()
{
	player->Update();
	g_floor->Update();

	D3DXVECTOR4 toPositionOut = toPosition;
	D3DXVECTOR3 newCameraPos;
	if (GetAsyncKeyState('A')){
		D3DXMatrixRotationY(&rotateMatrix, 0.1f);
		//第一引数に回転結果の格納先、二引数に回転させるベクトル、3に回転行列
		D3DXVec3Transform(&toPositionOut, &toPosition, &rotateMatrix);
	}
	if (GetAsyncKeyState('D')){
		D3DXMatrixRotationY(&rotateMatrix, -0.1f);
		//第一引数に回転結果の格納先、二引数に回転させるベクトル、3に回転行列
		D3DXVec3Transform(&toPositionOut, &toPosition, &rotateMatrix);
	}
	if (GetAsyncKeyState('W')){
		D3DXVECTOR3 vUP(0.0f, 1.0f, 0.0f);
		//外積計算
		D3DXVECTOR3 RotAxis;
		//第一引数が計算結果の格納先、第二引数と第三引数が外積に使用されるベクトル
		D3DXVec3Cross(&RotAxis, &toPosition, &vUP);
		D3DXVec3Normalize(&RotAxis, &RotAxis);
		//RotAxisの角度が一定のものだったら
			D3DXMatrixRotationAxis(&rotateMatrix, &RotAxis, 0.1f);
		//第一引数に回転結果の格納先、二引数に回転させるベクトル、3に回転行列
		D3DXVec3Transform(&toPositionOut, &toPosition, &rotateMatrix);
	}
	if (GetAsyncKeyState('S')){
		D3DXVECTOR3 vUP(0.0f, 1.0f, 0.0f);
		//外積計算
		D3DXVECTOR3 RotAxis;
		//第一引数が計算結果の格納先、第二引数と第三引数が外積に使用されるベクトル
		D3DXVec3Cross(&RotAxis, &toPosition, &vUP);
		D3DXVec3Normalize(&RotAxis,&RotAxis);
		D3DXMatrixRotationAxis(&rotateMatrix, &RotAxis, -0.1f);
		//第一引数に回転結果の格納先、二引数に回転させるベクトル、3に回転行列
		D3DXVec3Transform(&toPositionOut, &toPosition, &rotateMatrix);
	}
	newCameraPos.x = camera->GetLookatPt().x + toPositionOut.x;
	newCameraPos.y = camera->GetLookatPt().y + toPositionOut.y;
	newCameraPos.z = camera->GetLookatPt().z + toPositionOut.z;
	camera->SetEyePt(newCameraPos);
	toPosition = camera->GetEyePt() - camera->GetLookatPt();
	camera->SetLookatPt(player->GetPos());
	camera->Update();
}
//-----------------------------------------------------------------------------
//ゲームが終了するときに呼ばれる処理。
//-----------------------------------------------------------------------------
void Terminate()
{
	delete player;
	delete g_effectManager;
	g_pd3dDevice->Release();
	g_pD3D->Release();
}
