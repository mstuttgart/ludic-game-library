#pragma once
#include "stuff.h"
#include "stat.h"
#include "precision.h"
#include "power.h"
namespace sgl {
	class EquipItem;
	class EquipStatSet: public PrecisionStatSet, public PowerStatSet {
	protected:
		static const StatValue LOAD_STRENGTH=10, LOAD_LIMIT=20;
		StatValue totalLoad=0, loadLimit=LOAD_LIMIT, force=0;
		SpaceUnit totalRange=0; TimeUnit actionTime=0;
		AttackType attackType=AttackType::MELEE;
		const StatValue* totalAttack=&meleeAttack;
		const StatValue* totalDamage=&meleeDamage;
		DamageType damageType=DamageType::PHYSIC;
		EquipStatSet() {}
	public:
		StatValue getTotalLoad() const;
		StatValue getLoadLimit() const;
		StatValue getForce() const;
		bool hasEnoughForce(const EquipItem&) const;
		SpaceUnit getTotalRange() const;
		TimeUnit getActionTime() const;
		AttackType getAttackType() const;
		StatValue getTotalAttack() const;
		StatValue getTotalDamage() const;
		DamageType getDamageType() const;
	public:
		void modTotalLoad(StatValue);
		void modLoadLimit(StatValue);
		void modForce(StatValue);
		void modTotalRange(SpaceUnit);
		void modActionTime(TimeUnit);
		void setAttackType(AttackType);
		void setDamageType(DamageType);
	};
}