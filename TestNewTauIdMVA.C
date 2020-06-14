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
  //TString inpath =  "/home/redwan/PlotTestScripts/RootFiles/PreANFiles";
  //TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars/Final";
  TString inpath =  "/home/redwan/PlotTestScripts/RootFiles/ANFilesNewTauID";
  TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars/FinalNewID";


  TFile* infile        = new TFile(inpath+"/TauEfficiency_ma20_NewTauID.root");
  TString Dir ="TauEffVVLoose";
  TString Dir2 ="TauEffVLoose";
  TString Dir3 ="TauEffLoose";
  TString Dir4 ="TauEffMedium";
  TString Dir5 ="TauEffTight";
  TString Dir6 ="TauEffVTight";  
  TString Dir7 ="TauEffVVTight";
  TString Dir8 ="TauEffEleVVLoose";
  TString Dir9 ="TauEffEleVLoose";
  TString Dir10 ="TauEffEleLoose";
  TString Dir11 ="TauEffEleMedium";
  TString Dir12 ="TauEffEleTight";
  TString Dir13 ="TauEffEleVTight";
  TString Dir14 ="TauEffEleVVTight";
    

    
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
  lumi.SetTextSize(0.04*0.8);
  lumi.SetTextColor(kBlack);
  lumi.SetTextAlign(31);
  lumi.SetTextFont(42);
  
  //legend                                                                                                                                                                                                                                                                       
  //TLegend *leg = new TLegend(0.50,0.70,0.70,0.90);
  
  
  // leg->SetBorderSize(0);
  // leg->SetFillStyle(0);
  // leg->SetTextSize(0.042);
  
  TLegend *leg = new TLegend(0.10,0.65,0.45,0.90);

  
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.020);

  //TEfficiency *E    = (TEfficiency*)infile->Get(Dir+"/"+histName)->Clone("E");
  //TEfficiency *E2   =(TEfficiency*)infile->Get(Dir2+"/"+histName)->Clone("E2");

  TEfficiency *E = 0;
  TEfficiency *E2 =0;
  TEfficiency *E3 =0;
  TEfficiency *E4 =0;
  TEfficiency *E5 =0;
  TEfficiency *E6 =0;
  TEfficiency *E7 =0;
  TEfficiency *E8 =0;
  TEfficiency *E9 =0;
  TEfficiency *E10=0;
  TEfficiency *E11=0;
  TEfficiency *E12=0;
  TEfficiency *E13=0;
  TEfficiency *E14=0;
 

  TH1F *Num1 =(TH1F*)infile->Get(Dir+"/"+Num);
  TH1F *Num2 =(TH1F*)infile->Get(Dir2+"/"+Num);
  TH1F *Num3 =(TH1F*)infile->Get(Dir3+"/"+Num);
  TH1F *Num4 =(TH1F*)infile->Get(Dir4+"/"+Num);
  TH1F *Num5 =(TH1F*)infile->Get(Dir5+"/"+Num);
  TH1F *Num6 =(TH1F*)infile->Get(Dir6+"/"+Num);
  TH1F *Num7 =(TH1F*)infile->Get(Dir7+"/"+Num);
  TH1F *Num8 =(TH1F*)infile->Get(Dir8+"/"+Num);
  TH1F *Num9 =(TH1F*)infile->Get(Dir9+"/"+Num);
  TH1F *Num10 =(TH1F*)infile->Get(Dir10+"/"+Num);
  TH1F *Num11 =(TH1F*)infile->Get(Dir11+"/"+Num);
  TH1F *Num12 =(TH1F*)infile->Get(Dir12+"/"+Num);
  TH1F *Num13 =(TH1F*)infile->Get(Dir13+"/"+Num);
  TH1F *Num14 =(TH1F*)infile->Get(Dir14+"/"+Num);



  

  
  TH1F *Den1 =(TH1F*)infile->Get(Dir+"/"+Denom);
  TH1F *Den2 =(TH1F*)infile->Get(Dir2+"/"+Denom);
  TH1F *Den3 =(TH1F*)infile->Get(Dir3+"/"+Denom);
  TH1F *Den4 =(TH1F*)infile->Get(Dir4+"/"+Denom);
  TH1F *Den5 =(TH1F*)infile->Get(Dir5+"/"+Denom);
  TH1F *Den6 =(TH1F*)infile->Get(Dir6+"/"+Denom);
  TH1F *Den7 =(TH1F*)infile->Get(Dir7+"/"+Denom);
  TH1F *Den8 =(TH1F*)infile->Get(Dir8+"/"+Denom);
  TH1F *Den9 =(TH1F*)infile->Get(Dir9+"/"+Denom);
  TH1F *Den10 =(TH1F*)infile->Get(Dir10+"/"+Denom);
  TH1F *Den11 =(TH1F*)infile->Get(Dir11+"/"+Denom);
  TH1F *Den12 =(TH1F*)infile->Get(Dir12+"/"+Denom);
  TH1F *Den13 =(TH1F*)infile->Get(Dir13+"/"+Denom);
  TH1F *Den14 =(TH1F*)infile->Get(Dir14+"/"+Denom);

  const TH1F& h_Num1 = *Num1;
  const TH1F& h_Num2 = *Num2;
  const TH1F& h_Num3 = *Num3;
  const TH1F& h_Num4 = *Num4;
  const TH1F& h_Num5 = *Num5;
  const TH1F& h_Num6 = *Num6;
  const TH1F& h_Num7 = *Num7;
  const TH1F& h_Num8 = *Num8;
  const TH1F& h_Num9 = *Num9;
  const TH1F& h_Num10 = *Num10;
  const TH1F& h_Num11 = *Num11;
  const TH1F& h_Num12 = *Num12;
  const TH1F& h_Num13 = *Num13;
  const TH1F& h_Num14 = *Num14;
  

  const TH1F& h_Den1 = *Den1;
  const TH1F& h_Den2 = *Den2;
  const TH1F& h_Den3 = *Den3;
  const TH1F& h_Den4 = *Den4;
  const TH1F& h_Den5 = *Den5;
  const TH1F& h_Den6 = *Den6;
  const TH1F& h_Den7 = *Den7;
  const TH1F& h_Den8 = *Den8;
  const TH1F& h_Den9 = *Den9;
  const TH1F& h_Den10 = *Den10;
  const TH1F& h_Den11 = *Den11;
  const TH1F& h_Den12 = *Den12;
  const TH1F& h_Den13 = *Den13;
  const TH1F& h_Den14 = *Den14;
  
  
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


 if(TEfficiency::CheckConsistency(h_Num7,h_Den7))
    {
      E7 = new TEfficiency(h_Num7,h_Den7);
    }


 if(TEfficiency::CheckConsistency(h_Num8,h_Den8))
    {
      E8 = new TEfficiency(h_Num8,h_Den8);
    }


 if(TEfficiency::CheckConsistency(h_Num9,h_Den9))
    {
      E9 = new TEfficiency(h_Num9,h_Den9);
    }

 if(TEfficiency::CheckConsistency(h_Num10,h_Den10))
    {
      E10 = new TEfficiency(h_Num10,h_Den10);
    }

 if(TEfficiency::CheckConsistency(h_Num11,h_Den11))
    {
      E11 = new TEfficiency(h_Num11,h_Den11);
    }
