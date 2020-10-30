#pragma once
#include "stdafx.h"
#include "data_structure.h"


data_structure::data_structure()
{
	m_st_Chromosome.clear();
	m_ll_Sumfitness = 0;
	m_ll_CountChromosome = 0;
}


data_structure::~data_structure()
{
	m_st_Chromosome.clear();
}

//initialize the population
void data_structure::func_init(st_chrom &t_st_Chromosome)
{
	map<ll, ll>t_map_squ;
	t_st_Chromosome.m_vec_sequence.clear();
	// make sure there is no repetition in the sequence
	for (ll i = 0; i < ce_ll_max_count; i++)
	{
	kk:ll temp_squ = random(0, ce_ll_max_n);
		if (t_map_squ[temp_squ] != 0)
		{
			goto kk;
		}
		else
		{
			t_st_Chromosome.m_vec_sequence.push_back(temp_squ);
			t_map_squ[temp_squ]++;
		}
	}
	return;
}

//search function to search the position of the gene in the chromosome
ll data_structure::func_search(st_chrom &t_st_Chromosome, ll t_ll_city)
{
	ll t_ll_pos=-1;
	for (ll i = 0; i < t_st_Chromosome.m_vec_sequence.size(); i++)
	{
		if (t_ll_city == t_st_Chromosome.m_vec_sequence[i])
		{
			t_ll_pos = i;
			break;
		}
	}
	if (t_ll_pos == -1)
	{
		cout << "error" << endl;
		return 0;
	}
	return t_ll_pos;
}

//function to count fitness of the whole population
void data_structure::func_Fitness(st_chrom &t_st_Chromosome)
{

	//func_decode(t_st_Chromosome);
	t_st_Chromosome.m_ll_fitness = 0;
	for (ll i = 0; i < t_st_Chromosome.m_vec_sequence.size()-1; i++)
	{
		//cout << "count fitness "<<i<<" "<< t_st_Chromosome.m_vec_sequence[i] <<"  " <<t_st_Chromosome.m_vec_sequence[i + 1] <<endl;
		t_st_Chromosome.m_ll_fitness += m_ll_distance[t_st_Chromosome.m_vec_sequence[i]][t_st_Chromosome.m_vec_sequence[i+1]];
	}
	//cout << "count fitness end";
	//cout << t_st_Chromosome.m_vec_sequence[ce_ll_max_n - 1] << "  " << t_st_Chromosome.m_vec_sequence[0] << endl;
	t_st_Chromosome.m_ll_fitness += m_ll_distance[t_st_Chromosome.m_vec_sequence[ce_ll_max_n-1]][t_st_Chromosome.m_vec_sequence[0]];
	return;
}

//decode function
/*void data_structure::func_decode(st_chrom &t_st_chrom)
{
	t_st_chrom.m_vec_sequence.clear();
	ll t_ll_valuex = t_st_chrom.m_ll_valuex;
	for (ll i = 0; i < ce_ll_max_n; i++)
	{
		ll temp_num = t_ll_valuex % 10;
		t_ll_valuex /= 10;
		t_st_chrom.m_vec_sequence.push_back(temp_num);
	}
	return;
}*/

// function to check reprtition
bool data_structure::func_check(st_chrom &t_st_Chromosome)
{
	bool flag = true;
	for (ll i = 0; i < ce_ll_max_n; i++)
	{
		for (ll j = i + 1; j < ce_ll_max_n; j++)
		{
			if (t_st_Chromosome.m_vec_sequence[i] == t_st_Chromosome.m_vec_sequence[j])
			{
				return false;
			}
		}
	}
	return flag;
}