/*���ѥ��ȫe20�jDJI����*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

ifstream input_file;
ifstream test_input_file;
ofstream output_file;
double all_stock[10000][10000]; //�Ҧ��Ѳ�
double test_all_stock[100][400];
string stock_no[50]; //�Ѳ��s��
string test_stock_no[50];
int index;
int test_index;
//read_file

double beta[50];
double partical[10][90000];
//int profolio[50];//���զX
//initial

int stock_index[10][50];//�O���C���ɤl(10)�ҿ�쪺���զX(50)
						//choose

int train_stock_index[50];
double initial_fund = 10000000; //��l���
double test_initial_fund;
double remaind;//�Ѿl���
double test_remaind;
double all_remain_fund;
double test_all_remain_fund;
double fund_standardization; //�������
double fee; //����O
double test_fee;
double total_fee[50000];
double one_fund_standardization[50][2500];
double n_fund_standardization[100][50][2500];//�U�ɸ������
double test_n_fund_standardization[50][300];//���մ��������
double partical_fund_standardization[100][2500];//���զX�������
double risk[10000]; //�C�魷�I
double test_risk;//�V�m���C�魷�I
double final_test_risk;
double m[10000]; //�w�����S
double test_m;
int share_money;//�C�ɤ��t����
int test_share_money;
double one_of_price; //�C�i����
double test_one_of_price;
double daily_risk[50][10000][10];//�C������C�N�C�魷�I
double expect_m[50][10000][10];//�C������C�N�w�����S
double Gbest_daily_risk;//�̨θѨC�魷�I
double Gbest_expect_retutn;//�̨θѹw�����S

int buy_lots;//�i�R���i��
int test_buy_lots;
double yi[10000][10000];//��i�ѯu��������
double test_yi[1000];
double all_final_yi[10000];//�C�@�Ӳɤl�̫�@�Ѫ�yi
						   //standardization

double m1;
int m2;
double all_standardization[2500];
double Yi[100][300];//�@���^�k�Ͷսu
double test_Yi[300];
double r1;
double trend_ratio;//�Ͷխ�
double test_trend_ratio;
double final_test_trend_ratio;
double all_trend_ratio[10];
//fitness

double theta = 0.0004;
double min_fitness = 0;
double max_fitness = 0;
double max_fitness_aray[100];
int min_fitness_tmp = 0;
int max_fitness_tmp = 0;
int Gbest_tmp = 0;
int t;
//update


int i, j, k, a;
int kind[50];
//double n;
int n[50];//��諸���զX���X��
int partical_num = 10;
int generation = 10000;
int experiment_time = 50;
int s_stock_index = 0;//train stock num
int test_stock_index = 0;

int total_n;
int day = 0;
int test_day;
//compare

double all_max = 0;
int all_max_solution[10000];
double random;
int file_num = 28;
double Gbest[50];
double all_max_tmp[50];
double Gbest_max;
int best_experimrentime;
int best_generation;
double real_all_trend_ratio[50][10000][10];
double real_yi[50][10000][10];
double Gbest_yi;
int Gbest_num;//Gbest���X�{����
int final_n[50][10000][10];//�s�̨θ��ɼ�
int Gbest_n;//Gbest��쪺�ɼ�
int Gbest_i;
int selection_stock_no[10][50];
int real_partical[50][10][50];
string final_portfolio[50];
int all_buy_lots[50];//�s�i�R�i�ƪ��}�C
int last_test_all_buy_paper[50];
int test_all_buy_lots[50];
int all_share_money[10];//�s���t������}�C
int test_all_share_money[10];
int compare_share_money[50][10000][10];//�s�C������C�ӥ@�N�C�Ӳɤl�����t����}�C
int compare_buy_lots[50][10][50];//�s�C�ӹ��礤���զX�Ѳ��i�R�i��
int Gbest_share_money;
int Gbest_buy_lots[50];//Gbest�զX���Ѳ��i�R���i��
double real_all_remain_fund[50];
double test_real_all_remain_fund[50];
double compare_remain_fund[50][50];
double Gbest_all_remain_fund[50];//Gbest���R���U�ѳѾl���
double all_n_fund_standardization[50][50][300];
double Gbest_n_fund_standardization[50][300];
double all_total_yi[300];
double test_all_total_yi[300];
double test_all_final_fund;
double final_fund[10];
double compare_total_yi[50][300];
double real_total_yi[300];
int total_test_day;
double test_total_yi[100][10000];
double final_total_test_yi[10000];
double test_total_all_period_m;//���մ��`��w�����S
double test_all_period_Yi[10000];
double test_all_period_risk;
double test_all_period_trend_ratio;
double test_all_period_m1;
int test_all_period_m2;
double last_total_std[10000];//�s�Ҧ����մ��`�������
double last_total_Yi[10000];//�p���`����մ��w���������
double real_last_total_std[100][10000];//�s�Ҧ����մ��`�������
int day_count;
double all_test_m;
double final_all_test_m;//�`����մ��̲׹w�����S
double final_test_m1;
double final_test_m2;
double final_test_r1;
int day_count_risk;//�`����մ��p�⭷�I�Ѽ�counter
int day_count_result;//�`����մ���X���G�Ѽ�counter

double all_file_gbest_risk[100];
double all_file_gbest_return[100];
int all_file_gbest_num[100];
int all_file_gbest_generation[100];
int all_file_gbest_experiment[100];
int all_file_gbest_appear[100];
double all_gbest_trend_ratio[100];
string all_file_gbest_portfolio[100][50];

string AAPL[] = { "AAPL-2012.csv", "AAPL-2013.csv", "AAPL-2014.csv", "AAPL-2015.csv", "AAPL-2016.csv", "AAPL-2017.csv", "AAPL-2018.csv", "AAPL-2019.csv" };
string AMZN[] = { "AMZN-2012.csv", "AMZN-2013.csv", "AMZN-2014.csv", "AMZN-2015.csv", "AMZN-2016.csv", "AMZN-2017.csv", "AMZN-2018.csv", "AMZN-2019.csv" };
string BABA[] = { "BABA-2014.csv", "BABA-2015.csv", "BABA-2016.csv", "BABA-2017.csv", "BABA-2018.csv", "BABA-2019.csv" };
string BRKA[] = { "BRK-A-2012.csv", "BRK-A-2013.csv", "BRK-A-2014.csv", "BRK-A-2015.csv", "BRK-A-2016.csv", "BRK-A-2017.csv", "BRK-A-2018.csv", "BRK-A-2019.csv" };
string FB[] = { "FB-2013.csv", "FB-2014.csv", "FB-2015.csv", "FB-2016.csv", "FB-2017.csv", "FB-2018.csv", "FB-2019.csv" };
string GOOG[] = { "GOOG-2012.csv", "GOOG-2013.csv", "GOOG-2014.csv", "GOOG-2015.csv", "GOOG-2016.csv", "GOOG-2017.csv", "GOOG-2018.csv", "GOOG-2019.csv" };
string GOOGL[] = { "GOOGL-2012.csv", "GOOGL-2013.csv", "GOOGL-2014.csv", "GOOGL-2015.csv", "GOOGL-2016.csv", "GOOGL-2017.csv", "GOOGL-2018.csv", "GOOGL-2019.csv" };
string JNJ[] = { "JNJ-2012.csv", "JNJ-2013.csv", "JNJ-2014.csv", "JNJ-2015.csv", "JNJ-2016.csv", "JNJ-2017.csv", "JNJ-2018.csv", "JNJ-2019.csv" };
string JPM[] = { "JPM-2012.csv", "JPM-2013.csv", "JPM-2014.csv", "JPM-2015.csv", "JPM-2016.csv", "JPM-2017.csv", "JPM-2018.csv", "JPM-2019.csv" };
string MSFT[] = { "MSFT-2012.csv", "MSFT-2013.csv", "MSFT-2014.csv", "MSFT-2015.csv", "MSFT-2016.csv", "MSFT-2017.csv", "MSFT-2018.csv", "MSFT-2019.csv" };
string TCEHY[] = { "TCEHY_2012.csv", "TCEHY_2013.csv", "TCEHY_2014.csv", "TCEHY_2015.csv", "TCEHY_2016.csv", "TCEHY_2017.csv", "TCEHY_2018.csv", "TCEHY_2019.csv" };
string V[] = { "V-2012.csv", "V-2013.csv", "V-2014.csv", "V-2015.csv", "V-2016.csv", "V-2017.csv", "V-2018.csv", "V-2019.csv" };
string XOM[] = { "XOM-2012.csv", "XOM-2013.csv", "XOM-2014.csv", "XOM-2015.csv", "XOM-2016.csv", "XOM-2017.csv", "XOM-2018.csv", "XOM-2019.csv" };
string all_US_10[] = { "2012.csv", "2013.csv", "2014.csv", "2015.csv", "2016.csv", "2017.csv", "2018.csv", "2019.csv" };
string all_US_12[] = { "2012.csv", "2013.csv", "2014.csv", "2015.csv", "2016.csv", "2017.csv", "2018.csv", "2019.csv" };
/*���ѥ��ȫe12�j*/
string BRKB[] = { "BRK.B_2012.csv", "BRK.B_2013.csv", "BRK.B_2014.csv", "BRK.B_2015.csv", "BRK.B_2016.csv", "BRK.B_2017.csv", "BRK.B_2018.csv", "BRK.B_2019.csv" };
string CHT[] = { "CHT_2012.csv", "CHT_2013.csv", "CHT_2014.csv", "CHT_2015.csv", "CHT_2016.csv", "CHT_2017.csv", "CHT_2018.csv", "CHT_2019.csv" };
string HD[] = { "HD_2012.csv", "HD_2013.csv", "HD_2014.csv", "HD_2015.csv","HD_2016.csv","HD_2017.csv","HD_2018.csv","HD_2019.csv" };
string MA[] = { "MA_2012.csv","MA_2013.csv","MA_2014.csv","MA_2015.csv","MA_2016.csv","MA_2017.csv","MA_2018.csv","MA_2019.csv" };
string PG[] = { "PG_2012.csv", "PG_2013.csv","PG_2014.csv","PG_2015.csv","PG_2016.csv","PG_2017.csv","PG_2018.csv","PG_2019.csv" };
string SNP[] = { "SNP_2012.csv", "SNP_2013.csv", "SNP_2014.csv", "SNP_2015.csv", "SNP_2016.csv", "SNP_2017.csv", "SNP_2018.csv", "SNP_2019.csv" };
string T[] = { "T_2012.csv", "T_2013.csv", "T_2014.csv", "T_2015.csv", "T_2016.csv", "T_2017.csv", "T_2018.csv", "T_2019.csv" };
string TSM[] = { "TSM_2012.csv", "TSM_2013.csv", "TSM_2014.csv", "TSM_2015.csv", "TSM_2016.csv", "TSM_2017.csv", "TSM_2018.csv", "TSM_2019.csv" };
string UNH[] = { "UNH_2012.csv", "UNH_2013.csv", "UNH_2014.csv", "UNH_2015.csv", "UNH_2016.csv", "UNH_2017.csv", "UNH_2018.csv", "UNH_2019.csv" };
string VOD[] = { "VOD_2012.csv", "VOD_2013.csv", "VOD_2014.csv",  "VOD_2015.csv", "VOD_2016.csv", "VOD_2017.csv", "VOD_2018.csv", "VOD_2019.csv" };
string WMT[] = { "WMT_2012.csv", "WMT_2013.csv", "WMT_2014.csv", "WMT_2015.csv", "WMT_2016.csv", "WMT_2017.csv", "WMT_2018.csv", "WMT_2019.csv" };
/*���ѥ��ȫe20�j*/

string BAC[] = { "BAC_2012.csv",  "BAC_2013.csv", "BAC_2014.csv", "BAC_2015.csv", "BAC_2016.csv", "BAC_2017.csv", "BAC_2018.csv", "BAC_2019.csv" };
string CSCO[] = { "CSCO_2012.csv", "CSCO_2013.csv", "CSCO_2014.csv", "CSCO_2015.csv", "CSCO_2016.csv", "CSCO_2017.csv", "CSCO_2018.csv", "CSCO_2019.csv" };
string INTC[] = { "INTC_2012.csv", "INTC_2013.csv", "INTC_2014.csv", "INTC_2015.csv", "INTC_2016.csv", "INTC_2017.csv", "INTC_2018.csv", "INTC_2019.csv" };
string VZ[] = { "VZ_2012.csv", "VZ_2013.csv", "VZ_2014.csv", "VZ_2015.csv", "VZ_2016.csv", "VZ_2017.csv", "VZ_2018.csv", "VZ_2019.csv" };
string B_all_US_20[] = { "B_20_2012.csv", "B_20_2013.csv", "B_20_2014.csv", "B_20_2015.csv", "B_20_2016.csv", "B_20_2017.csv", "B_20_2018.csv", "B_20_2019.csv" };
string LG_all_US_20[] = { "LG_20_2012.csv", "LG_20_2013.csv", "LG_20_2014.csv", "LG_20_2015.csv", "LG_20_2016.csv", "LG_20_2017.csv", "LG_20_2018.csv", "LG_20_2019.csv" };
/*�T�{�L�᪺���ѥ��ȫe20�j*/

