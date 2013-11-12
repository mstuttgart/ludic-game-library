#pragma once
#include <vector>
#include "stuff.h"
#include "level.h"
#include "entity.h"
#include "base.h"
#include "life.h"
#include "energy.h"
#include "affinity.h"
#include "common.h"
#include "equipitem.h"
namespace sgl {
	class Character: public Entity, 
		public BaseStatSet,
		public EquipItemSet,
		public AffinityStatSet {
//==============================================================================
	public:
		void modStrength(StatValue);
		void modAgility(StatValue);
		void modConstitution(StatValue);
		void modIntelligence(StatValue);
		void modPerception(StatValue);
		void modCharism(StatValue);
		void modEnergyStatSet(
			StatValue, StatValue, StatValue, StatValue, StatValue, StatValue);
//==============================================================================
	private:
		JobClass mainJob, secondaryJob, finalJob=JobEnum::NONE;
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
	private: 
		
		
	public:
		
		
		
		
		
//------------------------------------------------------------------------------
	private: StatValue speed=0, criticalChance=0, criticalPower=0, wealth=0, luck=0;
	public:
		StatValue getSpeed() const;
		
		StatValue getCriticalChance() const;
		StatValue getCriticalPower() const;
		StatValue getWealth() const;
		StatValue getLuck() const;
	public:
		void modSpeed(StatValue);
		void modCriticalChance(StatValue);
		void modCriticalPower(StatValue);
		void modWealth(StatValue);
		void modLuck(StatValue);
//==============================================================================

//==============================================================================
	
	private:
		Character* focus;
		bool fightning;
	public:
		
//------------------------------------------------------------------------------
	private:
		StatValue instantAttack=0, instantDefense=0, instantDamage=0, instantProtection=0;
	public:
		StatValue getInstantAttack() const;
		StatValue getInstantDefense() const;
		StatValue getInstantDamage() const;
		StatValue getInstantProtection() const;
		void setInstantAttack();
		void setInstantDefense();
		void setInstantDamage();
		void setInstantProtection();
		void modInstantAttack(StatValue);
		void modInstantDefense(StatValue);
		void modInstantDamage(StatValue);
		void modInstantProtection(StatValue);
	};
}