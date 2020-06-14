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
  TString inpath =  "/home/redwan/PlotTestScripts";
  TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars";

  TFile* infile        = new TFile(inpath+"/TauEffDModeMClean_mA9_DMode_Jet_Cleaned_dRTest_Total_Lep.root");                                                        
  

  TString Dir ="TauEffDMode";
  TString Dir2 ="TauEffMDMode";
    
  
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
  
  
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.042);
  
  //TEfficiency *E    = (TEfficiency*)infile->Get(Dir+"/"+histName)->Clone("E");
  //TEfficiency *E2   =(TEfficiency*)infile->Get(Dir2+"/"+histName)->Clone("E2");

  TEfficiency *E = 0;
  TEfficiency *E2 =0;

  TH1F *Num1 =(TH1F*)infile->Get(Dir+"/"+Num);
  TH1F *Num2 =(TH1F*)infile->Get(Dir2+"/"+Num);
  
  TH1F *Den1 =(TH1F*)infile->Get(Dir+"/"+Denom);
  TH1F *Den2 =(TH1F*)infile->Get(Dir2+"/"+Denom);

  const TH1F& h_Num1 = *Num1;
  const TH1F& h_Num2 = *Num2;
  const TH1F& h_Den1 = *Den1;
  const TH1F& h_Den2 = *Den2;

  if(TEfficiency::CheckConsistency(h_Num1,h_Den1))
    {
     E = new TEfficiency(h_Num1,h_Den1);
    }

    if(TEfficiency::CheckConsistency(h_Num2,h_Den2))
    {
     E2 = new TEfficiency(h_Num2,h_Den2);
    }








  //TH1F *h3   =(TH1F*)infile3->Get(Dir+"/"+histName)->Clone("h3");
  //bool RebinFlag =  false;
  //bool VarbinFlag = false;
    bool DMode0 =false;
    bool DMode1 =false;
    bool DMode5 =false;
    bool DMode6 =false;
    bool DMode10 =false;
    bool dR=false;
    bool Vis=false;
    bool dRTotal=false;
    bool VisTotal=false;
    bool VisIso =false;
    bool NumTotalLep=false;
    bool dRIso=false;
    bool IsoLep=false;
    //RebinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection")); 
  //VarbinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection"));
  //RebinFlag=(histName == "TauEff");
    DMode0 = (Num =="NumDMode0");
    DMode1 = (Num =="NumDMode1");
    DMode5 = (Num =="NumDMode5");
    DMode6 = (Num =="NumDMode6");
    DMode10 = (Num =="NumDMode10");
    dR =(Num == "NumdR");
    Vis= (Num == "NumVis");
    dRTotal =(Num == "NumTotaldR");
    VisTotal = (Num == "NumTotalVis");
    VisIso = (Num == "NumIsoVis");
    NumTotalLep= (Num == "NumTotalLep");
    dRIso=(Num == "NumIsodR");
    IsoLep=(Num == "NumIsoLep");
    
    if(DMode0)
      {
	E->Draw("AP");
	E->SetTitle("DecayMode Finding Efficiency for Decay Mode 0 -> 1 Prong; Jet Pt(GeV);#epsilon");


      }
    else if(DMode1)
      {
	E->Draw("AP");
	E->SetTitle("DecayMode Finding Efficiency for Decay Mode 1 -> 1 Prong + 1 #pi 0 ; Jet Pt(GeV);#epsilon");
      }
     else if(DMode5)
      {	
        E->Draw("AP");
        E->SetTitle("DecayMode Finding Efficiency for Decay Mode 5 -> 1 Prong + N #pi 0 ; Jet Pt(GeV);#epsilon");
      }

    else if(DMode6)
      {
       	E->Draw("AP");
	E->SetTitle("DecayMode Finding Efficiency for Decay Mode 6 -> 2 Prong; Jet Pt(GeV);#epsilon");
      }
      else if(DMode10)
      {
       	E->Draw("AP");
	E->SetTitle("DecayMode Finding Efficiency for Decay Mode 10 -> 3 Prong; Jet Pt(GeV);#epsilon");
      }
     else if(dR)
      {
        E->Draw("AP");
        E->SetTitle("DecayMode Finding Efficiency; dR(#tau_{had},#tau_{#mu});#epsilon");
      }
     else if(dRIso)
      {
        E->Draw("AP");
        E->SetTitle("Isolation Efficiency; dR(#tau_{had},#tau_{#mu});#epsilon");
      }

     else if(dRTotal)
      {
        E->Draw("AP");
        E->SetTitle(" Total (DecayMode + Isolation) Efficiency; dR(#tau_{had},#tau_{#mu});#epsilon");
      }


    
    else if(Vis)
      {
        E->Draw("AP");
        E->SetTitle("DecayMode Finding Efficiency; #tau_{had} Visible Pt (GeV);#epsilon");
      }
     else if(VisIso)
      {
        E->Draw("AP");
        E->SetTitle("Isolation Efficiency; #tau_{had} Visible Pt (GeV);#epsilon");
      }

        else if(VisTotal)
      {
        E->Draw("AP");
        E->SetTitle("Total (DecayMode + Isolation) Finding Efficiency; #tau_{had} Visible Pt (GeV);#epsilon");
      }
      else if(NumTotalLep)
      {
        E->Draw("AP");
        E->SetTitle("Total (DecayMode + Isolation) Finding Efficiency; Gen #tau_{#mu} Pt (GeV);#epsilon");
      }

         else if(IsoLep)
      {
        E->Draw("AP");
        E->SetTitle("Isolation Efficiency; Gen #tau_{#mu} Pt (GeV);#epsilon");
      }



    else 
      {
	      
	E->Draw("AP");
	E->SetTitle("DecayMode Finding Efficiency; Jet Pt(GeV);#epsilon");
      }
    E->SetLineWidth(2);
    E->SetLineColor(kRed);
  //hs->Add(E);
    
    
    E2->Draw("same");
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

  if(Num=="NumdR")
    {
      std::size_t pos = Num.find("d");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID__Efficiency.png");
      
    }
  else if(Num=="NumIsodR")
    {
      std::size_t pos = Num.find("I");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID__Efficiency.png");

    }
    else if(Num=="NumIsoLep")
    {
      std::size_t pos = Num.find("I");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID_Lep_Efficiency.png");

    }



  else if(Num=="NumTotalLep")
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID_Lep_Efficiency.png");
      
    }

  else if(Num=="NumTotaldR")
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID_Efficiency.png");

    }
  

  
  else if(Num=="NumVis" )
    {
      std::size_t pos = Num.find("V");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID_Lep_Efficiency.png");

    }
  
  else if(Num=="NumTotalVis" )
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID_Efficiency.png");

    }
    else if(Num=="NumIsoVis" )
    {
      std::size_t pos = Num.find("I");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID_Efficiency.png");

    }



  

  else
    {
      std::size_t pos = Num.find("D");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA9_Cleaned_LooseMuonID_Efficiency.png");
    }
  //canvas->SaveAs(outpath+"/"+histName+"Compare.pdf");
  
  //canvas->SaveAs(outpath+"/"+histName+".png");   


}

