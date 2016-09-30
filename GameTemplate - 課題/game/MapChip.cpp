#include "stdafx.h"
#include "MapChip.h"


void MapChip::init(SMapChipLocInfo map){

	//tableSize=テーブルの要素数
	char modelPath[256];
	sprintf(modelPath, "%s.X", map.modelName);
	modelData.LoadModelData(modelPath,0);

	light.SetDiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetDiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetDiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetAmbientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	//モデルをロード。

	model.Init(&modelData);
	model.SetLight(&light);
	m_pos = map.pos;
	m_rotation = map.rotation;
}

void MapChip::Update()
{
	model.UpdateWorldMatrix(m_pos, m_rotation, D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}

void MapChip::Draw()
{
	model.Draw(&camera->GetViewMatrix(), &camera->GetProjectionMatrix());
}