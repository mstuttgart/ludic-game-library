#include "level.h"
using namespace sgl;

//padrão
const JobEnum JobEnum::NONE=JobEnum(0, 0, 0, 0, 0, 0, 0);
//classes básicas
const JobEnum JobEnum::COMMONER=JobEnum(3, 3, 3, 2, 0, 1, 2);
const JobEnum JobEnum::WARRIOR=JobEnum(5, 3, 1, 3, 1, 0, 1);
const JobEnum JobEnum::ROGUE=JobEnum(3, 5, 1, 2, 0, 1, 2);
const JobEnum JobEnum::MAGE=JobEnum(3, 1, 5, 1, 1, 0, 3);
const JobEnum JobEnum::CLERIC=JobEnum(1, 3, 5, 2, 0, 1, 2);
const JobEnum JobEnum::SAVAGE=JobEnum(5, 1, 3, 3, 1, 0, 1);
const JobEnum JobEnum::BARD=JobEnum(1, 5, 3, 1, 0, 1, 3);
//classes combinadas
const JobEnum JobEnum::KNIGHT=JobEnum(4, 3, 2, 0, 0, 0, 0);
const JobEnum JobEnum::ASSASSIN=JobEnum(4, 4, 1, 0, 0, 0, 0);

StatValue JobEnum::getAttack() const {
	return attack;
}
StatValue JobEnum::getDefense() const {
	return defense;
}
StatValue JobEnum::getTech() const {
	return tech;
}
StatValue JobEnum::getLife() const {
	return life;
}
StatValue JobEnum::getFury() const {
	return fury;
}
StatValue JobEnum::getSpirit() const {
	return spirit;
}
StatValue JobEnum::getMagic() const {
	return magic;
}
//compara o job comparando a sua origem na memória ;)
bool JobEnum::operator==(const JobEnum& job) const {
	return &job==this;
}
JobEnum::JobEnum(StatValue attack, StatValue defense, StatValue tech,
	StatValue life, StatValue fury, StatValue spirit, StatValue magic):
	attack(attack), defense(defense), tech(tech), life(life),
	fury(fury), spirit(spirit), magic(magic) {}
//------------------------------------------------------------------------------
const JobEnum& JobClass::getJob() const {
	return *job;
}
StatValue JobClass::getLevel() const {
	return level;
}
void JobClass::setJob(const JobEnum& job) {
	this->job=&job;
}
void JobClass::setLevel(StatValue value) {
	level=value;
}
void JobClass::modLevel(StatValue value) {
	level+=value;
}
//padrão: job=NONE, level=0
JobClass::JobClass(): job(&JobEnum::NONE) {}
//básico: job=job, level=0
JobClass::JobClass(const JobEnum& job): job(&job) {}