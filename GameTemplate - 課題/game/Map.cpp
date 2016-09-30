#include "stdafx.h"
#include "Map.h"
#include "MapChip.h"

using namespace std;
namespace {
	//�}�b�v�`�b�v�̔z�u���̃e�[�u���B
	SMapChipLocInfo mapChipLocInfoTable[] = {
#include "locationInfo.h"
	};
}
Map::Map()
{

}
Map::~Map()
{

}

void Map::Start()
{
	//�z�u��񂩂�}�b�v���\�z
	int tableSize = sizeof(mapChipLocInfoTable) / sizeof(mapChipLocInfoTable[0]);
	for (int m = 0; m < tableSize; m++) {
		//�}�b�v�`�b�v�𐶐�
		MapChip* mapChip = new MapChip;
		//Func(mapChipLocInfoTable[m]);
		mapChip->init(mapChipLocInfoTable[m]);
		mapChipList.push_back(mapChip);
	}
}
void Func(SMapChipLocInfo map){}
void Map::Update()
{
	for (int m = 0; m < mapChipList.size(); m++){
		mapChipList[m]->Update();
	}
}
void Map::Render()
{
	for (int m = 0; m < mapChipList.size(); m++){
		mapChipList[m]->Draw();
	}
}