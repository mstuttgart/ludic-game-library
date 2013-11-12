#include "affinity.h"
using namespace sgl;
StatValue AffinityStatSet::getPhysicAffinity() const {
	return physicAffinity;
}
StatValue AffinityStatSet::getIceAffinity() const {
	return iceAffinity;
}
StatValue AffinityStatSet::getLightningAffinity() const {
	return lightningAffinity;
}
StatValue AffinityStatSet::getFireAffinity() const {
	return fireAffinity;
}
StatValue AffinityStatSet::getPsychicAffinity() const {
	return psychicAffinity;
}
StatValue AffinityStatSet::getBiologicAffinity() const {
	return biologicAffinity;
}
StatValue AffinityStatSet::getArcaneAffinity() const {
	return arcaneAffinity;
}
StatValue AffinityStatSet::getHolyAffinity() const {
	return holyAffinity;
}
//------------------------------------------------------------------------------
AffinityStatSet::AffinityStatSet(StatValue physicAffinity, StatValue iceAffinity, 
	StatValue lightningAffinity, StatValue fireAffinity, StatValue psychicAffinity, 
	StatValue biologicAffinity, StatValue arcaneAffinity, StatValue holyAffinity):
	physicAffinity(physicAffinity), iceAffinity(iceAffinity), lightningAffinity(lightningAffinity), 
	fireAffinity(fireAffinity), psychicAffinity(psychicAffinity), biologicAffinity(biologicAffinity), 
	arcaneAffinity(arcaneAffinity), holyAffinity(holyAffinity) {}
//------------------------------------------------------------------------------
void AffinityStatSet::modPhysicAffinity(StatValue value) {
	physicAffinity+=value;
}
void AffinityStatSet::modIceAffinity(StatValue value) {
	iceAffinity+=value;
}
void AffinityStatSet::modLightningAffinity(StatValue value) {
	lightningAffinity+=value;
}
void AffinityStatSet::modFireAffinity(StatValue value) {
	fireAffinity+=value;
}
void AffinityStatSet::modPsychicAffinity(StatValue value) {
	psychicAffinity+=value;
}
void AffinityStatSet::modBiologicAffinity(StatValue value) {
	biologicAffinity+=value;
}
void AffinityStatSet::modArcaneAffinity(StatValue value) {
	arcaneAffinity+=value;
}
void AffinityStatSet::modHolyAffinity(StatValue value) {
	holyAffinity+=value;
}
//------------------------------------------------------------------------------
void AffinityStatSet::modAffinityStatSet(StatValue physicAffinity, StatValue iceAffinity, 
	StatValue lightningAffinity, StatValue fireAffinity, StatValue psychicAffinity, 
	StatValue biologicAffinity, StatValue arcaneAffinity, StatValue holyAffinity) {
	modPhysicAffinity(physicAffinity);
	modIceAffinity(iceAffinity);
	modLightningAffinity(lightningAffinity);
	modFireAffinity(fireAffinity);
	modPsychicAffinity(psychicAffinity);
	modBiologicAffinity(biologicAffinity);
	modArcaneAffinity(arcaneAffinity);
	modHolyAffinity(holyAffinity);
}