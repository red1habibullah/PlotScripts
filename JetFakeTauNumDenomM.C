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
  TString outpath = "/home/redwan/PlotTestScripts/JetFakeTauOldTauId";

  TFile* infile        = new TFile(inpath+"/JetFakeTau_AllID_Rebin.root");                                                        
  

  //TString Dir ="TauEffDMode";
  //TString Dir2 ="TauEffEDMode";

  TString Dir ="JetFakeTau";
  TString Dir2 ="JetFakeTauMLoose";
  TString Dir3 ="JetFakeTauMMedium";
  TString Dir4 ="JetFakeTauMTight";
  
  
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
  
  //TText* lumi = new TText(1,1,"") ;
  TLatex lumi; 
  lumi.SetTextSize(0.04*0.8);
  lumi.SetTextColor(kBlack);
  lumi.SetTextAlign(31);
  lumi.SetTextFont(42);
  
  //legend                                                                                                                                                                                                                                                                       
  TLegend *leg = new TLegend(0.10,0.65,0.50,0.85);
  
  
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.032);
  

  TEfficiency *E = 0;
  TEfficiency *E2 =0;
  TEfficiency *E3 =0;
  TEfficiency *E4 =0;



  
  TH1F *Num1 =(TH1F*)infile->Get(Dir+"/"+Num);
  TH1F *Num2 =(TH1F*)infile->Get(Dir2+"/"+Num);
  TH1F *Num3 =(TH1F*)infile->Get(Dir3+"/"+Num);
  TH1F *Num4 =(TH1F*)infile->Get(Dir4+"/"+Num);


  
  TH1F *Den1 =(TH1F*)infile->Get(Dir+"/"+Denom);
  TH1F *Den2 =(TH1F*)infile->Get(Dir2+"/"+Denom);
  TH1F *Den3 =(TH1F*)infile->Get(Dir3+"/"+Denom);
  TH1F *Den4 =(TH1F*)infile->Get(Dir4+"/"+Denom);
  

  const TH1F& h_Num1 = *Num1;
  const TH1F& h_Num2 = *Num2;
  const TH1F& h_Num3 = *Num3;
  const TH1F& h_Num4 = *Num4;
  

  const TH1F& h_Den1 = *Den1;
  const TH1F& h_Den2 = *Den2;
  const TH1F& h_Den3 = *Den3;
  const TH1F& h_Den4 = *Den4;





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
  
  





    // bool DMode0 =false;
    // bool DMode1 =false;
    // bool DMode5 =false;
    // bool DMode6 =false;
    // bool DMode10 =false;
    // bool dR=false;
    // bool Vis=false;
    // bool dRTotal=false;
    // bool VisTotal=false;
    // bool VisIso =false;
  bool num=false;
  bool DM=false;
  bool Tau=false;
  
    //RebinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection")); 
  //VarbinFlag=((histName == "chargedIsoPtSum") ||(histName == "neutralIsoPtSum") || (histName == "puCorrPtSum") || (histName == "photonPtSumOutsideSignalCone") || (histName == "footprintCorrection"));
  //RebinFlag=(histName == "TauEff");
  num = (Num =="NumIn");
  DM= (Num=="NumDM");
  Tau=(Num=="NumTau");
  



     if(num)
       {
	 E->Draw("AP");
	 E->SetTitle("Jet Fake Tau Efficiency; Jet Pt(GeV);#epsilon");
       }
     else if(DM)                                                                                                                                                                                                                                                         
      {                                                                                                                                                                                                                                                                     
        E->Draw("AP");                                                                                                                                                                                                                                                      
        E->SetTitle("Jet Fake Tau Efficiency; Tau Pt (GeV);#epsilon");                                                                                                                                                                                          
      }                                                                                                                                                                                                                                                                     
     else if(Tau)
       {                                                                                                                                                                                                                                                                     
        E->Draw("AP");                                                                                                                                                                                                                                                      
        E->SetTitle("Jet Fake Tau Efficiency; Tau Pt (GeV);#epsilon");                                                                                                                                                                                          
       }                                                                                                                                                                                                                                                                     





     //E->SetLineWidth(2);
    //E->SetLineColor(kRed);
  //hs->Add(E);
    
    
    E2->Draw("same");
    //E2->SetLineWidth(2);
    E2->SetLineColor(kBlue);
    
    E3->Draw("same");
    //E3->SetLineWidth(2);
    E3->SetLineColor(kGreen);

    E4->Draw("same");
    //E4->SetLineWidth(2);
    E4->SetLineColor(kRed);
  /////////////////Setting Range////////////////////




  leg->AddEntry(E,"#tau_{h}", "l");
  leg->AddEntry(E2,"#tau_{h} MuonCleaned Loose Muon ID", "l");
  leg->AddEntry(E3,"#tau_{h} MuonCleaned Medium Muon ID", "l");
  leg->AddEntry(E4,"#tau_{h} MuonCleaned Tight Muon ID", "l");


  //leg->AddEntry(h3,"slimmedTaus", "l");

  //mg->Draw();
  leg->Draw();
  title->DrawTextNDC(0.13,0.91,"CMS");
  extra->DrawTextNDC(0.23,0.91,"Simulation");
  lumi.DrawLatexNDC(0.9,0.91,"2017 Style MC");
  gPad->Update();
  auto graph = E->GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(0.8);
  gPad->Update();
  auto graph2 = E2->GetPaintedGraph();
  graph2->SetMinimum(0);
  graph2->SetMaximum(0.8);
  gPad->Update();
  gPad->RedrawAxis();
  auto graph3 = E3->GetPaintedGraph();
  graph3->SetMinimum(0);
  graph3->SetMaximum(0.8);
  gPad->Update();
  gPad->RedrawAxis();
  auto graph4 = E4->GetPaintedGraph();
  graph4->SetMinimum(0);
  graph4->SetMaximum(0.8);
  gPad->Update();
  gPad->RedrawAxis();


  //Yaxis->Draw();

  if(Num=="NumIn")
    {
      std::size_t pos = Num.find("In");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"JetFakeTau_Efficiency_MuonALLID_Rebin.png");
      
    }
  else if(Num=="NumDM")
    {
      std::size_t pos = Num.find("D");                                                                                                                                                                                                                                       
      std::string Name=Num.substr(pos);                                                                                                                                                                                                                                      
      std::cout << "  " << Name <<std::endl;                                                                                                                                                                                                                                 
      canvas->SaveAs(outpath+"/"+Name+"JetFakeTau_Efficiency_MuonALLID.png");

    }
   else if(Num=="NumTau")
    {
      std::size_t pos = Num.find("T");
      std::string Name=Num.substr(pos);
      std::cout << "  " << Name <<std::endl;
      canvas->SaveAs(outpath+"/"+Name+"JetFakeTau_Efficiency_MuonALLID.png");

    }

    else                                                                                                                                                                                                                                                                      
    {                                                                                                                                                                                                                                                                       
      //std::size_t pos = Num.find("D");                                                                                                                                                                                                                                      
      //std::string Name=Num.substr(pos);                                                                                                                                                                                                                                     
      //std::cout << "  " << Name <<std::endl;                                                                                                                                                                                                                                
      canvas->SaveAs(outpath+"/JetFakeTau_Efficiency_MuonALLID.png");                                                                                                                                                                                       
    }   

  
  
  // else if(Num=="NumTotaldR")
  //   {
  //     std::size_t pos = Num.find("T");
  //     std::string Name=Num.substr(pos);
  //     std::cout << "  " << Name <<std::endl;
  //     canvas->SaveAs(outpath+"/"+Name+"mA20_Cleaned_LooseElectronID_Efficiency.png");

  //   }
  

  
  // else if(Num=="NumVis" )
  //   {
  //     std::size_t pos = Num.find("V");
  //     std::string Name=Num.substr(pos);
  //     std::cout << "  " << Name <<std::endl;
  //     canvas->SaveAs(outpath+"/"+Name+"mA20_Cleaned_LooseElectronID_Efficiency.png");

  //   }
  
  // else if(Num=="NumTotalVis" )
  //   {
  //     std::size_t pos = Num.find("T");
  //     std::string Name=Num.substr(pos);
  //     std::cout << "  " << Name <<std::endl;
  //     canvas->SaveAs(outpath+"/"+Name+"mA20_Cleaned_LooseElectronID_Efficiency.png");

  //   }
  //  else if(Num=="NumIsoVis" )
  //   {
  //     std::size_t pos = Num.find("I");
  //     std::string Name=Num.substr(pos);
  //     std::cout << "  " << Name <<std::endl;
  //     canvas->SaveAs(outpath+"/"+Name+"mA20_Cleaned_LooseElectronID_Efficiency.png");

  //   }

  

  // else
  //   {
  //     std::size_t pos = Num.find("D");
  //     std::string Name=Num.substr(pos);
  //     std::cout << "  " << Name <<std::endl;
  //     canvas->SaveAs(outpath+"/"+Name+"mA20_Cleaned_LooseElectronID_Efficiency.png");
  //   }
  //canvas->SaveAs(outpath+"/"+histName+"Compare.pdf");
  
  //canvas->SaveAs(outpath+"/"+histName+".png");   


}

