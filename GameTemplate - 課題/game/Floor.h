/*!
* @brief	�w�i(��)�N���X�B
*/

#pragma once

class Floor{
public:
	Floor();
	~Floor();
	void Start();
	void Update();
	void Render();
private:
	Camera camera;
	SkinModel model;
	SkinModelData modelData;
	Light light;
	D3DXVECTOR3				position;		//���W�B
	D3DXMATRIX				mWorld;			//���[���h�s��B
};
extern Floor* g_floor;