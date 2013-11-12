#include "base.h"
using namespace sgl;
StatValue BaseStatSet::getStrength() const {
	return strength;
}
StatValue BaseStatSet::getAgility() const {
	return agility;
}
StatValue BaseStatSet::getConstitution() const {
	return constitution;
}
StatValue BaseStatSet::getIntelligence() const {
	return intelligence;
}
StatValue BaseStatSet::getPerception() const {
	return perception;
}
StatValue BaseStatSet::getCharism() const {
	return charism;
}
BaseStatSet::BaseStatSet(
	StatValue strength, StatValue agility, StatValue constitution, 
	StatValue intelligence, StatValue perception, StatValue charism):
	strength(strength), agility(agility), constitution(constitution),
	intelligence(intelligence), perception(perception), charism(charism) {}
void BaseStatSet::modBaseStatSet(
	StatValue strength, StatValue agility, StatValue constitution, 
	StatValue intelligence, StatValue perception, StatValue charism) {
	modStrength(strength);
	modAgility(agility);
	modConstitution(constitution);
	modIntelligence(intelligence);
	modPerception(perception);
	modCharism(charism);
}