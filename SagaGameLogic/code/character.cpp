#include "character.h"
#include <iostream>
using namespace std;
using namespace sgl;
//==============================================================================
void Character::modStrength(StatValue value) {
	strength+=value;
	modForce(value);
	modLoadLimit(LOAD_STRENGTH*value);
	modMeleeDamage(value);
}
void Character::modAgility(StatValue value) {
	agility+=value;
	modSpeed(value);
	modMeleeAttack(value);
	modReflexDefense(value);
}
void Character::modConstitution(StatValue value) {
	constitution+=value;
	modVigorDefense(value);
	modLifeLimit(LIFE_CONSTITUTION*value);
	modBaseProtection(value);
}
void Character::modIntelligence(StatValue value) {
	intelligence+=value;
	modMagicPrecision(value);
	modWillDefense(value);
	modTotalTech(value);
	modMagicPower(value);
}
void Character::modPerception(StatValue value) {
	perception+=value;
	modRangedAttack(value);
	modRangedDamage(value);
	modTotalRange(value);
	modCriticalChance(value);
	modCriticalPower(value);
}
void Character::modCharism(StatValue value) {
	charism+=value;
	modLuck(value);
}
//==============================================================================
const JobClass& Character::getFinalJob() const {
	return finalJob;
}
StatValue Character::getTotalLevel() const {
	return totalLevel;
}
void Character::modFinalJob(const JobEnum& job) {
	const JobEnum& aux=finalJob.getJob();
	modBaseAttack(-aux.getAttack());
	modBaseDefense(-aux.getDefense());
	modTotalTech(-aux.getTech());
	modBaseAttack(+job.getAttack());
	modBaseDefense(+job.getDefense());
	modTotalTech(+job.getTech());
	finalJob=job;
}
void Character::modFinalLevel(StatValue value) {
	finalJob.modLevel(value);
	const JobEnum& aux=finalJob.getJob();
	modLifeLimit(value*aux.getLife());
	modFuryEnergy(value*aux.getFury());
	modSpiritEnergy(value*aux.getSpirit());
	modMagicLimit(value*aux.getMagic());
}
void Character::modTotalLevel(StatValue value) {
	totalLevel+=value;
	modBaseAttack(value);
	modBaseDefense(value);
	modTotalTech(value);
}
//==============================================================================
Character::Character() {}
Character::Character(
	//base 6
	StatValue strength, StatValue agility, StatValue constitution, 
	StatValue intelligence, StatValue perception, StatValue charism,
	//level
	const JobEnum& job, StatValue level,
	//equip 7
	StatValue baseProtection, StatValue normalProtection, StatValue magicProtection,
	StatValue randomDamage, StatValue meleeDamage, StatValue rangedDamage, StatValue magicPower,
	//energy 6
	StatValue staminaEnergy, StatValue healthEnergy, StatValue lifeLimit,
	StatValue furyEnergy, StatValue spiritEnergy, StatValue magicLimit,
	//combat 7
	StatValue meleeAttack, StatValue rangedAttack, StatValue magicAttack, 
	StatValue reflexDefense, StatValue vigorDefense, StatValue willDefense, StatValue totalTech,
	//affinity 8
	StatValue physic, StatValue ice, StatValue lightning, StatValue fire, 
	StatValue psychic, StatValue biologic, StatValue arcane, StatValue holy) {
	//finally
	modBaseStatSet(
		strength, agility, constitution, 
		intelligence, perception, charism);
	modFinalJob(job);
	modFinalLevel(level);
	modTotalLevel(level);
	modPrecisionStatSet(
		0, meleeAttack, rangedAttack, magicAttack, 
		0, reflexDefense, vigorDefense, willDefense);
	modEnergyStatSet(
		staminaEnergy, healthEnergy, lifeLimit, 
		furyEnergy, spiritEnergy, magicLimit);
	modPowerStatSet(
		baseProtection, normalProtection, magicProtection,
		randomDamage, meleeDamage, rangedDamage, totalTech, magicPower);
	modAffinityStatSet(
		psychic, ice, lightning, fire, 
		psychic, biologic, arcane, holy);
}
//==============================================================================
void Character::modEnergyStatSet(
	StatValue stamina, StatValue health, StatValue life,
	StatValue fury, StatValue spirit, StatValue magic) {
	modStaminaEnergy(stamina);
	modHealthEnergy(health);
	modLifeLimit(life);
	modFuryEnergy(fury);
	modSpiritEnergy(spirit);
	modMagicLimit(magic);
}
//==============================================================================



StatValue Character::getSpeed() const {
	return speed;
}


//------------------------------------------------------------------------------


void Character::modSpeed(StatValue value) {
	speed+=value;
}
//==============================================================================
StatValue Character::getCriticalChance() const {
	return criticalChance;
}
StatValue Character::getCriticalPower() const {
	return criticalPower;
}
StatValue Character::getWealth() const {
	return wealth;
}
StatValue Character::getLuck() const {
	return luck;
}
//------------------------------------------------------------------------------
void Character::modCriticalChance(StatValue value) {
	criticalChance+=value;
}
void Character::modCriticalPower(StatValue value) {
	criticalPower+=value;
}
void Character::modWealth(StatValue value) {
	wealth+=value;
}
void Character::modLuck(StatValue value) {
	luck+=value;
}
//==============================================================================



//------------------------------------------------------------------------------
StatValue Character::getInstantAttack() const {
	return instantAttack;
}
StatValue Character::getInstantDefense() const {
	return instantDefense;
}
StatValue Character::getInstantDamage() const {
	return instantDamage;
}
StatValue Character::getInstantProtection() const {
	return instantProtection;
}
void Character::setInstantAttack() {
	instantAttack=0;
}
void Character::setInstantDefense() {
	instantDefense=0;
}
void Character::setInstantDamage() {
	instantDamage=0;
}
void Character::setInstantProtection() {
	instantProtection=0;
}
void Character::modInstantAttack(StatValue value) {
	instantAttack+=value;
}
void Character::modInstantDefense(StatValue value) {
	instantDefense+=value;
}
void Character::modInstantDamage(StatValue value) {
	instantDamage+=value;
}
void Character::modInstantProtection(StatValue value) {
	instantProtection+=value;
}
//------------------------------------------------------------------------------