string Y2Y_train20[] = { "train_2012(2012 Q1).csv", "train_2013(2013 Q1).csv", "train_2014(2014 Q1).csv", "train_2015(2015 Q1).csv", "train_2016(2016 Q1).csv", "train_2017(2017 Q1).csv", "train_2018(2018 Q1).csv" };
string Y2Q_train20[] = { "train_2012(2012 Q1).csv", "train_2012_Q2~2013_Q1(2012 Q1).csv", "train_2012_Q3~2013_Q2(2012 Q1).csv", "train_2012_Q4~2013_Q3(2012 Q1).csv", "train_2013(2013 Q1).csv", "train_2013_Q2~2014_Q1(2013 Q1).csv",
"train_2013_Q3~2014_Q2(2013 Q1).csv", "train_2013_Q4~2014_Q3(2013 Q1).csv", "train_2014(2014 Q1).csv", "train_2014_Q2~2015_Q1(2014 Q1).csv", "train_2014_Q3~2015_Q2(2014 Q1).csv", "train_2014_Q4~2015_Q3(2014 Q1).csv", "train_2015(2015 Q1).csv",
"train_2015_Q2~2016_Q1(2015 Q1).csv", "train_2015_Q3~2016_Q2(2015 Q1).csv", "train_2015_Q4~2016_Q3(2015 Q1).csv", "train_2016(2016 Q1).csv", "train_2016_Q2~2017_Q1(2016 Q1).csv", "train_2016_Q3~2017_Q2(2016 Q1).csv", "train_2016_Q4~2017_Q3(2016 Q1).csv",
"train_2017(2017 Q1).csv", "train_2017_Q2~2018_Q1(2017 Q1).csv", "train_2017_Q3~2018_Q2(2017 Q1).csv", "train_2017_Q4~2018_Q3(2017 Q1).csv", "train_2018(2018 Q1).csv", "train_2018_Q2~2019_Q1(2018 Q1).csv", "train_2018_Q3~2019_Q2(2018 Q1).csv", "train_2018_Q4~2019_Q3(2018 Q1).csv" };
string Y2M_train20[] = { "train_2012(2012 Q1).csv", "train_2012_02~2013_01(2012 Q1).csv", "train_2012_03~2013_02(2012 Q1).csv", "train_2012_04~2013_03(2012 Q1).csv", "train_2012_05~2013_04(2012 Q1).csv", "train_2012_06~2013_05(2012 Q1).csv", "train_2012_07~2013_06(2012 Q1).csv", "train_2012_08~2013_07(2012 Q1).csv", "train_2012_09~2013_08(2012 Q1).csv", "train_2012_10~2013_09(2012 Q1).csv", "train_2012_11~2013_10(2012 Q1).csv", "train_2012_12~2013_11(2012 Q1).csv",
"train_2013(2013 Q1).csv", "train_2013_02~2014_01(2013 Q1).csv", "train_2013_03~2014_02(2013 Q1).csv", "train_2013_04~2014_03(2013 Q1).csv", "train_2013_05~2014_04(2013 Q1).csv", "train_2013_06~2014_05(2013 Q1).csv", "train_2013_07~2014_06(2013 Q1).csv", "train_2013_08~2014_07(2013 Q1).csv", "train_2013_09~2014_08(2013 Q1).csv", "train_2013_10~2014_09(2013 Q1).csv", "train_2013_11~2014_10(2013 Q1).csv", "train_2013_12~2014_11(2013 Q1).csv",
"train_2014(2014 Q1).csv", "train_2014_02~2015_01(2014 Q1).csv", "train_2014_03~2015_02(2014 Q1).csv", "train_2014_04~2015_03(2014 Q1).csv", "train_2014_05~2015_04(2014 Q1).csv", "train_2014_06~2015_05(2014 Q1).csv", "train_2014_07~2015_06(2014 Q1).csv", "train_2014_08~2015_07(2014 Q1).csv", "train_2014_09~2015_08(2014 Q1).csv", "train_2014_10~2015_09(2014 Q1).csv", "train_2014_11~2015_10(2014 Q1).csv", "train_2014_12~2015_11(2014 Q1).csv",
"train_2015(2015 Q1).csv", "train_2015_02~2016_01(2015 Q1).csv", "train_2015_03~2016_02(2015 Q1).csv", "train_2015_04~2016_03(2015 Q1).csv", "train_2015_05~2016_04(2015 Q1).csv", "train_2015_06~2016_05(2015 Q1).csv", "train_2015_07~2016_06(2015 Q1).csv", "train_2015_08~2016_07(2015 Q1).csv", "train_2015_09~2016_08(2015 Q1).csv", "train_2015_10~2016_09(2015 Q1).csv", "train_2015_11~2016_10(2015 Q1).csv", "train_2015_12~2016_11(2015 Q1).csv",
"train_2016(2016 Q1).csv", "train_2016_02~2017_01(2016 Q1).csv", "train_2016_03~2017_02(2016 Q1).csv", "train_2016_04~2017_03(2016 Q1).csv", "train_2016_05~2017_04(2016 Q1).csv", "train_2016_06~2017_05(2016 Q1).csv", "train_2016_07~2017_06(2016 Q1).csv", "train_2016_08~2017_07(2016 Q1).csv", "train_2016_09~2017_08(2016 Q1).csv", "train_2016_10~2017_09(2016 Q1).csv", "train_2016_11~2017_10(2016 Q1).csv", "train_2016_12~2017_11(2016 Q1).csv",
"train_2017(2017 Q1).csv", "train_2017_02~2018_01(2017 Q1).csv", "train_2017_03~2018_02(2017 Q1).csv", "train_2017_04~2018_03(2017 Q1).csv", "train_2017_05~2018_04(2017 Q1).csv", "train_2017_06~2018_05(2017 Q1).csv", "train_2017_07~2018_06(2017 Q1).csv", "train_2017_08~2018_07(2017 Q1).csv", "train_2017_09~2018_08(2017 Q1).csv", "train_2017_10~2018_09(2017 Q1).csv", "train_2017_11~2018_10(2017 Q1).csv", "train_2017_12~2018_11(2017 Q1).csv",
"train_2018(2018 Q1).csv", "train_2018_02~2019_01(2018 Q1).csv", "train_2018_03~2019_02(2018 Q1).csv", "train_2018_04~2019_03(2018 Q1).csv", "train_2018_05~2019_04(2018 Q1).csv", "train_2018_06~2019_05(2018 Q1).csv", "train_2018_07~2019_06(2018 Q1).csv", "train_2018_08~2019_07(2018 Q1).csv", "train_2018_09~2019_08(2018 Q1).csv", "train_2018_10~2019_09(2018 Q1).csv", "train_2018_11~2019_10(2018 Q1).csv", "train_2018_12~2019_11(2018 Q1).csv" };
string Y2H_train20[] = { "train_2012(2012 Q1).csv", "train_2012_Q3~2013_Q2(2012 Q1).csv", "train_2013(2013 Q1).csv", "train_2013_Q3~2014_Q2(2013 Q1).csv", "train_2014(2014 Q1).csv", "train_2014_Q3~2015_Q2(2014 Q1).csv", "train_2015(2015 Q1).csv", "train_2015_Q3~2016_Q2(2015 Q1).csv",
"train_2016(2016 Q1).csv", "train_2016_Q3~2017_Q2(2016 Q1).csv", "train_2017(2017 Q1).csv", "train_2017_Q3~2018_Q2(2017 Q1).csv", "train_2018(2018 Q1).csv", "train_2018_Q3~2019_Q2(2018 Q1).csv" };
string Q2Q_train20[] = { "train_2012_Q4(2012 Q1).csv", "train_2013_Q1(2013 Q1).csv", "train_2013_Q2(2013 Q1).csv", "train_2013_Q3(2013 Q1).csv", "train_2013_Q4(2013 Q1).csv", "train_2014_Q1(2014 Q1).csv", "train_2014_Q2(2014 Q1).csv", "train_2014_Q3(2014 Q1).csv", "train_2014_Q4(2014 Q1).csv", "train_2015_Q1(2015 Q1).csv", "train_2015_Q2(2015 Q1).csv", "train_2015_Q3(2015 Q1).csv", "train_2015_Q4(2015 Q1).csv", "train_2016_Q1(2016 Q1).csv", "train_2016_Q2(2016 Q1).csv",
"train_2016_Q3(2016 Q1).csv", "train_2016_Q4(2016 Q1).csv", "train_2017_Q1(2017 Q1).csv", "train_2017_Q2(2017 Q1).csv", "train_2017_Q3(2017 Q1).csv", "train_2017_Q4(2017 Q1).csv", "train_2018_Q1(2018 Q1).csv", "train_2018_Q2(2018 Q1).csv", "train_2018_Q3(2018 Q1).csv", "train_2018_Q4(2018 Q1).csv", "train_2019_Q1(2019 Q1).csv", "train_2019_Q2(2019 Q1).csv", "train_2019_Q3(2019 Q1).csv" };
string Q2M_train20[] = { "train_2012_10-12(2012 Q1).csv", "train_2012_11~2013_01(2012 Q1).csv", "train_2012_12~2013_02(2012 Q1).csv", "train_2013_01-03(2013 Q1).csv", "train_2013_02-04(2013 Q1).csv", "train_2013_03-05(2013 Q1).csv",
"train_2013_04-06(2013 Q1).csv", "train_2013_05-07(2013 Q1).csv", "train_2013_06-08(2013 Q1).csv", "train_2013_07-09(2013 Q1).csv", "train_2013_08-10(2013 Q1).csv", "train_2013_09-11(2013 Q1).csv", "train_2013_10-12(2013 Q1).csv", "train_2013_11~2014_01(2013 Q1).csv", "train_2013_12~2014_02(2013 Q1).csv", "train_2014_01-03(2014 Q1).csv", "train_2014_02-04(2014 Q1).csv", "train_2014_03-05(2014 Q1).csv", "train_2014_04-06(2014 Q1).csv", "train_2014_05-07(2014 Q1).csv",
"train_2014_06-08(2014 Q1).csv", "train_2014_07-09(2014 Q1).csv", "train_2014_08-10(2014 Q1).csv", "train_2014_09-11(2014 Q1).csv", "train_2014_10-12(2014 Q1).csv", "train_2014_11~2015_01(2014 Q1).csv", "train_2014_12~2015_02(2014 Q1).csv", "train_2015_01-03(2015 Q1).csv", "train_2015_02-04(2015 Q1).csv", "train_2015_03-05(2015 Q1).csv", "train_2015_04-06(2015 Q1).csv", "train_2015_05-07(2015 Q1).csv", "train_2015_06-08(2015 Q1).csv", "train_2015_07-09(2015 Q1).csv",
"train_2015_08-10(2015 Q1).csv", "train_2015_09-11(2015 Q1).csv", "train_2015_10-12(2015 Q1).csv", "train_2015_11~2016_01(2015 Q1).csv", "train_2015_12~2016_02(2015 Q1).csv", "train_2016_01-03(2016 Q1).csv", "train_2016_02-04(2016 Q1).csv", "train_2016_03-05(2016 Q1).csv", "train_2016_04-06(2016 Q1).csv", "train_2016_05-07(2016 Q1).csv", "train_2016_06-08(2016 Q1).csv", "train_2016_07-09(2016 Q1).csv", "train_2016_08-10(2016 Q1).csv", "train_2016_09-11(2016 Q1).csv",
"train_2016_10-12(2016 Q1).csv", "train_2016_11~2017_01(2016 Q1).csv", "train_2016_12~2017_02(2016 Q1).csv", "train_2017_01-03(2017 Q1).csv", "train_2017_02-04(2017 Q1).csv", "train_2017_03-05(2017 Q1).csv", "train_2017_04-06(2017 Q1).csv", "train_2017_05-07(2017 Q1).csv", "train_2017_06-08(2017 Q1).csv", "train_2017_07-09(2017 Q1).csv", "train_2017_08-10(2017 Q1).csv", "train_2017_09-11(2017 Q1).csv", "train_2017_10-12(2017 Q1).csv", "train_2017_11~2018_01(2017 Q1).csv",
"train_2017_12~2018_02(2017 Q1).csv", "train_2018_01-03(2018 Q1).csv", "train_2018_02-04(2018 Q1).csv", "train_2018_03-05(2018 Q1).csv", "train_2018_04-06(2018 Q1).csv", "train_2018_05-07(2018 Q1).csv", "train_2018_06-08(2018 Q1).csv", "train_2018_07-09(2018 Q1).csv", "train_2018_08-10(2018 Q1).csv", "train_2018_09-11(2018 Q1).csv", "train_2018_10-12(2018 Q1).csv", "train_2018_11~2019_01(2018 Q1).csv", "train_2018_12~2019_02(2018 Q1).csv", "train_2019_01-03(2019 Q1).csv", "train_2019_02-04(2019 Q1).csv",
"train_2019_03-05(2019 Q1).csv", "train_2019_04-06(2019 Q1).csv", "train_2019_05-07(2019 Q1).csv", "train_2019_06-08(2019 Q1).csv", "train_2019_07-09(2019 Q1).csv", "train_2019_08-10(2019 Q1).csv", "train_2019_09-11(2019 Q1).csv" };
string QQ_train20[] = { "train_2012_Q1(2012 Q1).csv", "train_2012_Q2(2012 Q1).csv", "train_2012_Q3(2012 Q1).csv", "train_2012_Q4(2012 Q1).csv", "train_2013_Q1(2013 Q1).csv", "train_2013_Q2(2013 Q1).csv", "train_2013_Q3(2013 Q1).csv", "train_2013_Q4(2013 Q1).csv", "train_2014_Q1(2014 Q1).csv", "train_2014_Q2(2014 Q1).csv", "train_2014_Q3(2014 Q1).csv", "train_2014_Q4(2014 Q1).csv", "train_2015_Q1(2015 Q1).csv", "train_2015_Q2(2015 Q1).csv", "train_2015_Q3(2015 Q1).csv", "train_2015_Q4(2015 Q1).csv",
"train_2016_Q1(2016 Q1).csv", "train_2016_Q2(2016 Q1).csv", "train_2016_Q3(2016 Q1).csv", "train_2016_Q4(2016 Q1).csv", "train_2017_Q1(2017 Q1).csv", "train_2017_Q2(2017 Q1).csv", "train_2017_Q3(2017 Q1).csv", "train_2017_Q4(2017 Q1).csv", "train_2018_Q1(2018 Q1).csv", "train_2018_Q2(2018 Q1).csv", "train_2018_Q3(2018 Q1).csv", "train_2018_Q4(2018 Q1).csv" };
string M2M_train20[] = { "train_2012_12(2012 Q1).csv", "train_2013_01(2013 Q1).csv", "train_2013_02(2013 Q1).csv", "train_2013_03(2013 Q1).csv", "train_2013_04(2013 Q1).csv", "train_2013_05(2013 Q1).csv",
"train_2013_06(2013 Q1).csv", "train_2013_07(2013 Q1).csv", "train_2013_08(2013 Q1).csv", "train_2013_09(2013 Q1).csv", "train_2013_10(2013 Q1).csv", "train_2013_11(2013 Q1).csv", "train_2013_12(2013 Q1).csv", "train_2014_01(2014 Q1).csv", "train_2014_02(2014 Q1).csv", "train_2014_03(2014 Q1).csv", "train_2014_04(2014 Q1).csv", "train_2014_05(2014 Q1).csv", "train_2014_06(2014 Q1).csv", "train_2014_07(2014 Q1).csv",
"train_2014_08(2014 Q1).csv", "train_2014_09(2014 Q1).csv", "train_2014_10(2014 Q1).csv", "train_2014_11(2014 Q1).csv", "train_2014_12(2014 Q1).csv", "train_2015_01(2015 Q1).csv", "train_2015_02(2015 Q1).csv", "train_2015_03(2015 Q1).csv", "train_2015_04(2015 Q1).csv", "train_2015_05(2015 Q1).csv", "train_2015_06(2015 Q1).csv", "train_2015_07(2015 Q1).csv", "train_2015_08(2015 Q1).csv", "train_2015_09(2015 Q1).csv",
"train_2015_10(2015 Q1).csv", "train_2015_11(2015 Q1).csv", "train_2015_12(2015 Q1).csv", "train_2016_01(2016 Q1).csv", "train_2016_02(2016 Q1).csv", "train_2016_03(2016 Q1).csv", "train_2016_04(2016 Q1).csv", "train_2016_05(2016 Q1).csv", "train_2016_06(2016 Q1).csv", "train_2016_07(2016 Q1).csv", "train_2016_08(2016 Q1).csv", "train_2016_09(2016 Q1).csv", "train_2016_10(2016 Q1).csv", "train_2016_11(2016 Q1).csv",
"train_2016_12(2016 Q1).csv", "train_2017_01(2017 Q1).csv", "train_2017_02(2017 Q1).csv", "train_2017_03(2017 Q1).csv", "train_2017_04(2017 Q1).csv", "train_2017_05(2017 Q1).csv", "train_2017_06(2017 Q1).csv", "train_2017_07(2017 Q1).csv", "train_2017_08(2017 Q1).csv", "train_2017_09(2017 Q1).csv", "train_2017_10(2017 Q1).csv", "train_2017_11(2017 Q1).csv", "train_2017_12(2017 Q1).csv", "train_2018_01(2018 Q1).csv",
"train_2018_02(2018 Q1).csv", "train_2018_03(2018 Q1).csv", "train_2018_04(2018 Q1).csv", "train_2018_05(2018 Q1).csv", "train_2018_06(2018 Q1).csv", "train_2018_07(2018 Q1).csv", "train_2018_08(2018 Q1).csv", "train_2018_09(2018 Q1).csv", "train_2018_10(2018 Q1).csv", "train_2018_11(2018 Q1).csv", "train_2018_12(2018 Q1).csv", "train_2019_01(2019 Q1).csv", "train_2019_02(2019 Q1).csv", "train_2019_03(2019 Q1).csv",
"train_2019_04(2019 Q1).csv", "train_2019_05(2019 Q1).csv", "train_2019_06(2019 Q1).csv", "train_2019_07(2019 Q1).csv", "train_2019_08(2019 Q1).csv", "train_2019_09(2019 Q1).csv", "train_2019_10(2019 Q1).csv", "train_2019_11(2019 Q1).csv" };
string MM_train20[] = { "train_2012_01(2012 Q1).csv", "train_2012_02(2012 Q1).csv", "train_2012_03(2012 Q1).csv", "train_2012_04(2012 Q1).csv", "train_2012_05(2012 Q1).csv", "train_2012_06(2012 Q1).csv", "train_2012_07(2012 Q1).csv", "train_2012_08(2012 Q1).csv", "train_2012_09(2012 Q1).csv", "train_2012_10(2012 Q1).csv", "train_2012_11(2012 Q1).csv", "train_2012_12(2012 Q1).csv", "train_2013_01(2013 Q1).csv", "train_2013_02(2013 Q1).csv", "train_2013_03(2013 Q1).csv",
"train_2013_04(2013 Q1).csv", "train_2013_05(2013 Q1).csv", "train_2013_06(2013 Q1).csv", "train_2013_07(2013 Q1).csv", "train_2013_08(2013 Q1).csv", "train_2013_09(2013 Q1).csv", "train_2013_10(2013 Q1).csv", "train_2013_11(2013 Q1).csv", "train_2013_12(2013 Q1).csv", "train_2014_01(2014 Q1).csv", "train_2014_02(2014 Q1).csv", "train_2014_03(2014 Q1).csv", "train_2014_04(2014 Q1).csv", "train_2014_05(2014 Q1).csv", "train_2014_06(2014 Q1).csv", "train_2014_07(2014 Q1).csv", "train_2014_08(2014 Q1).csv",
"train_2014_09(2014 Q1).csv", "train_2014_10(2014 Q1).csv", "train_2014_11(2014 Q1).csv", "train_2014_12(2014 Q1).csv", "train_2015_01(2015 Q1).csv", "train_2015_02(2015 Q1).csv", "train_2015_03(2015 Q1).csv", "train_2015_04(2015 Q1).csv", "train_2015_05(2015 Q1).csv", "train_2015_06(2015 Q1).csv", "train_2015_07(2015 Q1).csv", "train_2015_08(2015 Q1).csv", "train_2015_09(2015 Q1).csv", "train_2015_10(2015 Q1).csv", "train_2015_11(2015 Q1).csv", "train_2015_12(2015 Q1).csv", "train_2016_01(2016 Q1).csv",
"train_2016_02(2016 Q1).csv", "train_2016_03(2016 Q1).csv", "train_2016_04(2016 Q1).csv", "train_2016_05(2016 Q1).csv", "train_2016_06(2016 Q1).csv", "train_2016_07(2016 Q1).csv", "train_2016_08(2016 Q1).csv", "train_2016_09(2016 Q1).csv", "train_2016_10(2016 Q1).csv", "train_2016_11(2016 Q1).csv", "train_2016_12(2016 Q1).csv", "train_2017_01(2017 Q1).csv", "train_2017_02(2017 Q1).csv", "train_2017_03(2017 Q1).csv", "train_2017_04(2017 Q1).csv", "train_2017_05(2017 Q1).csv", "train_2017_06(2017 Q1).csv",
"train_2017_07(2017 Q1).csv", "train_2017_08(2017 Q1).csv", "train_2017_09(2017 Q1).csv", "train_2017_10(2017 Q1).csv", "train_2017_11(2017 Q1).csv", "train_2017_12(2017 Q1).csv", "train_2018_01(2018 Q1).csv", "train_2018_02(2018 Q1).csv", "train_2018_03(2018 Q1).csv", "train_2018_04(2018 Q1).csv", "train_2018_05(2018 Q1).csv", "train_2018_06(2018 Q1).csv", "train_2018_07(2018 Q1).csv", "train_2018_08(2018 Q1).csv", "train_2018_09(2018 Q1).csv", "train_2018_10(2018 Q1).csv", "train_2018_11(2018 Q1).csv",
"train_2018_12(2018 Q1).csv" };
string H2Q_train20[] = { "train_2012_Q3-Q4(2012 Q1).csv", "train_2012_Q4~2013_Q1(2012 Q1).csv", "train_2013_Q1-Q2(2013 Q1).csv", "train_2013_Q2-Q3(2013 Q1).csv", "train_2013_Q3-Q4(2013 Q1).csv", "train_2013_Q4~2014_Q1(2013 Q1).csv", "train_2014_Q1-Q2(2014 Q1).csv", "train_2014_Q2-Q3(2014 Q1).csv", "train_2014_Q3-Q4(2014 Q1).csv", "train_2014_Q4~2015_Q1(2014 Q1).csv", "train_2015_Q1-Q2(2015 Q1).csv", "train_2015_Q2-Q3(2015 Q1).csv", "train_2015_Q3-Q4(2015 Q1).csv", "train_2015_Q4~2016_Q1(2015 Q1).csv", "train_2016_Q1-Q2(2016 Q1).csv", "train_2016_Q2-Q3(2016 Q1).csv",
"train_2016_Q3-Q4(2016 Q1).csv", "train_2016_Q4~2017_Q1(2016 Q1).csv", "train_2017_Q1-Q2(2017 Q1).csv", "train_2017_Q2-Q3(2017 Q1).csv", "train_2017_Q3-Q4(2017 Q1).csv", "train_2017_Q4~2018_Q1(2017 Q1).csv", "train_2018_Q1-Q2(2018 Q1).csv", "train_2018_Q2-Q3(2018 Q1).csv", "train_2018_Q3-Q4(2018 Q1).csv", "train_2018_Q4~2019_Q1(2018 Q1).csv", "train_2019_Q1-Q2(2019 Q1).csv", "train_2019_Q2-Q3(2019 Q1).csv" };
string H2M_train20[] = { "train_2012_07-12(2012 Q1).csv", "train_2012_08~2013_01(2012 Q1).csv", "train_2012_09~2013_02(2012 Q1).csv",
"train_2012_10~2013_03(2012 Q1).csv", "train_2012_11~2013_04(2012 Q1).csv", "train_2012_12~2013_05(2012 Q1).csv", "train_2013_01-06(2013 Q1).csv", "train_2013_02-07(2013 Q1).csv", "train_2013_03-08(2013 Q1).csv", "train_2013_04-09(2013 Q1).csv", "train_2013_05-10(2013 Q1).csv", "train_2013_06-11(2013 Q1).csv", "train_2013_07-12(2013 Q1).csv", "train_2013_08~2014_01(2013 Q1).csv", "train_2013_09~2014_02(2013 Q1).csv",
"train_2013_10~2014_03(2013 Q1).csv", "train_2013_11~2014_04(2013 Q1).csv", "train_2013_12~2014_05(2013 Q1).csv", "train_2014_01-06(2014 Q1).csv", "train_2014_02-07(2014 Q1).csv", "train_2014_03-08(2014 Q1).csv", "train_2014_04-09(2014 Q1).csv", "train_2014_05-10(2014 Q1).csv", "train_2014_06-11(2014 Q1).csv", "train_2014_07-12(2014 Q1).csv", "train_2014_08~2015_01(2014 Q1).csv", "train_2014_09~2015_02(2014 Q1).csv", "train_2014_10~2015_03(2014 Q1).csv",
"train_2014_11~2015_04(2014 Q1).csv", "train_2014_12~2015_05(2014 Q1).csv", "train_2015_01-06(2015 Q1).csv", "train_2015_02-07(2015 Q1).csv", "train_2015_03-08(2015 Q1).csv", "train_2015_04-09(2015 Q1).csv", "train_2015_05-10(2015 Q1).csv", "train_2015_06-11(2015 Q1).csv", "train_2015_07-12(2015 Q1).csv", "train_2015_08~2016_01(2015 Q1).csv", "train_2015_09~2016_02(2015 Q1).csv", "train_2015_10~2016_03(2015 Q1).csv", "train_2015_11~2016_04(2015 Q1).csv",
"train_2015_12~2016_05(2015 Q1).csv", "train_2016_01-06(2016 Q1).csv", "train_2016_02-07(2016 Q1).csv", "train_2016_03-08(2016 Q1).csv", "train_2016_04-09(2016 Q1).csv", "train_2016_05-10(2016 Q1).csv", "train_2016_06-11(2016 Q1).csv", "train_2016_07-12(2016 Q1).csv", "train_2016_08~2017_01(2016 Q1).csv", "train_2016_09~2017_02(2016 Q1).csv", "train_2016_10~2017_03(2016 Q1).csv", "train_2016_11~2017_04(2016 Q1).csv", "train_2016_12~2017_05(2016 Q1).csv",
"train_2017_01-06(2017 Q1).csv", "train_2017_02-07(2017 Q1).csv", "train_2017_03-08(2017 Q1).csv", "train_2017_04-09(2017 Q1).csv", "train_2017_05-10(2017 Q1).csv", "train_2017_06-11(2017 Q1).csv", "train_2017_07-12(2017 Q1).csv", "train_2017_08~2018_01(2017 Q1).csv", "train_2017_09~2018_02(2017 Q1).csv", "train_2017_10~2018_03(2017 Q1).csv", "train_2017_11~2018_04(2017 Q1).csv", "train_2017_12~2018_05(2017 Q1).csv", "train_2018_01-06(2018 Q1).csv",
"train_2018_02-07(2018 Q1).csv", "train_2018_03-08(2018 Q1).csv", "train_2018_04-09(2018 Q1).csv", "train_2018_05-10(2018 Q1).csv", "train_2018_06-11(2018 Q1).csv", "train_2018_07-12(2018 Q1).csv", "train_2018_08~2019_01(2018 Q1).csv", "train_2018_09~2019_02(2018 Q1).csv", "train_2018_10~2019_03(2018 Q1).csv", "train_2018_11~2019_04(2018 Q1).csv", "train_2018_12~2019_05(2018 Q1).csv", "train_2019_01-06(2019 Q1).csv", "train_2019_02-07(2019 Q1).csv",
"train_2019_03-08(2019 Q1).csv", "train_2019_04-09(2019 Q1).csv", "train_2019_05-10(2019 Q1).csv", "train_2019_06-11(2019 Q1).csv" };
string HH_train20[] = { "train_2012_Q1-Q2(2012 Q1).csv", "train_2012_Q3-Q4(2012 Q1).csv", "train_2013_Q1-Q2(2013 Q1).csv", "train_2013_Q3-Q4(2013 Q1).csv", "train_2014_Q1-Q2(2014 Q1).csv", "train_2014_Q3-Q4(2014 Q1).csv", "train_2015_Q1-Q2(2015 Q1).csv", "train_2015_Q3-Q4(2015 Q1).csv", "train_2016_Q1-Q2(2016 Q1).csv", "train_2016_Q3-Q4(2016 Q1).csv", "train_2017_Q1-Q2(2017 Q1).csv", "train_2017_Q3-Q4(2017 Q1).csv", "train_2018_Q1-Q2(2018 Q1).csv", "train_2018_Q3-Q4(2018 Q1).csv" };
string H2H_train20[] = { "train_2012_Q3-Q4(2012 Q1).csv", "train_2013_Q1-Q2(2013 Q1).csv", "train_2013_Q3-Q4(2013 Q1).csv", "train_2014_Q1-Q2(2014 Q1).csv", "train_2014_Q3-Q4(2014 Q1).csv", "train_2015_Q1-Q2(2015 Q1).csv", "train_2015_Q3-Q4(2015 Q1).csv", "train_2016_Q1-Q2(2016 Q1).csv","train_2016_Q3-Q4(2016 Q1).csv","train_2017_Q1-Q2(2017 Q1).csv", "train_2017_Q3-Q4(2017 Q1).csv", "train_2018_Q1-Q2(2018 Q1).csv", "train_2018_Q3-Q4(2018 Q1).csv", "train_2019_Q1-Q2(2019 Q1).csv" };
/*���ȫe20�j�V�m��*/

