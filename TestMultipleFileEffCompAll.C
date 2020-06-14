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
  TString inpath =  "/home/redwan/PlotTestScripts/RootFiles/ANFilesOldTauID";
  TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars/FinalOldTauID";

  TFile* infile        = new TFile(inpath+"/TauEfficiency_ElectronAllID_mA19_OldTauID.root");
  //TFile* infile2        = new TFile(inpath+"/TauEffDModeMClean_mA20_DMode_Jet_Cleaned_dRTest_Total_Medium_NewSelection.root");  
  
  TString Dir ="TauEffDModeLoose";
  TString Dir2 ="TauEffEDModeLoose";
  TString Dir3 ="TauEffDModeMedium";
  TString Dir4 ="TauEffEDModeMedium";
  TString Dir5 ="TauEffDModeTight";
  TString Dir6 ="TauEffEDModeTight";

    
  
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
  extra->SetTextSize(0.04*0.76);
  extra->SetTextColor(kBlack);
  extra->SetTextAlign(11);
  extra->SetTextFont(52);
  
  //TText* lumi = new TText(1,1,"") ;
  TLatex lumi; 
  lumi.SetTextSize(0.04*0.80); 
  lumi.SetTextColor(kBlack);
  lumi.SetTextAlign(31);
  lumi.SetTextFont(42);
  
  //legend                                                                                                                                                                                                                                                                       
  //TLegend *leg = new TLegend(0.15,0.70,0.45,0.85);
  TLegend *leg = new TLegend(0.10,0.65,0.50,0.90);

  
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.035);
  
  //TEfficiency *E    = (TEfficiency*)infile->Get(Dir+"/"+histName)->Clone("E");
  //TEfficiency *E2   =(TEfficiency*)infile->Get(Dir2+"/"+histName)->Clone("E2");

  TEfficiency *E = 0;
  TEfficiency *E2 =0;
  TEfficiency *E3 =0;
  TEfficiency *E4 =0;
  TEfficiency *E5 =0;
  TEfficiency *E6 =0;


  TH1F *Num1 =(TH1F*)infile->Get(Dir+"/"+Num);
  TH1F *Num2 =(TH1F*)infile->Get(Dir2+"/"+Num);
  TH1F *Num3 =(TH1F*)infile->Get(Dir3+"/"+Num);
  TH1F *Num4 =(TH1F*)infile->Get(Dir4+"/"+Num);
  TH1F *Num5 =(TH1F*)infile->Get(Dir5+"/"+Num);
  TH1F *Num6 =(TH1F*)infile->Get(Dir6+"/"+Num);

  TH1F *Den1 =(TH1F*)infile->Get(Dir+"/"+Denom);
  TH1F *Den2 =(TH1F*)infile->Get(Dir2+"/"+Denom);
  TH1F *Den3 =(TH1F*)infile->Get(Dir3+"/"+Denom);
  TH1F *Den4 =(TH1F*)infile->Get(Dir4+"/"+Denom);
  TH1F *Den5 =(TH1F*)infile->Get(Dir5+"/"+Denom);
  TH1F *Den6 =(TH1F*)infile->Get(Dir6+"/"+Denom);


  const TH1F& h_Num1 = *Num1;
  const TH1F& h_Num2 = *Num2;
  const TH1F& h_Num3 = *Num3;
  const TH1F& h_Num4 = *Num4;
  const TH1F& h_Num5 = *Num5;
  const TH1F& h_Num6 = *Num6;


  const TH1F& h_Den1 = *Den1;
  const TH1F& h_Den2 = *Den2;
  const TH1F& h_Den3 = *Den3;
  const TH1F& h_Den4 = *Den4;
  const TH1F& h_Den5 = *Den5;
  const TH1F& h_Den6 = *Den6;

  if(TEfficiency::CheckConsistency(h_Num1,h_Den1))
    {
     E = new TEfficiency(h_Num1,h_Den1);
    }

  if(TEfficiency::CheckConsistency(h_Num2,h_Den2))
    {
      E2 = new TEfficiency(h_Num2,h_Den2);
    }
  if(TEfficiency::CheckConsistency(h_Num3,h_Den3))
    {
      E3 = new TEfficiency(h_Num3,h_Den3);
    }
  if(TEfficiency::CheckConsistency(h_Num4,h_Den4))
    {
      E4 = new TEfficiency(h_Num4,h_Den4);
    }
 if(TEfficiency::CheckConsistency(h_Num5,h_Den5))
    {
      E5 = new TEfficiency(h_Num5,h_Den5);
    }
  if(TEfficiency::CheckConsistency(h_Num6,h_Den6))
    {
      E6 = new TEfficiency(h_Num6,h_Den6);
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
    bool TotalLep=false;
    bool ComboLep=false;
    bool ComboVis=false;
    
    dRTotal =(Num == "NumTotaldR");
    VisTotal = (Num == "NumTotalVis");
    TotalLep= (Num == "NumTotalLep");
    ComboVis = (Num == "NumComboVis");
    ComboLep= (Num == "NumComboLep");

     //VisIso = (Num == "NumIsoVis");
    

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
        E->SetTitle("DecayMode Finding Efficiency; dR(#tau_{had},#tau_{e});#epsilon");
      }
     else if(TotalLep)
      {
        E->Draw("AP");
        E->SetTitle("Total (DecayMode + Isolation) Finding Efficiency; Gen #tau_{e} Pt (GeV);#epsilon");
      }

     else if(dRTotal)
      {
        E->Draw("AP");
        E->SetTitle(" Total (DecayMode + Isolation) Efficiency; dR(#tau_{had},#tau_{e});#epsilon");
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

     else if(ComboVis)
       {
         E->Draw("AP");
         E->SetTitle("#tau_{e}#tau_{had} Efficiency; #tau_{had} Visible Pt (GeV);#epsilon");
       }
       else if(ComboLep)
      {
        E->Draw("AP");
        E->SetTitle(" #tau_{e}#tau_{had} Efficiency; Gen #tau_{e} Pt (GeV);#epsilon");
      }


    else 
      {
	      
	E->Draw("AP");
	E->SetTitle("DecayMode Finding Efficiency; Jet Pt(GeV);#epsilon");
      }
    //E->SetLineWidth(2);
    //E->SetLineColor(kGreen);
    //hs->Add(E);
    
    
    E2->Draw("same");
    //E2->SetLineWidth(2);
    E2->SetLineColor(kBlue);;

    
    E3->Draw("same");
    //E3->SetLineWidth(2);
    E3->SetLineStyle(2);
    //E3->SetLineColor(kGreen);


    E4->Draw("same");
    //E4->SetLineWidth(2);
    E4->SetLineColor(kGreen);

    E5->Draw("same");
    //E5->SetLineWidth(2);
    //E5->SetLineColor(kRed);
    E5->SetLineStyle(3);
    
    E6->Draw("same");
    //E6->SetLineWidth(2);
    E6->SetLineColor(kRed);


    
  /////////////////Setting Range////////////////////





  
  //Yaxis->Draw();
  leg->AddEntry(E,"#tau_{h} Loose Electron ID", "l");
  leg->AddEntry(E3,"#tau_{h} Medium Electron  ID ", "l");
  leg->AddEntry(E5,"#tau_{h} Tight Electron ID ", "l");
  leg->AddEntry(E2,"#tau_{h} ElectronCleaned Loose Electron ID ", "l");
  leg->AddEntry(E4,"#tau_{h} EectronCleaned Medium Electron ID ", "l");
  leg->AddEntry(E6,"#tau_{h} EectronCleaned Tight Electron ID ", "l");
  
  //leg->AddEntry(h3,"slimmedTaus", "l");

  //mg->Draw();
  leg->Draw();
  title->DrawTextNDC(0.13,0.91,"CMS");
  extra->DrawTextNDC(0.23,0.91,"Simulation");
  lumi.DrawLatexNDC(0.9,0.91,"2017 Style MC");
  gPad->Update();
  auto graph = E->GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(1.0);
  gPad->Update();
  auto graph2 = E2->GetPaintedGraph();
  graph2->SetMinimum(0);
  graph2->SetMaximum(1.0);
  gPad->Update();
  auto graph3 = E3->GetPaintedGraph();
  graph3->SetMinimum(0);
  graph3->SetMaximum(1.0);
  gPad->Update();
  auto graph4 = E4->GetPaintedGraph();
  graph4->SetMinimum(0);
  graph4->SetMaximum(1.0);
  gPad->Update();
  auto graph5 = E5->GetPaintedGraph();
  graph5->SetMinimum(0);
  graph5->SetMaximum(1.0);
  gPad->Update();
  auto graph6 = E5->GetPaintedGraph();
  graph6->SetMinimum(0);
  graph6->SetMaximum(1.0);
  gPad->Update();


  gPad->RedrawAxis();  

  
  //Yaxis->Draw();

  if(Num=="NumdR")
    {
      std::size_t pos = Num.find("d");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_Electron_AllID_Comparison_OldTauID.png");
      
    }
  else if(Num=="NumTotaldR")
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_ElectronAllID_Comparison_OldTauID.png");

    }
  
  else if(Num=="NumTotalLep")
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_ElectronAllID_Comparison_OldTauID.png");

    }


  
  else if(Num=="NumVis" )
    {
      std::size_t pos = Num.find("V");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_ElectronAllID_Comparison_OldTauID.png");

    }
  
  else if(Num=="NumTotalVis" )
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_ElectronAllID_Comparison_OldTauID.png");

    }
    else if(Num=="NumIsoVis" )
    {
      std::size_t pos = Num.find("I");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_ElectronAllID_Comparison_OldTauID.png");

    }

    else if(Num=="NumComboVis" )
    {
      std::size_t pos = Num.find("C");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_ElectronAllID_Comparison_OldTauID.png");

    }
   else if(Num=="NumComboLep" )
    {
      std::size_t pos = Num.find("C");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_ElectronAllID_Comparison_OldTauID.png");

    }





  

  else
    {
      std::size_t pos = Num.find("D");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA19_ElectronAllID_Comparison_OldTauID.png");
    }
  //canvas->SaveAs(outpath+"/"+histName+"Compare.pdf");
  
  //canvas->SaveAs(outpath+"/"+histName+".png");   


}

