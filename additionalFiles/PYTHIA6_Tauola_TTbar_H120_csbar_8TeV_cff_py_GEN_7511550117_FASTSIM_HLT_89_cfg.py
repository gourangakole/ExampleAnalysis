import FWCore.ParameterSet.Config as cms

process = cms.Process('HLT')

# add this line for random number changing
process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
                                                    generator = cms.PSet(
			initialSeed = cms.untracked.uint32(7511550117),
                    engineName = cms.untracked.string('HepJamesRandom')
                    )
                                                   )
                                                                                         

# import of standard configurations
                                                                                                          
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('FastSimulation.Configuration.EventContent_cff')
process.load('FastSimulation.PileUpProducer.PileUpSimulator_2012_Summer_inTimeOnly_cff')
process.load('FastSimulation.Configuration.Geometries_START_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('FastSimulation.Configuration.FamosSequences_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedParameters_cfi')
process.load('HLTrigger.Configuration.HLT_7E33v2_Famos_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(2000)
)

# Input source
                                                                                                                               
process.source = cms.Source("EmptySource")

process.options = cms.untracked.PSet(

)

# Production Info
                                                                                                                            
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.1 $'),
    annotation = cms.untracked.string('PYTHIA6-TTbar Hplus120 To TauNu, with Tauola at 8TeV'),
    name = cms.untracked.string('$Source: /local/reps/CMSSW/CMSSW/Configuration/GenProduction/python/EightTeV/PYTHIA6_Tauola_TTbar_H120_taunu_8TeV_cff.py,v $')
)

#output definition 
process.AODSIMoutput = cms.OutputModule("PoolOutputModule",
    eventAutoFlushCompressedSize = cms.untracked.int32(15728640),
    outputCommands = process.AODSIMEventContent.outputCommands,
    #fileName = cms.untracked.string('rfio:/castor/cern.ch/user/g/gkole/chargedHiggs/mc/signal/PYTHIA6_Tauola_TTbar_H120_csbar_8TeV_cff_py_GEN_FASTSIM_HLT_89.root'),
    #fileName = cms.untracked.string('/tmp/gkole/PYTHIA6_Tauola_TTbar_H120_csbar_8TeV_cff_py_GEN_FASTSIM_HLT_89.root'),
    fileName = cms.untracked.string('/afs/cern.ch/work/g/gkole/chargedHiggs/8TeV/signal/rootfiles/hpwnu/PYTHIA6_Tauola_TTbar_H120_csbar_8TeV_cff_py_GEN_FASTSIM_HLT_89.root'),	
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('AODSIM')
    ),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    )
)

# Additional output definition
# Other statements                                                                                                                           
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
process.famosSimHits.SimulateCalorimetry = True
process.famosSimHits.SimulateTracking = True
process.simulation = cms.Sequence(process.simulationWithFamos)
process.HLTEndSequence = cms.Sequence(process.reconstructionWithFamos)
process.Realistic8TeVCollisionVtxSmearingParameters.type = cms.string("BetaFunc")
process.famosSimHits.VertexGenerator = process.Realistic8TeVCollisionVtxSmearingParameters
process.famosPileUp.VertexGenerator = process.Realistic8TeVCollisionVtxSmearingParameters
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'START53_V7C::All', '')

