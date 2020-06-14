//MultipleHistograms+Normalized to unity+Same variable from 2 Files
#include "TString.h"
#include "TH1F.h"
#include "TLatex.h"
#include "TAttLine.h"
#include "TEfficiency.h"
#include "TGaxis.h"
#include <string>
#include <iostream>

void HistSingleVal(string Num,string Denom,int a)

{
  using namespace std;
  //*** read root files, get variables to plot *********                                                                         
  
  //input/output paths                                                                                                                  
  TString inpath =  "/home/redwan/PlotTestScripts/RootFiles/PreANFiles";
  TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars/SemiFinal";

  TFile* infile        = new TFile(inpath+"/TauEfficiency_MuonAllID_mA5_SemiFinal.root");

  //TFile* infile2        = new TFile(inpath+"/TauEffDModeMClean_mA20_DMode_Jet_Cleaned_dRTest_Total_Medium_NewSelection.root");  
  
  //TString Dir2 ="TauEffDMode";
  TString Dir ="TauEffMDModeLoose";
  //TString Dir3 ="TauEffMDModeMedium";
  //TString Dir4 ="TauEffMDModeTight";
    
  
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
  lumi.SetTextSize(0.018);
  lumi.SetTextColor(kBlack);
  lumi.SetTextAlign(31);
  lumi.SetTextFont(42);
  
  //legend                                                                                                                                                                                                                                                                       
  TLegend *leg = new TLegend(0.50,0.70,0.70,0.90);
  
  
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.042);

  TEfficiency *E = 0;
 


  TH2D *Num1 =(TH2D*)infile->Get(Dir+"/"+Num);
  
  TH2D *Den1 =(TH2D*)infile->Get(Dir+"/"+Denom);
 

  const TH2D& h_Num1 = *Num1;
 

  const TH2D& h_Den1 = *Den1;
  
  if(TEfficiency::CheckConsistency(h_Num1,h_Den1))
    {
     E = new TEfficiency(h_Num1,h_Den1);
    }

  bool dRLep=false;
  dRLep= (Num == "NumdRLep");
  //VisIso = (Num == "NumIsoVis");
  
  if(dRLep)
	  {
	    E->Draw("E");
	    //E->SetStatisticOption(TEfficiency::kBBayesian);
	    E->SetTitle("Total (DecayMode + Isolation) Finding Efficiency;dR(#tau_{had},#tau_{#mu});#tau_{#mu} Pt(GeV);#epsilon");
	  }
  
  
  
  
  
  else 
    {
      
      E->Draw("AP");
      E->SetTitle("DecayMode Finding Efficiency; Jet Pt(GeV);#epsilon");
      //E->SetLineColor(kRed);
    }
    
    
  
  
    // E2->Draw("same");
    // E2->SetLineWidth(2);
    // E2->SetLineColor(kBlue);;



    
  /////////////////Setting Range////////////////////





  
  //Yaxis->Draw();
  leg->AddEntry(E,"#tau_{h} ", "l");
  leg->Draw();
  title->DrawTextNDC(0.13,0.91,"CMS");
  extra->DrawTextNDC(0.23,0.91,"Work in Progress");
  lumi.DrawLatexNDC(0.9,0.91,"41.5 fb^{-1} (13 TeV)");



  gPad->Update();
  auto hist = E->GetPaintedHistogram();
  hist->SetMinimum(0);
  hist->SetMaximum(1.0);
  hist->Draw("COLZ");
  hist->GetYaxis()->SetLabelSize(0.025);
  //hist->GetXaxis()->SetTitleOffset(1.65);
  //hist->GetYaxis()->SetTitleOffset(1.65);

  gPad->Update();
  gPad->RedrawAxis();  

  
  //Yaxis->Draw();

  

  if(Num=="NumdRLep")
    {
      std::size_t pos = Num.find("d");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_MuonAllID_Comparison_2D.png");

    }


 


  

  else
    {
      std::size_t pos = Num.find("D");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_MuonAllID_Comparison.png");
    }
  

}

void TestSingleFile2DEffMu()

{
  
  string NumdRLep="NumdRLep";
  string DenomdRLep="DenomdRLep";


    HistSingleVal(NumdRLep,DenomdRLep,1);
    


}
