/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                          ALL RIGHTS RESERVED                              */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*	    						                     */
/*   This is an openmp implementation of Parallel-ALID algorithm             */
/*									     */
/*   Version:  alpha_0.1           				             */
/*                                                                           */
/*   Author :  Lingyang Chu                                                  */
/*             Institute of Computing Technology (ICT), 		     */
/*	       University of Chinese Academy of Sciences (UCAS)              */
/*   Email_1:  chulingyang@gmail.com      	                             */
/*   Email_2:  lingyang.chu@vipl.ict.ac.cn                                   */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*									     */
/*   Please cite the following publication if you use this package 	     */
/* 									     */
/*   Lingyang Chu, Shuhui Wang, Siyuan Liu, Qingming Huang, Jian Pei,        */
/*   "ALID: Scalable Dominant Cluster Detection", VLDB 2015.                 */
/*									     */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "omp.h"
#include "stdio.h"
#include "stdlib.h"
#include "m_LSH.h"
#include "MVector.h"
#include "MMatrix.h"
#include "ALID_RUNNER.h"
#include "time.h"

static void usage(char *argv0) 
{
    const char *params =
	"Usage:\n %s -i inputfile -o outputfile -e ek -k NKX -l NLX -r WX -d data_dim -c Num_cores\n\b"
    	"-e (double):	the ek paramter for laplacian kernel\n"
	"-k (int):	the number of keys (NKX) for E2LSH\n"
	"-l (int):	the number of hash tables for E2LSH\n"
	"-r (double):	the r (i.e., wx) denominator for E2LSH\n"
	"-d (int): 	the data dimension\n"
	"-S (int): 	the sample threshold when sampling hash buckets for init_idx\n"
	"-R (float):	the sample rate when sampling hash buckets for init_idx\n"
	"-c (int): 	the number of cores (threads) to use\n"
	"-i (string):	the input file name <*.bin>\n"
	"-o (string): 	the output file name <*.txt>\n\n"
	"-u :           use single core sequential ALID ";	
		
    fprintf(stderr, params, argv0);
    exit(-1);
}

static void showCurTime(string title)
{
	time_t tt = time(NULL);//这句返回的只是一个时间cuo
	tm* t= localtime(&tt);
	printf("%s: %d-%02d-%02d %02d:%02d:%02d\n",
	title.c_str(),
	t->tm_year + 1900,
	t->tm_mon + 1,
	t->tm_mday,
	t->tm_hour,
	t->tm_min,
	t->tm_sec);
}

int test4_main() {
	printf("before ...\n");
	getchar();
	vector<vector<double> > mat;
	int count = 0;
	for (int i = 0; i < 500; i++) {
		vector<double> buf;
		for (int j = 0; j < 2000; j++) {
			count++;
			buf.push_back(j*1.5);	
		}
		mat.push_back(buf);
	}
	
	printf("after ... Memory should be: %f MB \n", 1.0*count*8/1024/1024);
	getchar();
}

// this test main is used to test the memory efficiency of <MMatrix>
int test3_main() {
	MMatrix m_mat(1e6, 1e6);
	int count = 0;
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			count++;
			
			if (count%10000 == 0)
			{
				printf("count: %d   Memory should be: %f MB\n", count, 1.0*count*8/1024/1024);
				getchar();
			}
			m_mat.setElem(i*3,j, 1.0*i*j);
		}	
		
	} 	
}

int test2_main() {
	// some default values	
	double ek		= 0.1;
	int K   		= 24;
	int L   		= 8;
	double r		= 0.3;
	int data_dim 		= 100;

	int sample_thres	= 7;
	float sample_rate 	= 0.3;

	int num_cores		= 8;

	string input_file	= "";
	string output_file	= "./PALID_result.txt";

	// start building LSH
	m_LSH hash_database(K, L, r, "/home/leon/ALID_NEW_EXP/ALID_C_Linux/HASHPOOL.bin",
				     "/home/leon/ALID_NEW_EXP/ALID_C_Linux/WXPOOL.bin",
				     "/home/leon/ALID_NEW_EXP/SYN_DATA_FORC/md1_p1.00_N1000000_D100_C2000.bin");
	printf("LSH define finished!");
	getchar();
	hash_database.performLSH();
	printf("LSH building finished!");
	getchar();		
}

