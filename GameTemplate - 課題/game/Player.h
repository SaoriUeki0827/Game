/*!
 * @brief	�Q�[���N���X�B
 */

#pragma once


/*!
 * @brief	�Q�[���N���X�B
 */
class Player{
public:
	Player();
	~Player();
	void Start();
	void Update();
	void Render();
	D3DXVECTOR3 GetPos(){ return position; }
private:
	SkinModel model;
	SkinModelData modelData;
	Animation animation;
	Light light;
	D3DXVECTOR3				position;		//���W�B
	D3DXQUATERNION			rotate;		//��]���W�B
	D3DXMATRIX				mWorld;			//���[���h�s��B
	D3DXMATRIX				mRotation;		//��]�s��B
	bool animeFlg;
};

extern Player* player;
extern Camera* camera;