if(TEfficiency::CheckConsistency(h_Num12,h_Den12))
    {
      E12 = new TEfficiency(h_Num12,h_Den12);
    }


if(TEfficiency::CheckConsistency(h_Num13,h_Den13))
    {
      E13 = new TEfficiency(h_Num13,h_Den13);
    }


if(TEfficiency::CheckConsistency(h_Num14,h_Den14))
    {
      E14 = new TEfficiency(h_Num14,h_Den14);
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
    //RebinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection")); 
  //VarbinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection"));
  //RebinFlag=(histName == "TauEff");
    //DMode0 = (Num =="NumDMode0");
    //DMode1 = (Num =="NumDMode1");
    //DMode5 = (Num =="NumDMode5");
    //DMode6 = (Num =="NumDMode6");
    //DMode10 = (Num =="NumDMode10");
    //dR =(Num == "NumdR");
    //Vis= (Num == "NumVis");
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
        E->SetTitle("DecayMode Finding Efficiency; dR(#tau_{had},#tau_{lep});#epsilon");
      }
     else if(TotalLep)
      {
        E->Draw("AP");
        E->SetTitle("#tau_{had} (DecayMode + Isolation) Finding Efficiency; Gen #tau_{e} Pt (GeV);#epsilon");
      }

     else if(dRTotal)
      {
        E->Draw("AP");
        E->SetTitle(" #tau_{had} (DecayMode + Isolation) Efficiency; dR(#tau_{had},#tau_{lep});#epsilon");
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
	 E->SetTitle("#tau_{had} (DecayMode + Isolation) Finding Efficiency; #tau_{had} Visible Pt (GeV);#epsilon");
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
     E->SetLineColor(kRed);
     E->SetLineStyle(2);

      //E->SetLineWidth(2);
    //E->SetLineColor(kGreen);
    //hs->Add(E);
    
    
    E2->Draw("same");
    E2->SetLineStyle(2);
    E2->SetLineColor(kGreen);


    E3->Draw("same");
    E3->SetLineStyle(2);
    E3->SetLineColor(kGray);


    E4->Draw("same");
    E4->SetLineStyle(2);
    E4->SetLineColor(kBlue);


    E5->Draw("same");
    E5->SetLineStyle(2);
    E5->SetLineColor(kMagenta);



    E6->Draw("same");
    E6->SetLineStyle(2);
    E6->SetLineColor(kViolet);


    E7->Draw("same");
    E7->SetLineStyle(2);
    E7->SetLineColor(kBlack);
       

    E8->Draw("same");
    E8->SetLineColor(kRed);

    E9->Draw("same");  
    E9->SetLineColor(kGreen);
    
    E10->Draw("same");
    E10->SetLineColor(kGray);

    E11->Draw("same");
    E11->SetLineColor(kBlue);

    E12->Draw("same");
    E12->SetLineColor(kMagenta);

    E13->Draw("same");
    E13->SetLineColor(kViolet);
    
    E14->Draw("same");
    E14->SetLineColor(kBlack);

    

    
  /////////////////Setting Range////////////////////





  
  //Yaxis->Draw();
  leg->AddEntry(E,"#tau_{h} VVLoose", "l");
  leg->AddEntry(E2,"#tau_{h} VLoose ", "l");
  leg->AddEntry(E3,"#tau_{h} Loose ", "l");
  leg->AddEntry(E4,"#tau_{h} Medium ", "l");
  leg->AddEntry(E5,"#tau_{h} Tight ", "l");
  leg->AddEntry(E6,"#tau_{h} VTight ", "l");
  leg->AddEntry(E7,"#tau_{h} VVTight ", "l");
  leg->AddEntry(E8,"#tau_{h} VVLoose Electron Cleaned ", "l");
  leg->AddEntry(E9,"#tau_{h} VLoose Electron Cleaned ", "l");
  leg->AddEntry(E10,"#tau_{h} Loose Electron Cleaned", "l");
  leg->AddEntry(E11,"#tau_{h} Medium Electron Cleaned ", "l");
  leg->AddEntry(E12,"#tau_{h} Tight Electron Cleaned ", "l");
  leg->AddEntry(E13,"#tau_{h} VTight Electron Cleaned ", "l");
  leg->AddEntry(E14,"#tau_{h} VVTight Electron Cleaned ", "l");



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
  auto graph6 = E6->GetPaintedGraph();
  graph6->SetMinimum(0);
  graph6->SetMaximum(1.0);
  gPad->Update();
  auto graph7 = E7->GetPaintedGraph();
  graph7->SetMinimum(0);
  graph7->SetMaximum(1.0);
  gPad->Update();
  auto graph8 = E8->GetPaintedGraph();
  graph8->SetMinimum(0);
  graph8->SetMaximum(1.0);
  gPad->Update();
  auto graph9 = E9->GetPaintedGraph();
  graph9->SetMinimum(0);
  graph9->SetMaximum(1.0);
  gPad->Update();
  auto graph10 = E10->GetPaintedGraph();
  graph10->SetMinimum(0);
  graph10->SetMaximum(1.0);
  gPad->Update();
  auto graph11 = E11->GetPaintedGraph();
  graph11->SetMinimum(0);
  graph11->SetMaximum(1.0);
  gPad->Update();
  auto graph12 = E12->GetPaintedGraph();
  graph12->SetMinimum(0);
  graph12->SetMaximum(1.0);
  gPad->Update();
  auto graph13 = E13->GetPaintedGraph();
  graph13->SetMinimum(0);
  graph13->SetMaximum(1.0);
  gPad->Update();
  auto graph14 = E14->GetPaintedGraph();
  graph14->SetMinimum(0);
  graph14->SetMaximum(1.0);
  gPad->Update();
  
  
  gPad->RedrawAxis();  
  
  
  //Yaxis->Draw();
  
  if(Num=="NumdR")
    {
      std::size_t pos = Num.find("d");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_AllID_Comparison_OldTauID.png");
      
    }
  else if(Num=="NumTotaldR")
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_mA5_NewTauID.png");

    }
  
  else if(Num=="NumTotalLep")
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_mA5_NewTauID.png");

    }
    else if(Num=="NumComboLep")
    {
      std::size_t pos = Num.find("C");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_mA5_NewTauID.png");

    }



  
  else if(Num=="NumVis" )
    {
      std::size_t pos = Num.find("V");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_mA5_NewTauID.png");

    }
  
  else if(Num=="NumTotalVis" )
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_mA5_NewTauID.png");

    }

    else if(Num=="NumComboVis" )
    {
      std::size_t pos = Num.find("C");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_mA5_NewTauID.png");

    }




  
    else if(Num=="NumIsoVis" )
    {
      std::size_t pos = Num.find("I");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_mA5_NewTauID.png");

    }



  

  else
    {
      std::size_t pos = Num.find("D");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"mA5_Electron_mA20_NewTauID.png");
    }
  //canvas->SaveAs(outpath+"/"+histName+"Compare.pdf");
  
  //canvas->SaveAs(outpath+"/"+histName+".png");   


}

void TestNewTauIdMVA()

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
  
  string NumVisCombo="NumComboVis";
  string DenomVisCombo="DenomComboVis";
  
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
    HistSingleVal(NumVisCombo,DenomVisCombo,5);
     

    //HistSingleVal(NumIsoVis,DenomIsoVis,5);


}
