std::vector<double> EffVector(string Num,string Denom,string inputfile)
{
  using namespace std;
  //*** read root files, get variables to plot *********                                                                              
  vector <double> Efficiency;
  Efficiency.clear();
  
  //input/output paths     
  TString inpath =  "/home/redwan/PlotTestScripts/RootFiles/PreANFiles";
  TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars/SemiFinal";
  //TauEfficiency_MuonAllID_mA9_SemiFinal.root

  TFile* infile        = new TFile(inpath+"/"+inputfile);

  TString Dir ="TauEffDModeLoose";
  TString Dir2 ="TauEffMDModeLoose";
  TString Dir3 ="TauEffDModeMedium";
  TString Dir4 ="TauEffMDModeMedium";
  TString Dir5 ="TauEffDModeTight";
  TString Dir6 ="TauEffMDModeTight";


  TEfficiency *E = 0;
  TEfficiency *E2 =0;
  TEfficiency *E3 =0;
  TEfficiency *E4 =0;
  TEfficiency *E5 =0;
  TEfficiency *E6 =0;

  TH1F *Num1 =(TH1F*)infile->Get(Dir+"/"+Num)->Clone("Num1");
  TH1F *Num2 =(TH1F*)infile->Get(Dir2+"/"+Num)->Clone("Num2");
  TH1F *Num3 =(TH1F*)infile->Get(Dir3+"/"+Num)->Clone("Num3");
  TH1F *Num4 =(TH1F*)infile->Get(Dir4+"/"+Num)->Clone("Num4");
  TH1F *Num5 =(TH1F*)infile->Get(Dir5+"/"+Num)->Clone("Num5");
  TH1F *Num6 =(TH1F*)infile->Get(Dir6+"/"+Num)->Clone("Num6");



  TH1F *Den1 =(TH1F*)infile->Get(Dir+"/"+Denom)->Clone("Den1");
  TH1F *Den2 =(TH1F*)infile->Get(Dir2+"/"+Denom)->Clone("Den2");
  TH1F *Den3 =(TH1F*)infile->Get(Dir3+"/"+Denom)->Clone("Den3");
  TH1F *Den4 =(TH1F*)infile->Get(Dir4+"/"+Denom)->Clone("Den4");
  TH1F *Den5 =(TH1F*)infile->Get(Dir5+"/"+Denom)->Clone("Den5");
  TH1F *Den6 =(TH1F*)infile->Get(Dir6+"/"+Denom)->Clone("Den6");

  double Int_Num1=(double)(Num1->Integral());
  double Int_Den1=(double)(Den1->Integral());

  double Int_Num2=(double)(Num2->Integral());
  double Int_Den2=(double)(Den2->Integral());

  double Int_Num3=(double)(Num3->Integral());
  double Int_Den3=(double)(Den3->Integral());

  double Int_Num4=(double)(Num4->Integral());
  double Int_Den4=(double)(Den4->Integral());

  double Int_Num5=(double)(Num5->Integral());
  double Int_Den5=(double)(Den5->Integral());

  double Int_Num6=(double)(Num6->Integral());
  double Int_Den6=(double)(Den6->Integral());

  TH1F *h_NumT1 = new TH1F("h_NumT1", "", 1, 0,1);
  TH1F *h_NumT2 = new TH1F("h_NumT2", "", 1, 0,1);
  TH1F *h_NumT3 = new TH1F("h_NumT3", "", 1, 0,1);
  TH1F *h_NumT4 = new TH1F("h_NumT4", "", 1, 0,1);
  TH1F *h_NumT5 = new TH1F("h_NumT5", "", 1, 0,1);
  TH1F *h_NumT6 = new TH1F("h_NumT6", "", 1, 0,1);

  h_NumT1->SetBinContent(1,Int_Num1);
  h_NumT2->SetBinContent(1,Int_Num2);
  h_NumT3->SetBinContent(1,Int_Num3);
  h_NumT4->SetBinContent(1,Int_Num4);
  h_NumT5->SetBinContent(1,Int_Num5);
  h_NumT6->SetBinContent(1,Int_Num6);

  TH1F *h_DenT1 = new TH1F("h_DenT1", "", 1, 0,1);
  TH1F *h_DenT2 = new TH1F("h_DenT2", "", 1, 0,1);
  TH1F *h_DenT3 = new TH1F("h_DenT3", "", 1, 0,1);
  TH1F *h_DenT4 = new TH1F("h_DenT4", "", 1, 0,1);
  TH1F *h_DenT5 = new TH1F("h_DenT5", "", 1, 0,1);
  TH1F *h_DenT6 = new TH1F("h_DenT6", "", 1, 0,1);


  h_DenT1->SetBinContent(1,Int_Den1);
  h_DenT2->SetBinContent(1,Int_Den2);
  h_DenT3->SetBinContent(1,Int_Den3);
  h_DenT4->SetBinContent(1,Int_Den4);
  h_DenT5->SetBinContent(1,Int_Den5);
  h_DenT6->SetBinContent(1,Int_Den6);

  



  const TH1F& H_Num1 = *h_NumT1;
  const TH1F& H_Num2 = *h_NumT2;
  const TH1F& H_Num3 = *h_NumT3;
  const TH1F& H_Num4 = *h_NumT4;
  const TH1F& H_Num5 = *h_NumT5;
  const TH1F& H_Num6 = *h_NumT6;


  const TH1F& H_Den1 = *h_DenT1;
  const TH1F& H_Den2 = *h_DenT2;
  const TH1F& H_Den3 = *h_DenT3;
  const TH1F& H_Den4 = *h_DenT4;
  const TH1F& H_Den5 = *h_DenT5;
  const TH1F& H_Den6 = *h_DenT6;

  if(TEfficiency::CheckConsistency(H_Num1,H_Den1))
    {
     E = new TEfficiency(H_Num1,H_Den1);
    }

  if(TEfficiency::CheckConsistency(H_Num2,H_Den2))
    {
      E2 = new TEfficiency(H_Num2,H_Den2);
    }
  if(TEfficiency::CheckConsistency(H_Num3,H_Den3))
    {
      E3 = new TEfficiency(H_Num3,H_Den1);
    }
  if(TEfficiency::CheckConsistency(H_Num4,H_Den4))
    {
      E4 = new TEfficiency(H_Num4,H_Den2);
    }


   if(TEfficiency::CheckConsistency(H_Num5,H_Den5))
    {
      E5 = new TEfficiency(H_Num5,H_Den1);
    }

 if(TEfficiency::CheckConsistency(H_Num6,H_Den6))
    {
      E6 = new TEfficiency(H_Num6,H_Den2);
    }




 double Teff1=E->GetEfficiency(1);
 
 double	Teff2=E2->GetEfficiency(1);

 double	Teff3=E3->GetEfficiency(1);

 double	Teff4=E4->GetEfficiency(1);

 double	Teff5=E5->GetEfficiency(1);

 double	Teff6=E6->GetEfficiency(1);

  cout<< "TEff1 :"<< Teff1 <<endl;
  cout<< "TEff2 :"<< Teff2 <<endl;
  cout<< "TEff3 :"<< Teff3 <<endl;
  cout<< "TEff4 :"<< Teff4 <<endl;
  cout<< "TEff5 :"<< Teff5 <<endl;
  cout<< "TEff6 :"<< Teff6 <<endl;


 double Teff1ErrUp=E->GetEfficiencyErrorUp(1);

 double Teff2ErrUp=E2->GetEfficiencyErrorUp(1);

 double Teff3ErrUp=E3->GetEfficiencyErrorUp(1);

 double Teff4ErrUp=E4->GetEfficiencyErrorUp(1);

 double Teff5ErrUp=E5->GetEfficiencyErrorUp(1);

 double Teff6ErrUp=E6->GetEfficiencyErrorUp(1);


 cout<< "TEff1ErrUp :"<< Teff1ErrUp <<endl;
 cout<< "TEff2ErrUp :"<< Teff2ErrUp <<endl;
 cout<< "TEff3ErrUp :"<< Teff3ErrUp <<endl;
 cout<< "TEff4ErrUp :"<< Teff4ErrUp <<endl;
 cout<< "TEff5ErrUp :"<< Teff5ErrUp <<endl;
 cout<< "TEff6ErrUp :"<< Teff6ErrUp <<endl;



  double Teff1ErrLow=E->GetEfficiencyErrorLow(1);
  
  double Teff2ErrLow=E2->GetEfficiencyErrorLow(1);
  
  double Teff3ErrLow=E3->GetEfficiencyErrorLow(1);
  
  double Teff4ErrLow=E4->GetEfficiencyErrorLow(1);
  
  double Teff5ErrLow=E5->GetEfficiencyErrorLow(1);
  
  double Teff6ErrLow=E6->GetEfficiencyErrorLow(1);
  
  
  cout<< "TEff1ErrLow :"<< Teff1ErrLow <<endl;
  cout<< "TEff2ErrLow :"<< Teff2ErrLow <<endl;
  cout<< "TEff3ErrLow :"<< Teff3ErrLow <<endl;
  cout<< "TEff4ErrLow :"<< Teff4ErrLow <<endl;
  cout<< "TEff5ErrLow :"<< Teff5ErrLow <<endl;
  cout<< "TEff6ErrLow :"<< Teff6ErrLow <<endl;
  

  
 

  double eff1=Int_Num1/Int_Den1;
  double eff2=Int_Num2/Int_Den2;
  double eff3=Int_Num1/Int_Den1;
  double eff4=Int_Num2/Int_Den2;
  double eff5=Int_Num1/Int_Den1;
  double eff6=Int_Num2/Int_Den2;

  cout<< "Eff1 :"<< eff1 <<endl;
  cout<< "Eff2 :"<< eff2 <<endl;
  cout<< "Eff3 :"<< eff3 <<endl;
  cout<< "Eff4 :"<< eff4 <<endl;
  cout<< "Eff5 :"<< eff5 <<endl;
  cout<< "Eff6 :"<< eff6 <<endl;

  Efficiency.push_back(Teff1);
  Efficiency.push_back(Teff2);
  Efficiency.push_back(Teff3);
  Efficiency.push_back(Teff4);
  Efficiency.push_back(Teff5);
  Efficiency.push_back(Teff6);

  Efficiency.push_back(Teff1ErrUp);
  Efficiency.push_back(Teff2ErrUp);
  Efficiency.push_back(Teff3ErrUp);
  Efficiency.push_back(Teff4ErrUp);
  Efficiency.push_back(Teff5ErrUp);
  Efficiency.push_back(Teff6ErrUp);

  Efficiency.push_back(Teff1ErrLow);
  Efficiency.push_back(Teff2ErrLow);
  Efficiency.push_back(Teff3ErrLow);
  Efficiency.push_back(Teff4ErrLow);
  Efficiency.push_back(Teff5ErrLow);
  Efficiency.push_back(Teff6ErrLow);




  
  return Efficiency;
}

