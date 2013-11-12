#include "precision.h"
using namespace sgl;
//------------------------------------------------------------------------------
StatValue PrecisionStatSet::getBaseAttack() const {
	return baseAttack;
}
StatValue PrecisionStatSet::getMeleeAttack() const {
	return meleeAttack;
}
StatValue PrecisionStatSet::getRangedAttack() const {
	return rangedAttack;
}
StatValue PrecisionStatSet::getMagicPrecision() const {
	return magicPrecision;
}
StatValue PrecisionStatSet::getBaseDefense() const {
	return baseDefense;
}
StatValue PrecisionStatSet::getReflexDefense() const {
	return reflexDefense;
}
StatValue PrecisionStatSet::getVigorDefense() const {
	return vigorDefense;
}
StatValue PrecisionStatSet::getWillDefense() const {
	return willDefense;
}
//------------------------------------------------------------------------------
PrecisionStatSet::PrecisionStatSet(StatValue baseAttack, StatValue meleeAttack, 
	StatValue rangedAttack, StatValue magicPrecision, StatValue baseDefense, 
	StatValue reflexDefense, StatValue vigorDefense, StatValue willDefense):
	baseAttack(baseAttack), meleeAttack(meleeAttack), rangedAttack(rangedAttack),
	magicPrecision(magicPrecision), baseDefense(baseDefense), 
	vigorDefense(vigorDefense), willDefense(willDefense) {}
//------------------------------------------------------------------------------
void PrecisionStatSet::modBaseAttack(StatValue value) {
	baseAttack+=value;
	modMeleeAttack(value);
	modRangedAttack(value);
	modMagicPrecision(value);
}
void PrecisionStatSet::modMeleeAttack(StatValue value) {
	meleeAttack+=value;
}
void PrecisionStatSet::modRangedAttack(StatValue value) {
	rangedAttack+=value;
}
void PrecisionStatSet::modMagicPrecision(StatValue value) {
	magicPrecision+=value;
}
void PrecisionStatSet::modBaseDefense(StatValue value) {
	baseDefense+=value;
	modReflexDefense(value);
	modVigorDefense(value);
	modWillDefense(value);
}
void PrecisionStatSet::modReflexDefense(StatValue value) {
	reflexDefense+=value;
}
void PrecisionStatSet::modVigorDefense(StatValue value) {
	vigorDefense+=value;
}
void PrecisionStatSet::modWillDefense(StatValue value) {
	willDefense+=value;
}
//------------------------------------------------------------------------------
void PrecisionStatSet::modPrecisionStatSet(
	StatValue baseAttack, StatValue meleeAttack, StatValue rangedAttack, StatValue magicPrecision, 
	StatValue baseDefense, StatValue reflexDefense, StatValue vigorDefense, StatValue willDefense) {
	modBaseAttack(baseAttack);
	modMeleeAttack(meleeAttack);
	modRangedAttack(rangedAttack);
	modMagicPrecision(magicPrecision);
	modBaseDefense(baseDefense);
	modReflexDefense(reflexDefense);
	modVigorDefense(vigorDefense);
	modWillDefense(willDefense);
}