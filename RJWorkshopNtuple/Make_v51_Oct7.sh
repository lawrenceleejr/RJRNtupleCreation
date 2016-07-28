mkdir -p ../../../../BKG_v51_Oct7
mkdir -p ../../../../SIG_v51_Oct7
./MakeZeroLeptonTree.x -ofile=../../../../BKG_v51_Oct7/Top.root -ifile=/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Oct7/Top.root
./MakeZeroLeptonTree.x -ofile=../../../../BKG_v51_Oct7/DiBoson.root -ifile=/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Oct7/DibosonMassiveCB.root
./MakeZeroLeptonTree.x -ofile=../../../../BKG_v51_Oct7/Wjets.root -ifile=/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Oct7/WMassiveCB.root
./MakeZeroLeptonTree.x -ofile=../../../../BKG_v51_Oct7/Zjets.root -ifile=/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Oct7/ZMassiveCB.root
./MakeZeroLeptonTree.x -ofile=../../../../BKG_v51_Oct7/QCD.root -ifile=/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Oct7/QCD.root
./MakeZeroLeptonTree.x -ofile=../../../../BKG_v51_Oct7/GammaJet.root -ifile=/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Oct7/GAMMAMassiveCB.root