string Y2Y_test20[] = { "test_2013(2012 Q1).csv", "test_2014(2013 Q1).csv", "test_2015(2014 Q1).csv", "test_2016(2015 Q1).csv", "test_2017(2016 Q1).csv", "test_2018(2017 Q1).csv", "test_2019(2018 Q1).csv" };
string Y2Q_test20[] = { "test_2013_Q1(2012 Q1).csv", "test_2013_Q2(2012 Q1).csv", "test_2013_Q3(2012 Q1).csv", "test_2013_Q4(2012 Q1).csv", "test_2014_Q1(2013 Q1).csv","test_2014_Q2(2013 Q1).csv", "test_2014_Q3(2013 Q1).csv", "test_2014_Q4(2013 Q1).csv", "test_2015_Q1(2014 Q1).csv", "test_2015_Q2(2014 Q1).csv", "test_2015_Q3(2014 Q1).csv", "test_2015_Q4(2014 Q1).csv", "test_2016_Q1(2015 Q1).csv", "test_2016_Q2(2015 Q1).csv", "test_2016_Q3(2015 Q1).csv", "test_2016_Q4(2015 Q1).csv",
"test_2017_Q1(2016 Q1).csv", "test_2017_Q2(2016 Q1).csv", "test_2017_Q3(2016 Q1).csv", "test_2017_Q4(2016 Q1).csv", "test_2018_Q1(2017 Q1).csv", "test_2018_Q2(2017 Q1).csv", "test_2018_Q3(2017 Q1).csv", "test_2018_Q4(2017 Q1).csv", "test_2019_Q1(2018 Q1).csv", "test_2019_Q2(2018 Q1).csv", "test_2019_Q3(2018 Q1).csv", "test_2019_Q4(2018 Q1).csv" };
string Y2M_test20[] = { "test_2013_01(2012 Q1).csv", "test_2013_02(2012 Q1).csv", "test_2013_03(2012 Q1).csv", "test_2013_04(2012 Q1).csv", "test_2013_05(2012 Q1).csv", "test_2013_06(2012 Q1).csv", "test_2013_07(2012 Q1).csv", "test_2013_08(2012 Q1).csv", "test_2013_09(2012 Q1).csv", "test_2013_10(2012 Q1).csv", "test_2013_11(2012 Q1).csv", "test_2013_12(2012 Q1).csv", "test_2014_01(2013 Q1).csv", "test_2014_02(2013 Q1).csv", "test_2014_03(2013 Q1).csv", "test_2014_04(2013 Q1).csv", "test_2014_05(2013 Q1).csv",
"test_2014_06(2013 Q1).csv", "test_2014_07(2013 Q1).csv", "test_2014_08(2013 Q1).csv", "test_2014_09(2013 Q1).csv", "test_2014_10(2013 Q1).csv", "test_2014_11(2013 Q1).csv", "test_2014_12(2013 Q1).csv", "test_2015_01(2014 Q1).csv", "test_2015_02(2014 Q1).csv", "test_2015_03(2014 Q1).csv", "test_2015_04(2014 Q1).csv", "test_2015_05(2014 Q1).csv", "test_2015_06(2014 Q1).csv", "test_2015_07(2014 Q1).csv", "test_2015_08(2014 Q1).csv", "test_2015_09(2014 Q1).csv", "test_2015_10(2014 Q1).csv", "test_2015_11(2014 Q1).csv",
"test_2015_12(2014 Q1).csv", "test_2016_01(2015 Q1).csv", "test_2016_02(2015 Q1).csv", "test_2016_03(2015 Q1).csv", "test_2016_04(2015 Q1).csv", "test_2016_05(2015 Q1).csv", "test_2016_06(2015 Q1).csv", "test_2016_07(2015 Q1).csv", "test_2016_08(2015 Q1).csv", "test_2016_09(2015 Q1).csv", "test_2016_10(2015 Q1).csv", "test_2016_11(2015 Q1).csv", "test_2016_12(2015 Q1).csv", "test_2017_01(2016 Q1).csv", "test_2017_02(2016 Q1).csv", "test_2017_03(2016 Q1).csv", "test_2017_04(2016 Q1).csv", "test_2017_05(2016 Q1).csv",
"test_2017_06(2016 Q1).csv", "test_2017_07(2016 Q1).csv", "test_2017_08(2016 Q1).csv", "test_2017_09(2016 Q1).csv", "test_2017_10(2016 Q1).csv", "test_2017_11(2016 Q1).csv", "test_2017_12(2016 Q1).csv", "test_2018_01(2017 Q1).csv", "test_2018_02(2017 Q1).csv", "test_2018_03(2017 Q1).csv", "test_2018_04(2017 Q1).csv", "test_2018_05(2017 Q1).csv", "test_2018_06(2017 Q1).csv", "test_2018_07(2017 Q1).csv", "test_2018_08(2017 Q1).csv", "test_2018_09(2017 Q1).csv", "test_2018_10(2017 Q1).csv", "test_2018_11(2017 Q1).csv",
"test_2018_12(2017 Q1).csv", "test_2019_01(2018 Q1).csv", "test_2019_02(2018 Q1).csv", "test_2019_03(2018 Q1).csv", "test_2019_04(2018 Q1).csv", "test_2019_05(2018 Q1).csv", "test_2019_06(2018 Q1).csv", "test_2019_07(2018 Q1).csv", "test_2019_08(2018 Q1).csv", "test_2019_09(2018 Q1).csv", "test_2019_10(2018 Q1).csv", "test_2019_11(2018 Q1).csv", "test_2019_12(2018 Q1).csv" };
string Y2H_test20[] = { "test_2013_Q1-Q2(2012 Q1).csv", "test_2013_Q3-Q4(2012 Q1).csv", "test_2014_Q1-Q2(2013 Q1).csv", "test_2014_Q3-Q4(2013 Q1).csv", "test_2015_Q1-Q2(2014 Q1).csv", "test_2015_Q3-Q4(2014 Q1).csv", "test_2016_Q1-Q2(2015 Q1).csv", "test_2016_Q3-Q4(2015 Q1).csv", "test_2017_Q1-Q2(2016 Q1).csv", "test_2017_Q3-Q4(2016 Q1).csv", "test_2018_Q1-Q2(2017 Q1).csv", "test_2018_Q3-Q4(2017 Q1).csv", "test_2019_Q1-Q2(2018 Q1).csv", "test_2019_Q3-Q4(2018 Q1).csv" };
string Q2Q_test20[] = { "test_2013_Q1(2012 Q1).csv", "test_2013_Q2(2013 Q1).csv", "test_2013_Q3(2013 Q1).csv", "test_2013_Q4(2013 Q1).csv", "test_2014_Q1(2013 Q1).csv", "test_2014_Q2(2014 Q1).csv", "test_2014_Q3(2014 Q1).csv", "test_2014_Q4(2014 Q1).csv", "test_2015_Q1(2014 Q1).csv", "test_2015_Q2(2015 Q1).csv", "test_2015_Q3(2015 Q1).csv", "test_2015_Q4(2015 Q1).csv", "test_2016_Q1(2015 Q1).csv", "test_2016_Q2(2016 Q1).csv", "test_2016_Q3(2016 Q1).csv", "test_2016_Q4(2016 Q1).csv", "test_2017_Q1(2016 Q1).csv",
"test_2017_Q2(2017 Q1).csv", "test_2017_Q3(2017 Q1).csv", "test_2017_Q4(2017 Q1).csv", "test_2018_Q1(2017 Q1).csv", "test_2018_Q2(2018 Q1).csv", "test_2018_Q3(2018 Q1).csv", "test_2018_Q4(2018 Q1).csv", "test_2019_Q1(2018 Q1).csv", "test_2019_Q2(2019 Q1).csv", "test_2019_Q3(2019 Q1).csv", "test_2019_Q4(2019 Q1).csv" };
string Q2M_test20[] = { "test_2013_01(2012 Q1).csv","test_2013_02(2012 Q1).csv", "test_2013_03(2012 Q1).csv", "test_2013_04(2013 Q1).csv", "test_2013_05(2013 Q1).csv", "test_2013_06(2013 Q1).csv", "test_2013_07(2013 Q1).csv", "test_2013_08(2013 Q1).csv", "test_2013_09(2013 Q1).csv", "test_2013_10(2013 Q1).csv", "test_2013_11(2013 Q1).csv", "test_2013_12(2013 Q1).csv", "test_2014_01(2013 Q1).csv", "test_2014_02(2013 Q1).csv", "test_2014_03(2013 Q1).csv", "test_2014_04(2014 Q1).csv", "test_2014_05(2014 Q1).csv", "test_2014_06(2014 Q1).csv", "test_2014_07(2014 Q1).csv", "test_2014_08(2014 Q1).csv",
"test_2014_09(2014 Q1).csv", "test_2014_10(2014 Q1).csv", "test_2014_11(2014 Q1).csv", "test_2014_12(2014 Q1).csv", "test_2015_01(2014 Q1).csv", "test_2015_02(2014 Q1).csv", "test_2015_03(2014 Q1).csv", "test_2015_04(2015 Q1).csv", "test_2015_05(2015 Q1).csv", "test_2015_06(2015 Q1).csv", "test_2015_07(2015 Q1).csv", "test_2015_08(2015 Q1).csv", "test_2015_09(2015 Q1).csv", "test_2015_10(2015 Q1).csv", "test_2015_11(2015 Q1).csv", "test_2015_12(2015 Q1).csv", "test_2016_01(2015 Q1).csv", "test_2016_02(2015 Q1).csv", "test_2016_03(2015 Q1).csv",
"test_2016_04(2016 Q1).csv", "test_2016_05(2016 Q1).csv", "test_2016_06(2016 Q1).csv", "test_2016_07(2016 Q1).csv", "test_2016_08(2016 Q1).csv", "test_2016_09(2016 Q1).csv", "test_2016_10(2016 Q1).csv", "test_2016_11(2016 Q1).csv", "test_2016_12(2016 Q1).csv", "test_2017_01(2016 Q1).csv", "test_2017_02(2016 Q1).csv", "test_2017_03(2016 Q1).csv", "test_2017_04(2017 Q1).csv", "test_2017_05(2017 Q1).csv", "test_2017_06(2017 Q1).csv", "test_2017_07(2017 Q1).csv", "test_2017_08(2017 Q1).csv", "test_2017_09(2017 Q1).csv", "test_2017_10(2017 Q1).csv",
"test_2017_11(2017 Q1).csv", "test_2017_12(2017 Q1).csv", "test_2018_01(2017 Q1).csv", "test_2018_02(2017 Q1).csv", "test_2018_03(2017 Q1).csv", "test_2018_04(2018 Q1).csv", "test_2018_05(2018 Q1).csv", "test_2018_06(2018 Q1).csv", "test_2018_07(2018 Q1).csv", "test_2018_08(2018 Q1).csv", "test_2018_09(2018 Q1).csv", "test_2018_10(2018 Q1).csv", "test_2018_11(2018 Q1).csv", "test_2018_12(2018 Q1).csv", "test_2019_01(2018 Q1).csv", "test_2019_02(2018 Q1).csv", "test_2019_03(2018 Q1).csv", "test_2019_04(2019 Q1).csv", "test_2019_05(2019 Q1).csv",
"test_2019_06(2019 Q1).csv", "test_2019_07(2019 Q1).csv", "test_2019_08(2019 Q1).csv", "test_2019_09(2019 Q1).csv", "test_2019_10(2019 Q1).csv", "test_2019_11(2019 Q1).csv", "test_2019_12(2019 Q1).csv" };
string QQ_test20[] = { "test_2013_Q1(2012 Q1).csv", "test_2013_Q2(2012 Q1).csv", "test_2013_Q3(2012 Q1).csv", "test_2013_Q4(2012 Q1).csv", "test_2014_Q1(2013 Q1).csv", "test_2014_Q2(2013 Q1).csv",
"test_2014_Q3(2013 Q1).csv", "test_2014_Q4(2013 Q1).csv", "test_2015_Q1(2014 Q1).csv", "test_2015_Q2(2014 Q1).csv", "test_2015_Q3(2014 Q1).csv", "test_2015_Q4(2014 Q1).csv", "test_2016_Q1(2015 Q1).csv", "test_2016_Q2(2015 Q1).csv", "test_2016_Q3(2015 Q1).csv", "test_2016_Q4(2015 Q1).csv", "test_2017_Q1(2016 Q1).csv", "test_2017_Q2(2016 Q1).csv", "test_2017_Q3(2016 Q1).csv", "test_2017_Q4(2016 Q1).csv", "test_2018_Q1(2017 Q1).csv", "test_2018_Q2(2017 Q1).csv", "test_2018_Q3(2017 Q1).csv", "test_2018_Q4(2017 Q1).csv",
"test_2019_Q1(2018 Q1).csv", "test_2019_Q2(2018 Q1).csv", "test_2019_Q3(2018 Q1).csv", "test_2019_Q4(2018 Q1).csv" };
string M2M_test20[] = { "test_2013_01(2012 Q1).csv","test_2013_02(2013 Q1).csv", "test_2013_03(2013 Q1).csv", "test_2013_04(2013 Q1).csv", "test_2013_05(2013 Q1).csv", "test_2013_06(2013 Q1).csv", "test_2013_07(2013 Q1).csv", "test_2013_08(2013 Q1).csv", "test_2013_09(2013 Q1).csv", "test_2013_10(2013 Q1).csv", "test_2013_11(2013 Q1).csv", "test_2013_12(2013 Q1).csv", "test_2014_01(2013 Q1).csv", "test_2014_02(2014 Q1).csv", "test_2014_03(2014 Q1).csv", "test_2014_04(2014 Q1).csv", "test_2014_05(2014 Q1).csv", "test_2014_06(2014 Q1).csv", "test_2014_07(2014 Q1).csv", "test_2014_08(2014 Q1).csv",
"test_2014_09(2014 Q1).csv", "test_2014_10(2014 Q1).csv", "test_2014_11(2014 Q1).csv", "test_2014_12(2014 Q1).csv", "test_2015_01(2014 Q1).csv", "test_2015_02(2015 Q1).csv", "test_2015_03(2015 Q1).csv", "test_2015_04(2015 Q1).csv", "test_2015_05(2015 Q1).csv", "test_2015_06(2015 Q1).csv", "test_2015_07(2015 Q1).csv", "test_2015_08(2015 Q1).csv", "test_2015_09(2015 Q1).csv", "test_2015_10(2015 Q1).csv", "test_2015_11(2015 Q1).csv", "test_2015_12(2015 Q1).csv", "test_2016_01(2015 Q1).csv", "test_2016_02(2016 Q1).csv", "test_2016_03(2016 Q1).csv",
"test_2016_04(2016 Q1).csv", "test_2016_05(2016 Q1).csv", "test_2016_06(2016 Q1).csv", "test_2016_07(2016 Q1).csv", "test_2016_08(2016 Q1).csv", "test_2016_09(2016 Q1).csv", "test_2016_10(2016 Q1).csv", "test_2016_11(2016 Q1).csv", "test_2016_12(2016 Q1).csv", "test_2017_01(2016 Q1).csv", "test_2017_02(2017 Q1).csv", "test_2017_03(2017 Q1).csv", "test_2017_04(2017 Q1).csv", "test_2017_05(2017 Q1).csv", "test_2017_06(2017 Q1).csv", "test_2017_07(2017 Q1).csv", "test_2017_08(2017 Q1).csv", "test_2017_09(2017 Q1).csv", "test_2017_10(2017 Q1).csv",
"test_2017_11(2017 Q1).csv", "test_2017_12(2017 Q1).csv", "test_2018_01(2017 Q1).csv", "test_2018_02(2018 Q1).csv", "test_2018_03(2018 Q1).csv", "test_2018_04(2018 Q1).csv", "test_2018_05(2018 Q1).csv", "test_2018_06(2018 Q1).csv", "test_2018_07(2018 Q1).csv", "test_2018_08(2018 Q1).csv", "test_2018_09(2018 Q1).csv", "test_2018_10(2018 Q1).csv", "test_2018_11(2018 Q1).csv", "test_2018_12(2018 Q1).csv", "test_2019_01(2018 Q1).csv", "test_2019_02(2019 Q1).csv", "test_2019_03(2019 Q1).csv", "test_2019_04(2019 Q1).csv", "test_2019_05(2019 Q1).csv",
"test_2019_06(2019 Q1).csv", "test_2019_07(2019 Q1).csv", "test_2019_08(2019 Q1).csv", "test_2019_09(2019 Q1).csv", "test_2019_10(2019 Q1).csv", "test_2019_11(2019 Q1).csv", "test_2019_12(2019 Q1).csv" };
string MM_test20[] = { "test_2013_01(2012 Q1).csv","test_2013_02(2012 Q1).csv", "test_2013_03(2012 Q1).csv", "test_2013_04(2012 Q1).csv", "test_2013_05(2012 Q1).csv", "test_2013_06(2012 Q1).csv", "test_2013_07(2012 Q1).csv", "test_2013_08(2012 Q1).csv", "test_2013_09(2012 Q1).csv", "test_2013_10(2012 Q1).csv", "test_2013_11(2012 Q1).csv", "test_2013_12(2012 Q1).csv", "test_2014_01(2013 Q1).csv", "test_2014_02(2013 Q1).csv", "test_2014_03(2013 Q1).csv", "test_2014_04(2013 Q1).csv", "test_2014_05(2013 Q1).csv", "test_2014_06(2013 Q1).csv", "test_2014_07(2013 Q1).csv", "test_2014_08(2013 Q1).csv",
"test_2014_09(2013 Q1).csv", "test_2014_10(2013 Q1).csv", "test_2014_11(2013 Q1).csv", "test_2014_12(2013 Q1).csv", "test_2015_01(2014 Q1).csv", "test_2015_02(2014 Q1).csv", "test_2015_03(2014 Q1).csv", "test_2015_04(2014 Q1).csv", "test_2015_05(2014 Q1).csv", "test_2015_06(2014 Q1).csv", "test_2015_07(2014 Q1).csv", "test_2015_08(2014 Q1).csv", "test_2015_09(2014 Q1).csv", "test_2015_10(2014 Q1).csv", "test_2015_11(2014 Q1).csv", "test_2015_12(2014 Q1).csv", "test_2016_01(2015 Q1).csv", "test_2016_02(2015 Q1).csv", "test_2016_03(2015 Q1).csv",
"test_2016_04(2015 Q1).csv", "test_2016_05(2015 Q1).csv", "test_2016_06(2015 Q1).csv", "test_2016_07(2015 Q1).csv", "test_2016_08(2015 Q1).csv", "test_2016_09(2015 Q1).csv", "test_2016_10(2015 Q1).csv", "test_2016_11(2015 Q1).csv", "test_2016_12(2015 Q1).csv", "test_2017_01(2016 Q1).csv", "test_2017_02(2016 Q1).csv", "test_2017_03(2016 Q1).csv", "test_2017_04(2016 Q1).csv", "test_2017_05(2016 Q1).csv", "test_2017_06(2016 Q1).csv", "test_2017_07(2016 Q1).csv", "test_2017_08(2016 Q1).csv", "test_2017_09(2016 Q1).csv", "test_2017_10(2016 Q1).csv",
"test_2017_11(2016 Q1).csv", "test_2017_12(2016 Q1).csv", "test_2018_01(2017 Q1).csv", "test_2018_02(2017 Q1).csv", "test_2018_03(2017 Q1).csv", "test_2018_04(2017 Q1).csv", "test_2018_05(2017 Q1).csv", "test_2018_06(2017 Q1).csv", "test_2018_07(2017 Q1).csv", "test_2018_08(2017 Q1).csv", "test_2018_09(2017 Q1).csv", "test_2018_10(2017 Q1).csv", "test_2018_11(2017 Q1).csv", "test_2018_12(2017 Q1).csv", "test_2019_01(2018 Q1).csv", "test_2019_02(2018 Q1).csv", "test_2019_03(2018 Q1).csv", "test_2019_04(2018 Q1).csv", "test_2019_05(2018 Q1).csv",
"test_2019_06(2018 Q1).csv", "test_2019_07(2018 Q1).csv", "test_2019_08(2018 Q1).csv", "test_2019_09(2018 Q1).csv", "test_2019_10(2018 Q1).csv", "test_2019_11(2018 Q1).csv", "test_2019_12(2018 Q1).csv" };
string H2Q_test20[] = { "test_2013_Q1(2012 Q1).csv", "test_2013_Q2(2012 Q1).csv", "test_2013_Q3(2013 Q1).csv", "test_2013_Q4(2013 Q1).csv", "test_2014_Q1(2013 Q1).csv", "test_2014_Q2(2013 Q1).csv","test_2014_Q3(2014 Q1).csv", "test_2014_Q4(2014 Q1).csv", "test_2015_Q1(2014 Q1).csv", "test_2015_Q2(2014 Q1).csv", "test_2015_Q3(2015 Q1).csv", "test_2015_Q4(2015 Q1).csv", "test_2016_Q1(2015 Q1).csv", "test_2016_Q2(2015 Q1).csv", "test_2016_Q3(2016 Q1).csv", "test_2016_Q4(2016 Q1).csv", "test_2017_Q1(2016 Q1).csv", "test_2017_Q2(2016 Q1).csv", "test_2017_Q3(2017 Q1).csv", "test_2017_Q4(2017 Q1).csv",
"test_2018_Q1(2017 Q1).csv", "test_2018_Q2(2017 Q1).csv", "test_2018_Q3(2018 Q1).csv", "test_2018_Q4(2018 Q1).csv", "test_2019_Q1(2018 Q1).csv", "test_2019_Q2(2018 Q1).csv", "test_2019_Q3(2019 Q1).csv", "test_2019_Q4(2019 Q1).csv" };
string H2M_test20[] = { "test_2013_01(2012 Q1).csv","test_2013_02(2012 Q1).csv", "test_2013_03(2012 Q1).csv", "test_2013_04(2012 Q1).csv", "test_2013_05(2012 Q1).csv", "test_2013_06(2012 Q1).csv", "test_2013_07(2013 Q1).csv", "test_2013_08(2013 Q1).csv", "test_2013_09(2013 Q1).csv", "test_2013_10(2013 Q1).csv", "test_2013_11(2013 Q1).csv", "test_2013_12(2013 Q1).csv", "test_2014_01(2013 Q1).csv", "test_2014_02(2013 Q1).csv", "test_2014_03(2013 Q1).csv", "test_2014_04(2013 Q1).csv", "test_2014_05(2013 Q1).csv", "test_2014_06(2013 Q1).csv", "test_2014_07(2014 Q1).csv", "test_2014_08(2014 Q1).csv",
"test_2014_09(2014 Q1).csv", "test_2014_10(2014 Q1).csv", "test_2014_11(2014 Q1).csv", "test_2014_12(2014 Q1).csv", "test_2015_01(2014 Q1).csv", "test_2015_02(2014 Q1).csv", "test_2015_03(2014 Q1).csv", "test_2015_04(2014 Q1).csv", "test_2015_05(2014 Q1).csv", "test_2015_06(2014 Q1).csv", "test_2015_07(2015 Q1).csv", "test_2015_08(2015 Q1).csv", "test_2015_09(2015 Q1).csv", "test_2015_10(2015 Q1).csv", "test_2015_11(2015 Q1).csv", "test_2015_12(2015 Q1).csv", "test_2016_01(2015 Q1).csv", "test_2016_02(2015 Q1).csv", "test_2016_03(2015 Q1).csv",
"test_2016_04(2015 Q1).csv", "test_2016_05(2015 Q1).csv", "test_2016_06(2015 Q1).csv", "test_2016_07(2016 Q1).csv", "test_2016_08(2016 Q1).csv", "test_2016_09(2016 Q1).csv", "test_2016_10(2016 Q1).csv", "test_2016_11(2016 Q1).csv", "test_2016_12(2016 Q1).csv", "test_2017_01(2016 Q1).csv", "test_2017_02(2016 Q1).csv", "test_2017_03(2016 Q1).csv", "test_2017_04(2016 Q1).csv", "test_2017_05(2016 Q1).csv", "test_2017_06(2016 Q1).csv", "test_2017_07(2017 Q1).csv", "test_2017_08(2017 Q1).csv", "test_2017_09(2017 Q1).csv", "test_2017_10(2017 Q1).csv",
"test_2017_11(2017 Q1).csv", "test_2017_12(2017 Q1).csv", "test_2018_01(2017 Q1).csv", "test_2018_02(2017 Q1).csv", "test_2018_03(2017 Q1).csv", "test_2018_04(2017 Q1).csv", "test_2018_05(2017 Q1).csv", "test_2018_06(2017 Q1).csv", "test_2018_07(2018 Q1).csv", "test_2018_08(2018 Q1).csv", "test_2018_09(2018 Q1).csv", "test_2018_10(2018 Q1).csv", "test_2018_11(2018 Q1).csv", "test_2018_12(2018 Q1).csv", "test_2019_01(2018 Q1).csv", "test_2019_02(2018 Q1).csv", "test_2019_03(2018 Q1).csv", "test_2019_04(2018 Q1).csv", "test_2019_05(2018 Q1).csv",
"test_2019_06(2018 Q1).csv", "test_2019_07(2019 Q1).csv", "test_2019_08(2019 Q1).csv", "test_2019_09(2019 Q1).csv", "test_2019_10(2019 Q1).csv", "test_2019_11(2019 Q1).csv", "test_2019_12(2019 Q1).csv"};
string HH_test20[] = { "test_2013_Q1-Q2(2012 Q1).csv", "test_2013_Q3-Q4(2012 Q1).csv", "test_2014_Q1-Q2(2013 Q1).csv", "test_2014_Q3-Q4(2013 Q1).csv", "test_2015_Q1-Q2(2014 Q1).csv", "test_2015_Q3-Q4(2014 Q1).csv", "test_2016_Q1-Q2(2015 Q1).csv", "test_2016_Q3-Q4(2015 Q1).csv", "test_2017_Q1-Q2(2016 Q1).csv", "test_2017_Q3-Q4(2016 Q1).csv", "test_2018_Q1 - Q2(2017 Q1).csv", "test_2018_Q3-Q4(2017 Q1).csv" };
string H2H_test20[] = { "test_2013_Q1-Q2(2012 Q1).csv", "test_2013_Q3-Q4(2013 Q1).csv", "test_2014_Q1-Q2(2013 Q1).csv", "test_2014_Q3-Q4(2014 Q1).csv", "test_2015_Q1-Q2(2014 Q1).csv", "test_2015_Q3-Q4(2015 Q1).csv", "test_2016_Q1-Q2(2015 Q1).csv","test_2016_Q3-Q4(2016 Q1).csv", "test_2017_Q1-Q2(2016 Q1).csv", "test_2017_Q3-Q4(2017 Q1).csv", "test_2018_Q1-Q2(2017 Q1).csv", "test_2018_Q3-Q4(2018 Q1).csv", "test_2019_Q1-Q2(2018 Q1).csv", "test_2019_Q3-Q4(2019 Q1).csv" };
/*���ȫe20�j���մ�*/