void JetFakeTauNumDenomM()

{
  // vector <string> Parameter;
  // string Denominator ="DenomDMode";
  string Num="NumIn";
  string Denom="DenomIn";
  string NumDM="NumDM";
  string DenomDM="DenomDM";
  string NumTau="NumTau";
  string DenomTau="DenomTau";
  
  // string NumdRTotal="NumTotaldR";
  // string DenomdRTotal="DenomTotaldR";
  // string NumVis="NumVis";
  // string DenomVis="DenomVis";
  // string NumVisTotal="NumTotalVis";
  // string DenomVisTotal="DenomTotalVis";
  // string NumIsoVis="NumIsoVis";
  // string DenomIsoVis="DenomIsoVis";

  
  // Parameter.push_back("NumDMode");
  //Parameter.push_back("NumDMode0");
  //Parameter.push_back("NumDMode1");
  //Parameter.push_back("NumDMode5");
  //Parameter.push_back("NumDMode6");
  //Parameter.push_back("NumDMode10");
  // Parameter.push_back("TauEff");
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
    // for (int i=0; i<Parameter.size(); i++)     
    //   {
    // 	HistSingleVal(Parameter[i],Denominator,i);
    // 	//HistSingleVal(NumdR,DenomdR);
    //   }
    HistSingleVal(Num,Denom,1);
    HistSingleVal(NumDM,DenomDM,2);
    HistSingleVal(NumTau,DenomTau,3);

    // HistSingleVal(NumVis,DenomVis,2);
    // HistSingleVal(NumVisTotal,DenomVisTotal,3);
    // HistSingleVal(NumdRTotal,DenomdRTotal,4);
    // HistSingleVal(NumIsoVis,DenomIsoVis,5);



}
