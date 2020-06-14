//MultipleHistograms+Normalized to unity+Several times for different variables
#include "TString.h"
#include "TH1F.h"
#include "TLatex.h"
#include "TAttLine.h"

//void TestMultipleHistoNormalizedLoop()

void HistSingleVal(string histName,int a)

{
  using namespace std;
  //*** read root files, get variables to plot *********                                                                         
  
  //input/output paths                                                                                                                  
  TString inpath =  "/home/redwan/PlotTestScripts";
  TString outpath = "/home/redwan/PlotTestScripts";
  
  //open/read input root file & get histograms                                                                                          
  // TFile* infile        = new TFile(inpath+"/test_Validate_new_Eclean.root");//The RootFile with the histogram
  // TFile* infile2       = new TFile(inpath+"/test_Validate_new_Mclean.root");
  // TFile* infile3       = new TFile(inpath+"/test_Validate_new_Unclean.root");
  //TFile* infile        = new TFile(inpath+"/test_Validate_Cut_Eclean.root");//The RootFile with the histogram
  //TFile* infile2       = new TFile(inpath+"/test_Validate_Cut_Mclean.root");
  //TFile* infile3       = new TFile(inpath+"/test_Validate_Cut_Unclean.root");

  //TFile* infile        = new TFile(inpath+"/test_Validate_MCut_Eclean.root");//The RootFile with the histogram
  //TFile* infile2       = new TFile(inpath+"/test_Validate_MCut_Mclean.root");
  //TFile* infile3       = new TFile(inpath+"/test_Validate_MCut_Unclean.root");
  // TFile* infile        = new TFile(inpath+"/test_Validate_NumberCompare_Mclean.root");
   TFile* infile        = new TFile(inpath+"/test_Validate_NumberCompare_MMatched_JetMatched.root");

   //TString Dir ="CompareTau";
   TString Dir ="CompareTauM"; 
   //TString histName="ip3d"; //The name of the historgram                      
  //TString binnings     = "(30,0,1)";
  // ********* read root files, get variables to plot end *********                                                                     
  
  // *********set up canvas/pad *********                                                                                               
  Bool_t dolog = kFALSE;
  //Bool_t dolog = kTRUE;                                                                                                               
  TString extraname = "";
  if(dolog){extraname+="_log";}
  std:: string tag = to_string(a);
  
  //canvas                                                                                                                     
  TCanvas* canvas = new TCanvas(("canvas"+tag).c_str(),"canvas",700,700);
  canvas->Clear();
  canvas->cd();
  canvas->SetGrid();
  //Pad
  TPad *pad  = new TPad("pad1", "pad1", 0.02, 0.02, 1.0, 1.0);
  gStyle->SetOptStat(0);
  pad->SetLogy(dolog);
  pad->SetTickx();
  pad->SetTicky();
  pad->Draw();
  //pad->SetGrid();
  pad->SetFillStyle(4000);
  pad->cd();
  gStyle->SetPalette(71);

  //CMS Text
  TText* title = new TText(1,1,"") ;
  title->SetTextSize(0.04);
  title->SetTextColor(kBlack);
  title->SetTextAlign(11);
  title->SetTextFont(61);

  TText* extra = new TText(1,1,"") ;
  extra->SetTextSize(0.04*0.76);
  extra->SetTextColor(kBlack);
  extra->SetTextAlign(11);
  extra->SetTextFont(52);
  
  //TText* lumi = new TText(1,1,"") ;
  TLatex lumi; 
  lumi.SetTextSize(0.04*0.8);
  lumi.SetTextColor(kBlack);
  lumi.SetTextAlign(31);
  lumi.SetTextFont(42);
  
  //legend                                                                                                                                                                                                                                                                       
  TLegend *leg = new TLegend(0.55,0.80,0.90,0.90);
  //TLegend *leg = new TLegend(0.45,0.7,0.64,OB0.85);                                                                                                                                                                                                                              
  //leg->SetNColumns(2);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.016);
  //get histograms
  //add legend entries                                                                                                                                                                                                                                       
  TH1F *h    = (TH1F*)infile->Get(Dir+"/"+histName)->Clone("h");
  //TH1F *h2   =(TH1F*)infile2->Get(Dir+"/"+histName)->Clone("h2");
  //TH1F *h3   =(TH1F*)infile3->Get(Dir+"/"+histName)->Clone("h3");
  //bool RebinFlag =  false;
  //bool VarbinFlag = false;
  //RebinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection")); 
  //VarbinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection"));
  //RebinFlag=((histName =="chargedEmEnergy2D") || (histName =="chargedHadronEnergy2D") || (histName =="chargedMultiplicity2D") || (histName =="chargedEmEnergy2D"));
  
  //h->Draw("hist");
  h->Draw("COLZ");
  //Double_t scale_h1 =1/h->Integral();
  //h->Scale(scale_h1);
  //h->SetLineWidth(2);
  
  // h2->Draw("hist same");
  // Double_t scale_h2 =1/h2->Integral();
  // h2->Scale(scale_h2);
  // h2->SetLineWidth(2);
  // h2->SetLineColor(kMagenta);
  
  // h3->Draw("hist same");
  // Double_t scale_h3 =1/h3->Integral();
  // h3->Scale(scale_h3);
  // h3->SetLineWidth(2);
  // h3->SetLineColor(kRed);

  /*if(RebinFlag)
    {
      
      h->Rebin(10);
      //h2->Rebin(10);
      // h3->Rebin(10);
    }
  */
  //leg->AddEntry(h,"MuonCleaned Taus vs Uncleaned Taus", "l");
  //leg->AddEntry(h2,"slimmedTausMuonCleaned ", "l");
  //leg->AddEntry(h3,"slimmedTaus", "l");
  
  leg->Draw();
  title->DrawTextNDC(0.13,0.91,"CMS");
  extra->DrawTextNDC(0.23,0.91,"Preliminary");
  lumi.DrawLatexNDC(0.9,0.91,"41.5 fb^{-1} (13 TeV)");
  gPad->Update();
  gPad->RedrawAxis();
  
  
  
  canvas->SaveAs(outpath+"/"+histName+"JetPlots.png");
  //canvas->SaveAs(outpath+"/"+histName+"Compare.pdf");

  //canvas->SaveAs(outpath+"/"+histName+".png");   


}