process.generator = cms.EDFilter("Pythia6GeneratorFilter",
    ExternalDecays = cms.PSet(
        Tauola = cms.untracked.PSet(
            UseTauolaPolarization = cms.bool(True),
            InputCards = cms.PSet(
                mdtau = cms.int32(0),
                pjak2 = cms.int32(0),
                pjak1 = cms.int32(0)
            )
        ),
        parameterSets = cms.vstring('Tauola')
    ),
    maxEventsToPrint = cms.untracked.int32(2),
    pythiaPylistVerbosity = cms.untracked.int32(1),
    filterEfficiency = cms.untracked.double(1.0),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    comEnergy = cms.double(8000.0),
    crossSection = cms.untracked.double(1.1),
    UseExternalGenerators = cms.untracked.bool(True),
    PythiaParameters = cms.PSet(
        pythiaUESettings = cms.vstring('MSTU(21)=1     ! Check on possible errors during program execution',
            'MSTJ(22)=2     ! Decay those unstable particles',
            'PARJ(71)=10 .  ! for which ctau  10 mm',
            'MSTP(33)=0     ! no K factors in hard cross sections',
            'MSTP(2)=1      ! which order running alphaS',
            'MSTP(51)=10042 ! structure function chosen (external PDF CTEQ6L1)',
            'MSTP(52)=2     ! work with LHAPDF',
            'PARP(82)=1.921 ! pt cutoff for multiparton interactions',
            'PARP(89)=1800. ! sqrts for which PARP82 is set',
            'PARP(90)=0.227 ! Multiple interactions: rescaling power',
            'MSTP(95)=6     ! CR (color reconnection parameters)',
            'PARP(77)=1.016 ! CR',
            'PARP(78)=0.538 ! CR',
            'PARP(80)=0.1   ! Prob. colored parton from BBR',
            'PARP(83)=0.356 ! Multiple interactions: matter distribution parameter',
            'PARP(84)=0.651 ! Multiple interactions: matter distribution parameter',
            'PARP(62)=1.025 ! ISR cutoff',
            'MSTP(91)=1     ! Gaussian primordial kT',
            'PARP(93)=10.0  ! primordial kT-max',
            'MSTP(81)=21    ! multiple parton interactions 1 is Pythia default',
            'MSTP(82)=4     ! Defines the multi-parton model'),
        processParameters = cms.vstring('MSEL=0         ! User defined processes',
            'MSUB(81)  = 1     ! qqbar to QQbar',
            'MSUB(82)  = 1     ! gg to QQbar',
            'MSTP(7)   = 6     ! flavor = top',
            'PMAS(6,1)  = 172.5  ! top quark mass',
            'PMAS(37,1) = 120  ! charged Higgs mass ',
            'MDME(41,1) = 0   ! t decay into g t',
            'MDME(42,1) = 0   ! t decay into gamma t',
            'MDME(43,1) = 0   ! t decay into Z0 t',
            'MDME(44,1) = 0   ! t decay into W d',
            'MDME(45,1) = 0   ! t decay into W s',
            'MDME(46,1) = 3   ! t decay into W and b (channel is ON for tbar, OFF for t)',
            'MDME(47,1) = 0   ! t decay into W b` ',
            'MDME(48,1) = 0   ! t decay into h0 t',
            'MDME(49,1) = 2   ! t decay into H and b (channel is ON for t, OFF for tbar)',
            'MDME(50,1) = 0   ! t decay into ~chi_10 ~t_1',
            'MDME(51,1) = 0   ! t decay into ~chi_20 ~t_1',
            'MDME(52,1) = 0   ! t decay into ~chi_30 ~t_1',
            'MDME(53,1) = 0   ! t decay into ~chi_40 ~t_1',
            'MDME(54,1) = 0   ! t decay into ~g ~t_1',
            'MDME(55,1) = 0   ! t decay into ~Gravitino ~t_1',
            'MDME(190,1) = 0            !W decay into dbar u',
            'MDME(191,1) = 0            !W decay into dbar c',
            'MDME(192,1) = 0            !W decay into dbar t',
            'MDME(194,1) = 0            !W decay into sbar u',
            'MDME(195,1) = 0            !W decay into sbar c',
            'MDME(196,1) = 0            !W decay into sbar t',
            'MDME(198,1) = 0            !W decay into bbar u',
            'MDME(199,1) = 0            !W decay into bbar c',
            'MDME(200,1) = 0            !W decay into bbar t',
            'MDME(206,1) = 0            !W decay into e+ nu_e',
            'MDME(207,1) = 1            !W decay into mu+ nu_mu',
            'MDME(208,1) = 0            !W decay into tau+ nu_tau',
            'MDME(503,1) = 0   ! H+ decay into dbar u', 
            'MDME(504,1) = 1   ! H+ decay into sbar c',
            'MDME(503,1) = 0   ! H+ decay into dbar u', 
            'MDME(504,1) = 1   ! H+ decay into sbar c',
            'MDME(505,1) = 0   ! H+ decay into bbar t', 
            'MDME(506,1) = 0   ! H+ decay into b`bar t`', 
            'MDME(507,1) = 0   ! H+ decay into e+ nu_e', 
            'MDME(508,1) = 0   ! H+ decay into mu+ nu_mu', 
            'MDME(509,1) = 0   ! H+ decay into tau+ nu_tau (channel is switched on)',
            'MDME(510,1) = 0   ! H+ decay into tau`+ nu`_tau',
            'MDME(511,1) = 0   ! H+ decay into W+ h0', 
            'MDME(512,1) = 0   ! H+ decay into ~chi_10 ~chi_1+', 
            'MDME(513,1) = 0   ! H+ decay into ~chi_10 ~chi_2+', 
            'MDME(514,1) = 0   ! H+ decay into ~chi_20 ~chi_1+',
            'MDME(515,1) = 0   ! H+ decay into ~chi_20 ~chi_2+',
            'MDME(516,1) = 0   ! H+ decay into ~chi_30 ~chi_1+',
            'MDME(517,1) = 0   ! H+ decay into ~chi_30 ~chi_2+', 
            'MDME(518,1) = 0   ! H+ decay into ~chi_40 ~chi_1+',
            'MDME(519,1) = 0   ! H+ decay into ~chi_40 ~chi_2+',
            'MDME(520,1) = 0   ! H+ decay into ~t_1 ~b_1bar   ',
            'MDME(521,1) = 0   ! H+ decay into ~t_2 ~b_1bar   ',
            'MDME(522,1) = 0   ! H+ decay into ~t_1 ~b_2bar   ',
            'MDME(523,1) = 0   ! H+ decay into ~t_2 ~b_2bar   ',
            'MDME(524,1) = 0   ! H+ decay into ~d_Lbar ~u_L   ',
            'MDME(525,1) = 0   ! H+ decay into ~s_Lbar ~c_L   ',
            'MDME(526,1) = 0   ! H+ decay into ~e_L+ ~nu_muL  ',
            'MDME(527,1) = 0   ! H+ decay into ~mu_L+ ~u_L    ',
            'MDME(528,1) = 0   ! H+ decay into ~tau_1+ ~nu_tauL',
            'MDME(529,1) = 0   ! H+ decay into ~tau_2+ ~nu_tauL'),
        parameterSets = cms.vstring('pythiaUESettings',
            'processParameters')
    )
)
process.ProductionFilterSequence = cms.Sequence(process.generator)

# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen_genonly)
process.reconstruction = cms.Path(process.reconstructionWithFamos)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.AODSIMoutput_step = cms.EndPath(process.AODSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step)
process.schedule.extend(process.HLTSchedule)
process.schedule.extend([process.reconstruction,process.AODSIMoutput_step])
# filter all path with the production filter sequence
for path in process.paths:
        getattr(process,path)._seq = process.ProductionFilterSequence * getattr(process,path)._seq

# customisation of the process.

# Automatic addition of the customisation function from HLTrigger.Configuration.customizeHLTforMC
from HLTrigger.Configuration.customizeHLTforMC import customizeHLTforMC

#call to customisation function customizeHLTforMC imported from HLTrigger.Configuration.customizeHLTforMC
process = customizeHLTforMC(process)

# End of customisation functions

