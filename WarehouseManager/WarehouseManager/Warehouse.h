#pragma once
#include <cstdint>
#include <vector>
#include <string>

using namespace std;

class Warehouse {
private:
	static uint32_t idCounter;
	const uint32_t id;
	uint32_t floorIdCounter = 0;
	vector<Floor> floors;
public:
	Warehouse();
	
	size_t addFloor();

	void addGoodsCollection(uint32_t floorNr, GoodsCollection goodsCollection);
	static void setIdCounter(uint32_t value);
};

class Floor {
private:
	uint32_t id;
	uint32_t goodsCollectionId = 0;
	vector<GoodsCollection> goodsCollections;
public:
	Floor(uint32_t id);
	void addGoodsCollection(GoodsCollection goodsCollection);
};

class GoodsCollection {
private:
	uint32_t id;
	vector<Good> goods;
public:
	GoodsCollection(uint32_t id);
	void addGood(Good good);
};

class Good {
private:
	GoodInformation goodInfo;
	uint32_t quantity;
public:
	Good(GoodInformation goodInfo, uint32_t quantity);
	void setQuantity(uint32_t newQuantity);
};

class GoodInformation {
private:
	static uint32_t idCounter;
	uint32_t id;
	string name;
	float weight;
public:
	GoodInformation(string name);
	GoodInformation(string name, float weight);
	void setWeight(float newWeight);
};
