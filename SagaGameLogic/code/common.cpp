#include "common.h"
#include "item.h"
using namespace sgl;
StatValue EquipStatSet::getTotalLoad() const {
	return totalLoad;
}
StatValue EquipStatSet::getLoadLimit() const {
	return loadLimit;
}
StatValue EquipStatSet::getForce() const {
	return force;
}
bool EquipStatSet::hasEnoughForce(const EquipItem& item) const {
	return item.getLoad()<=getForce();
}
void EquipStatSet::modTotalLoad(StatValue value) {
	totalLoad+=value;
}
void EquipStatSet::modLoadLimit(StatValue value) {
	loadLimit+=value;
}
void EquipStatSet::modForce(StatValue value) {
	force+=value;
}
//------------------------------------------------------------------------------
SpaceUnit EquipStatSet::getTotalRange() const {
	return totalRange;
}
TimeUnit EquipStatSet::getActionTime() const {
	return actionTime;
}
AttackType EquipStatSet::getAttackType() const {
	return attackType;
}
StatValue EquipStatSet::getTotalAttack() const {
	return *totalAttack;
}
StatValue EquipStatSet::getTotalDamage() const {
	return *totalDamage;
}
DamageType EquipStatSet::getDamageType() const {
	return damageType;
}
void EquipStatSet::modTotalRange(SpaceUnit value) {
	totalRange+=value;
}
void EquipStatSet::modActionTime(TimeUnit value) {
	actionTime+=value;
}
void EquipStatSet::setAttackType(AttackType value) {
	if(value==AttackType::MELEE)
		totalAttack=&meleeAttack;
	else totalAttack=&rangedAttack;
	if(value!=AttackType::RANGED)
		totalDamage=&meleeDamage;
	else totalDamage=&rangedDamage;
	totalRange+=(int)value-(int)attackType;
	attackType=value;
}
void EquipStatSet::setDamageType(DamageType value) {
	damageType=value;
}