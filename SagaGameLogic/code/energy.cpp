#include "energy.h"
using namespace sgl;
//------------------------------------------------------------------------------
StatValue MagicEnergySet::getMagicQuantity() const {
	return magicQuantity;
}
StatValue MagicEnergySet::getFuryEnergy() const {
	return furyEnergy;
}
StatValue MagicEnergySet::getMagicCapacity() const {
	return magicCapacity;
}
StatValue MagicEnergySet::getSpiritEnergy() const {
	return spiritEnergy;
}
StatValue MagicEnergySet::getMagicLimit() const {
	return magicLimit;
}
//------------------------------------------------------------------------------
MagicCondition MagicEnergySet::getMagicCondition() const {
	return magicCondition;
}
ActionCondition MagicEnergySet::getActionCondition() const {
	return actionCondition;
}
void MagicEnergySet::setMagicCondition(MagicCondition value) {
	magicCondition=value;
}
void MagicEnergySet::setActionCondition(ActionCondition value) {
	actionCondition=value;
}
//------------------------------------------------------------------------------
MagicEnergySet::MagicEnergySet(
	StatValue furyEnergy, StatValue spiritEnergy, StatValue magicLimit, bool fullEnergy):
	furyEnergy(furyEnergy), spiritEnergy(spiritEnergy), magicLimit(magicLimit) {
		if(!fullEnergy) {
			zeroMagicQuantity();
			zeroMagicCapacity();
		}
		else {
			fullMagicCapacity();
			fullMagicQuantity();
		}
	}
//------------------------------------------------------------------------------
void MagicEnergySet::zeroMagicQuantity() {
	magicQuantity=0;
}
void MagicEnergySet::fullMagicQuantity() {
	magicQuantity=magicCapacity;
}
void MagicEnergySet::modMagicQuantity(StatValue value) {
	magicQuantity+=value;
	if(magicQuantity<=0) {
		value=magicQuantity;
		zeroMagicQuantity();
		modMagicCapacity(value);
	}
	else if(magicQuantity>=magicCapacity) 
		fullMagicQuantity();
}
void MagicEnergySet::magicQuantityRecovery() {
	if(magicCondition!=MagicCondition::COMA)
		modMagicQuantity(furyEnergy);
}
void MagicEnergySet::modFuryEnergy(StatValue value) {
	furyEnergy+=value;
}
void MagicEnergySet::zeroMagicCapacity() {
	magicCapacity=0;
	zeroMagicQuantity();
}
void MagicEnergySet::fullMagicCapacity() {
	magicCapacity=magicLimit;
}
void MagicEnergySet::modMagicCapacity(StatValue value) {
	magicCapacity+=value;
	if(magicCapacity<=0) zeroMagicCapacity();
	else if(magicCapacity<=magicQuantity) fullMagicQuantity();
	else if(magicCapacity>=magicLimit) fullMagicCapacity();
}
void MagicEnergySet::magicCapacityRecovery() {
	if(magicCondition==MagicCondition::NORMAL)
		modMagicCapacity(spiritEnergy);
}
void MagicEnergySet::modSpiritEnergy(StatValue value) {
	spiritEnergy+=value;
}
void MagicEnergySet::modMagicLimit(StatValue value) {
	magicLimit+=value;
}