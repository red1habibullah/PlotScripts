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

  double eff1=Int_Num1/Int_Den1;
  double eff2=Int_Num2/Int_Den2;
  double eff3=Int_Num1/Int_Den3;
  double eff4=Int_Num2/Int_Den4;
  double eff5=Int_Num1/Int_Den5;
  double eff6=Int_Num2/Int_Den6;

  cout<< "Eff1 :"<< eff1 <<endl;
  cout<< "Eff2 :"<< eff2 <<endl;
  cout<< "Eff3 :"<< eff3 <<endl;
  cout<< "Eff4 :"<< eff4 <<endl;
  cout<< "Eff5 :"<< eff5 <<endl;
  cout<< "Eff6 :"<< eff6 <<endl;

  Efficiency.push_back(eff1);
  Efficiency.push_back(eff2);
  Efficiency.push_back(eff3);
  Efficiency.push_back(eff4);
  Efficiency.push_back(eff5);
  Efficiency.push_back(eff6);

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

void TestMultipleFileMultiplemACombMuEff(){
  using namespace std;
  std::vector<string> Files={"TauEfficiency_MuonAllID_mA4_SemiFinal.root","TauEfficiency_MuonAllID_mA5_SemiFinal.root","TauEfficiency_MuonAllID_mA7_SemiFinal.root","TauEfficiency_MuonAllID_mA9_SemiFinal.root","TauEfficiency_MuonAllID_mA12_SemiFinal.root","TauEfficiency_MuonAllID_mA13_SemiFinal.root","TauEfficiency_MuonAllID_mA16_SemiFinal.root","TauEfficiency_MuonAllID_mA19_SemiFinal.root","TauEfficiency_MuonAllID_mA20_SemiFinal.root"};
  vector<double> StdLoose;
  vector<double> ClnLoose;
  vector<double> StdMedium;
  vector<double> ClnMedium;
  vector<double> StdTight;
  vector<double> ClnTight;
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
  TGraph StdLs(mAPts.size()-1,&mAPts[0],&StdLoose[0]);
  TGraph ClnLs(mAPts.size()-1,&mAPts[0],&ClnLoose[0]);
  TGraph StdMd(mAPts.size()-1,&mAPts[0],&StdMedium[0]);
  TGraph ClnMd(mAPts.size()-1,&mAPts[0],&ClnMedium[0]);
  TGraph StdTt(mAPts.size()-1,&mAPts[0],&StdTight[0]);
  TGraph ClnTt(mAPts.size()-1,&mAPts[0],&ClnTight[0]);




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
  canvas->SaveAs(outpath+"/"+"MuonEfficiencyCombination.png");
  






}
    
    
