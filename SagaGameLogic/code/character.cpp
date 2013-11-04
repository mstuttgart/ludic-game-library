#include "character.h"
using namespace sgl;
//==============================================================================
StatValue Character::getStrength() const {
	return strength;
}
StatValue Character::getAgility() const {
	return agility;
}
StatValue Character::getConstitution() const {
	return constitution;
}
StatValue Character::getIntelligence() const {
	return intelligence;
}
StatValue Character::getPerception() const {
	return perception;
}
StatValue Character::getCharism() const {
	return charism;
}
//------------------------------------------------------------------------------
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
	modCriticalChance(value);
	modCriticalPower(value);
}
void Character::modCharism(StatValue value) {
	charism+=value;
	modLuck(value);
}
void Character::modBaseStatSet(
	StatValue strength, StatValue agility, StatValue constitution, 
	StatValue intelligence, StatValue perception, StatValue charism) {
	modStrength(strength);
	modAgility(agility);
	modConstitution(constitution);
	modIntelligence(intelligence);
	modPerception(perception);
	modCharism(charism);
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
	modBaseTech(-aux.getTech());
	modBaseAttack(+job.getAttack());
	modBaseDefense(+job.getDefense());
	modBaseTech(+job.getTech());
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
	modBaseTech(value);
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
	modCombatStatSet(
		meleeAttack, rangedAttack, magicAttack, 
		reflexDefense, vigorDefense, willDefense, totalTech);
	modEnergyStatSet(
		staminaEnergy, healthEnergy, lifeLimit, 
		furyEnergy, spiritEnergy, magicLimit);
	modEquipStatSet(
		baseProtection, normalProtection, magicProtection,
		randomDamage, meleeDamage, rangedDamage, magicPower);
	modAffinityStatSet(
		psychic, ice, lightning, fire, 
		psychic, biologic, arcane, holy);
}
//==============================================================================
StatValue Character::getBaseAttack() const {
	return baseAttack;
}
StatValue Character::getMeleeAttack() const {
	return meleeAttack;
}
StatValue Character::getRangedAttack() const {
	return rangedAttack;
}
StatValue Character::getMagicPrecision() const {
	return magicPrecision;
}
//------------------------------------------------------------------------------
void Character::modBaseAttack(StatValue value) {
	baseAttack+=value;
	modMeleeAttack(value);
	modRangedAttack(value);
	modMagicPrecision(value);
}
void Character::modMeleeAttack(StatValue value) {
	meleeAttack+=value;
}
void Character::modRangedAttack(StatValue value) {
	rangedAttack+=value;
}
void Character::modMagicPrecision(StatValue value) {
	magicPrecision+=value;
}
//==============================================================================
StatValue Character::getBaseDefense() const {
	return baseDefense;
}
StatValue Character::getReflexDefense() const {
	return reflexDefense;
}
StatValue Character::getVigorDefense() const {
	return vigorDefense;
}
StatValue Character::getWillDefense() const {
	return willDefense;
}
//------------------------------------------------------------------------------
void Character::modBaseDefense(StatValue value) {
	baseDefense+=value;
	modReflexDefense(value);
	modVigorDefense(value);
	modWillDefense(value);
}
void Character::modReflexDefense(StatValue value) {
	reflexDefense+=value;
}
void Character::modVigorDefense(StatValue value) {
	vigorDefense+=value;
}
void Character::modWillDefense(StatValue value) {
	willDefense+=value;
}
//==============================================================================
StatValue Character::getLifeQuantity() const {
	return lifeQuantity;
}
StatValue Character::getStaminaEnergy() const {
	return staminaEnergy;
}
StatValue Character::getLifeCapacity() const {
	return lifeCapacity;
}
StatValue Character::getHealthEnergy() const {
	return healthEnergy;
}
StatValue Character::getLifeLimit() const {
	return lifeLimit;
}
//------------------------------------------------------------------------------
void Character::zeroLifeQuantity() {
	lifeQuantity=0;
	setLifeCondition(LifeCondition::DYING);
}
void Character::fullLifeQuantity() {
	lifeQuantity=lifeCapacity;
}
void Character::modLifeQuantity(StatValue value) {
	lifeQuantity+=value;
	if(lifeQuantity<=0) {
		value=lifeQuantity;
		zeroLifeQuantity();
		modLifeCapacity(value);
	}
	else if(lifeQuantity>=lifeCapacity) 
		fullLifeQuantity();
}
void Character::modStaminaEnergy(StatValue value) {
	staminaEnergy+=value;
}
void Character::lifeQuantityRecovery() {
	modLifeQuantity(staminaEnergy);
}
void Character::zeroLifeCapacity() {
	lifeCapacity=0;
	zeroLifeQuantity();
	setLifeCondition(LifeCondition::NONE);
}
void Character::fullLifeCapacity() {
	lifeCapacity=lifeLimit;
}
void Character::modLifeCapacity(StatValue value) {
	lifeCapacity+=value;
	if(lifeCapacity<=0) zeroLifeCapacity();
	else if(lifeCapacity<=lifeQuantity) fullLifeQuantity();
	else if(lifeCapacity>=lifeLimit) fullLifeCapacity();
}
void Character::modHealthEnergy(StatValue value) {
	healthEnergy+=value;
}
void Character::LifeCapacityRecovery() {
	modLifeCapacity(healthEnergy);
}
void Character::modLifeLimit(StatValue value) {
	lifeLimit+=value;
}
//==============================================================================
StatValue Character::getMagicQuantity() const {
	return magicQuantity;
}
StatValue Character::getFuryEnergy() const {
	return furyEnergy;
}
StatValue Character::getMagicCapacity() const {
	return magicCapacity;
}
StatValue Character::getSpiritEnergy() const {
	return spiritEnergy;
}
StatValue Character::getMagicLimit() const {
	return magicLimit;
}
//------------------------------------------------------------------------------
void Character::zeroMagicQuantity() {
	magicQuantity=0;
}
void Character::fullMagicQuantity() {
	magicQuantity=magicCapacity;
}
void Character::modMagicQuantity(StatValue value) {
	magicQuantity+=value;
	if(magicQuantity<=0) {
		value=magicQuantity;
		zeroMagicQuantity();
		modMagicCapacity(value);
	}
	else if(magicQuantity>=magicCapacity) 
		fullMagicQuantity();
}
void Character::modFuryEnergy(StatValue value) {
	furyEnergy+=value;
}
void Character::magicQuantityRecovery() {
	modMagicQuantity(furyEnergy);
}
void Character::zeroMagicCapacity() {
	magicCapacity=0;
	zeroMagicQuantity();
}
void Character::fullMagicCapacity() {
	magicCapacity=magicLimit;
}
void Character::modMagicCapacity(StatValue value) {
	magicCapacity+=value;
	if(magicCapacity<=0) zeroMagicCapacity();
	else if(magicCapacity<=magicQuantity) fullMagicQuantity();
	else if(magicCapacity>=magicLimit) fullMagicCapacity();
}
void Character::modSpiritEnergy(StatValue value) {
	spiritEnergy+=value;
}
void Character::magicCapacityRecovery() {
	modMagicCapacity(spiritEnergy);
}
void Character::modMagicLimit(StatValue value) {
	magicLimit+=value;
}
//------------------------------------------------------------------------------
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
StatValue Character::getTotalLoad() const {
	return totalLoad;
}
StatValue Character::getLoadLimit() const {
	return loadLimit;
}
StatValue Character::getForce() const {
	return force;
}
StatValue Character::getSpeed() const {
	return speed;
}
//------------------------------------------------------------------------------
void Character::modTotalLoad(StatValue value) {
	totalLoad+=value;
}
void Character::modLoadLimit(StatValue value) {
	loadLimit+=value;
}
void Character::modForce(StatValue value) {
	force+=value;
}
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
StatValue Character::getBaseProtection() const {
	return baseProtection;
}
StatValue Character::getNormalProtection() const {
	return normalProtection;
}
StatValue Character::getMagicProtection() const {
	return magicProtection;
}
//------------------------------------------------------------------------------
void Character::modBaseProtection(StatValue value) {
	baseProtection+=value;
	modNormalProtection(value);
	modMagicProtection(value);
}
void Character::modNormalProtection(StatValue value) {
	normalProtection+=value;
}
void Character::modMagicProtection(StatValue value) {
	magicProtection+=value;
}
//==============================================================================
StatValue Character::getRandomDamage() const {
	return randomDamage;
}
StatValue Character::getMeleeDamage() const {
	return meleeDamage;
}
StatValue Character::getRangedDamage() const {
	return rangedDamage;
}
//------------------------------------------------------------------------------
void Character::modRandomDamage(StatValue value) {
	randomDamage+=value;
}
void Character::modMeleeDamage(StatValue value) {
	meleeDamage+=value;
}
void Character::modRangedDamage(StatValue value) {
	rangedDamage+=value;
}
//==============================================================================
StatValue Character::getBaseTech() const {
	return baseTech;
}
StatValue Character::getTotalTech() const {
	return totalTech;
}
StatValue Character::getMagicPower() const {
	return magicPower;
}
//------------------------------------------------------------------------------
void Character::modBaseTech(StatValue value) {
	baseTech+=value;
	modTotalTech(value);
}
void Character::modTotalTech(StatValue value) {
	totalTech+=value;
}
void Character::modMagicPower(StatValue value) {
	magicPower+=value;
}
//------------------------------------------------------------------------------
void Character::modCombatStatSet(
	StatValue melee, StatValue ranged, StatValue magic, 
	StatValue reflex, StatValue vigor, StatValue will, StatValue total) {
	modMeleeAttack(melee);
	modRangedAttack(ranged);
	modMagicPrecision(magic);
	modReflexDefense(reflex);
	modVigorDefense(vigor);
	modWillDefense(will);
	modTotalTech(total);
}
void Character::modEquipStatSet(
	StatValue baseProtection, StatValue normalProtection, StatValue magicProtection,
	StatValue randomDamage, StatValue meleeDamage, StatValue rangedDamage, StatValue magicPower) {
	modBaseProtection(baseProtection);
	modNormalProtection(normalProtection);
	modMagicProtection(magicProtection);
	modRandomDamage(randomDamage);
	modMeleeDamage(meleeDamage);
	modRangedDamage(rangedDamage);
	modMagicPower(magicPower);
}
//==============================================================================
LifeCondition Character::getLifeCondition() const {
	return lifeCondition;
}
void Character::setLifeCondition(LifeCondition value) {
	lifeCondition=value;
}
//==============================================================================
StatValue Character::getPhysicAffinity() const {
	return physicAffinity;
}
StatValue Character::getIceAffinity() const {
	return iceAffinity;
}
StatValue Character::getLightningAffinity() const {
	return lightningAffinity;
}
StatValue Character::getFireAffinity() const {
	return fireAffinity;
}
//------------------------------------------------------------------------------
void Character::modPhysicAffinity(StatValue value) {
	physicAffinity+=value;
}
void Character::modIceAffinity(StatValue value) {
	iceAffinity+=value;
}
void Character::modLightningAffinity(StatValue value) {
	lightningAffinity+=value;
}
void Character::modFireAffinity(StatValue value) {
	fireAffinity+=value;
}
//==============================================================================
StatValue Character::getPsychicAffinity() const {
	return psychicAffinity;
}
StatValue Character::getBiologicAffinity() const {
	return biologicAffinity;
}
StatValue Character::getArcaneAffinity() const {
	return arcaneAffinity;
}
StatValue Character::getHolyAffinity() const {
	return holyAffinity;
}
//------------------------------------------------------------------------------
void Character::modPsychicAffinity(StatValue value) {
	psychicAffinity+=value;
}
void Character::modBiologicAffinity(StatValue value) {
	biologicAffinity+=value;
}
void Character::modArcaneAffinity(StatValue value) {
	arcaneAffinity+=value;
}
void Character::modHolyAffinity(StatValue value) {
	holyAffinity+=value;
}
//------------------------------------------------------------------------------
void Character::modAffinityStatSet(
	StatValue physic, StatValue ice, StatValue lightning, StatValue fire, 
	StatValue psychic, StatValue biologic, StatValue arcane, StatValue holy) {
	modPhysicAffinity(physic);
	modIceAffinity(ice);
	modLightningAffinity(lightning);
	modFireAffinity(fire);
	modPsychicAffinity(psychic);
	modBiologicAffinity(biologic);
	modArcaneAffinity(arcane);
	modHolyAffinity(holy);
}