#include "equip.h"
#include "character.h"
using namespace sgl;
//------------------------------------------------------------------------------
StatValue Armor::getVigorDefense() const {
	return vigorDefense;
}
StatValue Armor::getNormalProtection() const {
	return normalProtection;
}
StatValue Armor::getLifeEnergy() const {
	return lifeEnergy;
}
Armor::Armor(
	StatValue vigorDefense, StatValue normalProtection, StatValue lifeEnergy): 
	vigorDefense(vigorDefense), normalProtection(normalProtection), lifeEnergy(lifeEnergy) {}
void Armor::setVigorDefense(StatValue value) {
	vigorDefense=value;
}
void Armor::setNormalProtection(StatValue value) {
	normalProtection=value;
}
void Armor::setLifeEnergy(StatValue value) {
	lifeEnergy=value;
}
void Armor::use(Character& individual) {
	individual.modArmor(*this);
}
//------------------------------------------------------------------------------
StatValue Veil::getWillDefense() const {
	return willDefense;
}
StatValue Veil::getMagicProtection() const {
	return magicProtection;
}
StatValue Veil::getMagicEnergy() const {
	return magicEnergy;
}
Veil::Veil(
	StatValue willDefense, StatValue magicProtection, StatValue magicEnergy):
	willDefense(willDefense), magicProtection(magicProtection), magicEnergy(magicEnergy) {}
void Veil::setWillDefense(StatValue value) {
	willDefense=value;
}
void Veil::setMagicProtection(StatValue value) {
	magicProtection=value;
}
void Veil::setMagicEnergy(StatValue value) {
	magicEnergy=value;
}
void Veil::use(Character& individual) {
	individual.modVeil(*this);
}
//------------------------------------------------------------------------------
Size Weapon::getSize() const {
	return size;
}
AttackType Weapon::getAttackType() const {
	return attackType;
}
DamageType Weapon::getDamageType() const {
	return damageType;
}
TimeUnit Weapon::getActionTime() const {
	return actionTime;
}
StatValue Weapon::getRandomDamage() const {
	return randomDamage;
}
StatValue Weapon::getNormalDamage() const {
	return normalDamage;
}
StatValue Weapon::getMagicPower() const {
	return magicPower;
}
//------------------------------------------------------------------------------
Weapon::Weapon(Size size, AttackType attackType, DamageType damageType, 
	TimeUnit actionTime, StatValue randomDamage, StatValue normalDamage, 
	StatValue magicPower): size(size), attackType(attackType), 
	damageType(damageType), actionTime(actionTime), randomDamage(randomDamage), 
	normalDamage(normalDamage), magicPower(magicPower) {}
void Weapon::use(Character& individual) {
	individual.modWeapon(*this);
}
//------------------------------------------------------------------------------
void Weapon::setSize(Size value) {
	size=value;
}
void Weapon::setAttackType(AttackType value) {
	attackType=value;
}
void Weapon::setDamageType(DamageType value) {
	damageType=value;
}
void Weapon::setActionTime(TimeUnit value) {
	actionTime=value;
}
void Weapon::setRandomDamage(StatValue value) {
	randomDamage=value;
}
void Weapon::setNormalDamage(StatValue value) {
	normalDamage=value;
}
void Weapon::setMagicPower(StatValue value) {
	magicPower=value;
}
//------------------------------------------------------------------------------
StatValue Shield::getReflexDefense() const {
	return reflexDefense;
}
StatValue Shield::getNormalProtection() const {
	return normalProtection;
}
StatValue Shield::getMagicProtection() const {
	return magicProtection;
}
Shield::Shield(StatValue reflexDefense, StatValue normalProtection, 
	StatValue magicProtection): reflexDefense(reflexDefense), 
	normalProtection(normalProtection), magicProtection(magicProtection) {}
void Shield::setReflexDefense(StatValue value) {
	reflexDefense=value;
}
void Shield::setNormalProtection(StatValue value) {
	normalProtection=value;
}
void Shield::setMagicProtection(StatValue value) {
	magicProtection=value;
}
void Shield::use(Character& individual) {
	individual.modShield(*this);
}
//------------------------------------------------------------------------------
StatValue Accessory::getMeleeAttack() const {
	return meleeAttack;
}
StatValue Accessory::getRangedAttack() const {
	return rangedAttack;
}
StatValue Accessory::getMeleeDamage() const {
	return meleeDamage;
}
StatValue Accessory::getRangedDamage() const {
	return rangedDamage;
}
Accessory::Accessory(
	StatValue meleeAttack, StatValue rangedAttack,
	StatValue meleeDamage, StatValue rangedDamage):
	meleeAttack(meleeAttack), rangedAttack(rangedAttack),
	meleeDamage(meleeDamage), rangedDamage(rangedDamage) {}
void Accessory::setMeleeDamage(StatValue value) {
	meleeDamage=value;
}
void Accessory::setMeleeAttack(StatValue value) {
	meleeAttack=value;
}
void Accessory::setRangedAttack(StatValue value) {
	rangedAttack=value;
}
void Accessory::setRangedDamage(StatValue value) {
	rangedDamage=value;
}
void Accessory::use(Character& individual) {
	individual.modAccessory(*this);
}
//------------------------------------------------------------------------------
StatValue Charm::getMagicPrecision() const {
	return magicPrecision;
}
StatValue Charm::getTotalTech() const {
	return totalTech;
}
StatValue Charm::getMagicPower() const {
	return magicPower;
}
Charm::Charm(StatValue magicPrecision, StatValue totalTech, StatValue magicPower):
	magicPrecision(magicPrecision), totalTech(totalTech), magicPower(magicPower) {}
void Charm::setTotalTech(StatValue value) {
	totalTech=value;
}
void Charm::setMagicPrecision(StatValue value) {
	magicPrecision=value;
}
void Charm::setMagicPower(StatValue value) {
	magicPower=value;
}
void Charm::use(Character& individual) {
	individual.modCharm(*this);
}