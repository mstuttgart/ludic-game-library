#include "equipitem.h"
using namespace sgl;
Rarity Item::getRarity() const {
	return rarity;
}
StatValue Item::getLoad() const {
	return load;
}
Currency Item::getPrice() const {
	return price;
}
Item::Item(Rarity rarity, StatValue load, Currency price):
	rarity(rarity), load(load), price(price) {}
void Item::setRarity(Rarity value) {
	rarity=value;
}
void Item::setLoad(StatValue value) {
	load=value;
}
void Item::setPrice(Currency value) {
	price=value;
}
//------------------------------------------------------------------------------
StatValue Material::getMineralValue() const {
	return mineralValue;
}
StatValue Material::getVegetalValue() const {
	return vegetalValue;
}
StatValue Material::getAnimalValue() const {
	return animalValue;
}
StatValue Material::getMagicValue() const {
	return magicValue;
}
Material::Material(
	StatValue mineralValue, StatValue vegetalValue, 
	StatValue animalValue, StatValue magicValue):
	mineralValue(mineralValue), vegetalValue(vegetalValue),
	animalValue(animalValue), magicValue(magicValue) {}
void Material::setMineralValue(StatValue value) {
	mineralValue=value;
}
void Material::setVegetalValue(StatValue value) {
	vegetalValue=value;
}
void Material::setAnimalValue(StatValue value) {
	animalValue=value;
}
void Material::setMagicValue(StatValue value) {
	magicValue=value;
}
void Material::use(Character& individual) {}
//------------------------------------------------------------------------------
const StatStruct& BoostItem::getModification() const {
	return modification;
}
RoundTime BoostItem::getDuration() const {
	return duration;
}
BoostItem::BoostItem(const StatStruct& modification, RoundTime duration):
	modification(modification), duration(duration) {}
void BoostItem::setDuration(RoundTime value) {
	duration=value;
}
void BoostItem::use(Character& individual) {}
//------------------------------------------------------------------------------
StatStruct* EquipItem::getModification() const {
	return modification;
}
EquipItem::EquipItem(): modification(nullptr) {}
void EquipItem::setModification(StatStruct& value) {
	delete modification;
	modification=new StatStruct(value);
}
void EquipItem::setModification() {
	delete modification;
	modification=nullptr;
}	
void EquipItem::aux(EquipItemSet& individual, bool activating) const {
	if(modification) modification->modCharStat((Character&)individual, activating);
}