int test1_main() {
	// some default values	
	double ek		= 0.1;
	int K   		= 24;
	int L   		= 8;
	double r		= 0.3;
	int data_dim 		= 100;

	int sample_thres	= 7;
	float sample_rate 	= 0.3;

	int num_cores		= 8;

	string input_file	= "";
	string output_file	= "./PALID_result.txt";

	// load data and build LSH indexes for linux
	m_LSH hash_database(K, L, r, "/home/leon/ALID_NEW_EXP/ALID_C_Linux/HASHPOOL.bin",
				     "/home/leon/ALID_NEW_EXP/ALID_C_Linux/WXPOOL.bin",
				     "/home/leon/ALID_NEW_EXP/SYN_DATA_FORC/md1_p1.00_N100000_D100_C200.bin");
	hash_database.performLSH();
	printf("LSH building finished!");
	getchar();

	// init mask
	vector<bool> pmask(hash_database.getTotalFeaNum(), false);
	printf("pmask assigned!");
	getchar();
	
	// start to new objects
	PALID m_palid1 = PALID(ek, &hash_database);	
	printf("stop");
	getchar();
	PALID m_palid2 = PALID(ek, &hash_database);
	printf("stop");
	getchar();
	PALID m_palid3 = PALID(ek, &hash_database);
	printf("stop");
	getchar();	
	PALID m_palid4 = PALID(ek, &hash_database);
	printf("stop");
	getchar();
	PALID m_palid5 = PALID(ek, &hash_database);
	printf("stop");
	getchar();
	PALID m_palid6 = PALID(ek, &hash_database);
	printf("stop");
	getchar();
	PALID m_palid7 = PALID(ek, &hash_database);
	printf("stop");
	getchar();
	PALID m_palid8 = PALID(ek, &hash_database);
	printf("stop");
	getchar();
}

int main(int argc, char** argv) {
	// get the input option parameters
	int 	opt;

	// some default values	
	double ek		= 0.2;
	int K   		= 24;
	int L   		= 8;
	double r		= 0.3;
	int data_dim 		= 100;

	int sample_thres	= 7;
	float sample_rate 	= 0.3;

	int num_cores		= 8;

	string input_file	= "./md1_p1.00_N10000_D100_C20.bin";
	string output_file	= "./PALID_result.txt";

	bool sequential_flag    = false;

	while ((opt=getopt(argc,argv,"e:k:l:r:d:S:R:c:i:o:h:u"))!= EOF)
    	{
		switch (opt)
        	{
			case 'e':
				ek = atof(optarg);
				break;			
           		case 'k':
		            	K = atoi(optarg);
            			break;
		        case 'l':
            			L = atoi(optarg);
            			break;
			case 'r':
				r = atof(optarg);
				break;
			case 'd':
				data_dim = atoi(optarg);
				break;

			case 'S':
				sample_thres = atoi(optarg);
				break;
			case 'R':
				sample_rate = atof(optarg);
				break;

			case 'c':
				num_cores = atoi(optarg);
				break;

			case 'i':
            			input_file = optarg;
               			break;
			case 'o':
				output_file = optarg;
				break;

			case 'u':
				sequential_flag = true;
				break;

			case '?':
           			usage(argv[0]);
	           		break;
			
           		default:
           			usage(argv[0]);
           			break;
    		}
	}

	// check valid
	if(input_file == "" || num_cores < 1)
	{
		usage(argv[0]);
		exit(-1);
	}

	// show info
	printf("************   Paramters  **************\n");
	printf("ek:\t\t %f\n", ek);
	printf("NKX:\t\t %d\n", K);
	printf("NLX:\t\t %d\n", L);
	printf("WX:\t\t %f\n", r);
	printf("r_limit:\t %f\n", r_limit);
	printf("data_dim:\t %d\n", data_dim);
	printf("sample_thres:\t %d\n", sample_thres);
	printf("sample_rate:\t %f\n", sample_rate);
	printf("num_cores:\t %d\n", num_cores);
	printf("input_file:\t %s\n", input_file.c_str());
	printf("output_file:\t %s\n", output_file.c_str());
	printf("****************************************\n");

	// load data and build LSH indexes for linux
	m_LSH hash_database(K, L, r, "./HASHPOOL.bin",
				     "./WXPOOL.bin",input_file.c_str());
				     hash_database.performLSH();
	
	showCurTime("Build hash_database finished timespot");
	// getchar();
	
	// run PALID to find the result
	ALID_RUNNER m_runner(ek, &hash_database);
	
	if (sequential_flag == true)
	{
	    m_runner.sequentialALID(output_file);
	}
	else
	{
	    m_runner.parallelALIDWithSample(num_cores, output_file.c_str(), sample_thres, sample_rate);
	}
}
