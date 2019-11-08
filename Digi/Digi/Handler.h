#pragma once
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>

class Handler
{
public:
	friend class boost::serialization::access;
	Handler();
	~Handler();
	template<size_t rows, size_t cols>
	void serializeMap(int(&map)[rows][cols]) {
		std::ofstream ofs("mapRecord.txt");
		boost::archive::text_oarchive oa(ofs);
		oa << map;

	};
	template<size_t rows, size_t cols>
	void LoadMap(int(&map)[rows][cols]) {
		std::ifstream ifs("mapRecord.txt", std::ios::binary);
		boost::archive::text_iarchive ia(ifs);
		ia >> map;
	}
};

