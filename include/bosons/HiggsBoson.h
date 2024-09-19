//HiggsBoson.h
//Declares the HiggsBoson class which is a polymorphism of the Boson class. No new private members compared to boson.
//Overrides the initialise_decay_channels function to get pointer to shared higgs decays.
//Herbie Warner 28/04/2024

#ifndef HIGGSBOSON_H
#define HIGGSBOSON_H

#include<memory>
#include"bosons/Boson.h"

constexpr double higgs_rest_mass_ennergy = 125000; //MeV

class HiggsBoson : public Boson
{
private:
  void initialise_decay_channels() override; //Initialise set of possible decay channels
public:
  HiggsBoson(double E, double px, double py, double pz);
  HiggsBoson();

  //Use the copy/move semantics + destructor generated by boson
  ~HiggsBoson() override = default;
  HiggsBoson(const HiggsBoson& other) = default;
  HiggsBoson(HiggsBoson&& other) noexcept = default;
  HiggsBoson& operator=(const HiggsBoson& other) = default;
  HiggsBoson& operator=(HiggsBoson&& other) noexcept = default;

  std::unique_ptr<Particle> clone() const override {return std::make_unique<HiggsBoson>(*this);}
  std::unique_ptr<Particle> generate_anti_particle() const override;

  ParticleUtilities::ParticleIdentifier get_general_type() const override {return ParticleUtilities::ParticleIdentifier::HiggsBoson;}
};

#endif