void read_file(int a) {
	input_file.open(QQ_train20[a], ios::in);
	cout << endl << QQ_train20[a] << endl;
	string line;
	while (getline(input_file, line))
	{
		s_stock_index = 0;
		string tmp;
		stringstream ss(line);
		if (index == 0)
		{
			while (getline(ss, tmp, ','))
			{
				string num;
				num = tmp;
				stock_no[s_stock_index] = num; //�s��
											   //cout << stock_no[s_stock_index] << endl;
				s_stock_index++;
			}
			index++;
		}
		else if (index > 0)
		{
			s_stock_index = 0;
			while (getline(ss, tmp, ','))
			{
				stringstream price;
				price << tmp;
				price >> all_stock[s_stock_index][index - 1];//�ѻ�
				s_stock_index++;
			}
			index++;
		}
	}
	input_file.close();
	day = index - 1;
	cout << day;
}//Ū��

void test_read_file(int a) {

	test_input_file.open(QQ_test20[a], ios::in);
	cout << endl << QQ_test20[a] << endl;
	string test_line;
	while (getline(test_input_file, test_line))
	{
		test_stock_index = 0;
		string test_tmp;
		stringstream test_ss(test_line);
		if (test_index == 0)
		{
			while (getline(test_ss, test_tmp, ','))
			{
				stringstream test_num;
				test_num << test_tmp;
				test_num >> test_stock_no[test_stock_index];//�s��
															//cout << test_stock_no[test_stock_index] << endl;
				test_stock_index++;
			}
			test_index++;
		}
		else if (test_index > 0)
		{
			test_stock_index = 0;
			while (getline(test_ss, test_tmp, ','))
			{
				stringstream test_price;
				test_price << test_tmp;
				test_price >> test_all_stock[test_stock_index][test_index - 1];//�ѻ�
				test_stock_index++;
			}
			test_index++;
		}
	}
	test_input_file.close();
	test_day = test_index - 1;
	total_test_day += test_day;
}//Ū��

