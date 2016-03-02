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

#include "set"
#include "map"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

using namespace std;

class MVector
{
private:
	int DIM; // the vector global dimension
	map<int, double> BUF; // the buffer to store all the vector elements	

public:
	set<int> getKeys(); // return a solid copy of the KEYS
	void setElem(int id, double _value); // set element value
	double getElem(int id); // get element value
	int getCardinality(); // return the number of non-zero elements
	int getDim(); // return the real dimension of the full vector
	
	MVector subtract(MVector Vec_B); // Vec_A.subtract(Vec_B)=Vec_A - Vec_B
	MVector add(MVector Vec_B); // Vec_A.add(Vec_B) = Vec_A + Vec_B
	MVector multiply(double factor); // element wise multiply by <factor>

	map<int, double> getNonzeroElemts();
	
	double innerProduct(MVector Vec_B);

	void clear(); // clear the vector to empty

public:
	MVector(int _dim);
	MVector(void);
	~MVector(void);
};

