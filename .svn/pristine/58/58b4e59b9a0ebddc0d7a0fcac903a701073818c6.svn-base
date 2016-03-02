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


#include "MMatrix.h"


MMatrix::MMatrix(int _row, int _col)
{
	row = _row;
	col  = _col;

	buf.clear();
	row_map.clear();
	col_map.clear();
}

MMatrix::MMatrix( void )
{

}

MMatrix::~MMatrix(void)
{
}


void MMatrix::clear()
{
	// clear <buf>
	for (int i = 0; i < buf.size(); i++) {
		buf[i].clear();
		vector<DATATYPE> null_vec;
		buf[i].swap(null_vec);		
	}
	
	buf.clear();
	vector<vector<DATATYPE> > null_vec;
	buf.swap(null_vec);
	
	// clear map
	row_map.clear();
	col_map.clear();
}

void MMatrix::setElem( int _rowidx, int _colidx, DATATYPE value )
{
	// first, memory alloc in <buf>
	if (row_map.count(_rowidx) <= 0)
	{
		buf.push_back(vector<DATATYPE> (col_map.size(), 0.0));
		int row_num = row_map.size();
		row_map[_rowidx] = row_num;
	}

	if (col_map.count(_colidx) <= 0)
	{
		for (int i = 0; i < buf.size(); i++)
		{
			buf[i].push_back(0.0);
		}
		int col_num = col_map.size();
		col_map[_colidx] = col_num;
	}

	// second, set element
	int local_row = row_map[_rowidx];
	int local_col = col_map[_colidx];
	buf[local_row][local_col] = value;

}

DATATYPE MMatrix::getElem( int _rowidx, int _colidx )
{
	if (row_map.count(_rowidx) <= 0 || col_map.count(_colidx) <= 0 )
	{
		return 0.0;
	}
	else
	{
		int local_row = row_map[_rowidx];
		int local_col = col_map[_colidx];
		return buf[local_row][local_col];
	}
}

int MMatrix::getCardinality()
{
	return (int) row_map.size() * col_map.size();
}