void initial()
{
	for (int i = 0; i < s_stock_index; i++)
	{
		beta[i] = 0.5;
	}
}

void  measure()
{
	//cout << s_stock_index << endl;
	for (int i = 0; i < partical_num; i++) {
		n[i] = 0;//�d�U����R
		for (int j = 0; j < s_stock_index; j++) {

			random = rand() / 32767.0;
			if (random < beta[j]) {
				partical[i][j] = 1;
			}
			else partical[i][j] = 0;//�H����0��1
									/*if (j == 0 || j == 5 || j == 7 || j == 8 || j == 9 || j == 12 || j == 15 || j == 16 || j == 17)
									{
									partical[i][j] = 1;
									}
									else partical[i][j] = 0;*/

			if (partical[i][j] == 1)
			{
				stock_index[i][n[i]] = j;
				//cout << stock_no[stock_index[i][n[i]]] << endl; //�Ѳ��s��
				//cout << stock_index[i][n[i]]  << endl;//��쪺�Ѳ� index
				n[i] = n[i]++;//�X��
			}

		}

	}
}

void standardization()
{
	for (int i = 0; i < partical_num; i++)
	{
		share_money = initial_fund / n[i];//�C����ܫᥭ���C�ɪ����,���n�R!!!!
		all_share_money[i] = share_money;//��C�Ӳɤl�����t����s�_��
		remaind = initial_fund - share_money * n[i];//���զX���t���ѤU����
		for (int j = 0; j < n[i]; j++) {
			all_buy_lots[j] = 0;
			real_all_remain_fund[j] = 0;
			for (int k = 0; k < day; k++) {
				n_fund_standardization[i][j][k] = 0;
				if (k == 0)
				{
					buy_lots = share_money / all_stock[stock_index[i][j]][k];//����R�X��
																			 //buy_papper = share_money / (all_stock[stock_index[i][j]][k] * 1000.0 + all_stock[stock_index[i][j]][k] * 1.425);//�i�R�i��
					all_buy_lots[j] = buy_lots;
					all_remain_fund = share_money - buy_lots * all_stock[stock_index[i][j]][k];
					real_all_remain_fund[j] = all_remain_fund;//��R���U�ѳѾl����s�J�}�C���i��P�_
															  //fee = all_stock[stock_index[i][j]][k] * buy_papper * 1000 * fee_rate;//����O v
					n_fund_standardization[i][j][k] = share_money;
					//n_fund_standardization[i][j][k] = share_money - all_stock[stock_index[i][j]][k] * buy_papper * 1000 * fee_rate;//������� v

				}
				else
				{
					n_fund_standardization[i][j][k] = all_stock[stock_index[i][j]][k] * buy_lots + all_remain_fund;
					/*n_fund_standardization[i][j][k] = all_stock[stock_index[i][j]][k] * buy_papper -
					all_stock[stock_index[i][j]][k] * buy_papper * 1000 * fee_rate - buy_papper * all_stock[stock_index[i][j]][k] * 1000 * tax_rate + all_remain_fund;*/

				}
				/*if (share_money < 0)
				{
				n_fund_standardization[i][j][k] = 0;
				}*/
			}

		}

		for (int k = 0; k < day; k++)
		{
			yi[i][k] = 0;
			//all_total_yi[k] = 0;
			for (int j = 0; j < n[i]; j++)
			{
				yi[i][k] += n_fund_standardization[i][j][k];//yi total
			}
			yi[i][k] = yi[i][k] + remaind;//v
			all_total_yi[k] = yi[i][k];
		}
	}
}


