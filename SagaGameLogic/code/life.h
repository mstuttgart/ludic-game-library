#pragma once
#include "stat.h"
namespace sgl {
	enum class HealthCondition {
		NORMAL, POISON, VENOM,
	};
	enum class LifeCondition {
		NONE, DYING, LIVING,
	};
	class LifeEnergySet {
	protected: const StatValue LIFE_CONSTITUTION=3;
		HealthCondition healthCondition=HealthCondition::NORMAL;
		LifeCondition lifeCondition=LifeCondition::NONE;
		StatValue lifeQuantity, staminaEnergy, lifeCapacity, healthEnergy, lifeLimit;
	public:
		StatValue getLifeQuantity() const;
		StatValue getStaminaEnergy() const;
		StatValue getLifeCapacity() const;
		StatValue getHealthEnergy() const;
		StatValue getLifeLimit() const;
	public:
		HealthCondition getHealthCondition() const;
		LifeCondition getLifeCondition() const;
		void setHealthCondition(HealthCondition);
		void setLifeCondition(LifeCondition);
	protected:
		LifeEnergySet(StatValue=0, StatValue=0, StatValue=0, bool=false);
	public:
		void zeroLifeQuantity();
		void fullLifeQuantity();
		void modLifeQuantity(StatValue);
		void lifeQuantityRecovery();
		void modStaminaEnergy(StatValue);
		void zeroLifeCapacity();
		void fullLifeCapacity();
		void modLifeCapacity(StatValue);
		void lifeCapacityRecovery();
		void modHealthEnergy(StatValue);
		void modLifeLimit(StatValue);
	};
}