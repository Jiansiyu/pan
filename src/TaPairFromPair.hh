#ifndef PAN_TaPairFromPair
#define PAN_TaPairFromPair
//////////////////////////////////////////////////////////////////////////
//
//     HALL A C++/ROOT Parity Analyzer  Pan           
//
//           TaPairFromPair.hh  (header file)
//           ^^^^^^^^^^^^^^^^^
//
//    Authors :  R. Holmes, A. Vacheret, R. Michaels
//
//    Class which make pair of helicity state with events from          
//    a pair of continuous window of helicity.  This is a derived 
//    class for pairing from paired helicity structure
//
//////////////////////////////////////////////////////////////////////////

#include "Rtypes.h"
#include "PanTypes.hh"
#include "VaPair.hh"

class TaCutList;
class TaEvent;
class TaRun;

class TaPairFromPair : public VaPair {
  
public:
  
  // Constructors/destructors/operators
  TaPairFromPair();
  TaPairFromPair(const TaPairFromPair& copy);
  TaPairFromPair& operator=( const TaPairFromPair& assign);  
  
  ~TaPairFromPair();
  
  // Major functions
  Bool_t Fill (TaEvent&, TaRun&); // check for pair and fill
  
private:
  
  // Private member functions
  void CheckSequence (TaEvent&, TaRun&); // look for helicity/synch errors
  Bool_t ProcessPairing();
  UInt_t  RanBit(); 
  //#define HSDEB
#ifdef HSDEB
  UInt_t  RanBit2(); 
#endif
  Bool_t TaPairFromPair::HelSeqOK (EHelicity h);

  // Data members
  static Bool_t  fgSkipping;   // true until first event of first full window
  static TaEvent fgThisWinEv;  // first ev of this window
  static TaEvent fgLastWinEv;  // first ev of last window
  static UInt_t  fgShreg;      // value for sequence algorithm      
#ifdef HSDEB
  static UInt_t  fgShreg2;     // value for sequence algorithm      
#endif
  static UInt_t  fgNShreg;     // count since fgShreg was reset
  static Bool_t  fgPairMade;   // set in Fill to true if pair made, else false
  static Bool_t  fgNeedHelCheck; // need to check helicity on next first event
#ifdef DICT
  ClassDef(TaPairFromPair, 0)  // Helicity pair from HAPPEX pair structure
#endif
};

#endif
