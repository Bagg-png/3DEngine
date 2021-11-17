#pragma once
#include <iostream>

namespace ag 
{
	template<class T>
	class Singleton 
	{
	public:
		Singleton(const Singleton&) = delete;
		Singleton& operator = (const Singleton&) = delete;

		//Created during compile time
		static T& Instance() 
		{
			static T instance;
			return instance;
		}
	protected:
		Singleton() {}

	};
}