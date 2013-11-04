#pragma once
#include "entity.h"
#include "stat.h"
#include "level.h"
#include "condition.h"
namespace sgl {
	class Character: public Entity {
//==============================================================================
	private: StatValue
		strength, agility=0, constitution=0, intelligence=0, perception=0, charism=0;
	public:
		StatValue getStrength() const;
		StatValue getAgility() const;
		StatValue getConstitution() const;
		StatValue getIntelligence() const;
		StatValue getPerception() const;
		StatValue getCharism() const;
	public:
		void modStrength(StatValue);
		void modAgility(StatValue);
		void modConstitution(StatValue);
		void modIntelligence(StatValue);
		void modPerception(StatValue);
		void modCharism(StatValue);
		void modBaseStatSet(
			StatValue, StatValue, StatValue, StatValue, StatValue, StatValue);
//==============================================================================
	private:
		JobClass finalJob=JobEnum::NONE;
		StatValue totalLevel=0;
	public:
		const JobClass& getFinalJob() const;
		StatValue getTotalLevel() const;
	public:
		void modFinalJob(const JobEnum&);
		void modFinalLevel(StatValue);
		void modTotalLevel(StatValue);
//==============================================================================
public:
		Character();
		Character(
			//base 6
			StatValue, StatValue, StatValue, StatValue, StatValue, StatValue, const JobEnum&, StatValue,
			//equip 7
			StatValue, StatValue, StatValue, StatValue, StatValue, StatValue, StatValue=0,
			//energy 6
			StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0,
			//combat 7
			StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0,
			//affinity 8
			StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0, StatValue=0);
//==============================================================================
	private: StatValue baseAttack=0, meleeAttack=0, rangedAttack=0, magicPrecision=0;
	public:
		StatValue getBaseAttack() const;
		StatValue getMeleeAttack() const;
		StatValue getRangedAttack() const;
		StatValue getMagicPrecision() const;
	public:
		void modBaseAttack(StatValue);
		void modMeleeAttack(StatValue);
		void modRangedAttack(StatValue);
		void modMagicPrecision(StatValue);
//------------------------------------------------------------------------------
	private: StatValue baseDefense=0, reflexDefense=0, vigorDefense=0, willDefense=0;
	public:
		StatValue getBaseDefense() const;
		StatValue getReflexDefense() const;
		StatValue getVigorDefense() const;
		StatValue getWillDefense() const;
	public:
		void modBaseDefense(StatValue);
		void modReflexDefense(StatValue);
		void modVigorDefense(StatValue);
		void modWillDefense(StatValue);
//==============================================================================
	private: 
		const StatValue LIFE_CONSTITUTION=3;
		StatValue lifeQuantity=0, staminaEnergy=0, lifeCapacity=0, healthEnergy=0, lifeLimit=0;
	public:
		StatValue getLifeQuantity() const;
		StatValue getStaminaEnergy() const;
		StatValue getLifeCapacity() const;
		StatValue getHealthEnergy() const;
		StatValue getLifeLimit() const;
	public:
		void zeroLifeQuantity();
		void fullLifeQuantity();
		void modLifeQuantity(StatValue);
		void modStaminaEnergy(StatValue);
		void lifeQuantityRecovery();
		void zeroLifeCapacity();
		void fullLifeCapacity();
		void modLifeCapacity(StatValue);
		void modHealthEnergy(StatValue);
		void LifeCapacityRecovery();
		void modLifeLimit(StatValue);
//------------------------------------------------------------------------------
	private: StatValue
		magicQuantity=0, furyEnergy=0, magicCapacity=0, spiritEnergy=0, magicLimit=0;
	public:
		StatValue getMagicQuantity() const;
		StatValue getFuryEnergy() const;
		StatValue getMagicCapacity() const;
		StatValue getSpiritEnergy() const;
		StatValue getMagicLimit() const;
	public:
		void zeroMagicQuantity();
		void fullMagicQuantity();
		void modMagicQuantity(StatValue);
		void modFuryEnergy(StatValue);
		void magicQuantityRecovery();
		void zeroMagicCapacity();
		void fullMagicCapacity();
		void modMagicCapacity(StatValue);
		void modSpiritEnergy(StatValue);
		void magicCapacityRecovery();
		void modMagicLimit(StatValue);
		void modEnergyStatSet(
			StatValue, StatValue, StatValue, StatValue, StatValue, StatValue);
//==============================================================================
	private: 
		const StatValue LOAD_STRENGTH=10;
		StatValue totalLoad=0, loadLimit=0, force=0, speed=0;
	public:
		StatValue getTotalLoad() const;
		StatValue getLoadLimit() const;
		StatValue getForce() const;
		StatValue getSpeed() const;
	public:
		void modTotalLoad(StatValue);
		void modLoadLimit(StatValue);
		void modForce(StatValue);
		void modSpeed(StatValue);
//------------------------------------------------------------------------------
	private: StatValue criticalChance=0, criticalPower=0, wealth=0, luck=0;
	public:
		StatValue getCriticalChance() const;
		StatValue getCriticalPower() const;
		StatValue getWealth() const;
		StatValue getLuck() const;
	public:
		void modCriticalChance(StatValue);
		void modCriticalPower(StatValue);
		void modWealth(StatValue);
		void modLuck(StatValue);
//==============================================================================
	private: StatValue baseProtection=0, normalProtection=0, magicProtection=0;
	public:
		StatValue getBaseProtection() const;
		StatValue getNormalProtection() const;
		StatValue getMagicProtection() const;
	public:
		void modBaseProtection(StatValue);
		void modNormalProtection(StatValue);
		void modMagicProtection(StatValue);
//------------------------------------------------------------------------------
	private: StatValue randomDamage=0, meleeDamage=0, rangedDamage=0;
	public:
		StatValue getRandomDamage() const;
		StatValue getMeleeDamage() const;
		StatValue getRangedDamage() const;
	public:
		void modRandomDamage(StatValue);
		void modMeleeDamage(StatValue);
		void modRangedDamage(StatValue);
//------------------------------------------------------------------------------
	private: StatValue baseTech=0, totalTech=0, magicPower=0;
	public:
		StatValue getBaseTech() const;
		StatValue getTotalTech() const;
		StatValue getMagicPower() const;
	public:
		void modBaseTech(StatValue);
		void modTotalTech(StatValue);
		void modMagicPower(StatValue);
		void modCombatStatSet(StatValue, StatValue, 
			StatValue, StatValue, StatValue, StatValue, StatValue);
		void modEquipStatSet(
			StatValue, StatValue, StatValue, StatValue, StatValue, StatValue, StatValue);
//==============================================================================
	private:
		LifeCondition lifeCondition=LifeCondition::NONE;
	public:
		LifeCondition getLifeCondition() const;
		void setLifeCondition(LifeCondition);
//==============================================================================
	private: StatValue 
		physicAffinity=0, iceAffinity=-1, lightningAffinity=-2, fireAffinity=-3;
	public:
		StatValue getPhysicAffinity() const;
		StatValue getIceAffinity() const;
		StatValue getLightningAffinity() const;
		StatValue getFireAffinity() const;
	public:
		void modPhysicAffinity(StatValue);
		void modIceAffinity(StatValue);
		void modLightningAffinity(StatValue);
		void modFireAffinity(StatValue);
//------------------------------------------------------------------------------
	private: StatValue
		psychicAffinity=0, biologicAffinity=-1, arcaneAffinity=-2, holyAffinity=-3;
	public:
		StatValue getPsychicAffinity() const;
		StatValue getBiologicAffinity() const;
		StatValue getArcaneAffinity() const;
		StatValue getHolyAffinity() const;
	public:
		void modPsychicAffinity(StatValue);
		void modBiologicAffinity(StatValue);
		void modArcaneAffinity(StatValue);
		void modHolyAffinity(StatValue);
		void modAffinityStatSet(
			StatValue, StatValue, StatValue, StatValue, 
			StatValue, StatValue, StatValue, StatValue);
	};
}