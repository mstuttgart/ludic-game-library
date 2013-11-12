#include "stat.h"
#include "character.h"
using namespace sgl;
//------------------------------------------------------------------------------
StatId::StatId(GetFunction getFunction, ModFunction modFunction):
	getFunction(getFunction), modFunction(modFunction) {}
StatValue StatId::getStat(const Character& individual) const {
	return getFunction(individual);
}
void StatId::modStat(Character& individual, StatValue value) const {
	modFunction(individual, value);
}
//------------------------------------------------------------------------------
const StatId& StatStruct::getStatId() const {
	return statId;
}
StatValue StatStruct::getStatValue(bool activating) const {
	return activating? +statValue: -statValue;
}
StatStruct::StatStruct(const StatId& statId, StatValue statValue): 
	statId(statId), statValue(statValue) {}
void StatStruct::setStatValue(StatValue value) {
	statValue=value;
}
void StatStruct::modStatValue(StatValue value) {
	statValue+=value;
}
StatValue StatStruct::getCharStat(const Character& individual) const {
	return statId.getStat(individual);
}
void StatStruct::modCharStat(Character& individual, bool activating) const {
	statId.modStat(individual, getStatValue(activating));
}
//------------------------------------------------------------------------------
const StatId StatId::STRENGTH=StatId(
	&Character::getStrength, &Character::modStrength);
const StatId StatId::AGILITY=StatId(
	&Character::getAgility, &Character::modAgility);
const StatId StatId::CONSTITUTION=StatId(
	&Character::getConstitution, &Character::modConstitution);
const StatId StatId::INTELLIGENCE=StatId(
	&Character::getIntelligence, &Character::modIntelligence);
const StatId StatId::PERCEPTION=StatId(
	&Character::getPerception, &Character::modPerception);
const StatId StatId::CHARISM=StatId(
	&Character::getCharism, &Character::modCharism);
//------------------------------------------------------------------------------
const StatId StatId::BASE_ATTACK=StatId(
	&Character::getBaseAttack, &Character::modBaseAttack);
const StatId StatId::MELEE_ATTACK=StatId(
	&Character::getMeleeAttack, &Character::modMeleeAttack);
const StatId StatId::RANGED_ATTACK=StatId(
	&Character::getRangedAttack, &Character::modRangedAttack);
const StatId StatId::MAGIC_PRECISION=StatId(
	&Character::getMagicPrecision, &Character::modMagicPrecision);
const StatId StatId::BASE_DEFENSE=StatId(
	&Character::getBaseDefense, &Character::modBaseDefense);
const StatId StatId::REFLEX_DEFENSE=StatId(
	&Character::getReflexDefense, &Character::modReflexDefense);
const StatId StatId::VIGOR_DEFENSE=StatId(
	&Character::getVigorDefense, &Character::modVigorDefense);
const StatId StatId::WILL_DEFENSE=StatId(
	&Character::getWillDefense, &Character::modWillDefense);
//------------------------------------------------------------------------------
const StatId StatId::LIFE_QUANTITY=StatId(
	&Character::getLifeQuantity, &Character::modLifeQuantity);
const StatId StatId::STAMINA_ENERGY=StatId(
	&Character::getStaminaEnergy, &Character::modStaminaEnergy);
const StatId StatId::LIFE_CAPACITY=StatId(
	&Character::getLifeCapacity, &Character::modLifeCapacity);
const StatId StatId::HEALTH_ENERGY=StatId(
	&Character::getHealthEnergy, &Character::modHealthEnergy);
const StatId StatId::LIFE_LIMIT=StatId(
	&Character::getLifeLimit, &Character::modLifeLimit);
const StatId StatId::MAGIC_QUANTITY=StatId(
	&Character::getMagicQuantity, &Character::modMagicQuantity);
const StatId StatId::FURY_ENERGY=StatId(
	&Character::getFuryEnergy, &Character::modFuryEnergy);
const StatId StatId::MAGIC_CAPACITY=StatId(
	&Character::getMagicCapacity, &Character::modMagicCapacity);
const StatId StatId::SPIRIT_ENERGY=StatId(
	&Character::getSpiritEnergy, &Character::modSpiritEnergy);
const StatId StatId::MAGIC_LIMIT=StatId(
	&Character::getMagicLimit, &Character::modMagicLimit);
//------------------------------------------------------------------------------
const StatId StatId::BASE_PROTECTION=StatId(
	&Character::getBaseProtection, &Character::modBaseProtection);
const StatId StatId::NORMAL_PROTECTION=StatId(
	&Character::getNormalProtection, &Character::modNormalProtection);
const StatId StatId::MAGIC_PROTECTION=StatId(
	&Character::getMagicProtection, &Character::modMagicProtection);
const StatId StatId::RANDOM_DAMAGE=StatId(
	&Character::getRandomDamage, &Character::modRandomDamage);
const StatId StatId::MELEE_DAMAGE=StatId(
	&Character::getMeleeDamage, &Character::modMeleeDamage);
const StatId StatId::RANGED_DAMAGE=StatId(
	&Character::getRangedDamage, &Character::modRangedDamage);
const StatId StatId::TOTAL_TECH=StatId(
	&Character::getTotalTech, &Character::modTotalTech);
const StatId StatId::MAGIC_POWER=StatId(
	&Character::getMagicPower, &Character::modMagicPower);
//------------------------------------------------------------------------------
const StatId StatId::PHYSIC_AFFINITY=StatId(
	&Character::getPhysicAffinity, &Character::modPhysicAffinity);
const StatId StatId::ICE_AFFINITY=StatId(
	&Character::getIceAffinity, &Character::modIceAffinity);
const StatId StatId::LIGHTNING_AFFINITY=StatId(
	&Character::getLightningAffinity, &Character::modLightningAffinity);
const StatId StatId::FIRE_AFFINITY=StatId(
	&Character::getFireAffinity, &Character::modFireAffinity);
const StatId StatId::PSYCHIC_AFFINITY=StatId(
	&Character::getPsychicAffinity, &Character::modPsychicAffinity);
const StatId StatId::BIOLOGIC_AFFINITY=StatId(
	&Character::getBiologicAffinity, &Character::modBiologicAffinity);
const StatId StatId::ARCANE_AFFINITY=StatId(
	&Character::getArcaneAffinity, &Character::modArcaneAffinity);
const StatId StatId::HOLY_AFFINITY=StatId(
	&Character::getHolyAffinity, &Character::modHolyAffinity);
//------------------------------------------------------------------------------
const StatId StatId::INSTANT_ATTACK=StatId(
	&Character::getInstantAttack, &Character::modInstantAttack);
const StatId StatId::INSTANT_DEFENSE=StatId(
	&Character::getInstantDefense, &Character::modInstantDefense);
const StatId StatId::INSTANT_DAMAGE=StatId(
	&Character::getInstantDamage, &Character::modInstantProtection);
const StatId StatId::INSTANT_PROTECTION=StatId(
	&Character::getInstantProtection, &Character::modInstantProtection);