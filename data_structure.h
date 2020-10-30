// head file of the data structure of the genetic algorithm
//	contains the chromosome
#pragma once
#include "stdafx.h"
#include "Cities.h"
//#define func_fit(x,y) 1.0*abs( cos(1.0*x/185000)*log(1.0*y+1)*cos(1.0*y/185000)*sqrt(1.0*x+1) )


typedef struct ST_CHROM
{
	vector<ll>m_ll_valuex;		//chromosome contains the genetic information using vector of integers
	db m_ll_fitness;	// the whole distance if we ergodic the sequence
	vector<ll>m_vec_sequence;		// if we decode the chromosome into gene	
	//Operator overloading
	bool operator<(const ST_CHROM& obj)  const 
	{
		return (m_ll_fitness<obj.m_ll_fitness);
	}
}st_chrom;

//the class of the species
class data_structure :
	public Cities
{
public:
	data_structure();
	~data_structure();
	void data_structure::func_Fitness(st_chrom &t_st_Chromosome);		//to count fitness of each individual
	//void func_decode(st_chrom &t_st_chrom);		// decode function, to decode the chromosome
	void func_init(st_chrom &t_st_Chromosome);		// initialize the individual
	ll func_search(st_chrom &t_st_Chromosome,ll t_ll_city);		//gene probe to search the position of the gene in the chromosome
	bool func_check(st_chrom &t_st_Chromosome);		// check wether the solution is legal

	vector<st_chrom>m_st_Chromosome;	// the whole population
	ll m_ll_CountChromosome;		// the amount of the individual
	ll m_ll_Sumfitness;		// the sum of the fitness of the whole population
};

