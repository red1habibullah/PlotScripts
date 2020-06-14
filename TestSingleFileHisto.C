//plot a single histogram from a single rootfile using necessary  
#include "TString.h"
#include "TH1F.h"
#include "TLatex.h"

void TestSingleFileHisto()
{
  using namespace std;
  //*** read root files, get variables to plot *********                                                                         
  
  //input/output paths                                                                                                                  
  TString inpath =  "/home/redwan/PlotTestScripts";
  TString outpath = "/home/redwan/PlotTestScripts";
  
  //open/read input root file & get histograms                                                                                          
  TFile* infile        = new TFile(inpath+"/test_Validate_new_Eclean.root");//The RootFile with the histogram
  TString Dir ="ValidateTau";
  TString histName="chargedIsoPtSum"; //The name of the historgram                      
  //TString binnings     = "(30,0,1)";
  // ********* read root files, get variables to plot end *********                                                                     
  
  // *********set up canvas/pad *********                                                                                               
  //Bool_t dolog = kFALSE;
  Bool_t dolog = kTRUE;                                                                                                               
  TString extraname = "";
  if(dolog){extraname+="_log";}
  
  //canvas                                                                                                                     
  TCanvas* canvas = new TCanvas("canvas","canvas",600,600);
  canvas->Clear();
  canvas->cd();
  canvas->SetGrid();
  //Pad
  TPad *pad  = new TPad("pad1", "pad1", 0, 0.0, 1, 1.0);
  gStyle->SetOptStat(0);
  pad->SetLogy(dolog);
  pad->SetTickx();
  pad->SetTicky();
  pad->Draw();
  pad->SetGrid();
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
  lumi.SetTextSize(0.03);
  lumi.SetTextColor(kBlack);
  lumi.SetTextAlign(31);
  lumi.SetTextFont(42);

  //legend                                                                                                                                                                                                                                                                       
  TLegend *leg = new TLegend(0.65,0.65,0.95,0.95);
  //TLegend *leg = new TLegend(0.45,0.7,0.64,0.85);                                                                                                                                                                                                                              
  leg->SetNColumns(2);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  
  //get histograms
  //add legend entries                                                                                                                                                                                                                                       
  TH1F *h    = (TH1F*)infile->Get(Dir+"/"+histName)->Clone("h");
  h->Draw("hist");
  h->SetLineWidth(2);
  leg->AddEntry(h,"slimmedTausElectronCleaned ", "l");
  leg->Draw();
  title->DrawTextNDC(0.13,0.91,"CMS");
  extra->DrawTextNDC(0.23,0.91,"Preliminary");
  lumi.DrawLatexNDC(0.9,0.91,"41.5 fb^{-1} (13 TeV)");
  gPad->Update();
  gPad->RedrawAxis();
  

  canvas->SaveAs(outpath+"/"+histName+".pdf");
  //canvas->SaveAs(outpath+"/"+histName+".png");   


}
