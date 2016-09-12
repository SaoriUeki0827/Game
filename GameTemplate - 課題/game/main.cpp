/*!
 *@brief	�Q�[���e���v���[�g�B
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
// Name: �Q�[�����������B
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
// Name: �`�揈���B
//-----------------------------------------------------------------------------
VOID Render()
{
	// ��ʂ��N���A�B
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	//�V�[���̕`��J�n�B
	g_pd3dDevice->BeginScene();

	player->Render();
	g_floor->Render();

	// �V�[���̕`��I���B
	g_pd3dDevice->EndScene();
	// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ���B
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
/*!-----------------------------------------------------------------------------
 *@brief	�X�V�����B
 -----------------------------------------------------------------------------*/

D3DXMATRIX				rotateMatrix;		//!<��]�s��B
void Update()
{
	player->Update();
	g_floor->Update();

	D3DXVECTOR4 toPositionOut = toPosition;
	D3DXVECTOR3 newCameraPos;
	if (GetAsyncKeyState('A')){
		D3DXMatrixRotationY(&rotateMatrix, 0.1f);
		//�������ɉ�]���ʂ̊i�[��A������ɉ�]������x�N�g���A3�ɉ�]�s��
		D3DXVec3Transform(&toPositionOut, &toPosition, &rotateMatrix);
	}
	if (GetAsyncKeyState('D')){
		D3DXMatrixRotationY(&rotateMatrix, -0.1f);
		//�������ɉ�]���ʂ̊i�[��A������ɉ�]������x�N�g���A3�ɉ�]�s��
		D3DXVec3Transform(&toPositionOut, &toPosition, &rotateMatrix);
	}
	if (GetAsyncKeyState('W')){
		D3DXVECTOR3 vUP(0.0f, 1.0f, 0.0f);
		//�O�όv�Z
		D3DXVECTOR3 RotAxis;
		//���������v�Z���ʂ̊i�[��A�������Ƒ�O�������O�ςɎg�p�����x�N�g��
		D3DXVec3Cross(&RotAxis, &toPosition, &vUP);
		D3DXVec3Normalize(&RotAxis, &RotAxis);
		//RotAxis�̊p�x�����̂��̂�������
			D3DXMatrixRotationAxis(&rotateMatrix, &RotAxis, 0.1f);
		//�������ɉ�]���ʂ̊i�[��A������ɉ�]������x�N�g���A3�ɉ�]�s��
		D3DXVec3Transform(&toPositionOut, &toPosition, &rotateMatrix);
	}
	if (GetAsyncKeyState('S')){
		D3DXVECTOR3 vUP(0.0f, 1.0f, 0.0f);
		//�O�όv�Z
		D3DXVECTOR3 RotAxis;
		//���������v�Z���ʂ̊i�[��A�������Ƒ�O�������O�ςɎg�p�����x�N�g��
		D3DXVec3Cross(&RotAxis, &toPosition, &vUP);
		D3DXVec3Normalize(&RotAxis,&RotAxis);
		D3DXMatrixRotationAxis(&rotateMatrix, &RotAxis, -0.1f);
		//�������ɉ�]���ʂ̊i�[��A������ɉ�]������x�N�g���A3�ɉ�]�s��
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
//�Q�[�����I������Ƃ��ɌĂ΂�鏈���B
//-----------------------------------------------------------------------------
void Terminate()
{
	delete player;
	delete g_effectManager;
	g_pd3dDevice->Release();
	g_pD3D->Release();
}