void TestSingleFileSingleEffMuDMode()

{
  vector <string> Parameter;
  string Denominator ="DenomDMode";
  string NumdR="NumdR";
  string DenomdR="DenomdR";
  string NumIsodR="NumIsodR";
  string DenomIsodR="DenomIsodR";
  string NumdRTotal="NumTotaldR";
  string DenomdRTotal="DenomTotaldR";
  string NumVis="NumVis";
  string DenomVis="DenomVis";
  string NumVisTotal="NumTotalVis";
  string DenomVisTotal="DenomTotalVis";
  string NumIsoVis="NumIsoVis";
  string DenomIsoVis="DenomIsoVis";
  string NumTotalLep="NumTotalLep";
  string DenomTotalLep="DenomTotalLep";
  string NumIsoLep="NumIsoLep";
  string DenomIsoLep="DenomIsoLep";
  

  
  Parameter.push_back("NumDMode");
  
  // Parameters stored in a Vector execute in a loop 
    for (int i=0; i<Parameter.size(); i++)     
      {
	HistSingleVal(Parameter[i],Denominator,i);
	//HistSingleVal(NumdR,DenomdR);
      }
    std::cout<< "Bloop!" <<std::endl;
    HistSingleVal(NumdR,DenomdR,1);
    std::cout<< "Bleep!" <<std::endl;
    HistSingleVal(NumVis,DenomVis,2);
    std::cout<< "Blaap!" <<std::endl;
    HistSingleVal(NumVisTotal,DenomVisTotal,3);
    HistSingleVal(NumdRTotal,DenomdRTotal,4);
    HistSingleVal(NumIsoVis,DenomIsoVis,5);
    HistSingleVal(NumTotalLep,DenomTotalLep,6);
    HistSingleVal(NumIsodR,DenomIsodR,7);
    HistSingleVal(NumIsoLep,DenomIsoLep,8);


}
