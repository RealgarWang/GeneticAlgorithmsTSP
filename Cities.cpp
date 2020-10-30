#include "stdafx.h"
#include "Cities.h"

// cities initialize
Cities::Cities()
{
	m_st_cities.clear();
	m_map_cityCount.clear();
	m_ll_distance.clear();
	//make sure there are not cities locate on the same places
	for (ll i = 0; i < ce_ll_max_n; i++)
	{
		st_city t_st_newCity;
		t_st_newCity.m_ll_x = random(0, ce_ll_max_x)/pow(10,random(0,2));
		t_st_newCity.m_ll_y = random(0, ce_ll_max_x)/pow(10,random(0,2));
		if (m_map_cityCount[t_st_newCity] == 0)
		{
			m_st_cities.push_back(t_st_newCity);
		}
		else
		{
			i--;
		}
	}

	// distance matrix initialize
	vector<ll>t_vec_line;
	for (ll i = 0; i < ce_ll_max_n; i++)
	{
		t_vec_line.push_back(ce_ll_inf);
	}
	for (ll i = 0; i < ce_ll_max_n; i++)
	{
		m_ll_distance.push_back(t_vec_line);
	}

	// count the distance matrix of the undirected graph
	for (ll i = 0; i < ce_ll_max_n; i++)
	{
		for (ll j = i+1; j < ce_ll_max_n; j++)
		{
			m_ll_distance[i][j] = 1LL*(m_st_cities[i].m_ll_x - m_st_cities[j].m_ll_x)*(m_st_cities[i].m_ll_x - m_st_cities[j].m_ll_x) + (m_st_cities[i].m_ll_y - m_st_cities[j].m_ll_y)*(m_st_cities[i].m_ll_y - m_st_cities[j].m_ll_y);
			//m_ll_distance[i][j] = sqrt(1.0*m_ll_distance[i][j]);
			m_ll_distance[j][i] = m_ll_distance[i][j];
		}
	}
}

// the destructor function
Cities::~Cities()
{
	m_st_cities.clear();
	m_map_cityCount.clear();
}

// output function
void Cities::func_print()
{
	// output the position of the cities
	cout << "city" << endl;
	for (ll i = 0; i < ce_ll_max_n; i++)
	{
		cout << "( "<<m_st_cities[i].m_ll_x <<" , " << m_st_cities[i].m_ll_y << ") "<<endl;
	}

	// output the distance matrix
	cout << "distance" << endl;
	for (ll i = 0; i < ce_ll_max_n; i++)
	{
		for (ll j = 0; j < ce_ll_max_n; j++)
		{
			cout<< m_ll_distance[i][j]<<'\t';
		}
		cout << endl;
	}
	cout << endl;
	return;
}