int mA(string s)
{
  std::size_t pos =s.rfind("_");
  std::size_t pos2 =s.rfind("A");

  std::string Name=s.substr(pos2+1,pos-pos2-1);
  //std::cout<< " pos: "<< pos <<endl;
  //std::cout<< " pos2: "<< pos2 <<endl;

  std::cout << "  " << stoi(Name) <<std::endl;
  
  return stoi(Name);
}

void TestTEffCombineMuRed(){
  using namespace std;
  std::vector<string> Files={"TauEfficiency_MuonAllID_mA4_SemiFinal.root","TauEfficiency_MuonAllID_mA5_SemiFinal.root","TauEfficiency_MuonAllID_mA7_SemiFinal.root","TauEfficiency_MuonAllID_mA9_SemiFinal.root","TauEfficiency_MuonAllID_mA12_SemiFinal.root","TauEfficiency_MuonAllID_mA13_SemiFinal.root","TauEfficiency_MuonAllID_mA16_SemiFinal.root","TauEfficiency_MuonAllID_mA19_SemiFinal.root","TauEfficiency_MuonAllID_mA20_SemiFinal.root"};
  vector<double> StdLoose;
  vector<double> StdLooseUp;
  vector<double> StdLooseLow;

  vector<double> ClnLoose;
  vector<double> ClnLooseUp;
  vector<double> ClnLooseLow;

  vector<double> StdMedium;
  vector<double> StdMediumUp;
  vector<double> StdMediumLow;

  vector<double> ClnMedium;
  vector<double> ClnMediumUp;
  vector<double> ClnMediumLow;
  
  vector<double> StdTight;
  vector<double> StdTightUp;
  vector<double> StdTightLow;
 
  vector<double> ClnTight;
  vector<double> ClnTightUp;
  vector<double> ClnTightLow;

  vector<double>mAPts;
  



  
  for (auto i :Files)
    {
      std::vector<double> Placeholder;
      Placeholder.clear();
      mAPts.push_back((double)mA(i));
      Placeholder=EffVector("NumTotalVis","DenomTotalVis",i);

      StdLoose.push_back(Placeholder[0]);
      ClnLoose.push_back(Placeholder[1]);

      StdMedium.push_back(Placeholder[2]);
      ClnMedium.push_back(Placeholder[3]);

      StdTight.push_back(Placeholder[4]);
      ClnTight.push_back(Placeholder[5]);

      StdLooseUp.push_back(Placeholder[6]);
      ClnLooseUp.push_back(Placeholder[7]);

      StdMediumUp.push_back(Placeholder[8]);
      ClnMediumUp.push_back(Placeholder[9]);

      StdTightUp.push_back(Placeholder[10]);
      ClnTightUp.push_back(Placeholder[11]);

      StdLooseLow.push_back(Placeholder[12]);
      ClnLooseLow.push_back(Placeholder[13]);

      StdMediumLow.push_back(Placeholder[14]);
      ClnMediumLow.push_back(Placeholder[15]);

      StdTightLow.push_back(Placeholder[16]);
      ClnTightLow.push_back(Placeholder[17]);

      



      
    }

  cout<<"VecSize1: "<<StdLoose.size() <<endl;
  cout<<"VecSize2: "<<ClnLoose.size() <<endl;
  cout<<"VecSize6: "<<ClnTight.size() <<endl;
  cout<<"mA: "<<mAPts.size() <<endl;




  // *********set up canvas/pad *********                                                                                                                                                                                                                                  
  //Bool_t dolog = kFALSE;                                                                                                            
  Bool_t dolog = kTRUE;                                                                                                             
  TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars/SemiFinal";
  TString extraname = "";
  if(dolog){extraname+="_log";}
  int a=1;
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


  TLegend *leg = new TLegend(0.10,0.65,0.50,0.90);


  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.035);

  // canvas->cd();
  TGraphAsymmErrors StdLs(mAPts.size()-1,&mAPts[0],&StdLoose[0],0,0,&StdLooseLow[0] ,&StdLooseUp[0]);
  TGraphAsymmErrors ClnLs(mAPts.size()-1,&mAPts[0],&ClnLoose[0],0,0,&ClnLooseLow[0],&ClnLooseUp[0]);
  TGraphAsymmErrors StdMd(mAPts.size()-1,&mAPts[0],&StdMedium[0],0,0,&StdMediumLow[0],&StdMediumUp[0]);
  TGraphAsymmErrors ClnMd(mAPts.size()-1,&mAPts[0],&ClnMedium[0],0,0,&ClnMediumLow[0],&ClnMediumUp[0]);
  TGraphAsymmErrors StdTt(mAPts.size()-1,&mAPts[0],&StdTight[0],0,0,&StdTightLow[0],&StdTightUp[0]);
  TGraphAsymmErrors ClnTt(mAPts.size()-1,&mAPts[0],&ClnTight[0],0,0,&ClnTightLow[0],&ClnTightUp[0]);




  StdLs.Draw("ALP");
  //StdLs.SetMarkerStyle(8);
  StdLs.SetLineWidth(2);
  StdLs.SetMinimum(0.0);
  StdLs.SetMaximum(1.0);
  StdLs.SetLineColor(kBlue);
  StdLs.SetLineStyle(2);
  StdLs.SetTitle("Total (DecayMode + Isolation) Efficiency");
  StdLs.GetXaxis()->SetTitle("m_{a} (Gev)");
  StdLs.GetYaxis()->SetTitle("#tau_{#mu}#tau_{h} Total (DecayMode + Isolation) Efficiency");

  gPad->Update();



  ClnLs.Draw("same");
  //ClnLs.SetMarkerStyle(8);
  ClnLs.SetLineWidth(2);
  ClnLs.SetLineColor(kBlue);
  gPad->Update();
    
  

  StdMd.Draw("same");
  //StdMd.SetMarkerStyle(8);
  StdMd.SetLineWidth(2);
  StdMd.SetLineStyle(2);
  StdMd.SetLineColor(kGreen);
  gPad->Update();


  ClnMd.Draw("same");
  //ClnMd.SetMarkerStyle(8);
  ClnMd.SetLineWidth(2);
  ClnMd.SetLineColor(kGreen);
  gPad->Update();


  StdTt.Draw("same");
  //StdTt.SetMarkerStyle(8);
  StdTt.SetLineWidth(2);
  StdTt.SetLineStyle(2);
  StdTt.SetLineColor(kRed);
  gPad->Update();


  ClnTt.Draw("same");
  //ClnTt.SetMarkerStyle(8);
  ClnTt.SetLineWidth(2);
  ClnTt.SetLineColor(kRed);
  gPad->Update();
    



 


  

  







  gPad->Update();
  //gPad->RedrawAxis();

  
  
  
  leg->AddEntry(&StdLs,"#tau_{h} Loose Muon ID", "l");    
  leg->AddEntry(&ClnLs,"#tau_{h} MuonCleaned Loose Muon ID", "l");
  leg->AddEntry(&StdMd,"#tau_{h} Medium Muon ID", "l");
  leg->AddEntry(&ClnMd,"#tau_{h} MuonCleaned Medium Muon ID", "l");
  leg->AddEntry(&StdTt,"#tau_{h} Tight Muon ID", "l");
  leg->AddEntry(&ClnTt,"#tau_{h} MuonCleaned Tight Muon ID", "l");

  
  leg->Draw();
  title->DrawTextNDC(0.13,0.91,"CMS");
  extra->DrawTextNDC(0.23,0.91,"Simulation");
  lumi.DrawLatexNDC(0.9,0.91,"2017 Style MC");                                                                                       
  gPad->Update();                                                                                                                  
  gPad->RedrawAxis();                                                                                                             
  canvas->SaveAs(outpath+"/"+"MuonEfficiencyCombinationTEffRedefine.png");
  






}
    
    
