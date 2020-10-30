// head file of the city
//we can also statement other class
#pragma once
#include "stdafx.h"

// the struct of Cities

typedef struct ST_CITY
{
	// the position
	ll m_ll_x;
	ll m_ll_y;
	//Operator overloading
	bool operator<(const ST_CITY& obj)  const 
	{
		return (m_ll_x==obj.m_ll_x)?(m_ll_y<obj.m_ll_y):(m_ll_x<obj.m_ll_x);
	}
}st_city;

//the class of the cities
class Cities
{
public:
	Cities();		// cities initialize
	~Cities();		// the destructor function
	void func_print();		// output the position of the cities and distance matrix

	vector<vector< ll > >m_ll_distance;		//the distance matrix
	vector<st_city>m_st_cities;		//the position of each city
	map<st_city ,ll > m_map_cityCount;		//the times of occurence of a city in the sequence
};

