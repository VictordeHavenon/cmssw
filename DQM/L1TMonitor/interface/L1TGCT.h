// -*-C++-*-
#ifndef L1TGCT_H
#define L1TGCT_H

/*
 * \file L1TGCT.h
 *
 * $Date: 2007/02/19 19:24:08 $
 * $Revision: 1.1 $
 * \author J. Berryhill
 * $Id$
 * $Log$
 *
*/

// system include files
#include <memory>
#include <unistd.h>


#include <iostream>
#include <fstream>
#include <vector>


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

// DQM
#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"


// Trigger Headers

// GCT and RCT data formats
#include "DataFormats/L1GlobalCaloTrigger/interface/L1GctCollections.h"
#include "DataFormats/L1GlobalCaloTrigger/interface/L1GctEtSums.h"
#include "DataFormats/L1CaloTrigger/interface/L1CaloCollections.h"

// L1Extra
#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticle.h"



//
// class declaration
//

class L1TGCT : public edm::EDAnalyzer {

public:

// Constructor
  L1TGCT(const edm::ParameterSet& ps);

// Destructor
 virtual ~L1TGCT();

protected:
// Analyze
 void analyze(const edm::Event& e, const edm::EventSetup& c);

// BeginJob
 void beginJob(const edm::EventSetup& c);

// EndJob
void endJob(void);

private:
  // ----------member data ---------------------------
  DaqMonitorBEInterface * dbe;

  // L1Extra stuff
  MonitorElement* l1ExtraCenJetsEtEtaPhi_; 
  MonitorElement* l1ExtraForJetsEtEtaPhi_;
  MonitorElement* l1ExtraTauJetsEtEtaPhi_;
  MonitorElement* l1ExtraIsoEmEtEtaPhi_;
  MonitorElement* l1ExtraNonIsoEmEtEtaPhi_;

  MonitorElement* l1ExtraCenJetsOccEtaPhi_;
  MonitorElement* l1ExtraForJetsOccEtaPhi_;  
  MonitorElement* l1ExtraTauJetsOccEtaPhi_;  
  MonitorElement* l1ExtraIsoEmOccEtaPhi_;    
  MonitorElement* l1ExtraNonIsoEmOccEtaPhi_; 

  MonitorElement* l1ExtraCenJetsRank_;
  MonitorElement* l1ExtraForJetsRank_;
  MonitorElement* l1ExtraTauJetsRank_;
  MonitorElement* l1ExtraIsoEmRank_;
  MonitorElement* l1ExtraNonIsoEmRank_;

  MonitorElement* l1ExtraEtMiss_;
  MonitorElement* l1ExtraEtMissPhi_;
  MonitorElement* l1ExtraEtTotal_;
  MonitorElement* l1ExtraEtHad_;


  int nev_; // Number of events processed
  std::string outputFile_; //file name for ROOT ouput
  bool verbose_;
  bool monitorDaemon_;
  ofstream logFile_;

  edm::InputTag l1ExtraLabel_;


};

#endif
