#pragma once
#include "item.h"
#include "stuff.h"
namespace sgl {
	class Armor: public EquipItem {
	private: StatValue vigorDefense, normalProtection, lifeEnergy;
	public:
		StatValue getVigorDefense() const;
		StatValue getNormalProtection() const;
		StatValue getLifeEnergy() const;
		Armor(StatValue=0, StatValue=0, StatValue=0);
		void setVigorDefense(StatValue);
		void setNormalProtection(StatValue);
		void setLifeEnergy(StatValue);
		void use(Character&);
	};
	class Veil: public EquipItem {
	private:
		StatValue willDefense, magicProtection, magicEnergy;
	public:
		StatValue getWillDefense() const;
		StatValue getMagicProtection() const;
		StatValue getMagicEnergy() const;
		Veil(StatValue=0, StatValue=0, StatValue=0);
		void setWillDefense(StatValue);
		void setMagicProtection(StatValue);
		void setMagicEnergy(StatValue);
		void use(Character&);
	};
	class Weapon: public EquipItem {
	private:
		Size size=Size::NONE;
		AttackType attackType;
		DamageType damageType;
		TimeUnit actionTime;
		StatValue randomDamage, normalDamage, magicPower;
	public:
		Size getSize() const;
		AttackType getAttackType() const;
		DamageType getDamageType() const;
		TimeUnit getActionTime() const;
		StatValue getRandomDamage() const;
		StatValue getNormalDamage() const;
		StatValue getMagicPower() const;
		Weapon(
			Size=Size::NONE, AttackType=AttackType::NONE, DamageType=DamageType::NONE, 
			TimeUnit=0, StatValue=0, StatValue=0, StatValue=0);
		void use(Character&);
		void setSize(Size);
		void setAttackType(AttackType);
		void setDamageType(DamageType);
		void setActionTime(TimeUnit);
		void setRandomDamage(StatValue);
		void setNormalDamage(StatValue);
		void setMagicPower(StatValue);

	};
	class Shield: public EquipItem {
	private:
		StatValue reflexDefense, normalProtection, magicProtection;
	public:
		StatValue getReflexDefense() const;
		StatValue getNormalProtection() const;
		StatValue getMagicProtection() const;
		Shield(StatValue=0, StatValue=0, StatValue=0);
		void setReflexDefense(StatValue);
		void setNormalProtection(StatValue);
		void setMagicProtection(StatValue);
		void use(Character&);
	};
	class Accessory: public EquipItem {
	private:
		StatValue meleeAttack, rangedAttack;
		StatValue meleeDamage, rangedDamage;
	public:
		StatValue getMeleeAttack() const;
		StatValue getRangedAttack() const;
		StatValue getMeleeDamage() const;
		StatValue getRangedDamage() const;
		Accessory(StatValue=0, StatValue=0, StatValue=0, StatValue=0);
		void setMeleeAttack(StatValue);
		void setRangedAttack(StatValue);
		void setMeleeDamage(StatValue);
		void setRangedDamage(StatValue);
		void use(Character&);
	};
	class Charm: public EquipItem {
	private:
		StatValue magicPrecision, totalTech, magicPower;
	public:
		StatValue getMagicPrecision() const;
		StatValue getTotalTech() const;
		StatValue getMagicPower() const;
		Charm(StatValue=0, StatValue=0, StatValue=0);
		void setMagicPrecision(StatValue);
		void setTotalTech(StatValue);
		void setMagicPower(StatValue);
		void use(Character&);
	};
}