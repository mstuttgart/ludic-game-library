#pragma once
#include "stat.h"
namespace sgl {
	class PowerStatSet {
	protected:
		StatValue baseProtection, normalProtection, magicProtection;
		StatValue randomDamage, meleeDamage, rangedDamage;
		StatValue totalTech, magicPower;
	public:
		StatValue getBaseProtection() const;
		StatValue getNormalProtection() const;
		StatValue getMagicProtection() const;
		StatValue getRandomDamage() const;
		StatValue getMeleeDamage() const;
		StatValue getRangedDamage() const;
		StatValue getTotalTech() const;
		StatValue getMagicPower() const;
	protected:
		PowerStatSet(
			StatValue=0, StatValue=0, StatValue=0, StatValue=0,
			StatValue=0, StatValue=0, StatValue=0, StatValue=0);
	public:
		void modBaseProtection(StatValue);
		void modNormalProtection(StatValue);
		void modMagicProtection(StatValue);
		void modRandomDamage(StatValue);
		void modMeleeDamage(StatValue);
		void modRangedDamage(StatValue);
		void modTotalTech(StatValue);
		void modMagicPower(StatValue);
		void modPowerStatSet(
			StatValue, StatValue, StatValue, StatValue, 
			StatValue, StatValue, StatValue, StatValue);
	};
}