#pragma once
#include "stdafx.h"
#include "operation_function.h"

// initialize function 
operation_function::operation_function()
{
	//cout << "operation begain" << endl;
	m_ll_Sumfitness = 0;
	for (ll i = 0; i < ce_ll_max_count; i++)
	{
		st_chrom t_st_Chromosome;
		func_init(t_st_Chromosome);
		//cout << "init" << i << endl;
		func_Fitness(t_st_Chromosome);
		
		m_st_Chromosome.push_back(t_st_Chromosome);
		m_ll_Sumfitness += t_st_Chromosome.m_ll_fitness;
	}
	m_ll_CountChromosome = ce_ll_max_count;
}


operation_function::~operation_function()
{
}

// crossing function
void operation_function::func_cross()
{
	func_variant();
	ll t_ll_crossTime = 2;//random(0,4)   // the times to cross
	while (t_ll_crossTime--)
	{
		//roulette to select the chromosome to cross
		// using probability method
		ll i,j;
		while (1)
		{
			i = ce_ll_max_count *rand() / (RAND_MAX + 1.0);

			if (m_st_Chromosome[i].m_ll_fitness * ce_ll_max_count * 0.5 < m_ll_Sumfitness)
			{
				break;
			}
		}
		while (1)
		{
			j = ce_ll_max_count *rand() / (RAND_MAX + 1.0);

			if (m_st_Chromosome[j].m_ll_fitness * ce_ll_max_count * 0.5 < m_ll_Sumfitness)
			{
				break;
			}
		}

		st_chrom t_st_Chromosome1 = m_st_Chromosome[i];
		st_chrom t_st_Chromosome2 = m_st_Chromosome[j];
		ll temp_time = 0;
		tk:ll t_ll_swichCross1 = random(0, ce_ll_max_n);
		swap(t_st_Chromosome1.m_vec_sequence[t_ll_swichCross1], t_st_Chromosome2.m_vec_sequence[t_ll_swichCross1]);
		if(!func_check(t_st_Chromosome1))
		{
			temp_time++;
			if (temp_time > 1000) goto tt;
			goto tk;
		}
		m_st_Chromosome.push_back(t_st_Chromosome1);
		m_st_Chromosome.push_back(t_st_Chromosome2);
		//cout << "00" << endl;
		//obsolete code
		//
		/*		ll t_ll_swichCross2 = random(0, ce_ll_max_n);
		swap(t_st_Chromosome1.m_vec_sequence[t_ll_swichCross2], t_st_Chromosome2.m_vec_sequence[t_ll_swichCross2]);
		if (func_check(t_st_Chromosome1))
		{

		goto kkk;
		}
		if (func_check(t_st_Chromosome2))
		{
		m_st_Chromosome.push_back(t_st_Chromosome2);
		}

		ll t_ll_digit11 = func_search(m_st_Chromosome[i], t_ll_swichCross1);
		ll t_ll_digit12 = func_search(m_st_Chromosome[i], t_ll_swichCross2);
		ll t_ll_digit21 = func_search(m_st_Chromosome[j], t_ll_swichCross1);
		ll t_ll_digit22 = func_search(m_st_Chromosome[j], t_ll_swichCross2);

		st_chrom t_st_Chromosome1= m_st_Chromosome[i];
		t_st_Chromosome1.m_vec_sequence[t_ll_digit11] = m_st_Chromosome[j].m_vec_sequence[t_ll_digit22];
		t_st_Chromosome1.m_vec_sequence[t_ll_digit12] = m_st_Chromosome[j].m_vec_sequence[t_ll_digit21];
		func_Fitness(t_st_Chromosome1);
		m_st_Chromosome.push_back(t_st_Chromosome1);

		st_chrom t_st_Chromosome2 = m_st_Chromosome[j];
		t_st_Chromosome2.m_vec_sequence[t_ll_digit21] = m_st_Chromosome[i].m_vec_sequence[t_ll_digit12];
		t_st_Chromosome2.m_vec_sequence[t_ll_digit22] = m_st_Chromosome[i].m_vec_sequence[t_ll_digit11];
		func_Fitness(t_st_Chromosome2);
		*/
	}
	// eliminate operation
	tt:func_erase();
	return;
}

// variant function
void operation_function::func_variant()
{
	// the probability to variant
	ll t_ll_vartime = 5 * rand() / (RAND_MAX + 1.0);
	if(t_ll_vartime==1)
	{
			ll t_ll_varchance = 20 * rand() / (RAND_MAX + 1.0);
			if (t_ll_varchance == 1)
			{
				// choose the chromosome to variant
				ll t_ll_varswitch = m_ll_CountChromosome * rand() / (RAND_MAX + 1.0);
				
				//cout << "before varswitch value  " << m_st_Chromosome[t_ll_varswitch].m_ll_valuex <<"    fitness    "<<m_st_Chromosome[t_ll_varswitch].m_ll_fitness << endl;

				//choose the gene to variant
				ll t_ll_city1 = random(0, ce_ll_max_n);
				ll t_ll_city2 = random(0, ce_ll_max_n);

				ll t_ll_digit1 = func_search(m_st_Chromosome[t_ll_varswitch], t_ll_city1);
				ll t_ll_digit2 = func_search(m_st_Chromosome[t_ll_varswitch], t_ll_city2);

				m_st_Chromosome[t_ll_varswitch].m_vec_sequence[t_ll_digit1] = t_ll_city2;
				m_st_Chromosome[t_ll_varswitch].m_vec_sequence[t_ll_digit2] = t_ll_city1;
				func_Fitness(m_st_Chromosome[t_ll_varswitch]);
				//cout << "after varswitch value  " << m_st_Chromosome[t_ll_varswitch].m_ll_valuex << "    fitness    " << m_st_Chromosome[t_ll_varswitch].m_ll_fitness << endl;
			}
	}
	return;
}

// iteration function
void operation_function::func_loop()
{
	ll t_ll_maxfit= m_st_Chromosome[0].m_ll_fitness ;
	//the requisite to terminal
	ll i;
	for (i = 1;  i<=3000||((i < 10000) && (i % 100 == 0 || t_ll_maxfit == m_st_Chromosome[0].m_ll_fitness ));i++) 
	{
		if(i % 100 == 1)
		t_ll_maxfit = m_st_Chromosome[0].m_ll_fitness;
		func_cross();
	}
	cout << "iteration times : " << i << endl;
	return;
}

// output function
void operation_function::func_print()
{
	cout << "   SumFitness : " << m_ll_Sumfitness <<endl;
	for (ll i=0; i< ce_ll_max_count; i++)
	{
		cout << "Chromosome" << i<<" fit: "<< m_st_Chromosome[i].m_ll_fitness<<endl;
		for (ll j = 0; j < ce_ll_max_n; j++)
		{
			cout << m_st_Chromosome[i].m_vec_sequence[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

// recount the fitness
void operation_function::func_refitness()
{
	m_ll_Sumfitness = 0;
	for (ll i = 0; i < m_ll_CountChromosome; i++)
	{
		data_structure::func_Fitness(m_st_Chromosome[i]);
		m_ll_Sumfitness += m_st_Chromosome[i].m_ll_fitness ;
	}
	return;
}

//eliminate function
void operation_function::func_erase()
{
	func_refitness();
	sort(m_st_Chromosome.begin(), m_st_Chromosome.end());	//sort first
	for (; m_ll_CountChromosome > ce_ll_max_count; m_ll_CountChromosome--)
	{
		m_st_Chromosome.erase(m_st_Chromosome.end());	//erase the longest one
	}
	func_refitness();
}//st_chrom t_st_chromx