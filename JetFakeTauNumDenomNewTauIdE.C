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
  TString inpath =  "/home/redwan/PlotTestScripts/RootFiles/ANFilesNewTauID";
  TString outpath = "/home/redwan/PlotTestScripts/JetFakeTauNewTauId";

  TFile* infile        = new TFile(inpath+"/JetFakeTau_NewTauID.root");                                                        
  

  TString Dir ="JetFakeTauVVLoose";
  TString Dir2 ="JetFakeTauVLoose";
  TString Dir3 ="JetFakeTauLoose";
  TString Dir4 ="JetFakeTauMedium";
  TString Dir5 ="JetFakeTauTight";
  TString Dir6 ="JetFakeTauVTight";
  TString Dir7 ="JetFakeTauVVTight";
  TString Dir8 ="JetFakeTauEleVVLoose";
  TString Dir9 ="JetFakeTauEleVLoose";
  TString Dir10 ="JetFakeTauEleLoose";
  TString Dir11 ="JetFakeTauEleMedium";
  TString Dir12 ="JetFakeTauEleTight";
  TString Dir13 ="JetFakeTauEleVTight";
  TString Dir14 ="JetFakeTauEleVVTight";
  // *********set up canvas/pad *********                                                                                               
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
  pad->SetLogy(dolog);
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
  
  TLatex lumi; 
  lumi.SetTextSize(0.04*0.8);
  lumi.SetTextColor(kBlack);
  lumi.SetTextAlign(31);
  lumi.SetTextFont(42);
  
  //legend                                                                                                                                                                                                                                                                       
  TLegend *leg = new TLegend(0.25,0.70,0.85,0.90);
  
  
  leg->SetBorderSize(0);
  leg->SetNColumns(2);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.020);
  

  TEfficiency *E = 0;
  TEfficiency *E2 =0;
  TEfficiency *E3 =0;
  TEfficiency *E4 =0;
  TEfficiency *E5 = 0;
  TEfficiency *E6 =0;
  TEfficiency *E7 =0;
  TEfficiency *E8 =0;
  TEfficiency *E9 = 0;
  TEfficiency *E10 =0;
  TEfficiency *E11 =0;
  TEfficiency *E12 =0;
  TEfficiency *E13 =0;
  TEfficiency *E14 =0;

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
  TH1F *Den11=(TH1F*)infile->Get(Dir11+"/"+Denom);
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
   if(TEfficiency::CheckConsistency(h_Num5,h_Den5))
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




  
  bool num=false;
  bool DM=false;
  bool Tau=false;
  
  num = (Num =="NumIn");
  DM= (Num=="NumDM");
  Tau=(Num=="NumTau");
  



     if(num)
       {
	 E->Draw("AP");
	 E->SetTitle("Jet->Tau Fake Rate; Jet Pt(GeV);#epsilon");
       }
     else if(DM)                                                                                                                                                                                                                                                         
      {                                                                                                                                                                                                                                                                     
        E->Draw("AP");                                                                                                                                                                                                                                                      
        E->SetTitle("Tau Fake Rate; Tau Pt (GeV);#epsilon");                                                                                                                                                                                          
      }                                                                                                                                                                                                                                                                     
     else if(Tau)
       {                                                                                                                                                                                                                                                                     
        E->Draw("AP");                                                                                                                                                                                                                                                      
        E->SetTitle("Tau Fake Rate; Tau Pt (GeV);#epsilon");                                                                                                                                                                                          
       }
       E->SetLineColor(kRed);
       E->SetLineStyle(2);
       
       
       
       
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
  gPad->RedrawAxis();
  auto graph3 = E3->GetPaintedGraph();
  graph3->SetMinimum(0);
  graph3->SetMaximum(1.0);
  gPad->Update();
  gPad->RedrawAxis();
  auto graph4 = E4->GetPaintedGraph();
  graph4->SetMinimum(0);
  graph4->SetMaximum(1.0);
  gPad->Update();
  auto graph5 = E5->GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(1.0);
  gPad->Update();
  auto graph6 = E6->GetPaintedGraph();
  graph6->SetMinimum(0);
  graph6->SetMaximum(1.0);
  gPad->Update();
  gPad->RedrawAxis();
  auto graph7 = E7->GetPaintedGraph();
  graph7->SetMinimum(0);
  graph7->SetMaximum(1.0);
  gPad->Update();
  gPad->RedrawAxis();
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
  gPad->RedrawAxis();
  auto graph11 = E11->GetPaintedGraph();
  graph11->SetMinimum(0);
  graph11->SetMaximum(1.0);
  gPad->Update();
  gPad->RedrawAxis();
  auto graph12 = E12->GetPaintedGraph();
  graph12->SetMinimum(0);
  graph12->SetMaximum(1.0);
  gPad->Update();
  auto graph13 = E13->GetPaintedGraph();
  graph13->SetMinimum(0);
  graph13->SetMaximum(1.0);
  gPad->Update();
  gPad->RedrawAxis();
  auto graph14 = E14->GetPaintedGraph();
  graph14->SetMinimum(0);
  graph14->SetMaximum(1.0);
  gPad->Update();

  gPad->RedrawAxis();


  //Yaxis->Draw();

  if(Num=="NumIn")
    {
      std::size_t pos = Num.find("In");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"JetFakeTau_Efficiency_ElectronNewTauId.png");
      
    }
  else if(Num=="NumDM")
    {
      std::size_t pos = Num.find("D");                                                                                                                                                                                                                                       
      std::string Name=Num.substr(pos);                                                                                                                                                                                                                                      
      std::cout << "  " << Name <<std::endl;                                                                                                                                                                                                                                 
      canvas->SaveAs(outpath+"/"+Name+"JetFakeTau_Efficiency_ElectronNewTauId.png");

    }
   else if(Num=="NumTau")
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"JetFakeTau_Efficiency_ElectronNewTauId.png");

    }

    else                                                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                                       
      //std::size_t pos = Num.find("D");                                                                                                                                                                                                                                      
      //std::string Name=Num.substr(pos);                                                                                                                                                                                                                                     
      //std::cout << "  " << Name <<std::endl;                                                                                                                                                                                                                                
      canvas->SaveAs(outpath+"/JetFakeTau_Efficiency_Electron_NewTauId.png");                                                                                                                                                                                       
    }   

  
  
  


}

void JetFakeTauNumDenomNewTauIdE()

{
  // vector <string> Parameter;
  // string Denominator ="DenomDMode";
  string Num="NumIn";
  string Denom="DenomIn";
  string NumDM="NumDM";
  string DenomDM="DenomDM";
  string NumTau="NumTau";
  string DenomTau="DenomTau";
  
  
    HistSingleVal(Num,Denom,1);
    HistSingleVal(NumDM,DenomDM,2);
    HistSingleVal(NumTau,DenomTau,3);

  


}
