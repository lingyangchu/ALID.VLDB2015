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



// this class <ALID_RUNNER> handles all the running issues of ALID
#pragma once
#include "PALID.h"
#include "m_timer.h"

using namespace std;

class ALID_RUNNER
{
private:
	double ek;
	m_LSH* hash_database;
	
public: // Timing in second
	double time_sequentialALID;
	double time_sequentialALIDWithSample;
	double time_parallelALIDWithSample;

public:
	void sequentialALID(string output_file);  // run ALID in sequential mode and export the clustering result into <output file>
	void sequentialALIDWithSample(string output_file, int _threshold, float _sample_rate); // run ALID in sequential mode using LSH sample trick
	void parallelALIDWithSample(int num_cores, string output_file, int _threshold, float _sample_rate);

public:
	ALID_RUNNER(double _ek, m_LSH *_hash_database);
	~ALID_RUNNER(void);
};

