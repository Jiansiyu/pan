#ifndef PAN_TaPairFromPair
#define PAN_TaPairFromPair
//**********************************************************************
//
//     HALL A C++/ROOT Parity Analyzer  Pan           
//
//           TaPairFromPair.hh  (interface)
//
// Author:  R. Holmes <http://mepserv.phy.syr.edu/~rsholmes>, A. Vacheret <http://www.jlab.org/~vacheret>, R. Michaels <http://www.jlab.org/~rom>
// @(#)pan/src:$Name$:$Id$
//
////////////////////////////////////////////////////////////////////////
//
//    Class which makes and analyzes opposite helicity event pairs
//    from a data stream structured as helicity window pairs.  Derived
//    from VaPair.
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
  
private:
  
  // Private member functions
  void CheckSequence (TaEvent&, TaRun&); // look for helicity/synch errors
  UInt_t RanBit (UInt_t hRead = 2);

#ifndef NODICT
  ClassDef(TaPairFromPair, 0)  // Event pair from window pair helicity structure
#endif
};

#endif
