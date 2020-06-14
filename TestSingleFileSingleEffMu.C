//MultipleHistograms+Normalized to unity+Same variable from 2 Files
#include "TString.h"
#include "TH1F.h"
#include "TLatex.h"
#include "TAttLine.h"
#include "TEfficiency.h"
//#include "THStack.h"
//#include "TMultiGraph.h"
#include "TGaxis.h"

//void TestMultipleHistoNormalizedLoop()

void HistSingleVal(string histName,int a)

{
  using namespace std;
  //*** read root files, get variables to plot *********                                                                         
  
  //input/output paths                                                                                                                  
  TString inpath =  "/home/redwan/PlotTestScripts";
  TString outpath = "/home/redwan/PlotTestScripts/PlotsTauIsoEfficiency";
  
  //open/read input root file & get histograms                                                                                          
  // TFile* infile        = new TFile(inpath+"/test_Validate_new_Eclean.root");//The RootFile with the histogram
  // TFile* infile2       = new TFile(inpath+"/test_Validate_new_Mclean.root");
  // TFile* infile3       = new TFile(inpath+"/test_Validate_new_Unclean.root");
  // TFile* infile        = new TFile(inpath+"/test_Validate_Cut_Eclean.root");//The RootFile with the histogram
  // TFile* infile2       = new TFile(inpath+"/test_Validate_Cut_Mclean.root");
  // TFile* infile3       = new TFile(inpath+"/test_Validate_Cut_Unclean.root");

  // TFile* infile        = new TFile(inpath+"/test_Validate_MCut_Eclean.root");//The RootFile with the histogram
  // TFile* infile2       = new TFile(inpath+"/test_Validate_MCut_Mclean.root");
  // TFile* infile3       = new TFile(inpath+"/test_Validate_MCut_Unclean.root");

  //TFile* infile        = new TFile(inpath+"/test_Validate_Cut_Mclean.root");
  //TFile* infile2       = new TFile(inpath+"/test_Validate_MCut_Mclean.root");
  
  TFile* infile        = new TFile(inpath+"/TauEffDModeMClean_mA20_DMode_Jet_Cleaned_dRTest_Total.root");                                                        
  //TFile* infile2       = new TFile(inpath+"/test_TauEffMCleaned.root");                                                       


  TString Dir ="TauEffDMode";
  TString Dir2 ="TauEffMDMode";
    
  //TString histName="ip3d"; //The name of the historgram                      
  //TString binnings     = "(30,0,1)";
  // ********* read root files, get variables to plot end *********                                                                     
  
  // *********set up canvas/pad *********                                                                                               
  //Bool_t dolog = kFALSE;
  Bool_t dolog = kTRUE;                                                                                                               
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
  //pad->SetLogy(dolog);
  pad->SetTickx();
  pad->SetTicky();
  pad->Draw();
  // pad->SetGrid();
  pad->SetFillStyle(4000);
  pad->cd();
  gStyle->SetPalette(71);
  //CMS Text
  TText* title = new TText(1,1,"") ;
  title->SetTextSize(0.04);
  title->SetTextColor(kBlack);
  title->SetTextAlign(11);
  title->SetTextFont(62);
  
  TText* extra = new TText(1,1,"") ;
  extra->SetTextSize(0.04);
  extra->SetTextColor(kBlack);
  extra->SetTextAlign(11);
  extra->SetTextFont(52);
  
  //TText* lumi = new TText(1,1,"") ;
  TLatex lumi; 
  lumi.SetTextSize(0.02);
  lumi.SetTextColor(kBlack);
  lumi.SetTextAlign(31);
  lumi.SetTextFont(42);
  
  //legend                                                                                                                                                                                                                                                                       
  TLegend *leg = new TLegend(0.50,0.65,0.80,0.95);
  //TLegend *leg = new TLegend(0.45,0.7,0.64,0.85);
  
  //leg->SetNColumns(2);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.042);
  //get histograms
  //add legend entries
  //THStack *hs = new THStack("hs","");  
  //TMultiGraph *mg = new TMultiGraph();
  TEfficiency *E    = (TEfficiency*)infile->Get(Dir+"/"+histName)->Clone("E");
  TEfficiency *E2   =(TEfficiency*)infile->Get(Dir2+"/"+histName)->Clone("E2");
  //TH1F *h3   =(TH1F*)infile3->Get(Dir+"/"+histName)->Clone("h3");
  //bool RebinFlag =  false;
  //bool VarbinFlag = false;
  //RebinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection")); 
  //VarbinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection"));
  //RebinFlag=(histName == "TauEff");
  E->Draw("");

  //Double_t scale_h1 =1/h->Integral();
  //h->Scale(scale_h1);
  E->SetLineWidth(2);
  E->SetLineColor(kRed);
  //hs->Add(E);

  
  E2->Draw("same");
  //E->Draw("same");
  //Double_t scale_h2 =1/h2->Integral();
  //h2->Scale(scale_h2);
  E2->SetLineWidth(2);
  E2->SetLineColor(kMagenta);

  
  /////////////////Setting Range////////////////////





  //hs->Add(E2);
  //h3->Draw("hist same");
  //Double_t scale_h3 =1/h3->Integral();
  //h3->Scale(scale_h3);
  //h3->SetLineWidth(2);
  //h3->SetLineColor(kRed);
  //if(RebinFlag)
  //{
      
  //E->Rebin(5);
  //E2->Rebin(5);
      //h3->Rebin(10);
  //}
  
  
  //Yaxis->Draw();
  leg->AddEntry(E,"#tau_{h}", "l");
  leg->AddEntry(E2,"#tau_{h}muon cleaned", "l");
  //leg->AddEntry(h3,"slimmedTaus", "l");

  //mg->Draw();
  leg->Draw();
  title->DrawTextNDC(0.13,0.91,"CMS");
  extra->DrawTextNDC(0.23,0.91,"Work in Progress");
  lumi.DrawLatexNDC(0.9,0.91,"41.5 fb^{-1} (13 TeV)");
  gPad->Update();
  auto graph = E->GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(1.1);
  gPad->Update();
  auto graph2 = E2->GetPaintedGraph();
  graph2->SetMinimum(0);
  graph2->SetMaximum(1.1);
  gPad->Update();
  gPad->RedrawAxis();
  //Yaxis->Draw();
  
  
  canvas->SaveAs(outpath+"/"+histName+"mA20_LooseMuonID_IsoEfficiency.png");
  //canvas->SaveAs(outpath+"/"+histName+"Compare.pdf");

  //canvas->SaveAs(outpath+"/"+histName+".png");   


}

void TestSingleFileSingleEffMu()

{
  vector <string> Parameter;
  
  // Parameter.push_back("TauEffDMode");
  // Parameter.push_back("TauEffDModes");
  Parameter.push_back("TauEff");
  // Parameter.push_back("TauEffDMode0");
  // Parameter.push_back("TauEffDMode1");
  // Parameter.push_back("TauEffDMode5");
  // Parameter.push_back("TauEffDMode6");
  // Parameter.push_back("TauEffDMode10");
  //Parameter.push_back("JetPt");
  //Parameter.push_back("TauPt");
  // Parameter.push_back("chargedIsoPtSum");
  // Parameter.push_back("neutralIsoPtSum");
  // Parameter.push_back("puCorrPtSum");
  // Parameter.push_back("photonPtSumOutsideSignalCone");
  // Parameter.push_back("footprintCorrection");
  // Parameter.push_back("decayDistMag");
  // Parameter.push_back("dxy");
  // Parameter.push_back("dxySig");
  // Parameter.push_back("ip3d");
  // Parameter.push_back("ip3dSig");

  // Parameters stored in a Vector execute in a loop 
    for (int i=0; i<Parameter.size(); i++)     
      {
	HistSingleVal(Parameter[i],i);
      }
  
}
