std::vector<double> EffVector(string Num,string Denom,string inputfile)
{
  using namespace std;
  //*** read root files, get variables to plot *********                                                                              
  vector <double> Efficiency;
  Efficiency.clear();
  cout<< " " <<inputfile<<endl;
  //input/output paths     
  TString inpath =  "/home/redwan/PlotTestScripts/RootFiles/ANFilesNewTauID";
  TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars/FinalNewTauID";
  //TauEfficiency_MuonAllID_mA9_SemiFinal.root

  TFile* infile        = new TFile(inpath+"/"+inputfile);


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
  TString Dir12="TauEffEleTight";
  TString Dir13 ="TauEffEleVTight";
  TString Dir14 ="TauEffEleVVTight";
    
  
  TEfficiency *E = 0;
  TEfficiency *E2 =0;
  TEfficiency *E3 =0;
  TEfficiency *E4 =0;
  TEfficiency *E5 =0;
  TEfficiency *E6 =0;
  TEfficiency *E7 = 0;
  TEfficiency *E8 =0;
  TEfficiency *E9 =0;
  TEfficiency *E10 =0;
  TEfficiency *E11 =0;
  TEfficiency *E12 =0;
  TEfficiency *E13 = 0;
  TEfficiency *E14 =0;
  
  
  TH1F *Num1 =(TH1F*)infile->Get(Dir+"/"+Num)->Clone("Num1");
  TH1F *Num2 =(TH1F*)infile->Get(Dir2+"/"+Num)->Clone("Num2");
  TH1F *Num3 =(TH1F*)infile->Get(Dir3+"/"+Num)->Clone("Num3");
  TH1F *Num4 =(TH1F*)infile->Get(Dir4+"/"+Num)->Clone("Num4");
  TH1F *Num5 =(TH1F*)infile->Get(Dir5+"/"+Num)->Clone("Num5");
  TH1F *Num6 =(TH1F*)infile->Get(Dir6+"/"+Num)->Clone("Num6");
  TH1F *Num7 =(TH1F*)infile->Get(Dir7+"/"+Num)->Clone("Num7");
  TH1F *Num8 =(TH1F*)infile->Get(Dir8+"/"+Num)->Clone("Num8");
  TH1F *Num9 =(TH1F*)infile->Get(Dir9+"/"+Num)->Clone("Num9");
  TH1F *Num10 =(TH1F*)infile->Get(Dir10+"/"+Num)->Clone("Num10");
  TH1F *Num11 =(TH1F*)infile->Get(Dir11+"/"+Num)->Clone("Num11");
  TH1F *Num12 =(TH1F*)infile->Get(Dir12+"/"+Num)->Clone("Num6");
  TH1F *Num13 =(TH1F*)infile->Get(Dir13+"/"+Num)->Clone("Num5");
  TH1F *Num14 =(TH1F*)infile->Get(Dir14+"/"+Num)->Clone("Num6");


  TH1F *Den1 =(TH1F*)infile->Get(Dir+"/"+Denom)->Clone("Den1");
  TH1F *Den2 =(TH1F*)infile->Get(Dir2+"/"+Denom)->Clone("Den2");
  TH1F *Den3 =(TH1F*)infile->Get(Dir3+"/"+Denom)->Clone("Den3");
  TH1F *Den4 =(TH1F*)infile->Get(Dir4+"/"+Denom)->Clone("Den4");
  TH1F *Den5 =(TH1F*)infile->Get(Dir5+"/"+Denom)->Clone("Den5");
  TH1F *Den6 =(TH1F*)infile->Get(Dir6+"/"+Denom)->Clone("Den6");
  TH1F *Den7 =(TH1F*)infile->Get(Dir7+"/"+Denom)->Clone("Den7");
  TH1F *Den8 =(TH1F*)infile->Get(Dir8+"/"+Denom)->Clone("Den8");
  TH1F *Den9 =(TH1F*)infile->Get(Dir9+"/"+Denom)->Clone("Den9");
  TH1F *Den10 =(TH1F*)infile->Get(Dir10+"/"+Denom)->Clone("Den10");
  TH1F *Den11 =(TH1F*)infile->Get(Dir11+"/"+Denom)->Clone("Den11");
  TH1F *Den12 =(TH1F*)infile->Get(Dir12+"/"+Denom)->Clone("Den12");
  TH1F *Den13 =(TH1F*)infile->Get(Dir13+"/"+Denom)->Clone("Den13");
  TH1F *Den14 =(TH1F*)infile->Get(Dir14+"/"+Denom)->Clone("Den14");


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

  
  double Int_Num7=(double)(Num7->Integral());
  double Int_Den7=(double)(Den7->Integral());

  double Int_Num8=(double)(Num8->Integral());
  double Int_Den8=(double)(Den8->Integral());

  double Int_Num9=(double)(Num9->Integral());
  double Int_Den9=(double)(Den9->Integral());

  double Int_Num10=(double)(Num10->Integral());
  double Int_Den10=(double)(Den10->Integral());

  double Int_Num11=(double)(Num11->Integral());
  double Int_Den11=(double)(Den11->Integral());

  double Int_Num12=(double)(Num12->Integral());
  double Int_Den12=(double)(Den12->Integral());

  double Int_Num13=(double)(Num13->Integral());
  double Int_Den13=(double)(Den13->Integral());

  double Int_Num14=(double)(Num14->Integral());
  double Int_Den14=(double)(Den14->Integral());








  TH1F *h_NumT1 = new TH1F("h_NumT1", "", 1, 0,1);
  TH1F *h_NumT2 = new TH1F("h_NumT2", "", 1, 0,1);
  TH1F *h_NumT3 = new TH1F("h_NumT3", "", 1, 0,1);
  TH1F *h_NumT4 = new TH1F("h_NumT4", "", 1, 0,1);
  TH1F *h_NumT5 = new TH1F("h_NumT5", "", 1, 0,1);
  TH1F *h_NumT6 = new TH1F("h_NumT6", "", 1, 0,1);
  TH1F *h_NumT7 = new TH1F("h_NumT7", "", 1, 0,1);
  TH1F *h_NumT8 = new TH1F("h_NumT8", "", 1, 0,1);
  TH1F *h_NumT9 = new TH1F("h_NumT9", "", 1, 0,1);
  TH1F *h_NumT10 = new TH1F("h_NumT10", "", 1, 0,1);
  TH1F *h_NumT11 = new TH1F("h_NumT11", "", 1, 0,1);
  TH1F *h_NumT12 = new TH1F("h_NumT12", "", 1, 0,1);
  TH1F *h_NumT13 = new TH1F("h_NumT13", "", 1, 0,1);
  TH1F *h_NumT14 = new TH1F("h_NumT14", "", 1, 0,1);





  h_NumT1->SetBinContent(1,Int_Num1);
  h_NumT2->SetBinContent(1,Int_Num2);
  h_NumT3->SetBinContent(1,Int_Num3);
  h_NumT4->SetBinContent(1,Int_Num4);
  h_NumT5->SetBinContent(1,Int_Num5);
  h_NumT6->SetBinContent(1,Int_Num6);
  h_NumT7->SetBinContent(1,Int_Num7);
  h_NumT8->SetBinContent(1,Int_Num8);
  h_NumT9->SetBinContent(1,Int_Num9);
  h_NumT10->SetBinContent(1,Int_Num10);
  h_NumT11->SetBinContent(1,Int_Num11);
  h_NumT12->SetBinContent(1,Int_Num12);
  h_NumT13->SetBinContent(1,Int_Num13);
  h_NumT14->SetBinContent(1,Int_Num14);

  

  
  TH1F *h_DenT1 = new TH1F("h_DenT1", "", 1, 0,1);
  TH1F *h_DenT2 = new TH1F("h_DenT2", "", 1, 0,1);
  TH1F *h_DenT3 = new TH1F("h_DenT3", "", 1, 0,1);
  TH1F *h_DenT4 = new TH1F("h_DenT4", "", 1, 0,1);
  TH1F *h_DenT5 = new TH1F("h_DenT5", "", 1, 0,1);
  TH1F *h_DenT6 = new TH1F("h_DenT6", "", 1, 0,1);
  TH1F *h_DenT7 = new TH1F("h_DenT7", "", 1, 0,1);
  TH1F *h_DenT8 = new TH1F("h_DenT8", "", 1, 0,1);
  TH1F *h_DenT9 = new TH1F("h_DenT9", "", 1, 0,1);
  TH1F *h_DenT10 = new TH1F("h_DenT10", "", 1, 0,1);
  TH1F *h_DenT11 = new TH1F("h_DenT11", "", 1, 0,1);
  TH1F *h_DenT12 = new TH1F("h_DenT12", "", 1, 0,1);
  TH1F *h_DenT13 = new TH1F("h_DenT13", "", 1, 0,1);
  TH1F *h_DenT14 = new TH1F("h_DenT14", "", 1, 0,1);








  h_DenT1->SetBinContent(1,Int_Den1);
  h_DenT2->SetBinContent(1,Int_Den2);
  h_DenT3->SetBinContent(1,Int_Den3);
  h_DenT4->SetBinContent(1,Int_Den4);
  h_DenT5->SetBinContent(1,Int_Den5);
  h_DenT6->SetBinContent(1,Int_Den6);
  h_DenT7->SetBinContent(1,Int_Den7);
  h_DenT8->SetBinContent(1,Int_Den8);
  h_DenT9->SetBinContent(1,Int_Den9);
  h_DenT10->SetBinContent(1,Int_Den10);
  h_DenT11->SetBinContent(1,Int_Den11);
  h_DenT12->SetBinContent(1,Int_Den12);
  h_DenT13->SetBinContent(1,Int_Den13);
  h_DenT14->SetBinContent(1,Int_Den14);

  



  const TH1F& H_Num1 = *h_NumT1;
  const TH1F& H_Num2 = *h_NumT2;
  const TH1F& H_Num3 = *h_NumT3;
  const TH1F& H_Num4 = *h_NumT4;
  const TH1F& H_Num5 = *h_NumT5;
  const TH1F& H_Num6 = *h_NumT6;
  const TH1F& H_Num7 = *h_NumT7;
  const TH1F& H_Num8 = *h_NumT8;
  const TH1F& H_Num9 = *h_NumT9;
  const TH1F& H_Num10 = *h_NumT10;
  const TH1F& H_Num11 = *h_NumT11;
  const TH1F& H_Num12 = *h_NumT12;
  const TH1F& H_Num13 = *h_NumT13;
  const TH1F& H_Num14 = *h_NumT14;


  


  const TH1F& H_Den1 = *h_DenT1;
  const TH1F& H_Den2 = *h_DenT2;
  const TH1F& H_Den3 = *h_DenT3;
  const TH1F& H_Den4 = *h_DenT4;
  const TH1F& H_Den5 = *h_DenT5;
  const TH1F& H_Den6 = *h_DenT6;
  const TH1F& H_Den7 = *h_DenT7;
  const TH1F& H_Den8 = *h_DenT8;
  const TH1F& H_Den9 = *h_DenT9;
  const TH1F& H_Den10 = *h_DenT10;
  const TH1F& H_Den11 = *h_DenT11;
  const TH1F& H_Den12 = *h_DenT12;
  const TH1F& H_Den13 = *h_DenT13;
  const TH1F& H_Den14 = *h_DenT14;



  

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
      E3 = new TEfficiency(H_Num3,H_Den3);
    }
  if(TEfficiency::CheckConsistency(H_Num4,H_Den4))
    {
      E4 = new TEfficiency(H_Num4,H_Den4);
    }


  if(TEfficiency::CheckConsistency(H_Num5,H_Den5))
    {
      E5 = new TEfficiency(H_Num5,H_Den5);
    }
  
  if(TEfficiency::CheckConsistency(H_Num6,H_Den6))
    {
       E6 = new TEfficiency(H_Num6,H_Den6);
    }
  if(TEfficiency::CheckConsistency(H_Num7,H_Den7))
    {
      E7 = new TEfficiency(H_Num7,H_Den7);
    }
  
  if(TEfficiency::CheckConsistency(H_Num8,H_Den8))
    {
      E8 = new TEfficiency(H_Num8,H_Den8);
    }
  if(TEfficiency::CheckConsistency(H_Num9,H_Den9))
    {
      E9 = new TEfficiency(H_Num9,H_Den9);
    }
  if(TEfficiency::CheckConsistency(H_Num10,H_Den10))
    {
      E10 = new TEfficiency(H_Num10,H_Den10);
    }
  if(TEfficiency::CheckConsistency(H_Num11,H_Den11))
    {
      E11 = new TEfficiency(H_Num11,H_Den11);
    }
   if(TEfficiency::CheckConsistency(H_Num12,H_Den12))
    {
      E12 = new TEfficiency(H_Num12,H_Den12);
    }
  if(TEfficiency::CheckConsistency(H_Num13,H_Den13))
    {
      E13 = new TEfficiency(H_Num13,H_Den13);
    }

  if(TEfficiency::CheckConsistency(H_Num14,H_Den14))
    {
      E14 = new TEfficiency(H_Num14,H_Den14);
    }













 double Teff1=E->GetEfficiency(1);
 
 double	Teff2=E2->GetEfficiency(1);

 double	Teff3=E3->GetEfficiency(1);

 double	Teff4=E4->GetEfficiency(1);

 double	Teff5=E5->GetEfficiency(1);

 double	Teff6=E6->GetEfficiency(1);

 double Teff7=E7->GetEfficiency(1);
 
 double Teff8=E8->GetEfficiency(1);
 
 double Teff9=E9->GetEfficiency(1);
 
 double Teff10=E10->GetEfficiency(1);

 double Teff11=E11->GetEfficiency(1);

 double Teff12=E12->GetEfficiency(1);

 double Teff13=E13->GetEfficiency(1);

 double Teff14=E14->GetEfficiency(1);

 double eff1=Int_Num1/Int_Den1;
 double eff2=Int_Num2/Int_Den2;
 double eff3=Int_Num1/Int_Den3;
 double eff4=Int_Num2/Int_Den4;
 double eff5=Int_Num1/Int_Den5;
 double eff6=Int_Num2/Int_Den6;
 
 double eff7=Int_Num7/Int_Den7;
 double eff8=Int_Num8/Int_Den8;
 double eff9=Int_Num9/Int_Den9;
 double eff10=Int_Num10/Int_Den10;
 double eff11=Int_Num11/Int_Den11;
 double eff12=Int_Num12/Int_Den12;
 
 
 double eff13=Int_Num1/Int_Den13;
 double eff14=Int_Num2/Int_Den14;
 
 Efficiency.push_back(Teff1);
  Efficiency.push_back(Teff2);
  Efficiency.push_back(Teff3);
  Efficiency.push_back(Teff4);
  Efficiency.push_back(Teff5);
  Efficiency.push_back(Teff6);
  Efficiency.push_back(Teff7);
  Efficiency.push_back(Teff8);
  Efficiency.push_back(Teff9);
  Efficiency.push_back(Teff10);
  Efficiency.push_back(Teff11);
  Efficiency.push_back(Teff12);
  Efficiency.push_back(Teff13);
  Efficiency.push_back(Teff14);





  
  return Efficiency;
}


