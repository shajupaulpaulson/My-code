#include <map>
#include <functional>

#include <memory>
#include "base_sound.h"
	std::map <int, std::function<std::shared_ptr<BaseSound>()>> m_testMap {
		{0,[] (){return std::make_shared<Dog>();}},
		{1,[] (){return std::make_shared<Cat>();}},
		{2,[] (){return std::make_shared<Car>();}},		
	};
