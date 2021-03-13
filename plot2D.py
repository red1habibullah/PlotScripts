import tdrStyle
import math
import ROOT
tdrStyle.setTDRStyle()
ROOT.gROOT.SetBatch()


tethDir="/eos/uscms/store/user/zfwd666/2017/bkgEffCheck/TauETauHad/"
tmthDir="/eos/uscms/store/user/zfwd666/2017/bkgEffCheck/TauMuTauHad/"
ththDir="/eos/uscms/store/user/zfwd666/2017/bkgEffCheck/TauHadTauHad/"

canvas1 = ROOT.TCanvas("tmth","data",900,900)
canvas2 = ROOT.TCanvas("teth","data",900,900)
canvas3 = ROOT.TCanvas("thth","data",900,900)
canvas4 = ROOT.TCanvas("tmth_t","data",900,900)
canvas5 = ROOT.TCanvas("teth_t","data",900,900)
canvas6 = ROOT.TCanvas("thth_t","data",900,900)




tethFile=ROOT.TFile(tethDir+"deepTauVSele_vvvloose_deepTauVSmu_vloose_deepTauVSjet_medium.root")
tmthFile=ROOT.TFile(tmthDir+"deepTauVSele_vvvloose_deepTauVSmu_vloose_deepTauVSjet_medium.root")
ththFile=ROOT.TFile(ththDir+"deepDiTauRaw_0.7.root")


tethHist=ROOT.TH2D("",";M_{#mu#mu};M_{#mu#mu#tau#tau}",15,0,15,50,0,500)
tmthHist=ROOT.TH2D("",";M_{#mu#mu};M_{#mu#mu#tau#tau}",15,0,15,50,0,500)
ththHist=ROOT.TH2D("",";M_{#mu#mu};M_{#mu#mu#tau#tau}",15,0,15,50,0,500)
tethHist_t=ROOT.TH2D("",";M_{#tau#tau};M_{#mu#mu#tau#tau}",15,0,15,50,0,500)
tmthHist_t=ROOT.TH2D("",";M_{#tau#tau};M_{#mu#mu#tau#tau}",15,0,15,50,0,500)
ththHist_t=ROOT.TH2D("",";M_{#tau#tau};M_{#mu#mu#tau#tau}",15,0,15,50,0,500)



tethTree=tethFile.Get("TreeMuMuTauTau")
tmthTree=tmthFile.Get("TreeMuMuTauTau")
ththTree=ththFile.Get("TreeMuMuTauTau")


for event in tethTree:
    tethHist.Fill(event.invMassMuMu,event.visMassMuMuTauTau)
    tethHist_t.Fill(event.visMassTauTau,event.visMassMuMuTauTau)
    
for event in tmthTree:
    tmthHist.Fill(event.invMassMuMu,event.visMassMuMuTauTau)
    tmthHist_t.Fill(event.visMassTauTau,event.visMassMuMuTauTau)
for event in ththTree:
    ththHist.Fill(event.invMassMuMu,event.visMassMuMuTauTau)
    ththHist_t.Fill(event.visMassTauTau,event.visMassMuMuTauTau)

canvas1.cd()
tethHist.Draw("COLZ text")
canvas1.Update()
canvas2.cd()
tmthHist.Draw("COLZ text")
canvas2.Update()
canvas3.cd()
ththHist.Draw("COLZ text")
canvas3.Update()
canvas4.cd()
tethHist_t.Draw("COLZ text")
canvas4.Update()
canvas5.cd()
tmthHist_t.Draw("COLZ text")
canvas5.Update()
canvas6.cd()
ththHist_t.Draw("COLZ text")
canvas6.Update()

canvas1.SaveAs("teth.png")
canvas2.SaveAs("tmth.png")
canvas3.SaveAs("thth.png")
canvas4.SaveAs("teth_t.png")
canvas5.SaveAs("tmth_t.png")
canvas6.SaveAs("thth_t.png")
