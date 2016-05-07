# ExampleAnalysis
########### Steps to run the code:#####
-----------------------------------------------------------------
git clone https://github.com/gourangakole/ExampleAnalysis.git

cd ExampleAnalysis/

Check "setPaths.sh" file

cd MiniTree/Selection/src/

make clean

make

cd - (to return "ExampleAnalysis" directory)

Check the file "HplusAnalyzer_kinfit11_2M_v1.C" with your favorite editor e,g. vi, emacs

# Compile the code
root -l 
.L HplusAnalyzer_kinfit11_2M_v1.C+
HplusAnalyzer_kinfit11_2M_v1 t;
t.processEvents();


# In one goal
root -l 'runme.C("HplusAnalyzer_kinfit11_2M_v1")'

