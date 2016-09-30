#include "stdafx.h"
#include "Map.h"
#include "MapChip.h"

using namespace std;
namespace {
	//マップチップの配置情報のテーブル。
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
	//配置情報からマップを構築
	int tableSize = sizeof(mapChipLocInfoTable) / sizeof(mapChipLocInfoTable[0]);
	for (int m = 0; m < tableSize; m++) {
		//マップチップを生成
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