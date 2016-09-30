#pragma once

struct SMapChipLocInfo {
	const char* modelName;		//モデル。
	D3DXVECTOR3 pos;			//座標。
	D3DXQUATERNION rotation;		//回転。
};

class MapChip{
public:
	void init(SMapChipLocInfo map);
	void Update();
	void Draw();
private:
	SkinModel model;
	SkinModelData modelData;
	Light light;

	D3DXVECTOR3 m_pos;			//座標。
	D3DXQUATERNION m_rotation;		//回転。

};

extern Camera* camera;