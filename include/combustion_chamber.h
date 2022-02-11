#ifndef ATG_ENGINE_SIM_COMBUSTION_CHAMBER_H
#define ATG_ENGINE_SIM_COMBUSTION_CHAMBER_H

#include "scs.h"

#include "piston.h"
#include "cylinder_bank.h"

class CombustionChamber : public atg_scs::ForceGenerator {
    public:
        CombustionChamber();
        virtual ~CombustionChamber();

        void initialize(double p0, double t0);
        virtual void apply(atg_scs::SystemState *system);

        Piston *m_piston;
        CylinderBank *m_bank;

        double volume();
        void updatePv();

    protected:
        double m_pressure;
        double m_temperature;
        double m_volume;
        double m_crankcasePressure;
};

#endif /* ATG_ENGINE_SIM_COMBUSTION_CHAMBER_H */
