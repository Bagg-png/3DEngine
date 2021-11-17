#pragma once
#include "Json.h"

namespace ag 
{
	class ISerializable 
	{
	public:
		virtual ~ISerializable() {};

		virtual bool Read(const rapidjson::Value& value) = 0;
		virtual bool Write(const rapidjson::Value& value) const = 0;
	};

}