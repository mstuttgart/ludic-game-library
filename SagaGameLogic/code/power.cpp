#include "power.h"
using namespace sgl;
StatValue PowerStatSet::getBaseProtection() const {
	return baseProtection;
}
StatValue PowerStatSet::getNormalProtection() const {
	return normalProtection;
}
StatValue PowerStatSet::getMagicProtection() const {
	return magicProtection;
}
StatValue PowerStatSet::getRandomDamage() const {
	return randomDamage;
}
StatValue PowerStatSet::getMeleeDamage() const {
	return meleeDamage;
}
StatValue PowerStatSet::getRangedDamage() const {
	return rangedDamage;
}
StatValue PowerStatSet::getTotalTech() const {
	return totalTech;
}
StatValue PowerStatSet::getMagicPower() const {
	return magicPower;
}
//------------------------------------------------------------------------------
PowerStatSet::PowerStatSet(StatValue baseProtection, StatValue normalProtection, 
	StatValue magicProtection, StatValue randomDamage, StatValue meleeDamage, 
	StatValue rangedDamage, StatValue totalTech, StatValue magicPower):
	baseProtection(baseProtection), normalProtection(normalProtection),
	magicProtection(magicProtection), randomDamage(randomDamage),
	meleeDamage(meleeDamage), rangedDamage(rangedDamage), 
	totalTech(totalTech), magicPower(magicPower) {}
//------------------------------------------------------------------------------
void PowerStatSet::modBaseProtection(StatValue value) {
	baseProtection+=value;
	modNormalProtection(value);
	modMagicProtection(value);
}
void PowerStatSet::modNormalProtection(StatValue value) {
	normalProtection+=value;
}
void PowerStatSet::modMagicProtection(StatValue value) {
	magicProtection+=value;
}
void PowerStatSet::modRandomDamage(StatValue value) {
	randomDamage+=value;
}
void PowerStatSet::modMeleeDamage(StatValue value) {
	meleeDamage+=value;
}
void PowerStatSet::modRangedDamage(StatValue value) {
	rangedDamage+=value;
}
void PowerStatSet::modTotalTech(StatValue value) {
	totalTech+=value;
}
void PowerStatSet::modMagicPower(StatValue value) {
	magicPower+=value;
}
//------------------------------------------------------------------------------
void PowerStatSet::modPowerStatSet(StatValue baseProtection, StatValue normalProtection, 
	StatValue magicProtection, StatValue randomDamage, StatValue meleeDamage, 
	StatValue rangedDamage, StatValue totalTech, StatValue magicPower) {
	modBaseProtection(baseProtection);
	modNormalProtection(normalProtection);
	modMagicProtection(magicProtection);
	modRandomDamage(randomDamage);
	modMeleeDamage(meleeDamage);
	modRangedDamage(rangedDamage);
	modTotalTech(totalTech);
	modMagicPower(magicPower);
}