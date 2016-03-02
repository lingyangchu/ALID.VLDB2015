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


#pragma once
#include <map>
#include <vector>

using namespace std;

// typedef double DATATYPE;
typedef float DATATYPE;

class MMatrix
{
private:
	int row; // the global matrix row number
	int col; // the global matrix column number

	vector<vector<DATATYPE> > buf; // the buf to densely store all matrix elements, using local index
	
	map<int, int> row_map; // map<global_row_idx, local_row_idx>
	map<int, int> col_map; // map<global_col_idx, local_col_idx>

public:
	void clear(); // clear this entire object to empty
	void setElem(int _rowidx, int _colidx, DATATYPE value);
	DATATYPE getElem(int _rowidx, int _colidx);
	int getCardinality();

public:
	MMatrix(int _row, int _col);
	MMatrix(void);
	~MMatrix(void);
};

