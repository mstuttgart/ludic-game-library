#include "stat.h"
namespace sgl {
	class AffinityStatSet {
	protected: StatValue 
		physicAffinity, iceAffinity, lightningAffinity, fireAffinity,
		psychicAffinity, biologicAffinity, arcaneAffinity, holyAffinity;
	public:
		StatValue getPhysicAffinity() const;
		StatValue getIceAffinity() const;
		StatValue getLightningAffinity() const;
		StatValue getFireAffinity() const;
		StatValue getPsychicAffinity() const;
		StatValue getBiologicAffinity() const;
		StatValue getArcaneAffinity() const;
		StatValue getHolyAffinity() const;
	protected:
		AffinityStatSet(
			StatValue=0, StatValue=0, StatValue=0, StatValue=0,
			StatValue=0, StatValue=0, StatValue=0, StatValue=0);
	public:
		void modPhysicAffinity(StatValue);
		void modIceAffinity(StatValue);
		void modLightningAffinity(StatValue);
		void modFireAffinity(StatValue);
		void modPsychicAffinity(StatValue);
		void modBiologicAffinity(StatValue);
		void modArcaneAffinity(StatValue);
		void modHolyAffinity(StatValue);
		void modAffinityStatSet(
			StatValue, StatValue, StatValue, StatValue, 
			StatValue, StatValue, StatValue, StatValue);
	};
}