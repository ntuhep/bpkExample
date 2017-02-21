#include "format.h"

void
LHERead()
{
  TChain* root = new TChain( "bprimeKit/root" );
  root->Add( "bprimeKit_ntuples.root" );

  GenInfoBranches EvtInfo;
  EvtInfo.Register( root );

  for( int entry = 0; entry < root->GetEntries() && entry < 100 ; ++entry ){    // Loop over all events
    root->GetEntry( entry );

    cout << EvtInfo.LHESystematicWeights[3] / EvtInfo.LHEOriginalWeight << endl;
  }

}
