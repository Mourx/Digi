#pragma once
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>
#include "MacroValues.h"

class Handler
{
public:
	friend class boost::serialization::access;
	Handler();
	~Handler();
	//template<size_t rows, size_t cols>
	// int(&map)[rows][cols]
	void serializeMap() {
		std::ofstream ofs("mapRecord.txt");
		boost::archive::text_oarchive oa(ofs);
		for (int i = 0; i < mapsAmount; i++) {
			oa << mapList[i];
		}

	};
	/*int(&map)[rows][cols]*/
	//template<size_t rows, size_t cols>
	void LoadMap() {
		std::ifstream ifs("mapRecord.txt", std::ios::binary);
		boost::archive::text_iarchive ia(ifs);
		for (int i =0; i < mapsAmount; i++) {
			ia >> mapList[i];
		}
	}
};