void TestMultipleFileEffCompAll()

{
  // vector <string> Parameter;
  // string Denominator ="DenomDMode";
  // string NumdR="NumdR";
  // string DenomdR="DenomdR";
  string NumdRTotal="NumTotaldR";
  string DenomdRTotal="DenomTotaldR";
  // string NumVis="NumVis";
  // string DenomVis="DenomVis";
  string NumVisTotal="NumTotalVis";
  string DenomVisTotal="DenomTotalVis";
  string NumComboVis="NumComboVis";
  string DenomComboVis="DenomComboVis";
  string NumTotalLep="NumTotalLep";
  string DenomTotalLep="DenomTotalLep";
  string NumComboLep="NumComboLep";
  string DenomComboLep="DenomComboLep";
  // string NumIsoVis="NumIsoVis";
  // string DenomIsoVis="DenomIsoVis";

  
  // Parameter.push_back("NumDMode")
  //;
  
  // Parameters stored in a Vector execute in a loop 
    // for (int i=0; i<Parameter.size(); i++)     
    //   {
    // 	HistSingleVal(Parameter[i],Denominator,i);
    // 	//HistSingleVal(NumdR,DenomdR);
    //   }
    //HistSingleVal(NumdR,DenomdR,1);
    //HistSingleVal(NumVis,DenomVis,2);
    HistSingleVal(NumVisTotal,DenomVisTotal,1);
    HistSingleVal(NumdRTotal,DenomdRTotal,2);
    HistSingleVal(NumTotalLep,DenomTotalLep,3);
    HistSingleVal(NumComboLep,DenomComboLep,4);
    HistSingleVal(NumComboVis,DenomComboVis,5);
    //HistSingleVal(NumIsoVis,DenomIsoVis,5);


}
