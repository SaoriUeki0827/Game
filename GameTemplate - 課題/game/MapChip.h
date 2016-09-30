#pragma once

struct SMapChipLocInfo {
	const char* modelName;		//���f���B
	D3DXVECTOR3 pos;			//���W�B
	D3DXQUATERNION rotation;		//��]�B
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

	D3DXVECTOR3 m_pos;			//���W�B
	D3DXQUATERNION m_rotation;		//��]�B

};

extern Camera* camera;