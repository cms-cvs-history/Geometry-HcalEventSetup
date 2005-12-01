#include "Geometry/HcalEventSetup/src/HcalHardcodeGeometryEP.h"
#include "Geometry/HcalEventSetup/src/CaloTowerHardcodeGeometryEP.h"
#include "Geometry/HcalEventSetup/src/HcalTopologyIdealEP.h"
//define this as a plug-in
DEFINE_FWK_EVENTSETUP_MODULE(HcalHardcodeGeometryEP)
DEFINE_ANOTHER_FWK_EVENTSETUP_MODULE(CaloTowerHardcodeGeometryEP)
DEFINE_ANOTHER_FWK_EVENTSETUP_MODULE(HcalTopologyIdealEP)