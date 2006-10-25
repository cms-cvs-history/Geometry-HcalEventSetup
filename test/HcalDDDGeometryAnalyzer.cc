// -*- C++ -*-
//
// Package:    HcalDDDGeometryAnalyzer
// Class:      HcalDDDGeometryAnalyzer
// 
/**\class HcalDDDGeometryAnalyzer HcalDDDGeometryAnalyzer.cc test/HcalDDDGeometryAnalyzer/src/HcalDDDGeometryAnalyzer.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//



// system include files
#include <memory>
#include <vector>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"

#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "DataFormats/HcalDetId/interface/HcalSubdetector.h"
#include <fstream>

//
// class decleration
//

class HcalDDDGeometryAnalyzer : public edm::EDAnalyzer {

public:

  explicit HcalDDDGeometryAnalyzer( const edm::ParameterSet& );
  ~HcalDDDGeometryAnalyzer();

  virtual void analyze( const edm::Event&, const edm::EventSetup& );

private:

  // ----------member data ---------------------------
  int pass_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
HcalDDDGeometryAnalyzer::HcalDDDGeometryAnalyzer(const edm::ParameterSet& ) {

  //now do what ever initialization is needed
  pass_=0;
}

HcalDDDGeometryAnalyzer::~HcalDDDGeometryAnalyzer() {}


// ------------ method called to produce the data  ------------
void HcalDDDGeometryAnalyzer::analyze(const edm::Event& , 
				      const edm::EventSetup& iSetup) {

  LogDebug("HCalGeom") << "HcalDDDGeometryAnalyzer::analyze at pass " << pass_;

  edm::ESHandle<CaloGeometry> geometry;
  iSetup.get<IdealGeometryRecord>().get(geometry);     
  //
  // get the ecal & hcal geometry
  //
  if (pass_==0) {
    std::vector<DetId> hbCells = geometry->getValidDetIds(DetId::Hcal, 
							  HcalBarrel);
    std::vector<DetId> heCells = geometry->getValidDetIds(DetId::Hcal, 
							  HcalEndcap);
    std::vector<DetId> hoCells = geometry->getValidDetIds(DetId::Hcal,
							  HcalOuter);
    std::vector<DetId> hfCells = geometry->getValidDetIds(DetId::Hcal,
							  HcalForward);
    LogDebug("HCalGeom") << "HcalDDDGeometryAnalyzer:: Hcal Barrel with "
			 << hbCells.size() << " valid cells; Hcal Endcap with "
			 << heCells.size() << " valid cells; Hcal Outer with "
			 << hoCells.size() << " valid cells; and Hcal Forward "
			 << " with " << hfCells.size() << " valid cells";
  }

  pass_++;
      
}

//define this as a plug-in
DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(HcalDDDGeometryAnalyzer);