std::vector<double> JetEffVector(string Num,string Denom,string inputfile)
{
  using namespace std;
  //*** read root files, get variables to plot *********                                                                              
  vector <double> Efficiency;
  Efficiency.clear();
  cout<< " " <<inputfile<<endl;
  //input/output paths     
  TString inpath =  "/home/redwan/PlotTestScripts/RootFiles/ANFilesNewTauID";
  TString outpath = "/home/redwan/PlotTestScripts/PlotsDModeVsGenVars/FinalNewTauID";
  //TauEfficiency_MuonAllID_mA9_SemiFinal.root

  TFile* infile2= new TFile(inpath+"/"+inputfile);

  cout<<" "<<infile2<<endl;
  TString Dir1 ="JetFakeTauVVLoose";
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
  TString Dir12="JetFakeTauEleTight";
  TString Dir13 ="JetFakeTauEleVTight";
  TString Dir14 ="JetFakeTauEleVVTight";
  
    
  cout<<" Bloop "<<endl;
   
  TEfficiency *E = 0;
  TEfficiency *E2 =0;
  TEfficiency *E3 =0;
  TEfficiency *E4 =0;
  TEfficiency *E5 =0;
  TEfficiency *E6 =0;
  TEfficiency *E7 = 0;
  TEfficiency *E8 =0;
  TEfficiency *E9 =0;
  TEfficiency *E10 =0;
  TEfficiency *E11 =0;
  TEfficiency *E12 =0;
  TEfficiency *E13 = 0;
  TEfficiency *E14 =0;
  
  
  TH1F *Num1 =(TH1F*)infile2->Get(Dir1+"/"+Num)->Clone("Num1");
  TH1F *Num2 =(TH1F*)infile2->Get(Dir2+"/"+Num)->Clone("Num2");
  TH1F *Num3 =(TH1F*)infile2->Get(Dir3+"/"+Num)->Clone("Num3");
  TH1F *Num4 =(TH1F*)infile2->Get(Dir4+"/"+Num)->Clone("Num4");
  TH1F *Num5 =(TH1F*)infile2->Get(Dir5+"/"+Num)->Clone("Num5");
  TH1F *Num6 =(TH1F*)infile2->Get(Dir6+"/"+Num)->Clone("Num6");
  TH1F *Num7 =(TH1F*)infile2->Get(Dir7+"/"+Num)->Clone("Num7");
  TH1F *Num8 =(TH1F*)infile2->Get(Dir8+"/"+Num)->Clone("Num8");
  TH1F *Num9 =(TH1F*)infile2->Get(Dir9+"/"+Num)->Clone("Num9");
  TH1F *Num10 =(TH1F*)infile2->Get(Dir10+"/"+Num)->Clone("Num10");
  TH1F *Num11 =(TH1F*)infile2->Get(Dir11+"/"+Num)->Clone("Num11");
  TH1F *Num12 =(TH1F*)infile2->Get(Dir12+"/"+Num)->Clone("Num6");
  TH1F *Num13 =(TH1F*)infile2->Get(Dir13+"/"+Num)->Clone("Num5");
  TH1F *Num14 =(TH1F*)infile2->Get(Dir14+"/"+Num)->Clone("Num6");


  TH1F *Den1 =(TH1F*)infile2->Get(Dir1+"/"+Denom)->Clone("Den1");
  TH1F *Den2 =(TH1F*)infile2->Get(Dir2+"/"+Denom)->Clone("Den2");
  TH1F *Den3 =(TH1F*)infile2->Get(Dir3+"/"+Denom)->Clone("Den3");
  TH1F *Den4 =(TH1F*)infile2->Get(Dir4+"/"+Denom)->Clone("Den4");
  TH1F *Den5 =(TH1F*)infile2->Get(Dir5+"/"+Denom)->Clone("Den5");
  TH1F *Den6 =(TH1F*)infile2->Get(Dir6+"/"+Denom)->Clone("Den6");
  TH1F *Den7 =(TH1F*)infile2->Get(Dir7+"/"+Denom)->Clone("Den7");
  TH1F *Den8 =(TH1F*)infile2->Get(Dir8+"/"+Denom)->Clone("Den8");
  TH1F *Den9 =(TH1F*)infile2->Get(Dir9+"/"+Denom)->Clone("Den9");
  TH1F *Den10 =(TH1F*)infile2->Get(Dir10+"/"+Denom)->Clone("Den10");
  TH1F *Den11 =(TH1F*)infile2->Get(Dir11+"/"+Denom)->Clone("Den11");
  TH1F *Den12 =(TH1F*)infile2->Get(Dir12+"/"+Denom)->Clone("Den12");
  TH1F *Den13 =(TH1F*)infile2->Get(Dir13+"/"+Denom)->Clone("Den13");
  TH1F *Den14 =(TH1F*)infile2->Get(Dir14+"/"+Denom)->Clone("Den14");


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

  
  double Int_Num7=(double)(Num7->Integral());
  double Int_Den7=(double)(Den7->Integral());

  double Int_Num8=(double)(Num8->Integral());
  double Int_Den8=(double)(Den8->Integral());

  double Int_Num9=(double)(Num9->Integral());
  double Int_Den9=(double)(Den9->Integral());

  double Int_Num10=(double)(Num10->Integral());
  double Int_Den10=(double)(Den10->Integral());

  double Int_Num11=(double)(Num11->Integral());
  double Int_Den11=(double)(Den11->Integral());

  double Int_Num12=(double)(Num12->Integral());
  double Int_Den12=(double)(Den12->Integral());

  double Int_Num13=(double)(Num13->Integral());
  double Int_Den13=(double)(Den13->Integral());

  double Int_Num14=(double)(Num14->Integral());
  double Int_Den14=(double)(Den14->Integral());








  TH1F *h_NumT1 = new TH1F("h_NumT1", "", 1, 0,1);
  TH1F *h_NumT2 = new TH1F("h_NumT2", "", 1, 0,1);
  TH1F *h_NumT3 = new TH1F("h_NumT3", "", 1, 0,1);
  TH1F *h_NumT4 = new TH1F("h_NumT4", "", 1, 0,1);
  TH1F *h_NumT5 = new TH1F("h_NumT5", "", 1, 0,1);
  TH1F *h_NumT6 = new TH1F("h_NumT6", "", 1, 0,1);
  TH1F *h_NumT7 = new TH1F("h_NumT7", "", 1, 0,1);
  TH1F *h_NumT8 = new TH1F("h_NumT8", "", 1, 0,1);
  TH1F *h_NumT9 = new TH1F("h_NumT9", "", 1, 0,1);
  TH1F *h_NumT10 = new TH1F("h_NumT10", "", 1, 0,1);
  TH1F *h_NumT11 = new TH1F("h_NumT11", "", 1, 0,1);
  TH1F *h_NumT12 = new TH1F("h_NumT12", "", 1, 0,1);
  TH1F *h_NumT13 = new TH1F("h_NumT13", "", 1, 0,1);
  TH1F *h_NumT14 = new TH1F("h_NumT14", "", 1, 0,1);





  h_NumT1->SetBinContent(1,Int_Num1);
  h_NumT2->SetBinContent(1,Int_Num2);
  h_NumT3->SetBinContent(1,Int_Num3);
  h_NumT4->SetBinContent(1,Int_Num4);
  h_NumT5->SetBinContent(1,Int_Num5);
  h_NumT6->SetBinContent(1,Int_Num6);
  h_NumT7->SetBinContent(1,Int_Num7);
  h_NumT8->SetBinContent(1,Int_Num8);
  h_NumT9->SetBinContent(1,Int_Num9);
  h_NumT10->SetBinContent(1,Int_Num10);
  h_NumT11->SetBinContent(1,Int_Num11);
  h_NumT12->SetBinContent(1,Int_Num12);
  h_NumT13->SetBinContent(1,Int_Num13);
  h_NumT14->SetBinContent(1,Int_Num14);

  

  
  TH1F *h_DenT1 = new TH1F("h_DenT1", "", 1, 0,1);
  TH1F *h_DenT2 = new TH1F("h_DenT2", "", 1, 0,1);
  TH1F *h_DenT3 = new TH1F("h_DenT3", "", 1, 0,1);
  TH1F *h_DenT4 = new TH1F("h_DenT4", "", 1, 0,1);
  TH1F *h_DenT5 = new TH1F("h_DenT5", "", 1, 0,1);
  TH1F *h_DenT6 = new TH1F("h_DenT6", "", 1, 0,1);
  TH1F *h_DenT7 = new TH1F("h_DenT7", "", 1, 0,1);
  TH1F *h_DenT8 = new TH1F("h_DenT8", "", 1, 0,1);
  TH1F *h_DenT9 = new TH1F("h_DenT9", "", 1, 0,1);
  TH1F *h_DenT10 = new TH1F("h_DenT10", "", 1, 0,1);
  TH1F *h_DenT11 = new TH1F("h_DenT11", "", 1, 0,1);
  TH1F *h_DenT12 = new TH1F("h_DenT12", "", 1, 0,1);
  TH1F *h_DenT13 = new TH1F("h_DenT13", "", 1, 0,1);
  TH1F *h_DenT14 = new TH1F("h_DenT14", "", 1, 0,1);








  h_DenT1->SetBinContent(1,Int_Den1);
  h_DenT2->SetBinContent(1,Int_Den2);
  h_DenT3->SetBinContent(1,Int_Den3);
  h_DenT4->SetBinContent(1,Int_Den4);
  h_DenT5->SetBinContent(1,Int_Den5);
  h_DenT6->SetBinContent(1,Int_Den6);
  h_DenT7->SetBinContent(1,Int_Den7);
  h_DenT8->SetBinContent(1,Int_Den8);
  h_DenT9->SetBinContent(1,Int_Den9);
  h_DenT10->SetBinContent(1,Int_Den10);
  h_DenT11->SetBinContent(1,Int_Den11);
  h_DenT12->SetBinContent(1,Int_Den12);
  h_DenT13->SetBinContent(1,Int_Den13);
  h_DenT14->SetBinContent(1,Int_Den14);

  



  const TH1F& H_Num1 = *h_NumT1;
  const TH1F& H_Num2 = *h_NumT2;
  const TH1F& H_Num3 = *h_NumT3;
  const TH1F& H_Num4 = *h_NumT4;
  const TH1F& H_Num5 = *h_NumT5;
  const TH1F& H_Num6 = *h_NumT6;
  const TH1F& H_Num7 = *h_NumT7;
  const TH1F& H_Num8 = *h_NumT8;
  const TH1F& H_Num9 = *h_NumT9;
  const TH1F& H_Num10 = *h_NumT10;
  const TH1F& H_Num11 = *h_NumT11;
  const TH1F& H_Num12 = *h_NumT12;
  const TH1F& H_Num13 = *h_NumT13;
  const TH1F& H_Num14 = *h_NumT14;


  


  const TH1F& H_Den1 = *h_DenT1;
  const TH1F& H_Den2 = *h_DenT2;
  const TH1F& H_Den3 = *h_DenT3;
  const TH1F& H_Den4 = *h_DenT4;
  const TH1F& H_Den5 = *h_DenT5;
  const TH1F& H_Den6 = *h_DenT6;
  const TH1F& H_Den7 = *h_DenT7;
  const TH1F& H_Den8 = *h_DenT8;
  const TH1F& H_Den9 = *h_DenT9;
  const TH1F& H_Den10 = *h_DenT10;
  const TH1F& H_Den11 = *h_DenT11;
  const TH1F& H_Den12 = *h_DenT12;
  const TH1F& H_Den13 = *h_DenT13;
  const TH1F& H_Den14 = *h_DenT14;



  

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
      E3 = new TEfficiency(H_Num3,H_Den3);
    }
  if(TEfficiency::CheckConsistency(H_Num4,H_Den4))
    {
      E4 = new TEfficiency(H_Num4,H_Den4);
    }


  if(TEfficiency::CheckConsistency(H_Num5,H_Den5))
    {
      E5 = new TEfficiency(H_Num5,H_Den5);
    }
  
  if(TEfficiency::CheckConsistency(H_Num6,H_Den6))
    {
       E6 = new TEfficiency(H_Num6,H_Den6);
    }
  if(TEfficiency::CheckConsistency(H_Num7,H_Den7))
    {
      E7 = new TEfficiency(H_Num7,H_Den7);
    }
  
  if(TEfficiency::CheckConsistency(H_Num8,H_Den8))
    {
      E8 = new TEfficiency(H_Num8,H_Den8);
    }
  if(TEfficiency::CheckConsistency(H_Num9,H_Den9))
    {
      E9 = new TEfficiency(H_Num9,H_Den9);
    }
  if(TEfficiency::CheckConsistency(H_Num10,H_Den10))
    {
      E10 = new TEfficiency(H_Num10,H_Den10);
    }
  if(TEfficiency::CheckConsistency(H_Num11,H_Den11))
    {
      E11 = new TEfficiency(H_Num11,H_Den11);
    }
   if(TEfficiency::CheckConsistency(H_Num12,H_Den12))
    {
      E12 = new TEfficiency(H_Num12,H_Den12);
    }
  if(TEfficiency::CheckConsistency(H_Num13,H_Den13))
    {
      E13 = new TEfficiency(H_Num13,H_Den13);
    }

  if(TEfficiency::CheckConsistency(H_Num14,H_Den14))
    {
      E14 = new TEfficiency(H_Num14,H_Den14);
    }

 double Teff1=E->GetEfficiency(1);
 
 double	Teff2=E2->GetEfficiency(1);

 double	Teff3=E3->GetEfficiency(1);

 double	Teff4=E4->GetEfficiency(1);

 double	Teff5=E5->GetEfficiency(1);

 double	Teff6=E6->GetEfficiency(1);

 double Teff7=E7->GetEfficiency(1);
 
 double Teff8=E8->GetEfficiency(1);
 
 double Teff9=E9->GetEfficiency(1);
 
 double Teff10=E10->GetEfficiency(1);

 double Teff11=E11->GetEfficiency(1);

 double Teff12=E12->GetEfficiency(1);

 double Teff13=E13->GetEfficiency(1);

 double Teff14=E14->GetEfficiency(1);
 double eff1=Int_Num1/Int_Den1;
 double eff2=Int_Num2/Int_Den2;
 double eff3=Int_Num1/Int_Den3;
 double eff4=Int_Num2/Int_Den4;
 double eff5=Int_Num1/Int_Den5;
 double eff6=Int_Num2/Int_Den6;
 
 double eff7=Int_Num7/Int_Den7;
 double eff8=Int_Num8/Int_Den8;
 double eff9=Int_Num9/Int_Den9;
 double eff10=Int_Num10/Int_Den10;
 double eff11=Int_Num11/Int_Den11;
 double eff12=Int_Num12/Int_Den12;
 
 
 double eff13=Int_Num1/Int_Den13;
 double eff14=Int_Num2/Int_Den14;
 
 Efficiency.push_back(Teff1);
 Efficiency.push_back(Teff2);
 Efficiency.push_back(Teff3);
 Efficiency.push_back(Teff4);
 Efficiency.push_back(Teff5);
 Efficiency.push_back(Teff6);
 Efficiency.push_back(Teff7);
 Efficiency.push_back(Teff8);
 Efficiency.push_back(Teff9);
 Efficiency.push_back(Teff10);
 Efficiency.push_back(Teff11);
 Efficiency.push_back(Teff12);
 Efficiency.push_back(Teff13);
 Efficiency.push_back(Teff14);
  



  
  return Efficiency;
}
//Getting the Efficiency from several MVA discriminants for UnCleaned and ElectronCleaned case.
void FakeRateVsTEffE(){
  using namespace std;

  string File1="TauEfficiency_ma20_NewTauID.root";
  string File2="JetFakeTau_NewTauID.root";
  vector<double> VVLoose;
  vector<double> VLoose;
  vector<double> JetVVLoose;
  vector<double> JetVLoose;
  std::vector<double> Placeholder;
  //cout<< " " << i <<endl; 
  Placeholder.clear();
  //mAPts.push_back((double)mA(i));
  Placeholder=EffVector("NumTotalVis","DenomTotalVis",File1);
  
  VVLoose.push_back(Placeholder[0]);
  VVLoose.push_back(Placeholder[1]);
  
  VVLoose.push_back(Placeholder[2]);
  VVLoose.push_back(Placeholder[3]);
  
  VVLoose.push_back(Placeholder[4]);
  VVLoose.push_back(Placeholder[5]);
  
  VVLoose.push_back(Placeholder[6]);


  VLoose.push_back(Placeholder[7]);
  
  VLoose.push_back(Placeholder[8]);
  VLoose.push_back(Placeholder[9]);
  
  VLoose.push_back(Placeholder[10]);
  VLoose.push_back(Placeholder[11]);
  
  VLoose.push_back(Placeholder[12]);
  VLoose.push_back(Placeholder[13]);
  
  
  
  
  std::vector<double> JetPlaceholder;
  //cout<< " " << i <<endl;
  JetPlaceholder.clear();
  //mAPts.push_back((double)mA(i));                                                                                                                                                                                                                                        
  JetPlaceholder=JetEffVector("NumIn","DenomIn",File2);
  
  
  JetVVLoose.push_back(JetPlaceholder[0]);
  JetVVLoose.push_back(JetPlaceholder[1]);
  
  JetVVLoose.push_back(JetPlaceholder[2]);
  JetVVLoose.push_back(JetPlaceholder[3]);
  
  JetVVLoose.push_back(JetPlaceholder[4]);
  JetVVLoose.push_back(JetPlaceholder[5]);
  
  JetVVLoose.push_back(JetPlaceholder[6]);


  JetVLoose.push_back(JetPlaceholder[7]);
  
  JetVLoose.push_back(JetPlaceholder[8]);
  JetVLoose.push_back(JetPlaceholder[9]);
  
  JetVLoose.push_back(JetPlaceholder[10]);
  JetVLoose.push_back(JetPlaceholder[11]);
  
  JetVLoose.push_back(JetPlaceholder[12]);
  JetVLoose.push_back(JetPlaceholder[13]);
  
   // *********set up canvas/pad *********                                                                                                                                                                                                                                  
  //Bool_t dolog = kFALSE;                                                                                                            
  Bool_t dolog = kTRUE;                                                                                                             
  TString outpath = "/home/redwan/PlotTestScripts/JetFakeTauNewTauId";
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
  TPad *pad  = new TPad("pad1", "pad1", 0.05, 0.05, 1.0, 1.0);
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


  TLegend *leg = new TLegend(0.10,0.65,0.50,0.95);

 
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.025);

  // canvas->cd();
  TGraph VVLooseG(VVLoose.size(),&VVLoose[0],&JetVVLoose[0]);
  TGraph VLooseG(VLoose.size(),&VLoose[0],&JetVLoose[0]);
 


  //VVLooseG.SetPoint(0,VLoose[0],JetVLoose[0]);
  VVLooseG.Draw("A*");
  VVLooseG.SetLineColor(kRed);
  //VVLooseG.SetMinimum(0.0);
  //VVLooseG.SetMaximum(1.0);
  VVLooseG.SetMarkerColor(kRed);
  //VVLooseG.SetMarkerStyle(2);
  VVLooseG.SetTitle("Jet-> Tau Fake rate Vs #tau_{had}  Efficiency");
  //VVLooseG.GetXaxis()->SetRange(0,1);
  VVLooseG.GetXaxis()->SetTitle("#tau_{had} Efficiency");
  VVLooseG.GetYaxis()->SetTitle("Jet-> Tau Fake Rate");
  VVLooseG.GetYaxis()->SetLabelSize(.02);
  gPad->Update();
  
  
  
  VLooseG.Draw("same*");
  //VLooseG.SetTitle("Muon Cleaned #tau_{h}");
  VLooseG.SetMarkerColor(kBlue);
  VLooseG.SetLineColor(kBlue);
  gPad->Update();
  leg->AddEntry(&VVLooseG,"UnCleaned #tau_{h}  New Tau ID Working points ", "l");    
  leg->AddEntry(&VLooseG,"ElectronCleaned #tau_{h} New Tau ID Working points ", "l");
  
  


  
  leg->Draw();
  title->DrawTextNDC(0.13,0.91,"CMS");
  extra->DrawTextNDC(0.23,0.91,"Simulation");
  lumi.DrawLatexNDC(0.9,0.91,"2017 Style MC");                                                                                       
  gPad->Update();                                                                                                                  
  gPad->RedrawAxis();
  canvas->SaveAs(outpath+"/"+"JetFakeRateVSTauEffEle_NewTauID_mA20.png");
  






}
    
    