void test_standardization(int a)//���մ��������p��
{
	test_share_money = test_initial_fund / Gbest_n;//�C����ܫᥭ���C�ɪ����,���n�R!!!!
	test_remaind = test_initial_fund - test_share_money * Gbest_n;//���զX���t���ѤU����


	for (int v = 0; v < s_stock_index; v++)
	{
		if (final_portfolio[v] != "/0")
		{
			for (int s = 0; s < test_stock_index; s++)
			{
				//cout << test_stock_no[s] << endl;
				if (final_portfolio[v] == test_stock_no[s])
				{
					//cout << s << endl;
					for (int k = 0; k < test_day; k++) {
						//	test_all_stock[s][k] = 0;
						if (k == 0)
						{
							//test_one_of_price = test_all_stock[s][k] * 1000 + test_all_stock[s][k] * 1.425;//��i����
							test_buy_lots = test_share_money / test_all_stock[s][k];//�i�R�i��
							test_all_buy_lots[s] = test_buy_lots;
							test_all_remain_fund = test_share_money - test_buy_lots * test_all_stock[s][k];//�R���U�ѳѾl���
							test_real_all_remain_fund[s] = test_all_remain_fund;//��R���U�ѳѾl����s�J�}�C���i��P�_;
							test_n_fund_standardization[s][k] = test_share_money;//������� 
						}
						else
						{
							test_n_fund_standardization[s][k] = test_all_stock[s][k] * test_buy_lots + test_all_remain_fund;
						}
						if (test_share_money <= 0)
						{
							test_n_fund_standardization[s][k] = 0;
						}
					}
				}
			}

		}
	}

	for (int k = 0; k < test_day; k++)
	{
		test_yi[k] = 0;

		for (int v = 0; v < s_stock_index; v++)
		{
			/*if (final_portfolio[v] != 0)
			{*/
			for (int s = 0; s < test_stock_index; s++)
			{
				if (final_portfolio[v] == test_stock_no[s])
				{
					test_yi[k] = test_yi[k] + test_n_fund_standardization[s][k];//yi total
				}
			}
			//}
		}

		test_yi[k] += test_remaind;
		test_all_total_yi[k] = test_yi[k];
		test_all_final_fund = test_yi[test_day - 1];
		if (test_yi[k] > 0)
		{
			real_last_total_std[a][k] = test_yi[k];
		}
		if (Gbest_max <= 0)
		{
			real_last_total_std[a][k] = test_initial_fund;
		}
		else if (test_yi[k] <= 10)
		{
			real_last_total_std[a][k] = test_initial_fund;
		}
	}
}

