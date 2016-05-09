#pushd /afs/cern.ch/work/g/gkole/chargedHiggs/8TeV/JERStusy/CMSSW_5_3_5/src/
pushd /afs/cern.ch/work/g/gkole/chargedHiggs/8TeV/ele_ch/SLC6/CMSSW_5_3_19/src/
#setcms
eval `scramv1 runtime -csh`
popd
setenv MY_PATH ${PWD}/MiniTree/Selection/src/

if( $?LD_LIBRARY_PATH ) then
  setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${MY_PATH}
else
  setenv LD_LIBRARY_PATH ${MY_PATH}
endif

