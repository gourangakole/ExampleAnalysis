/********************************************************************
* eventdict.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error eventdict.h/C is only for compilation. Abort cint.
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define G__ANSIHEADER
#define G__DICTIONARY
#define G__PRIVATE_GVALUE
#include "G__ci.h"
#include "FastAllocString.h"
extern "C" {
extern void G__cpp_setup_tagtableeventdict();
extern void G__cpp_setup_inheritanceeventdict();
extern void G__cpp_setup_typetableeventdict();
extern void G__cpp_setup_memvareventdict();
extern void G__cpp_setup_globaleventdict();
extern void G__cpp_setup_memfunceventdict();
extern void G__cpp_setup_funceventdict();
extern void G__set_cpp_environmenteventdict();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "MiniTree/Selection/interface/MyEvent.h"
#include "MiniTree/Selection/interface/MyMET.h"
#include "MiniTree/Selection/interface/MyMCParticle.h"
#include "MiniTree/Selection/interface/MyTrack.h"
#include "MiniTree/Selection/interface/MyVertex.h"
#include "MiniTree/Selection/interface/MyJet.h"
#include "MiniTree/Selection/interface/MyElectron.h"
#include "MiniTree/Selection/interface/MyMuon.h"
#include "MiniTree/Selection/interface/MyTau.h"
#include "MiniTree/Selection/interface/SampleInfo.h"
#include "MiniTree/Selection/interface/MyKineFitParticle.h"
#include "MiniTree/Selection/interface/Reader.h"
#include "MiniTree/Selection/interface/ObjectSelector.hh"
#include "MiniTree/Selection/interface/HistogramPlotter.hh"
#include "MiniTree/Selection/interface/BtagSF.hh"
#include "MiniTree/Selection/interface/SVEffUnc.hh"
#include "MiniTree/Selection/interface/UncertaintyComputer.hh"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G__eventdictLN_TClass;
extern G__linked_taginfo G__eventdictLN_TBuffer;
extern G__linked_taginfo G__eventdictLN_TMemberInspector;
extern G__linked_taginfo G__eventdictLN_TString;
extern G__linked_taginfo G__eventdictLN_ROOT;
extern G__linked_taginfo G__eventdictLN_vectorlEunsignedsPintcOallocatorlEunsignedsPintgRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEfloatcOallocatorlEfloatgRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEdoublecOallocatorlEdoublegRsPgR;
extern G__linked_taginfo G__eventdictLN_string;
extern G__linked_taginfo G__eventdictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G__eventdictLN_TFile;
extern G__linked_taginfo G__eventdictLN_maplEstringcOfloatcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOfloatgRsPgRsPgR;
extern G__linked_taginfo G__eventdictLN_maplEstringcOdoublecOlesslEstringgRcOallocatorlEpairlEconstsPstringcOdoublegRsPgRsPgR;
extern G__linked_taginfo G__eventdictLN_ROOTcLcLMath;
extern G__linked_taginfo G__eventdictLN_ROOTcLcLMathcLcLPositionVector3DlEROOTcLcLMathcLcLCartesian3DlEdoublegRcOROOTcLcLMathcLcLDefaultCoordinateSystemTaggR;
extern G__linked_taginfo G__eventdictLN_ROOTcLcLMathcLcLLorentzVectorlEROOTcLcLMathcLcLPxPyPzE4DlEdoublegRsPgR;
extern G__linked_taginfo G__eventdictLN_MyJet;
extern G__linked_taginfo G__eventdictLN_vectorlEROOTcLcLMathcLcLLorentzVectorlEROOTcLcLMathcLcLPxPyPzE4DlEdoublegRsPgRcOallocatorlEROOTcLcLMathcLcLLorentzVectorlEROOTcLcLMathcLcLPxPyPzE4DlEdoublegRsPgRsPgRsPgR;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEROOTcLcLMathcLcLLorentzVectorlEROOTcLcLMathcLcLPxPyPzE4DlEdoublegRsPgRcOallocatorlEROOTcLcLMathcLcLLorentzVectorlEROOTcLcLMathcLcLPxPyPzE4DlEdoublegRsPgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_MyMET;
extern G__linked_taginfo G__eventdictLN_MyTrack;
extern G__linked_taginfo G__eventdictLN_MyVertex;
extern G__linked_taginfo G__eventdictLN_MyElectron;
extern G__linked_taginfo G__eventdictLN_MyMuon;
extern G__linked_taginfo G__eventdictLN_MyTau;
extern G__linked_taginfo G__eventdictLN_MyMCParticle;
extern G__linked_taginfo G__eventdictLN_vectorlEintcOallocatorlEintgRsPgR;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_SampleInfo;
extern G__linked_taginfo G__eventdictLN_MyKineFitParticle;
extern G__linked_taginfo G__eventdictLN_MyEvent;
extern G__linked_taginfo G__eventdictLN_MyEventcLcLSampleType;
extern G__linked_taginfo G__eventdictLN_MyEventcLcLTTChannel;
extern G__linked_taginfo G__eventdictLN_MyEventcLcLZChannel;
extern G__linked_taginfo G__eventdictLN_MyEventcLcLWChannel;
extern G__linked_taginfo G__eventdictLN_vectorlEMyElectroncOallocatorlEMyElectrongRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyElectroncOallocatorlEMyElectrongRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyElectroncOallocatorlEMyElectrongRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyMuoncOallocatorlEMyMuongRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyMuoncOallocatorlEMyMuongRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyMuoncOallocatorlEMyMuongRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyJetcOallocatorlEMyJetgRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyJetcOallocatorlEMyJetgRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyJetcOallocatorlEMyJetgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyTaucOallocatorlEMyTaugRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyTaucOallocatorlEMyTaugRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyTaucOallocatorlEMyTaugRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyMETcOallocatorlEMyMETgRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyMETcOallocatorlEMyMETgRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyMETcOallocatorlEMyMETgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyVertexcOallocatorlEMyVertexgRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyVertexcOallocatorlEMyVertexgRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyVertexcOallocatorlEMyVertexgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyMCParticlecOallocatorlEMyMCParticlegRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyMCParticlecOallocatorlEMyMCParticlegRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyMCParticlecOallocatorlEMyMCParticlegRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyKineFitParticlecOallocatorlEMyKineFitParticlegRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyKineFitParticlecOallocatorlEMyKineFitParticlegRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyKineFitParticlecOallocatorlEMyKineFitParticlegRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlEstringcOallocatorlEstringgRsPgR;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_vectorlETStringcOallocatorlETStringgRsPgR;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlETStringcOallocatorlETStringgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_pairlEunsignedsPintcOintgR;
extern G__linked_taginfo G__eventdictLN_vectorlEpairlEunsignedsPintcOintgRcOallocatorlEpairlEunsignedsPintcOintgRsPgRsPgR;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEpairlEunsignedsPintcOintgRcOallocatorlEpairlEunsignedsPintcOintgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__eventdictLN_TVectorTlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TVectorTlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TH1;
extern G__linked_taginfo G__eventdictLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G__eventdictLN_TTree;
extern G__linked_taginfo G__eventdictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR;
extern G__linked_taginfo G__eventdictLN_TElementActionTlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TElementPosActionTlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TElementActionTlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TElementPosActionTlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTRow_constlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTRowlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTDiag_constlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTColumn_constlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTFlat_constlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSub_constlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparseRow_constlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparseDiag_constlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTColumnlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTDiaglEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTFlatlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSublEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparseRowlEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparseDiaglEfloatgR;
extern G__linked_taginfo G__eventdictLN_TMatrixTRow_constlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSymlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTRowlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparselEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparseRow_constlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparseRowlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTDiag_constlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTColumn_constlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparseDiag_constlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTFlat_constlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSub_constlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTColumnlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTDiaglEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTFlatlEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSublEdoublegR;
extern G__linked_taginfo G__eventdictLN_TMatrixTSparseDiaglEdoublegR;
extern G__linked_taginfo G__eventdictLN_Reader;
extern G__linked_taginfo G__eventdictLN_TRandom3;
extern G__linked_taginfo G__eventdictLN_BtagSF;
extern G__linked_taginfo G__eventdictLN_BtagSFcLcLdA;
extern G__linked_taginfo G__eventdictLN_SVEffUnc;
extern G__linked_taginfo G__eventdictLN_UncertaintyComputer;
extern G__linked_taginfo G__eventdictLN_UncertaintyComputercLcLBVariation;
extern G__linked_taginfo G__eventdictLN_ObjectSelector;
extern G__linked_taginfo G__eventdictLN_HistogramPlotter;
extern G__linked_taginfo G__eventdictLN_maplETStringcOTH1mUcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOTH1mUgRsPgRsPgR;
extern G__linked_taginfo G__eventdictLN_maplETStringcOTH2mUcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOTH2mUgRsPgRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyTrackcOallocatorlEMyTrackgRsPgR;
extern G__linked_taginfo G__eventdictLN_vectorlEMyTrackcOallocatorlEMyTrackgRsPgRcLcLiterator;
extern G__linked_taginfo G__eventdictLN_reverse_iteratorlEvectorlEMyTrackcOallocatorlEMyTrackgRsPgRcLcLiteratorgR;

/* STUB derived class for protected member access */
typedef vector<MyElectron,allocator<MyElectron> > G__vectorlEMyElectroncOallocatorlEMyElectrongRsPgR;
typedef vector<MyMuon,allocator<MyMuon> > G__vectorlEMyMuoncOallocatorlEMyMuongRsPgR;
typedef vector<MyJet,allocator<MyJet> > G__vectorlEMyJetcOallocatorlEMyJetgRsPgR;
typedef vector<MyTau,allocator<MyTau> > G__vectorlEMyTaucOallocatorlEMyTaugRsPgR;
typedef vector<MyMET,allocator<MyMET> > G__vectorlEMyMETcOallocatorlEMyMETgRsPgR;
typedef vector<MyVertex,allocator<MyVertex> > G__vectorlEMyVertexcOallocatorlEMyVertexgRsPgR;
typedef vector<MyMCParticle,allocator<MyMCParticle> > G__vectorlEMyMCParticlecOallocatorlEMyMCParticlegRsPgR;
typedef vector<MyKineFitParticle,allocator<MyKineFitParticle> > G__vectorlEMyKineFitParticlecOallocatorlEMyKineFitParticlegRsPgR;
typedef vector<MyTrack,allocator<MyTrack> > G__vectorlEMyTrackcOallocatorlEMyTrackgRsPgR;