void all_test_return()
{
	for (int k = 0; k < test_day; k++)
	{
		for (int d = 0; d < total_test_day; d++)
		{
			last_total_std[d] = test_yi[k];

			if (last_total_std[d] != 0)
			{
				day_count++;
			}
			final_test_m1 += ((day_count * last_total_std[d]) - (day_count * initial_fund));
			final_test_m2 += day_count * day_count;
			all_test_m = final_test_m1 / final_test_m2;
			break;
		}
	}

	final_all_test_m = all_test_m;
}

void all_test_risk()
{
	for (int a = 0; a < file_num; a++)
	{
		for (int d = 0; d < total_test_day; d++)
		{
			if (real_last_total_std[a][d] != 0)
			{
				day_count_risk++;//�֥[�s�J�}�C������0������,�÷��@�`�Ѽƨϥ�
				last_total_Yi[d] = (all_test_m * day_count_risk) + initial_fund;
				final_test_r1 += ((real_last_total_std[a][d] - last_total_Yi[d]) * (real_last_total_std[a][d] - last_total_Yi[d]));//(yi-Yi)
			}
		}
	}
	final_test_risk = sqrt(final_test_r1 / (day_count_risk));
	if (all_test_m < 0)
	{
		final_test_trend_ratio = all_test_m * final_test_risk;
	}
	else if (all_test_m > 0)
	{
		final_test_trend_ratio = all_test_m / final_test_risk;//�Ͷխ�
	}
	cout << "����w�����S: " << final_all_test_m << endl;
	cout << "���魷�I:" << final_test_risk << endl;
	cout << "�����Ͷխ�: " << final_test_trend_ratio << endl;
}

void test_fitness()//�p����մ��U�϶��Ͷխ�
{
	double test_m1 = 0;
	double test_m2 = 0;

	for (int k = 0; k < test_day; k++)
	{
		test_m1 += (((k + 1) * test_yi[k]) - ((k + 1) * test_initial_fund));
		test_m2 += (k + 1) * (k + 1);
	}

	test_m = test_m1 / test_m2;//v


	double test_r1 = 0;

	for (int k = 0; k < test_day; k++)
	{
		test_Yi[k] = 0;
		test_Yi[k] = test_m * (k + 1) + test_initial_fund;//�@���^�k�Ͷսu//v
		test_r1 += ((test_yi[k] - test_Yi[k]) * (test_yi[k] - test_Yi[k]));//(yi-Yi)
	}
	test_risk = sqrt(test_r1 / (test_day));//���I

	if (test_m < 0)
	{
		test_trend_ratio = test_m * test_risk;
	}
	else if (test_m > 0)
	{
		test_trend_ratio = test_m / test_risk;//�Ͷխ�
	}
}

void fitness()
{
	for (int i = 0; i < partical_num; i++)
	{
		m1 = 0;
		m2 = 0;
		m[i] = 0;


		for (int k = 0; k < day; k++)
		{
			m1 += (((k + 1) * yi[i][k]) - ((k + 1) * initial_fund));
			m2 += (k + 1) * (k + 1);
		}
		m[i] = m1 / m2;//v
	}

	for (int i = 0; i < partical_num; i++) {
		risk[i] = 0;
		r1 = 0;
		all_trend_ratio[i] = 0.0;
		trend_ratio = 0;
		for (int k = 0; k < day; k++)
		{
			Yi[i][k] = 0;
			Yi[i][k] = m[i] * (k + 1) + initial_fund;//�@���^�k�Ͷսu//v
			r1 += ((yi[i][k] - Yi[i][k]) * (yi[i][k] - Yi[i][k]));//(yi-Yi)
		}
		risk[i] = sqrt(r1 / (day));//���I

		if (m[i] < 0)
		{
			trend_ratio = m[i] * risk[i];
		}
		else if (m[i] > 0)
		{
			trend_ratio = m[i] / risk[i];//�Ͷխ�
		}
		all_trend_ratio[i] = trend_ratio;
	}

}

void compare()
{
	max_fitness = all_trend_ratio[0];//�p�G�o��]��0,��쪺���@�w�O���N�ɤl���̤j�ȡC(�p�G���N�ɤl���O�t��)
	max_fitness_tmp = 0;
	for (int i = 0; i < partical_num; i++)
	{
		if (max_fitness < all_trend_ratio[i])
		{
			max_fitness = all_trend_ratio[i];
			max_fitness_tmp = i;
		}
	}
	min_fitness = max_fitness;

	for (int i = 0; i < partical_num; i++)
	{

		if (min_fitness > all_trend_ratio[i])
		{
			min_fitness = all_trend_ratio[i];
			min_fitness_tmp = i;
		}
	}//��Best&Worst

	if (max_fitness > all_max)
	{
		all_max = max_fitness;
		for (int k = 0; k < s_stock_index; k++)
		{
			all_max_solution[k] = partical[max_fitness_tmp][k];
		}
	}//Gbest

	if (all_max <= 0)
	{
		for (int k = 0; k < s_stock_index; k++)
		{
			all_max_solution[k] = 0;
		}
	}

	for (int k = 0; k < s_stock_index; k++) {
		if (all_max_solution[k] == 0 && partical[min_fitness_tmp][k] == 1)
		{
			if (beta[k] > 0.5)
			{
				beta[k] = 1 - beta[k];
				beta[k] = beta[k] - theta;
			}

			else if (beta[k] <= 0.5)
			{
				beta[k] = beta[k] - theta;
			}
		}
		if (all_max_solution[k] == 1 && partical[min_fitness_tmp][k] == 0)
		{
			if (beta[k] < 0.5)
			{
				beta[k] = 1 - beta[k];
				beta[k] = beta[k] + theta;
			}
			else if (beta[k] >= 0.5)
			{
				beta[k] = beta[k] + theta;
			}
		}
	}
}

void experiment_compre() /*50������Gbest���,�ç�XGbest�������*/
{
	Gbest_max = all_max_tmp[0];
	for (int j = 0; j < experiment_time; j++)
	{
		if (Gbest_max <= all_max_tmp[j])
		{
			Gbest_max = all_max_tmp[j];
		}//��50�����窺Gbest,�p�G�u���@������i����
	}

	for (int j = 0; j < experiment_time; j++)
	{
		if (Gbest_max == all_max_tmp[j])
		{
			best_experimrentime = j + 1;//��̨θѹ��禸��
			break;
		}
	}
}

void Gbest_num_find()//��Gbest����禸�Ƥ��X�{������
{
	Gbest_num = 0;
	for (int j = 0; j < experiment_time; j++)
	{
		if (Gbest_max == all_max_tmp[j])
		{
			Gbest_num += 1;
		}
	}
}

void generation_compare()
{
	best_generation = 0;
	for (int j = 0; j < experiment_time; j++)
	{
		for (int t = 0; t < generation; t++)
		{
			for (int i = 0; i < partical_num; i++)
			{
				if (Gbest_max == real_all_trend_ratio[j][t][i])
				{
					best_generation = t + 1;//�̨θѥ@�N��
					Gbest_daily_risk = daily_risk[j][t][i];//�̨θѭ��I
					Gbest_expect_retutn = expect_m[j][t][i];//�̨θѹw�����S
					Gbest_n = final_n[j][t][i];
					Gbest_share_money = compare_share_money[j][t][i];
					Gbest_i = i;
					for (int k = 0; k < Gbest_n; k++)
					{
						Gbest_all_remain_fund[k] = 0;
						Gbest_buy_lots[k] = compare_buy_lots[j][i][k];//�i�R�i��
						Gbest_all_remain_fund[k] = compare_remain_fund[j][k];
						for (int d = 0; d < day; d++)
						{
							Gbest_n_fund_standardization[k][d] = all_n_fund_standardization[j][k][d];
						}
					}
					for (int d = 0; d < day; d++)
					{
						real_total_yi[d] = compare_total_yi[j][d];
						Gbest_yi = real_total_yi[day - 1];
					}
					return;
				}
			}
		}
	}
}

void Gbest_stock_selection()
{
	for (int j = 0; j < experiment_time; j++)
	{
		for (int t = 0; t < generation; t++)
		{
			for (int i = 0; i < partical_num; i++)
			{
				for (int s = 0; s < s_stock_index; s++)
				{
					final_portfolio[s] = "\0";
					//cout << real_partical[j][i][s] << endl;
					if (real_partical[best_experimrentime - 1][i][s] == 1)
					{
						final_portfolio[s] = stock_no[s];//Gbest���զX��
						train_stock_index[s] = s;
					}
				}
				return;
			}
		}
	}
}