void TestSingleFileMultipleVar()

{
  vector <string> Parameter;
  
  Parameter.push_back("DiffsignalGammaCands");
  Parameter.push_back("DiffsignalNeutrHadrCands");
  Parameter.push_back("DiffsignalChargedHadrCands");
  Parameter.push_back("dR(Tau,TauCleaned)");
  Parameter.push_back("DiffisolationChargedHadrCands");
  Parameter.push_back("DiffisolationNeutrHadrCands");
  Parameter.push_back("DiffisolationGammaCands");
  Parameter.push_back("neutralHadronEnergy2D");
  Parameter.push_back("chargedHadronEnergy2D");
  Parameter.push_back("chargedEmEnergy2D");
  Parameter.push_back("photonEnergy2D");
  Parameter.push_back("neutralMultiplicity2D");
  Parameter.push_back("chargedHadronMultiplicity2D");
  Parameter.push_back("chargedMultiplicity2D");
  Parameter.push_back("photonMultiplicity2D");
  Parameter.push_back("muonMultiplicity2D");
  Parameter.push_back("electronMultiplicity2D");
  Parameter.push_back("neutralHadronMultiplicity2D");
  Parameter.push_back("JetEnergy2D");

  // Parameters stored in a Vector execute in a loop 
    for (int i=0; i<Parameter.size(); i++)     
      {
	HistSingleVal(Parameter[i],i);
      }
  
}
