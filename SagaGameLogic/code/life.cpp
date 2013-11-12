#include "life.h"
using namespace sgl;
StatValue LifeEnergySet::getLifeQuantity() const {
	return lifeQuantity;
}
StatValue LifeEnergySet::getStaminaEnergy() const {
	return staminaEnergy;
}
StatValue LifeEnergySet::getLifeCapacity() const {
	return lifeCapacity;
}
StatValue LifeEnergySet::getHealthEnergy() const {
	return healthEnergy;
}
StatValue LifeEnergySet::getLifeLimit() const {
	return lifeLimit;
}
//------------------------------------------------------------------------------
HealthCondition LifeEnergySet::getHealthCondition() const {
	return healthCondition;
}
LifeCondition LifeEnergySet::getLifeCondition() const {
	return lifeCondition;
}
void LifeEnergySet::setHealthCondition(HealthCondition value) {
	healthCondition=value;
}
void LifeEnergySet::setLifeCondition(LifeCondition value) {
	lifeCondition=value;
}
//------------------------------------------------------------------------------
LifeEnergySet::LifeEnergySet(
	StatValue staminaEnergy, StatValue healthEnergy, StatValue lifeLimit, bool fullEnergy):
	staminaEnergy(staminaEnergy), healthEnergy(healthEnergy), lifeLimit(lifeLimit) {
	if(!fullEnergy) {
		zeroLifeQuantity();
		zeroLifeCapacity();
	} else {
		fullLifeCapacity();
		fullLifeQuantity();
	}
}
//------------------------------------------------------------------------------
void LifeEnergySet::zeroLifeQuantity() {
	lifeQuantity=0;
	setLifeCondition(LifeCondition::DYING);
}
void LifeEnergySet::fullLifeQuantity() {
	lifeQuantity=lifeCapacity;
}
void LifeEnergySet::modLifeQuantity(StatValue value) {
	lifeQuantity+=value;
	if(lifeQuantity<=0) {
		value=lifeQuantity;
		zeroLifeQuantity();
		modLifeCapacity(value);
	}
	else if(lifeQuantity>=lifeCapacity) 
		fullLifeQuantity();
}
void LifeEnergySet::lifeQuantityRecovery() {
	if(healthCondition!=HealthCondition::VENOM)
		modLifeQuantity(staminaEnergy);
}
void LifeEnergySet::modStaminaEnergy(StatValue value) {
	staminaEnergy+=value;
}
void LifeEnergySet::zeroLifeCapacity() {
	lifeCapacity=0;
	zeroLifeQuantity();
	setLifeCondition(LifeCondition::NONE);
}
void LifeEnergySet::fullLifeCapacity() {
	lifeCapacity=lifeLimit;
}
void LifeEnergySet::modLifeCapacity(StatValue value) {
	lifeCapacity+=value;
	if(lifeCapacity<=0) zeroLifeCapacity();
	else if(lifeCapacity<=lifeQuantity) fullLifeQuantity();
	else if(lifeCapacity>=lifeLimit) fullLifeCapacity();
}
void LifeEnergySet::lifeCapacityRecovery() {
	if(healthCondition==HealthCondition::NORMAL)
		modLifeCapacity(healthEnergy);
}
void LifeEnergySet::modHealthEnergy(StatValue value) {
	healthEnergy+=value;
}
void LifeEnergySet::modLifeLimit(StatValue value) {
	lifeLimit+=value;
}