void out_file(int a)
{
	if (Gbest_max > 0)
	{
		string ouput_file = "Larry_result_" + QQ_train20[a].substr(0, QQ_train20[a].length());//��X�ɮצW��
		output_file.open(ouput_file, ios::app);//�ɮ׿�X
		output_file << "�N��" << "," << generation << endl;
		output_file << "�ɤl��" << "," << partical_num << endl;
		output_file << "���ਤ�פW��" << "," << theta << endl;
		output_file << "���ਤ�פU��" << "," << theta << endl;
		output_file << "���ਤ��" << "," << theta << endl;
		output_file << "���禸��" << "," << experiment_time << endl << endl;
		output_file << "��l���" << "," << initial_fund << endl;
		output_file << "�̫���" << "," << fixed << setprecision(15) << Gbest_yi << endl;
		output_file << "�u����S" << "," << fixed << setprecision(15) << Gbest_yi - initial_fund << endl << endl;
		output_file << "�w�����S" << "," << fixed << setprecision(15) << Gbest_expect_retutn << endl;
		output_file << "���I" << "," << fixed << setprecision(15) << Gbest_daily_risk << endl;
		output_file << "Gbest" << "," << fixed << setprecision(30) << Gbest_max << endl;
		output_file << "���̨θѥ@�N" << "," << best_generation << endl;
		output_file << "���̨θѹ���#" << "," << best_experimrentime << endl;
		output_file << "���̨θѦ���" << "," << Gbest_num << endl << endl;
		output_file << "���զX�ɼ�" << "," << Gbest_n << endl;
		for (int s = 0; s < s_stock_index; s++)
		{
			if (final_portfolio[s] != "\0")
			{
				output_file << final_portfolio[s] << "(" << s << ")" << ",";
			}

		}
		output_file << endl;
		output_file << "Stock#" << ",";
		for (int s = 0; s < s_stock_index; s++)
		{
			if (final_portfolio[s] != "\0")
			{
				output_file << final_portfolio[s] << "(" << s << ")" << ",";
			}
		}
		output_file << endl;
		output_file << "�Ѽ�" << ",";
		for (int k = 0; k < Gbest_n; k++)
		{
			output_file << Gbest_buy_lots[k] << ",";
		}
		output_file << endl;
		output_file << "���t���" << ",";
		for (int k = 0; k < Gbest_n; k++)
		{
			output_file << Gbest_share_money << ",";
		}
		output_file << endl;
		output_file << "�Ѿl���" << ",";
		for (int k = 0; k < Gbest_n; k++)
		{
			output_file << Gbest_all_remain_fund[k] << ",";
		}
		output_file << endl;
		for (int d = 0; d < day; d++)
		{
			output_file << "FS(" << d + 1 << ")" << ",";
			for (int k = 0; k < Gbest_n; k++)
			{
				output_file << fixed << setprecision(15) << Gbest_n_fund_standardization[k][d] << ",";
			}
			output_file << fixed << setprecision(15) << real_total_yi[d] << "," << endl;

		}
		output_file.close();
	}
}


void test_out_file(int a)
{
	if (Gbest_max > 0)
	{
		string ouput_file = "Larry_result_" + QQ_test20[a].substr(0, QQ_test20[a].length());//��X�ɮצW��
		output_file.open(ouput_file, ios::app);//�ɮ׿�X
		output_file << "�N��" << "," << generation << endl;//v
		output_file << "�ɤl��" << "," << partical_num << endl;//v
		output_file << "���ਤ��" << "," << theta << endl;//v
		output_file << "���禸��" << "," << experiment_time << endl << endl;//v
		output_file << "��l���" << "," << test_initial_fund << endl;//v
		output_file << "�̫���" << "," << fixed << setprecision(15) << test_all_final_fund << endl;
		output_file << "�u����S" << "," << fixed << setprecision(15) << test_all_final_fund - test_initial_fund << endl << endl;
		output_file << "�w�����S" << "," << fixed << setprecision(15) << test_m << endl;//v
		output_file << "���I" << "," << fixed << setprecision(15) << test_risk << endl;//v
		output_file << "Gbest" << "," << fixed << setprecision(11) << test_trend_ratio << endl;//v
		output_file << endl;
		output_file << "���զX�ɼ�" << "," << Gbest_n << endl;
		for (int s = 0; s < test_stock_index; s++)
		{
			for (int v = 0; v < s_stock_index; v++)
			{
				/*if (final_portfolio[s] != 0)
				{*/
				if (final_portfolio[v] == test_stock_no[s])
				{
					output_file << test_stock_no[s] << "(" << s << ")" << ",";
				}
				//}
			}
		}
		output_file << endl;
		output_file << "Stock#" << ",";
		for (int s = 0; s < test_stock_index; s++)
		{
			for (int v = 0; v < s_stock_index; v++)
			{
				/*if (final_portfolio[s] != 0)
				{*/
				if (final_portfolio[v] == test_stock_no[s])
				{
					output_file << test_stock_no[s] << "(" << s << ")" << ",";
				}
				//}
			}
		}
		output_file << endl;
		output_file << "�Ѽ�" << ",";

		for (int s = 0; s < test_stock_index; s++)
		{
			for (int v = 0; v < s_stock_index; v++)
			{
				/*if (final_portfolio[s] != 0)
				{*/
				if (final_portfolio[v] == test_stock_no[s])
				{
					output_file << test_all_buy_lots[s] << ",";

				}
				//}
			}
		}
		output_file << endl;
		output_file << "���t���" << ",";
		for (int k = 0; k < Gbest_n; k++)
		{
			output_file << test_share_money << ",";
		}
		output_file << endl;
		output_file << "�Ѿl���" << ",";
		for (int s = 0; s < test_stock_index; s++)
		{
			for (int v = 0; v < s_stock_index; v++)
			{
				/*if (final_portfolio[s] != 0)
				{*/
				if (final_portfolio[v] == test_stock_no[s])
				{
					output_file << test_real_all_remain_fund[s] << ",";
				}
				//}
			}
		}
		output_file << endl;
		for (int d = 0; d < test_day; d++)
		{
			output_file << "FS(" << d + 1 << ")" << ",";
			for (int s = 0; s < test_stock_index; s++)
			{
				for (int v = 0; v < s_stock_index; v++)
				{
					/*if (final_portfolio[s] != 0)
					{*/
					if (final_portfolio[v] == test_stock_no[s])
					{
						output_file << fixed << setprecision(15) << test_n_fund_standardization[s][d] << ",";
					}
					//}
				}
			}
			output_file << fixed << setprecision(15) << test_all_total_yi[d] << "," << endl;
		}
		output_file.close();
	}
}

void all_testperiod_final_result()
{
	string ouput_file = "Larry_US20_Q#_total_test_result.csv";//��X�ɮצW��
	output_file.open(ouput_file, ios::app);//�ɮ׿�X
	output_file << "���մ��϶�" << "," << "test_2013_01(2012 Q1).csv - test_2019_12(2019 Q1).csv" << endl;
	output_file << "�@�N��" << "," << generation << endl;
	output_file << "���ਤ��" << "," << theta << endl;
	output_file << "�ɤl��" << "," << partical_num << endl;
	output_file << "���禸��" << "," << experiment_time << endl;
	output_file << "��l���" << "," << initial_fund << endl;
	output_file << "�u����S" << "," << fixed << setprecision(15) << test_all_final_fund - initial_fund << endl << endl;
	output_file << "�w�����S" << "," << fixed << setprecision(15) << all_test_m << endl;
	output_file << "���I" << "," << fixed << setprecision(15) << final_test_risk << endl;
	output_file << "�Ͷխ�" << "," << fixed << setprecision(15) << final_test_trend_ratio << endl;
	output_file << "*�o�̪��_�I�ȬO�ιw�����S���W���I" << endl << endl;
	output_file << "�`�Ѽ�" << "," << day_count << endl;
	output_file << "�Ѽ�" << "," << "�`�������" << endl;
	for (int a = 0; a < file_num; a++)
	{
		for (int d = 0; d < total_test_day; d++)
		{
			if (real_last_total_std[a][d] != 0)
			{
				day_count_result++;
				output_file << "FS(" << day_count_result << ")" << ",";
				output_file << real_last_total_std[a][d] << endl;

			}
		}
	}

	output_file.close();
}

void all_train_prtiod_result(int a)
{
	string ouput_file = "Larry_US20_Q#_train_Gbest_10000_10_50_0.0004.csv";//��X�ɮצW��
	output_file.open(ouput_file, ios::app);

	if (all_gbest_trend_ratio[a] > 0)
	{
		output_file << a + 1 << "," << all_file_gbest_num[a] << ",";
		for (int s = 0; s < s_stock_index; s++)
		{
			if (all_file_gbest_portfolio[a][s] != "\0")
			{
				output_file << all_file_gbest_portfolio[a][s] << "(" << s << ") " << " ";
			}
		}
		output_file << ",";
		output_file << "Gbest" << "," << fixed << setprecision(20) << all_gbest_trend_ratio[a] << ",";
		output_file << "�w�����S" << "," << fixed << setprecision(20) << all_file_gbest_return[a] << ",";
		output_file << "���I" << "," << fixed << setprecision(20) << all_file_gbest_risk[a] << ",";
		output_file << "�̨θѹ���#" << "," << all_file_gbest_experiment[a] << ",";
		output_file << "�̨θѥ@�N#" << "," << all_file_gbest_generation[a] << ",";
		output_file << "�̨θѥX�{����" << "," << all_file_gbest_appear[a];
		output_file << endl;
	}

	else if (all_gbest_trend_ratio[a] <= 0)
	{
		output_file << a + 1 << "," << 0 << "," << 0 << ",";
		output_file << "Gbest" << "," << 0 << ",";
		output_file << "�w�����S" << "," << 0 << ",";
		output_file << "���I" << "," << 0 << ",";
		output_file << "�̨θѹ���#" << "," << 0 << ",";
		output_file << "�̨θѥ@�N#" << "," << 0 << ",";
		output_file << "�̨θѥX�{����" << "," << 0;
		output_file << endl;
	}
	output_file.close();

}

int main()
{
	srand(114);
	for (int a = 0; a < file_num; a++)
	{
		index = 0;
		day = 0;
		read_file(a);
		for (int j = 0; j < experiment_time; j++)
		{
			//index = 0;
			//day = 0;
			all_max = 0;
			initial();
			for (int t = 0; t < generation; t++)
			{
				measure();
				standardization();
				fitness();
				compare();
				for (int i = 0; i < partical_num; i++)
				{
					real_all_trend_ratio[j][t][i] = all_trend_ratio[i];
					daily_risk[j][t][i] = risk[i];
					expect_m[j][t][i] = m[i];
					final_n[j][t][i] = n[i];
					compare_share_money[j][t][i] = all_share_money[i];

					for (int s = 0; s < s_stock_index; s++)
					{
						real_partical[j][i][s] = partical[i][s];//Think
					}

					for (int k = 0; k < n[i]; k++)
					{
						compare_buy_lots[j][i][k] = all_buy_lots[k];
						compare_remain_fund[j][k] = real_all_remain_fund[k];
						for (int d = 0; d < day; d++)
						{
							all_n_fund_standardization[j][k][d] = n_fund_standardization[i][k][d];
							compare_total_yi[j][d] = all_total_yi[d];

						}
					}

				}
			}
			all_max_tmp[j] = all_max;//�N�C�������쪺Gbest��J�}�C��				
		}
		experiment_compre();
		Gbest_num_find();
		generation_compare();
		Gbest_stock_selection();
		out_file(a);
		test_index = 0;
		test_read_file(a);//���մ�Ū��
		if (a == 0)
		{
			test_initial_fund = initial_fund;//�p�G�O�Ĥ@�Ӵ��մ��ɮ�,�h��l�����10000000
		}
		if (test_all_final_fund <= 0)
		{
			test_initial_fund = test_initial_fund;
		}
		else if (a != 0)
		{
			test_initial_fund = test_all_final_fund;//�ĤG�Ӵ��մ��ɮ׶}�l,��l������W�@�϶��̫���

		}
		test_standardization(a);
		test_fitness();
		all_test_return();//�`����մ��w�����S�p��
		test_out_file(a);//���մ��ɮ׿�X
		all_file_gbest_risk[a] = Gbest_daily_risk;
		all_file_gbest_return[a] = Gbest_expect_retutn;
		all_file_gbest_num[a] = Gbest_n;
		all_file_gbest_generation[a] = best_generation;
		all_file_gbest_experiment[a] = best_experimrentime;
		all_file_gbest_appear[a] = Gbest_num;
		all_gbest_trend_ratio[a] = Gbest_max;
		for (int s = 0; s < s_stock_index; s++)
		{
			if (final_portfolio[s] != "/0")
			{
				all_file_gbest_portfolio[a][s] = final_portfolio[s];
			}
		}
		all_train_prtiod_result(a);
	}

	all_test_risk();//�`����մ����I�p��
	all_testperiod_final_result();//�`����մ����G��X
	cout << endl << (double)clock() / CLOCKS_PER_SEC << "S" << endl;
	system("pause");
	return 0;
}