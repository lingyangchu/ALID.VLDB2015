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


#include "m_timer.h"

m_timer::m_timer(void)
{
	t_start.tv_sec = -1;
	t_start.tv_usec = -1;
}

m_timer::~m_timer(void)
{
	
}

void m_timer::start()
{
	gettimeofday(&t_start,NULL);
}

double m_timer::end()
{
	if (t_start.tv_sec == -1 && t_start.tv_usec == -1)
	{
		printf("Warning: <t_start> is not marked ! \n");
		exit(0);
	}

	gettimeofday(&t_end, NULL);

	double diff = 1.0*(t_end.tv_sec - t_start.tv_sec) + 1.0*(t_end.tv_usec - t_start.tv_usec)/1e6;

	return diff;
}
